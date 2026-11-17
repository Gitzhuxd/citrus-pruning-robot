# Experiments & Archived Runs

This directory holds reference baselines and reproduction notes for the citrus pruning project.

## Directory Layout

- `s01_baseline/reference/` — Frozen S01 reference outputs copied from the verified runs (`s01_stump_demo_v1/verified_stump_replay` and `s01_closure_demo_v1/check_6`), used by `citrus_pruning_task` unit tests (`test_acceptance.py`).

## Reproducing Legacy Experiments (Preserved at Workspace Root)

All historical experiment directories at the workspace root retain their original scripts, data, relative paths, and `COLCON_IGNORE` markers (so `colcon build` in `~/aubo_ws` only builds `src/`):

1. **`s01_stump_demo_v1/`** (S01 verified baseline with 6 mm stump + axial disengagement):
   - Launch: `ROS_DOMAIN_ID=94 ROS_LOCALHOST_ONLY=1 ros2 launch ./simulation.launch.py rviz:=false s01_cut_offset_m:=0.006`
   - Run: `python3 cut_s01.py --model citrus_pruning_sim/data/tree_model.json --output <dir> --play`
   - Note: `source /opt/ros/humble/setup.bash && source ../install/setup.bash && source install/local_setup.bash` inside `s01_stump_demo_v1/`.
2. **`approach_benchmark_v1/`** (72-trial fixed vs. multi-candidate approach benchmark):
   - Source: `source /opt/ros/humble/setup.bash && source ../install/setup.bash && source ../src/ros2_critrus/install/setup.bash`
   - Run `benchmark.py` or `review_approach.py` in `ROS_DOMAIN_ID=92` (S01) / `93` (S07).
3. **`pruning_retry_v1/`** and **`pruning_closure_screen_v1/`**:
   - Use `run_formal.sh` / `run_closure_comparison.sh` / `run_s07_wrap.sh` inside each directory (they source `../install/setup.bash` then `install/local_setup.bash`).
4. **`pruning_seeded_s07_v1/`** (Seeded OMPL RRT S07 comparison):
   - Uses its own `install/local_setup.bash` (overriding `aubo_ompl_capture` with `CITRUS_OMPL_SEED` support) and `run_batch.py` in `ROS_DOMAIN_ID=98`.
