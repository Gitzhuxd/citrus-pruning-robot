"""Start only the new test backend, keeping existing MoveIt and RViz alive."""
from pathlib import Path
import os
import signal
import subprocess
import time

output = Path('/home/zhuxd/aubo_ws/rrt_results/panel_verification')
output.mkdir(parents=True, exist_ok=True)
old_pid = 19471
cmdline = Path(f'/proc/{old_pid}/cmdline')
if cmdline.exists() and b'/lib/aubo_rrt_python/rrt_demo\0' in cmdline.read_bytes():
    os.kill(old_pid, signal.SIGINT)
    time.sleep(0.5)
pidfile = output / 'server.pid'
if pidfile.exists():
    pid = int(pidfile.read_text())
    cmdline = Path(f'/proc/{pid}/cmdline')
    if cmdline.exists() and b'aubo_rrt_python.rrt_server' in cmdline.read_bytes():
        os.kill(pid, signal.SIGINT)
        time.sleep(1.0)
with (output / 'server.log').open('w') as log:
    process = subprocess.Popen(
        ['python3', '-m', 'aubo_rrt_python.rrt_server'], stdin=subprocess.DEVNULL,
        stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
pidfile.write_text(str(process.pid))
time.sleep(3)
if process.poll() is not None:
    raise RuntimeError('Backend exited; inspect panel_verification/server.log')
print('Started RRT backend:', process.pid)
