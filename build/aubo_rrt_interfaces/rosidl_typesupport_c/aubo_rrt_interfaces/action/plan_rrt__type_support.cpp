// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from aubo_rrt_interfaces:action/PlanRRT.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
#include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_Goal_type_support_ids_t;

static const _PlanRRT_Goal_type_support_ids_t _PlanRRT_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_Goal_type_support_symbol_names_t _PlanRRT_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Goal)),
  }
};

typedef struct _PlanRRT_Goal_type_support_data_t
{
  void * data[2];
} _PlanRRT_Goal_type_support_data_t;

static _PlanRRT_Goal_type_support_data_t _PlanRRT_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_Goal_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_Goal)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_Result_type_support_ids_t;

static const _PlanRRT_Result_type_support_ids_t _PlanRRT_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_Result_type_support_symbol_names_t _PlanRRT_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Result)),
  }
};

typedef struct _PlanRRT_Result_type_support_data_t
{
  void * data[2];
} _PlanRRT_Result_type_support_data_t;

static _PlanRRT_Result_type_support_data_t _PlanRRT_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_Result_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_Result)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_Feedback_type_support_ids_t;

static const _PlanRRT_Feedback_type_support_ids_t _PlanRRT_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_Feedback_type_support_symbol_names_t _PlanRRT_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_Feedback)),
  }
};

typedef struct _PlanRRT_Feedback_type_support_data_t
{
  void * data[2];
} _PlanRRT_Feedback_type_support_data_t;

static _PlanRRT_Feedback_type_support_data_t _PlanRRT_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_Feedback_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_Feedback)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_SendGoal_Request_type_support_ids_t;

static const _PlanRRT_SendGoal_Request_type_support_ids_t _PlanRRT_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_SendGoal_Request_type_support_symbol_names_t _PlanRRT_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Request)),
  }
};

typedef struct _PlanRRT_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PlanRRT_SendGoal_Request_type_support_data_t;

static _PlanRRT_SendGoal_Request_type_support_data_t _PlanRRT_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_SendGoal_Request_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Request)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_SendGoal_Response_type_support_ids_t;

static const _PlanRRT_SendGoal_Response_type_support_ids_t _PlanRRT_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_SendGoal_Response_type_support_symbol_names_t _PlanRRT_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Response)),
  }
};

typedef struct _PlanRRT_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PlanRRT_SendGoal_Response_type_support_data_t;

static _PlanRRT_SendGoal_Response_type_support_data_t _PlanRRT_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_SendGoal_Response_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal_Response)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_SendGoal_type_support_ids_t;

static const _PlanRRT_SendGoal_type_support_ids_t _PlanRRT_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_SendGoal_type_support_symbol_names_t _PlanRRT_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal)),
  }
};

typedef struct _PlanRRT_SendGoal_type_support_data_t
{
  void * data[2];
} _PlanRRT_SendGoal_type_support_data_t;

static _PlanRRT_SendGoal_type_support_data_t _PlanRRT_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_SendGoal_service_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PlanRRT_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_GetResult_Request_type_support_ids_t;

static const _PlanRRT_GetResult_Request_type_support_ids_t _PlanRRT_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_GetResult_Request_type_support_symbol_names_t _PlanRRT_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Request)),
  }
};

typedef struct _PlanRRT_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PlanRRT_GetResult_Request_type_support_data_t;

static _PlanRRT_GetResult_Request_type_support_data_t _PlanRRT_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_GetResult_Request_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Request)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_GetResult_Response_type_support_ids_t;

static const _PlanRRT_GetResult_Response_type_support_ids_t _PlanRRT_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_GetResult_Response_type_support_symbol_names_t _PlanRRT_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Response)),
  }
};

typedef struct _PlanRRT_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PlanRRT_GetResult_Response_type_support_data_t;

static _PlanRRT_GetResult_Response_type_support_data_t _PlanRRT_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_GetResult_Response_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_GetResult_Response)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_GetResult_type_support_ids_t;

static const _PlanRRT_GetResult_type_support_ids_t _PlanRRT_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_GetResult_type_support_symbol_names_t _PlanRRT_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_GetResult)),
  }
};

typedef struct _PlanRRT_GetResult_type_support_data_t
{
  void * data[2];
} _PlanRRT_GetResult_type_support_data_t;

static _PlanRRT_GetResult_type_support_data_t _PlanRRT_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_GetResult_service_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PlanRRT_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_GetResult)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace aubo_rrt_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PlanRRT_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanRRT_FeedbackMessage_type_support_ids_t;

static const _PlanRRT_FeedbackMessage_type_support_ids_t _PlanRRT_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanRRT_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanRRT_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanRRT_FeedbackMessage_type_support_symbol_names_t _PlanRRT_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aubo_rrt_interfaces, action, PlanRRT_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aubo_rrt_interfaces, action, PlanRRT_FeedbackMessage)),
  }
};

typedef struct _PlanRRT_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PlanRRT_FeedbackMessage_type_support_data_t;

static _PlanRRT_FeedbackMessage_type_support_data_t _PlanRRT_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanRRT_FeedbackMessage_message_typesupport_map = {
  2,
  "aubo_rrt_interfaces",
  &_PlanRRT_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PlanRRT_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PlanRRT_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanRRT_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanRRT_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace aubo_rrt_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_FeedbackMessage)() {
  return &::aubo_rrt_interfaces::action::rosidl_typesupport_c::PlanRRT_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "aubo_rrt_interfaces/action/plan_rrt.h"
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__type_support.h"

static rosidl_action_type_support_t _aubo_rrt_interfaces__action__PlanRRT__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT)()
{
  // Thread-safe by always writing the same values to the static struct
  _aubo_rrt_interfaces__action__PlanRRT__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_SendGoal)();
  _aubo_rrt_interfaces__action__PlanRRT__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_GetResult)();
  _aubo_rrt_interfaces__action__PlanRRT__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _aubo_rrt_interfaces__action__PlanRRT__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, aubo_rrt_interfaces, action, PlanRRT_FeedbackMessage)();
  _aubo_rrt_interfaces__action__PlanRRT__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_aubo_rrt_interfaces__action__PlanRRT__typesupport_c;
}

#ifdef __cplusplus
}
#endif
