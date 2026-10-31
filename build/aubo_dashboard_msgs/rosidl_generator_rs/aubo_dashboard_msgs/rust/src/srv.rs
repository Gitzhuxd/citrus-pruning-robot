#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to aubo_dashboard_msgs__srv__AddToLog_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddToLog_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for AddToLog_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AddToLog_Request::default())
  }
}

impl rosidl_runtime_rs::Message for AddToLog_Request {
  type RmwMsg = super::srv::rmw::AddToLog_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__AddToLog_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddToLog_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for AddToLog_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AddToLog_Response::default())
  }
}

impl rosidl_runtime_rs::Message for AddToLog_Response {
  type RmwMsg = super::srv::rmw::AddToLog_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__GetLoadedProgram_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetLoadedProgram_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetLoadedProgram_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetLoadedProgram_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetLoadedProgram_Request {
  type RmwMsg = super::srv::rmw::GetLoadedProgram_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__GetLoadedProgram_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetLoadedProgram_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub program_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetLoadedProgram_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetLoadedProgram_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetLoadedProgram_Response {
  type RmwMsg = super::srv::rmw::GetLoadedProgram_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        program_name: msg.program_name.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        program_name: msg.program_name.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      program_name: msg.program_name.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__GetProgramState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetProgramState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetProgramState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetProgramState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetProgramState_Request {
  type RmwMsg = super::srv::rmw::GetProgramState_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__GetProgramState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetProgramState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: super::msg::ProgramState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub program_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetProgramState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetProgramState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetProgramState_Response {
  type RmwMsg = super::srv::rmw::GetProgramState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: super::msg::ProgramState::into_rmw_message(std::borrow::Cow::Owned(msg.state)).into_owned(),
        program_name: msg.program_name.as_str().into(),
        answer: msg.answer.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: super::msg::ProgramState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.state)).into_owned(),
        program_name: msg.program_name.as_str().into(),
        answer: msg.answer.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state: super::msg::ProgramState::from_rmw_message(msg.state),
      program_name: msg.program_name.to_string(),
      answer: msg.answer.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__GetRobotMode_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRobotMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetRobotMode_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRobotMode_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetRobotMode_Request {
  type RmwMsg = super::srv::rmw::GetRobotMode_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__GetRobotMode_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRobotMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_mode: super::msg::RobotMode,


    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetRobotMode_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetRobotMode_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetRobotMode_Response {
  type RmwMsg = super::srv::rmw::GetRobotMode_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_mode: super::msg::RobotMode::into_rmw_message(std::borrow::Cow::Owned(msg.robot_mode)).into_owned(),
        answer: msg.answer.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        robot_mode: super::msg::RobotMode::into_rmw_message(std::borrow::Cow::Borrowed(&msg.robot_mode)).into_owned(),
        answer: msg.answer.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      robot_mode: super::msg::RobotMode::from_rmw_message(msg.robot_mode),
      answer: msg.answer.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__GetSafetyMode_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSafetyMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetSafetyMode_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetSafetyMode_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetSafetyMode_Request {
  type RmwMsg = super::srv::rmw::GetSafetyMode_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__GetSafetyMode_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSafetyMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub safety_mode: super::msg::SafetyMode,


    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetSafetyMode_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetSafetyMode_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetSafetyMode_Response {
  type RmwMsg = super::srv::rmw::GetSafetyMode_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        safety_mode: super::msg::SafetyMode::into_rmw_message(std::borrow::Cow::Owned(msg.safety_mode)).into_owned(),
        answer: msg.answer.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        safety_mode: super::msg::SafetyMode::into_rmw_message(std::borrow::Cow::Borrowed(&msg.safety_mode)).into_owned(),
        answer: msg.answer.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      safety_mode: super::msg::SafetyMode::from_rmw_message(msg.safety_mode),
      answer: msg.answer.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__IsProgramRunning_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramRunning_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsProgramRunning_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsProgramRunning_Request::default())
  }
}

impl rosidl_runtime_rs::Message for IsProgramRunning_Request {
  type RmwMsg = super::srv::rmw::IsProgramRunning_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__IsProgramRunning_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramRunning_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,

    /// is a program running?
    pub program_running: bool,

    /// Did the dashboard server call succeed?
    pub success: bool,

}



impl Default for IsProgramRunning_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsProgramRunning_Response::default())
  }
}

impl rosidl_runtime_rs::Message for IsProgramRunning_Response {
  type RmwMsg = super::srv::rmw::IsProgramRunning_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        program_running: msg.program_running,
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      program_running: msg.program_running,
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      program_running: msg.program_running,
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__IsInRemoteControl_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsInRemoteControl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsInRemoteControl_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsInRemoteControl_Request::default())
  }
}

impl rosidl_runtime_rs::Message for IsInRemoteControl_Request {
  type RmwMsg = super::srv::rmw::IsInRemoteControl_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__IsInRemoteControl_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsInRemoteControl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,

    /// is the robot currently in remote control mode?
    pub in_remote_control: bool,

    /// Did the dashboard server call succeed?
    pub success: bool,

}



impl Default for IsInRemoteControl_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsInRemoteControl_Response::default())
  }
}

impl rosidl_runtime_rs::Message for IsInRemoteControl_Response {
  type RmwMsg = super::srv::rmw::IsInRemoteControl_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        in_remote_control: msg.in_remote_control,
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      in_remote_control: msg.in_remote_control,
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      in_remote_control: msg.in_remote_control,
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__IsProgramSaved_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramSaved_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsProgramSaved_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsProgramSaved_Request::default())
  }
}

