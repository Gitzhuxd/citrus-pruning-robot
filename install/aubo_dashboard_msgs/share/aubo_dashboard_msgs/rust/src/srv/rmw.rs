#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__AddToLog_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__AddToLog_Request__init(msg: *mut AddToLog_Request) -> bool;
    fn aubo_dashboard_msgs__srv__AddToLog_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AddToLog_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__AddToLog_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AddToLog_Request>);
    fn aubo_dashboard_msgs__srv__AddToLog_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AddToLog_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AddToLog_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__AddToLog_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddToLog_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for AddToLog_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__AddToLog_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__AddToLog_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AddToLog_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__AddToLog_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__AddToLog_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__AddToLog_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AddToLog_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AddToLog_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/AddToLog_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__AddToLog_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__AddToLog_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__AddToLog_Response__init(msg: *mut AddToLog_Response) -> bool;
    fn aubo_dashboard_msgs__srv__AddToLog_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AddToLog_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__AddToLog_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AddToLog_Response>);
    fn aubo_dashboard_msgs__srv__AddToLog_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AddToLog_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AddToLog_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__AddToLog_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AddToLog_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for AddToLog_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__AddToLog_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__AddToLog_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AddToLog_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__AddToLog_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__AddToLog_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__AddToLog_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AddToLog_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AddToLog_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/AddToLog_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__AddToLog_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetLoadedProgram_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Request__init(msg: *mut GetLoadedProgram_Request) -> bool;
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetLoadedProgram_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetLoadedProgram_Request>);
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetLoadedProgram_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetLoadedProgram_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetLoadedProgram_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetLoadedProgram_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetLoadedProgram_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetLoadedProgram_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetLoadedProgram_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetLoadedProgram_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetLoadedProgram_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetLoadedProgram_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetLoadedProgram_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetLoadedProgram_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetLoadedProgram_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetLoadedProgram_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetLoadedProgram_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetLoadedProgram_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Response__init(msg: *mut GetLoadedProgram_Response) -> bool;
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetLoadedProgram_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetLoadedProgram_Response>);
    fn aubo_dashboard_msgs__srv__GetLoadedProgram_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetLoadedProgram_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetLoadedProgram_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetLoadedProgram_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetLoadedProgram_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub program_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetLoadedProgram_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetLoadedProgram_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetLoadedProgram_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetLoadedProgram_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetLoadedProgram_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetLoadedProgram_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetLoadedProgram_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetLoadedProgram_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetLoadedProgram_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetLoadedProgram_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetLoadedProgram_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetProgramState_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetProgramState_Request__init(msg: *mut GetProgramState_Request) -> bool;
    fn aubo_dashboard_msgs__srv__GetProgramState_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetProgramState_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetProgramState_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetProgramState_Request>);
    fn aubo_dashboard_msgs__srv__GetProgramState_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetProgramState_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetProgramState_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetProgramState_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetProgramState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetProgramState_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetProgramState_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetProgramState_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetProgramState_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetProgramState_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetProgramState_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetProgramState_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetProgramState_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetProgramState_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetProgramState_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetProgramState_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetProgramState_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetProgramState_Response__init(msg: *mut GetProgramState_Response) -> bool;
    fn aubo_dashboard_msgs__srv__GetProgramState_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetProgramState_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetProgramState_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetProgramState_Response>);
    fn aubo_dashboard_msgs__srv__GetProgramState_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetProgramState_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetProgramState_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetProgramState_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetProgramState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: super::super::msg::rmw::ProgramState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub program_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetProgramState_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetProgramState_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetProgramState_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetProgramState_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetProgramState_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetProgramState_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetProgramState_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetProgramState_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetProgramState_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetProgramState_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetProgramState_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetRobotMode_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetRobotMode_Request__init(msg: *mut GetRobotMode_Request) -> bool;
    fn aubo_dashboard_msgs__srv__GetRobotMode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRobotMode_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetRobotMode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRobotMode_Request>);
    fn aubo_dashboard_msgs__srv__GetRobotMode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRobotMode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRobotMode_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetRobotMode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRobotMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetRobotMode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetRobotMode_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetRobotMode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRobotMode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetRobotMode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetRobotMode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetRobotMode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRobotMode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRobotMode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetRobotMode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetRobotMode_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetRobotMode_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetRobotMode_Response__init(msg: *mut GetRobotMode_Response) -> bool;
    fn aubo_dashboard_msgs__srv__GetRobotMode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRobotMode_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetRobotMode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRobotMode_Response>);
    fn aubo_dashboard_msgs__srv__GetRobotMode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRobotMode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRobotMode_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetRobotMode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRobotMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub robot_mode: super::super::msg::rmw::RobotMode,


    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetRobotMode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetRobotMode_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetRobotMode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRobotMode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetRobotMode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetRobotMode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetRobotMode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRobotMode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRobotMode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetRobotMode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetRobotMode_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetSafetyMode_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Request__init(msg: *mut GetSafetyMode_Request) -> bool;
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSafetyMode_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSafetyMode_Request>);
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSafetyMode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSafetyMode_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetSafetyMode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSafetyMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetSafetyMode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetSafetyMode_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetSafetyMode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSafetyMode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetSafetyMode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetSafetyMode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetSafetyMode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSafetyMode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSafetyMode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetSafetyMode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetSafetyMode_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetSafetyMode_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Response__init(msg: *mut GetSafetyMode_Response) -> bool;
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetSafetyMode_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetSafetyMode_Response>);
    fn aubo_dashboard_msgs__srv__GetSafetyMode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetSafetyMode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetSafetyMode_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__GetSafetyMode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetSafetyMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub safety_mode: super::super::msg::rmw::SafetyMode,


    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for GetSafetyMode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__GetSafetyMode_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__GetSafetyMode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetSafetyMode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetSafetyMode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetSafetyMode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__GetSafetyMode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetSafetyMode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetSafetyMode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/GetSafetyMode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__GetSafetyMode_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramRunning_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Request__init(msg: *mut IsProgramRunning_Request) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsProgramRunning_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsProgramRunning_Request>);
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsProgramRunning_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<IsProgramRunning_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__IsProgramRunning_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramRunning_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsProgramRunning_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__IsProgramRunning_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__IsProgramRunning_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsProgramRunning_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramRunning_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramRunning_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramRunning_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsProgramRunning_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsProgramRunning_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/IsProgramRunning_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramRunning_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramRunning_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Response__init(msg: *mut IsProgramRunning_Response) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsProgramRunning_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsProgramRunning_Response>);
    fn aubo_dashboard_msgs__srv__IsProgramRunning_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsProgramRunning_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<IsProgramRunning_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__IsProgramRunning_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramRunning_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,

    /// is a program running?
    pub program_running: bool,

    /// Did the dashboard server call succeed?
    pub success: bool,

}



