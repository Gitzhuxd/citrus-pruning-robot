// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aubo_rrt_interfaces:action/PlanRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__BUILDER_HPP_
#define AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aubo_rrt_interfaces/action/detail/plan_rrt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_Goal_replay_step
{
public:
  explicit Init_PlanRRT_Goal_replay_step(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_Goal replay_step(::aubo_rrt_interfaces::action::PlanRRT_Goal::_replay_step_type arg)
  {
    msg_.replay_step = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_seed
{
public:
  explicit Init_PlanRRT_Goal_seed(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_replay_step seed(::aubo_rrt_interfaces::action::PlanRRT_Goal::_seed_type arg)
  {
    msg_.seed = std::move(arg);
    return Init_PlanRRT_Goal_replay_step(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_planning_time
{
public:
  explicit Init_PlanRRT_Goal_planning_time(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_seed planning_time(::aubo_rrt_interfaces::action::PlanRRT_Goal::_planning_time_type arg)
  {
    msg_.planning_time = std::move(arg);
    return Init_PlanRRT_Goal_seed(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_max_iterations
{
public:
  explicit Init_PlanRRT_Goal_max_iterations(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_planning_time max_iterations(::aubo_rrt_interfaces::action::PlanRRT_Goal::_max_iterations_type arg)
  {
    msg_.max_iterations = std::move(arg);
    return Init_PlanRRT_Goal_planning_time(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_collision_step
{
public:
  explicit Init_PlanRRT_Goal_collision_step(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_max_iterations collision_step(::aubo_rrt_interfaces::action::PlanRRT_Goal::_collision_step_type arg)
  {
    msg_.collision_step = std::move(arg);
    return Init_PlanRRT_Goal_max_iterations(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_goal_bias
{
public:
  explicit Init_PlanRRT_Goal_goal_bias(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_collision_step goal_bias(::aubo_rrt_interfaces::action::PlanRRT_Goal::_goal_bias_type arg)
  {
    msg_.goal_bias = std::move(arg);
    return Init_PlanRRT_Goal_collision_step(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_step_size
{
public:
  explicit Init_PlanRRT_Goal_step_size(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_goal_bias step_size(::aubo_rrt_interfaces::action::PlanRRT_Goal::_step_size_type arg)
  {
    msg_.step_size = std::move(arg);
    return Init_PlanRRT_Goal_goal_bias(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_goal
{
public:
  explicit Init_PlanRRT_Goal_goal(::aubo_rrt_interfaces::action::PlanRRT_Goal & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Goal_step_size goal(::aubo_rrt_interfaces::action::PlanRRT_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return Init_PlanRRT_Goal_step_size(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

class Init_PlanRRT_Goal_start
{
public:
  Init_PlanRRT_Goal_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_Goal_goal start(::aubo_rrt_interfaces::action::PlanRRT_Goal::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_PlanRRT_Goal_goal(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_Goal>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_Goal_start();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_Result_planning_seconds
{
public:
  explicit Init_PlanRRT_Result_planning_seconds(::aubo_rrt_interfaces::action::PlanRRT_Result & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_Result planning_seconds(::aubo_rrt_interfaces::action::PlanRRT_Result::_planning_seconds_type arg)
  {
    msg_.planning_seconds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

class Init_PlanRRT_Result_path_nodes
{
public:
  explicit Init_PlanRRT_Result_path_nodes(::aubo_rrt_interfaces::action::PlanRRT_Result & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Result_planning_seconds path_nodes(::aubo_rrt_interfaces::action::PlanRRT_Result::_path_nodes_type arg)
  {
    msg_.path_nodes = std::move(arg);
    return Init_PlanRRT_Result_planning_seconds(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

class Init_PlanRRT_Result_tree_nodes
{
public:
  explicit Init_PlanRRT_Result_tree_nodes(::aubo_rrt_interfaces::action::PlanRRT_Result & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Result_path_nodes tree_nodes(::aubo_rrt_interfaces::action::PlanRRT_Result::_tree_nodes_type arg)
  {
    msg_.tree_nodes = std::move(arg);
    return Init_PlanRRT_Result_path_nodes(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

class Init_PlanRRT_Result_iterations
{
public:
  explicit Init_PlanRRT_Result_iterations(::aubo_rrt_interfaces::action::PlanRRT_Result & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Result_tree_nodes iterations(::aubo_rrt_interfaces::action::PlanRRT_Result::_iterations_type arg)
  {
    msg_.iterations = std::move(arg);
    return Init_PlanRRT_Result_tree_nodes(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

class Init_PlanRRT_Result_output_directory
{
public:
  explicit Init_PlanRRT_Result_output_directory(::aubo_rrt_interfaces::action::PlanRRT_Result & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Result_iterations output_directory(::aubo_rrt_interfaces::action::PlanRRT_Result::_output_directory_type arg)
  {
    msg_.output_directory = std::move(arg);
    return Init_PlanRRT_Result_iterations(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

class Init_PlanRRT_Result_message
{
public:
  explicit Init_PlanRRT_Result_message(::aubo_rrt_interfaces::action::PlanRRT_Result & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Result_output_directory message(::aubo_rrt_interfaces::action::PlanRRT_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_PlanRRT_Result_output_directory(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

class Init_PlanRRT_Result_success
{
public:
  Init_PlanRRT_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_Result_message success(::aubo_rrt_interfaces::action::PlanRRT_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PlanRRT_Result_message(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_Result>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_Result_success();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_Feedback_elapsed_seconds
{
public:
  explicit Init_PlanRRT_Feedback_elapsed_seconds(::aubo_rrt_interfaces::action::PlanRRT_Feedback & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_Feedback elapsed_seconds(::aubo_rrt_interfaces::action::PlanRRT_Feedback::_elapsed_seconds_type arg)
  {
    msg_.elapsed_seconds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Feedback msg_;
};

class Init_PlanRRT_Feedback_tree_nodes
{
public:
  explicit Init_PlanRRT_Feedback_tree_nodes(::aubo_rrt_interfaces::action::PlanRRT_Feedback & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Feedback_elapsed_seconds tree_nodes(::aubo_rrt_interfaces::action::PlanRRT_Feedback::_tree_nodes_type arg)
  {
    msg_.tree_nodes = std::move(arg);
    return Init_PlanRRT_Feedback_elapsed_seconds(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Feedback msg_;
};

class Init_PlanRRT_Feedback_iterations
{
public:
  explicit Init_PlanRRT_Feedback_iterations(::aubo_rrt_interfaces::action::PlanRRT_Feedback & msg)
  : msg_(msg)
  {}
  Init_PlanRRT_Feedback_tree_nodes iterations(::aubo_rrt_interfaces::action::PlanRRT_Feedback::_iterations_type arg)
  {
    msg_.iterations = std::move(arg);
    return Init_PlanRRT_Feedback_tree_nodes(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Feedback msg_;
};

class Init_PlanRRT_Feedback_phase
{
public:
  Init_PlanRRT_Feedback_phase()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_Feedback_iterations phase(::aubo_rrt_interfaces::action::PlanRRT_Feedback::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_PlanRRT_Feedback_iterations(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_Feedback>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_Feedback_phase();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_SendGoal_Request_goal
{
public:
  explicit Init_PlanRRT_SendGoal_Request_goal(::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request goal(::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request msg_;
};

class Init_PlanRRT_SendGoal_Request_goal_id
{
public:
  Init_PlanRRT_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_SendGoal_Request_goal goal_id(::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PlanRRT_SendGoal_Request_goal(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Request>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_SendGoal_Request_goal_id();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_SendGoal_Response_stamp
{
public:
  explicit Init_PlanRRT_SendGoal_Response_stamp(::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response stamp(::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response msg_;
};

class Init_PlanRRT_SendGoal_Response_accepted
{
public:
  Init_PlanRRT_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_SendGoal_Response_stamp accepted(::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PlanRRT_SendGoal_Response_stamp(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_SendGoal_Response>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_SendGoal_Response_accepted();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_GetResult_Request_goal_id
{
public:
  Init_PlanRRT_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_GetResult_Request goal_id(::aubo_rrt_interfaces::action::PlanRRT_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_GetResult_Request>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_GetResult_Request_goal_id();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_GetResult_Response_result
{
public:
  explicit Init_PlanRRT_GetResult_Response_result(::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response result(::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response msg_;
};

class Init_PlanRRT_GetResult_Response_status
{
public:
  Init_PlanRRT_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_GetResult_Response_result status(::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PlanRRT_GetResult_Response_result(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_GetResult_Response>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_GetResult_Response_status();
}

}  // namespace aubo_rrt_interfaces


namespace aubo_rrt_interfaces
{

namespace action
{

namespace builder
{

class Init_PlanRRT_FeedbackMessage_feedback
{
public:
  explicit Init_PlanRRT_FeedbackMessage_feedback(::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage feedback(::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage msg_;
};

class Init_PlanRRT_FeedbackMessage_goal_id
{
public:
  Init_PlanRRT_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlanRRT_FeedbackMessage_feedback goal_id(::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PlanRRT_FeedbackMessage_feedback(msg_);
  }

private:
  ::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::aubo_rrt_interfaces::action::PlanRRT_FeedbackMessage>()
{
  return aubo_rrt_interfaces::action::builder::Init_PlanRRT_FeedbackMessage_goal_id();
}

}  // namespace aubo_rrt_interfaces

#endif  // AUBO_RRT_INTERFACES__ACTION__DETAIL__PLAN_RRT__BUILDER_HPP_
