// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__STRUCT_H_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "aubo_rrt_interfaces/msg/detail/endpoint__struct.h"

/// Struct defined in srv/PreviewRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__srv__PreviewRRT_Request
{
  aubo_rrt_interfaces__msg__Endpoint start;
  aubo_rrt_interfaces__msg__Endpoint goal;
  double step_size;
  double goal_bias;
  double collision_step;
  int32_t max_iterations;
  double planning_time;
  int32_t seed;
  double replay_step;
} aubo_rrt_interfaces__srv__PreviewRRT_Request;

// Struct for a sequence of aubo_rrt_interfaces__srv__PreviewRRT_Request.
typedef struct aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence
{
  aubo_rrt_interfaces__srv__PreviewRRT_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'start_state'
// Member 'goal_state'
#include "moveit_msgs/msg/detail/robot_state__struct.h"
// Member 'start_pose'
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/PreviewRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__srv__PreviewRRT_Response
{
  bool success;
  rosidl_runtime_c__String message;
  moveit_msgs__msg__RobotState start_state;
  moveit_msgs__msg__RobotState goal_state;
  geometry_msgs__msg__PoseStamped start_pose;
  geometry_msgs__msg__PoseStamped goal_pose;
} aubo_rrt_interfaces__srv__PreviewRRT_Response;

// Struct for a sequence of aubo_rrt_interfaces__srv__PreviewRRT_Response.
typedef struct aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence
{
  aubo_rrt_interfaces__srv__PreviewRRT_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__STRUCT_H_