impl Default for IsProgramRunning_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__IsProgramRunning_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__IsProgramRunning_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsProgramRunning_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramRunning_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramRunning_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramRunning_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsProgramRunning_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsProgramRunning_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/IsProgramRunning_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramRunning_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsInRemoteControl_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Request__init(msg: *mut IsInRemoteControl_Request) -> bool;
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsInRemoteControl_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsInRemoteControl_Request>);
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsInRemoteControl_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<IsInRemoteControl_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__IsInRemoteControl_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsInRemoteControl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsInRemoteControl_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__IsInRemoteControl_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__IsInRemoteControl_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsInRemoteControl_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsInRemoteControl_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsInRemoteControl_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsInRemoteControl_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsInRemoteControl_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsInRemoteControl_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/IsInRemoteControl_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsInRemoteControl_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsInRemoteControl_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Response__init(msg: *mut IsInRemoteControl_Response) -> bool;
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsInRemoteControl_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsInRemoteControl_Response>);
    fn aubo_dashboard_msgs__srv__IsInRemoteControl_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsInRemoteControl_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<IsInRemoteControl_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__IsInRemoteControl_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsInRemoteControl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,

    /// is the robot currently in remote control mode?
    pub in_remote_control: bool,

    /// Did the dashboard server call succeed?
    pub success: bool,

}



impl Default for IsInRemoteControl_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__IsInRemoteControl_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__IsInRemoteControl_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsInRemoteControl_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsInRemoteControl_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsInRemoteControl_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsInRemoteControl_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsInRemoteControl_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsInRemoteControl_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/IsInRemoteControl_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsInRemoteControl_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramSaved_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Request__init(msg: *mut IsProgramSaved_Request) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsProgramSaved_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsProgramSaved_Request>);
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsProgramSaved_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<IsProgramSaved_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__IsProgramSaved_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramSaved_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for IsProgramSaved_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__IsProgramSaved_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__IsProgramSaved_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsProgramSaved_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramSaved_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramSaved_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramSaved_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsProgramSaved_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsProgramSaved_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/IsProgramSaved_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramSaved_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramSaved_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Response__init(msg: *mut IsProgramSaved_Response) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<IsProgramSaved_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<IsProgramSaved_Response>);
    fn aubo_dashboard_msgs__srv__IsProgramSaved_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<IsProgramSaved_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<IsProgramSaved_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__IsProgramSaved_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IsProgramSaved_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub program_name: rosidl_runtime_rs::String,

    /// is the current program saved?
    pub program_saved: bool,

    /// Did the dashboard server call succeed?
    pub success: bool,

}



