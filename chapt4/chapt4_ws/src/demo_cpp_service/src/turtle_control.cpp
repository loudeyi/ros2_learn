#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include "chapt4_interfaces/srv/partol.hpp"

using Partol = chapt4_interfaces::srv::Partol;

class TurtleController: public rclcpp::Node
{
public:
    TurtleController() : Node("turtle_controller")
    {   
        partol_service_ = this->create_service<Partol>("partol",[&](const 
        Partol::Request::SharedPtr request,Partol::Response::SharedPtr response) -> void {
            if(
                (0<request->target_x&&request->target_x<12.0f)&&
                (0<request->target_y&&request->target_y<12.0f)
        ){
            this->target_x_ = request->target_x;
            this->target_y_ = request->target_y;
            response->result = Partol::Response::SUCCESS;
        }else{
            response->result = Partol::Response::FAIL;
        }
        });
        velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>
            ("/turtle1/cmd_vel", 10);
        pose_subscriber_ = this->create_subscription<turtlesim::msg::Pose>
            ("/turtle1/pose", 10, 
            std::bind(&TurtleController::on_pose_received_, this, std::placeholders::_1));
    }
private:
    void on_pose_received_(const turtlesim::msg::Pose::SharedPtr pose){
    auto message = geometry_msgs::msg::Twist();
    // 1.记录当前位置
    double current_x = pose->x;
    double current_y = pose->y;
    RCLCPP_INFO(this->get_logger(),"当前位置x=%f,y=%f",current_x,current_y);

    // 2.当前海龟和目标位置之间的距离差和角度差
    double distance = 
    std::sqrt((target_x_- current_x)*(target_x_- current_x)+
              (target_y_- current_y)*(target_y_- current_y));
    double angle = std::atan2(target_y_- current_y,target_x_- current_x) - pose->theta;

    // 3.控制策略
    if (distance>0.1){
        if (fabs(angle)>0.2)
        {
            message.angular.z = fabs(angle);
        }else{
            //通过比例控制器计算输出速度
            message.linear.x = k_*distance;
        }
    }

        // 4.限制线速度最大值
        if(message.linear.x > max_speed_)
        {
            message.linear.x = max_speed_;
        }
        velocity_publisher_->publish(message);
    }


private:
    rclcpp::Service<Partol>::SharedPtr partol_service_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_subscriber_; //订阅者的智能指针
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;   //发布者智能指针
    double target_x_{1.0};
    double target_y_{1.0};
    double k_{1.0}; //比例系数
    double max_speed_{3.0}; //最大速度
};



int main(int argc,char  **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<TurtleController>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return(0);
}