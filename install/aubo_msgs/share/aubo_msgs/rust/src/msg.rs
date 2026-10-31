#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to aubo_msgs__msg__Analog

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Analog::default())
  }
}

impl rosidl_runtime_rs::Message for Analog {
  type RmwMsg = super::msg::rmw::Analog;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pin: msg.pin,
        domain: msg.domain,
        state: msg.state,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pin: msg.pin,
      domain: msg.domain,
      state: msg.state,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pin: msg.pin,
      domain: msg.domain,
      state: msg.state,
    }
  }
}


// Corresponds to aubo_msgs__msg__Digital

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Digital::default())
  }
}

impl rosidl_runtime_rs::Message for Digital {
  type RmwMsg = super::msg::rmw::Digital;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pin: msg.pin,
        state: msg.state,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pin: msg.pin,
      state: msg.state,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pin: msg.pin,
      state: msg.state,
    }
  }
}


// Corresponds to aubo_msgs__msg__IOStates

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IOStates {

    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_in_states: Vec<super::msg::Digital>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_out_states: Vec<super::msg::Digital>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub flag_states: Vec<super::msg::Digital>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_in_states: Vec<super::msg::Analog>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub analog_out_states: Vec<super::msg::Analog>,

}



impl Default for IOStates {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::IOStates::default())
  }
}

