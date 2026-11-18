"""ROS 2 node that runs the S01 pruning task on request.

Interfaces
  service  /citrus_task/run_s01   std_srvs/srv/Trigger   plan + check (+ replay) one S01 round
  topic    /citrus_task/result    std_msgs/msg/String    JSON summary of the last round (latched)

The MoveIt / scene service calls are made through a private helper node that is
spun only inside the task, so the service callback never re-enters its own executor.
"""
import json
import threading
import time
from pathlib import Path

import rclpy
from ament_index_python.packages import get_package_share_directory
from rclpy.executors import ExternalShutdownException, SingleThreadedExecutor
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile
from std_msgs.msg import String
from std_srvs.srv import Trigger

from .acceptance import format_checks
from .isolation import isolation_error
from .planner import Planner
from .s01_task import TaskConfig, execute


def default_output_root():
    share = Path(get_package_share_directory("citrus_pruning_task"))
    for parent in share.parents:
        if (parent / "install").is_dir() and (parent / "src").is_dir():
            return parent / "results" / "s01"
    return Path.cwd() / "results" / "s01"


class S01TaskNode(Node):
    def __init__(self):
        super().__init__("citrus_s01_task")
        sim_share = Path(get_package_share_directory("citrus_pruning_sim"))
        self.declare_parameter("model_path", str(sim_share / "data" / "tree_model.json"))
        self.declare_parameter("output_root", "")
        self.declare_parameter("offset_mm", -1.0)      # < 0: use the scene stump length
        self.declare_parameter("play", True)
        self.declare_parameter("hold_at_cut_s", 1.0)
        self.declare_parameter("reuse_transit", "")    # demo only; acceptance needs ""
        self.declare_parameter("auto_start", False)
        self.declare_parameter("auto_start_delay_s", 8.0)
        self.declare_parameter("exit_after_auto_start", False)
        self._lock = threading.Lock()
        self.done = False
        self.last_passed = None
        latched = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.result_pub = self.create_publisher(String, "/citrus_task/result", latched)
        self.create_service(Trigger, "/citrus_task/run_s01", self._on_trigger)
        self.get_logger().info("Ready. Trigger: ros2 service call /citrus_task/run_s01 std_srvs/srv/Trigger {}")
        if self.get_parameter("auto_start").value:
            self._timer = self.create_timer(float(self.get_parameter("auto_start_delay_s").value), self._auto)

    def _config(self):
        root = self.get_parameter("output_root").value or str(default_output_root())
        stamp = time.strftime("%Y%m%d_%H%M%S")
        offset = float(self.get_parameter("offset_mm").value)
        reuse = self.get_parameter("reuse_transit").value
        return TaskConfig(model=Path(self.get_parameter("model_path").value),
                          output=Path(root).expanduser() / stamp,
                          offset_mm=None if offset < 0 else offset,
                          reuse_transit=Path(reuse).expanduser() if reuse else None,
                          play=bool(self.get_parameter("play").value),
                          hold_at_cut_s=float(self.get_parameter("hold_at_cut_s").value))

    def run_once(self):
        if not self._lock.acquire(blocking=False):
            return False, "An S01 round is already running"
        helper = rclpy.create_node("citrus_s01_task_client", use_global_arguments=False)
        try:
            config = self._config()
            self.get_logger().info(f"S01 round started; output {config.output}")
            report = execute(Planner(helper), config, log=lambda text: self.get_logger().info(text))
        finally:
            helper.destroy_node()
            self._lock.release()
        acceptance = report["acceptance"]
        self.last_passed = acceptance["passed"]
        summary = {"success": report["success"], "acceptance_passed": acceptance["passed"],
                   "output_dir": report["output_dir"], "error": report.get("error"),
                   "segments": report.get("segments"), "world_after": report.get("world_after")}
        self.result_pub.publish(String(data=json.dumps(summary)))
        self.get_logger().info("S01 acceptance:\n" + format_checks(acceptance))
        message = f"acceptance={'PASSED' if acceptance['passed'] else 'FAILED'}; result: {config.output}/result.json"
        if report.get("error"):
            message += f"; error: {report['error']}"
        return acceptance["passed"], message

    def _on_trigger(self, _request, response):
        response.success, response.message = self.run_once()
        return response

    def _auto(self):
        self._timer.cancel()
        self.run_once()
        if self.get_parameter("exit_after_auto_start").value:
            self.done = True


def main(args=None):
    error = isolation_error()
    if error:
        raise SystemExit(error)
    rclpy.init(args=args)
    node = S01TaskNode()
    # A private executor: the helper node used inside the task spins on the global one.
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    try:
        while rclpy.ok() and not node.done:
            executor.spin_once(timeout_sec=0.2)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        passed = node.last_passed
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    return 0 if passed in (None, True) else 1


if __name__ == "__main__":
    raise SystemExit(main())
