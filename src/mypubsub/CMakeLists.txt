cmake_minimum_required(VERSION 3.8)
project(mypubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_library(pub_component SHARED src/pub_component.cc)
ament_target_dependencies(pub_component rclcpp rclcpp_components std_msgs)
rclcpp_components_register_node(pub_component PLUGIN PubComponent EXECUTABLE pub_node)

add_library(sub_component SHARED src/sub_component.cc)
ament_target_dependencies(sub_component rclcpp rclcpp_components std_msgs)
rclcpp_components_register_node(sub_component PLUGIN SubComponent EXECUTABLE sub_node)

install(TARGETS pub_component sub_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
