# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target aubo_rrt_interfaces::aubo_rrt_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${aubo_rrt_interfaces_TARGETS}.
if(aubo_rrt_interfaces_TARGETS AND NOT TARGET aubo_rrt_interfaces::aubo_rrt_interfaces)
  add_library(aubo_rrt_interfaces::aubo_rrt_interfaces INTERFACE IMPORTED)
  set_target_properties(aubo_rrt_interfaces::aubo_rrt_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${aubo_rrt_interfaces_TARGETS}")
endif()
