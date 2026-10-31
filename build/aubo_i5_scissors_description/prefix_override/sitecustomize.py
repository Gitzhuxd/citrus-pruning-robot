import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/zhuxd/aubo_ws/install/aubo_i5_scissors_description'
