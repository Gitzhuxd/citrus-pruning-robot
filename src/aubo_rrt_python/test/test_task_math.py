"""Panel pose/parameter and cancellation tests, without ROS or a robot."""

import math
import unittest

import numpy as np

from aubo_rrt_python.rrt_core import PlanningCancelled, RRTPlanner
from aubo_rrt_python.task_math import (
    DEFAULTS, pose_error, rotation_matrix, validate_pose_values, validate_settings,
)


class TestTaskMath(unittest.TestCase):
    def test_roll_pitch_yaw_90_degree_tool_to_world_rotations(self):
        half_sqrt_two = math.sqrt(0.5)
        cases = [
            ('roll', [half_sqrt_two, 0, 0, half_sqrt_two],
             [[1, 0, 0], [0, 0, -1], [0, 1, 0]]),
            ('pitch', [0, half_sqrt_two, 0, half_sqrt_two],
             [[0, 0, 1], [0, 1, 0], [-1, 0, 0]]),
            ('yaw', [0, 0, half_sqrt_two, half_sqrt_two],
             [[0, -1, 0], [1, 0, 0], [0, 0, 1]]),
        ]
        for name, quaternion, expected in cases:
            with self.subTest(axis=name):
                np.testing.assert_allclose(
                    rotation_matrix(quaternion), expected, rtol=0, atol=1e-14)

    def test_combined_rpy_means_rz_ry_rx(self):
        # Roll=90, pitch=90, yaw=0: q = q_y * q_x in xyzw order.
        # Tool x points towards world -z; tool y points towards world +x.
        quaternion = [0.5, 0.5, -0.5, 0.5]
        expected = [[0, 1, 0], [0, 0, -1], [-1, 0, 0]]
        np.testing.assert_allclose(
            rotation_matrix(quaternion), expected, rtol=0, atol=1e-14)

    def test_quaternion_sign_does_not_change_pose(self):
        quaternion = np.array([0.5, -0.5, 0.5, 0.5])
        position_error, angle_error = pose_error(
            [0.2, -0.1, 0.7], quaternion,
            [0.2, -0.1, 0.7], -quaternion)
        self.assertEqual(position_error, 0.0)
        self.assertAlmostEqual(angle_error, 0.0)
        np.testing.assert_allclose(
            rotation_matrix(quaternion), rotation_matrix(-quaternion))

    def test_pose_error_has_meter_and_radian_semantics(self):
        position_error, angle_error = pose_error(
            [0, 0, 0], [0, 0, 0, 1],
            [0.3, 0.4, 0], [0, 0, math.sqrt(0.5), math.sqrt(0.5)])
        self.assertAlmostEqual(position_error, 0.5)
        self.assertAlmostEqual(angle_error, math.pi / 2)

    def test_pose_rejects_invalid_dimensions_and_nonfinite_values(self):
        bad_positions = ([1, 2], [[1, 2, 3]], [0, math.nan, 1],
                         [0, 0, math.inf], [])
        for position in bad_positions:
            with self.subTest(position=position), self.assertRaises(ValueError):
                validate_pose_values(position, [0, 0, 0, 1])
        bad_quaternions = ([0, 0, 1], [[0, 0, 0, 1]], [0, 0, 0, 0],
                           [0, 0, 0, 2], [0, 0, math.nan, 1],
                           [0, 0, 0, math.inf], [])
        for quaternion in bad_quaternions:
            with self.subTest(quaternion=quaternion), self.assertRaises(ValueError):
                validate_pose_values([0, 0, 0], quaternion)

    def test_pose_only_normalizes_small_rounding_error(self):
        _, quaternion = validate_pose_values([0, 0, 0], [0, 0, 0, 1.0005])
        np.testing.assert_array_equal(quaternion, [0, 0, 0, 1])
        with self.assertRaises(ValueError):
            validate_pose_values([0, 0, 0], [0, 0, 0, 1.01])

    def test_default_settings_pass_without_modifying_input(self):
        supplied = DEFAULTS.copy()
        result = validate_settings(supplied)
        self.assertEqual(result, DEFAULTS)
        self.assertEqual(supplied, DEFAULTS)
        self.assertIsNot(result, supplied)

    def test_settings_reject_nonfinite_floating_parameters(self):
        for name in ('step_size', 'goal_bias', 'collision_step',
                     'planning_time', 'replay_step'):
            for value in (math.nan, math.inf, -math.inf):
                with self.subTest(parameter=name, value=value):
                    with self.assertRaises(ValueError):
                        validate_settings({**DEFAULTS, name: value})

    def test_settings_reject_invalid_ranges_and_integer_types(self):
        cases = {
            'step_size': (0.0, -0.1, 6.4),
            'goal_bias': (-0.01, 1.01),
            'collision_step': (0.0, 0.21),
            'planning_time': (0.0, 601.0),
            'replay_step': (-0.1, 2.1),
            'max_iterations': (0, -1, 100001, 2.5, True),
            'seed': (-1, 2147483648, 1.5, False),
        }
        for name, values in cases.items():
            for value in values:
                with self.subTest(parameter=name, value=value):
                    with self.assertRaises(ValueError):
                        validate_settings({**DEFAULTS, name: value})

    def test_settings_accept_zero_bias_and_immediate_replay(self):
        result = validate_settings({
            **DEFAULTS, 'goal_bias': 0.0, 'replay_step': 0.0, 'seed': 0,
        })
        self.assertEqual(result['goal_bias'], 0.0)
        self.assertEqual(result['replay_step'], 0.0)
        self.assertEqual(result['seed'], 0)


