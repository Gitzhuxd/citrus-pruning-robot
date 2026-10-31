// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aubo_rrt_interfaces:msg/Endpoint.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__BUILDER_HPP_
#define AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aubo_rrt_interfaces/msg/detail/endpoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aubo_rrt_interfaces
{

namespace msg
{

namespace builder
{

class Init_Endpoint_pose
{
public:
  explicit Init_Endpoint_pose(::aubo_rrt_interfaces::msg::Endpoint & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::msg::Endpoint pose(::aubo_rrt_interfaces::msg::Endpoint::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::msg::Endpoint msg_;
};

class Init_Endpoint_name
{
public:
  explicit Init_Endpoint_name(::aubo_rrt_interfaces::msg::Endpoint & msg)
  : msg_(msg)
  {}
  Init_Endpoint_pose name(::aubo_rrt_interfaces::msg::Endpoint::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Endpoint_pose(msg_);
  }

private:
  ::aubo_rrt_interfaces::msg::Endpoint msg_;
};

class Init_Endpoint_mode
{
public:
  Init_Endpoint_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Endpoint_name mode(::aubo_rrt_interfaces::msg::Endpoint::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Endpoint_name(msg_);
  }

private:
  ::aubo_rrt_interfaces::msg::Endpoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::msg::Endpoint>()
{
  return aubo_rrt_interfaces::msg::builder::Init_Endpoint_mode();
}

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__BUILDER_HPP_
