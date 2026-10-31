// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aubo_rrt_interfaces:action/PlanRRT.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
#include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
#include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `start`
// Member `goal`
#include "aubo_rrt_interfaces/msg/endpoint.h"
// Member `start`
// Member `goal`
#include "aubo_rrt_interfaces/msg/detail/endpoint__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_Goal__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_member_array[9] = {
  {
    "start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, step_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_bias",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, goal_bias),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "collision_step",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, collision_step),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_iterations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, max_iterations),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "planning_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, planning_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "seed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, seed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "replay_step",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Goal, replay_step),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_Goal",  // message name
  9,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_Goal),
  aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Goal)() {
  aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, msg, Endpoint)();
  aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, msg, Endpoint)();
  if (!aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_Goal__rosidl_typesupport_introspection_c__PlanRRT_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `message`
// Member `output_directory`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_Result__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_member_array[7] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "output_directory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, output_directory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "iterations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, iterations),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tree_nodes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, tree_nodes),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path_nodes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, path_nodes),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "planning_seconds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Result, planning_seconds),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_Result",  // message name
  7,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_Result),
  aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Result)() {
  if (!aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_Result__rosidl_typesupport_introspection_c__PlanRRT_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `phase`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_Feedback__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_member_array[4] = {
  {
    "phase",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Feedback, phase),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "iterations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Feedback, iterations),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tree_nodes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Feedback, tree_nodes),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "elapsed_seconds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_Feedback, elapsed_seconds),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_Feedback",  // message name
  4,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_Feedback),
  aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Feedback)() {
  if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_Feedback__rosidl_typesupport_introspection_c__PlanRRT_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "aubo_rrt_interfaces/action/plan_rrt.h"
// Member `goal`
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request),
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Request)() {
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Goal)();
  if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response),
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Response)() {
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_members = {
  "aubo_rrt_interfaces__action",  // service namespace
  "PlanRRT_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal)() {
  if (!aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Response)()->data;
  }

  return &aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request),
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Request)() {
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "aubo_rrt_interfaces/action/plan_rrt.h"
// Member `result`
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response),
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Response)() {
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Result)();
  if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_members = {
  "aubo_rrt_interfaces__action",  // service namespace
  "PlanRRT_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult)() {
  if (!aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Response)()->data;
  }

  return &aubo_rrt_interfaces__action__detail__plan_rrt__rosidl_typesupport_introspection_c__PlanRRT_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "aubo_rrt_interfaces/action/plan_rrt.h"
// Member `feedback`
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(message_memory);
}

void aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_members = {
  "aubo_rrt_interfaces__action",  // message namespace
  "PlanRRT_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage),
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_member_array,  // message members
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_FeedbackMessage)() {
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Feedback)();
  if (!aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__rosidl_typesupport_introspection_c__PlanRRT_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
