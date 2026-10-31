"""Open a separate RViz verification window in the logged-in Ubuntu desktop."""
import os
from pathlib import Path
import re
import shutil
import subprocess
import time

output = Path('/home/zhuxd/aubo_ws/rrt_results/panel_verification')
pid = subprocess.check_output(['pgrep', '-u', str(os.getuid()), '-x', 'gnome-shell'], text=True).split()[0]
environment = os.environ.copy()
for item in Path(f'/proc/{pid}/environ').read_bytes().split(b'\0'):
    name, _, value = item.partition(b'=')
    if name in (b'DISPLAY', b'XAUTHORITY', b'DBUS_SESSION_BUS_ADDRESS', b'QT_QPA_PLATFORM'):
        environment[name.decode()] = value.decode()
assert environment.get('DISPLAY'), 'No logged-in graphical session'
config = output / 'rrt_panel_check.rviz'
shutil.copyfile('/home/zhuxd/aubo_ws/src/aubo_i5_scissors_moveit_config/config/moveit.rviz', config)
with (output / 'rviz.log').open('w') as log:
    process = subprocess.Popen(
        ['ros2', 'launch', 'aubo_i5_scissors_moveit_config', 'moveit_rviz.launch.py', 'rviz_config:=' + str(config)],
        env=environment, stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True)
(output / 'rviz.pid').write_text(str(process.pid))
deadline = time.monotonic() + 30
while time.monotonic() < deadline:
    assert process.poll() is None, 'Verification RViz exited'
    tree = subprocess.check_output(['xwininfo', '-root', '-tree'], env=environment, text=True)
    match = re.search(r'(0x[0-9a-f]+) "[^"\n]*rrt_panel_check[^"\n]*"', tree)
    if match:
        window = match.group(1)
        (output / 'window.id').write_text(window)
        break
    time.sleep(0.5)
else:
    raise RuntimeError('Verification window not found')
time.sleep(4)
subprocess.run(['import', '-window', window, str(output / 'panel_initial.png')], env=environment, check=True)
print('Verification window:', window)
