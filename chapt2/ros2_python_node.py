import rclpy
from rclpy.node import Node

def main(args=None):
    rclpy.init()
    node = Node('python_node') 
    node.get_logger().info('Hello, ROS 2 from Python!')
    node.get_logger().warn('This is a simple ROS 2 node written in Python.')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()