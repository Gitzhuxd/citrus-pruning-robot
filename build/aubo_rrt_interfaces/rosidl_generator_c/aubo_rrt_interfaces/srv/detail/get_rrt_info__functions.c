// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aubo_rrt_interfaces:srv/GetRRTInfo.idl
// generated code does not contain a copyright notice
#include "aubo_rrt_interfaces/srv/detail/get_rrt_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(aubo_rrt_interfaces__srv__GetRRTInfo_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Request__fini(aubo_rrt_interfaces__srv__GetRRTInfo_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Request__are_equal(const aubo_rrt_interfaces__srv__GetRRTInfo_Request * lhs, const aubo_rrt_interfaces__srv__GetRRTInfo_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Request__copy(
  const aubo_rrt_interfaces__srv__GetRRTInfo_Request * input,
  aubo_rrt_interfaces__srv__GetRRTInfo_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

aubo_rrt_interfaces__srv__GetRRTInfo_Request *
aubo_rrt_interfaces__srv__GetRRTInfo_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__GetRRTInfo_Request * msg = (aubo_rrt_interfaces__srv__GetRRTInfo_Request *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Request));
  bool success = aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Request__destroy(aubo_rrt_interfaces__srv__GetRRTInfo_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__init(aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__GetRRTInfo_Request * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__srv__GetRRTInfo_Request *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__srv__GetRRTInfo_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__fini(aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      aubo_rrt_interfaces__srv__GetRRTInfo_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence *
aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * array = (aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__destroy(aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__are_equal(const aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * lhs, const aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__srv__GetRRTInfo_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence__copy(
  const aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * input,
  aubo_rrt_interfaces__srv__GetRRTInfo_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__srv__GetRRTInfo_Request * data =
      (aubo_rrt_interfaces__srv__GetRRTInfo_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__srv__GetRRTInfo_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__srv__GetRRTInfo_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__srv__GetRRTInfo_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// Member `named_states`
#include "rosidl_runtime_c/string_functions.h"
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `current_state`
#include "moveit_msgs/msg/detail/robot_state__functions.h"

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(aubo_rrt_interfaces__srv__GetRRTInfo_Response * msg)
{
  if (!msg) {
    return false;
  }
  // ready
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(msg);
    return false;
  }
  // named_states
  if (!rosidl_runtime_c__String__Sequence__init(&msg->named_states, 0)) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(msg);
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->current_pose)) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(msg);
    return false;
  }
  // current_state
  if (!moveit_msgs__msg__RobotState__init(&msg->current_state)) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(aubo_rrt_interfaces__srv__GetRRTInfo_Response * msg)
{
  if (!msg) {
    return;
  }
  // ready
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // named_states
  rosidl_runtime_c__String__Sequence__fini(&msg->named_states);
  // current_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->current_pose);
  // current_state
  moveit_msgs__msg__RobotState__fini(&msg->current_state);
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Response__are_equal(const aubo_rrt_interfaces__srv__GetRRTInfo_Response * lhs, const aubo_rrt_interfaces__srv__GetRRTInfo_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ready
  if (lhs->ready != rhs->ready) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // named_states
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->named_states), &(rhs->named_states)))
  {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->current_pose), &(rhs->current_pose)))
  {
    return false;
  }
  // current_state
  if (!moveit_msgs__msg__RobotState__are_equal(
      &(lhs->current_state), &(rhs->current_state)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Response__copy(
  const aubo_rrt_interfaces__srv__GetRRTInfo_Response * input,
  aubo_rrt_interfaces__srv__GetRRTInfo_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // ready
  output->ready = input->ready;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // named_states
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->named_states), &(output->named_states)))
  {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->current_pose), &(output->current_pose)))
  {
    return false;
  }
  // current_state
  if (!moveit_msgs__msg__RobotState__copy(
      &(input->current_state), &(output->current_state)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__srv__GetRRTInfo_Response *
aubo_rrt_interfaces__srv__GetRRTInfo_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__GetRRTInfo_Response * msg = (aubo_rrt_interfaces__srv__GetRRTInfo_Response *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Response));
  bool success = aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Response__destroy(aubo_rrt_interfaces__srv__GetRRTInfo_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__init(aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__GetRRTInfo_Response * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__srv__GetRRTInfo_Response *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__fini(aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence *
aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * array = (aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__destroy(aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__are_equal(const aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * lhs, const aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__srv__GetRRTInfo_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence__copy(
  const aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * input,
  aubo_rrt_interfaces__srv__GetRRTInfo_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__srv__GetRRTInfo_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__srv__GetRRTInfo_Response * data =
      (aubo_rrt_interfaces__srv__GetRRTInfo_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__srv__GetRRTInfo_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__srv__GetRRTInfo_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__srv__GetRRTInfo_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
