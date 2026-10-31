// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from aubo_msgs:srv/JsonRpc.idl
// generated code does not contain a copyright notice
#include "aubo_msgs/srv/detail/json_rpc__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "aubo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "aubo_msgs/srv/detail/json_rpc__struct.h"
#include "aubo_msgs/srv/detail/json_rpc__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // cls, func, params
#include "rosidl_runtime_c/string_functions.h"  // cls, func, params

// forward declare type support functions


using _JsonRpc_Request__ros_msg_type = aubo_msgs__srv__JsonRpc_Request;

static bool _JsonRpc_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _JsonRpc_Request__ros_msg_type * ros_message = static_cast<const _JsonRpc_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: cls
  {
    const rosidl_runtime_c__String * str = &ros_message->cls;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: func
  {
    const rosidl_runtime_c__String * str = &ros_message->func;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: params
  {
    const rosidl_runtime_c__String * str = &ros_message->params;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _JsonRpc_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _JsonRpc_Request__ros_msg_type * ros_message = static_cast<_JsonRpc_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: cls
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->cls.data) {
      rosidl_runtime_c__String__init(&ros_message->cls);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->cls,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'cls'\n");
      return false;
    }
  }

  // Field name: func
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->func.data) {
      rosidl_runtime_c__String__init(&ros_message->func);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->func,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'func'\n");
      return false;
    }
  }

  // Field name: params
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->params.data) {
      rosidl_runtime_c__String__init(&ros_message->params);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->params,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'params'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_aubo_msgs
size_t get_serialized_size_aubo_msgs__srv__JsonRpc_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JsonRpc_Request__ros_msg_type * ros_message = static_cast<const _JsonRpc_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name cls
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cls.size + 1);
  // field.name func
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->func.size + 1);
  // field.name params
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->params.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _JsonRpc_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_aubo_msgs__srv__JsonRpc_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_aubo_msgs
size_t max_serialized_size_aubo_msgs__srv__JsonRpc_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: cls
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: func
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: params
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = aubo_msgs__srv__JsonRpc_Request;
    is_plain =
      (
      offsetof(DataType, params) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _JsonRpc_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_aubo_msgs__srv__JsonRpc_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_JsonRpc_Request = {
  "aubo_msgs::srv",
  "JsonRpc_Request",
  _JsonRpc_Request__cdr_serialize,
  _JsonRpc_Request__cdr_deserialize,
  _JsonRpc_Request__get_serialized_size,
  _JsonRpc_Request__max_serialized_size
};

static rosidl_message_type_support_t _JsonRpc_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JsonRpc_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_msgs, srv, JsonRpc_Request)() {
  return &_JsonRpc_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "aubo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "aubo_msgs/srv/detail/json_rpc__struct.h"
// already included above
// #include "aubo_msgs/srv/detail/json_rpc__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // error, result
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // error, result

// forward declare type support functions


using _JsonRpc_Response__ros_msg_type = aubo_msgs__srv__JsonRpc_Response;

static bool _JsonRpc_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _JsonRpc_Response__ros_msg_type * ros_message = static_cast<const _JsonRpc_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    const rosidl_runtime_c__String * str = &ros_message->result;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: error
  {
    const rosidl_runtime_c__String * str = &ros_message->error;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _JsonRpc_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _JsonRpc_Response__ros_msg_type * ros_message = static_cast<_JsonRpc_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->result.data) {
      rosidl_runtime_c__String__init(&ros_message->result);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->result,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'result'\n");
      return false;
    }
  }

  // Field name: error
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->error.data) {
      rosidl_runtime_c__String__init(&ros_message->error);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->error,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'error'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_aubo_msgs
size_t get_serialized_size_aubo_msgs__srv__JsonRpc_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JsonRpc_Response__ros_msg_type * ros_message = static_cast<const _JsonRpc_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->result.size + 1);
  // field.name error
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->error.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _JsonRpc_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_aubo_msgs__srv__JsonRpc_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_aubo_msgs
size_t max_serialized_size_aubo_msgs__srv__JsonRpc_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: result
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: error
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = aubo_msgs__srv__JsonRpc_Response;
    is_plain =
      (
      offsetof(DataType, error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _JsonRpc_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_aubo_msgs__srv__JsonRpc_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_JsonRpc_Response = {
  "aubo_msgs::srv",
  "JsonRpc_Response",
  _JsonRpc_Response__cdr_serialize,
  _JsonRpc_Response__cdr_deserialize,
  _JsonRpc_Response__get_serialized_size,
  _JsonRpc_Response__max_serialized_size
};

static rosidl_message_type_support_t _JsonRpc_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JsonRpc_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_msgs, srv, JsonRpc_Response)() {
  return &_JsonRpc_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "aubo_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "aubo_msgs/srv/json_rpc.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t JsonRpc__callbacks = {
  "aubo_msgs::srv",
  "JsonRpc",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_msgs, srv, JsonRpc_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_msgs, srv, JsonRpc_Response)(),
};

static rosidl_service_type_support_t JsonRpc__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &JsonRpc__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_msgs, srv, JsonRpc)() {
  return &JsonRpc__handle;
}

#if defined(__cplusplus)
}
#endif
