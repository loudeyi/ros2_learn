#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to chapt4_interfaces__srv__FaceDetector_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FaceDetector_Request {
    /// 人脸图像
    pub image: sensor_msgs::msg::Image,

}



impl Default for FaceDetector_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::FaceDetector_Request::default())
  }
}

impl rosidl_runtime_rs::Message for FaceDetector_Request {
  type RmwMsg = super::srv::rmw::FaceDetector_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Owned(msg.image)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        image: sensor_msgs::msg::Image::into_rmw_message(std::borrow::Cow::Borrowed(&msg.image)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      image: sensor_msgs::msg::Image::from_rmw_message(msg.image),
    }
  }
}


// Corresponds to chapt4_interfaces__srv__FaceDetector_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FaceDetector_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub number: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub use_time: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub top: Vec<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right: Vec<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bottom: Vec<i32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left: Vec<i32>,

}



impl Default for FaceDetector_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::FaceDetector_Response::default())
  }
}

impl rosidl_runtime_rs::Message for FaceDetector_Response {
  type RmwMsg = super::srv::rmw::FaceDetector_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        number: msg.number,
        use_time: msg.use_time,
        top: msg.top.into(),
        right: msg.right.into(),
        bottom: msg.bottom.into(),
        left: msg.left.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      number: msg.number,
      use_time: msg.use_time,
        top: msg.top.as_slice().into(),
        right: msg.right.as_slice().into(),
        bottom: msg.bottom.as_slice().into(),
        left: msg.left.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      number: msg.number,
      use_time: msg.use_time,
      top: msg.top
          .into_iter()
          .collect(),
      right: msg.right
          .into_iter()
          .collect(),
      bottom: msg.bottom
          .into_iter()
          .collect(),
      left: msg.left
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to chapt4_interfaces__srv__Partol_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Partol_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_y: f32,

}



impl Default for Partol_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Partol_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Partol_Request {
  type RmwMsg = super::srv::rmw::Partol_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target_x: msg.target_x,
        target_y: msg.target_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      target_x: msg.target_x,
      target_y: msg.target_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target_x: msg.target_x,
      target_y: msg.target_y,
    }
  }
}


// Corresponds to chapt4_interfaces__srv__Partol_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Partol_Response {
    /// 结果,SUCCESS / FAIL 取其一
    pub result: i8,

}

impl Partol_Response {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SUCCESS: i8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FAIL: i8 = 0;

}


impl Default for Partol_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Partol_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Partol_Response {
  type RmwMsg = super::srv::rmw::Partol_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      result: msg.result,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result,
    }
  }
}






#[link(name = "chapt4_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__chapt4_interfaces__srv__FaceDetector() -> *const std::ffi::c_void;
}

// Corresponds to chapt4_interfaces__srv__FaceDetector
#[allow(missing_docs, non_camel_case_types)]
pub struct FaceDetector;

impl rosidl_runtime_rs::Service for FaceDetector {
    type Request = FaceDetector_Request;
    type Response = FaceDetector_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__chapt4_interfaces__srv__FaceDetector() }
    }
}




#[link(name = "chapt4_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__chapt4_interfaces__srv__Partol() -> *const std::ffi::c_void;
}

// Corresponds to chapt4_interfaces__srv__Partol
#[allow(missing_docs, non_camel_case_types)]
pub struct Partol;

impl rosidl_runtime_rs::Service for Partol {
    type Request = Partol_Request;
    type Response = Partol_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__chapt4_interfaces__srv__Partol() }
    }
}


