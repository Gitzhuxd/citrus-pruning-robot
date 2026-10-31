"""在已启动的 MoveIt 仿真上检查真实消息、探索回放和保存数据。"""
import csv
from copy import deepcopy
import json
from pathlib import Path
import signal
import subprocess
import sys
import time

import numpy as np
import rclpy
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from moveit_msgs.msg import DisplayTrajectory, PlanningSceneComponents
from moveit_msgs.srv import GetPlanningScene, GetStateValidity, GetPositionFK
from visualization_msgs.msg import MarkerArray


directory = Path('/home/zhuxd/aubo_ws/rrt_results/python_verification')
directory.mkdir(exist_ok=True)
rclpy.init()
node = rclpy.create_node('rrt_python_integration_check')
qos = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE,
                 durability=DurabilityPolicy.TRANSIENT_LOCAL)
observed = {'markers': None, 'trajectory': None, 'replay_counts': []}


def markers_received(message):
    observed['markers'] = message
    by_id = {m.id: m for m in message.markers}
    if 6 in by_id and 'exploration_replay' in by_id[6].text:
        observed['replay_counts'].append(len(by_id[3].points))


def trajectory_received(message):
    observed['trajectory'] = message


def wait_until(predicate, timeout=20):
    deadline = time.monotonic() + timeout
    while not predicate() and time.monotonic() < deadline:
        if process.poll() is not None:
            raise RuntimeError('RRT 子进程提前退出，请看 demo.log')
        rclpy.spin_once(node, timeout_sec=0.05)
    assert predicate(), '等待消息超时'


def request(client, message):
    assert client.wait_for_service(timeout_sec=5)
    future = client.call_async(message)
    rclpy.spin_until_future_complete(node, future, timeout_sec=5)
    assert future.done(), '服务超时'
    return future.result()


marker_sub = node.create_subscription(
    MarkerArray, '/rrt_python/markers', markers_received, qos)
trajectory_sub = node.create_subscription(
    DisplayTrajectory, '/display_planned_path', trajectory_received, qos)
log = (directory / 'demo.log').open('w')
process = subprocess.Popen(
    [sys.executable, '-m', 'aubo_rrt_python.rrt_demo'], stdout=log,
    stderr=subprocess.STDOUT)

