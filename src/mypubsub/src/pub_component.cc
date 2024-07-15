#include <mypubsub/pub_component.h>

using namespace std::chrono_literals;

PubComponent::PubComponent(const rclcpp::NodeOptions &options)
    : Node("pub_component", options) {
  pub_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
  timer_ = this->create_wall_timer(
      1s, std::bind(&PubComponent::timer_callback, this));
}

void PubComponent::timer_callback() {
  static int count = 1;
  std_msgs::msg::String message;
  message.data = "Hello, world #" + std::to_string(count++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  pub_->publish(message);
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(PubComponent)

