"""Replay a saved DisplayTrajectory in the running simulation (demonstration only).

    ros2 run citrus_pruning_task s01_replay <display_trajectory.cdr> [--commit-cut] [--result <result.json>]

With --commit-cut, the matching successful result.json supplies the target and
the trajectory SHA256. The result defaults to the trajectory's sibling result.json.
Archived S01 trajectories without a SHA256 can still be played without --commit-cut.
Replay publishes simulated joint states and does not run planning or acceptance.
"""
import argparse
import hashlib
import json
import time
from pathlib import Path

import rclpy
from moveit_msgs.msg import DisplayTrajectory
from rclpy.serialization import deserialize_message

from .isolation import isolation_error
from .planner import OPEN_JOINT, OPEN_MIMIC, Planner, replay
from .s01_task import scene_command, scene_stump_offset


def paired_cut(result_path, trajectory_bytes, message):
    """Recover the recorded cut target and one unambiguous blade-closure segment."""
    report = json.loads(result_path.read_text(encoding="utf-8"))
    if not isinstance(report, dict) or report.get("success") is not True:
        raise ValueError("--commit-cut requires a successful result.json")
    target = report.get("target")
    if not isinstance(target, str) or not target:
        raise ValueError("The paired result does not contain a cut target")
    if not report.get("trajectory_sha256"):
        raise ValueError("The paired result lacks a trajectory SHA256; use visual playback without --commit-cut")
    if report["trajectory_sha256"] != hashlib.sha256(trajectory_bytes).hexdigest():
        raise ValueError("The trajectory SHA256 does not match the paired result")
    blade_joints = {OPEN_JOINT, OPEN_MIMIC}
    closures = []
    for index, segment in enumerate(message.trajectory):
        trajectory = segment.joint_trajectory
        if len(trajectory.joint_names) == 2 and set(trajectory.joint_names) == blade_joints:
            closures.append(index)
    if len(closures) != 1 or not message.trajectory[closures[0]].joint_trajectory.points:
        raise ValueError("Expected exactly one nonempty blade-closure segment")
    return target, closures[0]


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("trajectory", type=Path)
    parser.add_argument("--hold-at-cut", type=float, default=1.0)
    parser.add_argument("--commit-cut", action="store_true",
                        help="Reset the scene, then cut the recorded target when blade closure ends")
    parser.add_argument("--result", type=Path,
                        help="Result JSON for --commit-cut (default: result.json next to the trajectory)")
    args, ros_args = parser.parse_known_args()
    error = isolation_error()
    if error:
        parser.error(error)
    trajectory_bytes = args.trajectory.read_bytes()
    message = deserialize_message(trajectory_bytes, DisplayTrajectory)
    if args.commit_cut:
        try:
            target, closure_index = paired_cut(
                args.result or args.trajectory.with_name("result.json"), trajectory_bytes, message)
        except (OSError, ValueError) as exc:
            parser.error(str(exc))
    rclpy.init(args=ros_args)
    node = rclpy.create_node("citrus_s01_replay")
    planner = Planner(node)
    try:
        after_cut = None
        if args.commit_cut:
            scene_stump_offset(planner, target=target)
            scene_command(planner, "reset")

            def after_cut(index):
                if index == closure_index:
                    scene_command(planner, "cut/" + target)
                    time.sleep(1.0)

        replay(node, message, hold_at_cut=args.hold_at_cut,
               after_segment=after_cut)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
