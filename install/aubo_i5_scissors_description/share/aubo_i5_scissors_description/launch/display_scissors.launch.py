import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    package_name = 'aubo_i5_scissors_description'

    package_share = get_package_share_directory(package_name)

    urdf_file = os.path.join(
        package_share,
        'urdf',
        'electric_scissor.urdf'
    )

    with open(urdf_file, 'r', encoding='utf-8') as file:
        robot_description_content = file.read()

    robot_description = {
        'robot_description': robot_description_content
    }

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='scissor_robot_state_publisher',
        output='screen',
        parameters=[robot_description],
    )

    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='scissor_joint_state_publisher_gui',
        output='screen',
        parameters=[robot_description],
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='scissor_rviz2',
        output='screen',
        parameters=[robot_description],
    )

    return LaunchDescription([
        robot_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node,
    ])
