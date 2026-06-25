import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hzh/ros2_learn/chapt10/chapt10_ws/install/learn_executor_py'
