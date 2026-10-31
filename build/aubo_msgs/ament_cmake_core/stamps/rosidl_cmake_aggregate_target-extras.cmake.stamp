# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target aubo_msgs::aubo_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${aubo_msgs_TARGETS}.
if(aubo_msgs_TARGETS AND NOT TARGET aubo_msgs::aubo_msgs)
  add_library(aubo_msgs::aubo_msgs INTERFACE IMPORTED)
  set_target_properties(aubo_msgs::aubo_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${aubo_msgs_TARGETS}")
endif()
