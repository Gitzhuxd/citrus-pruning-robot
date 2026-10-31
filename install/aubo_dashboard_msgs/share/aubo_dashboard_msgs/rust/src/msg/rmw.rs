#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__msg__ProgramState() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__msg__ProgramState__init(msg: *mut ProgramState) -> bool;
    fn aubo_dashboard_msgs__msg__ProgramState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ProgramState>, size: usize) -> bool;
    fn aubo_dashboard_msgs__msg__ProgramState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ProgramState>);
    fn aubo_dashboard_msgs__msg__ProgramState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ProgramState>, out_seq: *mut rosidl_runtime_rs::Sequence<ProgramState>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__msg__ProgramState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProgramState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: rosidl_runtime_rs::String,

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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__msg__ProgramState__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__msg__ProgramState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ProgramState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__ProgramState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__ProgramState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__ProgramState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ProgramState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ProgramState where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/msg/ProgramState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__msg__ProgramState() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__msg__RobotMode() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__msg__RobotMode__init(msg: *mut RobotMode) -> bool;
    fn aubo_dashboard_msgs__msg__RobotMode__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotMode>, size: usize) -> bool;
    fn aubo_dashboard_msgs__msg__RobotMode__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotMode>);
    fn aubo_dashboard_msgs__msg__RobotMode__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotMode>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotMode>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__msg__RobotMode
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__msg__RobotMode__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__msg__RobotMode__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotMode {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__RobotMode__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__RobotMode__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__RobotMode__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotMode {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotMode where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/msg/RobotMode";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__msg__RobotMode() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__msg__SafetyMode() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__msg__SafetyMode__init(msg: *mut SafetyMode) -> bool;
    fn aubo_dashboard_msgs__msg__SafetyMode__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SafetyMode>, size: usize) -> bool;
    fn aubo_dashboard_msgs__msg__SafetyMode__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SafetyMode>);
    fn aubo_dashboard_msgs__msg__SafetyMode__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SafetyMode>, out_seq: *mut rosidl_runtime_rs::Sequence<SafetyMode>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__msg__SafetyMode
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__msg__SafetyMode__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__msg__SafetyMode__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SafetyMode {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__SafetyMode__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__SafetyMode__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__msg__SafetyMode__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SafetyMode {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SafetyMode where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/msg/SafetyMode";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__msg__SafetyMode() }
  }
}


