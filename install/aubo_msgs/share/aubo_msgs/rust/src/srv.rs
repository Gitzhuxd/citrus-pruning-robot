#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to aubo_msgs__srv__SetPayload_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPayload_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mass: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_of_gravity: geometry_msgs::msg::Vector3,

}



impl Default for SetPayload_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetPayload_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetPayload_Request {
  type RmwMsg = super::srv::rmw::SetPayload_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mass: msg.mass,
        center_of_gravity: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Owned(msg.center_of_gravity)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mass: msg.mass,
        center_of_gravity: geometry_msgs::msg::Vector3::into_rmw_message(std::borrow::Cow::Borrowed(&msg.center_of_gravity)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mass: msg.mass,
      center_of_gravity: geometry_msgs::msg::Vector3::from_rmw_message(msg.center_of_gravity),
    }
  }
}


// Corresponds to aubo_msgs__srv__SetPayload_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPayload_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SetPayload_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetPayload_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetPayload_Response {
  type RmwMsg = super::srv::rmw::SetPayload_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to aubo_msgs__srv__SetSpeedSliderFraction_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeedSliderFraction_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub speed_slider_fraction: f64,

}



impl Default for SetSpeedSliderFraction_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetSpeedSliderFraction_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetSpeedSliderFraction_Request {
  type RmwMsg = super::srv::rmw::SetSpeedSliderFraction_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        speed_slider_fraction: msg.speed_slider_fraction,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      speed_slider_fraction: msg.speed_slider_fraction,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      speed_slider_fraction: msg.speed_slider_fraction,
    }
  }
}


// Corresponds to aubo_msgs__srv__SetSpeedSliderFraction_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetSpeedSliderFraction_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SetSpeedSliderFraction_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetSpeedSliderFraction_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetSpeedSliderFraction_Response {
  type RmwMsg = super::srv::rmw::SetSpeedSliderFraction_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to aubo_msgs__srv__SetIO_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetIO_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetIO_Request {
  type RmwMsg = super::srv::rmw::SetIO_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        fun: msg.fun,
        pin: msg.pin,
        state: msg.state,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      fun: msg.fun,
      pin: msg.pin,
      state: msg.state,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      fun: msg.fun,
      pin: msg.pin,
      state: msg.state,
    }
  }
}


// Corresponds to aubo_msgs__srv__SetIO_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetIO_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SetIO_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetIO_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetIO_Response {
  type RmwMsg = super::srv::rmw::SetIO_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to aubo_msgs__srv__JsonRpc_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JsonRpc_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub cls: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub func: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub params: std::string::String,

}



impl Default for JsonRpc_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::JsonRpc_Request::default())
  }
}

impl rosidl_runtime_rs::Message for JsonRpc_Request {
  type RmwMsg = super::srv::rmw::JsonRpc_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        cls: msg.cls.as_str().into(),
        func: msg.func.as_str().into(),
        params: msg.params.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        cls: msg.cls.as_str().into(),
        func: msg.func.as_str().into(),
        params: msg.params.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      cls: msg.cls.to_string(),
      func: msg.func.to_string(),
      params: msg.params.to_string(),
    }
  }
}


// Corresponds to aubo_msgs__srv__JsonRpc_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JsonRpc_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: std::string::String,

}



impl Default for JsonRpc_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::JsonRpc_Response::default())
  }
}

impl rosidl_runtime_rs::Message for JsonRpc_Response {
  type RmwMsg = super::srv::rmw::JsonRpc_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result.as_str().into(),
        error: msg.error.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result.as_str().into(),
        error: msg.error.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result.to_string(),
      error: msg.error.to_string(),
    }
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


