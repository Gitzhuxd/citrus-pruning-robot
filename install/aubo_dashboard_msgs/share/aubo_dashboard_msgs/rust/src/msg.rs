#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to aubo_dashboard_msgs__msg__ProgramState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProgramState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: std::string::String,

}

impl ProgramState {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STOPPED: &'static str = "STOPPED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PLAYING: &'static str = "PLAYING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PAUSED: &'static str = "PAUSED";

}


impl Default for ProgramState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ProgramState::default())
  }
}

impl rosidl_runtime_rs::Message for ProgramState {
  type RmwMsg = super::msg::rmw::ProgramState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: msg.state.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: msg.state.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state: msg.state.to_string(),
    }
  }
}


// Corresponds to aubo_dashboard_msgs__msg__RobotMode

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotMode {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: i8,

}

impl RobotMode {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_CONTROLLER: i8 = -1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DISCONNECTED: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONFIRM_SAFETY: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BOOTING: i8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POWER_OFF: i8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POWER_ON: i8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const IDLE: i8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BACKDRIVE: i8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RUNNING: i8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UPDATING_FIRMWARE: i8 = 8;

}


impl Default for RobotMode {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RobotMode::default())
  }
}

impl rosidl_runtime_rs::Message for RobotMode {
  type RmwMsg = super::msg::rmw::RobotMode;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mode: msg.mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mode: msg.mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mode: msg.mode,
    }
  }
}


// Corresponds to aubo_dashboard_msgs__msg__SafetyMode

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SafetyMode {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,

}

impl SafetyMode {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NORMAL: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REDUCED: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PROTECTIVE_STOP: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RECOVERY: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SAFEGUARD_STOP: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SYSTEM_EMERGENCY_STOP: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ROBOT_EMERGENCY_STOP: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VIOLATION: u8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FAULT: u8 = 9;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VALIDATE_JOINT_ID: u8 = 10;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UNDEFINED_SAFETY_MODE: u8 = 11;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const AUTOMATIC_MODE_SAFEGUARD_STOP: u8 = 12;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SYSTEM_THREE_POSITION_ENABLING_STOP: u8 = 13;

}


impl Default for SafetyMode {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SafetyMode::default())
  }
}

impl rosidl_runtime_rs::Message for SafetyMode {
  type RmwMsg = super::msg::rmw::SafetyMode;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mode: msg.mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mode: msg.mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mode: msg.mode,
    }
  }
}


