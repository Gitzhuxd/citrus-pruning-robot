import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import Command, FindExecutable

from launch_ros.actions import Node


def generate_launch_description():

    package_name = 'aubo_i5_scissors_description'

    package_share = get_package_share_directory(package_name)

    # 顶层组合模型
    robot_core_xacro = os.path.join(
        package_share,
        'urdf',
        'robot_core.xacro',
    )

    # 使用xacro命令生成完整URDF
    robot_description_content = Command([
        FindExecutable(name='xacro'),
        ' ',
        robot_core_xacro,
    ])

    robot_description = {
        'robot_description': robot_description_content,
    }

    # 使用AUBO官方RViz配置
    aubo_description_share = get_package_share_directory(
        'aubo_description'
    )

    rviz_config_file = os.path.join(
        aubo_description_share,
        'rviz',
        'view_robot.rviz',
    )

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='aubo_i5_scissors_robot_state_publisher',
        output='screen',
        parameters=[robot_description],
    )

    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='aubo_i5_scissors_joint_state_publisher_gui',
        output='screen',
        parameters=[robot_description],
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='aubo_i5_scissors_rviz2',
        output='screen',
        arguments=[
            '-d',
            rviz_config_file,
        ],
        parameters=[robot_description],
    )

    return LaunchDescription([
        robot_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node,
    ])