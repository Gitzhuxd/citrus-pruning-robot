// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aubo_rrt_interfaces:action/PlanRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__STRUCT_HPP_
#define AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__STRUCT_HPP_

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
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Goal __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Goal __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_Goal_
{
  using Type = PlanRRT_Goal_<ContainerAllocator>;

  explicit PlanRRT_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  explicit PlanRRT_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Goal
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Goal
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_Goal_ & other) const
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
  bool operator!=(const PlanRRT_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_Goal_

// alias to use template instance with default allocator
using PlanRRT_Goal =
  aubo_rrt_interfaces::action::PlanRRT_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces


#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Result __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Result __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_Result_
{
  using Type = PlanRRT_Result_<ContainerAllocator>;

  explicit PlanRRT_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->output_directory = "";
      this->iterations = 0ul;
      this->tree_nodes = 0ul;
      this->path_nodes = 0ul;
      this->planning_seconds = 0.0;
    }
  }

  explicit PlanRRT_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    output_directory(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->output_directory = "";
      this->iterations = 0ul;
      this->tree_nodes = 0ul;
      this->path_nodes = 0ul;
      this->planning_seconds = 0.0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _output_directory_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _output_directory_type output_directory;
  using _iterations_type =
    uint32_t;
  _iterations_type iterations;
  using _tree_nodes_type =
    uint32_t;
  _tree_nodes_type tree_nodes;
  using _path_nodes_type =
    uint32_t;
  _path_nodes_type path_nodes;
  using _planning_seconds_type =
    double;
  _planning_seconds_type planning_seconds;

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
  Type & set__output_directory(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->output_directory = _arg;
    return *this;
  }
  Type & set__iterations(
    const uint32_t & _arg)
  {
    this->iterations = _arg;
    return *this;
  }
  Type & set__tree_nodes(
    const uint32_t & _arg)
  {
    this->tree_nodes = _arg;
    return *this;
  }
  Type & set__path_nodes(
    const uint32_t & _arg)
  {
    this->path_nodes = _arg;
    return *this;
  }
  Type & set__planning_seconds(
    const double & _arg)
  {
    this->planning_seconds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Result
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Result
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->output_directory != other.output_directory) {
      return false;
    }
    if (this->iterations != other.iterations) {
      return false;
    }
    if (this->tree_nodes != other.tree_nodes) {
      return false;
    }
    if (this->path_nodes != other.path_nodes) {
      return false;
    }
    if (this->planning_seconds != other.planning_seconds) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_Result_

// alias to use template instance with default allocator
using PlanRRT_Result =
  aubo_rrt_interfaces::action::PlanRRT_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces


#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Feedback __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_Feedback_
{
  using Type = PlanRRT_Feedback_<ContainerAllocator>;

  explicit PlanRRT_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->phase = "";
      this->iterations = 0ul;
      this->tree_nodes = 0ul;
      this->elapsed_seconds = 0.0;
    }
  }

  explicit PlanRRT_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : phase(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->phase = "";
      this->iterations = 0ul;
      this->tree_nodes = 0ul;
      this->elapsed_seconds = 0.0;
    }
  }

  // field types and members
  using _phase_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _phase_type phase;
  using _iterations_type =
    uint32_t;
  _iterations_type iterations;
  using _tree_nodes_type =
    uint32_t;
  _tree_nodes_type tree_nodes;
  using _elapsed_seconds_type =
    double;
  _elapsed_seconds_type elapsed_seconds;

  // setters for named parameter idiom
  Type & set__phase(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->phase = _arg;
    return *this;
  }
  Type & set__iterations(
    const uint32_t & _arg)
  {
    this->iterations = _arg;
    return *this;
  }
  Type & set__tree_nodes(
    const uint32_t & _arg)
  {
    this->tree_nodes = _arg;
    return *this;
  }
  Type & set__elapsed_seconds(
    const double & _arg)
  {
    this->elapsed_seconds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Feedback
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_Feedback
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_Feedback_ & other) const
  {
    if (this->phase != other.phase) {
      return false;
    }
    if (this->iterations != other.iterations) {
      return false;
    }
    if (this->tree_nodes != other.tree_nodes) {
      return false;
    }
    if (this->elapsed_seconds != other.elapsed_seconds) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_Feedback_

// alias to use template instance with default allocator
using PlanRRT_Feedback =
  aubo_rrt_interfaces::action::PlanRRT_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_SendGoal_Request_
{
  using Type = PlanRRT_SendGoal_Request_<ContainerAllocator>;

  explicit PlanRRT_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit PlanRRT_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const aubo_rrt_interfaces::action::PlanRRT_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_SendGoal_Request_

// alias to use template instance with default allocator
using PlanRRT_SendGoal_Request =
  aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_SendGoal_Response_
{
  using Type = PlanRRT_SendGoal_Response_<ContainerAllocator>;

  explicit PlanRRT_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PlanRRT_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_SendGoal_Response_

// alias to use template instance with default allocator
using PlanRRT_SendGoal_Response =
  aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces

namespace aubo_rrt_interfaces
{

namespace action
{

struct PlanRRT_SendGoal
{
  using Request = aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request;
  using Response = aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response;
};

}  // namespace action

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Request __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_GetResult_Request_
{
  using Type = PlanRRT_GetResult_Request_<ContainerAllocator>;

  explicit PlanRRT_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit PlanRRT_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Request
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Request
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_GetResult_Request_

// alias to use template instance with default allocator
using PlanRRT_GetResult_Request =
  aubo_rrt_interfaces::action::PlanRRT_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Response __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_GetResult_Response_
{
  using Type = PlanRRT_GetResult_Response_<ContainerAllocator>;

  explicit PlanRRT_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit PlanRRT_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const aubo_rrt_interfaces::action::PlanRRT_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Response
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_GetResult_Response
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_GetResult_Response_

// alias to use template instance with default allocator
using PlanRRT_GetResult_Response =
  aubo_rrt_interfaces::action::PlanRRT_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces

namespace aubo_rrt_interfaces
{

namespace action
{

struct PlanRRT_GetResult
{
  using Request = aubo_rrt_interfaces::action::PlanRRT_GetResult_Request;
  using Response = aubo_rrt_interfaces::action::PlanRRT_GetResult_Response;
};

}  // namespace action

}  // namespace aubo_rrt_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage __declspec(deprecated)
#endif

namespace aubo_rrt_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanRRT_FeedbackMessage_
{
  using Type = PlanRRT_FeedbackMessage_<ContainerAllocator>;

  explicit PlanRRT_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit PlanRRT_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const aubo_rrt_interfaces::action::PlanRRT_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage
    std::shared_ptr<aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanRRT_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanRRT_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanRRT_FeedbackMessage_

// alias to use template instance with default allocator
using PlanRRT_FeedbackMessage =
  aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace aubo_rrt_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace aubo_rrt_interfaces
{

namespace action
{

struct PlanRRT
{
  /// The goal message defined in the action definition.
  using Goal = aubo_rrt_interfaces::action::PlanRRT_Goal;
  /// The result message defined in the action definition.
  using Result = aubo_rrt_interfaces::action::PlanRRT_Result;
  /// The feedback message defined in the action definition.
  using Feedback = aubo_rrt_interfaces::action::PlanRRT_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = aubo_rrt_interfaces::action::PlanRRT_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = aubo_rrt_interfaces::action::PlanRRT_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct PlanRRT PlanRRT;

}  // namespace action

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__STRUCT_HPP_
