import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from moveit_configs_utils import MoveItConfigsBuilder


def generate_launch_description():
    config_package = "aubo_i5_scissors_moveit_config"
    moveit_config = MoveItConfigsBuilder(
        "aubo_i5_scissors_robot", package_name=config_package
    ).to_moveit_configs()

    arguments = [
        DeclareLaunchArgument("start_scene", default_value="true"),
        DeclareLaunchArgument(
            "rviz_config",
            default_value=(
                "/home/zhuxd/aubo_ws/src/"
                "aubo_i5_scissors_moveit_config/config/moveit.rviz"
            ),
        ),
        DeclareLaunchArgument("start_state", default_value="home"),
        DeclareLaunchArgument("goal_state", default_value="pose1"),
        DeclareLaunchArgument("planning_time", default_value="5.0"),
        DeclareLaunchArgument("range", default_value="0.3"),
        DeclareLaunchArgument("seed", default_value="42"),
        DeclareLaunchArgument(
            "output_directory",
            default_value=os.path.expanduser("~/aubo_ws/rrt_results"),
        ),
    ]

    scene = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory(config_package), "launch", "demo.launch.py"
            )
        ),
        condition=IfCondition(LaunchConfiguration("start_scene")),
        launch_arguments={"rviz_config": LaunchConfiguration("rviz_config")}.items(),
    )

    visualizer = Node(
        package="aubo_rrt_visualizer",
        executable="rrt_visualizer",
        name="rrt_visualizer",
        output="screen",
        parameters=[
            moveit_config.to_dict(),
            {
                "start_state": ParameterValue(
                    LaunchConfiguration("start_state"), value_type=str
                ),
                "goal_state": ParameterValue(
                    LaunchConfiguration("goal_state"), value_type=str
                ),
                "planning_time": ParameterValue(
                    LaunchConfiguration("planning_time"), value_type=float
                ),
                "seed": ParameterValue(LaunchConfiguration("seed"), value_type=int),
                "range": ParameterValue(LaunchConfiguration("range"), value_type=float),
                "output_directory": ParameterValue(
                    LaunchConfiguration("output_directory"), value_type=str
                ),
                "rviz_config": ParameterValue(
                    LaunchConfiguration("rviz_config"), value_type=str
                ),
            },
        ],
    )

    return LaunchDescription(arguments + [scene, visualizer])
