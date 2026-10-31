#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__Analog() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__Analog__init(msg: *mut Analog) -> bool;
    fn aubo_msgs__msg__Analog__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Analog>, size: usize) -> bool;
    fn aubo_msgs__msg__Analog__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Analog>);
    fn aubo_msgs__msg__Analog__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Analog>, out_seq: *mut rosidl_runtime_rs::Sequence<Analog>) -> bool;
}

// Corresponds to aubo_msgs__msg__Analog
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Analog {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pin: u8,

    /// can be VOLTAGE or CURRENT
    pub domain: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: f32,

}

impl Analog {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CURRENT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VOLTAGE: u8 = 1;

}


impl Default for Analog {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__Analog__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__Analog__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Analog {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__Analog__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__Analog__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__Analog__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Analog {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Analog where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/Analog";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__Analog() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__Digital() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__Digital__init(msg: *mut Digital) -> bool;
    fn aubo_msgs__msg__Digital__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Digital>, size: usize) -> bool;
    fn aubo_msgs__msg__Digital__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Digital>);
    fn aubo_msgs__msg__Digital__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Digital>, out_seq: *mut rosidl_runtime_rs::Sequence<Digital>) -> bool;
}

// Corresponds to aubo_msgs__msg__Digital
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Digital {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pin: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: bool,

}



impl Default for Digital {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__Digital__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__Digital__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Digital {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__Digital__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__Digital__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__Digital__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Digital {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Digital where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/Digital";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__Digital() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__IOStates() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__IOStates__init(msg: *mut IOStates) -> bool;
    fn aubo_msgs__msg__IOStates__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IOStates>, size: usize) -> bool;
    fn aubo_msgs__msg__IOStates__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IOStates>);
    fn aubo_msgs__msg__IOStates__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IOStates>, out_seq: *mut rosidl_runtime_rs::Sequence<IOStates>) -> bool;
}

// Corresponds to aubo_msgs__msg__IOStates
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IOStates {

    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_in_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Digital>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_out_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Digital>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub flag_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Digital>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_in_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Analog>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_out_states: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Analog>,

}



impl Default for IOStates {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__IOStates__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__IOStates__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IOStates {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__IOStates__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__IOStates__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__IOStates__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IOStates {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IOStates where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/IOStates";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__IOStates() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__RobotStateRTMsg() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__RobotStateRTMsg__init(msg: *mut RobotStateRTMsg) -> bool;
    fn aubo_msgs__msg__RobotStateRTMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotStateRTMsg>, size: usize) -> bool;
    fn aubo_msgs__msg__RobotStateRTMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotStateRTMsg>);
    fn aubo_msgs__msg__RobotStateRTMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotStateRTMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotStateRTMsg>) -> bool;
}

// Corresponds to aubo_msgs__msg__RobotStateRTMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Data structure for the realtime communications interface (aka Matlab interface)
/// used by the Universal Robots controller
///
/// This data structure is send at 125 Hz on TCP port 30003
///
/// Dokumentation can be found on the Universal Robots Support Wiki
/// (http://wiki03.lynero.net/Technical/RealTimeClientInterface?rev=9)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotStateRTMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub time: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_target: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub qd_target: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub qdd_target: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub i_target: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub m_target: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_actual: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub qd_actual: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub i_actual: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_acc_values: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tcp_force: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_vector: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tcp_speed: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_input_bits: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_temperatures: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub controller_timer: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub test_value: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_mode: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub joint_modes: rosidl_runtime_rs::Sequence<f64>,

}



impl Default for RobotStateRTMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__RobotStateRTMsg__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__RobotStateRTMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotStateRTMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__RobotStateRTMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__RobotStateRTMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__RobotStateRTMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotStateRTMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotStateRTMsg where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/RobotStateRTMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__RobotStateRTMsg() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__MasterboardDataMsg() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__MasterboardDataMsg__init(msg: *mut MasterboardDataMsg) -> bool;
    fn aubo_msgs__msg__MasterboardDataMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MasterboardDataMsg>, size: usize) -> bool;
    fn aubo_msgs__msg__MasterboardDataMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MasterboardDataMsg>);
    fn aubo_msgs__msg__MasterboardDataMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MasterboardDataMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<MasterboardDataMsg>) -> bool;
}

