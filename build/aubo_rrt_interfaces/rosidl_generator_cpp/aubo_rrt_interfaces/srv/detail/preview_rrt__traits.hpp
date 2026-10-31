// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__TRAITS_HPP_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'start'
// Member 'goal'
#include "aubo_rrt_interfaces/msg/detail/endpoint__traits.hpp"

namespace aubo_rrt_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PreviewRRT_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    to_flow_style_yaml(msg.start, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
    out << ", ";
  }

  // member: step_size
  {
    out << "step_size: ";
    rosidl_generator_traits::value_to_yaml(msg.step_size, out);
    out << ", ";
  }

  // member: goal_bias
  {
    out << "goal_bias: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_bias, out);
    out << ", ";
  }

  // member: collision_step
  {
    out << "collision_step: ";
    rosidl_generator_traits::value_to_yaml(msg.collision_step, out);
    out << ", ";
  }

  // member: max_iterations
  {
    out << "max_iterations: ";
    rosidl_generator_traits::value_to_yaml(msg.max_iterations, out);
    out << ", ";
  }

  // member: planning_time
  {
    out << "planning_time: ";
    rosidl_generator_traits::value_to_yaml(msg.planning_time, out);
    out << ", ";
  }

  // member: seed
  {
    out << "seed: ";
    rosidl_generator_traits::value_to_yaml(msg.seed, out);
    out << ", ";
  }

  // member: replay_step
  {
    out << "replay_step: ";
    rosidl_generator_traits::value_to_yaml(msg.replay_step, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PreviewRRT_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start:\n";
    to_block_style_yaml(msg.start, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }

  // member: step_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_size: ";
    rosidl_generator_traits::value_to_yaml(msg.step_size, out);
    out << "\n";
  }

  // member: goal_bias
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_bias: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_bias, out);
    out << "\n";
  }

  // member: collision_step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "collision_step: ";
    rosidl_generator_traits::value_to_yaml(msg.collision_step, out);
    out << "\n";
  }

  // member: max_iterations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_iterations: ";
    rosidl_generator_traits::value_to_yaml(msg.max_iterations, out);
    out << "\n";
  }

  // member: planning_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "planning_time: ";
    rosidl_generator_traits::value_to_yaml(msg.planning_time, out);
    out << "\n";
  }

  // member: seed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seed: ";
    rosidl_generator_traits::value_to_yaml(msg.seed, out);
    out << "\n";
  }

  // member: replay_step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "replay_step: ";
    rosidl_generator_traits::value_to_yaml(msg.replay_step, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PreviewRRT_Request & msg, bool use_flow_style = false)
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
  const aubo_rrt_interfaces::srv::PreviewRRT_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_rrt_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_rrt_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
{
  return aubo_rrt_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_rrt_interfaces::srv::PreviewRRT_Request>()
{
  return "aubo_rrt_interfaces::srv::PreviewRRT_Request";
}

template<>
inline const char * name<aubo_rrt_interfaces::srv::PreviewRRT_Request>()
{
  return "aubo_rrt_interfaces/srv/PreviewRRT_Request";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::srv::PreviewRRT_Request>
  : std::integral_constant<bool, has_fixed_size<aubo_rrt_interfaces::msg::Endpoint>::value> {};

template<>
struct has_bounded_size<aubo_rrt_interfaces::srv::PreviewRRT_Request>
  : std::integral_constant<bool, has_bounded_size<aubo_rrt_interfaces::msg::Endpoint>::value> {};

template<>
struct is_message<aubo_rrt_interfaces::srv::PreviewRRT_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'start_state'
// Member 'goal_state'
#include "moveit_msgs/msg/detail/robot_state__traits.hpp"
// Member 'start_pose'
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace aubo_rrt_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PreviewRRT_Response & msg,
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
    out << ", ";
  }

  // member: start_state
  {
    out << "start_state: ";
    to_flow_style_yaml(msg.start_state, out);
    out << ", ";
  }

  // member: goal_state
  {
    out << "goal_state: ";
    to_flow_style_yaml(msg.goal_state, out);
    out << ", ";
  }

  // member: start_pose
  {
    out << "start_pose: ";
    to_flow_style_yaml(msg.start_pose, out);
    out << ", ";
  }

  // member: goal_pose
  {
    out << "goal_pose: ";
    to_flow_style_yaml(msg.goal_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PreviewRRT_Response & msg,
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

  // member: start_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_state:\n";
    to_block_style_yaml(msg.start_state, out, indentation + 2);
  }

  // member: goal_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_state:\n";
    to_block_style_yaml(msg.goal_state, out, indentation + 2);
  }

  // member: start_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_pose:\n";
    to_block_style_yaml(msg.start_pose, out, indentation + 2);
  }

  // member: goal_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_pose:\n";
    to_block_style_yaml(msg.goal_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PreviewRRT_Response & msg, bool use_flow_style = false)
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
  const aubo_rrt_interfaces::srv::PreviewRRT_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_rrt_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_rrt_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const aubo_rrt_interfaces::srv::PreviewRRT_Response & msg)
{
  return aubo_rrt_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_rrt_interfaces::srv::PreviewRRT_Response>()
{
  return "aubo_rrt_interfaces::srv::PreviewRRT_Response";
}

template<>
inline const char * name<aubo_rrt_interfaces::srv::PreviewRRT_Response>()
{
  return "aubo_rrt_interfaces/srv/PreviewRRT_Response";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::srv::PreviewRRT_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_rrt_interfaces::srv::PreviewRRT_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_rrt_interfaces::srv::PreviewRRT_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aubo_rrt_interfaces::srv::PreviewRRT>()
{
  return "aubo_rrt_interfaces::srv::PreviewRRT";
}

template<>
inline const char * name<aubo_rrt_interfaces::srv::PreviewRRT>()
{
  return "aubo_rrt_interfaces/srv/PreviewRRT";
}

template<>
struct has_fixed_size<aubo_rrt_interfaces::srv::PreviewRRT>
  : std::integral_constant<
    bool,
    has_fixed_size<aubo_rrt_interfaces::srv::PreviewRRT_Request>::value &&
    has_fixed_size<aubo_rrt_interfaces::srv::PreviewRRT_Response>::value
  >
{
};

template<>
struct has_bounded_size<aubo_rrt_interfaces::srv::PreviewRRT>
  : std::integral_constant<
    bool,
    has_bounded_size<aubo_rrt_interfaces::srv::PreviewRRT_Request>::value &&
    has_bounded_size<aubo_rrt_interfaces::srv::PreviewRRT_Response>::value
  >
{
};

template<>
struct is_service<aubo_rrt_interfaces::srv::PreviewRRT>
  : std::true_type
{
};

template<>
struct is_service_request<aubo_rrt_interfaces::srv::PreviewRRT_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aubo_rrt_interfaces::srv::PreviewRRT_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__TRAITS_HPP_
