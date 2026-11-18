# 仿真实验

从项目根目录运行实验，启动前按 [项目首页](../README.md) 构建并加载本项目的安装环境。

## S01 验收

`s01_baseline/reference/` 保存自动测试使用的固定参考结果。日常验收脚本会触发两次新规划，检查首次轨迹回放后的剪切场景，复位后验证第二次计划及完整验收记录。

在已加载本项目安装环境的两个终端中设置相同的 `ROS_DOMAIN_ID` 和 `ROS_LOCALHOST_ONLY=1`。终端一启动：

```bash
ros2 launch citrus_pruning_task simulation.launch.py rviz:=false
```

终端二运行，输出目录每次选一个新名称：

```bash
python3 experiments/s01_baseline/probe_s01.py results/s01_smoke_new
```

查看输出目录中的 `runtime_audit.json`，`success: true` 表示两次运行均通过。

## S07 固定目标

S07 的目标关节角、树模型和校验所需数据都随项目保存。按 [启动与回放说明](s07_fixed_goal/README.md) 检查两种关节表示的仿真效果。
