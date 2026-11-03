from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_demo_launch


def generate_launch_description():
    moveit_config = MoveItConfigsBuilder("aubo_i5_scissors_robot", package_name="aubo_i5_scissors_moveit_config").to_moveit_configs()
    launch = generate_demo_launch(moveit_config)
    launch.add_action(DeclareLaunchArgument(
        "rrt_panel", default_value="true",
        description="Start the Python RRT panel backend (display only)"))
    launch.add_action(Node(
        package="aubo_rrt_python", executable="rrt_server", output="screen",
        condition=IfCondition(LaunchConfiguration("rrt_panel"))))
    return launch
