// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aubo_rrt_interfaces:msg/Endpoint.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__STRUCT_HPP_
#define AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__msg__Endpoint __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__msg__Endpoint __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Endpoint_
{
  using Type = Endpoint_<ContainerAllocator>;

  explicit Endpoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->name = "";
    }
  }

  explicit Endpoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->name = "";
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CURRENT =
    0u;
  static constexpr uint8_t NAMED =
    1u;
  static constexpr uint8_t POSE =
    2u;

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__msg__Endpoint
    std::shared_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__msg__Endpoint
    std::shared_ptr<aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Endpoint_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const Endpoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Endpoint_

// alias to use template instance with default allocator
using Endpoint =
  aubo_rrt_interfaces::msg::Endpoint_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Endpoint_<ContainerAllocator>::CURRENT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Endpoint_<ContainerAllocator>::NAMED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Endpoint_<ContainerAllocator>::POSE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__STRUCT_HPP_
