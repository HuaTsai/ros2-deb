#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class SubComponent : public rclcpp::Node {
public:
  SubComponent(const rclcpp::NodeOptions &options);

private:
  void callback(const std_msgs::msg::String &msg);
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};