impl rosidl_runtime_rs::Message for IsProgramSaved_Request {
  type RmwMsg = super::srv::rmw::IsProgramSaved_Request;

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


// Corresponds to aubo_dashboard_msgs__srv__IsProgramSaved_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramSaved_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub program_name: std::string::String,

    /// is the current program saved?
    pub program_saved: bool,

    /// Did the dashboard server call succeed?
    pub success: bool,

}



impl Default for IsProgramSaved_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::IsProgramSaved_Response::default())
  }
}

impl rosidl_runtime_rs::Message for IsProgramSaved_Response {
  type RmwMsg = super::srv::rmw::IsProgramSaved_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        program_name: msg.program_name.as_str().into(),
        program_saved: msg.program_saved,
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        program_name: msg.program_name.as_str().into(),
      program_saved: msg.program_saved,
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      program_name: msg.program_name.to_string(),
      program_saved: msg.program_saved,
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__Load_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Load_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub filename: std::string::String,

}



impl Default for Load_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Load_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Load_Request {
  type RmwMsg = super::srv::rmw::Load_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        filename: msg.filename.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        filename: msg.filename.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      filename: msg.filename.to_string(),
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__Load_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Load_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Load_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Load_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Load_Response {
  type RmwMsg = super::srv::rmw::Load_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__Popup_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Popup_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for Popup_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Popup_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Popup_Request {
  type RmwMsg = super::srv::rmw::Popup_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__Popup_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Popup_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Popup_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Popup_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Popup_Response {
  type RmwMsg = super::srv::rmw::Popup_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
      success: msg.success,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__RawRequest_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RawRequest_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub query: std::string::String,

}



impl Default for RawRequest_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RawRequest_Request::default())
  }
}

impl rosidl_runtime_rs::Message for RawRequest_Request {
  type RmwMsg = super::srv::rmw::RawRequest_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        query: msg.query.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        query: msg.query.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      query: msg.query.to_string(),
    }
  }
}


// Corresponds to aubo_dashboard_msgs__srv__RawRequest_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RawRequest_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: std::string::String,

}



impl Default for RawRequest_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RawRequest_Response::default())
  }
}

impl rosidl_runtime_rs::Message for RawRequest_Response {
  type RmwMsg = super::srv::rmw::RawRequest_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        answer: msg.answer.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      answer: msg.answer.to_string(),
    }
  }
}






#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__AddToLog() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__AddToLog
#[allow(missing_docs, non_camel_case_types)]
pub struct AddToLog;

impl rosidl_runtime_rs::Service for AddToLog {
    type Request = AddToLog_Request;
    type Response = AddToLog_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__AddToLog() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetLoadedProgram() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__GetLoadedProgram
#[allow(missing_docs, non_camel_case_types)]
pub struct GetLoadedProgram;

impl rosidl_runtime_rs::Service for GetLoadedProgram {
    type Request = GetLoadedProgram_Request;
    type Response = GetLoadedProgram_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetLoadedProgram() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetProgramState() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__GetProgramState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetProgramState;

impl rosidl_runtime_rs::Service for GetProgramState {
    type Request = GetProgramState_Request;
    type Response = GetProgramState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetProgramState() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetRobotMode() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__GetRobotMode
#[allow(missing_docs, non_camel_case_types)]
pub struct GetRobotMode;

impl rosidl_runtime_rs::Service for GetRobotMode {
    type Request = GetRobotMode_Request;
    type Response = GetRobotMode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetRobotMode() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetSafetyMode() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__GetSafetyMode
#[allow(missing_docs, non_camel_case_types)]
pub struct GetSafetyMode;

impl rosidl_runtime_rs::Service for GetSafetyMode {
    type Request = GetSafetyMode_Request;
    type Response = GetSafetyMode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__GetSafetyMode() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__IsProgramRunning() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__IsProgramRunning
#[allow(missing_docs, non_camel_case_types)]
pub struct IsProgramRunning;

impl rosidl_runtime_rs::Service for IsProgramRunning {
    type Request = IsProgramRunning_Request;
    type Response = IsProgramRunning_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__IsProgramRunning() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__IsInRemoteControl() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__IsInRemoteControl
#[allow(missing_docs, non_camel_case_types)]
pub struct IsInRemoteControl;

impl rosidl_runtime_rs::Service for IsInRemoteControl {
    type Request = IsInRemoteControl_Request;
    type Response = IsInRemoteControl_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__IsInRemoteControl() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__IsProgramSaved() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__IsProgramSaved
#[allow(missing_docs, non_camel_case_types)]
pub struct IsProgramSaved;

impl rosidl_runtime_rs::Service for IsProgramSaved {
    type Request = IsProgramSaved_Request;
    type Response = IsProgramSaved_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__IsProgramSaved() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__Load() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__Load
#[allow(missing_docs, non_camel_case_types)]
pub struct Load;

impl rosidl_runtime_rs::Service for Load {
    type Request = Load_Request;
    type Response = Load_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__Load() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__Popup() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__Popup
#[allow(missing_docs, non_camel_case_types)]
pub struct Popup;

impl rosidl_runtime_rs::Service for Popup {
    type Request = Popup_Request;
    type Response = Popup_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__Popup() }
    }
}




#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__RawRequest() -> *const std::ffi::c_void;
}

// Corresponds to aubo_dashboard_msgs__srv__RawRequest
#[allow(missing_docs, non_camel_case_types)]
pub struct RawRequest;

impl rosidl_runtime_rs::Service for RawRequest {
    type Request = RawRequest_Request;
    type Response = RawRequest_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_dashboard_msgs__srv__RawRequest() }
    }
}


