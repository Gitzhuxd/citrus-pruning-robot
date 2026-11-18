"""Use the shared task to exercise one archived S07 joint goal in simulation."""

import argparse
import hashlib
import json
from pathlib import Path

import numpy as np
import rclpy
from ament_index_python.packages import get_package_share_directory
from scipy.spatial.transform import Rotation

from citrus_pruning_task.isolation import isolation_error
from citrus_pruning_task.planner import OPEN_JOINT, OPEN_MIMIC, Planner
from citrus_pruning_task.s01_task import TaskConfig, execute, scene_command, scene_stump_offset
from citrus_pruning_task.scene_checks import tree_transform, world_counts


SOURCE_HASH = "82a7146dccb2fa134ba9f4e0bf1e3d7b7d7e55df803580daeedca18ec5aab17a"
MODEL_HASH = "70fd014449358300987381e2385234799d0bfe00e6cbc9e918771e55702ab82f"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=Path(__file__).resolve().with_name("source_results.json"),
                        help="Use a matching S07 source file instead of the bundled fixture")
    parser.add_argument("--candidate", choices=("raw_04", "wrapped_04"), required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--play", action="store_true", help="Play the verified simulated cut, then reset")
    args = parser.parse_args()
    if error := isolation_error():
        parser.error(error)
    source = args.source.read_bytes()
    sim_share = Path(get_package_share_directory("citrus_pruning_sim"))
    model = sim_share / "data" / "tree_model.json"
    if hashlib.sha256(source).hexdigest() != SOURCE_HASH:
        parser.error("Source differs from the archived paired experiment")
    if hashlib.sha256(model.read_bytes()).hexdigest() != MODEL_HASH:
        parser.error("Installed scene model differs from the archived S07 model")
    archived = json.loads(source)
    baseline = archived["config"]
    row = next(x for x in archived["trials"] if x["trajectory_id"] == args.candidate)
    attempt, = row["attempts"]
    joints = {name: value for name, value in attempt["pre_ik_joints"].items()
              if name not in (OPEN_JOINT, OPEN_MIMIC)}
    task = TaskConfig(model=model, output=args.output.resolve(), target="S07", play=args.play,
                      approach_angle_deg=attempt["angle_deg"], normal_sign=attempt["normal_sign"],
                      fixed_joints=joints)
    rclpy.init()
    node = rclpy.create_node("citrus_s07_fixture")
    try:
        planner = Planner(node)
        translation, rotation = tree_transform(node)
        if not np.allclose(translation, baseline["tree_xyz_world_m"], atol=1e-6, rtol=0) or (
                Rotation.from_quat(baseline["tree_quaternion_xyzw"]).inv() * rotation).magnitude() > 1e-6:
            parser.error("Launch the archived S07 tree pose before using a fixed goal")
        offset = scene_stump_offset(planner, target="S07")
        if abs(offset - baseline["retained_stump_m"]) > 1e-8:
            parser.error("The scene must retain a 6 mm stump for S07")
        report = execute(planner, task)
        note = {"candidate": args.candidate, "source_trajectory_id": row["source_trajectory_id"],
                "source_sha256": SOURCE_HASH, "model_sha256": MODEL_HASH, "fixed_goal_rad": joints,
                "historical_timing_reproduction": False, "success": report["acceptance"]["passed"]}
        try:
            if report["acceptance"]["passed"] and args.play:
                after = world_counts(planner)
                if after != report["world_after"] or report["replay_world_after"] != after:
                    raise RuntimeError(f"Playback ended with the wrong collision world: {after}")
                note["after_replay"] = after
            scene_command(planner, "reset")
            note["after_reset"] = world_counts(planner)
            if "world_before" in report and note["after_reset"] != report["world_before"]:
                raise RuntimeError("Reset did not restore the intact collision scene")
        except (RuntimeError, ValueError) as exc:
            note.update(success=False, error=str(exc))
        (task.output / "fixture.json").write_text(json.dumps(note, indent=2) + "\n")
        print(json.dumps(note), flush=True)
        return 0 if note["success"] else 1
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    raise SystemExit(main())
