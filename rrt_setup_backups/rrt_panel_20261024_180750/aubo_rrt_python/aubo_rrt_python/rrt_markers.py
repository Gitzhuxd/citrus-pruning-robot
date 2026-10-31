"""把关节空间 RRT 的末端投影作为完整快照发布到 RViz。"""

from geometry_msgs.msg import Point
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from std_msgs.msg import ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray


def _point(xyz):
    return Point(x=float(xyz[0]), y=float(xyz[1]), z=float(xyz[2]))


def _color(r, g, b, a=1.0):
    return ColorRGBA(r=float(r), g=float(g), b=float(b), a=float(a))


class RRTMarkers:
    """保留全部节点和边，让后打开的 RViz 也能收到完整探索树。"""

    def __init__(self, node, frame='world'):
        self.node = node
        self.frame = frame
        qos = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
        )
        self.publisher = node.create_publisher(
            MarkerArray, '/rrt_python/markers', qos)
        self._endpoints = None
        self._nodes = {}
        self._edges = {}
        self._path = []

    def set_endpoints(self, p_start, p_goal, start_name='home', goal_name='pose1'):
        self._endpoints = (_point(p_start), _point(p_goal))
        self._labels = (start_name, goal_name)

    def add_node(self, index, xyz, parent, curve):
        self._nodes[int(index)] = _point(xyz)
        if parent == -1:
            self._edges.pop(int(index), None)
            return
        # 边沿关节插值后的 FK 曲线显示，不能用两端直线替代。
        points = [_point(p) for p in curve]
        if len(points) < 2:
            raise ValueError('非根节点的 FK 曲线至少需要两个点')
        self._edges[int(index)] = points

    def set_path(self, xyz_sequence):
        self._path = [_point(p) for p in xyz_sequence]

    def clear_tree(self):
        self._nodes.clear()
        self._edges.clear()
        self._path.clear()

    def _marker(self, marker_id, marker_type, stamp, color):
        marker = Marker()
        marker.header.frame_id = self.frame
        marker.header.stamp = stamp
        marker.ns = 'rrt_python'
        marker.id = marker_id
        marker.type = marker_type
        marker.action = Marker.ADD
        marker.pose.orientation.w = 1.0
        marker.color = color
        return marker

    def publish(self, status=''):
        stamp = self.node.get_clock().now().to_msg()
        markers = MarkerArray()

        endpoints = self._marker(0, Marker.SPHERE_LIST, stamp, _color(1, 1, 1))
        endpoints.scale.x = endpoints.scale.y = endpoints.scale.z = 0.03
        if self._endpoints is None:
            endpoints.action = Marker.DELETE
        else:
            endpoints.points = list(self._endpoints)
            endpoints.colors = [_color(0.1, 0.85, 0.25), _color(0.95, 0.15, 0.12)]
        markers.markers.append(endpoints)

        for marker_id, label in enumerate(getattr(self, '_labels', ('home', 'pose1')), 1):
            marker = self._marker(
                marker_id, Marker.TEXT_VIEW_FACING, stamp, _color(0.95, 0.95, 0.95))
            marker.scale.z = 0.035
            marker.text = label
            if self._endpoints is None:
                marker.action = Marker.DELETE
            else:
                p = self._endpoints[marker_id - 1]
                marker.pose.position = Point(x=p.x, y=p.y, z=p.z + 0.06)
            markers.markers.append(marker)

        nodes = self._marker(3, Marker.SPHERE_LIST, stamp, _color(0.15, 0.55, 1.0, 0.9))
        nodes.scale.x = nodes.scale.y = nodes.scale.z = 0.008
        nodes.points = list(self._nodes.values())
        if not nodes.points:
            nodes.action = Marker.DELETE
        markers.markers.append(nodes)

        edges = self._marker(4, Marker.LINE_LIST, stamp, _color(0.35, 0.55, 0.72, 0.6))
        edges.scale.x = 0.002
        for curve in self._edges.values():
            for a, b in zip(curve[:-1], curve[1:]):
                edges.points.extend((a, b))
        if not edges.points:
            edges.action = Marker.DELETE
        markers.markers.append(edges)

        path = self._marker(5, Marker.LINE_STRIP, stamp, _color(1.0, 0.75, 0.05))
        path.scale.x = 0.006
        path.points = list(self._path)
        if len(path.points) < 2:
            path.action = Marker.DELETE
        markers.markers.append(path)

        message = self._marker(
            6, Marker.TEXT_VIEW_FACING, stamp, _color(0.95, 0.95, 0.95))
        message.scale.z = 0.03
        # 分行显示，避免当前 RViz/Ogre 字体把空格拉得过宽。
        message.text = str(status).replace(' | ', '\n').replace(' ', '_')
        if not status or self._endpoints is None:
            message.action = Marker.DELETE
        else:
            p = self._endpoints[0]
            message.pose.position = Point(x=p.x, y=p.y, z=p.z + 0.14)
        markers.markers.append(message)

        # 包括 DELETE 的全量快照，避免旧路径或旧文字残留。
        self.publisher.publish(markers)
