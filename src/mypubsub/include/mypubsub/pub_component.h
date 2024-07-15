#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class PubComponent : public rclcpp::Node {
public:
  PubComponent(const rclcpp::NodeOptions &options);

private:
  void timer_callback();
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};