impl Default for IsProgramSaved_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__IsProgramSaved_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__IsProgramSaved_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for IsProgramSaved_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramSaved_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramSaved_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__IsProgramSaved_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for IsProgramSaved_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for IsProgramSaved_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/IsProgramSaved_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__IsProgramSaved_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Load_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__Load_Request__init(msg: *mut Load_Request) -> bool;
    fn aubo_dashboard_msgs__srv__Load_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Load_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__Load_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Load_Request>);
    fn aubo_dashboard_msgs__srv__Load_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Load_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Load_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__Load_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Load_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub filename: rosidl_runtime_rs::String,

}



impl Default for Load_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__Load_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__Load_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Load_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Load_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Load_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Load_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Load_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Load_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/Load_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Load_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Load_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__Load_Response__init(msg: *mut Load_Response) -> bool;
    fn aubo_dashboard_msgs__srv__Load_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Load_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__Load_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Load_Response>);
    fn aubo_dashboard_msgs__srv__Load_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Load_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Load_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__Load_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Load_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Load_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__Load_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__Load_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Load_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Load_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Load_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Load_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Load_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Load_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/Load_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Load_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Popup_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__Popup_Request__init(msg: *mut Popup_Request) -> bool;
    fn aubo_dashboard_msgs__srv__Popup_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Popup_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__Popup_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Popup_Request>);
    fn aubo_dashboard_msgs__srv__Popup_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Popup_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Popup_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__Popup_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Popup_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for Popup_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__Popup_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__Popup_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Popup_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Popup_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Popup_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Popup_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Popup_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Popup_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/Popup_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Popup_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Popup_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__Popup_Response__init(msg: *mut Popup_Response) -> bool;
    fn aubo_dashboard_msgs__srv__Popup_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Popup_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__Popup_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Popup_Response>);
    fn aubo_dashboard_msgs__srv__Popup_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Popup_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Popup_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__Popup_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Popup_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Popup_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__Popup_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__Popup_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Popup_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Popup_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Popup_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__Popup_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Popup_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Popup_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/Popup_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__Popup_Response() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__RawRequest_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__RawRequest_Request__init(msg: *mut RawRequest_Request) -> bool;
    fn aubo_dashboard_msgs__srv__RawRequest_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RawRequest_Request>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__RawRequest_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RawRequest_Request>);
    fn aubo_dashboard_msgs__srv__RawRequest_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RawRequest_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RawRequest_Request>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__RawRequest_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RawRequest_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub query: rosidl_runtime_rs::String,

}



impl Default for RawRequest_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__RawRequest_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__RawRequest_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RawRequest_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__RawRequest_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__RawRequest_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__RawRequest_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RawRequest_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RawRequest_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/RawRequest_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__RawRequest_Request() }
  }
}


#[link(name = "aubo_dashboard_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__RawRequest_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_dashboard_msgs__rosidl_generator_c")]
extern "C" {
    fn aubo_dashboard_msgs__srv__RawRequest_Response__init(msg: *mut RawRequest_Response) -> bool;
    fn aubo_dashboard_msgs__srv__RawRequest_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RawRequest_Response>, size: usize) -> bool;
    fn aubo_dashboard_msgs__srv__RawRequest_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RawRequest_Response>);
    fn aubo_dashboard_msgs__srv__RawRequest_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RawRequest_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RawRequest_Response>) -> bool;
}

// Corresponds to aubo_dashboard_msgs__srv__RawRequest_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RawRequest_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub answer: rosidl_runtime_rs::String,

}



impl Default for RawRequest_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_dashboard_msgs__srv__RawRequest_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_dashboard_msgs__srv__RawRequest_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RawRequest_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__RawRequest_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__RawRequest_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_dashboard_msgs__srv__RawRequest_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RawRequest_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RawRequest_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_dashboard_msgs/srv/RawRequest_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_dashboard_msgs__srv__RawRequest_Response() }
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


