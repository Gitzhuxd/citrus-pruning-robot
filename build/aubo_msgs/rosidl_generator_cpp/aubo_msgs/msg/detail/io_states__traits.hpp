// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aubo_msgs:msg/IOStates.idl
// generated code does not contain a copyright notice

#ifndef AUBO_MSGS__MSG__DETAIL__IO_STATES__TRAITS_HPP_
#define AUBO_MSGS__MSG__DETAIL__IO_STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aubo_msgs/msg/detail/io_states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'digital_in_states'
// Member 'digital_out_states'
// Member 'flag_states'
#include "aubo_msgs/msg/detail/digital__traits.hpp"
// Member 'analog_in_states'
// Member 'analog_out_states'
#include "aubo_msgs/msg/detail/analog__traits.hpp"

namespace aubo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IOStates & msg,
  std::ostream & out)
{
  out << "{";
  // member: digital_in_states
  {
    if (msg.digital_in_states.size() == 0) {
      out << "digital_in_states: []";
    } else {
      out << "digital_in_states: [";
      size_t pending_items = msg.digital_in_states.size();
      for (auto item : msg.digital_in_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: digital_out_states
  {
    if (msg.digital_out_states.size() == 0) {
      out << "digital_out_states: []";
    } else {
      out << "digital_out_states: [";
      size_t pending_items = msg.digital_out_states.size();
      for (auto item : msg.digital_out_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: flag_states
  {
    if (msg.flag_states.size() == 0) {
      out << "flag_states: []";
    } else {
      out << "flag_states: [";
      size_t pending_items = msg.flag_states.size();
      for (auto item : msg.flag_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: analog_in_states
  {
    if (msg.analog_in_states.size() == 0) {
      out << "analog_in_states: []";
    } else {
      out << "analog_in_states: [";
      size_t pending_items = msg.analog_in_states.size();
      for (auto item : msg.analog_in_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: analog_out_states
  {
    if (msg.analog_out_states.size() == 0) {
      out << "analog_out_states: []";
    } else {
      out << "analog_out_states: [";
      size_t pending_items = msg.analog_out_states.size();
      for (auto item : msg.analog_out_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IOStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: digital_in_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.digital_in_states.size() == 0) {
      out << "digital_in_states: []\n";
    } else {
      out << "digital_in_states:\n";
      for (auto item : msg.digital_in_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: digital_out_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.digital_out_states.size() == 0) {
      out << "digital_out_states: []\n";
    } else {
      out << "digital_out_states:\n";
      for (auto item : msg.digital_out_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: flag_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.flag_states.size() == 0) {
      out << "flag_states: []\n";
    } else {
      out << "flag_states:\n";
      for (auto item : msg.flag_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: analog_in_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.analog_in_states.size() == 0) {
      out << "analog_in_states: []\n";
    } else {
      out << "analog_in_states:\n";
      for (auto item : msg.analog_in_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: analog_out_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.analog_out_states.size() == 0) {
      out << "analog_out_states: []\n";
    } else {
      out << "analog_out_states:\n";
      for (auto item : msg.analog_out_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IOStates & msg, bool use_flow_style = false)
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

}  // namespace aubo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use aubo_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aubo_msgs::msg::IOStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  aubo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aubo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const aubo_msgs::msg::IOStates & msg)
{
  return aubo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aubo_msgs::msg::IOStates>()
{
  return "aubo_msgs::msg::IOStates";
}

template<>
inline const char * name<aubo_msgs::msg::IOStates>()
{
  return "aubo_msgs/msg/IOStates";
}

template<>
struct has_fixed_size<aubo_msgs::msg::IOStates>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aubo_msgs::msg::IOStates>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aubo_msgs::msg::IOStates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUBO_MSGS__MSG__DETAIL__IO_STATES__TRAITS_HPP_
