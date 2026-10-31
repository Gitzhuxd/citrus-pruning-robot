#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to aubo_rrt_interfaces__srv__GetRRTInfo_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRRTInfo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetRRTInfo_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRRTInfo_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetRRTInfo_Request {
  type RmwMsg = super::srv::rmw::GetRRTInfo_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to aubo_rrt_interfaces__srv__GetRRTInfo_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRRTInfo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub ready: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub named_states: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_pose: geometry_msgs::msg::PoseStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_state: moveit_msgs::msg::RobotState,

}



impl Default for GetRRTInfo_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRRTInfo_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetRRTInfo_Response {
  type RmwMsg = super::srv::rmw::GetRRTInfo_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        ready: msg.ready,
        message: msg.message.as_str().into(),
        named_states: msg.named_states
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        current_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.current_pose)).into_owned(),
        current_state: moveit_msgs::msg::RobotState::into_rmw_message(std::borrow::Cow::Owned(msg.current_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      ready: msg.ready,
        message: msg.message.as_str().into(),
        named_states: msg.named_states
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        current_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_pose)).into_owned(),
        current_state: moveit_msgs::msg::RobotState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      ready: msg.ready,
      message: msg.message.to_string(),
      named_states: msg.named_states
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      current_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.current_pose),
      current_state: moveit_msgs::msg::RobotState::from_rmw_message(msg.current_state),
    }
  }
}


// Corresponds to aubo_rrt_interfaces__srv__PreviewRRT_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PreviewRRT_Request {

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



impl Default for PreviewRRT_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PreviewRRT_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PreviewRRT_Request {
  type RmwMsg = super::srv::rmw::PreviewRRT_Request;

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


// Corresponds to aubo_rrt_interfaces__srv__PreviewRRT_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PreviewRRT_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_state: moveit_msgs::msg::RobotState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_state: moveit_msgs::msg::RobotState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_pose: geometry_msgs::msg::PoseStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_pose: geometry_msgs::msg::PoseStamped,

}



impl Default for PreviewRRT_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PreviewRRT_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PreviewRRT_Response {
  type RmwMsg = super::srv::rmw::PreviewRRT_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        start_state: moveit_msgs::msg::RobotState::into_rmw_message(std::borrow::Cow::Owned(msg.start_state)).into_owned(),
        goal_state: moveit_msgs::msg::RobotState::into_rmw_message(std::borrow::Cow::Owned(msg.goal_state)).into_owned(),
        start_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.start_pose)).into_owned(),
        goal_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.goal_pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
        start_state: moveit_msgs::msg::RobotState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_state)).into_owned(),
        goal_state: moveit_msgs::msg::RobotState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_state)).into_owned(),
        start_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_pose)).into_owned(),
        goal_pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      start_state: moveit_msgs::msg::RobotState::from_rmw_message(msg.start_state),
      goal_state: moveit_msgs::msg::RobotState::from_rmw_message(msg.goal_state),
      start_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.start_pose),
      goal_pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.goal_pose),
    }
  }
}






#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__srv__GetRRTInfo() -> *const std::ffi::c_void;
}

// Corresponds to aubo_rrt_interfaces__srv__GetRRTInfo
#[allow(missing_docs, non_camel_case_types)]
pub struct GetRRTInfo;

impl rosidl_runtime_rs::Service for GetRRTInfo {
    type Request = GetRRTInfo_Request;
    type Response = GetRRTInfo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__srv__GetRRTInfo() }
    }
}




#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__srv__PreviewRRT() -> *const std::ffi::c_void;
}

// Corresponds to aubo_rrt_interfaces__srv__PreviewRRT
#[allow(missing_docs, non_camel_case_types)]
pub struct PreviewRRT;

impl rosidl_runtime_rs::Service for PreviewRRT {
    type Request = PreviewRRT_Request;
    type Response = PreviewRRT_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_rrt_interfaces__srv__PreviewRRT() }
    }
}


