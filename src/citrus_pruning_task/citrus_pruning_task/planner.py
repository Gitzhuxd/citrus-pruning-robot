"""MoveIt service wrapper and RViz replay shared by the S01 task.

Extracted verbatim from the verified S01 experiment script
``s01_stump_demo_v1/plan_s01.py`` (identical in pruning_retry_v1,
pruning_closure_screen_v1 and pruning_seeded_s07_v1). Only the old
command-line ``run``/``main`` (and their now-unused imports) were removed;
the planning logic is unchanged.
"""
import copy
import math
import time

import numpy as np
import rclpy
from geometry_msgs.msg import Pose, PoseStamped
from moveit_msgs.msg import Constraints, DisplayTrajectory, JointConstraint, MoveItErrorCodes
from moveit_msgs.srv import GetCartesianPath, GetMotionPlan, GetPositionFK, GetPositionIK, GetStateValidity
from rclpy.duration import Duration
from rclpy.qos import DurabilityPolicy, QoSProfile
from sensor_msgs.msg import JointState
from scipy.spatial.transform import Rotation


GROUP = "aubo_arm"
TIP = "scissor_tcp"
FRAME = "world"
DISPLAY_TOPIC = "/citrus/s01/display_trajectory"
OPEN_JOINT = "scissor_drive_joint"
OPEN_MIMIC = "scissor_mimic_joint"
OPEN_POSITION = 0.3009
CAD_MOUTH_BASE = np.array([0.0008, 0.140, 0.007])
NOMINAL_TIP_BASE = np.array([0.0, 0.150, 0.005])
MOUTH_OFFSET = Rotation.from_euler("x", -1.5708).inv().apply(CAD_MOUTH_BASE - NOMINAL_TIP_BASE)


def unit(vector):
    return vector / np.linalg.norm(vector)


def to_pose(position, rotation):
    pose = Pose()
    pose.position.x, pose.position.y, pose.position.z = map(float, position)
    pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w = rotation.as_quat().tolist()
    return pose


def joint_values(state):
    return dict(zip(state.joint_state.name, state.joint_state.position))


def with_positions(state, updates, *, blade_position=OPEN_POSITION):
    result = copy.deepcopy(state)
    values = joint_values(state)
    values.update(updates)
    values[OPEN_JOINT] = blade_position
    values[OPEN_MIMIC] = -blade_position
    result.joint_state.name = list(values)
    result.joint_state.position = list(values.values())
    result.joint_state.velocity = []
    result.joint_state.effort = []
    result.is_diff = False
    return result


def require_success(code, stage):
    if code.val != MoveItErrorCodes.SUCCESS:
        raise ValueError(f"{stage}: MoveIt code {code.val}")


