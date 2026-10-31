// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_dashboard_msgs:srv/GetSafetyMode.idl
// generated code does not contain a copyright notice

#ifndef AUBO_DASHBOARD_MSGS__SRV__DETAIL__GET_SAFETY_MODE__TRAITS_HPP_
#define AUBO_DASHBOARD_MSGS__SRV__DETAIL__GET_SAFETY_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_dashboard_msgs/srv/detail/get_safety_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_dashboard_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSafetyMode_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSafetyMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSafetyMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::srv::GetSafetyMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::srv::GetSafetyMode_Request & msg)
{
  return aubo_dashboard_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::srv::GetSafetyMode_Request>()
{
  return "aubo_dashboard_msgs::srv::GetSafetyMode_Request";
}

template<>
inline const char * name<aubo_dashboard_msgs::srv::GetSafetyMode_Request>()
{
  return "aubo_dashboard_msgs/srv/GetSafetyMode_Request";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::srv::GetSafetyMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::srv::GetSafetyMode_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aubo_dashboard_msgs::srv::GetSafetyMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'safety_mode'
#include "aubo_dashboard_msgs/msg/detail/safety_mode__traits.hpp"

namespace aubo_dashboard_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSafetyMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: safety_mode
  {
    out << "safety_mode: ";
    to_flow_style_yaml(msg.safety_mode, out);
    out << ", ";
  }

  // member: answer
  {
    out << "answer: ";
    rosidl_generator_traits::value_to_yaml(msg.answer, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSafetyMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: safety_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safety_mode:\n";
    to_block_style_yaml(msg.safety_mode, out, indentation + 2);
  }

  // member: answer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "answer: ";
    rosidl_generator_traits::value_to_yaml(msg.answer, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSafetyMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::srv::GetSafetyMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::srv::GetSafetyMode_Response & msg)
{
  return aubo_dashboard_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::srv::GetSafetyMode_Response>()
{
  return "aubo_dashboard_msgs::srv::GetSafetyMode_Response";
}

template<>
inline const char * name<aubo_dashboard_msgs::srv::GetSafetyMode_Response>()
{
  return "aubo_dashboard_msgs/srv/GetSafetyMode_Response";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::srv::GetSafetyMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::srv::GetSafetyMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_dashboard_msgs::srv::GetSafetyMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_dashboard_msgs::srv::GetSafetyMode>()
{
  return "aubo_dashboard_msgs::srv::GetSafetyMode";
}

template<>
inline const char * name<aubo_dashboard_msgs::srv::GetSafetyMode>()
{
  return "aubo_dashboard_msgs/srv/GetSafetyMode";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::srv::GetSafetyMode>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_dashboard_msgs::srv::GetSafetyMode_Request>::value &&
    has_fixed_size<aubo_dashboard_msgs::srv::GetSafetyMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_dashboard_msgs::srv::GetSafetyMode>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_dashboard_msgs::srv::GetSafetyMode_Request>::value &&
    has_bounded_size<aubo_dashboard_msgs::srv::GetSafetyMode_Response>::value
  >
{
};

template<>
struct is_service<aubo_dashboard_msgs::srv::GetSafetyMode>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_dashboard_msgs::srv::GetSafetyMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_dashboard_msgs::srv::GetSafetyMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUBO_DASHBOARD_MSGS__SRV__DETAIL__GET_SAFETY_MODE__TRAITS_HPP_
