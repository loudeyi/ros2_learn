import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hzh/ros2_learn/chapt3/topic_ws/install/demo_python_topic'
