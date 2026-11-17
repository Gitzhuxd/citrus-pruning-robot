"""S01 pruning task: transit -> insertion -> closure -> scene update -> retreat.

The stage logic is taken from the verified experiment script ``cut_s01.py``
(``s01_stump_demo_v1`` run ``verified_stump_replay``; the generalised copy in
``pruning_retry_v1`` / ``pruning_closure_screen_v1`` keeps identical S01 defaults).
Changes for the packaged version:

* configuration comes from a ``TaskConfig`` object instead of argparse;
* every run first calls ``/citrus/reset`` so that the scene starts complete
  and the robot plans again from the fixed SRDF ``home`` state;
* the acceptance summary from ``acceptance.py`` is added to the report.
"""
import json
import math
import time
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from pathlib import Path
from typing import Optional

import numpy as np
import rclpy
from ament_index_python.packages import get_package_share_directory
from moveit_msgs.msg import DisplayTrajectory, RobotState, RobotTrajectory
from moveit_msgs.srv import GetStateValidity
from rclpy.duration import Duration
from rclpy.qos import DurabilityPolicy, QoSProfile
from rclpy.serialization import deserialize_message, serialize_message
from scipy.spatial.transform import Rotation
from std_msgs.msg import String
from std_srvs.srv import Trigger
from trajectory_msgs.msg import JointTrajectoryPoint

from .acceptance import evaluate
from .planner import (MOUTH_OFFSET, OPEN_JOINT, OPEN_MIMIC, OPEN_POSITION,
                      joint_values, replay, to_pose, unit, with_positions)
from .scene_checks import tree_transform, verify_world, world_counts


TARGET = "S01"
SHOOT = "citrus_" + TARGET
STUMP = SHOOT + "_stump"
BLADES = {"scissor_active_blade_link", "scissor_mimic_blade_link"}
STANDOFF_M = 0.12  # precut distance used by every recorded S01 run


@dataclass
class TaskConfig:
    model: Path
    output: Path
    offset_mm: Optional[float] = None   # None: use the scene stump length (6 mm in the verified scene)
    reuse_transit: Optional[Path] = None  # demonstration only; acceptance requires None
    play: bool = True
    hold_at_cut_s: float = 1.0
    reset_before_run: bool = True


def scene_command(planner, name):
    client = planner.node.create_client(Trigger, "/citrus/" + name)
    try:
        response = planner.call(client, Trigger.Request(), timeout=15.0)
        if not response.success:
            raise RuntimeError(f"{name}: {response.message}")
    finally:
        planner.node.destroy_client(client)


def scene_stump_offset(planner, target=TARGET):
    messages = []
    sub = planner.node.create_subscription(
        String, "/citrus/state", messages.append, QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL))
    try:
        deadline = time.monotonic() + 5.0
        while time.monotonic() < deadline:
            rclpy.spin_once(planner.node, timeout_sec=0.1)
            if messages:
                state = json.loads(messages.pop().data)
                if state["moveit_sync"] == "synchronized":
                    if "partial_cut_target" in state:
                        if state["partial_cut_target"] != target:
                            raise RuntimeError(
                                f"Expected partial-cut target {target}, got {state['partial_cut_target']}")
                        return state["cut_offset_m"]
                    if target != TARGET:
                        raise RuntimeError(f"Legacy scene does not provide a stump offset for {target}")
                    return state.get("s01_cut_offset_m", 0.0)
    finally:
        planner.node.destroy_subscription(sub)
    raise RuntimeError("Missing synchronized /citrus/state; check the scene node and resync MoveIt")


def closed_blade_angle(srdf):
    joint = srdf.find(f"./group_state[@name='scissor_closed'][@group='scissor']/joint[@name='{OPEN_JOINT}']")
    if joint is None:
        raise RuntimeError("Missing the scissor_closed joint state")
    angle = float(joint.attrib["value"])
    if angle <= OPEN_POSITION:
        raise ValueError("Expected a nominal closed angle beyond the open angle")
    return angle


def check_closure(planner, cut_state, closed_angle, report, shoot=SHOOT):
    """Close the blades in 0.005 rad steps; only blade-to-target contacts are allowed."""
    closure = RobotTrajectory()
    closure.joint_trajectory.joint_names = [OPEN_JOINT, OPEN_MIMIC]
    divisions = math.ceil(abs(closed_angle - OPEN_POSITION) / 0.005)
    allowed = {tuple(sorted((blade, shoot))) for blade in BLADES}
    target_contacts = set()
    state = cut_state
    for index, angle in enumerate(np.linspace(OPEN_POSITION, closed_angle, divisions + 1)):
        state = with_positions(cut_state, {}, blade_position=float(angle))
        response = planner.call(planner.valid, GetStateValidity.Request(robot_state=state))
        pairs = {tuple(sorted((c.contact_body_1, c.contact_body_2))) for c in response.contacts}
        target_contacts.update(pairs & allowed)
        report.update(samples=index + 1, target_contacts=sorted(target_contacts))
        if not response.valid and (not pairs or pairs - allowed):
            report.update(status="blocked", blocked_at_rad=float(angle), contacts=sorted(pairs - allowed))
            return None, None
        closure.joint_trajectory.points.append(JointTrajectoryPoint(
            positions=[float(angle), -float(angle)],
            time_from_start=Duration(seconds=2.0 * index / divisions).to_msg()))
    if target_contacts != allowed:
        report["status"] = "target_contact_incomplete"
        return None, None
    report["status"] = "passed"
    return state, closure


