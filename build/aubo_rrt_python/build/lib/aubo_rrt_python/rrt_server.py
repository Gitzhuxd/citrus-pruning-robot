"""RViz 面板的常驻后端：位姿校验、基础 RRT、显示与任务保存。"""

from copy import deepcopy
from datetime import datetime
import json
from pathlib import Path
import threading
import time

import numpy as np
import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor, ExternalShutdownException
from rclpy.qos import QoSProfile, DurabilityPolicy, ReliabilityPolicy
from moveit_msgs.msg import DisplayRobotState, DisplayTrajectory, MoveItErrorCodes, PlanningSceneComponents, ObjectColor
from moveit_msgs.srv import GetPositionFK, GetPositionIK, GetPlanningScene
from std_srvs.srv import Trigger
from std_msgs.msg import ColorRGBA
from aubo_rrt_interfaces.msg import Endpoint
from aubo_rrt_interfaces.srv import GetRRTInfo, PreviewRRT
from aubo_rrt_interfaces.action import PlanRRT

from aubo_rrt_python.rrt_demo import RRTDemo
from aubo_rrt_python.rrt_core import RRTPlanner, PlanningCancelled, interpolate_edge
from aubo_rrt_python.task_math import DEFAULTS, validate_settings, validate_pose_values, pose_error


def pose_values(pose):
    p, q = pose.pose.position, pose.pose.orientation
    return [p.x, p.y, p.z], [q.x, q.y, q.z, q.w]


def pose_json(pose):
    p, q = pose_values(pose)
    return {'frame': pose.header.frame_id, 'position_m': p, 'quaternion_xyzw': q}


