// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__STRUCT_HPP_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Request __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Request __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRRTInfo_Request_
{
  using Type = GetRRTInfo_Request_<ContainerAllocator>;

  explicit GetRRTInfo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetRRTInfo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Request
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Request
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRRTInfo_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRRTInfo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRRTInfo_Request_

// alias to use template instance with default allocator
using GetRRTInfo_Request =
  aubo_rrt_interfaces::srv::GetRRTInfo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"
// Member 'current_state'
#include "moveit_msgs/msg/detail/robot_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Response __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Response __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRRTInfo_Response_
{
  using Type = GetRRTInfo_Response_<ContainerAllocator>;

  explicit GetRRTInfo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_pose(_init),
    current_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ready = false;
      this->message = "";
    }
  }

  explicit GetRRTInfo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    current_pose(_alloc, _init),
    current_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ready = false;
      this->message = "";
    }
  }

  // field types and members
  using _ready_type =
    bool;
  _ready_type ready;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _named_states_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _named_states_type named_states;
  using _current_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _current_pose_type current_pose;
  using _current_state_type =
    moveit_msgs::msg::RobotState_<ContainerAllocator>;
  _current_state_type current_state;

  // setters for named parameter idiom
  Type & set__ready(
    const bool & _arg)
  {
    this->ready = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__named_states(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->named_states = _arg;
    return *this;
  }
  Type & set__current_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->current_pose = _arg;
    return *this;
  }
  Type & set__current_state(
    const moveit_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->current_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Response
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__srv__GetRRTInfo_Response
    std::shared_ptr<aubo_rrt_interfaces::srv::GetRRTInfo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRRTInfo_Response_ & other) const
  {
    if (this->ready != other.ready) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->named_states != other.named_states) {
      return false;
    }
    if (this->current_pose != other.current_pose) {
      return false;
    }
    if (this->current_state != other.current_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRRTInfo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRRTInfo_Response_

// alias to use template instance with default allocator
using GetRRTInfo_Response =
  aubo_rrt_interfaces::srv::GetRRTInfo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aubo_rrt_interfaces

namespace aubo_rrt_interfaces
{

namespace srv
{

struct GetRRTInfo
{
  using Request = aubo_rrt_interfaces::srv::GetRRTInfo_Request;
  using Response = aubo_rrt_interfaces::srv::GetRRTInfo_Response;
};

}  // namespace srv

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__GET_RRT_INFO__STRUCT_HPP_
