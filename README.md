# 柑橘摘心机器人：建模、运动规划与 RRT 可视化

基于 **ROS 2 Humble、MoveIt 2 和 AUBO i5** 的柑橘摘心机器人研究项目，围绕机器人整机建模、末端剪切姿态、避障运动规划及规划过程可视化开展开发与实验。

<!-- 配图位置：将截图放入仓库 docs/images/ 目录，再取消下方对应图片的注释。 -->

> **项目图**：
<img width="2558" height="1131" alt="6a5e681056310d6b8db7084bba53869c" src="https://github.com/user-attachments/assets/f1d64713-4e3b-4f04-9ce5-43622d9527f7" />
<img width="2327" height="1261" alt="8546dac4-9449-4b9a-979e-802a15b0b3c3" src="https://github.com/user-attachments/assets/e5219144-af17-4de9-9c53-c90ff957bb43" />


<!-- ![机器人整机模型](docs/images/robot-overview.png) -->

## 项目功能

- **柑橘树场景**。参考三维高斯重建结果建立简化树模型，标注 `S01` 到 `S08` 共 8 个剪切点。111 段枝干用圆柱表示碰撞几何，376 个叶片实例用于外观显示。树的位置与朝向可以通过 launch 参数设置。
- **S01 剪切仿真**。从 `home` 出发，使用 OMPL 基础 RRT 到达预剪切位姿，随后依次验证进刀、闭刀、剪后场景更新和撤离。默认保留 6 mm 短桩，需要时先沿枝条轴向脱离，再闭刀撤离。
- **OMPL 规划过程记录**。在原 MoveIt 演示中，对单次基础 RRT 规划获取探索树、原始路径和经 MoveIt 处理的路径。RViz 使用剪刀 TCP 的正运动学结果，将关节空间中的节点投影到三维场景。

当前已在 Ubuntu 22.04 上验证 S01 的重新规划、仿真回放和场景复位。剪切用树模型和 MoveIt 碰撞体的变化表示，当前验证范围为仿真。

## 工作区结构

| 路径 | 职责 |
| --- | --- |
| [`src/citrus_pruning_sim`](src/citrus_pruning_sim/) | 果树几何、静态 URDF、剪切点、剪切和复位服务，以及 MoveIt 场景同步 |
| [`src/citrus_pruning_task`](src/citrus_pruning_task/) | S01 任务节点、端到端仿真启动文件和运行说明 |
| [`src/aubo_i5_scissors_description`](src/aubo_i5_scissors_description/) | 履带底盘、机械臂、剪刀和相机的 URDF/Xacro 装配与网格资源 |
| [`src/aubo_i5_scissors_moveit_config`](src/aubo_i5_scissors_moveit_config/) | SRDF、运动学、关节约束、规划器及 MoveIt 启动配置 |
| [`src/aubo_ompl_capture`](src/aubo_ompl_capture/) | 采集同一次 OMPL RRT 规划的探索树和路径 |
| `src/aubo_rrt_*` | 自编 RRT、演示节点、ROS 接口和 RViz 面板 |
| [`experiments`](experiments/README.md) | 历史实验索引和各轮复现所需的 ROS 环境 |
| `results/` | 本地运行生成的 JSON、轨迹和日志，由 Git 忽略 |

整机装配入口是 `robot_core.xacro`。机械臂规划组为 `aubo_arm`，剪刀工具坐标系为 `scissor_tcp`。仿真用 `world` 作为固定坐标系，果树几何以 `tree_base` 为参考。 [整机装配源码](src/aubo_i5_scissors_description/urdf/robot_core.xacro)

## 快速开始

### 构建与加载

使用 Ubuntu 22.04、ROS 2 Humble、MoveIt 2 和 colcon。已有 AUBO 工作区时，可用其已安装的机器人模型与规划配置，只构建两个柑橘功能包。在本仓库根目录执行以下命令。

```bash
source /opt/ros/humble/setup.bash
source ~/aubo_ws/install/local_setup.bash
colcon build --base-paths src --symlink-install \
  --packages-select citrus_pruning_sim citrus_pruning_task
source install/local_setup.bash
```

