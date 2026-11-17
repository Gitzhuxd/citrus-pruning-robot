# Simulation Results

Runtime outputs from `citrus_pruning_task` are saved here (ignored by Git):

- `results/s01/<YYYYmmdd_HHMMSS>/result.json` — Stage metrics, collision world counts before/after, and `acceptance` check results.
- `results/s01/<YYYYmmdd_HHMMSS>/display_trajectory.cdr` — Serialized `moveit_msgs/msg/DisplayTrajectory` for RViz replay (`ros2 run citrus_pruning_task s01_replay <path>`).
