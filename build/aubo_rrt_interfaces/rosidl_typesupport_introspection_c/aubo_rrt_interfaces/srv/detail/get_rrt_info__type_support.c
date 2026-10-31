// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aubo_rrt_interfaces/srv/detail/get_rrt_info__rosidl_typesupport_introspection_c.h"
#include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aubo_rrt_interfaces/srv/detail/get_rrt_info__functions.h"
#include "aubo_rrt_interfaces/srv/detail/get_rrt_info__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(message_memory);
}

void aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__GetRRTInfo_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_members = {
  "aubo_rrt_interfaces__srv",  // message namespace
  "GetRRTInfo_Request",  // message name
  1,  // number of fields
  sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Request),
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_member_array,  // message members
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo_Request)() {
  if (!aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__srv__GetRRTInfo_Request__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aubo_rrt_interfaces/srv/detail/get_rrt_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/get_rrt_info__functions.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/get_rrt_info__struct.h"


// Include directives for member types
// Member `message`
// Member `named_states`
#include "rosidl_runtime_c/string_functions.h"
// Member `current_pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"
// Member `current_state`
#include "moveit_msgs/msg/robot_state.h"
// Member `current_state`
#include "moveit_msgs/msg/detail/robot_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(message_memory);
}

void aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_fini_function(void * message_memory)
{
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(message_memory);
}

size_t aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__size_function__GetRRTInfo_Response__named_states(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__get_const_function__GetRRTInfo_Response__named_states(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__get_function__GetRRTInfo_Response__named_states(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__fetch_function__GetRRTInfo_Response__named_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__get_const_function__GetRRTInfo_Response__named_states(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__assign_function__GetRRTInfo_Response__named_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__get_function__GetRRTInfo_Response__named_states(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__resize_function__GetRRTInfo_Response__named_states(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_member_array[5] = {
  {
    "ready",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__GetRRTInfo_Response, ready),  // bytes offset in struct
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
    offsetof(aubo_rrt_interfaces__srv__GetRRTInfo_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "named_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__GetRRTInfo_Response, named_states),  // bytes offset in struct
    NULL,  // default value
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__size_function__GetRRTInfo_Response__named_states,  // size() function pointer
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__get_const_function__GetRRTInfo_Response__named_states,  // get_const(index) function pointer
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__get_function__GetRRTInfo_Response__named_states,  // get(index) function pointer
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__fetch_function__GetRRTInfo_Response__named_states,  // fetch(index, &value) function pointer
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__assign_function__GetRRTInfo_Response__named_states,  // assign(index, value) function pointer
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__resize_function__GetRRTInfo_Response__named_states  // resize(index) function pointer
  },
  {
    "current_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__GetRRTInfo_Response, current_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aubo_rrt_interfaces__srv__GetRRTInfo_Response, current_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_members = {
  "aubo_rrt_interfaces__srv",  // message namespace
  "GetRRTInfo_Response",  // message name
  5,  // number of fields
  sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Response),
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_member_array,  // message members
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_type_support_handle = {
  0,
  &aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo_Response)() {
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_msgs, msg, RobotState)();
  if (!aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aubo_rrt_interfaces__srv__GetRRTInfo_Response__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/get_rrt_info__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_members = {
  "aubo_rrt_interfaces__srv",  // service namespace
  "GetRRTInfo",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_Request_message_type_support_handle,
  NULL  // response message
  // aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_Response_message_type_support_handle
};

static rosidl_service_type_support_t aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_type_support_handle = {
  0,
  &aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aubo_rrt_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo)() {
  if (!aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_type_support_handle.typesupport_identifier) {
    aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, srv, GetRRTInfo_Response)()->data;
  }

  return &aubo_rrt_interfaces__srv__detail__get_rrt_info__rosidl_typesupport_introspection_c__GetRRTInfo_service_type_support_handle;
}
