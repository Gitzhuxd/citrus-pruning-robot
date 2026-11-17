# S07 on the shared pruning task

This smoke test uses the archived S07 `−90°/+1` six-joint goal. It checks
the live joint limits, starting state, precut pose and exact joint target,
then runs the same insertion, closure, scene update and withdrawal used
by S01. It still uses the daily native OMPL launcher; the archived seeded
experiment remains the reference for the 1.5-second transfer and 8-second
task comparison.

Build and source this workspace, as in the S01 instructions. Use one
unused simulation domain in both terminals with ROS_LOCALHOST_ONLY=1.

```bash
ros2 launch citrus_pruning_task simulation.launch.py rviz:=false task:=false \
  tree_x:=1.093761543 tree_y:=0.601040764 tree_z:=0.0 tree_yaw:=3.926990817 \
  partial_cut_target:=S07 s01_cut_offset_m:=0.006
```

Then start one fresh run. Choose a new output directory for every attempt.

```bash
python3 experiments/s07_fixed_goal/run_fixture.py \
  --source ~/aubo_ws/pruning_seeded_s07_v1/source_results.json \
  --candidate wrapped_04 --output results/s07_smoke_new --play
```

A successful result must contain all five motion stages, replace
`citrus_S07` with `citrus_S07_stump` during replay, preserve S01, and
restore the intact tree afterward. The run publishes simulated joint
states; set `rviz:=true` on a graphical Ubuntu session to watch it.
