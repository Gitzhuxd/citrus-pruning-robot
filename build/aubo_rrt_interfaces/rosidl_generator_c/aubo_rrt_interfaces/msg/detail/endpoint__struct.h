// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aubo_rrt_interfaces:msg/Endpoint.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__STRUCT_H_
#define AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CURRENT'.
enum
{
  aubo_rrt_interfaces__msg__Endpoint__CURRENT = 0
};

/// Constant 'NAMED'.
enum
{
  aubo_rrt_interfaces__msg__Endpoint__NAMED = 1
};

/// Constant 'POSE'.
enum
{
  aubo_rrt_interfaces__msg__Endpoint__POSE = 2
};

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/Endpoint in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__msg__Endpoint
{
  uint8_t mode;
  rosidl_runtime_c__String name;
  geometry_msgs__msg__PoseStamped pose;
} aubo_rrt_interfaces__msg__Endpoint;

// Struct for a sequence of aubo_rrt_interfaces__msg__Endpoint.
typedef struct aubo_rrt_interfaces__msg__Endpoint__Sequence
{
  aubo_rrt_interfaces__msg__Endpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__msg__Endpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__STRUCT_H_