class RRTServer(RRTDemo):
    def __init__(self):
        clients = ReentrantCallbackGroup()
        super().__init__('aubo_rrt_server', clients)
        self.ik_client = self.create_client(GetPositionIK, '/compute_ik', callback_group=clients)
        # Service waits occur on worker callbacks. Other executor threads deliver responses.
        self.operations = ReentrantCallbackGroup()
        self.job = threading.Lock()
        self.job.acquire()  # Reserved until model initialization completes.
        self.visual_lock = threading.RLock()
        self.ready = False
        self.active_goal = None
        self.cancel_event = threading.Event()
        self.committing = False
        self.task = None
        self.info_cache = None
        self.phase = '等待 MoveIt'
        self.job_started = time.monotonic()
        self.feedback_at = 0.0
        self.planner = None
        self.last_output_directory = None
        self.replay_index = 0
        self.replay_next = 0.0
        qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL,
                         reliability=ReliabilityPolicy.RELIABLE)
        self.start_pub = self.create_publisher(DisplayRobotState, '/rrt_python/start_state', qos)
        self.goal_pub = self.create_publisher(DisplayRobotState, '/rrt_python/goal_state', qos)
        self.endpoint_displays = (DisplayRobotState(hide=True), DisplayRobotState(hide=True))
        self.panel_services = [
            self.create_service(GetRRTInfo, '/rrt_python/info', self.info, callback_group=self.operations),
            self.create_service(PreviewRRT, '/rrt_python/preview', self.preview, callback_group=self.operations),
            self.create_service(Trigger, '/rrt_python/replay', self.replay, callback_group=self.operations),
            self.create_service(Trigger, '/rrt_python/save_task', self.save_task, callback_group=self.operations),
        ]
        self.action = ActionServer(
            self, PlanRRT, '/rrt_python/plan', self.execute,
            goal_callback=self.accept_goal, cancel_callback=self.cancel_goal,
            callback_group=self.operations)
        self.init_timer = self.create_timer(1.0, self.initialize)
        self.display_timer = self.create_timer(0.02, self.display_tick)
        self.maintenance_at = 0.0

    def check_cancel(self):
        handle = self.active_goal
        if not rclpy.ok() or self.cancel_event.is_set() or (handle is not None and handle.is_cancel_requested):
            raise PlanningCancelled('规划已取消')

    def wait_for_future(self, future, timeout_sec=5.0):
        event = threading.Event()
        future.add_done_callback(lambda _: event.set())
        deadline = time.monotonic() + timeout_sec
        try:
            while not future.done() and time.monotonic() < deadline:
                self.check_cancel()
                event.wait(0.03)
            self.check_cancel()
        except PlanningCancelled:
            future.cancel()
            raise

    def call(self, client, request, timeout=5.0):
        future = client.call_async(request)
        self.wait_for_future(future, timeout)
        if not future.done():
            future.cancel()
            raise RuntimeError(f'服务响应超时：{client.srv_name}')
        response = future.result()
        if response is None:
            raise RuntimeError(f'服务返回为空：{client.srv_name}')
        return response

    def initialize(self):
        if not all(client.service_is_ready() for client in (
                self.scene_client, self.validity_client, self.fk_client,
                self.parameter_client, self.ik_client)):
            return
        try:
            if not self.read_robot_state():
                return
            self.load_named_states()
            self.load_joint_limits()
            self.info_cache = (deepcopy(self.robot_state), self.fk_pose(self.robot_state))
            self.ready = True
            self.phase = '就绪'
            self.init_timer.cancel()
            self.job.release()
            self.get_logger().info('RRT 面板后台已就绪：world / scissor_tcp / aubo_arm')
        except Exception as error:
            self.phase = str(error)
            self.get_logger().error(f'初始化失败，稍后重试：{error}')

    def current_scene(self):
        request = GetPlanningScene.Request()
        request.components.components = (PlanningSceneComponents.ROBOT_STATE
            | PlanningSceneComponents.ROBOT_STATE_ATTACHED_OBJECTS
            | PlanningSceneComponents.WORLD_OBJECT_GEOMETRY | PlanningSceneComponents.OCTOMAP)
        return self.call(self.scene_client, request).scene

    def fk_pose(self, state):
        request = GetPositionFK.Request()
        request.header.frame_id = 'world'
        request.fk_link_names = ['scissor_tcp']
        request.robot_state = state
        response = self.call(self.fk_client, request)
        if (response.error_code.val != MoveItErrorCodes.SUCCESS
                or response.fk_link_names != ['scissor_tcp'] or len(response.pose_stamped) != 1):
            raise RuntimeError(f'末端正运动学失败：{response.error_code.val}')
        pose = response.pose_stamped[0]
        if pose.header.frame_id != 'world':
            raise RuntimeError('FK 返回的坐标系不是 world')
        validate_pose_values(*pose_values(pose))
        return pose

    def arm_values(self, state):
        values = dict(zip(state.joint_state.name, state.joint_state.position))
        return np.array([values[name] for name in self.arm_joint_names], dtype=float)

    def info(self, request, response):
        response.ready = self.ready
        response.message = self.phase
        if not self.ready:
            return response
        if self.job.acquire(blocking=False):
            try:
                state = self.current_scene().robot_state
                self.info_cache = (state, self.fk_pose(state))
                response.message = '就绪'
            except Exception as error:
                response.ready = False
                response.message = str(error)
            finally:
                self.job.release()
        else:
            response.message = '忙碌；显示上次读取的当前姿态'
        response.named_states = list(self.named_states)
        if self.info_cache:
            response.current_state, response.current_pose = deepcopy(self.info_cache)
        return response

    def reset_display(self):
        with self.visual_lock:
            self.replay_active = False
            self.display_trajectory = None
            self.tree_frames = []
            self.fk_cache.clear()
            self.markers.clear_all()
            self.markers.publish()
            self.trajectory_pub.publish(DisplayTrajectory())
            self.endpoint_displays = (DisplayRobotState(hide=True), DisplayRobotState(hide=True))
            self.start_pub.publish(self.endpoint_displays[0])
            self.goal_pub.publish(self.endpoint_displays[1])
            self.task = None
            self.planner = None
            self.last_output_directory = None

    def resolve_endpoint(self, endpoint, seed):
        if endpoint.mode == Endpoint.CURRENT:
            q = self.arm_values(self.robot_state)
        elif endpoint.mode == Endpoint.NAMED:
            if endpoint.name not in self.named_states:
                raise ValueError(f'未知命名状态：{endpoint.name}')
            q = self.named_states[endpoint.name].copy()
        elif endpoint.mode == Endpoint.POSE:
            if endpoint.pose.header.frame_id != 'world':
                raise ValueError('输入位姿必须使用 world 坐标系')
            validate_pose_values(*pose_values(endpoint.pose))
            request = GetPositionIK.Request()
            request.ik_request.group_name = 'aubo_arm'
            request.ik_request.ik_link_name = 'scissor_tcp'
            request.ik_request.robot_state = self.robot_state_from_q(seed)
            request.ik_request.pose_stamped = endpoint.pose
            request.ik_request.avoid_collisions = True
            request.ik_request.timeout.sec = 1
            result = self.call(self.ik_client, request, 4.0)
            if result.error_code.val != MoveItErrorCodes.SUCCESS:
                raise ValueError(f'当前 IK 求解未找到无碰撞解（错误码 {result.error_code.val}）；请调整位姿')
            q = self.arm_values(result.solution)
        else:
            raise ValueError('未知起终点输入方式')
        self.check_cancel()
        if not self.is_state_valid(q):
            raise ValueError('关节状态超出模型限位或未通过 MoveIt 碰撞检查')
        state = self.robot_state_from_q(q)
        pose = self.fk_pose(state)
        if endpoint.mode == Endpoint.POSE:
            position_error, angle_error = pose_error(*pose_values(pose), *pose_values(endpoint.pose))
            if position_error > 0.002 or angle_error > 0.01:
                raise ValueError(f'IK 误差超限：位置 {position_error:.4f} m，姿态 {angle_error:.4f} rad')
        return q, state, pose

    def prepare(self, request):
        self.reset_display()
        settings = validate_settings({key: getattr(request, key) for key in DEFAULTS})
        self.settings.update(settings)
        for key, endpoint in (('start_state', request.start), ('goal_state', request.goal)):
            self.settings[key] = endpoint.name if endpoint.mode == Endpoint.NAMED else (
                'current' if endpoint.mode == Endpoint.CURRENT else 'manual_pose')
        self.scene = self.current_scene()
        self.robot_state = self.scene.robot_state
        seed = self.arm_values(self.robot_state)
        self.phase = '校验起点'
        self.publish_feedback()
        try:
            self.q_start, start_state, start_pose = self.resolve_endpoint(request.start, seed)
        except ValueError as error:
            raise ValueError(f'起点：{error}') from error
        self.phase = '校验终点'
        self.publish_feedback()
        try:
            self.q_goal, goal_state, goal_pose = self.resolve_endpoint(request.goal, self.q_start)
        except ValueError as error:
            raise ValueError(f'终点：{error}') from error
        self.p_start, self.p_goal = np.array(pose_values(start_pose)[0]), np.array(pose_values(goal_pose)[0])
        def description(endpoint, state, pose):
            result = {'mode': int(endpoint.mode), 'name': endpoint.name,
                      'resolved_joints_rad': self.arm_values(state).tolist(), 'resolved_pose': pose_json(pose)}
            if endpoint.mode == Endpoint.POSE:
                result['requested_pose'] = pose_json(endpoint.pose)
            return result
        self.task = {
            'schema_version': 1, 'group': 'aubo_arm', 'tcp': 'scissor_tcp', 'frame': 'world',
            'settings': settings, 'joint_names': self.arm_joint_names,
            'start': description(request.start, start_state, start_pose),
            'goal': description(request.goal, goal_state, goal_pose),
            'full_state_joint_names': list(self.robot_state.joint_state.name),
            'full_state_positions_rad': list(self.robot_state.joint_state.position),
            'joint_lower': self.q_lower.tolist(), 'joint_upper': self.q_upper.tolist(),
            'display_only_no_execution': True, 'gaussian_tree_is_visual_only': True,
        }
        with self.visual_lock:
            self.markers.set_endpoints(self.p_start, self.p_goal, 'Start', 'Goal')
            self.markers.set_endpoint_poses(start_pose, goal_pose)
            self.status_text = 'Endpoints valid'
            self.markers.publish(self.status_text)
            self.endpoint_displays = (DisplayRobotState(state=start_state), DisplayRobotState(state=goal_state))
            links = ['shoulder_Link', 'upperArm_Link', 'foreArm_Link', 'wrist1_Link',
                     'wrist2_Link', 'wrist3_Link', 'scissor_base_link',
                     'scissor_active_blade_link', 'scissor_mimic_blade_link']
            for display, color in zip(self.endpoint_displays, [(0.1, 0.85, 0.25), (0.95, 0.25, 0.12)]):
                display.highlight_links = [ObjectColor(id=link,
                    color=ColorRGBA(r=color[0], g=color[1], b=color[2], a=1.0)) for link in links]
            self.start_pub.publish(self.endpoint_displays[0])
            self.goal_pub.publish(self.endpoint_displays[1])
        return start_state, goal_state, start_pose, goal_pose

    def preview(self, request, response):
        if not self.ready or not self.job.acquire(blocking=False):
            response.message = '后台未就绪或正在处理任务'
            return response
        try:
            (response.start_state, response.goal_state,
             response.start_pose, response.goal_pose) = self.prepare(request)
            response.success = True
            response.message = '起终点已通过 IK / 模型限位 / 碰撞检查'
        except Exception as error:
            self.reset_display()
            response.message = str(error)
        finally:
            self.phase = '就绪'
            self.job.release()
        return response

    def accept_goal(self, request):
        if self.ready and self.job.acquire(blocking=False):
            self.cancel_event.clear()
            self.committing = False
            return GoalResponse.ACCEPT
        return GoalResponse.REJECT

    def cancel_goal(self, handle):
        with self.visual_lock:
            if self.committing or not handle.is_active:
                return CancelResponse.REJECT
            self.cancel_event.set()
            self.replay_active = False
            return CancelResponse.ACCEPT

    def publish_feedback(self):
        handle = self.active_goal
        if handle is None or not handle.is_active:
            return
        feedback = PlanRRT.Feedback()
        feedback.phase = self.phase
        if self.planner:
            feedback.iterations = self.planner.iterations
            feedback.tree_nodes = len(self.planner.nodes)
        feedback.elapsed_seconds = time.monotonic() - self.job_started
        handle.publish_feedback(feedback)

    def on_tree_node(self, index, q, parent):
        self.check_cancel()
        # FK services may block, so do not hold the visualization lock while querying.
        curve = None if parent < 0 else [self.compute_fk(state) for state in
                    interpolate_edge(self.planner.nodes[parent], q, 0.08)]
        xyz = self.compute_fk(q)
        with self.visual_lock:
            self.markers.add_node(index, xyz, parent, curve)
            self.tree_frames.append((index, xyz, parent, curve))
            self.status_text = f'Python RRT | iteration {self.planner.iterations} | nodes {index + 1}'
            if time.monotonic() - self.last_marker_time > 0.1:
                self.markers.publish(self.status_text)
                self.last_marker_time = time.monotonic()

    def execute(self, handle):
        self.active_goal = handle
        self.job_started = time.monotonic()
        result = PlanRRT.Result()
        try:
            self.prepare(handle.request)
            self.check_cancel()
            self.phase = 'RRT 搜索'
            self.planner = RRTPlanner(
                self.q_lower, self.q_upper, self.is_state_valid,
                step_size=self.settings['step_size'], goal_bias=self.settings['goal_bias'],
                collision_step=self.settings['collision_step'], max_iterations=self.settings['max_iterations'],
                max_seconds=self.settings['planning_time'], seed=self.settings['seed'],
                on_node=self.on_tree_node, cancel_check=self.check_cancel)
            indices = self.planner.plan(self.q_start, self.q_goal)
            result.iterations = self.planner.iterations
            result.tree_nodes = len(self.planner.nodes)
            result.planning_seconds = self.planner.elapsed_seconds
            self.phase = '细化复验与保存'
            self.publish_feedback()
            postprocess = time.monotonic()
            dense, xyz = [], []
            if indices is not None:
                path = [self.planner.nodes[i] for i in indices]
                dense = [path[0]]
                for a, b in zip(path[:-1], path[1:]):
                    self.check_cancel()
                    dense.extend(interpolate_edge(a, b, self.settings['collision_step'] / 2)[1:])
                for q in dense:
                    self.check_cancel()
                    if not self.is_state_valid(q):
                        raise RuntimeError('最终路径细化复验失败；请检查场景是否变化')
                    xyz.append(self.compute_fk(q))
            directory = self.save_result(indices, dense, xyz, len(dense), time.monotonic() - postprocess)
            self.check_cancel()
            (directory / 'task.json').write_text(json.dumps(self.task, ensure_ascii=False, indent=2,
                                                          allow_nan=False), encoding='utf-8')
            result.output_directory = str(directory)
            self.last_output_directory = directory
            if indices is None:
                with self.visual_lock:
                    self.check_cancel()
                    self.committing = True
                    result.message = f'预算内未找到路径：{self.planner.outcome}'
                    self.status_text = 'RRT: no path found'
                    handle.abort()
            else:
                result.path_nodes = len(indices)
                with self.visual_lock:
                    self.check_cancel()
                    self.committing = True
                    self.display_trajectory = self.make_display_trajectory(dense)
                    self.final_path_xyz = xyz
                    self.final_status = f'RRT solved | {len(self.planner.nodes)} nodes | {len(indices)} path nodes'
                    self.start_replay()
                    result.success = True
                    result.message = '规划成功，已通过路径细化复验；仅显示预览'
                    handle.succeed()
        except PlanningCancelled:
            self.reset_display()
            result.message = '已取消；本次及上次回放缓存已清除'
            # rclpy transitions to CANCELING just after the cancel callback returns.
            deadline = time.monotonic() + 1.0
            while rclpy.ok() and self.cancel_event.is_set() and not handle.is_cancel_requested and time.monotonic() < deadline:
                time.sleep(0.005)
            if handle.is_cancel_requested:
                handle.canceled()
            else:
                handle.abort()
        except Exception as error:
            self.reset_display()
            result.message = str(error)
            self.get_logger().error(f'规划失败：{error}')
            handle.abort()
        finally:
            self.active_goal = None
            self.cancel_event.clear()
            self.phase = '就绪'
            self.job.release()
        return result

    def start_replay(self):
        # Caller holds visual_lock; the 50 Hz timer only uses recorded data.
        if self.settings['replay_step'] > 0 and self.tree_frames:
            self.markers.clear_tree()
            self.replay_active = True
            self.replay_index = 0
            self.replay_next = 0.0
            self.trajectory_pub.publish(DisplayTrajectory())
        else:
            self.markers.set_path(self.final_path_xyz)
            self.status_text = self.final_status
            self.trajectory_pub.publish(self.display_trajectory)
            self.replay_active = False
        self.markers.publish(self.status_text)

    def display_tick(self):
        if not self.ready:
            return
        now = time.monotonic()
        if self.active_goal is not None and now - self.feedback_at > 0.25:
            self.publish_feedback()
            self.feedback_at = now
        with self.visual_lock:
            if self.replay_active and now >= self.replay_next:
                self.markers.add_node(*self.tree_frames[self.replay_index])
                self.replay_index += 1
                self.replay_next = now + self.settings['replay_step']
                self.status_text = f'Exploration replay | {self.replay_index}/{len(self.tree_frames)} nodes'
                if self.replay_index >= len(self.tree_frames):
                    self.replay_active = False
                    self.markers.set_path(self.final_path_xyz)
                    self.status_text = self.final_status
                    self.trajectory_pub.publish(self.display_trajectory)
                self.markers.publish(self.status_text)
            if now - self.maintenance_at >= 1.0:
                self.markers.publish(self.status_text)
                # Humble RobotState display uses a volatile subscription; resend cached poses.
                self.start_pub.publish(self.endpoint_displays[0])
                self.goal_pub.publish(self.endpoint_displays[1])
                self.maintenance_at = now

    def replay(self, request, response):
        if not self.ready or not self.job.acquire(blocking=False):
            response.message = '后台未就绪或忙碌'
            return response
        try:
            with self.visual_lock:
                if self.display_trajectory is None:
                    response.message = '没有可回放的成功规划'
                else:
                    self.start_replay()
                    response.success = True
                    response.message = '已开始回放'
        finally:
            self.job.release()
        return response

    def save_task(self, request, response):
        if not self.ready or not self.job.acquire(blocking=False):
            response.message = '后台未就绪或忙碌'
            return response
        try:
            if self.task is None:
                response.message = '请先成功预览或规划当前任务'
                return response
            directory = Path(self.settings['output_directory']).expanduser() / 'tasks'
            directory.mkdir(parents=True, exist_ok=True)
            path = directory / (datetime.now().strftime('%Y%m%d_%H%M%S_%f') + '.json')
            path.write_text(json.dumps(self.task, ensure_ascii=False, indent=2, allow_nan=False), encoding='utf-8')
            response.success, response.message = True, str(path)
        except Exception as error:
            response.message = str(error)
        finally:
            self.job.release()
        return response


def main(args=None):
    rclpy.init(args=args)
    node = RRTServer()
    executor = MultiThreadedExecutor(num_threads=6)
    executor.add_node(node)
    try:
        executor.spin()
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        if rclpy.ok():
            rclpy.shutdown()
        executor.shutdown()
        node.destroy_node()


if __name__ == '__main__':
    main()
