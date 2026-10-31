
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to aubo_rrt_interfaces__action__PlanRRT_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start: super::msg::Endpoint,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::msg::Endpoint,


    // This member is not documented.
    #[allow(missing_docs)]
    pub step_size: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_bias: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub collision_step: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_iterations: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub planning_time: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub seed: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub replay_step: f64,

}



impl Default for PlanRRT_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_Goal {
  type RmwMsg = super::action::rmw::PlanRRT_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start: super::msg::Endpoint::into_rmw_message(std::borrow::Cow::Owned(msg.start)).into_owned(),
        goal: super::msg::Endpoint::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
        step_size: msg.step_size,
        goal_bias: msg.goal_bias,
        collision_step: msg.collision_step,
        max_iterations: msg.max_iterations,
        planning_time: msg.planning_time,
        seed: msg.seed,
        replay_step: msg.replay_step,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start: super::msg::Endpoint::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start)).into_owned(),
        goal: super::msg::Endpoint::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      step_size: msg.step_size,
      goal_bias: msg.goal_bias,
      collision_step: msg.collision_step,
      max_iterations: msg.max_iterations,
      planning_time: msg.planning_time,
      seed: msg.seed,
      replay_step: msg.replay_step,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      start: super::msg::Endpoint::from_rmw_message(msg.start),
      goal: super::msg::Endpoint::from_rmw_message(msg.goal),
      step_size: msg.step_size,
      goal_bias: msg.goal_bias,
      collision_step: msg.collision_step,
      max_iterations: msg.max_iterations,
      planning_time: msg.planning_time,
      seed: msg.seed,
      replay_step: msg.replay_step,
    }
  }
}


// Corresponds to aubo_rrt_interfaces__action__PlanRRT_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub output_directory: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub iterations: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tree_nodes: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub path_nodes: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub planning_seconds: f64,

}



impl Default for PlanRRT_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_Result::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_Result {
  type RmwMsg = super::action::rmw::PlanRRT_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        output_directory: msg.output_directory.as_str().into(),
        iterations: msg.iterations,
        tree_nodes: msg.tree_nodes,
        path_nodes: msg.path_nodes,
        planning_seconds: msg.planning_seconds,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
        output_directory: msg.output_directory.as_str().into(),
      iterations: msg.iterations,
      tree_nodes: msg.tree_nodes,
      path_nodes: msg.path_nodes,
      planning_seconds: msg.planning_seconds,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      output_directory: msg.output_directory.to_string(),
      iterations: msg.iterations,
      tree_nodes: msg.tree_nodes,
      path_nodes: msg.path_nodes,
      planning_seconds: msg.planning_seconds,
    }
  }
}


// Corresponds to aubo_rrt_interfaces__action__PlanRRT_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub phase: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub iterations: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tree_nodes: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub elapsed_seconds: f64,

}



impl Default for PlanRRT_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_Feedback {
  type RmwMsg = super::action::rmw::PlanRRT_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        phase: msg.phase.as_str().into(),
        iterations: msg.iterations,
        tree_nodes: msg.tree_nodes,
        elapsed_seconds: msg.elapsed_seconds,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        phase: msg.phase.as_str().into(),
      iterations: msg.iterations,
      tree_nodes: msg.tree_nodes,
      elapsed_seconds: msg.elapsed_seconds,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      phase: msg.phase.to_string(),
      iterations: msg.iterations,
      tree_nodes: msg.tree_nodes,
      elapsed_seconds: msg.elapsed_seconds,
    }
  }
}


// Corresponds to aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::PlanRRT_Feedback,

}



impl Default for PlanRRT_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_FeedbackMessage {
  type RmwMsg = super::action::rmw::PlanRRT_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::PlanRRT_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::PlanRRT_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::PlanRRT_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::PlanRRT_Goal,

}



impl Default for PlanRRT_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_SendGoal_Request {
  type RmwMsg = super::action::rmw::PlanRRT_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::PlanRRT_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::PlanRRT_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::PlanRRT_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for PlanRRT_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_SendGoal_Response {
  type RmwMsg = super::action::rmw::PlanRRT_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to aubo_rrt_interfaces__action__PlanRRT_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for PlanRRT_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_GetResult_Request {
  type RmwMsg = super::action::rmw::PlanRRT_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to aubo_rrt_interfaces__action__PlanRRT_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::PlanRRT_Result,

}



impl Default for PlanRRT_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::PlanRRT_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_GetResult_Response {
  type RmwMsg = super::action::rmw::PlanRRT_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::PlanRRT_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::PlanRRT_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::PlanRRT_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct PlanRRT_SendGoal;

impl rosidl_runtime_rs::Service for PlanRRT_SendGoal {
    type Request = PlanRRT_SendGoal_Request;
    type Response = PlanRRT_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_SendGoal() }
    }
}




#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct PlanRRT_GetResult;

impl rosidl_runtime_rs::Service for PlanRRT_GetResult {
    type Request = PlanRRT_GetResult_Request;
    type Response = PlanRRT_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_GetResult() }
    }
}






#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__aubo_rrt_interfaces__action__PlanRRT() -> *const std::ffi::c_void;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT
#[allow(missing_docs, non_camel_case_types)]
pub struct PlanRRT;

impl rosidl_runtime_rs::Action for PlanRRT {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = PlanRRT_Goal;

  /// The result message defined in the action definition.
  type Result = PlanRRT_Result;

  /// The feedback message defined in the action definition.
  type Feedback = PlanRRT_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::PlanRRT_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::PlanRRT_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::PlanRRT_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__aubo_rrt_interfaces__action__PlanRRT() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::PlanRRT_Goal,
  ) -> super::action::rmw::PlanRRT_SendGoal_Request {
   super::action::rmw::PlanRRT_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::PlanRRT_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::PlanRRT_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::PlanRRT_SendGoal_Response {
   super::action::rmw::PlanRRT_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::PlanRRT_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::PlanRRT_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::PlanRRT_Feedback,
  ) -> super::action::rmw::PlanRRT_FeedbackMessage {
    let mut message = super::action::rmw::PlanRRT_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::PlanRRT_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::PlanRRT_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::PlanRRT_GetResult_Request {
   super::action::rmw::PlanRRT_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::PlanRRT_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::PlanRRT_Result,
  ) -> super::action::rmw::PlanRRT_GetResult_Response {
   super::action::rmw::PlanRRT_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::PlanRRT_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::PlanRRT_Result,
  ) {
    (response.status, response.result)
  }
}


