// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.h"
#include "aubo_rrt_interfaces/srv/detail/preview_rrt__functions.h"

bool aubo_rrt_interfaces__msg__endpoint__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * aubo_rrt_interfaces__msg__endpoint__convert_to_py(void * raw_ros_message);
bool aubo_rrt_interfaces__msg__endpoint__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * aubo_rrt_interfaces__msg__endpoint__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool aubo_rrt_interfaces__srv__preview_rrt__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("aubo_rrt_interfaces.srv._preview_rrt.PreviewRRT_Request", full_classname_dest, 55) == 0);
  }
  aubo_rrt_interfaces__srv__PreviewRRT_Request * ros_message = _ros_message;
  {  // start
    PyObject * field = PyObject_GetAttrString(_pymsg, "start");
    if (!field) {
      return false;
    }
    if (!aubo_rrt_interfaces__msg__endpoint__convert_from_py(field, &ros_message->start)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // goal
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal");
    if (!field) {
      return false;
    }
    if (!aubo_rrt_interfaces__msg__endpoint__convert_from_py(field, &ros_message->goal)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // step_size
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_size");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->step_size = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // goal_bias
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_bias");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->goal_bias = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // collision_step
    PyObject * field = PyObject_GetAttrString(_pymsg, "collision_step");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->collision_step = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_iterations
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_iterations");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_iterations = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // planning_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "planning_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->planning_time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // seed
    PyObject * field = PyObject_GetAttrString(_pymsg, "seed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->seed = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // replay_step
    PyObject * field = PyObject_GetAttrString(_pymsg, "replay_step");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->replay_step = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * aubo_rrt_interfaces__srv__preview_rrt__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PreviewRRT_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("aubo_rrt_interfaces.srv._preview_rrt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PreviewRRT_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  aubo_rrt_interfaces__srv__PreviewRRT_Request * ros_message = (aubo_rrt_interfaces__srv__PreviewRRT_Request *)raw_ros_message;
  {  // start
    PyObject * field = NULL;
    field = aubo_rrt_interfaces__msg__endpoint__convert_to_py(&ros_message->start);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "start", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal
    PyObject * field = NULL;
    field = aubo_rrt_interfaces__msg__endpoint__convert_to_py(&ros_message->goal);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_size
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->step_size);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_size", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_bias
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->goal_bias);
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_bias", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // collision_step
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->collision_step);
    {
      int rc = PyObject_SetAttrString(_pymessage, "collision_step", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_iterations
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max_iterations);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_iterations", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // planning_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->planning_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "planning_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // seed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->seed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "seed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // replay_step
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->replay_step);
    {
      int rc = PyObject_SetAttrString(_pymessage, "replay_step", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.h"
// already included above
// #include "aubo_rrt_interfaces/srv/detail/preview_rrt__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool moveit_msgs__msg__robot_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * moveit_msgs__msg__robot_state__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool moveit_msgs__msg__robot_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * moveit_msgs__msg__robot_state__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_stamped__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_stamped__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool aubo_rrt_interfaces__srv__preview_rrt__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("aubo_rrt_interfaces.srv._preview_rrt.PreviewRRT_Response", full_classname_dest, 56) == 0);
  }
  aubo_rrt_interfaces__srv__PreviewRRT_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // message
    PyObject * field = PyObject_GetAttrString(_pymsg, "message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // start_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_state");
    if (!field) {
      return false;
    }
    if (!moveit_msgs__msg__robot_state__convert_from_py(field, &ros_message->start_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // goal_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_state");
    if (!field) {
      return false;
    }
    if (!moveit_msgs__msg__robot_state__convert_from_py(field, &ros_message->goal_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // start_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose_stamped__convert_from_py(field, &ros_message->start_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // goal_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose_stamped__convert_from_py(field, &ros_message->goal_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * aubo_rrt_interfaces__srv__preview_rrt__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PreviewRRT_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("aubo_rrt_interfaces.srv._preview_rrt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PreviewRRT_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  aubo_rrt_interfaces__srv__PreviewRRT_Response * ros_message = (aubo_rrt_interfaces__srv__PreviewRRT_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->message.data,
      strlen(ros_message->message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_state
    PyObject * field = NULL;
    field = moveit_msgs__msg__robot_state__convert_to_py(&ros_message->start_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_state
    PyObject * field = NULL;
    field = moveit_msgs__msg__robot_state__convert_to_py(&ros_message->goal_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose_stamped__convert_to_py(&ros_message->start_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose_stamped__convert_to_py(&ros_message->goal_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
