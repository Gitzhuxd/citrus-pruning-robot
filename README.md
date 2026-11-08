# 柑橘摘心机器人：建模、运动规划与 RRT 可视化

基于 **ROS 2 Humble、MoveIt 2 和 AUBO i5** 的柑橘摘心机器人研究项目，围绕机器人整机建模、末端剪切姿态、避障运动规划及规划过程可视化开展开发与实验。

<!-- 配图位置：将截图放入仓库 docs/images/ 目录，再取消下方对应图片的注释。 -->

> **项目配图预留区**：建议首先放置一张 RViz 整机截图，包含履带底盘、机械臂、转接板、电动剪刀和 Gemini 435Le 相机。

<!-- ![机器人整机模型](docs/images/robot-overview.png) -->

| 建议截图 | 建议文件名 | 截图内容 |
| --- | --- | --- |
| 整机模型 | `robot-overview.png` | RViz 中显示完整机器人，尽量使用清晰的斜侧视角 |
| 末端结构 | `end-effector.png` | 放大展示转接板、剪刀及相机安装关系 |
| 运动规划 | `motion-planning.png` | 展示目标姿态、障碍物及规划轨迹 |
| RRT 可视化 | `rrt-visualization.png` | 展示规划树、最终路径和 RViz 面板；功能验证后补充 |

## 目录

