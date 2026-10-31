#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__GetRRTInfo_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(msg: *mut GetRRTInfo_Request) -> bool;
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRRTInfo_Request>, size: usize) -> bool;
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRRTInfo_Request>);
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRRTInfo_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRRTInfo_Request>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__srv__GetRRTInfo_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRRTInfo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetRRTInfo_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__srv__GetRRTInfo_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRRTInfo_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRRTInfo_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRRTInfo_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/srv/GetRRTInfo_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__GetRRTInfo_Request() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__GetRRTInfo_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(msg: *mut GetRRTInfo_Response) -> bool;
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetRRTInfo_Response>, size: usize) -> bool;
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetRRTInfo_Response>);
    fn aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetRRTInfo_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetRRTInfo_Response>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__srv__GetRRTInfo_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetRRTInfo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub ready: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub named_states: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_pose: geometry_msgs::msg::rmw::PoseStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current_state: moveit_msgs::msg::rmw::RobotState,

}



impl Default for GetRRTInfo_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__srv__GetRRTInfo_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetRRTInfo_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetRRTInfo_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetRRTInfo_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/srv/GetRRTInfo_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__GetRRTInfo_Response() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__PreviewRRT_Request() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__srv__PreviewRRT_Request__init(msg: *mut PreviewRRT_Request) -> bool;
    fn aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PreviewRRT_Request>, size: usize) -> bool;
    fn aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PreviewRRT_Request>);
    fn aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PreviewRRT_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PreviewRRT_Request>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__srv__PreviewRRT_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PreviewRRT_Request {

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



impl Default for PreviewRRT_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__srv__PreviewRRT_Request__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__srv__PreviewRRT_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PreviewRRT_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PreviewRRT_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PreviewRRT_Request where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/srv/PreviewRRT_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__PreviewRRT_Request() }
  }
}


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__PreviewRRT_Response() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__srv__PreviewRRT_Response__init(msg: *mut PreviewRRT_Response) -> bool;
    fn aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PreviewRRT_Response>, size: usize) -> bool;
    fn aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PreviewRRT_Response>);
    fn aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PreviewRRT_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PreviewRRT_Response>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__srv__PreviewRRT_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PreviewRRT_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_state: moveit_msgs::msg::rmw::RobotState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_state: moveit_msgs::msg::rmw::RobotState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_pose: geometry_msgs::msg::rmw::PoseStamped,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_pose: geometry_msgs::msg::rmw::PoseStamped,

}



impl Default for PreviewRRT_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__srv__PreviewRRT_Response__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__srv__PreviewRRT_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PreviewRRT_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PreviewRRT_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PreviewRRT_Response where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/srv/PreviewRRT_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__srv__PreviewRRT_Response() }
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


