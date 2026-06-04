import rclpy
from rclpy.node import Node

class PersonNode(Node):
    def __init__(self,node_name:str, name_value: str, age_value: int) -> None:
        print("PersonNode __init__方法被调用了,添加了两个属性:name和age")
        super().__init__(node_name)
        self.name = name_value
        self.age = age_value  

    def eat(self,food_name: str):

        #print(f"{self.name},{self.age}岁,爱吃{food_name}.")
        self.get_logger().info(f"{self.name},{self.age}岁,爱吃{food_name}.")

def main():
    rclpy.init()
    node = PersonNode('zhangsan', '张三', 18)
    node.eat("回锅肉")
    rclpy.spin(node)
    rclpy.shutdown()