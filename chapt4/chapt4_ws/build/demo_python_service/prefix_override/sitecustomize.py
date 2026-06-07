import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hzh/ros2_learn/chapt4/chapt4_ws/install/demo_python_service'
