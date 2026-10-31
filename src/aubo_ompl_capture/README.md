# RViz 同一次 OMPL RRT 规划的数据采集

目标：在原 MotionPlanning 面板点击 Plan，显示这次实际 OMPL RRT 的探索树、原始路径和处理后路径。

## 运行方式

保留原启动入口。在 Ubuntu 图形桌面终端运行：

```bash
source /opt/ros/humble/setup.bash
source ~/aubo_ws/install/setup.bash
source ~/rvizsplat_humble_ws/install/local_setup.bash
ros2 launch aubo_i5_scissors_moveit_config demo.launch.py
```

本次验收发现根分区已满，而 `/home` 有空间。在根分区清理之前，启动前在同一终端增加以下两行，
让 ROS launch 把临时参数文件放到工程目录（无需修改启动文件）：

```bash
mkdir -p ~/aubo_ws/tools/ompl_capture_tmp
export TMPDIR=~/aubo_ws/tools/ompl_capture_tmp
```

RViz 必须从已登录的 Ubuntu 图形桌面启动；普通 SSH 终端缺少显示环境，不能仅靠设置 TMPDIR 解决。

在原 MotionPlanning 面板选择 `aubo_arm`、`RRTkConfigDefault`，设置起终点，例如 home → pose1。
Planning Attempts 保持 1，然后点击 **Plan**。新增显示 `OMPL RRT Same Plan` 自动接收结果。
Python RRT 面板保留原功能，它属于另一套规划来源。

蓝色节点和灰色分支：真实 OMPL RRT 的探索树，经 scissor_tcp 正运动学投影。
黄色线：从同一棵树回溯的原始路径。
洋红线：经过 MoveIt 原有适配器（含时间参数化）后的路径。
各类 Marker 使用独立 namespace，可在新增显示项的 Namespaces 下分别开关。
树节点只是已被 RRT 接受的关节状态，线条是这些状态经关节插值、正运动学得到的 TCP 曲线。
若原始路径只有起终点，黄色和洋红色路径可能大部分重合，这是本次数据本身的结果。

## 接入方式

新插件 `aubo_ompl_capture/OMPLPlanner` 内部加载原装 `ompl_interface/OMPLPlanner`，并委托原有
initialize、配置、getPlanningContext、solve、terminate。没有实现第二套 RRT，也不会为采集再求解一次。

标准单次 RRT 的 PlannerData 保存真实 parent → child 边。GoalVertex 可能编号为 0，因此原始路径
严格按父子关系回溯，不把节点编号当作接受顺序。OMPL 的路径后处理操作复制后的状态，不会修改这棵树。

最外层 `aubo_ompl_capture/CaptureResult` 适配器在原适配器链返回后采集处理后的轨迹。
树和处理后轨迹通过当前同步调用的记录对象关联，使用相同 run_id。捕获错误不会触发第二次规划。

## 数据

话题：

- `/rrt_ompl/markers`：完整 MarkerArray，可靠、Transient Local。
- `/rrt_ompl/raw_path`：原始路径 DisplayTrajectory，仅供查看。
- `/rrt_ompl/final_path`：适配器处理后的 DisplayTrajectory。
- `/rrt_ompl/status`：带 run_id、计数和输出位置的采集状态。

每次运行保存到：

```text
/home/zhuxd/aubo_ws/rrt_results/ompl_same_plan/<run_id>/
```

其中保存节点、边、原始和处理后路径 CSV，以及规划请求、实际上下文请求、场景和结果的 CDR 消息。
CDR 使用本机 moveit_msgs 类型读取，可用于后续验证；不同消息版本之间不能假定二进制兼容。

## 基准实验的解释范围

- 当前仍采用原配置的 `range=0.0`（OMPL 自动设置）、`goal_bias=0.05`，不会固定或伪造随机树。
- 采集使用同一次规划的真实数据；不同次 Plan 的树可能不同。
- 此版本显示求解后的树快照，不声称包含真实的节点插入时间。被拒绝的样本不属于这棵树。
- 多次规划尝试、非基础 RRT、无法明确关联的多次内部求解，会跳过树采集并清理旧显示。
- 洋红路径在适配器链返回时采集；其后 pipeline 仍有自己的路径检查。应同时记录最终 action 返回状态。
- 目标容差、目标优化和起点修复可能使原始路径与处理后路径的端点略有差别，不能强求逐数相等。
- 关节状态到 TCP 的三维映射不唯一；树枝交叉不代表关节状态相同，也不代表机械臂发生碰撞。
- Gaussian 果树仍只是视觉模型，实体关节限位待确认；本任务不增加果树碰撞体或执行机械臂运动。
- 导出和显示的开销应单独记录，不混作 OMPL 内部求解时间。
- 当前采集链路用于逐次请求。CSV/CDR 以 run_id 目录严格归档，但 MarkerArray 和 DisplayTrajectory
  没有专用 run_id 字段，不应根据跨话题的到达顺序关联并发请求。
- 原始路径 CDR 没有时间参数化，时间值为零；它用于数据分析和绘图。

## 已完成的现场验收

运行环境为 Ubuntu 22.04、ROS 2 Humble、MoveIt 2.5.9、OMPL 1.7.0，使用现有模拟硬件。
新增包已编译安装，原 demo.launch.py、Python 包、Gaussian 参数均未修改。

- 原 RViz 两次点击 Plan 均成功。最新运行 `1793002042066458-456543-6`：10 个节点、9 条边、
  2 个原始路径点、91 个处理后轨迹点；`solve_calls=1`。
- 标准 MoveGroup plan-only 动作验证两次：导出的处理后路径与动作返回的关节顺序、位置、速度、
  加速度、时间逐项完全相同；原始路径逐边属于真实树的父子链。
- 最新运行的 10 个节点全部通过独立 FK 比对，坐标误差为 0；9 条树边的 1259 个插值状态
  通过当前 MoveIt 场景的有效性检查。此结果不代表已添加果树碰撞体。
- 在发布后新建订阅者，仍能收到完整树和路径；每个快照以 DELETEALL 清除上一棵树。
- `attempts=2` 和 `RRTConnectkConfigDefault` 均正常返回规划结果，同时跳过采集并清除旧树。

验收记录：`/home/zhuxd/aubo_ws/rrt_results/ompl_capture_verification/` 下的 `action_*.json`、
`saved_check_*.json`、`demo.log` 和 `completed.png`。
验证脚本 `verify_capture.py` 仅发出 plan_only 请求；`check_saved.py` 检查后加入的订阅者、FK 和树边。

## 恢复原配置

修改前备份位于：

```text
/home/zhuxd/aubo_ws/rrt_setup_backups/ompl_same_plan_20261025_231329/
```

恢复备份中的配置包 package.xml、config/ompl_planning.yaml 和 config/moveit.rviz 即可退出此采集入口。
该备份已放置 COLCON_IGNORE，不参与工作空间包扫描。

## 接口依据

- [MoveIt 2.5.9 原 OMPL PlannerManager](https://github.com/moveit/moveit2/blob/2.5.9/moveit_planners/ompl/ompl_interface/src/ompl_planner_manager.cpp)
- [OMPL 1.7.0 RRT 树导出](https://github.com/ompl/ompl/blob/1.7.0/src/ompl/geometric/planners/rrt/src/RRT.cpp#L213-L229)
- [MoveIt 适配器链](https://github.com/moveit/moveit2/blob/2.5.9/moveit_core/planning_request_adapter/src/planning_request_adapter.cpp)
