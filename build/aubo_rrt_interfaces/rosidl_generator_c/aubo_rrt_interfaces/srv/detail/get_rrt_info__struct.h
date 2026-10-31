// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__STRUCT_H_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetRRTInfo in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__srv__GetRRTInfo_Request
{
  uint8_t structure_needs_at_least_one_member;
} aubo_rrt_interfaces__srv__GetRRTInfo_Request;

// Struct for a sequence of aubo_rrt_interfaces__srv__GetRRTInfo_Request.
typedef struct aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence
{
  aubo_rrt_interfaces__srv__GetRRTInfo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// Member 'named_states'
#include "rosidl_runtime_c/string.h"
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'current_state'
#include "moveit_msgs/msg/detail/robot_state__struct.h"

/// Struct defined in srv/GetRRTInfo in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__srv__GetRRTInfo_Response
{
  bool ready;
  rosidl_runtime_c__String message;
  rosidl_runtime_c__String__Sequence named_states;
  geometry_msgs__msg__PoseStamped current_pose;
  moveit_msgs__msg__RobotState current_state;
} aubo_rrt_interfaces__srv__GetRRTInfo_Response;

// Struct for a sequence of aubo_rrt_interfaces__srv__GetRRTInfo_Response.
typedef struct aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence
{
  aubo_rrt_interfaces__srv__GetRRTInfo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__STRUCT_H_
