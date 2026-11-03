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
from moveit_msgs.msg import DisplayTrajectory, RobotTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from aubo_rrt_python.rrt_core import RRTPlanner, interpolate_edge
from aubo_rrt_python.rrt_markers import RRTMarkers
from datetime import datetime
import csv
import json
import time

class RRTDemo(Node):
    def __init__(self, node_name='aubo_rrt_python', client_group=None):
        super().__init__(node_name)
        self.get_logger().info('Python 节点启动成功')

        self.scene_client = self.create_client(
            GetPlanningScene, '/get_planning_scene', callback_group=client_group)

        self.validity_client = self.create_client(
            GetStateValidity, '/check_state_validity', callback_group=client_group)

        self.fk_client = self.create_client(
            GetPositionFK, '/compute_fk', callback_group=client_group)

        self.parameter_client = self.create_client(
            GetParameters, '/move_group/get_parameters', callback_group=client_group)
        defaults = {
            'start_state': 'home', 'goal_state': 'pose1',
            'seed': 42, 'step_size': 0.3, 'goal_bias': 0.1,
            'collision_step': 0.04, 'max_iterations': 2500,
            'planning_time': 60.0, 'keep_alive': True,
            'replay_step': 0.08,
            'output_directory': str(Path.home() / 'aubo_ws/rrt_results/python'),
        }
        self.settings = {
            name: self.declare_parameter(name, default).value
            for name, default in defaults.items()
        }
        self.markers = RRTMarkers(self)
        qos = QoSProfile(
            depth=1, reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.trajectory_pub = self.create_publisher(
            DisplayTrajectory, '/display_planned_path', qos)
        self.display_trajectory = None
        self.previous_subscribers = 0
        self.fk_cache = {}
        self.last_marker_time = 0.0
        self.status_text = 'Python RRT: preparing'
        self.tree_frames = []
        self.replay_active = False

    def wait_for_future(self, future, timeout_sec=5.0):
        """CLI自行spin；常驻后台覆盖此方法，交给已有执行器处理响应。"""
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout_sec)

    def wait_for_moveit(self):
        services = [
            ('/get_planning_scene', self.scene_client),
            ('/check_state_validity', self.validity_client),
            ('/compute_fk', self.fk_client),
            ('/move_group/get_parameters', self.parameter_client),
        ]

        for name, client in services:
            if not client.wait_for_service(timeout_sec=5.0):
                self.get_logger().error(f'未发现服务：{name}')
                return False

            self.get_logger().info(f'服务已就绪：{name}')

        return True


    def read_robot_state(self):
        request = GetPlanningScene.Request()

        request.components.components = (
            PlanningSceneComponents.ROBOT_STATE
            | PlanningSceneComponents.ROBOT_STATE_ATTACHED_OBJECTS
            | PlanningSceneComponents.WORLD_OBJECT_GEOMETRY
            | PlanningSceneComponents.OCTOMAP
        )

        future = self.scene_client.call_async(request)
        self.wait_for_future(future, timeout_sec=5.0)

        if not future.done():
            future.cancel()
            self.get_logger().error('读取机器人状态超时')
            return False

        response = future.result()
        self.scene = response.scene
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
        self.arm_joint_names = [
            'shoulder_joint',
            'upperArm_joint',
            'foreArm_joint',
            'wrist1_joint',
            'wrist2_joint',
            'wrist3_joint',
        ]

        parameter = self.read_parameters(['robot_description_semantic'])[0]
        if parameter.type != ParameterType.PARAMETER_STRING:
            raise RuntimeError('MoveIt 未提供 robot_description_semantic')
        root = ET.fromstring(parameter.string_value)
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

        self.named_states = states
        start_name = self.settings['start_state']
        goal_name = self.settings['goal_state']
        if start_name not in states or goal_name not in states:
            raise RuntimeError(f'未找到命名状态，可选项：{list(states)}')
        self.q_start = states[start_name]
        self.q_goal = states[goal_name]

        self.get_logger().info(f'起点 {start_name}: {self.q_start.tolist()}')
        self.get_logger().info(f'目标 {goal_name}: {self.q_goal.tolist()}')

    def robot_state_from_q(self, q):
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
        # MoveIt 的状态服务不代替显式关节限位检查。
        if not self.in_joint_bounds(q):
            return False
        request = GetStateValidity.Request()
        request.group_name = 'aubo_arm'
        request.robot_state = self.robot_state_from_q(q)

        future = self.validity_client.call_async(request)
        self.wait_for_future(future, timeout_sec=5.0)

        if not future.done():
            future.cancel()
            raise RuntimeError('MoveIt 状态检查服务响应超时')

        response = future.result()
        return response.valid

    def read_parameters(self, names):
        request = GetParameters.Request()
        request.names = names
        future = self.parameter_client.call_async(request)
        self.wait_for_future(future, timeout_sec=5.0)
        if not future.done():
            future.cancel()
            raise RuntimeError('读取 MoveIt 参数超时')
        response = future.result()
        if response is None or len(response.values) != len(names):
            raise RuntimeError('MoveIt 参数响应不完整')
        return response.values

    def load_joint_limits(self):
        names = ['robot_description']

        for name in self.arm_joint_names:
            prefix = f'robot_description_planning.joint_limits.{name}.'
            names.extend([
                prefix + 'min_position',
                prefix + 'max_position',
            ])

        values = dict(zip(names, self.read_parameters(names), strict=True))

        description = values['robot_description']
        if description.type != ParameterType.PARAMETER_STRING:
            raise RuntimeError('未读取到 robot_description')

        root = ET.fromstring(description.string_value)
        self.model_name = root.get('name')
        joints = {
            joint.get('name'): joint
            for joint in root.findall('joint')
        }

        lower = []
        upper = []

        for name in self.arm_joint_names:
            joint = joints[name]
            if joint.get('type') != 'revolute':
                raise RuntimeError(f'{name} 不是本示例支持的有界旋转关节')
            limit = joint.find('limit')

            # 当前六个关节均为有界旋转关节。
            bounds = [
                float(limit.get('lower')),
                float(limit.get('upper')),
            ]

            safety = joint.find('safety_controller')
            if safety is not None:
                bounds[0] = max(bounds[0], float(safety.get('soft_lower_limit', bounds[0])))
                bounds[1] = min(bounds[1], float(safety.get('soft_upper_limit', bounds[1])))

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
        self.get_logger().info('使用当前仿真模型限位；实体机械臂规格尚未确认')

    def in_joint_bounds(self, q):
        q = np.asarray(q, dtype=float)

        if q.shape != self.q_lower.shape:
            return False

        return bool(
            np.all(np.isfinite(q))
            and np.all(q >= self.q_lower)
            and np.all(q <= self.q_upper)
        )

    def compute_fk(self, q):
        key = tuple(float(value) for value in q)
        if key in self.fk_cache:
            return self.fk_cache[key].copy()
        # 指定计算哪个末端，以及结果使用哪个坐标系。
        request = GetPositionFK.Request()
        request.header.frame_id = 'world'
        request.fk_link_names = ['scissor_tcp']

        # 修改机器人状态副本中的六个机械臂关节角。
        request.robot_state = self.robot_state_from_q(q)

        # 请求 MoveIt 计算正运动学。
        future = self.fk_client.call_async(request)
        self.wait_for_future(future, timeout_sec=5.0)

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

        self.fk_cache[key] = xyz.copy()
        return xyz

    def publish_endpoints(self):
        self.markers.set_endpoints(
            self.p_start, self.p_goal,
            self.settings['start_state'], self.settings['goal_state'])
        self.markers.publish(self.status_text)
        self.get_logger().info('已发布起点和目标点标记：/rrt_python/markers')

    def on_tree_node(self, index, q, parent):
        # 树仍然保存六维关节状态；RViz 显示的是 scissor_tcp 的 FK 投影。
        curve = None
        if parent >= 0:
            states = interpolate_edge(self.planner.nodes[parent], q, 0.08)
            curve = [self.compute_fk(state) for state in states]
        self.markers.add_node(index, self.compute_fk(q), parent, curve)
        self.tree_frames.append((index, self.compute_fk(q), parent, curve))
        self.status_text = (
            f'Python RRT | iteration {self.planner.iterations} | nodes {index + 1}')
        now = time.monotonic()
        if now - self.last_marker_time >= 0.1:
            self.markers.publish(self.status_text)
            self.last_marker_time = now
        if index and index % 50 == 0:
            self.get_logger().info(self.status_text)

    def run_rrt(self):
        self.planner = RRTPlanner(
            self.q_lower, self.q_upper, self.is_state_valid,
            step_size=self.settings['step_size'],
            goal_bias=self.settings['goal_bias'],
            collision_step=self.settings['collision_step'],
            max_iterations=self.settings['max_iterations'],
            max_seconds=self.settings['planning_time'],
            seed=self.settings['seed'], on_node=self.on_tree_node)
        self.get_logger().info('开始基础 RRT 搜索：随机采样 → 最近节点 → 扩展 → 检查整条边')
        path_indices = self.planner.plan(self.q_start, self.q_goal)
        dense_path = []
        path_xyz = []
        validation_checks = 0
        postprocess_start = time.monotonic()

        if path_indices is not None:
            path = [self.planner.nodes[i] for i in path_indices]
            dense_path = [path[0]]
            # 用搜索时一半的间隔复验最终路径，仍是离散检查。
            resolution = self.settings['collision_step'] / 2.0
            for a, b in zip(path[:-1], path[1:]):
                dense_path.extend(interpolate_edge(a, b, resolution)[1:])
            for q in dense_path:
                validation_checks += 1
                if not self.is_state_valid(q):
                    raise RuntimeError('最终路径细化复验失败；未发布轨迹，请检查场景是否变化')
                path_xyz.append(self.compute_fk(q))
            self.display_trajectory = self.make_display_trajectory(dense_path)
            self.status_text = (
                f'RRT solved | {len(self.planner.nodes)} nodes | '
                f'{len(path_indices)} path nodes | {self.planner.elapsed_seconds:.2f} s')
            self.get_logger().info(
                f'RRT 规划成功：迭代 {self.planner.iterations}，'
                f'树节点 {len(self.planner.nodes)}，路径节点 {len(path_indices)}，'
                f'复验状态 {validation_checks}')
        else:
            self.status_text = f'RRT: {self.planner.outcome} | no path found'
            self.get_logger().warning('本次预算内未找到路径；保留已探索的树')

        self.save_result(
            path_indices, dense_path, path_xyz, validation_checks,
            time.monotonic() - postprocess_start)
        replay_step = self.settings['replay_step']
        if not np.isfinite(replay_step) or replay_step < 0:
            raise ValueError('replay_step 必须是有限非负数')
        self.final_status = self.status_text
        self.final_path_xyz = path_xyz
        if self.settings['keep_alive'] and replay_step > 0 and self.tree_frames:
            # 搜索通常很快，按真实节点接受顺序慢放；回放时间不计入规划耗时。
            self.markers.clear_tree()
            self.replay_active = True
            self.replay_index = 0
            self.status_text = 'Python RRT: replaying recorded exploration'
            self.replay_timer = self.create_timer(replay_step, self.replay_frame)
            self.get_logger().info('开始按真实节点顺序回放探索过程；结束后显示路径和机械臂预览')
        else:
            self.markers.set_path(path_xyz)
        self.maintain_visualization()
        # 该定时器只重发已生成的消息，不在回调中请求 MoveIt 服务。
        self.visualization_timer = self.create_timer(1.0, self.maintain_visualization)
        return path_indices is not None

    def replay_frame(self):
        frame = self.tree_frames[self.replay_index]
        self.markers.add_node(*frame)
        self.replay_index += 1
        self.status_text = (
            f'RRT exploration replay | {self.replay_index}/{len(self.tree_frames)} nodes')
        if self.replay_index == len(self.tree_frames):
            self.replay_timer.cancel()
            self.markers.set_path(self.final_path_xyz)
            self.status_text = self.final_status
            self.replay_active = False
            self.previous_subscribers = 0
        self.maintain_visualization()

    def make_display_trajectory(self, path):
        result = DisplayTrajectory()
        result.model_id = self.model_name
        result.trajectory_start = self.robot_state_from_q(path[0])
        trajectory = RobotTrajectory()
        trajectory.joint_trajectory.joint_names = self.arm_joint_names
        lengths = [0.0]
        for a, b in zip(path[:-1], path[1:]):
            lengths.append(lengths[-1] + float(np.linalg.norm(b - a)))
        for q, length in zip(path, lengths):
            point = JointTrajectoryPoint()
            point.positions = [float(value) for value in q]
            # 12 秒是演示播放时长；未做可用于控制器执行的时间参数化。
            nanoseconds = int(12.0 * length / max(lengths[-1], 1e-12) * 1e9)
            point.time_from_start.sec = nanoseconds // 1_000_000_000
            point.time_from_start.nanosec = nanoseconds % 1_000_000_000
            trajectory.joint_trajectory.points.append(point)
        result.trajectory.append(trajectory)
        return result

    def maintain_visualization(self):
        self.markers.publish(self.status_text)
        count = self.trajectory_pub.get_subscription_count()
        if (not self.replay_active and self.display_trajectory is not None
                and count > self.previous_subscribers):
            self.trajectory_pub.publish(self.display_trajectory)
            self.get_logger().info('已发布 RViz 轨迹预览：/display_planned_path')
        self.previous_subscribers = count

    def save_result(self, path_indices, dense_path, path_xyz, validation_checks,
                    postprocess_seconds):
        directory = Path(self.settings['output_directory']).expanduser()
        directory /= datetime.now().strftime('%Y%m%d_%H%M%S_%f')
        directory.mkdir(parents=True, exist_ok=False)
        header = ['id', 'parent'] + self.arm_joint_names + ['tcp_x', 'tcp_y', 'tcp_z']
        with (directory / 'tree.csv').open('w', newline='') as stream:
            writer = csv.writer(stream)
            writer.writerow(header)
            for index, q in enumerate(self.planner.nodes):
                writer.writerow([index, self.planner.parents[index]] + q.tolist()
                                + self.compute_fk(q).tolist())
        with (directory / 'path.csv').open('w', newline='') as stream:
            writer = csv.writer(stream)
            writer.writerow(['waypoint'] + self.arm_joint_names + ['tcp_x', 'tcp_y', 'tcp_z'])
            for index, (q, xyz) in enumerate(zip(dense_path, path_xyz)):
                writer.writerow([index] + q.tolist() + xyz.tolist())
        length = sum(float(np.linalg.norm(b - a))
                     for a, b in zip(dense_path[:-1], dense_path[1:]))
        summary = {
            'algorithm': 'Python basic RRT (not the RViz OMPL planner)',
            'success': path_indices is not None,
            'outcome': self.planner.outcome,
            'settings': self.settings,
            'joint_names': self.arm_joint_names,
            'joint_lower': self.q_lower.tolist(), 'joint_upper': self.q_upper.tolist(),
            'limits_source': 'runtime MoveIt model; hardware limits not confirmed',
            'start': self.q_start.tolist(), 'goal': self.q_goal.tolist(),
            'iterations': self.planner.iterations,
            'tree_nodes': len(self.planner.nodes),
            'collision_checks': self.planner.collision_checks,
            'rejected_edges': self.planner.rejected_edges,
            'planning_wall_seconds_including_services_and_visualization': self.planner.elapsed_seconds,
            'postprocess_seconds': postprocess_seconds,
            'path_tree_indices': path_indices,
            'path_l2_joint_length_rad': length,
            'path_validation_checks': validation_checks,
            'path_validation_max_joint_step_rad': self.settings['collision_step'] / 2.0,
            'world_collision_objects': [obj.id for obj in self.scene.world.collision_objects],
            'octomap_bytes': len(self.scene.world.octomap.octomap.data),
            'gaussian_tree_is_visual_only': True,
            'display_only_no_execution': True,
        }
        (directory / 'summary.json').write_text(
            json.dumps(summary, ensure_ascii=False, indent=2, allow_nan=False),
            encoding='utf-8')
        self.get_logger().info(f'结果已保存：{directory}')
        return directory

