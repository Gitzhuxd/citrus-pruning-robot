"""Unified S01 simulation: robot state, MoveIt, citrus scene, S01 task node, optional RViz.

    export ROS_DOMAIN_ID=94 ROS_LOCALHOST_ONLY=1
    ros2 launch citrus_pruning_task simulation.launch.py              # RViz on
    ros2 launch citrus_pruning_task simulation.launch.py rviz:=false  # headless

Planning only: move_group runs with trajectory execution disabled and no
ros2_control / AUBO driver is started. The robot shown in RViz is driven by
joint_state_publisher listening to /citrus/s01/joint_states (task replay).

Based on the archived experiment launch files (s01_stump_demo_v1 ->
pruning_seeded_s07_v1/simulation.launch.py); defaults reproduce the verified S01 scene.
"""

import xml.etree.ElementTree as ET
from pathlib import Path
from tempfile import NamedTemporaryFile

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    GroupAction,
    IncludeLaunchDescription,
    OpaqueFunction,
    RegisterEventHandler,
)
from launch.conditions import IfCondition
from launch.event_handlers import OnShutdown
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from moveit_configs_utils import MoveItConfigsBuilder

from citrus_pruning_task.isolation import isolation_error


CONFIG_PACKAGE = "aubo_i5_scissors_moveit_config"


def verify_isolated_environment(context):
    error = isolation_error()
    if error:
        raise RuntimeError(error)
    return []


def create_rviz(context, config_dir, moveit_parameters):
    with (config_dir / "config" / "moveit.rviz").open(encoding="utf-8") as handle:
        config = yaml.safe_load(handle)

    # Keep the installed MoveIt view and remove experimental, unrelated plugins.
    config["Panels"] = [panel for panel in config["Panels"] if panel["Class"] == "rviz_common/Displays"]
    manager = config["Visualization Manager"]
    manager["Displays"] = [
        display for display in manager["Displays"]
        if display["Class"] in {"moveit_rviz_plugin/MotionPlanning", "rviz_default_plugins/Grid"}
    ]
    motion = next(display for display in manager["Displays"] if display["Class"] == "moveit_rviz_plugin/MotionPlanning")
    motion["Planned Path"].update({
        "Trajectory Topic": "/citrus/s01/display_trajectory",
        "State Display Time": "REALTIME",
        "Robot Alpha": 1.0,
    })
    motion["Planning Request"]["Query Goal State"] = False
    motion["Scene Geometry"]["Show Scene Geometry"] = False
    motion["Scene Robot"]["Show Robot Visual"] = False
    motion["Scene Robot"]["Show Robot Collision"] = False
    motion["Enabled"] = motion["Value"] = False
    manager["Displays"].append({
        "Class": "rviz_default_plugins/RobotModel",
        "Enabled": True,
        "Name": "AUBO i5 replay",
        "Description Source": "Topic",
        "Description Topic": {
            "Value": "/robot_description",
            "Reliability Policy": "Reliable",
            "Durability Policy": "Transient Local",
            "Depth": 1,
        },
        "Visual Enabled": True,
        "Collision Enabled": False,
        "Value": True,
    })
    manager["Displays"].append({
        "Class": "rviz_default_plugins/MarkerArray",
        "Enabled": True,
        "Name": "Citrus tree and cut targets",
        "Topic": {
            "Value": "/citrus/markers",
            "Reliability Policy": "Reliable",
            "Durability Policy": "Transient Local",
            "Depth": 1,
        },
        "Value": True,
    })
    manager["Global Options"]["Fixed Frame"] = "world"
    manager["Global Options"]["Frame Rate"] = 30
    manager["Views"]["Current"].update({
        "Distance": 3.7,
        "Focal Point": {"X": 0.55, "Y": -0.20, "Z": 0.9},
    })
    config["Window Geometry"] = {"Width": 1400, "Height": 900}

    with NamedTemporaryFile(mode="w", encoding="utf-8", suffix=".rviz", prefix="citrus_s01_", delete=False) as handle:
        yaml.safe_dump(config, handle, sort_keys=False, allow_unicode=True)
        config_path = Path(handle.name)

    def remove_temporary_config(event, launch_context):
        config_path.unlink(missing_ok=True)
        return []

    return [
        RegisterEventHandler(OnShutdown(on_shutdown=remove_temporary_config)),
        Node(
            package="rviz2", executable="rviz2", name="s01_rviz",
            arguments=["-d", str(config_path)], parameters=[moveit_parameters], output="screen",
        ),
    ]


