#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "aubo_rrt_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__msg__Endpoint() -> *const std::ffi::c_void;
}

#[link(name = "aubo_rrt_interfaces__rosidl_generator_c")]
extern "C" {
    fn aubo_rrt_interfaces__msg__Endpoint__init(msg: *mut Endpoint) -> bool;
    fn aubo_rrt_interfaces__msg__Endpoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Endpoint>, size: usize) -> bool;
    fn aubo_rrt_interfaces__msg__Endpoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Endpoint>);
    fn aubo_rrt_interfaces__msg__Endpoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Endpoint>, out_seq: *mut rosidl_runtime_rs::Sequence<Endpoint>) -> bool;
}

// Corresponds to aubo_rrt_interfaces__msg__Endpoint
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Endpoint {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::rmw::PoseStamped,

}

impl Endpoint {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CURRENT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NAMED: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POSE: u8 = 2;

}


impl Default for Endpoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !aubo_rrt_interfaces__msg__Endpoint__init(&mut msg as *mut _) {
        panic!("Call to aubo_rrt_interfaces__msg__Endpoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Endpoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__msg__Endpoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__msg__Endpoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { aubo_rrt_interfaces__msg__Endpoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Endpoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Endpoint where Self: Sized {
  const TYPE_NAME: &'static str = "aubo_rrt_interfaces/msg/Endpoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__aubo_rrt_interfaces__msg__Endpoint() }
  }
}


