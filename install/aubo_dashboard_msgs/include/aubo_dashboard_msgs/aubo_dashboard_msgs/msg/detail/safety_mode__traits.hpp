// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_dashboard_msgs:msg/SafetyMode.idl
// generated code does not contain a copyright notice

#ifndef AUBO_DASHBOARD_MSGS__MSG__DETAIL__SAFETY_MODE__TRAITS_HPP_
#define AUBO_DASHBOARD_MSGS__MSG__DETAIL__SAFETY_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_dashboard_msgs/msg/detail/safety_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_dashboard_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SafetyMode & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SafetyMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SafetyMode & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace aubo_dashboard_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_dashboard_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_dashboard_msgs::msg::SafetyMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::msg::SafetyMode & msg)
{
  return aubo_dashboard_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::msg::SafetyMode>()
{
  return "aubo_dashboard_msgs::msg::SafetyMode";
}

template<>
inline const char * name<aubo_dashboard_msgs::msg::SafetyMode>()
{
  return "aubo_dashboard_msgs/msg/SafetyMode";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::msg::SafetyMode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::msg::SafetyMode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aubo_dashboard_msgs::msg::SafetyMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUBO_DASHBOARD_MSGS__MSG__DETAIL__SAFETY_MODE__TRAITS_HPP_
