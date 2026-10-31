// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_dashboard_msgs:msg/ProgramState.idl
// generated code does not contain a copyright notice

#ifndef AUBO_DASHBOARD_MSGS__MSG__DETAIL__PROGRAM_STATE__TRAITS_HPP_
#define AUBO_DASHBOARD_MSGS__MSG__DETAIL__PROGRAM_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_dashboard_msgs/msg/detail/program_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_dashboard_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProgramState & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProgramState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProgramState & msg, bool use_flow_style = false)
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
  const aubo_dashboard_msgs::msg::ProgramState & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_dashboard_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_dashboard_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const aubo_dashboard_msgs::msg::ProgramState & msg)
{
  return aubo_dashboard_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_dashboard_msgs::msg::ProgramState>()
{
  return "aubo_dashboard_msgs::msg::ProgramState";
}

template<>
inline const char * name<aubo_dashboard_msgs::msg::ProgramState>()
{
  return "aubo_dashboard_msgs/msg/ProgramState";
}

template<>
struct has_fixed_size<aubo_dashboard_msgs::msg::ProgramState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_dashboard_msgs::msg::ProgramState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_dashboard_msgs::msg::ProgramState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUBO_DASHBOARD_MSGS__MSG__DETAIL__PROGRAM_STATE__TRAITS_HPP_
