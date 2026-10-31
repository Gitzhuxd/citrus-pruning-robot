// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aubo_msgs:srv/JsonRpc.idl
// generated code does not contain a copyright notice

#ifndef AUBO_MSGS__SRV__DETAIL__JSON_RPC__BUILDER_HPP_
#define AUBO_MSGS__SRV__DETAIL__JSON_RPC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aubo_msgs/srv/detail/json_rpc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aubo_msgs
{

namespace srv
{

namespace builder
{

class Init_JsonRpc_Request_params
{
public:
  explicit Init_JsonRpc_Request_params(::aubo_msgs::srv::JsonRpc_Request & msg)
  : msg_(msg)
  {}
  ::aubo_msgs::srv::JsonRpc_Request params(::aubo_msgs::srv::JsonRpc_Request::_params_type arg)
  {
    msg_.params = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_msgs::srv::JsonRpc_Request msg_;
};

class Init_JsonRpc_Request_func
{
public:
  explicit Init_JsonRpc_Request_func(::aubo_msgs::srv::JsonRpc_Request & msg)
  : msg_(msg)
  {}
  Init_JsonRpc_Request_params func(::aubo_msgs::srv::JsonRpc_Request::_func_type arg)
  {
    msg_.func = std::move(arg);
    return Init_JsonRpc_Request_params(msg_);
  }

private:
  ::aubo_msgs::srv::JsonRpc_Request msg_;
};

class Init_JsonRpc_Request_cls
{
public:
  Init_JsonRpc_Request_cls()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JsonRpc_Request_func cls(::aubo_msgs::srv::JsonRpc_Request::_cls_type arg)
  {
    msg_.cls = std::move(arg);
    return Init_JsonRpc_Request_func(msg_);
  }

private:
  ::aubo_msgs::srv::JsonRpc_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_msgs::srv::JsonRpc_Request>()
{
  return aubo_msgs::srv::builder::Init_JsonRpc_Request_cls();
}

}  // namespace aubo_msgs


namespace aubo_msgs
{

namespace srv
{

namespace builder
{

class Init_JsonRpc_Response_error
{
public:
  explicit Init_JsonRpc_Response_error(::aubo_msgs::srv::JsonRpc_Response & msg)
  : msg_(msg)
  {}
  ::aubo_msgs::srv::JsonRpc_Response error(::aubo_msgs::srv::JsonRpc_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_msgs::srv::JsonRpc_Response msg_;
};

class Init_JsonRpc_Response_result
{
public:
  Init_JsonRpc_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JsonRpc_Response_error result(::aubo_msgs::srv::JsonRpc_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_JsonRpc_Response_error(msg_);
  }

private:
  ::aubo_msgs::srv::JsonRpc_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_msgs::srv::JsonRpc_Response>()
{
  return aubo_msgs::srv::builder::Init_JsonRpc_Response_result();
}

}  // namespace aubo_msgs

#endif  // AUBO_MSGS__SRV__DETAIL__JSON_RPC__BUILDER_HPP_
