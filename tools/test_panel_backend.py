#!/usr/bin/env python3
"""Exercise the running RRT panel backend on its Ubuntu host.

Run after sourcing the workspace, with MoveIt and rrt_server running. This
script only requests planning, visualization, and task export; it never sends
robot execution commands. Avoid starting other plans while it is running.
"""

from copy import deepcopy
import csv
import json
import math
from pathlib import Path
import sys
import time

import rclpy
from action_msgs.msg import GoalStatus
from aubo_rrt_interfaces.action import PlanRRT
from aubo_rrt_interfaces.msg import Endpoint
from aubo_rrt_interfaces.srv import GetRRTInfo, PreviewRRT
from moveit_msgs.msg import DisplayTrajectory
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from std_srvs.srv import Trigger


ARM_JOINTS = (
    'shoulder_joint', 'upperArm_joint', 'foreArm_joint',
    'wrist1_joint', 'wrist2_joint', 'wrist3_joint',
)
DEFAULT_SETTINGS = {
    'step_size': 0.3, 'goal_bias': 0.1, 'collision_step': 0.04,
    'max_iterations': 2500, 'planning_time': 60.0, 'seed': 42,
    'replay_step': 0.08,
}


def require(condition, message):
    if not condition:
        raise AssertionError(message)


def joints(state):
    names = list(state.joint_state.name)
    positions = list(state.joint_state.position)
    require(len(names) == len(positions), 'Joint names/positions differ in length')
    require(len(set(names)) == len(names), 'Duplicate joint names')
    require(all(math.isfinite(x) for x in positions), 'Non-finite joint position')
    result = dict(zip(names, positions))
    require(all(name in result for name in ARM_JOINTS), 'Missing arm joint')
    return result


def pose_error(actual, expected):
    require(actual.header.frame_id == 'world', 'Unexpected pose reference frame')
    a, b = actual.pose, expected.pose
    position_error = math.sqrt(sum(
        (getattr(a.position, axis) - getattr(b.position, axis)) ** 2
        for axis in ('x', 'y', 'z')))
    qa = [getattr(a.orientation, axis) for axis in ('x', 'y', 'z', 'w')]
    qb = [getattr(b.orientation, axis) for axis in ('x', 'y', 'z', 'w')]
    na = math.sqrt(sum(x * x for x in qa))
    nb = math.sqrt(sum(x * x for x in qb))
    require(math.isfinite(na) and abs(na - 1.0) < 1e-5,
            'Returned quaternion is not unit length')
    require(math.isfinite(nb) and nb > 0.0, 'Invalid reference quaternion')
    dot = abs(sum(x * y for x, y in zip(qa, qb)) / (na * nb))
    angle_error = 2.0 * math.acos(min(1.0, max(0.0, dot)))
    require(math.isfinite(position_error), 'Non-finite pose position')
    return position_error, angle_error


def endpoint(mode, name='', pose=None):
    result = Endpoint()
    result.mode = mode
    result.name = name
    if pose is not None:
        result.pose = deepcopy(pose)
    return result


