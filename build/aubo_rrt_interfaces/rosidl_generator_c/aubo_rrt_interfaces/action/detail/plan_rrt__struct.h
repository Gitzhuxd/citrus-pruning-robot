// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aubo_rrt_interfaces:action/PlanRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__STRUCT_H_
#define AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__STRUCT_H_

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

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_Goal
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
} aubo_rrt_interfaces__action__PlanRRT_Goal;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_Goal.
typedef struct aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// Member 'output_directory'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_Result
{
  bool success;
  rosidl_runtime_c__String message;
  rosidl_runtime_c__String output_directory;
  uint32_t iterations;
  uint32_t tree_nodes;
  uint32_t path_nodes;
  double planning_seconds;
} aubo_rrt_interfaces__action__PlanRRT_Result;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_Result.
typedef struct aubo_rrt_interfaces__action__PlanRRT_Result__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'phase'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_Feedback
{
  rosidl_runtime_c__String phase;
  uint32_t iterations;
  uint32_t tree_nodes;
  double elapsed_seconds;
} aubo_rrt_interfaces__action__PlanRRT_Feedback;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_Feedback.
typedef struct aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  aubo_rrt_interfaces__action__PlanRRT_Goal goal;
} aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request.
typedef struct aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response.
typedef struct aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} aubo_rrt_interfaces__action__PlanRRT_GetResult_Request;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_GetResult_Request.
typedef struct aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_GetResult_Response
{
  int8_t status;
  aubo_rrt_interfaces__action__PlanRRT_Result result;
} aubo_rrt_interfaces__action__PlanRRT_GetResult_Response;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_GetResult_Response.
typedef struct aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"

/// Struct defined in action/PlanRRT in the package aubo_rrt_interfaces.
typedef struct aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  aubo_rrt_interfaces__action__PlanRRT_Feedback feedback;
} aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage;

// Struct for a sequence of aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage.
typedef struct aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence
{
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__STRUCT_H_
