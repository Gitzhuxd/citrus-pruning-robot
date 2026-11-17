"""Exercise node control flow with message stand-ins; not an ROS/RViz runtime test."""
import copy
import importlib.util
import json
from pathlib import Path
import sys
import threading
import types
import unittest
from unittest.mock import patch

from citrus_pruning_sim.model import PruningState
from test_model import example

try:
    from geometry_msgs.msg import Point as RosPoint
    from visualization_msgs.msg import Marker as RosMarker
except ImportError:
    RosMarker = None


class Point(types.SimpleNamespace):
    def __init__(self, **kwargs):
        super().__init__(x=0., y=0., z=0.)
        self.__dict__.update(kwargs)


class Pose:
    def __init__(self):
        self.position = Point()
        self.orientation = types.SimpleNamespace(x=0., y=0., z=0., w=0.)


class Marker:
    ADD, DELETE = 0, 2
    TRIANGLE_LIST, SPHERE, TEXT_VIEW_FACING, ARROW, CYLINDER, POINTS = 11, 2, 9, 0, 3, 8

    def __init__(self):
        self.header = types.SimpleNamespace(frame_id='', stamp=None)
        self.pose, self.scale = Pose(), Point()
        self.points, self.colors = [], []


class MarkerArray:
    def __init__(self):
        self.markers = []


class PoseArray:
    def __init__(self):
        self.header = types.SimpleNamespace(frame_id='', stamp=None)
        self.poses = []


def load_node_with_standins():
    """Import the actual node methods without installing or impersonating ROS globally."""
    stubs = {
        'rclpy': {},
        'ament_index_python': {},
        'ament_index_python.packages': {'get_package_share_directory': lambda _: ''},
        'geometry_msgs': {},
        'geometry_msgs.msg': {'Point': Point, 'Pose': Pose, 'PoseArray': PoseArray},
        'rclpy.callback_groups': {'ReentrantCallbackGroup': object},
        'rclpy.executors': {'MultiThreadedExecutor': object},
        'rclpy.node': {'Node': object},
        'rclpy.qos': {'DurabilityPolicy': object, 'QoSProfile': object, 'ReliabilityPolicy': object},
        'std_msgs': {},
        'std_msgs.msg': {'ColorRGBA': types.SimpleNamespace, 'String': types.SimpleNamespace},
        'std_srvs': {},
        'std_srvs.srv': {'Trigger': types.SimpleNamespace(Response=types.SimpleNamespace)},
        'visualization_msgs': {},
        'visualization_msgs.msg': {'Marker': Marker, 'MarkerArray': MarkerArray},
    }
    modules = {}
    for name, attrs in stubs.items():
        module = types.ModuleType(name)
        module.__dict__.update(attrs)
        modules[name] = module
    path = Path(__file__).parents[1] / 'citrus_pruning_sim' / 'scene_node.py'
    spec = importlib.util.spec_from_file_location('citrus_pruning_sim._contract_test_node', path)
    module = importlib.util.module_from_spec(spec)
    with patch.dict(sys.modules, modules):
        spec.loader.exec_module(module)
    return module


NODE = load_node_with_standins()


class Publisher:
    def publish(self, msg):
        self.last = msg


def make_node(offset=0.0, reuse_marker_geometry=True):
    node = NODE.PruningScene.__new__(NODE.PruningScene)
    model = example()
    model['targets'][0]['axis'] = [.2, 0, .4]
    node.state = PruningState(model, s01_cut_offset_m=offset)
    node.frame, node.margin = 'tree_base', .003
    node._lock = threading.Lock()
    node._uncertain_future = None
    node._sync_state, node._last_message = 'disabled', ''
    node.moveit_enabled, node._scan = False, None
    node.reuse_marker_geometry = reuse_marker_geometry
    node.visual_pub, node.collision_pub, node.target_pub, node.state_pub = [Publisher() for _ in range(4)]
    node.get_clock = lambda: types.SimpleNamespace(now=lambda: types.SimpleNamespace(to_msg=lambda: None))
    node.timing_logs = []
    node.get_logger = lambda: types.SimpleNamespace(info=node.timing_logs.append)
    node._templates = node._make_visuals()
    node._collision_templates = node._make_collisions()
    return node


