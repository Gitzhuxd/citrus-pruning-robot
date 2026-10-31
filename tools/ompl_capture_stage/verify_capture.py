"""Send one plan-only MoveGroup request and verify its capture, without execution."""
import argparse
from copy import deepcopy
import csv
import json
from pathlib import Path
import time

import rclpy
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, JointConstraint, DisplayTrajectory, PlanningSceneComponents
from moveit_msgs.srv import GetPlanningScene
from std_msgs.msg import String
from visualization_msgs.msg import MarkerArray
import yaml

NAMES = ['shoulder_joint', 'upperArm_joint', 'foreArm_joint',
         'wrist1_joint', 'wrist2_joint', 'wrist3_joint']
GOAL = [-0.0347, 1.215, 2.2564, 0.7984, 0.3818, 0.5207]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--attempts', type=int, default=1)
    parser.add_argument('--planner', default='RRTkConfigDefault')
    args = parser.parse_args()
    rclpy.init()
    node = rclpy.create_node('verify_same_call_ompl')
    qos = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE,
                     durability=DurabilityPolicy.TRANSIENT_LOCAL)
    received = {}
    subscriptions = [node.create_subscription(kind, '/rrt_ompl/' + topic,
        lambda message, name=topic: received.__setitem__(name, message), qos)
        for topic, kind in [('markers', MarkerArray), ('final_path', DisplayTrajectory), ('status', String)]]
    def until(predicate, seconds=15):
        deadline = time.monotonic() + seconds
        while not predicate() and time.monotonic() < deadline:
            rclpy.spin_once(node, timeout_sec=0.05)
        assert predicate(), 'verification timed out'
    def result(future, seconds=15):
        until(future.done, seconds)
        return future.result()
    until(lambda: 'status' in received)
    previous = yaml.safe_load(received['status'].data)['run_id']
    scene_client = node.create_client(GetPlanningScene, '/get_planning_scene')
    assert scene_client.wait_for_service(timeout_sec=5)
    query = GetPlanningScene.Request()
    query.components.components = PlanningSceneComponents.ROBOT_STATE | PlanningSceneComponents.ROBOT_STATE_ATTACHED_OBJECTS
    start = deepcopy(result(scene_client.call_async(query)).scene.robot_state)
    positions = dict(zip(start.joint_state.name, start.joint_state.position))
    positions.update(dict.fromkeys(NAMES, 0.0))
    start.joint_state.name = list(positions)
    start.joint_state.position = list(positions.values())
    start.is_diff = False
    goal = MoveGroup.Goal()
    request = goal.request
    request.group_name = 'aubo_arm'
    request.pipeline_id = 'ompl'
    request.planner_id = args.planner
    request.num_planning_attempts = args.attempts
    request.allowed_planning_time = 5.0
    request.max_velocity_scaling_factor = 0.1
    request.max_acceleration_scaling_factor = 0.1
    request.start_state = start
    constraints = Constraints()
    for name, value in zip(NAMES, GOAL):
        constraints.joint_constraints.append(JointConstraint(
            joint_name=name, position=value, tolerance_above=0.0001,
            tolerance_below=0.0001, weight=1.0))
    request.goal_constraints = [constraints]
    goal.planning_options.plan_only = True
    action = ActionClient(node, MoveGroup, '/move_action')
    assert action.wait_for_server(timeout_sec=5)
    handle = result(action.send_goal_async(goal))
    assert handle.accepted
    response = result(handle.get_result_async(), 20).result
    assert response.error_code.val == 1, f'MoveGroup error {response.error_code.val}'
    until(lambda: yaml.safe_load(received['status'].data)['run_id'] != previous)
    status = yaml.safe_load(received['status'].data)
    assert status['solve_calls'] == 1
    expected_capture = args.attempts == 1 and args.planner == 'RRTkConfigDefault'
    assert status['capture_ok'] == expected_capture, status
    directory = Path(status['output_directory'])
    report = {'run_id': status['run_id'], 'previous_run_id': previous,
              'plan_only': True, 'action_success': True, 'solve_calls': status['solve_calls'],
              'planner': args.planner, 'attempts': args.attempts,
              'capture_ok': status['capture_ok'], 'reason': status['reason']}
    if expected_capture:
        final = response.planned_trajectory
        def matches():
            topic = received.get('final_path')
            if not topic or len(topic.trajectory) != 1:
                return False
            actual = topic.trajectory[0]
            return (actual.joint_trajectory.joint_names == final.joint_trajectory.joint_names
                    and actual.joint_trajectory.points == final.joint_trajectory.points
                    and actual.multi_dof_joint_trajectory.joint_names == final.multi_dof_joint_trajectory.joint_names
                    and actual.multi_dof_joint_trajectory.points == final.multi_dof_joint_trajectory.points)
        until(matches)
        rows = list(csv.DictReader((directory / 'nodes.csv').open()))
        nodes = {int(row['id']): row for row in rows}
        edges = {(int(e['source']), int(e['target'])) for e in csv.DictReader((directory / 'edges.csv').open())}
        raw = list(csv.DictReader((directory / 'raw_path.csv').open()))
        ids = [int(row['vertex_id']) for row in raw]
        assert ids == status['raw_path_vertex_ids'] and len(set(ids)) == len(ids)
        assert int(nodes[ids[0]]['is_start']) == 1 and int(nodes[ids[-1]]['is_goal']) == 1
        for a, b in zip(ids, ids[1:]):
            assert (a, b) in edges and int(nodes[b]['parent']) == a
        for row in raw:
            for field in NAMES + ['tcp_x', 'tcp_y', 'tcp_z']:
                assert float(row[field]) == float(nodes[int(row['vertex_id'])][field])
        markers = received['markers'].markers
        assert markers[0].action == 3
        tree_nodes = next(m for m in markers if m.ns == 'tree_nodes')
        assert len(tree_nodes.points) == len(nodes)
        report.update({'final_exactly_matches_action': True, 'raw_follows_actual_parent_edges': True,
                       'vertex_count': len(nodes), 'raw_waypoints': len(raw),
                       'final_waypoints': len(final.joint_trajectory.points)})
    else:
        until(lambda: len(received['markers'].markers) == 1
              and received['markers'].markers[0].action == 3
              and not received['final_path'].trajectory)
        report['stale_display_cleared'] = True
    output = Path('/home/zhuxd/aubo_ws/rrt_results/ompl_capture_verification')
    (output / ('action_' + status['run_id'] + '.json')).write_text(json.dumps(report, indent=2))
    print(json.dumps(report, indent=2))
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
