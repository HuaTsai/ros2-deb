#include <mypubsub/sub_component.h>

SubComponent::SubComponent(const rclcpp::NodeOptions &options)
    : Node("sub_component", options) {
  sub_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10,
      std::bind(&SubComponent::callback, this, std::placeholders::_1));
}

void SubComponent::callback(const std_msgs::msg::String &msg) {
  RCLCPP_INFO(this->get_logger(), "Subscribing: '%s'", msg.data.c_str());
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(SubComponent)
