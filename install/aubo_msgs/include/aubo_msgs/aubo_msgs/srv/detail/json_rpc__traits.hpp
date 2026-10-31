// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_msgs:srv/JsonRpc.idl
// generated code does not contain a copyright notice

#ifndef AUBO_MSGS__SRV__DETAIL__JSON_RPC__TRAITS_HPP_
#define AUBO_MSGS__SRV__DETAIL__JSON_RPC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_msgs/srv/detail/json_rpc__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const JsonRpc_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cls
  {
    out << "cls: ";
    rosidl_generator_traits::value_to_yaml(msg.cls, out);
    out << ", ";
  }

  // member: func
  {
    out << "func: ";
    rosidl_generator_traits::value_to_yaml(msg.func, out);
    out << ", ";
  }

  // member: params
  {
    out << "params: ";
    rosidl_generator_traits::value_to_yaml(msg.params, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JsonRpc_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cls
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cls: ";
    rosidl_generator_traits::value_to_yaml(msg.cls, out);
    out << "\n";
  }

  // member: func
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "func: ";
    rosidl_generator_traits::value_to_yaml(msg.func, out);
    out << "\n";
  }

  // member: params
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "params: ";
    rosidl_generator_traits::value_to_yaml(msg.params, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JsonRpc_Request & msg, bool use_flow_style = false)
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

}  // namespace aubo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_msgs::srv::JsonRpc_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_msgs::srv::JsonRpc_Request & msg)
{
  return aubo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_msgs::srv::JsonRpc_Request>()
{
  return "aubo_msgs::srv::JsonRpc_Request";
}

template<>
inline const char * name<aubo_msgs::srv::JsonRpc_Request>()
{
  return "aubo_msgs/srv/JsonRpc_Request";
}

template<>
struct has_fixed_size<aubo_msgs::srv::JsonRpc_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_msgs::srv::JsonRpc_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_msgs::srv::JsonRpc_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace aubo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const JsonRpc_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JsonRpc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JsonRpc_Response & msg, bool use_flow_style = false)
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

}  // namespace aubo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_msgs::srv::JsonRpc_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_msgs::srv::JsonRpc_Response & msg)
{
  return aubo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_msgs::srv::JsonRpc_Response>()
{
  return "aubo_msgs::srv::JsonRpc_Response";
}

template<>
inline const char * name<aubo_msgs::srv::JsonRpc_Response>()
{
  return "aubo_msgs/srv/JsonRpc_Response";
}

template<>
struct has_fixed_size<aubo_msgs::srv::JsonRpc_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_msgs::srv::JsonRpc_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_msgs::srv::JsonRpc_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_msgs::srv::JsonRpc>()
{
  return "aubo_msgs::srv::JsonRpc";
}

template<>
inline const char * name<aubo_msgs::srv::JsonRpc>()
{
  return "aubo_msgs/srv/JsonRpc";
}

template<>
struct has_fixed_size<aubo_msgs::srv::JsonRpc>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_msgs::srv::JsonRpc_Request>::value &&
    has_fixed_size<aubo_msgs::srv::JsonRpc_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_msgs::srv::JsonRpc>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_msgs::srv::JsonRpc_Request>::value &&
    has_bounded_size<aubo_msgs::srv::JsonRpc_Response>::value
  >
{
};

template<>
struct is_service<aubo_msgs::srv::JsonRpc>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_msgs::srv::JsonRpc_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_msgs::srv::JsonRpc_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUBO_MSGS__SRV__DETAIL__JSON_RPC__TRAITS_HPP_
