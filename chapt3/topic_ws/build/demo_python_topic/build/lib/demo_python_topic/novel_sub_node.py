import espeakng
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
from queue import Queue
import threading
import time


class NovelSubNode(Node):
    def __init__(self, node_name):
        super().__init__(node_name)
        self.get_logger().info(f'{node_name},启动!')
        self.novels_queue_ = Queue() #创建队列
        self.novel_subscriber = self.create_subscription(String, 'novel', self.novel_callback, 10)
        self.speech_thread = threading.Thread(target=self.speaker_thread)
        self.speech_thread.start()
    
    def novel_callback(self, msg):
        self.novels_queue_.put(msg.data)

    def speaker_thread(self):
        speaker = espeakng.Speaker()
        speaker.voice = 'zh'

        while rclpy.ok(): #检测当前ros上下文是否正常
            if self.novels_queue_.qsize() > 0:
                text = self.novels_queue_.get()
                self.get_logger().info(f'朗读:{text}')
                speaker.say(text) #说
                speaker.wait() #等待朗读完成
            else:
                # 让当前线程休眠一段时间，避免CPU占用过高
                time.sleep(1) #休眠一秒



def main():
    rclpy.init()
    node = NovelSubNode('novel_sub')
    rclpy.spin(node)
    rclpy.shutdown()
