"""Interact only with the verification RViz window; coordinates are window-relative."""
import ctypes as C
import ctypes.util
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time

output = Path('/home/zhuxd/aubo_ws/rrt_results/panel_verification')
pid = subprocess.check_output(['pgrep', '-u', str(os.getuid()), '-x', 'gnome-shell'], text=True).split()[0]
environment = os.environ.copy()
for item in Path(f'/proc/{pid}/environ').read_bytes().split(b'\0'):
    name, _, value = item.partition(b'=')
    if name in (b'DISPLAY', b'XAUTHORITY', b'DBUS_SESSION_BUS_ADDRESS', b'QT_QPA_PLATFORM'):
        environment[name.decode()] = value.decode()
os.environ.update({key: environment[key] for key in ('DISPLAY', 'XAUTHORITY') if key in environment})
window = int((output / 'window.id').read_text(), 16)
info = subprocess.check_output(['xwininfo', '-id', hex(window)], env=environment, text=True)
ox = int(re.search(r'Absolute upper-left X:\s+(-?\d+)', info).group(1))
oy = int(re.search(r'Absolute upper-left Y:\s+(-?\d+)', info).group(1))
x11 = C.CDLL(ctypes.util.find_library('X11'))
xtst = C.CDLL(ctypes.util.find_library('Xtst'))
x11.XOpenDisplay.argtypes = [C.c_char_p]
x11.XOpenDisplay.restype = C.c_void_p
d = x11.XOpenDisplay(None)
assert d
x11.XRaiseWindow.argtypes = [C.c_void_p, C.c_ulong]
x11.XSetInputFocus.argtypes = [C.c_void_p, C.c_ulong, C.c_int, C.c_ulong]
x11.XFlush.argtypes = [C.c_void_p]
x11.XCloseDisplay.argtypes = [C.c_void_p]
x11.XStringToKeysym.argtypes = [C.c_char_p]
x11.XStringToKeysym.restype = C.c_ulong
x11.XKeysymToKeycode.argtypes = [C.c_void_p, C.c_ulong]
x11.XKeysymToKeycode.restype = C.c_uint
xtst.XTestFakeMotionEvent.argtypes = [C.c_void_p, C.c_int, C.c_int, C.c_int, C.c_ulong]
xtst.XTestFakeButtonEvent.argtypes = [C.c_void_p, C.c_uint, C.c_int, C.c_ulong]
xtst.XTestFakeKeyEvent.argtypes = [C.c_void_p, C.c_uint, C.c_int, C.c_ulong]
x11.XRaiseWindow(d, window)
x11.XSetInputFocus(d, window, 2, 0)
x11.XFlush(d)

def move(x, y):
    xtst.XTestFakeMotionEvent(d, -1, ox + x, oy + y, 0)
    x11.XFlush(d)

def button(number, down):
    xtst.XTestFakeButtonEvent(d, number, int(down), 0)
    x11.XFlush(d)

def key(name, down):
    code = x11.XKeysymToKeycode(d, x11.XStringToKeysym(name.encode()))
    assert code
    xtst.XTestFakeKeyEvent(d, code, int(down), 0)
    x11.XFlush(d)

actions = json.loads(Path(sys.argv[1]).read_text(encoding='utf-8-sig'))
for action in actions:
    if action[0] == 'drag':
        _, x, y, ex, ey = action
        move(x, y)
        button(1, True)
        for i in range(1, 31):
            move(round(x+(ex-x)*i/30), round(y+(ey-y)*i/30))
            time.sleep(0.025)
        button(1, False)
    elif action[0] == 'click':
        move(action[1], action[2])
        button(1, True)
        button(1, False)
    elif action[0] == 'keys':
        for name in action[1:]:
            key(name, True)
        for name in reversed(action[1:]):
            key(name, False)
    elif action[0] == 'wait':
        time.sleep(action[1])
    elif action[0] == 'screenshot':
        subprocess.run(['import', '-window', hex(window), str(output / action[1])], env=environment, check=True)
    else:
        raise ValueError('Unknown action')
    time.sleep(0.15)
x11.XCloseDisplay(d)
print('Verification UI actions completed')
