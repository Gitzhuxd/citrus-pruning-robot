// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_rrt_interfaces:msg/Endpoint.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__TRAITS_HPP_
#define AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_rrt_interfaces/msg/detail/endpoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace aubo_rrt_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Endpoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Endpoint & msg,
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

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Endpoint & msg, bool use_flow_style = false)
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

}  // namespace aubo_rrt_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use aubo_rrt_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_rrt_interfaces::msg::Endpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_rrt_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_rrt_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const aubo_rrt_interfaces::msg::Endpoint & msg)
{
  return aubo_rrt_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_rrt_interfaces::msg::Endpoint>()
{
  return "aubo_rrt_interfaces::msg::Endpoint";
}

template<>
inline const char * name<aubo_rrt_interfaces::msg::Endpoint>()
{
  return "aubo_rrt_interfaces/msg/Endpoint";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::msg::Endpoint>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_rrt_interfaces::msg::Endpoint>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_rrt_interfaces::msg::Endpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__TRAITS_HPP_
