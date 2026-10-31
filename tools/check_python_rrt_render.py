"""临时打开验证窗口，截图后只结束本脚本创建的进程。"""
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import sys
import time

output = Path('/home/zhuxd/aubo_ws/rrt_results/python_verification')
output.mkdir(exist_ok=True)
pids = subprocess.check_output(['pgrep', '-u', str(os.getuid()), '-x', 'gnome-shell'], text=True).split()
assert pids, '需要已登录的 Ubuntu 图形会话'
pid = pids[0]
environment = os.environ.copy()
for item in Path(f'/proc/{pid}/environ').read_bytes().split(b'\0'):
    name, sep, value = item.partition(b'=')
    if name in (b'DISPLAY', b'XAUTHORITY', b'DBUS_SESSION_BUS_ADDRESS', b'QT_QPA_PLATFORM'):
        environment[name.decode()] = value.decode()
assert environment.get('DISPLAY'), '图形会话没有 DISPLAY'
config = output / 'rrt_visual_check.rviz'
shutil.copyfile('/home/zhuxd/aubo_ws/src/aubo_i5_scissors_moveit_config/config/moveit.rviz', config)
args = ['ros2', 'launch', 'aubo_i5_scissors_moveit_config',
        'moveit_rviz.launch.py', 'rviz_config:=' + str(config)]
rviz_log = (output / 'rviz_render.log').open('w')
demo_log = (output / 'render_demo.log').open('w')
rviz = subprocess.Popen(args, env=environment, stdout=rviz_log,
                        stderr=subprocess.STDOUT, start_new_session=True)
demo = None
try:
    window_id = None
    deadline = time.monotonic() + 30
    while time.monotonic() < deadline:
        assert rviz.poll() is None, '验证 RViz 提前退出'
        tree = subprocess.check_output(['xwininfo', '-root', '-tree'], env=environment, text=True)
        match = re.search(r'(0x[0-9a-f]+) "[^"\n]*rrt_visual_check[^"\n]*"', tree)
        if match:
            window_id = match.group(1)
            break
        time.sleep(0.5)
    assert window_id is not None, '未找到验证窗口'
    demo = subprocess.Popen([sys.executable, '-m', 'aubo_rrt_python.rrt_demo'],
                            stdout=demo_log, stderr=subprocess.STDOUT)
    deadline = time.monotonic() + 20
    while time.monotonic() < deadline:
        assert demo.poll() is None, 'RRT 节点提前退出'
        if '已发布 RViz 轨迹预览' in (output / 'render_demo.log').read_text():
            break
        time.sleep(0.5)
    else:
        raise RuntimeError('轨迹预览未在期限内发布')
    time.sleep(2)
    assert rviz.poll() is None
    subprocess.run(['import', '-window', window_id, str(output / 'rviz_python_rrt.png')],
                   env=environment, check=True, timeout=10)
    print('RViz screenshot:', output / 'rviz_python_rrt.png')
finally:
    for process in (demo, rviz):
        if process is not None and process.poll() is None:
            if process is rviz:
                os.killpg(process.pid, signal.SIGINT)
            else:
                process.send_signal(signal.SIGINT)
            try:
                process.wait(timeout=5)
            except subprocess.TimeoutExpired:
                process.terminate()
                process.wait(timeout=5)
    rviz_log.close()
    demo_log.close()