- [项目背景](#项目背景)
- [系统组成](#系统组成)
- [开发环境](#开发环境)
- [功能包说明](#功能包说明)
- [整机装配与坐标关系](#整机装配与坐标关系)
- [下载与编译](#下载与编译)
- [模型与规划启动](#模型与规划启动)
- [RRT 算法与可视化](#rrt-算法与可视化)
- [实验记录](#实验记录)
- [后续工作](#后续工作)
- [第三方依赖与许可](#第三方依赖与许可)

## 项目背景

本项目面向柑橘新梢摘心作业。作业空间包含枝条、叶片等障碍物，需要在满足剪切要求的前提下，使机械臂携带电动剪刀到达目标位置，并完成接近、剪切和撤离动作。

研究重点包括：

- 建立履带平台、AUBO i5、转接板、剪刀和深度相机的统一机器人模型。
- 根据剪切点位置、枝条方向和剪刀几何关系构造末端目标姿态。
- 利用 MoveIt 2 与 OMPL 进行机械臂运动规划和碰撞检查。
- 开发 RRT 算法及可视化工具，辅助观察采样、树扩展和路径生成过程。
- 为后续候选剪切姿态选择、规划策略对比和实机验证建立实验基础。

当前开发以仿真和规划验证为主；真实机械臂、相机数据及剪刀控制的联调结果按实际完成情况补充。

## 系统组成

| 组成部分 | 配置或用途 |
| --- | --- |
| 机械臂 | AUBO i5，六自由度机械臂 |
| 移动平台 | 履带底盘，作为机械臂安装平台 |
| 转接板 | 连接机械臂末端与作业工具 |
| 末端执行器 | 电动剪刀，用于新梢剪切 |
| 深度相机 | Orbbec Gemini 435Le，用于后续图像、深度与点云接入 |
| 规划框架 | MoveIt 2 与 OMPL |
| 可视化工具 | RViz2、RRT 可视化节点与面板插件 |

**相机变更说明：** 早期版本使用 Intel RealSense D435i，当前模型更新为 Gemini 435Le。历史 RealSense 相关源码或配置可能仍然保留；存在相关目录不代表当前启动文件会启用旧相机。

## 开发环境

| 项目 | 开发环境 |
| --- | --- |
| 操作系统 | Ubuntu 22.04 |
| ROS | ROS 2 Humble |
| 运动规划 | MoveIt 2、OMPL |
| 可视化 | RViz2 |
| 开发语言 | Python、C++ |
| 机器人描述 | URDF、Xacro、SRDF |
| 工作空间 | `~/aubo_ws` |
| 构建工具 | colcon |

本文启动示例面向模型显示与规划验证。Gazebo 和实机运行所需的启动参数、控制器及依赖应按对应功能另行配置。

## 功能包说明

以下列出项目自定义功能包；第三方驱动目录不在此表中逐一展开。

| 路径 | 职责 |
| --- | --- |
| `src/aubo_i5_scissors_description/` | 机器人整机模型、Xacro 装配、网格资源及模型显示启动文件 |
| `src/aubo_i5_scissors_moveit_config/` | MoveIt 配置、SRDF、规划器配置及规划启动文件 |
| `src/aubo_rrt_interfaces/` | RRT 相关 ROS 消息、服务和动作接口 |
| `src/aubo_rrt_python/` | Python RRT 算法实现与 ROS 节点 |
| `src/aubo_rrt_visualizer/` | C++ RRT 可视化 |
| `src/aubo_rrt_panel/` | RViz 面板插件 |
| `src/aubo_ompl_capture/` | 面向真实 OMPL RRT 规划树的捕获功能 |

各包的具体可执行程序、话题、服务和参数，以包内源码与启动文件为准。尚未验证的功能不作为已完成能力或实验结论。

## 整机装配与坐标关系

整机装配入口：

```text
src/aubo_i5_scissors_description/urdf/robot_core.xacro
```

整机由履带平台承载 AUBO i5，机械臂末端连接转接板，剪刀和相机分别安装在转接板上。

| 父部件或参考坐标系 | 子部件或连接坐标系 | 说明 |
| --- | --- | --- |
| 履带平台 | AUBO i5 `base_link` | 机械臂固定在底盘安装位置；中间安装坐标系以 Xacro 为准 |
| AUBO i5 `base_link` | AUBO `ee_link` | 经机械臂各关节及连杆连接，并非直接固定连接 |
| `ee_link` | 转接板 `zhuanjie_link` | 末端转接板固定连接 |
| `zhuanjie_link` | 剪刀 `scissor_base_link` | 剪刀安装连接 |
| `zhuanjie_link` | Gemini 435Le `camera_screw_frame` | 相机安装参考连接，内部坐标系由相机描述文件定义 |

上述表格概括装配关系，不代替完整 TF 树。履带平台可能使用 `car_` 前缀，底盘根坐标系、机械臂安装坐标系及相机内部坐标系应以展开后的 URDF 为准。

修改相机、转接板或剪刀后，需要检查安装位姿、碰撞几何、SRDF 中的碰撞排除关系和规划起始状态。相机外观模型替换与真实相机驱动启动是两项独立配置。

<!-- ![末端结构与相机安装](docs/images/end-effector.png) -->

## 下载与编译

### 1. 获取源码

在主目录下执行以下命令；目标 `~/aubo_ws` 应不存在或为空：

```bash
cd ~
git clone https://github.com/Gitzhuxd/citrus-pruning-robot.git aubo_ws
```

如果下载的版本仍使用 Git 子模块，需要在仓库根目录补充执行：

```bash
cd ~/aubo_ws
git submodule update --init --recursive
```

若第三方驱动已经转换为普通源码目录，则无需初始化子模块。转换状态以实际提交的仓库内容为准。

### 2. 加载 ROS 环境并安装依赖

在已经安装 ROS 2 Humble 和初始化 rosdep 的环境中执行：

```bash
source /opt/ros/humble/setup.bash
cd ~/aubo_ws
rosdep install --from-paths src --ignore-src --rosdistro humble -r -y
```

如遇到无法解析的 rosdep 键或第三方 SDK 依赖，应根据错误和对应驱动文档补齐后再编译。

### 3. 编译并加载工作空间

```bash
cd ~/aubo_ws
colcon build --symlink-install
source ~/aubo_ws/install/setup.bash
```

每个新终端运行项目之前，都需要先加载 ROS 环境和工作空间环境。

## 模型与规划启动

### 显示整机模型

```bash
source /opt/ros/humble/setup.bash
source ~/aubo_ws/install/setup.bash
ros2 launch aubo_i5_scissors_description display_robot_core.launch.py
```

检查底盘、机械臂和末端部件是否完整加载，网格资源路径是否正确，坐标关系是否符合实际装配。

### 启动 MoveIt 规划演示

```bash
source /opt/ros/humble/setup.bash
source ~/aubo_ws/install/setup.bash
ros2 launch aubo_i5_scissors_moveit_config demo.launch.py
```

在 RViz 中检查规划组、起始状态和目标状态，再进行规划。该命令用于规划演示，不代表已接通真实机械臂控制。

### 单独检查 Xacro 展开

```bash
ros2 run xacro xacro \
  ~/aubo_ws/src/aubo_i5_scissors_description/urdf/robot_core.xacro \
  -o /tmp/robot_core_test.urdf
```

Xacro 展开成功说明描述文件可被处理，仍需进一步验证网格加载、TF 和碰撞模型。

<!-- ![MoveIt 运动规划](docs/images/motion-planning.png) -->

## RRT 算法与可视化

项目包含两类相关工具：

| 路线 | 涉及功能包 | 用途 |
| --- | --- | --- |
| 自定义 RRT 实现与展示 | `aubo_rrt_python`、`aubo_rrt_interfaces`、`aubo_rrt_visualizer`、`aubo_rrt_panel` | 算法开发、消息交互和规划过程展示 |
| OMPL 规划树捕获 | `aubo_ompl_capture` | 捕获底层实际规划过程中的树结构，辅助规划分析 |

自定义 RRT 的演示树和 MoveIt/OMPL 实际规划树应分别记录来源，避免在实验分析中混用。

> 待补充：各节点的启动命令、RViz 面板加载方法、话题名称、消息类型及一次完整实验示例。

<!-- ![RRT 规划树及控制面板](docs/images/rrt-visualization.png) -->

## 实验记录

每次实验建议记录 Git 提交编号、机器人模型版本、场景、起始状态、目标约束、规划器及时间预算。

| 指标 | 记录内容 |
| --- | --- |
| 规划成功率 | 成功任务数 / 总任务数，并记录失败判定标准 |
| 规划耗时 | 明确计时是否包含 IK、碰撞检查、路径简化和轨迹时间参数化 |
| 路径长度 | 明确关节空间或笛卡尔空间的计算方法与单位 |
| 路径平滑性 | 使用明确、可重复计算的指标 |
| 规划树规模 | 明确节点数、边数和统计阶段 |
| 随机性 | 记录重复次数；可控时记录随机种子 |

> 待补充：测试场景截图、实验参数、重复实验结果和对照方法。本文不预填未经验证的数据。
><img width="2558" height="1351" alt="d98a40c7e51c91767f693e86f9daaa04" src="https://github.com/user-attachments/assets/b14f3746-0a0f-4186-848c-0f86c3585485" />

> 

## 后续工作

- 验证 Gemini 435Le 与转接板更新后的整机模型及自碰撞关系。
- 完善“预备点 → 剪切点 → 撤离点”的连续作业流程。
- 接入相机图像、深度和点云，建立环境碰撞表示。
- 完善候选剪切姿态生成与姿态—路径联合决策实验。
- 整理 RRT 可视化和 OMPL 规划树捕获工具的运行文档。
- 在仿真验证后开展机械臂与电动剪刀实机联调。

## 第三方依赖与许可

项目涉及 AUBO、Orbbec、RealSense、ROS 2、MoveIt 2 和 OMPL 等第三方软件。第三方源码、模型及资源按各自的许可证使用，保留对应的版权声明和许可文件。

- [Orbbec ROS 2 驱动](https://github.com/orbbec/OrbbecSDK_ROS2)
- [项目仓库](https://github.com/Gitzhuxd/citrus-pruning-robot)

项目自研代码的许可证尚待仓库维护者明确；引用第三方代码的许可证不等于已为整个项目指定同一许可证。
