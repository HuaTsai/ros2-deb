from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    return LaunchDescription(
        [
            ComposableNodeContainer(
                name="pubsub_container",
                namespace="",
                package="rclcpp_components",
                executable="component_container",
                composable_node_descriptions=[
                    ComposableNode(
                        package="mypubsub", plugin="PubComponent", name="pub_component"
                    ),
                    ComposableNode(
                        package="mypubsub", plugin="SubComponent", name="sub_component"
                    ),
                ],
            ),
        ]
    )
