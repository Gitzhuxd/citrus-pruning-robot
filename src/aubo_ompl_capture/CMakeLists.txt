cmake_minimum_required(VERSION 3.16)
project(aubo_ompl_capture)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(moveit_planners_ompl REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(pluginlib REQUIRED)
find_package(ompl REQUIRED)

add_library(${PROJECT_NAME} SHARED src/capture.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp moveit_core moveit_ros_planning moveit_planners_ompl
  moveit_msgs visualization_msgs std_msgs pluginlib)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${OMPL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OMPL_LIBRARIES})
pluginlib_export_plugin_description_file(moveit_core plugins.xml)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(rclcpp moveit_core moveit_ros_planning
  moveit_planners_ompl moveit_msgs visualization_msgs std_msgs pluginlib ompl)
ament_package()
