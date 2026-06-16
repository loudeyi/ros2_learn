import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hzh/ros2_learn/chapt7/chapt7_ws/install/autopartol_robot'