try:
    def finished():
        message = observed['markers']
        return (message is not None and observed['trajectory'] is not None
                and any(m.id == 6 and m.text.startswith('RRT_solved')
                        for m in message.markers))

    wait_until(finished)
    counts = observed['replay_counts']
    assert len(set(counts)) >= 10 and counts == sorted(counts), counts
    final_markers = {m.id: m for m in observed['markers'].markers}
    trajectory = observed['trajectory']

    # 销毁订阅并晚加入：必须拿到完整树和轨迹，而非最后一个节点。
    node.destroy_subscription(marker_sub)
    node.destroy_subscription(trajectory_sub)
    observed['markers'] = observed['trajectory'] = None
    marker_sub = node.create_subscription(
        MarkerArray, '/rrt_python/markers', markers_received, qos)
    trajectory_sub = node.create_subscription(
        DisplayTrajectory, '/display_planned_path', trajectory_received, qos)
    wait_until(finished)
    late_markers = {m.id: m for m in observed['markers'].markers}
    assert len(late_markers[3].points) == len(final_markers[3].points)
    assert len(late_markers[5].points) == len(final_markers[5].points)

    run = max(Path('/home/zhuxd/aubo_ws/rrt_results/python').iterdir(),
              key=lambda path: path.stat().st_mtime)
    summary = json.loads((run / 'summary.json').read_text())
    with (run / 'tree.csv').open() as stream:
        tree = list(csv.DictReader(stream))
    with (run / 'path.csv').open() as stream:
        path = list(csv.DictReader(stream))
    names = summary['joint_names']
    q_tree = np.array([[float(row[name]) for name in names] for row in tree])
    q_path = np.array([[float(row[name]) for name in names] for row in path])
    parents = [int(row['parent']) for row in tree]
    assert summary['success'] and len(tree) == summary['tree_nodes']
    assert parents[0] == -1 and all(0 <= parents[i] < i for i in range(1, len(tree)))
    assert np.array_equal(q_path[0], summary['start'])
    assert np.array_equal(q_path[-1], summary['goal'])
    assert np.all(np.isfinite(q_tree))
    assert np.all(q_tree >= summary['joint_lower'])
    assert np.all(q_tree <= summary['joint_upper'])
    assert len(final_markers[3].points) == len(tree)
    assert len(final_markers[5].points) == len(path)
    assert len(final_markers[4].points) > 0 and len(final_markers[4].points) % 2 == 0
    assert all(marker.header.frame_id == 'world' for marker in final_markers.values())

    joint_trajectory = trajectory.trajectory[0].joint_trajectory
    assert list(joint_trajectory.joint_names) == names
    assert len(joint_trajectory.points) == len(path)
    for point, q in zip(joint_trajectory.points, q_path):
        np.testing.assert_allclose(point.positions, q, atol=1e-12)
    timestamps = [p.time_from_start.sec + p.time_from_start.nanosec * 1e-9
                  for p in joint_trajectory.points]
    assert all(b > a for a, b in zip(timestamps[:-1], timestamps[1:]))
    start_state = trajectory.trajectory_start.joint_state
    start_by_name = dict(zip(start_state.name, start_state.position))
    assert start_by_name['scissor_drive_joint'] == 0.3
    assert start_by_name['scissor_mimic_joint'] == -0.3

    scene_client = node.create_client(GetPlanningScene, '/get_planning_scene')
    validity_client = node.create_client(GetStateValidity, '/check_state_validity')
    fk_client = node.create_client(GetPositionFK, '/compute_fk')
    query = GetPlanningScene.Request()
    query.components.components = (PlanningSceneComponents.ROBOT_STATE
                                   | PlanningSceneComponents.ROBOT_STATE_ATTACHED_OBJECTS)
    state = request(scene_client, query).scene.robot_state
    indices = {name: i for i, name in enumerate(state.joint_state.name)}

    def state_for(q):
        result = deepcopy(state)
        for name, value in zip(names, q):
            result.joint_state.position[indices[name]] = float(value)
        result.is_diff = False
        return result

    checks = 0
    # 独立实现插值，不复用被测 RRT 核心的碰撞检查函数。
    for i in range(1, len(tree)):
        a, b = q_tree[parents[i]], q_tree[i]
        assert np.linalg.norm(b - a) <= summary['settings']['step_size'] + 1e-10
        n = max(1, int(np.ceil(np.max(np.abs(b - a)) / 0.02)))
        for fraction in np.linspace(0, 1, n + 1):
            query = GetStateValidity.Request()
            query.group_name = 'aubo_arm'
            query.robot_state = state_for(a + fraction * (b - a))
            assert request(validity_client, query).valid, f'tree edge {parents[i]}->{i}'
            checks += 1

    for row, q, point in zip(path, q_path, final_markers[5].points):
        query = GetPositionFK.Request()
        query.header.frame_id = 'world'
        query.fk_link_names = ['scissor_tcp']
        query.robot_state = state_for(q)
        response = request(fk_client, query)
        assert response.error_code.val == 1
        position = response.pose_stamped[0].pose.position
        xyz = [position.x, position.y, position.z]
        np.testing.assert_allclose(xyz, [point.x, point.y, point.z], atol=1e-9)
        np.testing.assert_allclose(xyz, [float(row[k]) for k in ('tcp_x', 'tcp_y', 'tcp_z')], atol=1e-9)

    result = {
        'passed': True, 'result_directory': str(run), 'tree_nodes': len(tree),
        'path_nodes': len(summary['path_tree_indices']), 'dense_path_states': len(path),
        'replay_distinct_frames': len(set(counts)), 'late_subscriber_complete_tree': True,
        'late_subscriber_complete_trajectory': True, 'scissor_state_preserved': True,
        'independent_tree_edge_state_checks_at_0_02_rad': checks,
        'independent_path_fk_checks': len(path), 'display_timing_monotonic': True,
    }
    (directory / 'verification.json').write_text(json.dumps(result, indent=2))
    print(json.dumps(result, indent=2))
finally:
    process.send_signal(signal.SIGINT)
    try:
        process.wait(timeout=5)
    except subprocess.TimeoutExpired:
        process.terminate()
        process.wait(timeout=5)
    log.close()
    node.destroy_node()
    rclpy.shutdown()
