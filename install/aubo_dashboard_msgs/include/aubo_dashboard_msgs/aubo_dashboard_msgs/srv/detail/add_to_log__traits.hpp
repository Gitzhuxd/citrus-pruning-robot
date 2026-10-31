// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_dashboard_msgs:srv/AddToLog.idl
// generated code does not contain a copyright notice

#ifndef AUBO_DASHBOARD_MSGS__SRV__DETAIL__ADD_TO_LOG__TRAITS_HPP_
#define AUBO_DASHBOARD_MSGS__SRV__DETAIL__ADD_TO_LOG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_dashboard_msgs/srv/detail/add_to_log__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_dashboard_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddToLog_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddToLog_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const AddToLog_Request & msg, bool use_flow_style = false)
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
  const aubo_dashboard_msgs::srv::AddToLog_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::srv::AddToLog_Request & msg)
{
  return aubo_dashboard_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::srv::AddToLog_Request>()
{
  return "aubo_dashboard_msgs::srv::AddToLog_Request";
}

template<>
inline const char * name<aubo_dashboard_msgs::srv::AddToLog_Request>()
{
  return "aubo_dashboard_msgs/srv/AddToLog_Request";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::srv::AddToLog_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::srv::AddToLog_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_dashboard_msgs::srv::AddToLog_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace aubo_dashboard_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddToLog_Response & msg,
  std::ostream & out)
{
  out << "{";
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
  const AddToLog_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const AddToLog_Response & msg, bool use_flow_style = false)
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
  const aubo_dashboard_msgs::srv::AddToLog_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::srv::AddToLog_Response & msg)
{
  return aubo_dashboard_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::srv::AddToLog_Response>()
{
  return "aubo_dashboard_msgs::srv::AddToLog_Response";
}

template<>
inline const char * name<aubo_dashboard_msgs::srv::AddToLog_Response>()
{
  return "aubo_dashboard_msgs/srv/AddToLog_Response";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::srv::AddToLog_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::srv::AddToLog_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_dashboard_msgs::srv::AddToLog_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_dashboard_msgs::srv::AddToLog>()
{
  return "aubo_dashboard_msgs::srv::AddToLog";
}

template<>
inline const char * name<aubo_dashboard_msgs::srv::AddToLog>()
{
  return "aubo_dashboard_msgs/srv/AddToLog";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::srv::AddToLog>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_dashboard_msgs::srv::AddToLog_Request>::value &&
    has_fixed_size<aubo_dashboard_msgs::srv::AddToLog_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_dashboard_msgs::srv::AddToLog>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_dashboard_msgs::srv::AddToLog_Request>::value &&
    has_bounded_size<aubo_dashboard_msgs::srv::AddToLog_Response>::value
  >
{
};

template<>
struct is_service<aubo_dashboard_msgs::srv::AddToLog>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_dashboard_msgs::srv::AddToLog_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_dashboard_msgs::srv::AddToLog_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUBO_DASHBOARD_MSGS__SRV__DETAIL__ADD_TO_LOG__TRAITS_HPP_
