"""Precisely add the verified panel/backend to the existing demo configuration."""
from pathlib import Path
import shutil
import yaml

base = Path('/home/zhuxd/aubo_ws/src/aubo_i5_scissors_moveit_config')
backup = Path('/home/zhuxd/aubo_ws/rrt_setup_backups/rrt_panel_20261024_180750')
for relative in ('launch/demo.launch.py', 'package.xml', 'config/moveit.rviz'):
    target = backup / relative
    target.parent.mkdir(parents=True, exist_ok=True)
    if not target.exists():
        shutil.copy2(base / relative, target)

launch = base / 'launch/demo.launch.py'
text = launch.read_text()
if 'rrt_server' not in text:
    text = text.replace('from moveit_configs_utils import MoveItConfigsBuilder',
                        'from launch.actions import DeclareLaunchArgument\n'
                        'from launch.conditions import IfCondition\n'
                        'from launch.substitutions import LaunchConfiguration\n'
                        'from launch_ros.actions import Node\n'
                        'from moveit_configs_utils import MoveItConfigsBuilder', 1)
    old = '    return generate_demo_launch(moveit_config)'
    assert old in text
    text = text.replace(old, '''    launch = generate_demo_launch(moveit_config)
    launch.add_action(DeclareLaunchArgument(
        "rrt_panel", default_value="true",
        description="Start the Python RRT panel backend (display only)"))
    launch.add_action(Node(
        package="aubo_rrt_python", executable="rrt_server", output="screen",
        condition=IfCondition(LaunchConfiguration("rrt_panel"))))
    return launch''', 1)
    compile(text, str(launch), 'exec')
    launch.write_text(text)

package = base / 'package.xml'
text = package.read_text()
if '<exec_depend>aubo_rrt_python</exec_depend>' not in text:
    text = text.replace('  <export>', '  <exec_depend>aubo_rrt_python</exec_depend>\n'
                        '  <exec_depend>aubo_rrt_panel</exec_depend>\n\n  <export>', 1)
    package.write_text(text)

config = base / 'config/moveit.rviz'
text = config.read_text()
before = yaml.safe_load(text)
if 'aubo_rrt_panel/RRTPanel' not in text:
    text = text.replace('Visualization Manager:',
                        '  - Class: aubo_rrt_panel/RRTPanel\n    Name: Python RRT\n'
                        'Visualization Manager:', 1)
if 'Name: RRT Start Preview' not in text:
    displays = ''
    for name, topic in [('Start', 'start'), ('Goal', 'goal')]:
        displays += f'''    - Class: moveit_rviz_plugin/RobotState
      Enabled: true
      Name: RRT {name} Preview
      Robot Description: robot_description
      Robot State Topic: /rrt_python/{topic}_state
      Robot Alpha: 0.35
      Show Highlights: true
      Visual Enabled: true
      Collision Enabled: false
      Value: true
'''
    anchor = '  Enabled: true\n  Global Options:'
    assert anchor in text
    text = text.replace(anchor, displays + anchor, 1)
after = yaml.safe_load(text)
assert before['Visualization Manager']['Views'] == after['Visualization Manager']['Views']
old_displays = before['Visualization Manager']['Displays']
assert all(display in after['Visualization Manager']['Displays'] for display in old_displays)
config.write_text(text)
print('Updated demo.launch.py, package.xml and moveit.rviz; existing scene/view preserved.')
print('Backup:', backup)