class SceneContractTests(unittest.TestCase):
    def test_cut_and_reset_preserve_published_snapshots_and_template_geometry(self):
        for reuse in (False, True):
            with self.subTest(reuse_marker_geometry=reuse):
                node = make_node(offset=.006, reuse_marker_geometry=reuse)
                geometry = [[(point.x, point.y, point.z) for point in marker.points]
                            for _, marker in node._templates]
                node._publish()
                before = node.visual_pub.last
                before_actions = [marker.action for marker in before.markers]
                node._command('S01', None, types.SimpleNamespace())
                cut = node.visual_pub.last
                cut_actions = [marker.action for marker in cut.markers]
                self.assertIn(Marker.DELETE, cut_actions)
                node._command('reset', None, types.SimpleNamespace())
                self.assertEqual([marker.action for marker in before.markers], before_actions)
                self.assertEqual([marker.action for marker in cut.markers], cut_actions)
                self.assertTrue(all(marker.action == Marker.ADD for _, marker in node._templates))
                self.assertEqual([[(point.x, point.y, point.z) for point in marker.points]
                                  for _, marker in node._templates], geometry)
                for (_, template), old, current in zip(node._templates, before.markers,
                                                       node.visual_pub.last.markers):
                    self.assertIsNot(old, template)
                    self.assertIsNot(old, current)
                    self.assertEqual(old.points is template.points, reuse)
                    self.assertEqual(old.colors is template.colors, reuse)

    def test_overlapping_publications_do_not_change_each_others_actions(self):
        node = make_node()
        entered, release = threading.Event(), threading.Event()
        messages = []
        def publish(message):
            messages.append(message)
            if len(messages) == 1:
                entered.set()
                if not release.wait(2.0):
                    raise RuntimeError('Test publication was not released')
        node.visual_pub.publish = publish
        worker = threading.Thread(target=node._publish)
        worker.start()
        try:
            self.assertTrue(entered.wait(2.0))
            node.state.commit(node.state.plan('S01'))
            node._publish()
        finally:
            release.set()
            worker.join(timeout=2.0)
        self.assertFalse(worker.is_alive())
        self.assertEqual(len(messages), 2)
        self.assertTrue(all(marker.action == Marker.ADD for marker in messages[0].markers))
        self.assertTrue(any(marker.action == Marker.DELETE for marker in messages[1].markers))
        self.assertTrue(all(marker.action == Marker.ADD for _, marker in node._templates))
        for old, current in zip(messages[0].markers, messages[1].markers):
            self.assertIsNot(old, current)
            self.assertIs(old.points, current.points)

    @unittest.skipIf(RosMarker is None, 'ROS message classes unavailable in this environment')
    def test_real_ros_marker_shallow_copy_owns_action_and_preserves_geometry(self):
        template = RosMarker()
        template.action = RosMarker.ADD
        template.points.append(RosPoint(x=1., y=2., z=3.))
        original = copy.deepcopy(template)
        first, second = copy.copy(template), copy.copy(template)
        first.action = RosMarker.DELETE
        self.assertEqual(template, original)
        self.assertEqual(second.action, RosMarker.ADD)
        self.assertIs(first.points, template.points)
        self.assertIs(second.points, template.points)
        self.assertIsNot(first, second)

    def test_command_timing_keeps_marker_templates_and_failed_commit_intact(self):
        node = make_node(offset=.006)
        original_actions = [marker.action for _, marker in node._templates]
        node._command('S01', None, types.SimpleNamespace())
        report = json.loads(node.timing_logs[-1].split('CITRUS_SCENE_TIMING ', 1)[1])
        self.assertTrue(report['success'])
        self.assertEqual(report['revision_after'], 1)
        self.assertGreaterEqual(report['total_s'], sum(report['phases_s'].values()))
        self.assertGreaterEqual(report['phases_s']['publish'], sum(report['publish'].values()))
        self.assertTrue(all(value >= 0 for value in report['publish'].values()))
        self.assertEqual([marker.action for _, marker in node._templates], original_actions)

        node.moveit_enabled, node._sync_state = True, 'synchronized'
        def reject(_desired):
            raise RuntimeError('Service rejected the scene')
        node._apply_world = reject
        node._command('reset', None, types.SimpleNamespace())
        report = json.loads(node.timing_logs[-1].split('CITRUS_SCENE_TIMING ', 1)[1])
        self.assertFalse(report['success'])
        self.assertIn('apply_world', report['phases_s'])
        self.assertEqual(report['revision_before'], report['revision_after'])
        self.assertEqual(node.state.cut_ids, frozenset({'S01'}))

    def test_cut_deletes_owned_markers_and_reset_restores_for_late_subscribers(self):
        node = make_node()
        node._command('S01', None, types.SimpleNamespace())
        self.assertEqual(len(node.target_pub.last.poses), 0)
        for publisher, templates in ((node.visual_pub, node._templates),
                                     (node.collision_pub, node._collision_templates)):
            actions = {(m.ns, m.id): m.action for m in publisher.last.markers}
            for group, template in templates:
                self.assertEqual(actions[template.ns, template.id],
                                 Marker.DELETE if group == 'S01' else Marker.ADD)
        node._publish()  # A subsequent full snapshot retains the delete actions.
        self.assertTrue(any(m.action == Marker.DELETE for m in node.visual_pub.last.markers))
        node._command('reset', None, types.SimpleNamespace())
        self.assertTrue(all(m.action == Marker.ADD for m in node.visual_pub.last.markers))
        self.assertEqual(len(node.target_pub.last.poses), 1)

    def test_failed_moveit_update_cannot_commit_visual_cut(self):
        node = make_node()
        node.moveit_enabled, node._sync_state = True, 'synchronized'
        def reject(_desired):
            raise RuntimeError('Service rejected the scene')
        node._apply_world = reject
        response = node._command('S01', None, types.SimpleNamespace())
        self.assertFalse(response.success)
        self.assertEqual(node.state.cut_ids, frozenset())
        self.assertEqual(node.state.revision, 0)
        self.assertEqual(len(node.target_pub.last.poses), 1)

    def test_moveit_confirmation_precedes_commit(self):
        node = make_node()
        node.moveit_enabled, node._sync_state = True, 'synchronized'
        confirmations = []
        def confirm(desired):
            self.assertEqual(node.state.cut_ids, frozenset())
            confirmations.append(desired)
        node._apply_world = confirm
        response = node._command('S01', None, types.SimpleNamespace())
        self.assertTrue(response.success)
        self.assertEqual(confirmations, [frozenset({'S01'})])
        self.assertEqual(node.state.cut_ids, frozenset({'S01'}))
        self.assertEqual(json.loads(node.state_pub.last.data)['cut_ids'], ['S01'])

    def test_unsynchronized_or_pending_scene_blocks_new_cuts(self):
        node = make_node()
        node.moveit_enabled, node._sync_state = True, 'unknown'
        response = node._command('S01', None, types.SimpleNamespace())
        self.assertFalse(response.success)
        node._uncertain_future = types.SimpleNamespace(done=lambda: False)
        response = node._command('resync_moveit', None, types.SimpleNamespace())
        self.assertFalse(response.success)
        self.assertEqual(node.state.cut_ids, frozenset())

    def test_partial_cut_diffs_never_remove_an_absent_object(self):
        node = make_node(offset=.006)
        node.moveit_enabled, node._sync_state, node.timeout = True, 'not_synchronized', 1.0
        objects = {'fixture'}

        class CollisionObject:
            ADD, REMOVE = 0, 1

            def __init__(self):
                self.header = types.SimpleNamespace(frame_id='')
                self.primitives, self.primitive_poses = [], []

        class SolidPrimitive(types.SimpleNamespace):
            CYLINDER = 3

        def apply_request():
            world = types.SimpleNamespace(collision_objects=[])
            state = types.SimpleNamespace(is_diff=False)
            return types.SimpleNamespace(scene=types.SimpleNamespace(world=world, robot_state=state))

        def apply(request):
            for item in request.scene.world.collision_objects:
                if item.operation == CollisionObject.REMOVE:
                    objects.remove(item.id)
                else:
                    objects.add(item.id)
            return types.SimpleNamespace(success=True)

        node.CollisionObject = CollisionObject
        node.SolidPrimitive = SolidPrimitive
        node.ApplyPlanningScene = types.SimpleNamespace(Request=apply_request)
        node.client = types.SimpleNamespace(
            wait_for_service=lambda **_: True,
            call_async=lambda request: types.SimpleNamespace(result=lambda: apply(request)))
        node._world_ids = lambda: objects.copy()
        node._wait_for_moveit = lambda _: True
        for command, stump in (('resync_moveit', False), ('S01', True), ('S01', True),
                               ('reset', False), ('reset', False)):
            response = node._command(command, None, types.SimpleNamespace())
            self.assertTrue(response.success, response.message)
            self.assertEqual(objects, {'fixture', 'citrus_static', 'citrus_S01_stump' if stump else 'citrus_S01'})
            summary = json.loads(node.state_pub.last.data)
            self.assertEqual(summary['s01_stump_present'], stump)
            self.assertEqual(summary['partial_cut_target'], 'S01')
            self.assertEqual(summary['cut_offset_m'], summary['s01_cut_offset_m'])
            self.assertEqual(summary['stump_present'], stump)


if __name__ == '__main__':
    unittest.main()
