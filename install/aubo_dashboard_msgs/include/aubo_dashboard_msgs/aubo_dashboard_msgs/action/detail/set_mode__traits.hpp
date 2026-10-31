// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_dashboard_msgs:action/SetMode.idl
// generated code does not contain a copyright notice

#ifndef AUBO_DASHBOARD_MSGS__ACTION__DETAIL__SET_MODE__TRAITS_HPP_
#define AUBO_DASHBOARD_MSGS__ACTION__DETAIL__SET_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_dashboard_msgs/action/detail/set_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_robot_mode
  {
    out << "target_robot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.target_robot_mode, out);
    out << ", ";
  }

  // member: stop_program
  {
    out << "stop_program: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_program, out);
    out << ", ";
  }

  // member: play_program
  {
    out << "play_program: ";
    rosidl_generator_traits::value_to_yaml(msg.play_program, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_robot_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_robot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.target_robot_mode, out);
    out << "\n";
  }

  // member: stop_program
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop_program: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_program, out);
    out << "\n";
  }

  // member: play_program
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "play_program: ";
    rosidl_generator_traits::value_to_yaml(msg.play_program, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_Goal & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_Goal>()
{
  return "aubo_dashboard_msgs::action::SetMode_Goal";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_Goal>()
{
  return "aubo_dashboard_msgs/action/SetMode_Goal";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_Result & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_Result>()
{
  return "aubo_dashboard_msgs::action::SetMode_Result";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_Result>()
{
  return "aubo_dashboard_msgs/action/SetMode_Result";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_robot_mode
  {
    out << "current_robot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_robot_mode, out);
    out << ", ";
  }

  // member: current_safety_mode
  {
    out << "current_safety_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_safety_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_robot_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_robot_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_robot_mode, out);
    out << "\n";
  }

  // member: current_safety_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_safety_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.current_safety_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_Feedback & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_Feedback>()
{
  return "aubo_dashboard_msgs::action::SetMode_Feedback";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_Feedback>()
{
  return "aubo_dashboard_msgs/action/SetMode_Feedback";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "aubo_dashboard_msgs/action/detail/set_mode__traits.hpp"

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_SendGoal_Request & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>()
{
  return "aubo_dashboard_msgs::action::SetMode_SendGoal_Request";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>()
{
  return "aubo_dashboard_msgs/action/SetMode_SendGoal_Request";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<aubo_dashboard_msgs::action::SetMode_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<aubo_dashboard_msgs::action::SetMode_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_SendGoal_Response & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>()
{
  return "aubo_dashboard_msgs::action::SetMode_SendGoal_Response";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>()
{
  return "aubo_dashboard_msgs/action/SetMode_SendGoal_Response";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_SendGoal>()
{
  return "aubo_dashboard_msgs::action::SetMode_SendGoal";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_SendGoal>()
{
  return "aubo_dashboard_msgs/action/SetMode_SendGoal";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>::value &&
    has_fixed_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>::value &&
    has_bounded_size<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<aubo_dashboard_msgs::action::SetMode_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_dashboard_msgs::action::SetMode_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_dashboard_msgs::action::SetMode_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_GetResult_Request & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_GetResult_Request>()
{
  return "aubo_dashboard_msgs::action::SetMode_GetResult_Request";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_GetResult_Request>()
{
  return "aubo_dashboard_msgs/action/SetMode_GetResult_Request";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "aubo_dashboard_msgs/action/detail/set_mode__traits.hpp"

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_GetResult_Response & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_GetResult_Response>()
{
  return "aubo_dashboard_msgs::action::SetMode_GetResult_Response";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_GetResult_Response>()
{
  return "aubo_dashboard_msgs/action/SetMode_GetResult_Response";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<aubo_dashboard_msgs::action::SetMode_Result>::value> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<aubo_dashboard_msgs::action::SetMode_Result>::value> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_GetResult>()
{
  return "aubo_dashboard_msgs::action::SetMode_GetResult";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_GetResult>()
{
  return "aubo_dashboard_msgs/action/SetMode_GetResult";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_dashboard_msgs::action::SetMode_GetResult_Request>::value &&
    has_fixed_size<aubo_dashboard_msgs::action::SetMode_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_dashboard_msgs::action::SetMode_GetResult_Request>::value &&
    has_bounded_size<aubo_dashboard_msgs::action::SetMode_GetResult_Response>::value
  >
{
};

template<>
struct is_service<aubo_dashboard_msgs::action::SetMode_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_dashboard_msgs::action::SetMode_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_dashboard_msgs::action::SetMode_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "aubo_dashboard_msgs/action/detail/set_mode__traits.hpp"

namespace aubo_dashboard_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetMode_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMode_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMode_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::action::SetMode_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::action::SetMode_FeedbackMessage & msg)
{
  return aubo_dashboard_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::action::SetMode_FeedbackMessage>()
{
  return "aubo_dashboard_msgs::action::SetMode_FeedbackMessage";
}

template<>
inline const char * name<aubo_dashboard_msgs::action::SetMode_FeedbackMessage>()
{
  return "aubo_dashboard_msgs/action/SetMode_FeedbackMessage";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::action::SetMode_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<aubo_dashboard_msgs::action::SetMode_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::action::SetMode_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<aubo_dashboard_msgs::action::SetMode_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<aubo_dashboard_msgs::action::SetMode_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<aubo_dashboard_msgs::action::SetMode>
  : std::true_type
{
};

template<>
struct is_action_goal<aubo_dashboard_msgs::action::SetMode_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<aubo_dashboard_msgs::action::SetMode_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<aubo_dashboard_msgs::action::SetMode_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // AUBO_DASHBOARD_MSGS__ACTION__DETAIL__SET_MODE__TRAITS_HPP_