如果从源码搭建新环境，先准备 ROS 2 Humble 和 rosdep，再从仓库根目录安装依赖并构建。相机或驱动依赖按对应 SDK 说明安装。

```bash
source /opt/ros/humble/setup.bash
rosdep install --from-paths src --ignore-src --rosdistro humble -r -y
colcon build --base-paths src --symlink-install --packages-up-to citrus_pruning_task
source install/setup.bash
```

此前的运行验收使用了已有 AUBO 工作区作为依赖。两个入口的详细操作和启动问题处理见包内说明。 [S01 仿真使用说明](src/citrus_pruning_task/README.md)

### 启动 S01 仿真

打开两个终端，进入本仓库根目录，并按所用的构建方式加载 ROS 和工作区。两个终端使用同一个本机仿真域。

```bash
export ROS_DOMAIN_ID=99 ROS_LOCALHOST_ONLY=1
```

**终端一**在 Ubuntu 图形桌面启动仿真。通过 SSH 无窗口运行时，改用 `rviz:=false`。

```bash
ros2 launch citrus_pruning_task simulation.launch.py rviz:=true
```

**终端二**等到 MoveIt 输出 `You can start planning now!` 且树场景就绪后，运行规划与回放。无窗口检查规划结果时，可省略 `--play`。

```bash
ros2 run citrus_pruning_task cut_s01 --play \
  --output "$PWD/results/s01_$(date +%Y%m%d_%H%M%S_%N)"
```

`result.json` 记录任务是否成功、各阶段的校验和剪后碰撞场景。`stages.transit.reused` 为 `false` 时，转移路径来自本次规划。`display_trajectory.cdr` 保存可回放的轨迹。带 `--play` 的运行结束后，在开启下一轮前恢复树场景。

```bash
ros2 service call /citrus/reset std_srvs/srv/Trigger '{}'
```

## 在 RViz 查看 OMPL RRT 探索树

采集使用原 AUBO MoveIt 演示入口。在加载 AUBO 工作区的图形终端中运行以下命令。如果 RViz 配置启用了 `CitrusGaussian`，请加载对应的 RVizSplat 插件并按本机路径选择 PLY 文件。

```bash
ros2 launch aubo_i5_scissors_moveit_config demo.launch.py
```

在 **MotionPlanning** 面板选 `aubo_arm`、`RRTkConfigDefault`，将 **Planning Attempts** 设为 `1`，点击 **Plan**。在 **OMPL RRT Same Plan** 显示项中，蓝点和灰边为探索树，黄色为原始路径，洋红为 MoveIt 处理后的路径。

| 话题 | 内容 |
| --- | --- |
| `/rrt_ompl/markers` | 树节点、树边和路径的 RViz 标记 |
| `/rrt_ompl/raw_path` | 同次规划的原始轨迹 |
| `/rrt_ompl/final_path` | MoveIt 处理后的轨迹 |
| `/rrt_ompl/status` | 采集状态和运行编号 |

采集程序按运行编号保存记录到 `~/aubo_ws/rrt_results/ompl_same_plan/`。探索树是一次规划结束后的快照。S01 仿真入口沿用基础 RRT，并把任务输出独立写入 `results/`。 [采集插件源码](src/aubo_ompl_capture/)

![RViz 规划与可视化记录](https://github.com/user-attachments/assets/b14f3746-0a0f-4186-848c-0f86c3585485)

## 实验与后续工作

历史实验涵盖 S01 进刀方向、闭刀碰撞和短桩撤离，以及 S07 的等价关节角目标对照。复现时核对场景版本、起点、候选目标、规划预算和随机种子，并保留各阶段的失败原因。 [实验目录与复现索引](experiments/README.md)

后续将把同一套场景扩展到多个剪切点，比较候选姿态的排序、筛选和规划预算分配。实机阶段将验证相机与剪刀的安装标定、剪刀关节行程及作业中的碰撞模型。

## 第三方依赖与许可

AUBO、Orbbec、RealSense、ROS 2、MoveIt 2 和 OMPL 的源码与资源遵循各自的许可及版权声明。子包声明见各自的 `package.xml`。 [Orbbec ROS 2 驱动](https://github.com/orbbec/OrbbecSDK_ROS2)