def generate_launch_description():
    config_dir = Path(get_package_share_directory(CONFIG_PACKAGE))
    citrus_dir = Path(get_package_share_directory("citrus_pruning_sim"))
    moveit = MoveItConfigsBuilder(
        "aubo_i5_scissors_robot", package_name=CONFIG_PACKAGE
    ).to_moveit_configs()
    # Use the stock planner for daily runs. Historical experiments supply their own capture launch.
    ompl = moveit.planning_pipelines["ompl"]
    ompl["planning_plugin"] = "ompl_interface/OMPLPlanner"
    ompl["request_adapters"] = " ".join(
        adapter for adapter in ompl["request_adapters"].split()
        if adapter != "aubo_ompl_capture/CaptureResult"
    )
    # The rigid lower deck touches the chassis at z=0.430 m by design.
    semantic = ET.fromstring(moveit.robot_description_semantic["robot_description_semantic"])
    ET.SubElement(semantic, "disable_collisions", link1="car_base_link",
                  link2="car_arm_mount_link", reason="Fixed chassis assembly")
    moveit.robot_description_semantic["robot_description_semantic"] = ET.tostring(semantic, encoding="unicode")
    open_joints = {
        "zeros.shoulder_joint": 0.0,
        "zeros.upperArm_joint": 0.0,
        "zeros.foreArm_joint": 0.0,
        "zeros.wrist1_joint": 0.0,
        "zeros.wrist2_joint": 0.0,
        "zeros.wrist3_joint": 0.0,
        "zeros.scissor_drive_joint": 0.3009,
    }
    task_params = str(Path(get_package_share_directory("citrus_pruning_task")) / "config" / "s01_task.yaml")
    return LaunchDescription([
        DeclareLaunchArgument("rviz", default_value="true", description="Open RViz (false for headless/SSH)"),
        DeclareLaunchArgument("task", default_value="true", description="Start the S01 task node"),
        DeclareLaunchArgument("auto_start", default_value="false",
                              description="Run one S01 round automatically after startup"),
        DeclareLaunchArgument("play", default_value="true", description="Replay the planned round in RViz"),
        # Verified S01 scene (s01_stump_demo_v1/verified_stump_replay): tree pose and 6 mm stump.
        DeclareLaunchArgument("tree_x", default_value="1.01"),
        DeclareLaunchArgument("tree_y", default_value="-0.72"),
        DeclareLaunchArgument("tree_z", default_value="0.0"),
        DeclareLaunchArgument("tree_yaw", default_value="0.0"),
        DeclareLaunchArgument("s01_cut_offset_m", default_value="0.006",
                              description="Stump length kept after the cut (0.0 = legacy full removal)"),
        DeclareLaunchArgument("partial_cut_target", default_value="S01"),
        DeclareLaunchArgument("reuse_marker_geometry", default_value="true"),
        OpaqueFunction(function=verify_isolated_environment),
        Node(
            package="tf2_ros", executable="static_transform_publisher", name="simulation_world_to_car",
            arguments=["--frame-id", "world", "--child-frame-id", "car_base_footprint"],
        ),
        Node(package="robot_state_publisher", executable="robot_state_publisher", parameters=[moveit.robot_description]),
        Node(
            package="joint_state_publisher", executable="joint_state_publisher",
            parameters=[open_joints, {"rate": 60, "use_mimic_tags": True,
                                      "source_list": ["/citrus/s01/joint_states"]}],
        ),
        Node(
            package="moveit_ros_move_group", executable="move_group", output="screen",
            parameters=[moveit.to_dict(), {
                "allow_trajectory_execution": False,
                "disable_capabilities": "move_group/MoveGroupExecuteTrajectoryAction",
                "moveit_manage_controllers": False,
                "publish_robot_description_semantic": True,
                "publish_planning_scene": True,
                "publish_geometry_updates": True,
                "publish_state_updates": True,
                "publish_transforms_updates": True,
                "monitor_dynamics": False,
            }],
        ),
        GroupAction(scoped=True, actions=[IncludeLaunchDescription(
            PythonLaunchDescriptionSource(str(citrus_dir / "launch" / "demo.launch.py")),
            launch_arguments={
                "rviz": "false", "publish_moveit": "true", "parent_frame": "world",
                "x": LaunchConfiguration("tree_x"), "y": LaunchConfiguration("tree_y"),
                "z": LaunchConfiguration("tree_z"), "yaw": LaunchConfiguration("tree_yaw"),
                "s01_cut_offset_m": LaunchConfiguration("s01_cut_offset_m"),
                "partial_cut_target": LaunchConfiguration("partial_cut_target"),
                "reuse_marker_geometry": LaunchConfiguration("reuse_marker_geometry"),
            }.items(),
        )]),
        OpaqueFunction(
            function=create_rviz,
            kwargs={"config_dir": config_dir, "moveit_parameters": moveit.to_dict()},
            condition=IfCondition(LaunchConfiguration("rviz")),
        ),
        Node(
            package="citrus_pruning_task", executable="s01_task", name="citrus_s01_task", output="screen",
            condition=IfCondition(LaunchConfiguration("task")),
            parameters=[task_params, {
                "auto_start": ParameterValue(LaunchConfiguration("auto_start"), value_type=bool),
                "play": ParameterValue(LaunchConfiguration("play"), value_type=bool),
            }],
        ),
    ])
