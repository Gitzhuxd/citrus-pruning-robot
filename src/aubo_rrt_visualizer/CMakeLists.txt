cmake_minimum_required(VERSION 3.16)
project(aubo_rrt_visualizer)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning REQUIRED)
find_package(moveit_planners_ompl REQUIRED)
find_package(moveit_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(ompl REQUIRED)

add_executable(rrt_visualizer src/rrt_visualizer.cpp)
target_compile_features(rrt_visualizer PRIVATE cxx_std_17)
target_compile_options(rrt_visualizer PRIVATE -O2)
ament_target_dependencies(rrt_visualizer
  rclcpp
  moveit_core
  moveit_ros_planning
  moveit_planners_ompl
  moveit_msgs
  visualization_msgs
)
target_include_directories(rrt_visualizer PRIVATE ${OMPL_INCLUDE_DIRS})
target_link_libraries(rrt_visualizer ${OMPL_LIBRARIES})

install(TARGETS rrt_visualizer DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()