def state_contacts(planner, state):
    result = planner.call(planner.valid, GetStateValidity.Request(robot_state=state))
    depths = {}
    for contact in result.contacts:
        pair = tuple(sorted((contact.contact_body_1, contact.contact_body_2)))
        depths[pair] = max(depths.get(pair, 0.0), abs(contact.depth))
    return result.valid, depths


def pose_position(pose):
    return np.array([pose.position.x, pose.position.y, pose.position.z])


def plan_retreat(planner, closed_state, goal, approach, rotation, branch, report, *,
                 stump=STUMP, separation_m=0.005):
    """Axial disengagement from the stump (if touching), then a straight withdrawal."""
    valid, initial = state_contacts(planner, closed_state)
    trajectories = []
    if not valid:
        allowed = {tuple(sorted((blade, stump))) for blade in BLADES}
        if not initial or initial.keys() - allowed:
            raise ValueError(f"Unexpected contacts at closed retreat start: {sorted(initial)}")
        lift = separation_m * branch
        lifted = to_pose(goal + lift, rotation)
        origin = pose_position(planner.fk_pose(closed_state, "disengagement start FK"))
        prefix, fraction = planner.straight(closed_state, lifted, "disengagement",
                                            max_step=0.0005, avoid_collisions=False)
        previous_contacts = initial
        previous_point = origin
        trace = []

        def verify_disengagement(state, label):
            nonlocal previous_contacts, previous_point
            pose = planner.fk_pose(state, label + " FK")
            point = pose_position(pose)
            delta = point - origin
            travel = float(delta @ branch)
            q = pose.orientation
            angular_error = (rotation.inv() * Rotation.from_quat([q.x, q.y, q.z, q.w])).magnitude()
            if (not -0.00005 <= travel <= separation_m + 0.00005
                    or (point - previous_point) @ branch < -0.00005
                    or np.linalg.norm(point - previous_point) > 0.001
                    or np.linalg.norm(delta - travel * branch) > 0.0001
                    or angular_error > math.radians(0.2)):
                raise ValueError(f"{label}: tool left the bounded axial separation path")
            is_valid, depths = state_contacts(planner, state)
            if depths.keys() - previous_contacts.keys() or (not is_valid and not depths):
                raise ValueError(f"{label}: new or unknown contact {sorted(depths)}")
            trace.append({"travel_mm": 1000.0 * travel,
                          "contacts": [(*pair, depth) for pair, depth in sorted(depths.items())]})
            previous_contacts, previous_point = depths, point

        closed_state, metrics = planner.validate_trajectory(
            prefix, closed_state, lifted, "disengagement", state_check=verify_disengagement, joint_step=0.0005)
        planner.valid_state(closed_state, "disengagement endpoint")
        report["disengagement"] = {**metrics, "fraction": fraction, "lift_mm": 1000.0 * separation_m,
                                   "start_contact_depth_m": [(*pair, depth) for pair, depth in sorted(initial.items())],
                                   "sample_trace": trace}
        goal = goal + lift
        trajectories.append(prefix)

    precut = to_pose(goal - STANDOFF_M * approach, rotation)
    withdrawal, fraction = planner.straight(closed_state, precut, "withdrawal")
    _, metrics = planner.validate_trajectory(withdrawal, closed_state, precut, "withdrawal")
    report["withdrawal"] = {**metrics, "fraction": fraction}
    return [*trajectories, withdrawal]


