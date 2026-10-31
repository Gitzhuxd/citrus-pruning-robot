// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__BUILDER_HPP_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aubo_rrt_interfaces
{

namespace srv
{

namespace builder
{

class Init_PreviewRRT_Request_replay_step
{
public:
  explicit Init_PreviewRRT_Request_replay_step(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request replay_step(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_replay_step_type arg)
  {
    msg_.replay_step = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_seed
{
public:
  explicit Init_PreviewRRT_Request_seed(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_replay_step seed(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_seed_type arg)
  {
    msg_.seed = std::move(arg);
    return Init_PreviewRRT_Request_replay_step(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_planning_time
{
public:
  explicit Init_PreviewRRT_Request_planning_time(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_seed planning_time(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_planning_time_type arg)
  {
    msg_.planning_time = std::move(arg);
    return Init_PreviewRRT_Request_seed(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_max_iterations
{
public:
  explicit Init_PreviewRRT_Request_max_iterations(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_planning_time max_iterations(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_max_iterations_type arg)
  {
    msg_.max_iterations = std::move(arg);
    return Init_PreviewRRT_Request_planning_time(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_collision_step
{
public:
  explicit Init_PreviewRRT_Request_collision_step(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_max_iterations collision_step(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_collision_step_type arg)
  {
    msg_.collision_step = std::move(arg);
    return Init_PreviewRRT_Request_max_iterations(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_goal_bias
{
public:
  explicit Init_PreviewRRT_Request_goal_bias(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_collision_step goal_bias(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_goal_bias_type arg)
  {
    msg_.goal_bias = std::move(arg);
    return Init_PreviewRRT_Request_collision_step(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_step_size
{
public:
  explicit Init_PreviewRRT_Request_step_size(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_goal_bias step_size(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_step_size_type arg)
  {
    msg_.step_size = std::move(arg);
    return Init_PreviewRRT_Request_goal_bias(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_goal
{
public:
  explicit Init_PreviewRRT_Request_goal(::aubo_rrt_interfaces::srv::PreviewRRT_Request & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Request_step_size goal(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return Init_PreviewRRT_Request_step_size(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

class Init_PreviewRRT_Request_start
{
public:
  Init_PreviewRRT_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PreviewRRT_Request_goal start(::aubo_rrt_interfaces::srv::PreviewRRT_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_PreviewRRT_Request_goal(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::srv::PreviewRRT_Request>()
{
  return aubo_rrt_interfaces::srv::builder::Init_PreviewRRT_Request_start();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace srv
{

namespace builder
{

class Init_PreviewRRT_Response_goal_pose
{
public:
  explicit Init_PreviewRRT_Response_goal_pose(::aubo_rrt_interfaces::srv::PreviewRRT_Response & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response goal_pose(::aubo_rrt_interfaces::srv::PreviewRRT_Response::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response msg_;
};

class Init_PreviewRRT_Response_start_pose
{
public:
  explicit Init_PreviewRRT_Response_start_pose(::aubo_rrt_interfaces::srv::PreviewRRT_Response & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Response_goal_pose start_pose(::aubo_rrt_interfaces::srv::PreviewRRT_Response::_start_pose_type arg)
  {
    msg_.start_pose = std::move(arg);
    return Init_PreviewRRT_Response_goal_pose(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response msg_;
};

class Init_PreviewRRT_Response_goal_state
{
public:
  explicit Init_PreviewRRT_Response_goal_state(::aubo_rrt_interfaces::srv::PreviewRRT_Response & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Response_start_pose goal_state(::aubo_rrt_interfaces::srv::PreviewRRT_Response::_goal_state_type arg)
  {
    msg_.goal_state = std::move(arg);
    return Init_PreviewRRT_Response_start_pose(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response msg_;
};

class Init_PreviewRRT_Response_start_state
{
public:
  explicit Init_PreviewRRT_Response_start_state(::aubo_rrt_interfaces::srv::PreviewRRT_Response & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Response_goal_state start_state(::aubo_rrt_interfaces::srv::PreviewRRT_Response::_start_state_type arg)
  {
    msg_.start_state = std::move(arg);
    return Init_PreviewRRT_Response_goal_state(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response msg_;
};

class Init_PreviewRRT_Response_message
{
public:
  explicit Init_PreviewRRT_Response_message(::aubo_rrt_interfaces::srv::PreviewRRT_Response & msg)
  : msg_(msg)
  {}
  Init_PreviewRRT_Response_start_state message(::aubo_rrt_interfaces::srv::PreviewRRT_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_PreviewRRT_Response_start_state(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response msg_;
};

class Init_PreviewRRT_Response_success
{
public:
  Init_PreviewRRT_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PreviewRRT_Response_message success(::aubo_rrt_interfaces::srv::PreviewRRT_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PreviewRRT_Response_message(msg_);
  }

private:
  ::aubo_rrt_interfaces::srv::PreviewRRT_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::srv::PreviewRRT_Response>()
{
  return aubo_rrt_interfaces::srv::builder::Init_PreviewRRT_Response_success();
}

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__BUILDER_HPP_
