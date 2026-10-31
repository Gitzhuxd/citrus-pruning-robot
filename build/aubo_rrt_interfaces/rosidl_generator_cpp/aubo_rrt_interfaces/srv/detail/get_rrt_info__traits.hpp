// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__TRAITS_HPP_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_rrt_interfaces/srv/detail/get_rrt_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aubo_rrt_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRRTInfo_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRRTInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRRTInfo_Request & msg, bool use_flow_style = false)
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

}  // namespace aubo_rrt_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use aubo_rrt_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_rrt_interfaces::srv::GetRRTInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_rrt_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_rrt_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_rrt_interfaces::srv::GetRRTInfo_Request & msg)
{
  return aubo_rrt_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_rrt_interfaces::srv::GetRRTInfo_Request>()
{
  return "aubo_rrt_interfaces::srv::GetRRTInfo_Request";
}

template<>
inline const char * name<aubo_rrt_interfaces::srv::GetRRTInfo_Request>()
{
  return "aubo_rrt_interfaces/srv/GetRRTInfo_Request";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::srv::GetRRTInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<aubo_rrt_interfaces::srv::GetRRTInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<aubo_rrt_interfaces::srv::GetRRTInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"
// Member 'current_state'
#include "moveit_msgs/msg/detail/robot_state__traits.hpp"

namespace aubo_rrt_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRRTInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ready
  {
    out << "ready: ";
    rosidl_generator_traits::value_to_yaml(msg.ready, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: named_states
  {
    if (msg.named_states.size() == 0) {
      out << "named_states: []";
    } else {
      out << "named_states: [";
      size_t pending_items = msg.named_states.size();
      for (auto item : msg.named_states) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: current_pose
  {
    out << "current_pose: ";
    to_flow_style_yaml(msg.current_pose, out);
    out << ", ";
  }

  // member: current_state
  {
    out << "current_state: ";
    to_flow_style_yaml(msg.current_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRRTInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ready: ";
    rosidl_generator_traits::value_to_yaml(msg.ready, out);
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

  // member: named_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.named_states.size() == 0) {
      out << "named_states: []\n";
    } else {
      out << "named_states:\n";
      for (auto item : msg.named_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_block_style_yaml(msg.current_pose, out, indentation + 2);
  }

  // member: current_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_state:\n";
    to_block_style_yaml(msg.current_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRRTInfo_Response & msg, bool use_flow_style = false)
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

}  // namespace aubo_rrt_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use aubo_rrt_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_rrt_interfaces::srv::GetRRTInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_rrt_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_rrt_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_rrt_interfaces::srv::GetRRTInfo_Response & msg)
{
  return aubo_rrt_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_rrt_interfaces::srv::GetRRTInfo_Response>()
{
  return "aubo_rrt_interfaces::srv::GetRRTInfo_Response";
}

template<>
inline const char * name<aubo_rrt_interfaces::srv::GetRRTInfo_Response>()
{
  return "aubo_rrt_interfaces/srv/GetRRTInfo_Response";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::srv::GetRRTInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_rrt_interfaces::srv::GetRRTInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_rrt_interfaces::srv::GetRRTInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_rrt_interfaces::srv::GetRRTInfo>()
{
  return "aubo_rrt_interfaces::srv::GetRRTInfo";
}

template<>
inline const char * name<aubo_rrt_interfaces::srv::GetRRTInfo>()
{
  return "aubo_rrt_interfaces/srv/GetRRTInfo";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::srv::GetRRTInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_rrt_interfaces::srv::GetRRTInfo_Request>::value &&
    has_fixed_size<aubo_rrt_interfaces::srv::GetRRTInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_rrt_interfaces::srv::GetRRTInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_rrt_interfaces::srv::GetRRTInfo_Request>::value &&
    has_bounded_size<aubo_rrt_interfaces::srv::GetRRTInfo_Response>::value
  >
{
};

template<>
struct is_service<aubo_rrt_interfaces::srv::GetRRTInfo>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_rrt_interfaces::srv::GetRRTInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_rrt_interfaces::srv::GetRRTInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__TRAITS_HPP_