class Planner:
    def __init__(self, node):
        self.node = node
        self.ik = node.create_client(GetPositionIK, "/compute_ik")
        self.fk = node.create_client(GetPositionFK, "/compute_fk")
        self.valid = node.create_client(GetStateValidity, "/check_state_validity")
        self.plan = node.create_client(GetMotionPlan, "/plan_kinematic_path")
        self.cart = node.create_client(GetCartesianPath, "/compute_cartesian_path")

    def call(self, client, request, timeout=12.0):
        if not client.wait_for_service(timeout_sec=5.0):
            raise RuntimeError(f"Missing {client.srv_name}")
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self.node, future, timeout_sec=timeout)
        if not future.done():
            raise RuntimeError(f"Timed out: {client.srv_name}")
        return future.result()

    def valid_state(self, state, label):
        request = GetStateValidity.Request()
        request.robot_state = state
        # Empty group checks the whole robot, including the blades.
        result = self.call(self.valid, request)
        if not result.valid:
            contacts = sorted({(c.contact_body_1, c.contact_body_2) for c in result.contacts})
            raise ValueError(f"{label}: invalid state, contacts={contacts[:6]}")

    def inverse(self, start, goal, arm_names):
        request = GetPositionIK.Request()
        request.ik_request.group_name = GROUP
        request.ik_request.ik_link_name = TIP
        request.ik_request.robot_state = start
        request.ik_request.avoid_collisions = True
        request.ik_request.timeout.nanosec = 900_000_000
        request.ik_request.pose_stamped = PoseStamped()
        request.ik_request.pose_stamped.header.frame_id = FRAME
        request.ik_request.pose_stamped.pose = goal
        response = self.call(self.ik, request)
        require_success(response.error_code, "precut IK")
        values = joint_values(response.solution)
        goal_state = with_positions(start, {name: values[name] for name in arm_names})
        self.valid_state(goal_state, "precut IK")
        return goal_state

    def transit(self, start, goal, arm_names):
        request = GetMotionPlan.Request()
        settings = request.motion_plan_request
        settings.group_name = GROUP
        settings.start_state = start
        settings.num_planning_attempts = 1
        settings.allowed_planning_time = 4.0
        settings.max_velocity_scaling_factor = 0.25
        settings.max_acceleration_scaling_factor = 0.25
        settings.workspace_parameters.header.frame_id = FRAME
        settings.workspace_parameters.min_corner.x = settings.workspace_parameters.min_corner.y = -3.0
        settings.workspace_parameters.min_corner.z = -0.1
        settings.workspace_parameters.max_corner.x = settings.workspace_parameters.max_corner.y = 3.0
        settings.workspace_parameters.max_corner.z = 3.0
        values = joint_values(goal)
        constraints = Constraints()
        constraints.joint_constraints = [
            JointConstraint(joint_name=name, position=values[name], tolerance_above=0.0003,
                            tolerance_below=0.0003, weight=1.0)
            for name in arm_names
        ]
        settings.goal_constraints = [constraints]
        result = self.call(self.plan, request).motion_plan_response
        require_success(result.error_code, "transit")
        return result.trajectory

    def straight(self, start, goal, stage, *, max_step=0.003, avoid_collisions=True):
        request = GetCartesianPath.Request()
        request.header.frame_id = FRAME
        request.start_state = start
        request.group_name = GROUP
        request.link_name = TIP
        request.waypoints = [goal]
        request.max_step = max_step
        request.jump_threshold = 2.0
        request.avoid_collisions = avoid_collisions
        response = self.call(self.cart, request)
        require_success(response.error_code, stage)
        if response.fraction < 1.0 - 1e-6:
            raise ValueError(f"{stage}: Cartesian fraction {response.fraction:.4f}")
        return response.solution, response.fraction

    def fk_pose(self, state, label):
        request = GetPositionFK.Request()
        request.header.frame_id = FRAME
        request.fk_link_names = [TIP]
        request.robot_state = state
        result = self.call(self.fk, request)
        require_success(result.error_code, label)
        return result.pose_stamped[0].pose

    def validate_trajectory(self, trajectory, start, goal, stage, record_sample=None, *,
                            state_check=None, joint_step=0.02):
        names = list(trajectory.joint_trajectory.joint_names)
        points = trajectory.joint_trajectory.points
        if not points or set(names) != set(joint_values(start)) - {OPEN_JOINT, OPEN_MIMIC}:
            raise ValueError(f"{stage}: missing points or unexpected joints")
        start_values = joint_values(start)
        blade_position = start_values[OPEN_JOINT]
        previous = np.array([start_values[name] for name in names])
        sample_count = 0
        validate_state = self.valid_state if state_check is None else state_check
        for number, point in enumerate(points):
            values = np.asarray(point.positions)
            max_delta = float(np.max(np.abs(values - previous)))
            if (number == 0 and max_delta > 0.005) or (stage != "transit" and max_delta > 0.20):
                raise ValueError(f"{stage}: discontinuous joint positions ({max_delta:.4f} rad)")
            divisions = max(1, math.ceil(max_delta / joint_step))
            for step in range(1, divisions + 1):
                joints = previous + (values - previous) * step / divisions
                state = with_positions(start, dict(zip(names, joints.tolist())), blade_position=blade_position)
                validate_state(state, f"{stage} waypoint {number}:{step}")
                if record_sample is not None:
                    record_sample(stage, joint_values(state))
                sample_count += 1
            previous = values
        end = with_positions(start, dict(zip(names, previous.tolist())), blade_position=blade_position)
        actual = self.fk_pose(end, stage + " endpoint FK")
        delta = np.array([actual.position.x - goal.position.x, actual.position.y - goal.position.y,
                          actual.position.z - goal.position.z])
        pos_error = float(np.linalg.norm(delta))
        qa = Rotation.from_quat([actual.orientation.x, actual.orientation.y, actual.orientation.z, actual.orientation.w])
        qg = Rotation.from_quat([goal.orientation.x, goal.orientation.y, goal.orientation.z, goal.orientation.w])
        angle_error = math.degrees((qa.inv() * qg).magnitude())
        if pos_error > 0.002 or angle_error > 1.0:
            raise ValueError(f"{stage}: FK error {1000 * pos_error:.2f} mm / {angle_error:.2f} deg")
        duration = points[-1].time_from_start
        metrics = {"waypoints": len(points), "validity_samples": sample_count,
                   "position_error_mm": 1000 * pos_error, "orientation_error_deg": angle_error,
                   "trajectory_duration_s": duration.sec + duration.nanosec * 1e-9}
        return end, metrics


