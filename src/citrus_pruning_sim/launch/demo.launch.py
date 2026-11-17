"""Start RViz and the cuttable tree; optionally synchronize an existing MoveIt scene."""
from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    share = Path(get_package_share_directory('citrus_pruning_sim'))
    declarations = [DeclareLaunchArgument(name, default_value=default, description=description)
                    for name, default, description in (
        ('rviz', 'true', 'Open the supplied RViz view'),
        ('publish_moveit', 'false', 'Synchronize an already running move_group'),
        ('show_scan', 'false', 'Show downsampled scan centers, not full Gaussian rendering'),
        ('reuse_marker_geometry', 'true', 'Reuse immutable marker geometry; false retains deep-copy baseline'),
        ('publish_tf', 'true', 'Publish the tree transform; disable if your robot already provides it'),
        ('parent_frame', 'world', 'Existing robot/world parent frame'),
        ('x', '0.0', 'Tree position in parent frame, meters'),
        ('y', '0.0', 'Tree position in parent frame, meters'),
        ('z', '0.0', 'Tree position in parent frame, meters'),
        ('yaw', '0.0', 'Tree yaw in radians'),
        ('collision_margin', '0.003', 'Radial and end-cap margin, meters'),
        ('s01_cut_offset_m', '0.0', 'Length retained after cutting partial_cut_target, meters'),
        ('partial_cut_target', 'S01', 'Target that retains a stump when the cut offset is positive'),
        ('moveit_service', '/apply_planning_scene', 'MoveIt ApplyPlanningScene service'),
        ('model_path', str(share / 'data' / 'tree_model.json'), 'Geometry JSON'),
    )]
    scene = Node(package='citrus_pruning_sim', executable='pruning_scene', output='screen',
                 parameters=[{
                     'model_path': LaunchConfiguration('model_path'),
                     'publish_moveit': ParameterValue(LaunchConfiguration('publish_moveit'), value_type=bool),
                     'show_scan': ParameterValue(LaunchConfiguration('show_scan'), value_type=bool),
                     'reuse_marker_geometry': ParameterValue(LaunchConfiguration('reuse_marker_geometry'), value_type=bool),
                     'collision_margin': ParameterValue(LaunchConfiguration('collision_margin'), value_type=float),
                     's01_cut_offset_m': ParameterValue(LaunchConfiguration('s01_cut_offset_m'), value_type=float),
                     'partial_cut_target': ParameterValue(LaunchConfiguration('partial_cut_target'), value_type=str),
                     'moveit_service': LaunchConfiguration('moveit_service'),
                 }])
    transform = Node(package='tf2_ros', executable='static_transform_publisher',
                     name='citrus_tree_transform', condition=IfCondition(LaunchConfiguration('publish_tf')),
                     arguments=['--x', LaunchConfiguration('x'), '--y', LaunchConfiguration('y'),
                                '--z', LaunchConfiguration('z'), '--yaw', LaunchConfiguration('yaw'),
                                '--frame-id', LaunchConfiguration('parent_frame'),
                                '--child-frame-id', 'tree_base'])
    viewer = Node(package='rviz2', executable='rviz2', name='citrus_rviz',
                  condition=IfCondition(LaunchConfiguration('rviz')),
                  arguments=['-d', str(share / 'config' / 'pruning.rviz'),
                             '-f', LaunchConfiguration('parent_frame')])
    return LaunchDescription([*declarations, transform, scene, viewer])
