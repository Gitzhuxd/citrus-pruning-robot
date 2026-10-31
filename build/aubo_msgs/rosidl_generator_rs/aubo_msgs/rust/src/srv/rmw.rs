#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetPayload_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__SetPayload_Request__init(msg: *mut SetPayload_Request) -> bool;
    fn aubo_msgs__srv__SetPayload_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetPayload_Request>, size: usize) -> bool;
    fn aubo_msgs__srv__SetPayload_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetPayload_Request>);
    fn aubo_msgs__srv__SetPayload_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetPayload_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetPayload_Request>) -> bool;
}

// Corresponds to aubo_msgs__srv__SetPayload_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPayload_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mass: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_of_gravity: geometry_msgs::msg::rmw::Vector3,

}



impl Default for SetPayload_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__SetPayload_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__SetPayload_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetPayload_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetPayload_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetPayload_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetPayload_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetPayload_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetPayload_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/SetPayload_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetPayload_Request() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetPayload_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__SetPayload_Response__init(msg: *mut SetPayload_Response) -> bool;
    fn aubo_msgs__srv__SetPayload_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetPayload_Response>, size: usize) -> bool;
    fn aubo_msgs__srv__SetPayload_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetPayload_Response>);
    fn aubo_msgs__srv__SetPayload_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetPayload_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetPayload_Response>) -> bool;
}

// Corresponds to aubo_msgs__srv__SetPayload_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPayload_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SetPayload_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__SetPayload_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__SetPayload_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetPayload_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetPayload_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetPayload_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetPayload_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetPayload_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetPayload_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/SetPayload_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetPayload_Response() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetSpeedSliderFraction_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__SetSpeedSliderFraction_Request__init(msg: *mut SetSpeedSliderFraction_Request) -> bool;
    fn aubo_msgs__srv__SetSpeedSliderFraction_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Request>, size: usize) -> bool;
    fn aubo_msgs__srv__SetSpeedSliderFraction_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Request>);
    fn aubo_msgs__srv__SetSpeedSliderFraction_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Request>) -> bool;
}

// Corresponds to aubo_msgs__srv__SetSpeedSliderFraction_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeedSliderFraction_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_slider_fraction: f64,

}



impl Default for SetSpeedSliderFraction_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__SetSpeedSliderFraction_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__SetSpeedSliderFraction_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetSpeedSliderFraction_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetSpeedSliderFraction_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetSpeedSliderFraction_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetSpeedSliderFraction_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetSpeedSliderFraction_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetSpeedSliderFraction_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/SetSpeedSliderFraction_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetSpeedSliderFraction_Request() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetSpeedSliderFraction_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__SetSpeedSliderFraction_Response__init(msg: *mut SetSpeedSliderFraction_Response) -> bool;
    fn aubo_msgs__srv__SetSpeedSliderFraction_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Response>, size: usize) -> bool;
    fn aubo_msgs__srv__SetSpeedSliderFraction_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Response>);
    fn aubo_msgs__srv__SetSpeedSliderFraction_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetSpeedSliderFraction_Response>) -> bool;
}

// Corresponds to aubo_msgs__srv__SetSpeedSliderFraction_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeedSliderFraction_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SetSpeedSliderFraction_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__SetSpeedSliderFraction_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__SetSpeedSliderFraction_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetSpeedSliderFraction_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetSpeedSliderFraction_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetSpeedSliderFraction_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetSpeedSliderFraction_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetSpeedSliderFraction_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetSpeedSliderFraction_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/SetSpeedSliderFraction_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetSpeedSliderFraction_Response() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetIO_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__SetIO_Request__init(msg: *mut SetIO_Request) -> bool;
    fn aubo_msgs__srv__SetIO_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetIO_Request>, size: usize) -> bool;
    fn aubo_msgs__srv__SetIO_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetIO_Request>);
    fn aubo_msgs__srv__SetIO_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetIO_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetIO_Request>) -> bool;
}

// Corresponds to aubo_msgs__srv__SetIO_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetIO_Request {
    /// request fields
    pub fun: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pin: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: f32,

}

impl SetIO_Request {
    /// constants
    /// pin mapping
    /// analog out
    pub const PIN_AOUT0: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_AOUT1: i8 = 1;

    /// digital out
    pub const PIN_DOUT0: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT1: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT2: i8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT3: i8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT4: i8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT5: i8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT6: i8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_DOUT7: i8 = 7;

    /// configurable out
    pub const PIN_CONF_OUT0: i8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT1: i8 = 9;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT2: i8 = 10;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT3: i8 = 11;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT4: i8 = 12;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT5: i8 = 13;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT6: i8 = 14;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_CONF_OUT7: i8 = 15;

    /// digital tool output
    pub const PIN_TOOL_DOUT0: i8 = 16;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PIN_TOOL_DOUT1: i8 = 17;