def replay(node, message, hold_at_cut, after_segment=None):
    if hold_at_cut:
        points = message.trajectory[1].joint_trajectory.points
        pause = copy.deepcopy(points[-1])
        duration_ns = Duration.from_msg(pause.time_from_start).nanoseconds
        pause.time_from_start = Duration(nanoseconds=duration_ns + round(hold_at_cut * 1e9)).to_msg()
        points.append(pause)
    qos = QoSProfile(depth=1, durability=DurabilityPolicy.VOLATILE)
    display = node.create_publisher(DisplayTrajectory, DISPLAY_TOPIC, qos)
    publisher = node.create_publisher(JointState, "/citrus/s01/joint_states", 10)
    deadline = time.monotonic() + 25
    while not publisher.get_subscription_count() and time.monotonic() < deadline:
        rclpy.spin_once(node, timeout_sec=0.2)
    if not publisher.get_subscription_count():
        raise RuntimeError("The isolated joint_state_publisher is not subscribed to replay")
    if display.get_subscription_count():
        display.publish(message)
        if not display.wait_for_all_acked(Duration(seconds=4)):
            raise RuntimeError("RViz did not acknowledge the trajectory message")
    joints = copy.deepcopy(message.trajectory_start.joint_state)
    joints.velocity = []
    joints.effort = []
    values = dict(zip(joints.name, joints.position))
    for index, segment in enumerate(message.trajectory):
        trajectory = segment.joint_trajectory
        points = trajectory.points
        times = np.array([Duration.from_msg(p.time_from_start).nanoseconds * 1e-9 for p in points])
        positions = np.asarray([p.positions for p in points])
        print(f"Replaying stage {index + 1}: {times[-1]:.2f} s", flush=True)
        start = time.monotonic()
        while True:
            elapsed = min(time.monotonic() - start, times[-1])
            values.update({name: float(np.interp(elapsed, times, positions[:, j]))
                           for j, name in enumerate(trajectory.joint_names)})
            joints.position = [values[name] for name in joints.name]
            joints.header.stamp = node.get_clock().now().to_msg()
            publisher.publish(joints)
            if elapsed >= times[-1]:
                break
            time.sleep(1 / 60)
        if after_segment is not None:
            after_segment(index)
    if not publisher.wait_for_all_acked(Duration(seconds=3)):
        raise RuntimeError("Final replay state was not acknowledged")
    count = len(message.trajectory)
    print(f"Completed the {'three' if count == 3 else count}-stage RViz joint-state replay.", flush=True)