class TestPlanningCancellation(unittest.TestCase):
    def test_cancel_check_stops_before_any_collision_rpc(self):
        checked = []
        cancellation = PlanningCancelled('test cancel before planning')

        def cancel_check():
            raise cancellation

        planner = RRTPlanner(
            [-1], [1], lambda q: checked.append(q) or True,
            cancel_check=cancel_check)
        with self.assertRaises(PlanningCancelled) as context:
            planner.plan([0], [0.8])
        self.assertIs(context.exception, cancellation)
        self.assertEqual(planner.outcome, 'cancelled')
        self.assertEqual(checked, [])
        self.assertEqual(planner.nodes, [])

    def test_cancellation_from_collision_rpc_is_not_a_collision(self):
        checked = []
        cancellation = PlanningCancelled('cancel while checking an edge')

        def valid(q):
            checked.append(q.copy())
            if len(checked) == 4:
                raise cancellation
            return True

        planner = RRTPlanner(
            [-1], [1], valid, step_size=0.3, goal_bias=1.0,
            collision_step=0.04)
        with self.assertRaises(PlanningCancelled) as context:
            planner.plan([0], [0.8])
        self.assertIs(context.exception, cancellation)
        self.assertEqual(planner.outcome, 'cancelled')
        self.assertEqual(planner.rejected_edges, 0)
        self.assertEqual(len(checked), 4)
        self.assertEqual(len(planner.nodes), 1)

    def test_cancel_during_visualization_propagates_and_allows_next_plan(self):
        cancellation = PlanningCancelled('cancel in node callback')

        def on_node(index, q, parent):
            if index == 1:
                raise cancellation

        planner = RRTPlanner(
            [-1], [1], lambda q: True,
            step_size=0.3, goal_bias=1.0, on_node=on_node)
        with self.assertRaises(PlanningCancelled) as context:
            planner.plan([0], [0.8])
        self.assertIs(context.exception, cancellation)
        self.assertEqual(planner.outcome, 'cancelled')
        planner.on_node = None
        path = planner.plan([0], [0.8])
        self.assertEqual(planner.outcome, 'success')
        self.assertEqual(path[0], 0)
        np.testing.assert_array_equal(planner.nodes[path[-1]], [0.8])


if __name__ == '__main__':
    unittest.main()