    /// valid function values
    ///
    /// Note: 'fun' is short for 'function' (ie: the function the service should perform).
    pub const FUN_SET_DIGITAL_OUT: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FUN_SET_FLAG: i8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FUN_SET_ANALOG_OUT: i8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FUN_SET_TOOL_VOLTAGE: i8 = 4;

    /// valid values for 'state' when setting digital IO or flags
    pub const STATE_OFF: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATE_ON: i8 = 1;

    /// valid 'state' values when setting tool voltage
    pub const STATE_TOOL_VOLTAGE_0V: i8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATE_TOOL_VOLTAGE_12V: i8 = 12;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STATE_TOOL_VOLTAGE_24V: i8 = 24;

}


impl Default for SetIO_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__SetIO_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__SetIO_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetIO_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetIO_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetIO_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetIO_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetIO_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetIO_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/SetIO_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetIO_Request() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetIO_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__SetIO_Response__init(msg: *mut SetIO_Response) -> bool;
    fn aubo_msgs__srv__SetIO_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetIO_Response>, size: usize) -> bool;
    fn aubo_msgs__srv__SetIO_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetIO_Response>);
    fn aubo_msgs__srv__SetIO_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetIO_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetIO_Response>) -> bool;
}

// Corresponds to aubo_msgs__srv__SetIO_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetIO_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SetIO_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__SetIO_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__SetIO_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetIO_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetIO_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetIO_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__SetIO_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetIO_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetIO_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/SetIO_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__SetIO_Response() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__JsonRpc_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__JsonRpc_Request__init(msg: *mut JsonRpc_Request) -> bool;
    fn aubo_msgs__srv__JsonRpc_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<JsonRpc_Request>, size: usize) -> bool;
    fn aubo_msgs__srv__JsonRpc_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<JsonRpc_Request>);
    fn aubo_msgs__srv__JsonRpc_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<JsonRpc_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<JsonRpc_Request>) -> bool;
}

// Corresponds to aubo_msgs__srv__JsonRpc_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JsonRpc_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub cls: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub func: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub params: rosidl_runtime_rs::String,

}



impl Default for JsonRpc_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__JsonRpc_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__JsonRpc_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for JsonRpc_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__JsonRpc_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__JsonRpc_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__JsonRpc_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for JsonRpc_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for JsonRpc_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/JsonRpc_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__JsonRpc_Request() }
  }
}


#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__JsonRpc_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_msgs__srv__JsonRpc_Response__init(msg: *mut JsonRpc_Response) -> bool;
    fn aubo_msgs__srv__JsonRpc_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<JsonRpc_Response>, size: usize) -> bool;
    fn aubo_msgs__srv__JsonRpc_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<JsonRpc_Response>);
    fn aubo_msgs__srv__JsonRpc_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<JsonRpc_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<JsonRpc_Response>) -> bool;
}

// Corresponds to aubo_msgs__srv__JsonRpc_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JsonRpc_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: rosidl_runtime_rs::String,

}



impl Default for JsonRpc_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_msgs__srv__JsonRpc_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_msgs__srv__JsonRpc_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for JsonRpc_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__JsonRpc_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__JsonRpc_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_msgs__srv__JsonRpc_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for JsonRpc_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for JsonRpc_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_msgs/srv/JsonRpc_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_msgs__srv__JsonRpc_Response() }
  }
}






#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__SetPayload() -> *const std::ffi::c_void;
}

// Corresponds to aubo_msgs__srv__SetPayload
#[allow(missing_docs, non_camel_case_types)]
pub struct SetPayload;

impl rosidl_runtime_rs::Service for SetPayload {
    type Request = SetPayload_Request;
    type Response = SetPayload_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__SetPayload() }
    }
}




#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__SetSpeedSliderFraction() -> *const std::ffi::c_void;
}

// Corresponds to aubo_msgs__srv__SetSpeedSliderFraction
#[allow(missing_docs, non_camel_case_types)]
pub struct SetSpeedSliderFraction;

impl rosidl_runtime_rs::Service for SetSpeedSliderFraction {
    type Request = SetSpeedSliderFraction_Request;
    type Response = SetSpeedSliderFraction_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__SetSpeedSliderFraction() }
    }
}




#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__SetIO() -> *const std::ffi::c_void;
}

// Corresponds to aubo_msgs__srv__SetIO
#[allow(missing_docs, non_camel_case_types)]
pub struct SetIO;

impl rosidl_runtime_rs::Service for SetIO {
    type Request = SetIO_Request;
    type Response = SetIO_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__SetIO() }
    }
}




#[link(name = "aubo_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__JsonRpc() -> *const std::ffi::c_void;
}

// Corresponds to aubo_msgs__srv__JsonRpc
#[allow(missing_docs, non_camel_case_types)]
pub struct JsonRpc;

impl rosidl_runtime_rs::Service for JsonRpc {
    type Request = JsonRpc_Request;
    type Response = JsonRpc_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__aubo_msgs__srv__JsonRpc() }
    }
}


