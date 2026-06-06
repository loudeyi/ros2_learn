#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include "turtlesim/msg/pose.hpp"

using namespace std::chrono_literals;

class TurtleControlNode: public rclcpp::Node
{
private:
    // rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;   //发布者智能指针
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_; //订阅者的智能指针
    double target_x_{1.0};
    double target_y_{1.0};
    double k_{1.0}; //比例系数
    double max_speed_{3.0}; //最大速度

public:
    explicit TurtleControlNode(const std::string& node_name):Node(node_name)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
        subscriber_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&
        TurtleControlNode::on_pose_received,this, std::placeholders::_1));
        // timer_ = this->create_wall_timer(1000ms,std::bind(&TurtleControlNode::timer_callback,this));

    }
    
    void on_pose_received(const turtlesim::msg::Pose::SharedPtr pose) //参数：收到数据的共享指针
    {
        // 1.获取当前位置
        auto current_x_ = pose->x;
        auto current_y_ = pose->y;
        RCLCPP_INFO(get_logger(),"当前x=%f,y=%f",current_x_,current_y_);

        // 2.当前海龟和目标位置之间的距离差和角度差
        auto distance = std::sqrt(
            (target_x_-current_x_)*(target_x_-current_x_)+
            (target_y_-current_y_)*(target_y_-current_y_)
        );
        auto angle = std::atan2(target_y_-current_y_,target_x_-current_x_) - pose->theta;

        // 3.控制策略
        auto msg = geometry_msgs::msg::Twist();
        if(distance>0.1)
        {
            if(fabs(angle)>0.2){
                msg.angular.z = fabs(angle);
            }else
            {
                msg.linear.x = k_*distance;
            }
        }

        // 4.限制线速度最大值
        if(msg.linear.x > max_speed_)
        {
            msg.linear.x = max_speed_;
        }
        publisher_->publish(msg);
    }
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<TurtleControlNode>("turtle_control");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return(0);
}
