"""Display a citrus tree and apply reversible cuts; no fracture physics is simulated."""
import copy
import json
import math
import threading
import time
from contextlib import contextmanager
from functools import partial
from pathlib import Path

import rclpy
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import Point, Pose, PoseArray
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import ColorRGBA, String
from std_srvs.srv import Trigger
from visualization_msgs.msg import Marker, MarkerArray

from .model import S01_STUMP, PruningState, branch_triangles, load_model, quaternion_z_to


@contextmanager
def timed_phase(timings, name):
    started = time.monotonic()
    try:
        yield
    finally:
        timings[name] = time.monotonic() - started


def point(xyz):
    return Point(x=float(xyz[0]), y=float(xyz[1]), z=float(xyz[2]))


def color(rgba):
    return ColorRGBA(r=float(rgba[0]), g=float(rgba[1]), b=float(rgba[2]), a=float(rgba[3]))


def pose(center, quat):
    result = Pose()
    result.position = point(center)
    result.orientation.x, result.orientation.y, result.orientation.z, result.orientation.w = quat
    return result


class PruningScene(Node):
    def __init__(self):
        super().__init__('citrus_pruning_scene')
        share = Path(get_package_share_directory('citrus_pruning_sim'))
        self.declare_parameter('model_path', str(share / 'data' / 'tree_model.json'))
        self.declare_parameter('publish_moveit', False)
        self.declare_parameter('show_scan', False)
        self.declare_parameter('reuse_marker_geometry', True)
        self.declare_parameter('collision_margin', 0.003)
        self.declare_parameter('s01_cut_offset_m', 0.0)
        self.declare_parameter('partial_cut_target', 'S01')
        self.declare_parameter('moveit_service', '/apply_planning_scene')
        self.declare_parameter('moveit_timeout', 10.0)
        self.state = PruningState(load_model(self.get_parameter('model_path').value),
                                  self.get_parameter('s01_cut_offset_m').value,
                                  partial_cut_target=self.get_parameter('partial_cut_target').value)
        self.frame = self.state.model['frame_id']
        self.margin = float(self.get_parameter('collision_margin').value)
        self.timeout = float(self.get_parameter('moveit_timeout').value)
        self.state.collision_snapshot(self.margin)  # Validate before creating the ROS interface.
        if not math.isfinite(self.timeout) or self.timeout <= 0:
            raise ValueError('moveit_timeout must be finite and positive')
        self.moveit_enabled = self.get_parameter('publish_moveit').value
        self.show_scan = self.get_parameter('show_scan').value
        self.reuse_marker_geometry = self.get_parameter('reuse_marker_geometry').value
        self._lock = threading.Lock()
        self._uncertain_future = None
        self._sync_state = 'not_synchronized' if self.moveit_enabled else 'disabled'
        self._last_message = 'Ready; leaves are visual only.'
        self.callbacks = ReentrantCallbackGroup()
        qos = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE,
                         durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.visual_pub = self.create_publisher(MarkerArray, '/citrus/markers', qos)
        self.collision_pub = self.create_publisher(MarkerArray, '/citrus/collision', qos)
        self.target_pub = self.create_publisher(PoseArray, '/citrus/cut_targets', qos)
        self.state_pub = self.create_publisher(String, '/citrus/state', qos)
        self._templates = self._make_visuals()
        self._collision_templates = self._make_collisions()
        self._scan = None
        if self.show_scan:
            self.scan_pub = self.create_publisher(Marker, '/citrus/reference', qos)
            scan_path = Path(self.get_parameter('model_path').value).parent / 'scan_reference.json'
            data = json.loads(scan_path.read_text(encoding='utf-8'))
            if data.get('units') != 'm' or data.get('frame_id') != self.frame:
                raise ValueError('Scan reference must use meters in tree_base')
            self._scan = self._marker('citrus_scan_centers_reference', 0, Marker.POINTS)
            self._scan.scale.x = self._scan.scale.y = 0.007
            for row in data['points']:
                if (len(row) != 6 or not all(math.isfinite(v) for v in row)
                        or not all(0 <= v <= 1 for v in row[3:])):
                    raise ValueError('Invalid scan reference row')
                self._scan.points.append(point(row[:3]))
                self._scan.colors.append(color([*row[3:], 1.0]))
        self._services = []
        for target_id in self.state.target_ids:
            self._services.append(self.create_service(
                Trigger, '/citrus/cut/' + target_id, partial(self._command, target_id),
                callback_group=self.callbacks))
        for command in ('cut_all', 'reset', 'resync_moveit'):
            self._services.append(self.create_service(
                Trigger, '/citrus/' + command, partial(self._command, command),
                callback_group=self.callbacks))
        if self.moveit_enabled:
            try:
                from moveit_msgs.msg import CollisionObject, PlanningSceneComponents
                from moveit_msgs.srv import ApplyPlanningScene, GetPlanningScene
                from shape_msgs.msg import SolidPrimitive
            except ImportError as exc:
                raise RuntimeError('Install ros-humble-moveit-msgs for publish_moveit:=true') from exc
            self.CollisionObject, self.ApplyPlanningScene = CollisionObject, ApplyPlanningScene
            self.PlanningSceneComponents, self.GetPlanningScene = PlanningSceneComponents, GetPlanningScene
            self.SolidPrimitive = SolidPrimitive
            apply_service = self.get_parameter('moveit_service').value
            namespace, separator, _ = apply_service.rpartition('/')
            self.client = self.create_client(ApplyPlanningScene, apply_service, callback_group=self.callbacks)
            self.world_client = self.create_client(GetPlanningScene, namespace + separator + 'get_planning_scene',
                                                   callback_group=self.callbacks)
            self.startup_timer = self.create_timer(0.5, self._initial_sync)
        self.create_timer(1.0, self._publish)
        self._publish()
        self.get_logger().info('Citrus scene ready: ' + ', '.join(self.state.target_ids)
                               + '; fixed frame world, leaves excluded from collision.')

    def _marker(self, namespace, marker_id, kind):
        marker = Marker()
        marker.header.frame_id = self.frame
        marker.ns, marker.id, marker.type = namespace, marker_id, kind
        marker.action = Marker.ADD
        marker.pose.orientation.w = 1.0
        marker.scale.x = marker.scale.y = marker.scale.z = 1.0
        marker.color = color([1, 1, 1, 1])
        marker.frame_locked = True
        return marker

    def _make_visuals(self):
        templates = []
        for gi, group in enumerate(('static', *self.state.target_ids)):
            for category in ('segments', 'leaves'):
                marker = self._marker('citrus_' + category, gi, Marker.TRIANGLE_LIST)
                for item in self.state.model[category]:
                    if item['group'] != group:
                        continue
                    points = branch_triangles(item) if category == 'segments' else [
                        item['vertices'][i] for face in item['triangles'] for i in face]
                    marker.points.extend(point(p) for p in points)
                    marker.colors.extend(color(item['color']) for _ in points)
                if marker.points:
                    templates.append((group, marker))
        if self.state.stump is not None:
            stump = self.state.stump
            marker = self._marker('citrus_stumps', 0, Marker.TRIANGLE_LIST)
            marker.points = [point(p) for p in branch_triangles(stump)]
            marker.color = color(stump['color'])
            templates.append((self.state.stump_group, marker))
        for i, target in enumerate(self.state.targets):
            group = target['id']
            marker = self._marker('citrus_cut_points', i, Marker.SPHERE)
            marker.pose.position = point(target['position'])
            marker.scale.x = marker.scale.y = marker.scale.z = 0.023
            marker.color = color([1.0, 0.23, 0.035, 1])
            templates.append((group, marker))
            label = self._marker('citrus_labels', i, Marker.TEXT_VIEW_FACING)
            label.pose.position = point([target['position'][0], target['position'][1],
                                         target['position'][2] + 0.047])
            label.scale.z, label.text = 0.035, group
            label.color = color([0.12, 0.12, 0.12, 1])
            templates.append((group, label))
            arrow = self._marker('citrus_approach', i, Marker.ARROW)
            arrow.points = [point(target['precut_position']), point(target['position'])]
            arrow.scale.x, arrow.scale.y, arrow.scale.z = 0.004, 0.012, 0.025
            arrow.color = color([0.0, 0.48, 0.85, 1])
            templates.append((group, arrow))
        return templates

    def _make_collisions(self):
        templates = []
        for snapshot in self.state.collision_snapshot(self.margin):
            geometries = snapshot['cylinders']
            if snapshot['group'] == self.state.stump_group:
                geometries = [self.state.stump_cylinder(self.margin)]
            for i, geometry in enumerate(geometries):
                marker = self._marker(snapshot['id'] + '_collision', i, Marker.CYLINDER)
                marker.pose = pose(geometry['center'], geometry['quaternion_xyzw'])
                marker.scale.x = marker.scale.y = 2.0 * geometry['radius']
                marker.scale.z = geometry['height']
                marker.color = color([0.1, 0.55, 0.95, 0.35])
                templates.append((snapshot['group'], marker))
        return templates

    def _publish(self):
        timings = {}
        cut_ids = self.state.cut_ids  # An immutable snapshot shared with service callbacks.
        copy_marker = copy.copy if self.reuse_marker_geometry else copy.deepcopy
        for name, publisher, templates in (('visual', self.visual_pub, self._templates),
                                           ('collision', self.collision_pub, self._collision_templates)):
            with timed_phase(timings, name + '_copy_s'):
                message = MarkerArray()
                for group, template in templates:
                    # Templates and their nested geometry remain read-only after construction.
                    # Each publication owns its action field, including overlapping callbacks.
                    marker = copy_marker(template)
                    marker.action = Marker.ADD if self.state.visible(group, cut_ids) else Marker.DELETE
                    message.markers.append(marker)
            with timed_phase(timings, name + '_publish_s'):
                publisher.publish(message)
        started = time.monotonic()
        poses = PoseArray()
        poses.header.frame_id = self.frame
        poses.header.stamp = self.get_clock().now().to_msg()
        active_ids = []
        for target in self.state.targets:
            if target['id'] not in cut_ids:
                active_ids.append(target['id'])
                # Pose +Z points along candidate approach; this is not a robot IK solution.
                poses.poses.append(pose(target['position'], quaternion_z_to(target['approach'])))
        self.target_pub.publish(poses)
        summary = {'revision': self.state.revision, 'cut_ids': sorted(cut_ids),
                   'active_target_ids': active_ids, 'frame_id': self.frame,
                   'moveit_sync': self._sync_state, 'message': self._last_message,
                   's01_cut_offset_m': self.state.s01_cut_offset_m,
                   's01_stump_present': self.state.visible(S01_STUMP, cut_ids),
                   'partial_cut_target': self.state.partial_cut_target,
                   'cut_offset_m': self.state.cut_offset_m,
                   'stump_present': self.state.visible(self.state.stump_group, cut_ids),
                   'leaves_in_collision': False, 'fracture_physics': False,
                   'ik_verified': False, 'scan_reference_is_gaussian_render': False}
        self.state_pub.publish(String(data=json.dumps(summary)))
        if self._scan is not None:
            self.scan_pub.publish(self._scan)
        timings['targets_state_scan_s'] = time.monotonic() - started
        return timings

    def _initial_sync(self):
        self.startup_timer.cancel()
        response = self._command('resync_moveit', None, Trigger.Response())
        if not response.success:
            self.get_logger().error(response.message)

    def _command(self, command, _request, response):
        started = time.monotonic()
        if not self._lock.acquire(blocking=False):
            response.success, response.message = False, 'Another scene update is in progress.'
            return response
        timings = {}
        detail = {'command': command, 'revision_before': self.state.revision, 'phases_s': timings,
                  'reuse_marker_geometry': self.reuse_marker_geometry}
        try:
            if self._uncertain_future is not None and not self._uncertain_future.done():
                raise RuntimeError('Previous MoveIt request still pending; outcome unknown. '
                                   'Wait for its response before /citrus/resync_moveit.')
            if self.moveit_enabled and command != 'resync_moveit' and self._sync_state != 'synchronized':
                raise RuntimeError('MoveIt is not synchronized; call /citrus/resync_moveit first.')
            with timed_phase(timings, 'plan'):
                desired = self.state.cut_ids if command == 'resync_moveit' else self.state.plan(command)
            if self.moveit_enabled:
                with timed_phase(timings, 'apply_world'):
                    detail['moveit'] = self._apply_world(desired)
            with timed_phase(timings, 'commit'):
                self.state.commit(desired)
            self._last_message = command + ' completed; simulated shoot geometry updated.'
            response.success, response.message = True, self._last_message
        except (RuntimeError, ValueError) as exc:
            response.success, response.message = False, str(exc)
            self._last_message = response.message
        finally:
            self._lock.release()
        with timed_phase(timings, 'publish'):
            detail['publish'] = self._publish()
        detail.update(success=response.success, revision_after=self.state.revision,
                      total_s=time.monotonic() - started)
        self.get_logger().info('CITRUS_SCENE_TIMING ' + json.dumps(detail, sort_keys=True))
        return response

    def _wait_for_moveit(self, future):
        # A reentrant client and a 4-thread executor keep replies flowing during this bounded wait.
        completed = threading.Event()
        future.add_done_callback(lambda _: completed.set())
        return completed.wait(self.timeout)

    def _world_ids(self):
        try:
            if not self.world_client.wait_for_service(timeout_sec=min(2.0, self.timeout)):
                raise RuntimeError('MoveIt scene query service unavailable.')
            request = self.GetPlanningScene.Request()
            request.components.components = self.PlanningSceneComponents.WORLD_OBJECT_NAMES
            future = self.world_client.call_async(request)
            if not self._wait_for_moveit(future):
                raise RuntimeError('MoveIt scene query timed out.')
            return {item.id for item in future.result().scene.world.collision_objects}
        except Exception as exc:
            self._sync_state = 'not_synchronized'
            raise RuntimeError('Could not read MoveIt object names. Resync required.') from exc

    def _apply_world(self, desired):
        timings = {}
        with timed_phase(timings, 'service_ready_s'):
            if not self.client.wait_for_service(timeout_sec=min(2.0, self.timeout)):
                self._sync_state = 'not_synchronized'
                raise RuntimeError('MoveIt service unavailable; start move_group, then /citrus/resync_moveit.')
        request = self.ApplyPlanningScene.Request()
        request.scene.is_diff = True
        request.scene.robot_state.is_diff = True
        with timed_phase(timings, 'snapshot_s'):
            snapshot = self.state.collision_snapshot(self.margin, desired)
        # Humble rejects REMOVE of a missing object, including after a repeated cut or reset.
        with timed_phase(timings, 'query_existing_s'):
            existing = self._world_ids() if any(item['operation'] == 'REMOVE' for item in snapshot) else set()
        with timed_phase(timings, 'message_build_s'):
            for item in snapshot:
                if item['operation'] == 'REMOVE' and item['id'] not in existing:
                    continue
                obstacle = self.CollisionObject()
                obstacle.header.frame_id, obstacle.id = self.frame, item['id']
                if hasattr(obstacle, 'pose'):
                    obstacle.pose.orientation.w = 1.0
                obstacle.operation = getattr(self.CollisionObject, item['operation'])
                for geometry in item['cylinders']:
                    primitive = self.SolidPrimitive()
                    primitive.type = self.SolidPrimitive.CYLINDER
                    primitive.dimensions = [geometry['height'], geometry['radius']]
                    obstacle.primitives.append(primitive)
                    obstacle.primitive_poses.append(pose(geometry['center'], geometry['quaternion_xyzw']))
                request.scene.world.collision_objects.append(obstacle)
        with timed_phase(timings, 'apply_wait_s'):
            future = self.client.call_async(request)
            if not self._wait_for_moveit(future):
                self._uncertain_future = future
                self._sync_state = 'unknown'
                raise RuntimeError('MoveIt response timed out: server outcome unknown; local cut not committed. '
                                   'After the pending request finishes, call /citrus/resync_moveit.')
        try:
            result = future.result()
        except Exception as exc:
            self._sync_state = 'not_synchronized'
            raise RuntimeError('MoveIt service failed; local state unchanged. Resync required.') from exc
        if result is None or not result.success:
            self._sync_state = 'not_synchronized'
            raise RuntimeError('MoveIt rejected scene; local state unchanged. Check TF and resync.')
        self._sync_state, self._uncertain_future = 'synchronized', None
        return {'phases_s': timings, 'objects_sent': len(request.scene.world.collision_objects),
                'primitives_sent': sum(len(item.primitives) for item in request.scene.world.collision_objects)}


def main(args=None):
    rclpy.init(args=args)
    node = None
    executor = MultiThreadedExecutor(num_threads=4)
    try:
        node = PruningScene()
        executor.add_node(node)
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
