"""Validate a saved capture against MoveIt services and late ROS subscriptions."""
import csv
import json
from pathlib import Path
import sys
import time

import numpy as np
import rclpy
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from rclpy.serialization import deserialize_message, serialize_message
from moveit_msgs.msg import DisplayTrajectory, MotionPlanRequest, RobotTrajectory
from moveit_msgs.srv import GetPositionFK, GetStateValidity
from std_msgs.msg import String
from visualization_msgs.msg import MarkerArray
import yaml


def main():
    base = Path('/home/zhuxd/aubo_ws/rrt_results/ompl_same_plan')
    directory = Path(sys.argv[1]) if len(sys.argv) > 1 else max(base.iterdir(), key=lambda p: p.name)
    summary = yaml.safe_load((directory / 'summary.yaml').read_text())
    assert summary['capture_ok'] and summary['exact_solution']
    request = deserialize_message((directory / 'context_request.cdr').read_bytes(), MotionPlanRequest)
    rows = list(csv.DictReader((directory / 'nodes.csv').open()))
    names = [name for name in rows[0] if name.endswith('_joint')]
    rclpy.init()
    node = rclpy.create_node('check_saved_ompl_capture')
    qos = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE,
                     durability=DurabilityPolicy.TRANSIENT_LOCAL)
    received = {}
    subscriptions = [node.create_subscription(kind, '/rrt_ompl/' + topic,
        lambda message, name=topic: received.__setitem__(name, message), qos)
        for topic, kind in [('markers', MarkerArray), ('final_path', DisplayTrajectory), ('status', String)]]
    deadline = time.monotonic() + 12
    while len(received) < 3 and time.monotonic() < deadline:
        rclpy.spin_once(node, timeout_sec=0.1)
    assert len(received) == 3, f'late subscriber missing topics: {received.keys()}'
    assert yaml.safe_load(received['status'].data)['run_id'] == summary['run_id']
    assert received['markers'].markers[0].action == 3
    marker_by_name = {m.ns: m for m in received['markers'].markers}
    assert len(marker_by_name['tree_nodes'].points) == len(rows)
    assert {'raw_path', 'final_path', 'tree_nodes', 'tree_edges'} <= marker_by_name.keys()
    saved_final = deserialize_message((directory / 'final_trajectory.cdr').read_bytes(), RobotTrajectory)
    assert saved_final == received['final_path'].trajectory[0], 'final message fields differ'
    fk = node.create_client(GetPositionFK, '/compute_fk')
    validity = node.create_client(GetStateValidity, '/check_state_validity')
    assert fk.wait_for_service(timeout_sec=5) and validity.wait_for_service(timeout_sec=5)
    def call(client, query):
        future = client.call_async(query)
        rclpy.spin_until_future_complete(node, future, timeout_sec=5)
        assert future.done(), 'service timeout'
        return future.result()
    def state(q):
        from copy import deepcopy
        robot = deepcopy(request.start_state)
        positions = dict(zip(robot.joint_state.name, robot.joint_state.position))
        positions.update(zip(names, q))
        robot.joint_state.name = list(positions)
        robot.joint_state.position = list(positions.values())
        robot.is_diff = False
        return robot
    vectors = {int(row['id']): np.array([float(row[n]) for n in names]) for row in rows}
    max_fk_error = 0.0
    for row in rows:
        query = GetPositionFK.Request()
        query.header.frame_id = summary['frame']
        query.fk_link_names = ['scissor_tcp']
        query.robot_state = state(vectors[int(row['id'])])
        answer = call(fk, query)
        assert answer.error_code.val == 1
        p = answer.pose_stamped[0].pose.position
        max_fk_error = max(max_fk_error, float(np.max(np.abs(
            np.array([p.x, p.y, p.z]) - [float(row['tcp_' + c]) for c in 'xyz']))))
    assert max_fk_error < 1e-8
    edges = list(csv.DictReader((directory / 'edges.csv').open()))
    checked = 0
    for edge in edges:
        a, b = vectors[int(edge['source'])], vectors[int(edge['target'])]
        count = max(1, int(np.ceil(np.max(np.abs(b - a)) / 0.03)))
        for fraction in np.linspace(0, 1, count + 1):
            query = GetStateValidity.Request()
            query.group_name = 'aubo_arm'
            query.robot_state = state(a + fraction * (b - a))
            assert call(validity, query).valid, f'invalid tree edge: {edge}'
            checked += 1
    report = {'run_id': summary['run_id'], 'late_subscriber': True,
              'snapshot_clears_previous': True, 'final_cdr_matches_topic': True,
              'vertices_fk_checked': len(rows), 'max_fk_error_m': max_fk_error,
              'tree_edge_interpolated_states_checked': checked, 'all_valid': True}
    out = Path('/home/zhuxd/aubo_ws/rrt_results/ompl_capture_verification')
    (out / ('saved_check_' + summary['run_id'] + '.json')).write_text(json.dumps(report, indent=2))
    print(json.dumps(report, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