impl rosidl_runtime_rs::Message for IOStates {
  type RmwMsg = super::msg::rmw::IOStates;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        digital_in_states: msg.digital_in_states
          .into_iter()
          .map(|elem| super::msg::Digital::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        digital_out_states: msg.digital_out_states
          .into_iter()
          .map(|elem| super::msg::Digital::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        flag_states: msg.flag_states
          .into_iter()
          .map(|elem| super::msg::Digital::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        analog_in_states: msg.analog_in_states
          .into_iter()
          .map(|elem| super::msg::Analog::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        analog_out_states: msg.analog_out_states
          .into_iter()
          .map(|elem| super::msg::Analog::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        digital_in_states: msg.digital_in_states
          .iter()
          .map(|elem| super::msg::Digital::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        digital_out_states: msg.digital_out_states
          .iter()
          .map(|elem| super::msg::Digital::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        flag_states: msg.flag_states
          .iter()
          .map(|elem| super::msg::Digital::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        analog_in_states: msg.analog_in_states
          .iter()
          .map(|elem| super::msg::Analog::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        analog_out_states: msg.analog_out_states
          .iter()
          .map(|elem| super::msg::Analog::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      digital_in_states: msg.digital_in_states
          .into_iter()
          .map(super::msg::Digital::from_rmw_message)
          .collect(),
      digital_out_states: msg.digital_out_states
          .into_iter()
          .map(super::msg::Digital::from_rmw_message)
          .collect(),
      flag_states: msg.flag_states
          .into_iter()
          .map(super::msg::Digital::from_rmw_message)
          .collect(),
      analog_in_states: msg.analog_in_states
          .into_iter()
          .map(super::msg::Analog::from_rmw_message)
          .collect(),
      analog_out_states: msg.analog_out_states
          .into_iter()
          .map(super::msg::Analog::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to aubo_msgs__msg__RobotStateRTMsg
/// Data structure for the realtime communications interface (aka Matlab interface)
/// used by the Universal Robots controller
///
/// This data structure is send at 125 Hz on TCP port 30003
///
/// Dokumentation can be found on the Universal Robots Support Wiki
/// (http://wiki03.lynero.net/Technical/RealTimeClientInterface?rev=9)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotStateRTMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub time: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_target: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub qd_target: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub qdd_target: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub i_target: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub m_target: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_actual: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub qd_actual: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub i_actual: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_acc_values: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tcp_force: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_vector: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tcp_speed: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub digital_input_bits: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_temperatures: Vec<f64>,


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
    pub joint_modes: Vec<f64>,

}



impl Default for RobotStateRTMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RobotStateRTMsg::default())
  }
}

impl rosidl_runtime_rs::Message for RobotStateRTMsg {
  type RmwMsg = super::msg::rmw::RobotStateRTMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        time: msg.time,
        q_target: msg.q_target.into(),
        qd_target: msg.qd_target.into(),
        qdd_target: msg.qdd_target.into(),
        i_target: msg.i_target.into(),
        m_target: msg.m_target.into(),
        q_actual: msg.q_actual.into(),
        qd_actual: msg.qd_actual.into(),
        i_actual: msg.i_actual.into(),
        tool_acc_values: msg.tool_acc_values.into(),
        tcp_force: msg.tcp_force.into(),
        tool_vector: msg.tool_vector.into(),
        tcp_speed: msg.tcp_speed.into(),
        digital_input_bits: msg.digital_input_bits,
        motor_temperatures: msg.motor_temperatures.into(),
        controller_timer: msg.controller_timer,
        test_value: msg.test_value,
        robot_mode: msg.robot_mode,
        joint_modes: msg.joint_modes.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      time: msg.time,
        q_target: msg.q_target.as_slice().into(),
        qd_target: msg.qd_target.as_slice().into(),
        qdd_target: msg.qdd_target.as_slice().into(),
        i_target: msg.i_target.as_slice().into(),
        m_target: msg.m_target.as_slice().into(),
        q_actual: msg.q_actual.as_slice().into(),
        qd_actual: msg.qd_actual.as_slice().into(),
        i_actual: msg.i_actual.as_slice().into(),
        tool_acc_values: msg.tool_acc_values.as_slice().into(),
        tcp_force: msg.tcp_force.as_slice().into(),
        tool_vector: msg.tool_vector.as_slice().into(),
        tcp_speed: msg.tcp_speed.as_slice().into(),
      digital_input_bits: msg.digital_input_bits,
        motor_temperatures: msg.motor_temperatures.as_slice().into(),
      controller_timer: msg.controller_timer,
      test_value: msg.test_value,
      robot_mode: msg.robot_mode,
        joint_modes: msg.joint_modes.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      time: msg.time,
      q_target: msg.q_target
          .into_iter()
          .collect(),
      qd_target: msg.qd_target
          .into_iter()
          .collect(),
      qdd_target: msg.qdd_target
          .into_iter()
          .collect(),
      i_target: msg.i_target
          .into_iter()
          .collect(),
      m_target: msg.m_target
          .into_iter()
          .collect(),
      q_actual: msg.q_actual
          .into_iter()
          .collect(),
      qd_actual: msg.qd_actual
          .into_iter()
          .collect(),
      i_actual: msg.i_actual
          .into_iter()
          .collect(),
      tool_acc_values: msg.tool_acc_values
          .into_iter()
          .collect(),
      tcp_force: msg.tcp_force
          .into_iter()
          .collect(),
      tool_vector: msg.tool_vector
          .into_iter()
          .collect(),
      tcp_speed: msg.tcp_speed
          .into_iter()
          .collect(),
      digital_input_bits: msg.digital_input_bits,
      motor_temperatures: msg.motor_temperatures
          .into_iter()
          .collect(),
      controller_timer: msg.controller_timer,
      test_value: msg.test_value,
      robot_mode: msg.robot_mode,
      joint_modes: msg.joint_modes
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to aubo_msgs__msg__MasterboardDataMsg
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

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MasterboardDataMsg::default())
  }
}

impl rosidl_runtime_rs::Message for MasterboardDataMsg {
  type RmwMsg = super::msg::rmw::MasterboardDataMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        digital_input_bits: msg.digital_input_bits,
        digital_output_bits: msg.digital_output_bits,
        analog_input_range0: msg.analog_input_range0,
        analog_input_range1: msg.analog_input_range1,
        analog_input0: msg.analog_input0,
        analog_input1: msg.analog_input1,
        analog_output_domain0: msg.analog_output_domain0,
        analog_output_domain1: msg.analog_output_domain1,
        analog_output0: msg.analog_output0,
        analog_output1: msg.analog_output1,
        masterboard_temperature: msg.masterboard_temperature,
        robot_voltage_48v: msg.robot_voltage_48v,
        robot_current: msg.robot_current,
        master_io_current: msg.master_io_current,
        master_safety_state: msg.master_safety_state,
        master_onoff_state: msg.master_onoff_state,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      digital_input_bits: msg.digital_input_bits,
      digital_output_bits: msg.digital_output_bits,
      analog_input_range0: msg.analog_input_range0,
      analog_input_range1: msg.analog_input_range1,
      analog_input0: msg.analog_input0,
      analog_input1: msg.analog_input1,
      analog_output_domain0: msg.analog_output_domain0,
      analog_output_domain1: msg.analog_output_domain1,
      analog_output0: msg.analog_output0,
      analog_output1: msg.analog_output1,
      masterboard_temperature: msg.masterboard_temperature,
      robot_voltage_48v: msg.robot_voltage_48v,
      robot_current: msg.robot_current,
      master_io_current: msg.master_io_current,
      master_safety_state: msg.master_safety_state,
      master_onoff_state: msg.master_onoff_state,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      digital_input_bits: msg.digital_input_bits,
      digital_output_bits: msg.digital_output_bits,
      analog_input_range0: msg.analog_input_range0,
      analog_input_range1: msg.analog_input_range1,
      analog_input0: msg.analog_input0,
      analog_input1: msg.analog_input1,
      analog_output_domain0: msg.analog_output_domain0,
      analog_output_domain1: msg.analog_output_domain1,
      analog_output0: msg.analog_output0,
      analog_output1: msg.analog_output1,
      masterboard_temperature: msg.masterboard_temperature,
      robot_voltage_48v: msg.robot_voltage_48v,
      robot_current: msg.robot_current,
      master_io_current: msg.master_io_current,
      master_safety_state: msg.master_safety_state,
      master_onoff_state: msg.master_onoff_state,
    }
  }
}


// Corresponds to aubo_msgs__msg__RobotModeDataMsg
/// This data structure contains the RobotModeData structure
/// used by the Universal Robots controller
///
/// This data structure is send at 10 Hz on TCP port 30002
///
/// Note: this message does not carry all fields from the RobotModeData structure as broadcast by the robot controller, but a subset.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::RobotModeDataMsg::default())
  }
}

impl rosidl_runtime_rs::Message for RobotModeDataMsg {
  type RmwMsg = super::msg::rmw::RobotModeDataMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        timestamp: msg.timestamp,
        is_robot_connected: msg.is_robot_connected,
        is_real_robot_enabled: msg.is_real_robot_enabled,
        is_power_on_robot: msg.is_power_on_robot,
        is_emergency_stopped: msg.is_emergency_stopped,
        is_protective_stopped: msg.is_protective_stopped,
        is_program_running: msg.is_program_running,
        is_program_paused: msg.is_program_paused,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      timestamp: msg.timestamp,
      is_robot_connected: msg.is_robot_connected,
      is_real_robot_enabled: msg.is_real_robot_enabled,
      is_power_on_robot: msg.is_power_on_robot,
      is_emergency_stopped: msg.is_emergency_stopped,
      is_protective_stopped: msg.is_protective_stopped,
      is_program_running: msg.is_program_running,
      is_program_paused: msg.is_program_paused,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      timestamp: msg.timestamp,
      is_robot_connected: msg.is_robot_connected,
      is_real_robot_enabled: msg.is_real_robot_enabled,
      is_power_on_robot: msg.is_power_on_robot,
      is_emergency_stopped: msg.is_emergency_stopped,
      is_protective_stopped: msg.is_protective_stopped,
      is_program_running: msg.is_program_running,
      is_program_paused: msg.is_program_paused,
    }
  }
}