def main(args=None):
    rclpy.init(args=args)
    node = RRTDemo()
    exit_code = 0

    try:
        if node.wait_for_moveit() and node.read_robot_state():
            node.load_named_states()
            node.load_joint_limits()

            start_valid = node.is_state_valid(node.q_start)
            goal_valid = node.is_state_valid(node.q_goal)
            start_name = node.settings['start_state']
            goal_name = node.settings['goal_state']

            node.get_logger().info(
                f'起点 {start_name} 的 MoveIt 状态检查：{start_valid}')
            node.get_logger().info(
                f'目标 {goal_name} 的 MoveIt 状态检查：{goal_valid}')
            if not start_valid or not goal_valid:
                raise RuntimeError('起点或目标不满足当前模型限位/碰撞检查，停止规划')

            node.p_start = node.compute_fk(node.q_start)
            node.p_goal = node.compute_fk(node.q_goal)

            node.get_logger().info(
                f'{start_name} 剪刀末端（world，米）：'
                f'{np.round(node.p_start, 6).tolist()}')

            node.get_logger().info(
                f'{goal_name} 剪刀末端（world，米）：'
                f'{np.round(node.p_goal, 6).tolist()}')
                
            node.publish_endpoints()
            solved = node.run_rrt()
            exit_code = 0 if solved else 2
            if node.settings['keep_alive']:
                node.get_logger().info('保持显示中，按 Ctrl+C 结束；未发送机械臂执行指令')
                rclpy.spin(node)
        else:
            exit_code = 1
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    except Exception as error:
        node.get_logger().error(f'{type(error).__name__}: {error}')
        exit_code = 1
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    return exit_code


if __name__ == '__main__':
    raise SystemExit(main())
