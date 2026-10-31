// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__BUILDER_HPP_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aubo_rrt_interfaces/srv/detail/get_rrt_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aubo_rrt_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::srv::GetRRTInfo_Request>()
{
  return ::aubo_rrt_interfaces::srv::GetRRTInfo_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRRTInfo_Response_current_state
{
public:
  explicit Init_GetRRTInfo_Response_current_state(::aubo_rrt_interfaces::srv::GetRRTInfo_Response & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::srv::GetRRTInfo_Response current_state(::aubo_rrt_interfaces::srv::GetRRTInfo_Response::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::GetRRTInfo_Response msg_;
};

class Init_GetRRTInfo_Response_current_pose
{
public:
  explicit Init_GetRRTInfo_Response_current_pose(::aubo_rrt_interfaces::srv::GetRRTInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRRTInfo_Response_current_state current_pose(::aubo_rrt_interfaces::srv::GetRRTInfo_Response::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_GetRRTInfo_Response_current_state(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::GetRRTInfo_Response msg_;
};

class Init_GetRRTInfo_Response_named_states
{
public:
  explicit Init_GetRRTInfo_Response_named_states(::aubo_rrt_interfaces::srv::GetRRTInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRRTInfo_Response_current_pose named_states(::aubo_rrt_interfaces::srv::GetRRTInfo_Response::_named_states_type arg)
  {
    msg_.named_states = std::move(arg);
    return Init_GetRRTInfo_Response_current_pose(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::GetRRTInfo_Response msg_;
};

class Init_GetRRTInfo_Response_message
{
public:
  explicit Init_GetRRTInfo_Response_message(::aubo_rrt_interfaces::srv::GetRRTInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetRRTInfo_Response_named_states message(::aubo_rrt_interfaces::srv::GetRRTInfo_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetRRTInfo_Response_named_states(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::GetRRTInfo_Response msg_;
};

class Init_GetRRTInfo_Response_ready
{
public:
  Init_GetRRTInfo_Response_ready()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRRTInfo_Response_message ready(::aubo_rrt_interfaces::srv::GetRRTInfo_Response::_ready_type arg)
  {
    msg_.ready = std::move(arg);
    return Init_GetRRTInfo_Response_message(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::GetRRTInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::srv::GetRRTInfo_Response>()
{
  return aubo_rrt_interfaces::srv::builder::Init_GetRRTInfo_Response_ready();
}

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__BUILDER_HPP_
