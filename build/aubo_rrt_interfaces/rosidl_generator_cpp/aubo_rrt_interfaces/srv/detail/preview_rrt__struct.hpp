// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__STRUCT_HPP_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'start'
// Member 'goal'
#include "aubo_rrt_interfaces/msg/detail/endpoint__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Request __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Request __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PreviewRRT_Request_
{
  using Type = PreviewRRT_Request_<ContainerAllocator>;

  explicit PreviewRRT_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start(_init),
    goal(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->step_size = 0.0;
      this->goal_bias = 0.0;
      this->collision_step = 0.0;
      this->max_iterations = 0l;
      this->planning_time = 0.0;
      this->seed = 0l;
      this->replay_step = 0.0;
    }
  }

  explicit PreviewRRT_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start(_alloc, _init),
    goal(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->step_size = 0.0;
      this->goal_bias = 0.0;
      this->collision_step = 0.0;
      this->max_iterations = 0l;
      this->planning_time = 0.0;
      this->seed = 0l;
      this->replay_step = 0.0;
    }
  }

  // field types and members
  using _start_type =
    aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>;
  _start_type start;
  using _goal_type =
    aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator>;
  _goal_type goal;
  using _step_size_type =
    double;
  _step_size_type step_size;
  using _goal_bias_type =
    double;
  _goal_bias_type goal_bias;
  using _collision_step_type =
    double;
  _collision_step_type collision_step;
  using _max_iterations_type =
    int32_t;
  _max_iterations_type max_iterations;
  using _planning_time_type =
    double;
  _planning_time_type planning_time;
  using _seed_type =
    int32_t;
  _seed_type seed;
  using _replay_step_type =
    double;
  _replay_step_type replay_step;

  // setters for named parameter idiom
  Type & set__start(
    const aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> & _arg)
  {
    this->start = _arg;
    return *this;
  }
  Type & set__goal(
    const aubo_rrt_interfaces::msg::Endpoint_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }
  Type & set__step_size(
    const double & _arg)
  {
    this->step_size = _arg;
    return *this;
  }
  Type & set__goal_bias(
    const double & _arg)
  {
    this->goal_bias = _arg;
    return *this;
  }
  Type & set__collision_step(
    const double & _arg)
  {
    this->collision_step = _arg;
    return *this;
  }
  Type & set__max_iterations(
    const int32_t & _arg)
  {
    this->max_iterations = _arg;
    return *this;
  }
  Type & set__planning_time(
    const double & _arg)
  {
    this->planning_time = _arg;
    return *this;
  }
  Type & set__seed(
    const int32_t & _arg)
  {
    this->seed = _arg;
    return *this;
  }
  Type & set__replay_step(
    const double & _arg)
  {
    this->replay_step = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Request
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Request
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PreviewRRT_Request_ & other) const
  {
    if (this->start != other.start) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    if (this->step_size != other.step_size) {
      return false;
    }
    if (this->goal_bias != other.goal_bias) {
      return false;
    }
    if (this->collision_step != other.collision_step) {
      return false;
    }
    if (this->max_iterations != other.max_iterations) {
      return false;
    }
    if (this->planning_time != other.planning_time) {
      return false;
    }
    if (this->seed != other.seed) {
      return false;
    }
    if (this->replay_step != other.replay_step) {
      return false;
    }
    return true;
  }
  bool operator!=(const PreviewRRT_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PreviewRRT_Request_

// alias to use template instance with default allocator
using PreviewRRT_Request =
  aubo_rrt_interfaces::srv::PreviewRRT_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'start_state'
// Member 'goal_state'
#include "moveit_msgs/msg/detail/robot_state__struct.hpp"
// Member 'start_pose'
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Response __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Response __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PreviewRRT_Response_
{
  using Type = PreviewRRT_Response_<ContainerAllocator>;

  explicit PreviewRRT_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_state(_init),
    goal_state(_init),
    start_pose(_init),
    goal_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit PreviewRRT_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    start_state(_alloc, _init),
    goal_state(_alloc, _init),
    start_pose(_alloc, _init),
    goal_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _start_state_type =
    moveit_msgs::msg::RobotState_<ContainerAllocator>;
  _start_state_type start_state;
  using _goal_state_type =
    moveit_msgs::msg::RobotState_<ContainerAllocator>;
  _goal_state_type goal_state;
  using _start_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _start_pose_type start_pose;
  using _goal_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _goal_pose_type goal_pose;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__start_state(
    const moveit_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->start_state = _arg;
    return *this;
  }
  Type & set__goal_state(
    const moveit_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->goal_state = _arg;
    return *this;
  }
  Type & set__start_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->start_pose = _arg;
    return *this;
  }
  Type & set__goal_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->goal_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Response
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__srv__PreviewRRT_Response
    std::shared_ptr<aubo_rrt_interfaces::srv::PreviewRRT_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PreviewRRT_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->start_state != other.start_state) {
      return false;
    }
    if (this->goal_state != other.goal_state) {
      return false;
    }
    if (this->start_pose != other.start_pose) {
      return false;
    }
    if (this->goal_pose != other.goal_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const PreviewRRT_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PreviewRRT_Response_

// alias to use template instance with default allocator
using PreviewRRT_Response =
  aubo_rrt_interfaces::srv::PreviewRRT_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aubo_rrt_interfaces

namespace aubo_rrt_interfaces
{

namespace srv
{

struct PreviewRRT
{
  using Request = aubo_rrt_interfaces::srv::PreviewRRT_Request;
  using Response = aubo_rrt_interfaces::srv::PreviewRRT_Response;
};

}  // namespace srv

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__STRUCT_HPP_
