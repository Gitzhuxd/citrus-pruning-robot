// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aubo_msgs:srv/JsonRpc.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aubo_msgs/srv/detail/json_rpc__rosidl_typesupport_introspection_c.h"
#include "aubo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aubo_msgs/srv/detail/json_rpc__functions.h"
#include "aubo_msgs/srv/detail/json_rpc__struct.h"


// Include directives for member types
// Member `cls`
// Member `func`
// Member `params`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_msgs__srv__JsonRpc_Request__init(message_memory);
}

void aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_fini_function(void * message_memory)
{
  aubo_msgs__srv__JsonRpc_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_member_array[3] = {
  {
    "cls",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_msgs__srv__JsonRpc_Request, cls),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "func",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_msgs__srv__JsonRpc_Request, func),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "params",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_msgs__srv__JsonRpc_Request, params),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_members = {
  "aubo_msgs__srv",  // message namespace
  "JsonRpc_Request",  // message name
  3,  // number of fields
  sizeof(aubo_msgs__srv__JsonRpc_Request),
  aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_member_array,  // message members
  aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_type_support_handle = {
  0,
  &aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc_Request)() {
  if (!aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_type_support_handle.typesupport_identifier) {
    aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_msgs__srv__JsonRpc_Request__rosidl_typesupport_introspection_c__JsonRpc_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_msgs/srv/detail/json_rpc__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_msgs/srv/detail/json_rpc__functions.h"
// already included above
// #include "aubo_msgs/srv/detail/json_rpc__struct.h"


// Include directives for member types
// Member `result`
// Member `error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_msgs__srv__JsonRpc_Response__init(message_memory);
}

void aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_fini_function(void * message_memory)
{
  aubo_msgs__srv__JsonRpc_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_member_array[2] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_msgs__srv__JsonRpc_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_msgs__srv__JsonRpc_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_members = {
  "aubo_msgs__srv",  // message namespace
  "JsonRpc_Response",  // message name
  2,  // number of fields
  sizeof(aubo_msgs__srv__JsonRpc_Response),
  aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_member_array,  // message members
  aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_type_support_handle = {
  0,
  &aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc_Response)() {
  if (!aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_type_support_handle.typesupport_identifier) {
    aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_msgs__srv__JsonRpc_Response__rosidl_typesupport_introspection_c__JsonRpc_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aubo_msgs/srv/detail/json_rpc__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_members = {
  "aubo_msgs__srv",  // service namespace
  "JsonRpc",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_Request_message_type_support_handle,
  NULL  // response message
  // aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_Response_message_type_support_handle
};

static rosidl_service_type_support_t aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_type_support_handle = {
  0,
  &aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc)() {
  if (!aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_type_support_handle.typesupport_identifier) {
    aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_msgs, srv, JsonRpc_Response)()->data;
  }

  return &aubo_msgs__srv__detail__json_rpc__rosidl_typesupport_introspection_c__JsonRpc_service_type_support_handle;
}
