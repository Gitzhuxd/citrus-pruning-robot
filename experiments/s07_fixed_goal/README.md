# S07 固定目标仿真

`source_results.json` 是随项目保存的成对实验基线，脚本用它读取 S07 的 `−90°/+1` 固定六关节目标，并校验树的位置、姿态和模型版本。可选的 `--source` 只接受内容完全相同的基线副本。

按 [项目首页](../../README.md) 构建并加载本项目的安装环境。两个终端使用同一个空闲 `ROS_DOMAIN_ID`，并设置 `ROS_LOCALHOST_ONLY=1`。终端一启动 S07 场景：

```bash
ros2 launch citrus_pruning_task simulation.launch.py rviz:=false task:=false \
  tree_x:=1.093761543 tree_y:=0.601040764 tree_z:=0.0 tree_yaw:=3.926990817 \
  partial_cut_target:=S07 s01_cut_offset_m:=0.006
```

终端二从项目根目录运行一次新的规划、检查和仿真回放。每次选新的输出目录。需要检查原始关节表示时，可将 `wrapped_04` 改为 `raw_04`。

```bash
python3 experiments/s07_fixed_goal/run_fixture.py \
  --candidate wrapped_04 --output results/s07_smoke_new --play
```

通过验收的运行包含五个运动阶段，回放时 S07 变为 6 mm 残桩并保留 S01，最后恢复完整树模型。结果见输出目录中的 `result.json`、`fixture.json` 和轨迹文件。在 Ubuntu 图形桌面上可用 `rviz:=true` 观看。

## 重放本次轨迹

独立回放会读取同一目录下的成功结果，校验轨迹摘要后更新目标场景。只查看机械臂动作时可省略 `--commit-cut`。

```bash
ros2 run citrus_pruning_task s01_replay results/s07_smoke_new/display_trajectory.cdr --commit-cut
ros2 service call /citrus/reset std_srvs/srv/Trigger '{}'
```
