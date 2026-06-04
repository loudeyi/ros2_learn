import rclpy
from rclpy.node import Node
from demo_python_pkg.person_node import PersonNode

class WriterNode(PersonNode):
    def __init__(self,nodename:str,name:str,age:int,book:str) -> None:
        print("WriterNode __init__方法被调用了,添加了两个属性:book")
        super().__init__(nodename,name,age) #调用父类的__init__方法，初始化name和age属性
        self.book = book


def main():
    rclpy.init()
    node = WriterNode('zhangsan','张三',18,'三国演义')
    node.eat("回锅肉")
    rclpy.spin(node)
    rclpy.shutdown()