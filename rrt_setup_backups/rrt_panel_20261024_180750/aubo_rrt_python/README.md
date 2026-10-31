# AUBO i5 Python RRT 仿真演示

已直接安装到 `/home/zhuxd/aubo_ws/src/aubo_rrt_python`。
使用 ROS 2 Humble 和现有 MoveIt 仿真服务。

## 运行

若原来的 demo 正在运行，先在它的启动终端按 Ctrl+C。
在 **Ubuntu 图形桌面中打开的终端**启动原来的仿真：

```bash
source /opt/ros/humble/setup.bash
source ~/aubo_ws/install/setup.bash
source ~/rvizsplat_humble_ws/install/local_setup.bash
ros2 launch aubo_i5_scissors_moveit_config demo.launch.py
```

普通 Windows SSH 终端没有自动连接 Ubuntu 图形桌面，不能用它直接打开 RViz。
Python 节点本身没有窗口，可在 Ubuntu 或 SSH 的另一终端运行：

```bash
source /opt/ros/humble/setup.bash
source ~/aubo_ws/install/setup.bash
ros2 run aubo_rrt_python rrt_demo
```

该包已经编译；更改 `.py` 文件后保存并重新运行即可。
不要同时运行多个同名 Python 节点。

## 预期画面

原机械臂、Gaussian 果树变换及相机视角保留，配置中新增 `PythonRRT` 显示。
绿色球为起点 home 的剪刀 TCP，红色球为目标 pose1 的 TCP。
蓝色小球和灰蓝线表示真实 RRT 树节点、边的 TCP 投影。
搜索结束后按节点接受顺序回放，每个节点间隔 0.08 秒。
回放结束显示金色路径，并通过 MotionPlanning 的 Planned Path 播放机械臂轨迹。
默认保留节点运行，按 Ctrl+C 结束。需要重看探索过程时重新运行 Python 节点。

MarkerArray 使用 `/rrt_python/markers`，Reliable、Transient Local、depth 1。
每条消息都是完整快照，晚打开 RViz 也能得到完整结果。
轨迹预览使用 `/display_planned_path`，消息类型为 MoveIt 的
[DisplayTrajectory](https://github.com/moveit/moveit_msgs/blob/ros2/msg/DisplayTrajectory.msg)。
没有发布关节反馈或调用运动执行接口。

若 RViz 已经打开，可使用 File → Open Config 打开下面这个文件来加载新增显示：

```text
/home/zhuxd/aubo_ws/src/aubo_i5_scissors_moveit_config/config/moveit.rviz
```

## 算法与数据

- 六维有界关节空间内的基础单树 RRT，欧氏距离，不做角度绕回、RRT* 重连或平滑。
- 关节名称顺序固定并按名称映射，保持剪刀及其 mimic 关节状态。
- 命名状态和关节范围从当前 `/move_group` 的 URDF/SRDF 参数读取。
- 每条边及最后的目标连接都检查中间状态；搜索最大单关节插值间隔为 0.04 rad。
- 最终路径以 0.02 rad 间隔重新检查，再生成 TCP 曲线及轨迹预览。
- 树边显示也使用关节插值的 FK 曲线，而非直接连接两个 TCP 端点。
- 这是离散碰撞检查，并非连续碰撞保证；Gaussian 果树目前没有配套碰撞体。
- 限位沿用当前仿真模型，实体机械臂规格仍待确认。
- 12 秒轨迹时间仅用于演示，未按速度、加速度约束做控制器执行所需的时间参数化。

每次运行自动创建目录：

```text
/home/zhuxd/aubo_ws/rrt_results/python/日期_时间/
  tree.csv       节点编号、父节点、六轴关节角、TCP 坐标
  path.csv       最终细化路径的关节角和 TCP 坐标
  summary.json   随机种子、参数、节点数、检查次数、路径长度及耗时
```

规划墙钟时间包括 Python、服务通信及生成树显示数据的开销；慢放回放时间不计入。
它不能直接和 OMPL C++ 的内部求解时间比较。此 Python 树也不是 RViz 点击 Plan 时的 OMPL 树。

## 参数示例

默认参数：seed=42、step_size=0.3 rad（六维 L2 距离）、goal_bias=0.1、
collision_step=0.04 rad、max_iterations=2500、planning_time=60.0 秒。

换随机种子并放慢回放：

```bash
ros2 run aubo_rrt_python rrt_demo --ros-args -p seed:=7 -p replay_step:=0.15
```

关闭回放、保留最后结果：

```bash
ros2 run aubo_rrt_python rrt_demo --ros-args -p replay_step:=0.0
```

`keep_alive:=false` 只适合自动验证：运行结束即退出，不能供晚打开的 RViz 接收消息。

## 文件与验证

`rrt_demo.py`：MoveIt 服务、状态与限位读取、回放、轨迹消息、CSV 导出。
`rrt_core.py`：采样、最近节点、扩展、整边检查、目标连接、父节点回溯。
`rrt_markers.py`：RViz 标记完整快照。

核心算法测试：

```bash
cd ~/aubo_ws/src/aubo_rrt_python
python3 -m unittest discover -s test -p test_rrt_core.py -v
```

本次测试：11 项核心测试通过；默认 home → pose1 为 47 次迭代、49 个树节点、
15 个路径节点、145 个细化路径状态。独立联调进一步检查了全部树边的 532 个状态，
以及 145 个路径坐标的 FK 一致性；真实回放和晚订阅完整消息检查通过。
验收数据位于 `/home/zhuxd/aubo_ws/rrt_results/python_verification/`。

修改前备份：
`/home/zhuxd/aubo_ws/rrt_setup_backups/python_rrt_20261023_225132/`。
备份含 `COLCON_IGNORE`，不会被 colcon 识别为重复包。
