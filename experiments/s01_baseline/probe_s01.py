"""Exercise the installed S01 service, replay, reset and a fresh second plan."""

import json
import sys
import time
from pathlib import Path

import rclpy
from rcl_interfaces.msg import Parameter, ParameterType, ParameterValue
from rcl_interfaces.srv import GetParameters, SetParameters
from rclpy.qos import DurabilityPolicy, QoSProfile
from std_msgs.msg import String
from std_srvs.srv import Trigger


def main(output):
    output.mkdir(parents=True, exist_ok=False)
    rclpy.init()
    node = rclpy.create_node("check_s01_desktop_runtime")
    report = {"success": False, "runs": []}
    messages = {}
    qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)
    for name, topic in (("scene", "/citrus/state"), ("result", "/citrus_task/result")):
        def receive(msg, key=name):
            messages[key] = json.loads(msg.data)
        node.create_subscription(String, topic, receive, qos)

    def call(service, request, timeout=35.0):
        service_type = {Trigger.Request: Trigger, GetParameters.Request: GetParameters,
                        SetParameters.Request: SetParameters}[type(request)]
        client = node.create_client(service_type, service)
        try:
            if not client.wait_for_service(timeout_sec=15.0):
                raise RuntimeError(f"Service unavailable: {service}")
            future = client.call_async(request)
            rclpy.spin_until_future_complete(node, future, timeout_sec=timeout)
            if not future.done():
                raise RuntimeError(f"Service timed out: {service}")
            return future.result()
        finally:
            node.destroy_client(client)

    def wait_msg(name, predicate, timeout=15.0):
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            if name in messages and predicate(messages[name]):
                return messages[name]
            rclpy.spin_once(node, timeout_sec=0.1)
        raise RuntimeError(f"Unexpected {name} state: {messages.get(name)}")

    def trigger(service):
        response = call(service, Trigger.Request(), timeout=90.0)
        if not response.success:
            raise RuntimeError(f"{service}: {response.message}")

    try:
        report["startup_scene"] = wait_msg("scene", lambda x: x["moveit_sync"] == "synchronized")
        settings = call("/move_group/get_parameters", GetParameters.Request(
            names=["ompl.planning_plugin", "ompl.request_adapters"]))
        plugin, adapters = (v.string_value for v in settings.values)
        report.update(planning_plugin=plugin, request_adapters=adapters)
        assert plugin == "ompl_interface/OMPLPlanner" and "aubo_ompl_capture/" not in adapters

        def parameter(name, type_id, **value):
            return Parameter(name=name, value=ParameterValue(type=type_id, **value))

        def set_params(*parameters):
            result = call("/citrus_s01_task/set_parameters", SetParameters.Request(parameters=list(parameters)))
            if not all(x.successful for x in result.results):
                raise RuntimeError("Failed to configure the isolated task node")

        for label, play in (("first_with_replay", True), ("second_after_reset", False)):
            dest = output / label
            set_params(parameter("output_root", ParameterType.PARAMETER_STRING, string_value=str(dest)),
                       parameter("play", ParameterType.PARAMETER_BOOL, bool_value=play))
            trigger("/citrus_task/run_s01")
            latest = wait_msg("result", lambda x: str(dest) in x.get("output_dir", ""))
            folder = Path(latest["output_dir"])
            data = json.loads((folder / "result.json").read_text())
            assert data["target"] == "S01" and data["acceptance"]["passed"] and data["success"]
            assert data["stages"]["transit"]["reused"] is False
            assert data["segments"] == ["transit", "insertion", "closure", "disengagement", "withdrawal"]
            assert (folder / "display_trajectory.cdr").stat().st_size > 0
            assert "citrus_S01_stump" in data["world_after"] and "citrus_S01" not in data["world_after"]
            run = {"name": label, "result": str(folder / "result.json"), "segments": data["segments"],
                   "fresh_transit": True, "acceptance": data["acceptance"]}
            if play:
                assert data["replay_world_after"] == data["world_after"]
                run["scene_after_replay"] = wait_msg(
                    "scene", lambda x: x["cut_ids"] == ["S01"] and x["stump_present"])
                trigger("/citrus/reset")
            run["scene_intact"] = wait_msg("scene", lambda x: not x["cut_ids"] and not x["stump_present"])
            report["runs"].append(run)
            print(label, folder, flush=True)
        report["success"] = True
    except Exception as exc:
        report["error"] = f"{type(exc).__name__}: {exc}"
        raise
    finally:
        (output / "runtime_audit.json").write_text(json.dumps(report, indent=2) + "\n")
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main(Path(sys.argv[1]).resolve())
