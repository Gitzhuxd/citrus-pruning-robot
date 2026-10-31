cmake_minimum_required(VERSION 3.8)
project(aubo_rrt_panel)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rviz_common REQUIRED)
find_package(pluginlib REQUIRED)
find_package(aubo_rrt_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
add_library(${PROJECT_NAME} SHARED
  src/rrt_panel.cpp
  include/aubo_rrt_panel/rrt_panel.hpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(${PROJECT_NAME}
  rclcpp rclcpp_action rviz_common pluginlib
  aubo_rrt_interfaces geometry_msgs std_srvs)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
pluginlib_export_plugin_description_file(rviz_common plugins.xml)
install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
ament_export_dependencies(rviz_common)
ament_package()