// Corresponds to aubo_msgs__msg__ToolDataMsg
/// This data structure contains the ToolData structure
/// used by the Universal Robots controller

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ToolDataMsg::default())
  }
}

impl rosidl_runtime_rs::Message for ToolDataMsg {
  type RmwMsg = super::msg::rmw::ToolDataMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        analog_input_range2: msg.analog_input_range2,
        analog_input_range3: msg.analog_input_range3,
        analog_input2: msg.analog_input2,
        analog_input3: msg.analog_input3,
        tool_voltage_48v: msg.tool_voltage_48v,
        tool_output_voltage: msg.tool_output_voltage,
        tool_current: msg.tool_current,
        tool_temperature: msg.tool_temperature,
        tool_mode: msg.tool_mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      analog_input_range2: msg.analog_input_range2,
      analog_input_range3: msg.analog_input_range3,
      analog_input2: msg.analog_input2,
      analog_input3: msg.analog_input3,
      tool_voltage_48v: msg.tool_voltage_48v,
      tool_output_voltage: msg.tool_output_voltage,
      tool_current: msg.tool_current,
      tool_temperature: msg.tool_temperature,
      tool_mode: msg.tool_mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      analog_input_range2: msg.analog_input_range2,
      analog_input_range3: msg.analog_input_range3,
      analog_input2: msg.analog_input2,
      analog_input3: msg.analog_input3,
      tool_voltage_48v: msg.tool_voltage_48v,
      tool_output_voltage: msg.tool_output_voltage,
      tool_current: msg.tool_current,
      tool_temperature: msg.tool_temperature,
      tool_mode: msg.tool_mode,
    }
  }
}


