// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aubo_rrt_interfaces/srv/detail/preview_rrt__rosidl_typesupport_introspection_c.h"
#include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aubo_rrt_interfaces/srv/detail/preview_rrt__functions.h"
#include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.h"


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

void aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__srv__PreviewRRT_Request__init(message_memory);
}

void aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_member_array[9] = {
  {
    "start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, start),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, goal),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, step_size),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, goal_bias),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, collision_step),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, max_iterations),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, planning_time),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, seed),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Request, replay_step),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_members = {
  "aubo_rrt_interfaces__srv",  // message namespace
  "PreviewRRT_Request",  // message name
  9,  // number of fields
  sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Request),
  aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_member_array,  // message members
  aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT_Request)() {
  aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, msg, Endpoint)();
  aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, msg, Endpoint)();
  if (!aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__srv__PreviewRRT_Request__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/srv/detail/preview_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/preview_rrt__functions.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `start_state`
// Member `goal_state`
#include "moveit_msgs/msg/robot_state.h"
// Member `start_state`
// Member `goal_state`
#include "moveit_msgs/msg/detail/robot_state__rosidl_typesupport_introspection_c.h"
// Member `start_pose`
// Member `goal_pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `start_pose`
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__srv__PreviewRRT_Response__init(message_memory);
}

void aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_member_array[6] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Response, success),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Response, start_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Response, goal_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Response, start_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__PreviewRRT_Response, goal_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_members = {
  "aubo_rrt_interfaces__srv",  // message namespace
  "PreviewRRT_Response",  // message name
  6,  // number of fields
  sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Response),
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_member_array,  // message members
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT_Response)() {
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, RobotState)();
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, RobotState)();
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__srv__PreviewRRT_Response__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/preview_rrt__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_members = {
  "aubo_rrt_interfaces__srv",  // service namespace
  "PreviewRRT",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_Request_message_type_support_handle,
  NULL  // response message
  // aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_Response_message_type_support_handle
};

static rosidl_service_type_support_t aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_type_support_handle = {
  0,
  &aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT)() {
  if (!aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, PreviewRRT_Response)()->data;
  }

  return &aubo_rrt_interfaces__srv__detail__preview_rrt__rosidl_typesupport_introspection_c__PreviewRRT_service_type_support_handle;
}