// Corresponds to aubo_msgs__msg__MasterboardDataMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This data structure contains the MasterboardData structure
/// used by the Universal Robots controller
///
/// MasterboardData is part of the data structure being send on the 
/// secondary client communications interface
///
/// This data structure is send at 10 Hz on TCP port 30002
///
/// Documentation can be found on the Universal Robots Support site, article
/// number 16496.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MasterboardDataMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_input_bits: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_output_bits: u32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_input_range0: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_input_range1: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_input0: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_input1: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_output_domain0: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_output_domain1: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_output0: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_output1: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub masterboard_temperature: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_voltage_48v: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_current: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub master_io_current: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub master_safety_state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub master_onoff_state: u8,

}



impl Default for MasterboardDataMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__MasterboardDataMsg__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__MasterboardDataMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MasterboardDataMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__MasterboardDataMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__MasterboardDataMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__MasterboardDataMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MasterboardDataMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MasterboardDataMsg where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/MasterboardDataMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__MasterboardDataMsg() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__RobotModeDataMsg() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__RobotModeDataMsg__init(msg: *mut RobotModeDataMsg) -> bool;
    fn aubo_msgs__msg__RobotModeDataMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotModeDataMsg>, size: usize) -> bool;
    fn aubo_msgs__msg__RobotModeDataMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotModeDataMsg>);
    fn aubo_msgs__msg__RobotModeDataMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotModeDataMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotModeDataMsg>) -> bool;
}

// Corresponds to aubo_msgs__msg__RobotModeDataMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This data structure contains the RobotModeData structure
/// used by the Universal Robots controller
///
/// This data structure is send at 10 Hz on TCP port 30002
///
/// Note: this message does not carry all fields from the RobotModeData structure as broadcast by the robot controller, but a subset.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotModeDataMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub timestamp: u64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_robot_connected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_real_robot_enabled: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_power_on_robot: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_emergency_stopped: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_protective_stopped: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_program_running: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_program_paused: bool,

}



impl Default for RobotModeDataMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__RobotModeDataMsg__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__RobotModeDataMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotModeDataMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__RobotModeDataMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__RobotModeDataMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__RobotModeDataMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotModeDataMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotModeDataMsg where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/RobotModeDataMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__RobotModeDataMsg() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__ToolDataMsg() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__msg__ToolDataMsg__init(msg: *mut ToolDataMsg) -> bool;
    fn aubo_msgs__msg__ToolDataMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ToolDataMsg>, size: usize) -> bool;
    fn aubo_msgs__msg__ToolDataMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ToolDataMsg>);
    fn aubo_msgs__msg__ToolDataMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ToolDataMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<ToolDataMsg>) -> bool;
}

// Corresponds to aubo_msgs__msg__ToolDataMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This data structure contains the ToolData structure
/// used by the Universal Robots controller

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ToolDataMsg {
    /// one of ANALOG_INPUT_RANGE_*
    pub analog_input_range2: i8,

    /// one of ANALOG_INPUT_RANGE_*
    pub analog_input_range3: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_input2: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_input3: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_voltage_48v: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_output_voltage: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_current: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_temperature: f32,

    /// one of TOOL_*
    pub tool_mode: u8,

}

impl ToolDataMsg {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ANALOG_INPUT_RANGE_CURRENT: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ANALOG_INPUT_RANGE_VOLTAGE: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TOOL_BOOTLOADER_MODE: u8 = 249;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TOOL_RUNNING_MODE: u8 = 253;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TOOL_IDLE_MODE: u8 = 255;

}


impl Default for ToolDataMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__msg__ToolDataMsg__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__msg__ToolDataMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ToolDataMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__ToolDataMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__ToolDataMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__msg__ToolDataMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ToolDataMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ToolDataMsg where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/msg/ToolDataMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__msg__ToolDataMsg() }
  }
}


