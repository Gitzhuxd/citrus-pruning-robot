
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_Goal() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_Goal__init(msg: *mut PlanRRT_Goal) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Goal>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Goal>);
    fn aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Goal>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start: super::super::msg::rmw::Endpoint,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::msg::rmw::Endpoint,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_Goal__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_Goal() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_Result() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_Result__init(msg: *mut PlanRRT_Result) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Result>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Result>);
    fn aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Result>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub output_directory: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_Result__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_Result where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_Result() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_Feedback__init(msg: *mut PlanRRT_Feedback) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Feedback>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Feedback>);
    fn aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_Feedback>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub phase: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_Feedback__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_Feedback() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(msg: *mut PlanRRT_FeedbackMessage) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_FeedbackMessage>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_FeedbackMessage>);
    fn aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_FeedbackMessage>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::PlanRRT_Feedback,

}



impl Default for PlanRRT_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage() }
  }
}




#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(msg: *mut PlanRRT_SendGoal_Request) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Request>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Request>);
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Request>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::PlanRRT_Goal,

}



impl Default for PlanRRT_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(msg: *mut PlanRRT_SendGoal_Response) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Response>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Response>);
    fn aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_SendGoal_Response>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for PlanRRT_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(msg: *mut PlanRRT_GetResult_Request) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Request>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Request>);
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Request>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for PlanRRT_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_GetResult_Request() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(msg: *mut PlanRRT_GetResult_Response) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Response>, size: usize) -> bool;
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Response>);
    fn aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PlanRRT_GetResult_Response>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__action__PlanRRT_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlanRRT_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::PlanRRT_Result,

}



impl Default for PlanRRT_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlanRRT_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlanRRT_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlanRRT_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/action/PlanRRT_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__action__PlanRRT_GetResult_Response() }
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


