"""Replay a saved S01 DisplayTrajectory in the running simulation (demonstration only).

    ros2 run citrus_pruning_task s01_replay <display_trajectory.cdr> [--commit-cut] [--hold-at-cut 1.0]

Works for new results (results/s01/<stamp>/display_trajectory.cdr) and for archived
ones, e.g. s01_stump_demo_v1/verified_stump_replay/display_trajectory.cdr.
This is NOT the acceptance run: it does not plan, it only moves the simulated joints.
"""
import argparse
import time
from pathlib import Path

import rclpy
from moveit_msgs.msg import DisplayTrajectory
from rclpy.serialization import deserialize_message

from .isolation import isolation_error
from .planner import Planner, replay
from .s01_task import TARGET, scene_command


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("trajectory", type=Path)
    parser.add_argument("--hold-at-cut", type=float, default=1.0)
    parser.add_argument("--commit-cut", action="store_true",
                        help="Reset the scene first, then cut S01 after the closure segment (index 2)")
    args, ros_args = parser.parse_known_args()
    error = isolation_error()
    if error:
        parser.error(error)
    message = deserialize_message(args.trajectory.read_bytes(), DisplayTrajectory)
    rclpy.init(args=ros_args)
    node = rclpy.create_node("citrus_s01_replay")
    planner = Planner(node)
    try:
        def after_cut(index):
            if index == 2:
                scene_command(planner, "cut/" + TARGET)
                time.sleep(1.0)

        if args.commit_cut:
            scene_command(planner, "reset")
        replay(node, message, hold_at_cut=args.hold_at_cut,
               after_segment=after_cut if args.commit_cut else None)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
