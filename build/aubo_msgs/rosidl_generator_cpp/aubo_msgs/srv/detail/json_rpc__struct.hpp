// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aubo_msgs:srv/JsonRpc.idl
// generated code does not contain a copyright notice

#ifndef AUBO_MSGS__SRV__DETAIL__JSON_RPC__STRUCT_HPP_
#define AUBO_MSGS__SRV__DETAIL__JSON_RPC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__aubo_msgs__srv__JsonRpc_Request __attribute__((deprecated))
#else
# define DEPRECATED__aubo_msgs__srv__JsonRpc_Request __declspec(deprecated)
#endif

namespace aubo_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct JsonRpc_Request_
{
  using Type = JsonRpc_Request_<ContainerAllocator>;

  explicit JsonRpc_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cls = "";
      this->func = "";
      this->params = "";
    }
  }

  explicit JsonRpc_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cls(_alloc),
    func(_alloc),
    params(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cls = "";
      this->func = "";
      this->params = "";
    }
  }

  // field types and members
  using _cls_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cls_type cls;
  using _func_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _func_type func;
  using _params_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _params_type params;

  // setters for named parameter idiom
  Type & set__cls(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cls = _arg;
    return *this;
  }
  Type & set__func(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->func = _arg;
    return *this;
  }
  Type & set__params(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->params = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_msgs__srv__JsonRpc_Request
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_msgs__srv__JsonRpc_Request
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JsonRpc_Request_ & other) const
  {
    if (this->cls != other.cls) {
      return false;
    }
    if (this->func != other.func) {
      return false;
    }
    if (this->params != other.params) {
      return false;
    }
    return true;
  }
  bool operator!=(const JsonRpc_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JsonRpc_Request_

// alias to use template instance with default allocator
using JsonRpc_Request =
  aubo_msgs::srv::JsonRpc_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aubo_msgs


#ifndef _WIN32
# define DEPRECATED__aubo_msgs__srv__JsonRpc_Response __attribute__((deprecated))
#else
# define DEPRECATED__aubo_msgs__srv__JsonRpc_Response __declspec(deprecated)
#endif

namespace aubo_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct JsonRpc_Response_
{
  using Type = JsonRpc_Response_<ContainerAllocator>;

  explicit JsonRpc_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
      this->error = "";
    }
  }

  explicit JsonRpc_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc),
    error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
      this->error = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_type result;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result = _arg;
    return *this;
  }
  Type & set__error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_msgs__srv__JsonRpc_Response
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_msgs__srv__JsonRpc_Response
    std::shared_ptr<aubo_msgs::srv::JsonRpc_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JsonRpc_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const JsonRpc_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JsonRpc_Response_

// alias to use template instance with default allocator
using JsonRpc_Response =
  aubo_msgs::srv::JsonRpc_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aubo_msgs

namespace aubo_msgs
{

namespace srv
{

struct JsonRpc
{
  using Request = aubo_msgs::srv::JsonRpc_Request;
  using Response = aubo_msgs::srv::JsonRpc_Response;
};

}  // namespace srv

}  // namespace aubo_msgs

#endif  // AUBO_MSGS__SRV__DETAIL__JSON_RPC__STRUCT_HPP_
