cmake_minimum_required(VERSION 3.8)
project(aubo_rrt_interfaces)
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(moveit_msgs REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Endpoint.msg"
  "srv/GetRRTInfo.srv"
  "srv/PreviewRRT.srv"
  "action/PlanRRT.action"
  DEPENDENCIES geometry_msgs moveit_msgs)
ament_export_dependencies(rosidl_default_runtime)
ament_package()