class BackendChecks(Node):
    def __init__(self):
        super().__init__('rrt_panel_integration_checks')
        self.info_client = self.create_client(GetRRTInfo, '/rrt_python/info')
        self.preview_client = self.create_client(PreviewRRT, '/rrt_python/preview')
        self.replay_client = self.create_client(Trigger, '/rrt_python/replay')
        self.save_client = self.create_client(Trigger, '/rrt_python/save_task')
        self.plan_client = ActionClient(self, PlanRRT, '/rrt_python/plan')
        qos = QoSProfile(
            depth=10, reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.trajectory_subscription = self.create_subscription(
            DisplayTrajectory, '/display_planned_path', self.on_trajectory, qos)
        self.trajectory_count = 0
        self.last_trajectory = None
        self.feedback = []
        self.active_goal = None
        self.report = []

    def on_trajectory(self, message):
        # An empty message is a cache-clear operation, not an old playback.
        if any(item.joint_trajectory.points for item in message.trajectory):
            self.trajectory_count += 1
            self.last_trajectory = message

    def on_feedback(self, message):
        feedback = message.feedback
        # Keep a compact record, rather than accumulating an unbounded trace.
        entry = (feedback.phase, int(feedback.iterations), int(feedback.tree_nodes))
        if len(self.feedback) < 100:
            self.feedback.append(entry)

    def wait_future(self, future, timeout=30.0):
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout)
        if not future.done():
            future.cancel()
            raise TimeoutError(f'ROS response exceeded {timeout:g} seconds')
        result = future.result()
        require(result is not None, 'ROS response is empty')
        return result

    def spin_for(self, seconds):
        deadline = time.monotonic() + seconds
        while rclpy.ok() and time.monotonic() < deadline:
            rclpy.spin_once(self, timeout_sec=max(0.0, min(0.1, deadline - time.monotonic())))

    def wait_until(self, predicate, timeout, description):
        deadline = time.monotonic() + timeout
        while rclpy.ok() and not predicate():
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                raise TimeoutError(description)
            rclpy.spin_once(self, timeout_sec=min(0.1, remaining))

    def record(self, name, **details):
        entry = {'test': name, 'success': True, **details}
        self.report.append(entry)
        print(json.dumps(entry, ensure_ascii=False, allow_nan=False), flush=True)

    def ready(self):
        for client in (self.info_client, self.preview_client,
                       self.replay_client, self.save_client):
            require(client.wait_for_service(timeout_sec=30.0),
                    f'Service unavailable: {client.srv_name}')
        require(self.plan_client.wait_for_server(timeout_sec=30.0),
                'Plan action unavailable')
        self.record('services_ready')

    def preview(self, start, goal, settings=None):
        request = PreviewRRT.Request()
        request.start, request.goal = deepcopy(start), deepcopy(goal)
        for name, value in (settings or DEFAULT_SETTINGS).items():
            setattr(request, name, value)
        return self.wait_future(self.preview_client.call_async(request), 45.0)

    def assert_full_state(self, state, reference, current=False):
        actual, expected = joints(state), joints(reference)
        require(set(actual) == set(expected), 'Full RobotState joint set was lost')
        for name, value in expected.items():
            if current or name not in ARM_JOINTS:
                require(abs(actual[name] - value) < 1e-6,
                        f'Unexpected change to {name}')
        require('scissor_drive_joint' in actual and 'scissor_mimic_joint' in actual,
                'Scissor joints missing')
        require([x.object.id for x in state.attached_collision_objects]
                == [x.object.id for x in reference.attached_collision_objects],
                'Attached object IDs were lost')
        require(list(state.multi_dof_joint_state.joint_names)
                == list(reference.multi_dof_joint_state.joint_names),
                'Multi-DOF joint names were lost')

    def make_goal(self, start, goal):
        request = PlanRRT.Goal()
        request.start, request.goal = deepcopy(start), deepcopy(goal)
        for name, value in DEFAULT_SETTINGS.items():
            setattr(request, name, value)
        request.replay_step = 0.0
        return request

    def save_task(self, test_name, expected_settings):
        saved = self.wait_future(self.save_client.call_async(Trigger.Request()), 15.0)
        require(saved.success, f'Save failed: {saved.message}')
        # The service contract returns an absolute path; tolerate a preceding label.
        text = saved.message.strip()
        path = Path(text[text.find('/'):].strip()) if '/' in text else Path(text)
        require(path.is_absolute() and path.is_file(), 'Saved task file missing')
        task = json.loads(path.read_text(encoding='utf-8'))
        require(isinstance(task, dict) and bool(task), 'Saved task JSON is empty')
        require('settings' in task, 'Saved task has no settings field')
        for name, value in expected_settings.items():
            require(task['settings'].get(name) == value,
                    f'Saved task settings differ for {name}')
        self.record(test_name, task_file=str(path))

    def send_goal(self, request):
        self.feedback = []
        handle = self.wait_future(self.plan_client.send_goal_async(
            request, feedback_callback=self.on_feedback), 15.0)
        require(handle.accepted, 'Plan action rejected a valid request')
        self.active_goal = handle
        return handle

    def successful_plan(self, request, expected_preview, test_name):
        before = self.trajectory_count
        handle = self.send_goal(request)
        wrapped = self.wait_future(handle.get_result_async(), 150.0)
        self.active_goal = None
        result = wrapped.result
        require(wrapped.status == GoalStatus.STATUS_SUCCEEDED, 'Action not succeeded')
        require(result.success, f'Planning failed: {result.message}')
        require(result.tree_nodes >= result.path_nodes >= 2, 'Invalid path/node counts')
        require(math.isfinite(result.planning_seconds) and result.planning_seconds >= 0,
                'Invalid reported planning duration')
        directory = Path(result.output_directory)
        require(directory.is_absolute() and directory.is_dir(), 'Export directory missing')
        path_file = directory / 'path.csv'
        require(path_file.is_file(), 'Exported path.csv missing')
        with path_file.open(newline='', encoding='utf-8') as stream:
            rows = list(csv.DictReader(stream))
        require(len(rows) >= 2, 'Exported path is empty')
        for row, expected in ((rows[0], expected_preview.start_state),
                              (rows[-1], expected_preview.goal_state)):
            expected_joints = joints(expected)
            for name in ARM_JOINTS:
                require(name in row and abs(float(row[name]) - expected_joints[name]) < 1e-6,
                        f'Exported endpoint differs at {name}')
        self.wait_until(lambda: self.trajectory_count > before, 15.0,
                        'Successful plan did not publish a non-empty trajectory')
        self.assert_full_state(self.last_trajectory.trajectory_start,
                               expected_preview.start_state, current=True)
        self.record(test_name, tree_nodes=int(result.tree_nodes),
                    path_nodes=int(result.path_nodes), feedback_count=len(self.feedback),
                    exported_path_rows=len(rows), output_directory=str(directory))

    def run_checks(self):
        self.ready()
        info = self.wait_future(self.info_client.call_async(GetRRTInfo.Request()), 45.0)
        require(info.ready, f'Backend is not ready: {info.message}')
        require('pose1' in info.named_states, 'Expected named state pose1 missing')
        joints(info.current_state)
        pose_error(info.current_pose, info.current_pose)
        self.record('info_current_fk', named_states=list(info.named_states),
                    joint_count=len(info.current_state.joint_state.name))

        start = endpoint(Endpoint.CURRENT)
        goal = endpoint(Endpoint.NAMED, name='pose1')
        named = self.preview(start, goal)
        require(named.success, f'Named preview failed: {named.message}')
        self.assert_full_state(named.start_state, info.current_state, current=True)
        self.assert_full_state(named.goal_state, info.current_state)
        position_error, angle_error = pose_error(named.start_pose, info.current_pose)
        require(position_error < 1e-5 and angle_error < 1e-5, 'CURRENT FK changed')
        self.record('preview_current_named_preserves_state')

        pose_goal = endpoint(Endpoint.POSE, pose=named.goal_pose)
        solved = self.preview(start, pose_goal)
        require(solved.success, f'Pose IK preview failed: {solved.message}')
        self.assert_full_state(solved.goal_state, info.current_state)
        position_error, angle_error = pose_error(solved.goal_pose, named.goal_pose)
        require(position_error <= 0.002 and angle_error <= 0.01,
                'IK solution misses requested pose tolerance')
        self.record('preview_pose_ik', position_error_m=position_error,
                    orientation_error_rad=angle_error)
        self.save_task('save_after_preview', DEFAULT_SETTINGS)

        invalid = deepcopy(pose_goal)
        invalid.pose.header.frame_id = 'unavailable_test_frame'
        bad_nan = deepcopy(pose_goal)
        bad_nan.pose.pose.position.x = float('nan')
        bad_quaternion = deepcopy(pose_goal)
        bad_quaternion.pose.pose.orientation.x = 0.0
        bad_quaternion.pose.pose.orientation.y = 0.0
        bad_quaternion.pose.pose.orientation.z = 0.0
        bad_quaternion.pose.pose.orientation.w = 0.0
        unreachable = deepcopy(pose_goal)
        unreachable.pose.pose.position.x = 100.0
        unreachable.pose.pose.position.y = 100.0
        unreachable.pose.pose.position.z = 100.0
        for label, bad_goal in (
                ('invalid_frame', invalid), ('nan_position', bad_nan),
                ('zero_quaternion', bad_quaternion), ('unreachable_pose', unreachable)):
            response = self.preview(start, bad_goal)
            require(not response.success, f'Invalid input accepted: {label}')
            require(bool(response.message.strip()), f'No explanation for {label}')
            self.record('reject_' + label, reason=response.message[:300])

        response = self.preview(start, goal, {**DEFAULT_SETTINGS, 'step_size': float('nan')})
        require(not response.success, 'Preview accepted a non-finite planning parameter')
        require(bool(response.message.strip()), 'No explanation for invalid planning parameter')
        self.record('reject_nan_planning_parameter', reason=response.message[:300])

        # A planning action must perform its own validation without a prior preview.
        request = self.make_goal(start, goal)
        self.successful_plan(request, named, 'first_plan_and_export')

        self.spin_for(0.3)  # Drain already queued samples from the completed run.
        cancellable = self.make_goal(start, goal)
        cancellable.step_size = 0.01
        cancellable.goal_bias = 0.0
        cancellable.max_iterations = 100000
        handle = self.send_goal(cancellable)
        second_handle = self.wait_future(self.plan_client.send_goal_async(request), 15.0)
        if second_handle.accepted:
            self.wait_future(second_handle.cancel_goal_async(), 10.0)
        require(not second_handle.accepted, 'Busy backend accepted a second plan')
        self.record('busy_plan_rejected')
        cancellation = self.wait_future(handle.cancel_goal_async(), 10.0)
        require(len(cancellation.goals_canceling) == 1, 'Cancellation was not accepted')
        wrapped = self.wait_future(handle.get_result_async(), 30.0)
        self.active_goal = None
        require(wrapped.status == GoalStatus.STATUS_CANCELED, 'Action did not end canceled')
        require(not wrapped.result.success, 'Canceled action reported success')
        nonempty_after_cancel = self.trajectory_count
        replay = self.wait_future(self.replay_client.call_async(Trigger.Request()), 10.0)
        require(not replay.success, 'Canceled request retained a replayable old result')
        # Observation window spans the existing 1-second visualization maintenance timer.
        # This checks absence of stale publication, not the duration of planning.
        self.spin_for(1.5)
        require(self.trajectory_count == nonempty_after_cancel,
                'A non-empty stale trajectory arrived after cancellation')
        self.record('cancel_clears_old_result', replay_rejected=True)

        self.successful_plan(request, named, 'plan_again_after_cancel')
        before_replay = self.trajectory_count
        replay = self.wait_future(self.replay_client.call_async(Trigger.Request()), 10.0)
        require(replay.success, f'Replay failed: {replay.message}')
        self.wait_until(lambda: self.trajectory_count > before_replay, 15.0,
                        'Replay did not republish the successful trajectory')
        self.record('replay_success')

        self.save_task('save_after_plan', {**DEFAULT_SETTINGS, 'replay_step': 0.0})

    def cancel_on_failure(self):
        if self.active_goal is not None:
            try:
                self.wait_future(self.active_goal.cancel_goal_async(), 5.0)
            except Exception:
                pass
            self.active_goal = None


def main():
    rclpy.init()
    node = BackendChecks()
    started = time.monotonic()
    failure = None
    try:
        node.run_checks()
    except (Exception, KeyboardInterrupt) as error:
        failure = f'{type(error).__name__}: {error}'
        node.cancel_on_failure()
    finally:
        report = {
            'suite': 'rrt_panel_backend', 'success': failure is None,
            'passed': len(node.report), 'elapsed_seconds': round(time.monotonic() - started, 3),
            'failure': failure, 'execution_commands_sent': False,
        }
        print(json.dumps(report, ensure_ascii=False, allow_nan=False), flush=True)
        node.plan_client.destroy()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
    return 0 if failure is None else 1


if __name__ == '__main__':
    sys.exit(main())
