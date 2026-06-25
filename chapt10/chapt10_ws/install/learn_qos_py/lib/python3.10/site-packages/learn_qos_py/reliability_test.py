import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from rclpy import qos
from rclpy.qos import QoSProfile

class OdomPublisherSubscriber(Node):
    def __init__(self):
        super().__init__("odom_publisher_subscriber")

        qos_profile = QoSProfile(depth = 10,reliability = qos.QoSReliabilityPolicy.BEST_EFFORT)

        self.odom_publisher = self.create_publisher(Odometry, "odom", qos.qos_profile_sensor_data)
        self.odom_subscriber = self.create_subscription(Odometry, "odom", self.odom_callback, qos_profile)
        self.timer = self.create_timer(1.0, self.timer_callback)

    def odom_callback(self, msg):
        self.get_logger().info("收到里程计消息")
    
    def timer_callback(self):
        odom_msg = Odometry()
        self.odom_publisher.publish(odom_msg)

def main(args=None):
    rclpy.init(args=args)
    odom_node = OdomPublisherSubscriber()
    rclpy.spin(odom_node)
    rclpy.shutdown()