"""开发验收辅助：使用现有 Ubuntu 桌面启动原 demo、截图和点击。"""
import ctypes
import ctypes.util
import json
import os
from pathlib import Path
import re
import signal
import subprocess
import sys
import time

output = Path('/home/zhuxd/aubo_ws/rrt_results/ompl_capture_verification')
output.mkdir(parents=True, exist_ok=True)
desktop = subprocess.check_output(['pgrep', '-u', str(os.getuid()), '-x', 'gnome-shell'], text=True).split()[0]
environment = os.environ.copy()
for entry in Path(f'/proc/{desktop}/environ').read_bytes().split(b'\0'):
    name, _, value = entry.partition(b'=')
    if name in (b'DISPLAY', b'XAUTHORITY', b'DBUS_SESSION_BUS_ADDRESS', b'QT_QPA_PLATFORM'):
        environment[name.decode()] = value.decode()
assert environment.get('DISPLAY'), '需要登录 Ubuntu 图形桌面'

mode = sys.argv[1]
if mode == 'start':
    existing = subprocess.run(['pgrep', '-u', str(os.getuid()), '-x', 'move_group'], capture_output=True)
    assert existing.returncode != 0, 'move_group 已在运行，避免重复启动'
    with (output / 'demo.log').open('w') as log:
        process = subprocess.Popen(
            ['ros2', 'launch', 'aubo_i5_scissors_moveit_config', 'demo.launch.py'],
            env=environment, stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
    (output / 'launch_pid.json').write_text(json.dumps({'pid': process.pid}))
    print('Started original demo; pid:', process.pid)
elif mode == 'stop':
    pid = json.loads((output / 'launch_pid.json').read_text())['pid']
    cmdline = Path(f'/proc/{pid}/cmdline').read_bytes().split(b'\0')
    assert b'aubo_i5_scissors_moveit_config' in cmdline and b'demo.launch.py' in cmdline
    os.killpg(pid, signal.SIGINT)
    print('Stopped validation launch:', pid)
else:
    tree = subprocess.check_output(['xwininfo', '-root', '-tree'], env=environment, text=True)
    match = re.search(r'(0x[0-9a-f]+) "[^"\n]*moveit\.rviz[^"\n]*"', tree)
    assert match, '未找到原场景 RViz 窗口'
    window = int(match.group(1), 16)
    if mode == 'screenshot':
        filename = Path(sys.argv[2]).name if len(sys.argv) > 2 else 'rviz.png'
        destination = output / filename
        subprocess.run(['import', '-window', hex(window), str(destination)], env=environment, check=True)
        print(destination)
    elif mode in ('click', 'key'):
        # 坐标来自刚刚查看的窗口截图；不改变窗口布局或系统设置。
        os.environ.update({key: environment[key] for key in ('DISPLAY', 'XAUTHORITY') if key in environment})
        x11 = ctypes.CDLL(ctypes.util.find_library('X11'))
        xtst = ctypes.CDLL(ctypes.util.find_library('Xtst'))
        x11.XOpenDisplay.restype = ctypes.c_void_p
        display = x11.XOpenDisplay(None)
        assert display
        x11.XDefaultRootWindow.argtypes = [ctypes.c_void_p]
        x11.XDefaultRootWindow.restype = ctypes.c_ulong
        x11.XFlush.argtypes = [ctypes.c_void_p]
        x11.XCloseDisplay.argtypes = [ctypes.c_void_p]
        if mode == 'click':
            x11.XTranslateCoordinates.argtypes = [ctypes.c_void_p, ctypes.c_ulong, ctypes.c_ulong,
                ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int),
                ctypes.POINTER(ctypes.c_ulong)]
            root_x, root_y, child = ctypes.c_int(), ctypes.c_int(), ctypes.c_ulong()
            x11.XTranslateCoordinates(display, window, x11.XDefaultRootWindow(display),
                int(sys.argv[2]), int(sys.argv[3]), ctypes.byref(root_x), ctypes.byref(root_y), ctypes.byref(child))
            xtst.XTestFakeMotionEvent.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_ulong]
            xtst.XTestFakeButtonEvent.argtypes = [ctypes.c_void_p, ctypes.c_uint, ctypes.c_int, ctypes.c_ulong]
            xtst.XTestFakeMotionEvent(display, -1, root_x.value, root_y.value, 0)
            xtst.XTestFakeButtonEvent(display, 1, 1, 0)
            xtst.XTestFakeButtonEvent(display, 1, 0, 0)
        else:
            x11.XStringToKeysym.argtypes = [ctypes.c_char_p]
            x11.XStringToKeysym.restype = ctypes.c_ulong
            x11.XKeysymToKeycode.argtypes = [ctypes.c_void_p, ctypes.c_ulong]
            x11.XKeysymToKeycode.restype = ctypes.c_uint
            xtst.XTestFakeKeyEvent.argtypes = [ctypes.c_void_p, ctypes.c_uint, ctypes.c_int, ctypes.c_ulong]
            for key in sys.argv[2:]:
                keycode = x11.XKeysymToKeycode(display, x11.XStringToKeysym(key.encode()))
                assert keycode
                xtst.XTestFakeKeyEvent(display, keycode, 1, 0)
                xtst.XTestFakeKeyEvent(display, keycode, 0, 0)
        x11.XFlush(display)
        x11.XCloseDisplay(display)
    else:
        raise ValueError(mode)
