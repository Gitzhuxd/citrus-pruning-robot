# 仿真构建与启动

在 Ubuntu 22.04 和 ROS 2 Humble 上运行 AUBO 机器人的剪切规划与仿真回放。S01 是日常点检任务，S07 使用随项目保存的固定关节目标，便于复查剪切和退刀过程。

| 目录 | 用途 |
| --- | --- |
| `src/citrus_pruning_task/` | 仿真启动、任务规划、回放与验收 |
| `src/citrus_pruning_sim/` | 柑橘树模型、剪后场景和复位服务 |
| `src/aubo_i5_scissors_description/` | 机器人、剪刀和相机装配模型 |
| `src/aubo_i5_scissors_moveit_config/` | MoveIt 配置 |
| `experiments/` | S01 验收脚本、S07 固定目标数据和运行说明 |
| `results/` | 本次工作区生成的轨迹、验收记录和诊断结果 |

## 构建

在装有 ROS 2 Humble、MoveIt 2、RViz 2 和 colcon 的 Ubuntu 终端中，进入本项目根目录。先打开干净的 Bash 环境，避免继承登录脚本加载的其他 ROS 工作区。

```bash
env -i HOME="$HOME" USER="$USER" PATH=/usr/local/bin:/usr/bin:/bin LANG=C.UTF-8 \
  TERM="${TERM:-xterm}" DISPLAY="${DISPLAY:-}" \
  XAUTHORITY="${XAUTHORITY:-$HOME/.Xauthority}" \
  XDG_RUNTIME_DIR="${XDG_RUNTIME_DIR:-}" WAYLAND_DISPLAY="${WAYLAND_DISPLAY:-}" \
  bash --noprofile --norc
```

以下命令在这个干净的 Bash 中执行。colcon 会安装本项目中的模型与功能包。

```bash
source /opt/ros/humble/setup.bash
colcon build --packages-up-to citrus_pruning_task aubo_rrt_visualizer --symlink-install
source install/local_setup.bash
```

## 运行 S01

在项目根目录打开两个终端，按上面的方式分别进入干净的 Bash，再加载本项目。两个终端使用同一个空闲域，仿真允许的域为 91–99。

```bash
source /opt/ros/humble/setup.bash
source install/local_setup.bash
export ROS_DOMAIN_ID=94 ROS_LOCALHOST_ONLY=1
```

在第一个终端启动仿真。使用 SSH 时可以保留 `rviz:=false`，在 Ubuntu 图形桌面上可改为 `rviz:=true`。

```bash
ros2 launch citrus_pruning_task simulation.launch.py rviz:=false
```

在第二个终端触发规划并回放。验收记录和轨迹保存在 `results/s01/`。

```bash
ros2 service call /citrus_task/run_s01 std_srvs/srv/Trigger '{}'
```

需要检查回放、场景复位及再次规划时，使用 [S01 验收脚本](README.md)。运行 S07 请查看 [S07 固定目标说明](s07_fixed_goal/README.md)。
