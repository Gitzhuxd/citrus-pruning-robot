"""不依赖 ROS 的核心测试，可由 pytest 或 unittest 执行。"""

import unittest
from unittest.mock import patch

import numpy as np

import aubo_rrt_python.rrt_core as core
from aubo_rrt_python.rrt_core import RRTPlanner, interpolate_edge


class TestRRTCore(unittest.TestCase):
    def test_interpolation_contains_endpoints_and_respects_resolution(self):
        a = np.array([-0.27, 0.5])
        b = np.array([0.38, -0.8])
        points = interpolate_edge(a, b, 0.07)
        np.testing.assert_array_equal(points[0], a)
        np.testing.assert_array_equal(points[-1], b)
        self.assertLessEqual(
            np.max(np.abs(np.diff(points, axis=0))), 0.07 + 1e-12)

    def test_success_has_correct_parents_and_exact_goal(self):
        notifications = []
        planner = RRTPlanner(
            [-1, -1], [2, 2], lambda q: True,
            step_size=0.3, goal_bias=1.0,
            on_node=lambda index, q, parent: notifications.append((index, parent)),
        )
        path = planner.plan([0, 0], [0.8, 0.4])
        self.assertEqual(planner.outcome, 'success')
        self.assertEqual(planner.parents[0], -1)
        self.assertEqual(path[0], 0)
        np.testing.assert_array_equal(planner.nodes[path[-1]], [0.8, 0.4])
        for parent, child in zip(path, path[1:]):
            self.assertEqual(planner.parents[child], parent)
            self.assertLessEqual(
                np.linalg.norm(planner.nodes[child] - planner.nodes[parent]),
                0.3 + 1e-12,
            )
        self.assertEqual(notifications, list(enumerate(planner.parents)))

    def test_internal_obstacle_rejected_with_valid_endpoints(self):
        checked = []

        def valid(q):
            checked.append(q[0])
            return not 0.45 <= q[0] <= 0.55

        planner = RRTPlanner(
            [0], [1], valid, step_size=2.0, goal_bias=1.0,
            collision_step=0.05, max_iterations=3,
        )
        self.assertIsNone(planner.plan([0], [1]))
        self.assertEqual(planner.outcome, 'max_iterations')
        self.assertEqual(planner.rejected_edges, 3)
        self.assertEqual(len(planner.nodes), 1)
        self.assertTrue(any(0.45 <= value <= 0.55 for value in checked))

    def test_final_short_connection_is_checked(self):
        planner = RRTPlanner(
            [0], [1], lambda q: not 0.75 <= q[0] <= 0.85,
            step_size=0.6, goal_bias=1.0, collision_step=0.05,
            max_iterations=1,
        )
        self.assertIsNone(planner.plan([0], [1]))
        self.assertEqual(len(planner.nodes), 2)
        self.assertEqual(planner.rejected_edges, 1)
        self.assertEqual(planner.outcome, 'max_iterations')
        np.testing.assert_allclose(planner.nodes[-1], [0.6])

    def test_invalid_endpoint_does_not_reach_collision_service(self):
        for bad in ([float('nan')], [float('inf')], [1.1], [-0.1], [0, 0]):
            with self.subTest(endpoint=bad):
                checked = []
                planner = RRTPlanner(
                    [0], [1], lambda q: checked.append(q.copy()) or True)
                with self.assertRaises(ValueError):
                    planner.plan(bad, [1])
                self.assertEqual(checked, [])
                self.assertEqual(planner.outcome, 'invalid_start')

    def test_collision_invalid_goal_raises(self):
        planner = RRTPlanner([0], [1], lambda q: q[0] < 0.9)
        with self.assertRaisesRegex(ValueError, 'goal'):
            planner.plan([0], [1])
        self.assertEqual(planner.outcome, 'invalid_goal')

    def test_equal_start_goal_has_one_node(self):
        planner = RRTPlanner([-1], [1], lambda q: True)
        self.assertEqual(planner.plan([0.2], [0.2]), [0])
        self.assertEqual(planner.parents, [-1])
        self.assertEqual(planner.iterations, 0)

    def test_seed_reproduces_tree_and_repeat_plan_resets(self):
        planner = RRTPlanner(
            [-1, -1], [1, 1], lambda q: True,
            seed=27, goal_bias=0.2, max_iterations=500,
        )
        first_path = planner.plan([-0.8, -0.8], [0.8, 0.8])
        first_nodes = np.array(planner.nodes)
        first_parents = list(planner.parents)
        first_checks = planner.collision_checks
        second_path = planner.plan([-0.8, -0.8], [0.8, 0.8])
        self.assertIsNotNone(first_path)
        self.assertEqual(first_path, second_path)
        np.testing.assert_array_equal(first_nodes, planner.nodes)
        self.assertEqual(first_parents, planner.parents)
        self.assertEqual(first_checks, planner.collision_checks)

    def test_time_budget_checked_inside_edge(self):
        clock = [0.0]

        def valid(q):
            clock[0] += 0.3
            return True

        planner = RRTPlanner(
            [0], [1], valid, step_size=2.0, goal_bias=1.0,
            collision_step=0.05, max_seconds=1.0,
        )
        with patch.object(core.time, 'perf_counter', lambda: clock[0]):
            self.assertIsNone(planner.plan([0], [1]))
        self.assertEqual(planner.outcome, 'timeout')
        self.assertEqual(planner.collision_checks, 4)
        self.assertEqual(len(planner.nodes), 1)
        self.assertAlmostEqual(planner.elapsed_seconds, 1.2)
        self.assertEqual(planner.rejected_edges, 0)

    def test_visualization_callback_counts_toward_budget(self):
        clock = [0.0]

        def on_node(index, q, parent):
            clock[0] += 2.0

        planner = RRTPlanner(
            [0], [1], lambda q: True, max_seconds=1.0, on_node=on_node,
        )
        with patch.object(core.time, 'perf_counter', lambda: clock[0]):
            self.assertIsNone(planner.plan([0], [1]))
        self.assertEqual(planner.outcome, 'timeout')
        self.assertEqual(planner.iterations, 0)

    def test_service_exception_propagates_without_counting_collision(self):
        def valid(q):
            raise RuntimeError('service timeout')

        planner = RRTPlanner([0], [1], valid)
        with self.assertRaisesRegex(RuntimeError, 'service timeout'):
            planner.plan([0], [1])
        self.assertEqual(planner.outcome, 'error')
        self.assertEqual(planner.rejected_edges, 0)


if __name__ == '__main__':
    unittest.main()
