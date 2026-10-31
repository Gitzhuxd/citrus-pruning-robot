#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to aubo_rrt_interfaces__msg__Endpoint

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Endpoint {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::PoseStamped,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Endpoint::default())
  }
}

impl rosidl_runtime_rs::Message for Endpoint {
  type RmwMsg = super::msg::rmw::Endpoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mode: msg.mode,
        name: msg.name.as_str().into(),
        pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mode: msg.mode,
        name: msg.name.as_str().into(),
        pose: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mode: msg.mode,
      name: msg.name.to_string(),
      pose: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.pose),
    }
  }
}


