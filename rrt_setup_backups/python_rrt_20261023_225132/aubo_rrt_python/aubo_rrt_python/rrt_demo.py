"""通过 MoveIt 读取机械臂状态、检查关节配置并计算末端正运动学。

本文件负责 RRT 示例所需的 ROS/MoveIt 接口准备与查询，不包含 RRT
路径搜索本身。关节配置统一按 ``arm_joint_names`` 的顺序表示为 NumPy 数组。
"""

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from moveit_msgs.srv import GetPlanningScene, GetStateValidity, GetPositionFK
from moveit_msgs.msg import PlanningSceneComponents
from pathlib import Path
import xml.etree.ElementTree as ET
import numpy as np
from copy import deepcopy
from rcl_interfaces.srv import GetParameters
from rcl_interfaces.msg import ParameterType
from moveit_msgs.msg import MoveItErrorCodes

class RRTDemo(Node):
    """封装示例中使用的 MoveIt 服务客户端和机械臂状态数据。"""

    def __init__(self):
        """创建 ROS 节点，并准备规划场景、状态检查和正运动学客户端。"""
        super().__init__('aubo_rrt_python')
        self.get_logger().info('Python 节点启动成功')

        self.scene_client = self.create_client(
            GetPlanningScene, '/get_planning_scene')

        self.validity_client = self.create_client(
            GetStateValidity, '/check_state_validity')

        self.fk_client = self.create_client(
            GetPositionFK, '/compute_fk')

    def wait_for_moveit(self):
        """等待本示例依赖的 MoveIt 服务全部上线；有服务缺失时返回 False。"""
        services = [
            ('/get_planning_scene', self.scene_client),
            ('/check_state_validity', self.validity_client),
            ('/compute_fk', self.fk_client),
        ]

        for name, client in services:
            if not client.wait_for_service(timeout_sec=5.0):
                self.get_logger().error(f'未发现服务：{name}')
                return False

            self.get_logger().info(f'服务已就绪：{name}')

        return True


    def read_robot_state(self):
        """从规划场景读取当前机器人状态，保存为后续查询的基准状态。"""
        request = GetPlanningScene.Request()

        # 只请求机器人关节状态和已附着物体，避免获取不需要的场景数据。
        request.components.components = (
            PlanningSceneComponents.ROBOT_STATE
            | PlanningSceneComponents.ROBOT_STATE_ATTACHED_OBJECTS
        )

        # MoveIt 服务采用异步调用；spin_until_future_complete 等待响应。
        future = self.scene_client.call_async(request)
        rclpy.spin_until_future_complete(
            self, future, timeout_sec=5.0)

        if not future.done():
            future.cancel()
            self.get_logger().error('读取机器人状态超时')
            return False

        response = future.result()
        self.robot_state = response.scene.robot_state
        joints = self.robot_state.joint_state

        if not joints.name:
            self.get_logger().error('收到的关节状态为空')
            return False

        self.get_logger().info(
            f'收到 {len(joints.name)} 个关节的状态')

        for name, position in zip(joints.name, joints.position):
            self.get_logger().info(f'{name}: {position:.6f}')

        return True

    def load_named_states(self):
        """从 SRDF 读取 home 和 pose1，并按机械臂关节顺序整理成数组。"""
        self.arm_joint_names = [
            'shoulder_joint',
            'upperArm_joint',
            'foreArm_joint',
            'wrist1_joint',
            'wrist2_joint',
            'wrist3_joint',
        ]

        srdf_path = (
            Path.home() / 'aubo_ws' / 'src'
            / 'aubo_i5_scissors_moveit_config' / 'config'
            / 'aubo_i5_scissors_robot.srdf'
        )

        # SRDF 中 group_state 按关节名称描述；下面转换成算法使用的固定顺序。
        root = ET.parse(srdf_path).getroot()
        states = {}

        for state in root.findall('group_state'):
            if state.get('group') != 'aubo_arm':
                continue

            by_name = {}
            for joint in state.findall('joint'):
                name = joint.get('name')
                by_name[name] = float(joint.get('value'))

            values = [by_name[name] for name in self.arm_joint_names]
            states[state.get('name')] = np.array(values, dtype=float)

        self.q_start = states['home']
        self.q_goal = states['pose1']

        self.get_logger().info(f'起点 home: {self.q_start.tolist()}')
        self.get_logger().info(f'目标 pose1: {self.q_goal.tolist()}')

    def robot_state_from_q(self, q):
        """将关节数组 q 写入基准状态副本，保留机械臂之外的状态信息。"""
        # 每次都从读取到的基准状态复制，避免不同查询之间互相污染。
        state = deepcopy(self.robot_state)

        indices = {
            name: i
            for i, name in enumerate(state.joint_state.name)
        }

        for name, value in zip(self.arm_joint_names, q, strict=True):
            index = indices[name]
            state.joint_state.position[index] = float(value)

        state.is_diff = False
        return state

    def is_state_valid(self, q):
        """请求 MoveIt 检查关节配置 q 是否满足碰撞等状态有效性约束。"""
        request = GetStateValidity.Request()
        request.group_name = 'aubo_arm'
        request.robot_state = self.robot_state_from_q(q)

        # 检查结果由 MoveIt 根据当前规划场景计算，而不是仅检查关节限位。
        future = self.validity_client.call_async(request)
        rclpy.spin_until_future_complete(
            self, future, timeout_sec=5.0)

        if not future.done():
            future.cancel()
            raise RuntimeError('MoveIt 状态检查服务响应超时')

        response = future.result()
        return response.valid

    def load_joint_limits(self):
        """读取 URDF 关节限位，并优先采用 MoveIt 配置中的规划限位覆盖值。"""
        client = self.create_client(
            GetParameters, '/move_group/get_parameters')

        if not client.wait_for_service(timeout_sec=5.0):
            raise RuntimeError('MoveIt 参数服务未就绪')

        request = GetParameters.Request()
        request.names = ['robot_description']

        for name in self.arm_joint_names:
            prefix = f'robot_description_planning.joint_limits.{name}.'
            request.names.extend([
                prefix + 'min_position',
                prefix + 'max_position',
            ])

        future = client.call_async(request)
        rclpy.spin_until_future_complete(
            self, future, timeout_sec=5.0)

        if not future.done():
            future.cancel()
            raise RuntimeError('读取关节限位超时')

        values = dict(zip(
            request.names, future.result().values, strict=True))
        self.destroy_client(client)

        description = values['robot_description']
        if description.type != ParameterType.PARAMETER_STRING:
            raise RuntimeError('未读取到 robot_description')

        root = ET.fromstring(description.string_value)
        joints = {
            joint.get('name'): joint
            for joint in root.findall('joint')
        }

        lower = []
        upper = []

        # URDF 提供基础边界；MoveIt 的 min/max_position 若已配置，则覆盖对应边界。
        for name in self.arm_joint_names:
            joint = joints[name]
            limit = joint.find('limit')

            # 当前六个关节均为有界旋转关节。
            bounds = [
                float(limit.get('lower')),
                float(limit.get('upper')),
            ]

            prefix = f'robot_description_planning.joint_limits.{name}.'
            for i, key in enumerate(['min_position', 'max_position']):
                value = values[prefix + key]

                if value.type == ParameterType.PARAMETER_DOUBLE:
                    bounds[i] = value.double_value
                elif value.type != ParameterType.PARAMETER_NOT_SET:
                    raise RuntimeError(f'{name} 的 {key} 类型不正确')

            if not np.all(np.isfinite(bounds)) or bounds[0] >= bounds[1]:
                raise RuntimeError(f'{name} 的上下限无效：{bounds}')

            lower.append(bounds[0])
            upper.append(bounds[1])

            self.get_logger().info(
                f'{name} 范围: [{bounds[0]:.6f}, {bounds[1]:.6f}] rad')

        self.q_lower = np.array(lower, dtype=float)
        self.q_upper = np.array(upper, dtype=float)

    def in_joint_bounds(self, q):
        """检查 q 的维度、数值有效性以及每个关节是否落在限位范围内。"""
        q = np.asarray(q, dtype=float)

        if q.shape != self.q_lower.shape:
            return False

        return bool(
            np.all(np.isfinite(q))
            and np.all(q >= self.q_lower)
            and np.all(q <= self.q_upper)
        )

    def compute_fk(self, q):
        """计算 q 对应的剪刀末端在 world 坐标系中的位置，返回米制 xyz。"""
        # 指定计算哪个末端，以及结果使用哪个坐标系。
        request = GetPositionFK.Request()
        request.header.frame_id = 'world'
        request.fk_link_names = ['scissor_tcp']

        # 修改机器人状态副本中的六个机械臂关节角。
        request.robot_state = self.robot_state_from_q(q)

        # 请求 MoveIt 计算正运动学。
        future = self.fk_client.call_async(request)
        rclpy.spin_until_future_complete(
            self, future, timeout_sec=5.0)

        if not future.done():
            future.cancel()
            raise RuntimeError('正运动学计算超时')

        response = future.result()

        if response.error_code.val != MoveItErrorCodes.SUCCESS:
            raise RuntimeError(
                f'正运动学计算失败，错误码：{response.error_code.val}')

        if (
            response.fk_link_names != ['scissor_tcp']
            or len(response.pose_stamped) != 1
        ):
            raise RuntimeError('返回的末端位姿不符合请求')

        pose = response.pose_stamped[0]

        if pose.header.frame_id != 'world':
            raise RuntimeError(
                f'返回坐标系不符合请求：{pose.header.frame_id}')

        # FK 返回位置和姿态，这里先提取位置，单位为米。
        position = pose.pose.position
        xyz = np.array(
            [position.x, position.y, position.z], dtype=float)

        if not np.all(np.isfinite(xyz)):
            raise RuntimeError('正运动学返回了无效坐标')

        return xyz

def main(args=None):
    """初始化 ROS、按顺序执行 MoveIt 查询，并在退出时释放节点资源。"""
    rclpy.init(args=args)
    node = RRTDemo()

    try:
        # 先确认服务可用并读取基准状态，之后再进行命名状态查询。
        if node.wait_for_moveit() and node.read_robot_state():
            node.load_named_states()

            # 对起点和目标分别检查碰撞有效性，并求出末端空间位置。
            start_valid = node.is_state_valid(node.q_start)
            goal_valid = node.is_state_valid(node.q_goal)

            node.get_logger().info(
                f'起点 home 的 MoveIt 状态检查：{start_valid}')
            node.get_logger().info(
                f'目标 pose1 的 MoveIt 状态检查：{goal_valid}')

            node.p_start = node.compute_fk(node.q_start)
            node.p_goal = node.compute_fk(node.q_goal)

            node.get_logger().info(
                f'home 剪刀末端（world，米）：'
                f'{np.round(node.p_start, 6).tolist()}')

            node.get_logger().info(
                f'pose1 剪刀末端（world，米）：'
                f'{np.round(node.p_goal, 6).tolist()}')
                
            node.publish_endpoints()
            rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()