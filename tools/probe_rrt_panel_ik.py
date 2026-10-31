import json
import xml.etree.ElementTree as ET
from copy import deepcopy
import rclpy
from rcl_interfaces.srv import GetParameters
from moveit_msgs.msg import PlanningSceneComponents
from moveit_msgs.srv import GetPlanningScene, GetPositionFK, GetPositionIK

rclpy.init()
node = rclpy.create_node('rrt_panel_ik_probe')


def call(kind, name, request):
    client = node.create_client(kind, name)
    assert client.wait_for_service(timeout_sec=5), name
    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future, timeout_sec=5)
    assert future.done(), name
    result = future.result()
    node.destroy_client(client)
    return result


try:
    request = GetPlanningScene.Request()
    request.components.components = PlanningSceneComponents.ROBOT_STATE
    current = call(GetPlanningScene, '/get_planning_scene', request).scene.robot_state
    request = GetParameters.Request()
    request.names = ['robot_description_semantic']
    srdf = call(GetParameters, '/move_group/get_parameters', request).values[0].string_value
    root = ET.fromstring(srdf)
    output = []
    for name in ('home', 'pose1', 'pose2'):
        state = deepcopy(current)
        indices = {name: i for i, name in enumerate(state.joint_state.name)}
        group = root.find(f'group_state[@group="aubo_arm"][@name="{name}"]')
        for joint in group.findall('joint'):
            state.joint_state.position[indices[joint.get('name')]] = float(joint.get('value'))
        state.is_diff = False
        request = GetPositionFK.Request()
        request.header.frame_id = 'world'
        request.fk_link_names = ['scissor_tcp']
        request.robot_state = state
        fk = call(GetPositionFK, '/compute_fk', request)
        assert fk.error_code.val == 1
        request = GetPositionIK.Request()
        request.ik_request.group_name = 'aubo_arm'
        request.ik_request.ik_link_name = 'scissor_tcp'
        request.ik_request.robot_state = deepcopy(current)
        request.ik_request.pose_stamped = fk.pose_stamped[0]
        request.ik_request.avoid_collisions = True
        request.ik_request.timeout.sec = 1
        ik = call(GetPositionIK, '/compute_ik', request)
        position = fk.pose_stamped[0].pose.position
        orientation = fk.pose_stamped[0].pose.orientation
        output.append({'name': name, 'ik_error_code': ik.error_code.val,
                       'xyz': [position.x, position.y, position.z],
                       'quaternion_xyzw': [orientation.x, orientation.y, orientation.z, orientation.w]})
    print(json.dumps(output, indent=2))
finally:
    node.destroy_node()
    rclpy.shutdown()