def run(planner, config: TaskConfig, report, log=print):
    """Plan and check the full S01 chain. Fills ``report``; raises on failure."""
    path = Path(get_package_share_directory("aubo_i5_scissors_moveit_config"))
    srdf = ET.parse(path / "config/aubo_i5_scissors_robot.srdf").getroot()
    arm = {joint.attrib["name"]: float(joint.attrib["value"])
           for joint in srdf.findall("./group_state[@name='home'][@group='aubo_arm']/joint")}
    if len(arm) != 6:
        raise RuntimeError("Expected six home arm joints")
    closed = closed_blade_angle(srdf)
    model = json.loads(config.model.read_text(encoding="utf-8"))
    if model["frame_id"] != "tree_base" or model["units"] != "m":
        raise ValueError("Expected a metric tree_base model")
    target = next(target for target in model["targets"] if target["id"] == TARGET)

    if config.reset_before_run:
        log("[0/6] reset scene: /citrus/reset")
        scene_command(planner, "reset")
    translation, tree_rotation = tree_transform(planner.node)
    branch = unit(tree_rotation.apply(target["axis"]))
    approach = tree_rotation.apply(target["approach"])
    approach = unit(approach - np.dot(approach, branch) * branch)
    rotation = Rotation.from_matrix(np.column_stack([branch, np.cross(approach, branch), approach]))
    junction = tree_rotation.apply(target["position"]) + translation
    stump_offset = scene_stump_offset(planner)
    offset = config.offset_mm * 0.001 if config.offset_mm is not None else (stump_offset or 0.006)
    cut = junction + offset * branch
    goal = cut - rotation.apply(MOUTH_OFFSET)
    precut_pose = to_pose(goal - STANDOFF_M * approach, rotation)
    cut_pose = to_pose(goal, rotation)
    report.update(tree_xyz_world_m=translation.tolist(), tree_quaternion_xyzw=tree_rotation.as_quat().tolist(),
                  junction_world_m=junction.tolist(), cut_world_m=cut.tolist(),
                  shoot_offset_mm=1000.0 * offset, scene_stump_length_mm=1000.0 * stump_offset,
                  open_rad=OPEN_POSITION, closed_rad=closed, precut_distance_m=STANDOFF_M)

    before = verify_world(planner, model, None)
    report["world_before"] = before
    start = with_positions(RobotState(), arm)
    report["start_joints"] = joint_values(start)
    planner.valid_state(start, "open-scissor home")

    log("[1/6] transit: IK /compute_ik + OMPL /plan_kinematic_path from SRDF home")
    if config.reuse_transit:
        saved = deserialize_message(config.reuse_transit.read_bytes(), DisplayTrajectory)
        if saved.model_id != srdf.attrib["name"] or not saved.trajectory:
            raise ValueError("The saved transit uses a different robot or is empty")
        transit = saved.trajectory[0]
    else:
        pre_ik = planner.inverse(start, precut_pose, arm)
        transit = planner.transit(start, pre_ik, arm)
    pre_state, report["stages"]["transit"] = planner.validate_trajectory(transit, start, precut_pose, "transit")
    report["stages"]["transit"]["reused"] = config.reuse_transit is not None

    log("[2/6] insertion: straight 120 mm via /compute_cartesian_path")
    insertion, fraction = planner.straight(pre_state, cut_pose, "insertion")
    cut_state, in_metrics = planner.validate_trajectory(insertion, pre_state, cut_pose, "insertion")
    report["stages"]["insertion"] = {**in_metrics, "fraction": fraction}

    log("[3/6] closure: blade sweep checked with /check_state_validity")
    closed_state, closure = check_closure(planner, cut_state, closed, report["stages"].setdefault("closure", {}))
    if closure is None:
        report["world_after"] = world_counts(planner)
        if report["world_after"] != before:
            raise RuntimeError("The scene changed despite closure failure")
        raise ValueError(f"closure: {report['stages']['closure'].get('status')}")

    expected = {name: count for name, count in before.items() if name != SHOOT}
    if stump_offset:
        if not math.isclose(offset, stump_offset, abs_tol=1e-8, rel_tol=0):
            raise ValueError("Planned cut and scene stump lengths differ; no cut was committed")
        expected[STUMP] = 1

    def commit_cut():
        scene_command(planner, "cut/" + TARGET)
        after = world_counts(planner)
        if after != expected:
            raise RuntimeError(f"Unexpected post-cut scene: {after}")
        return after

    log("[4/6] scene update: /citrus/cut/S01 (shoot removed, stump kept), then retreat preflight")
    # Preflight the retreat in the post-cut world, then reset for synchronized playback.
    try:
        report["world_after"] = commit_cut()
        log("[5/6] retreat: axial disengagement + straight withdrawal via /compute_cartesian_path")
        retreat = plan_retreat(planner, closed_state, goal, approach, rotation, branch, report["stages"])
    finally:
        scene_command(planner, "reset")
        verify_world(planner, model, None)

    display = DisplayTrajectory(model_id=srdf.attrib["name"], trajectory_start=start,
                                trajectory=[transit, insertion, closure, *retreat])
    (config.output / "display_trajectory.cdr").write_bytes(serialize_message(display))
    report["segments"] = ["transit", "insertion", "closure", *(
        ["disengagement"] if "disengagement" in report["stages"] else []), "withdrawal"]
    if config.play:
        log("[6/6] RViz replay on /citrus/s01/joint_states; scene is cut after the closure segment")

        def on_segment_end(index):
            if index == 2:
                report["replay_world_after"] = commit_cut()
                time.sleep(1.0)

        replay(planner.node, display, hold_at_cut=config.hold_at_cut_s, after_segment=on_segment_end)
    report["success"] = True


def execute(planner, config: TaskConfig, log=print):
    """Run once, always write ``result.json`` and return the report."""
    config.output.mkdir(parents=True, exist_ok=False)
    report = {"target": TARGET, "success": False, "fracture_physics": False, "stages": {},
              "output_dir": str(config.output),
              "parameters": {"offset_mm": config.offset_mm, "play": config.play,
                             "reuse_transit": str(config.reuse_transit) if config.reuse_transit else None,
                             "model": str(config.model)}}
    started = time.monotonic()
    try:
        run(planner, config, report, log)
    except (ValueError, RuntimeError) as exc:
        report["error"] = str(exc)
    finally:
        report["wall_time_s"] = time.monotonic() - started
        report["acceptance"] = evaluate(report)
        (config.output / "result.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    return report
