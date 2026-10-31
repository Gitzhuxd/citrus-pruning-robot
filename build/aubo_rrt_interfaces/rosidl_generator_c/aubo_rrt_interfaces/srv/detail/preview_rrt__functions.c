// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice
#include "aubo_rrt_interfaces/srv/detail/preview_rrt__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `start`
// Member `goal`
#include "aubo_rrt_interfaces/msg/detail/endpoint__functions.h"

bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__init(aubo_rrt_interfaces__srv__PreviewRRT_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start
  if (!aubo_rrt_interfaces__msg__Endpoint__init(&msg->start)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(msg);
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__msg__Endpoint__init(&msg->goal)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(msg);
    return false;
  }
  // step_size
  // goal_bias
  // collision_step
  // max_iterations
  // planning_time
  // seed
  // replay_step
  return true;
}

void
aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(aubo_rrt_interfaces__srv__PreviewRRT_Request * msg)
{
  if (!msg) {
    return;
  }
  // start
  aubo_rrt_interfaces__msg__Endpoint__fini(&msg->start);
  // goal
  aubo_rrt_interfaces__msg__Endpoint__fini(&msg->goal);
  // step_size
  // goal_bias
  // collision_step
  // max_iterations
  // planning_time
  // seed
  // replay_step
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Request * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start
  if (!aubo_rrt_interfaces__msg__Endpoint__are_equal(
      &(lhs->start), &(rhs->start)))
  {
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__msg__Endpoint__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  // step_size
  if (lhs->step_size != rhs->step_size) {
    return false;
  }
  // goal_bias
  if (lhs->goal_bias != rhs->goal_bias) {
    return false;
  }
  // collision_step
  if (lhs->collision_step != rhs->collision_step) {
    return false;
  }
  // max_iterations
  if (lhs->max_iterations != rhs->max_iterations) {
    return false;
  }
  // planning_time
  if (lhs->planning_time != rhs->planning_time) {
    return false;
  }
  // seed
  if (lhs->seed != rhs->seed) {
    return false;
  }
  // replay_step
  if (lhs->replay_step != rhs->replay_step) {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Request * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start
  if (!aubo_rrt_interfaces__msg__Endpoint__copy(
      &(input->start), &(output->start)))
  {
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__msg__Endpoint__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  // step_size
  output->step_size = input->step_size;
  // goal_bias
  output->goal_bias = input->goal_bias;
  // collision_step
  output->collision_step = input->collision_step;
  // max_iterations
  output->max_iterations = input->max_iterations;
  // planning_time
  output->planning_time = input->planning_time;
  // seed
  output->seed = input->seed;
  // replay_step
  output->replay_step = input->replay_step;
  return true;
}

aubo_rrt_interfaces__srv__PreviewRRT_Request *
aubo_rrt_interfaces__srv__PreviewRRT_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__PreviewRRT_Request * msg = (aubo_rrt_interfaces__srv__PreviewRRT_Request *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Request));
  bool success = aubo_rrt_interfaces__srv__PreviewRRT_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__srv__PreviewRRT_Request__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__init(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__PreviewRRT_Request * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__srv__PreviewRRT_Request *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__srv__PreviewRRT_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(&data[i - 1]);
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
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__fini(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array)
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
      aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(&array->data[i]);
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

aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence *
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array = (aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__srv__PreviewRRT_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__srv__PreviewRRT_Request * data =
      (aubo_rrt_interfaces__srv__PreviewRRT_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__srv__PreviewRRT_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__srv__PreviewRRT_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `start_state`
// Member `goal_state`
#include "moveit_msgs/msg/detail/robot_state__functions.h"
// Member `start_pose`
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__init(aubo_rrt_interfaces__srv__PreviewRRT_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(msg);
    return false;
  }
  // start_state
  if (!moveit_msgs__msg__RobotState__init(&msg->start_state)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(msg);
    return false;
  }
  // goal_state
  if (!moveit_msgs__msg__RobotState__init(&msg->goal_state)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(msg);
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->start_pose)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(msg);
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->goal_pose)) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(aubo_rrt_interfaces__srv__PreviewRRT_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // start_state
  moveit_msgs__msg__RobotState__fini(&msg->start_state);
  // goal_state
  moveit_msgs__msg__RobotState__fini(&msg->goal_state);
  // start_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->start_pose);
  // goal_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->goal_pose);
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Response * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // start_state
  if (!moveit_msgs__msg__RobotState__are_equal(
      &(lhs->start_state), &(rhs->start_state)))
  {
    return false;
  }
  // goal_state
  if (!moveit_msgs__msg__RobotState__are_equal(
      &(lhs->goal_state), &(rhs->goal_state)))
  {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->start_pose), &(rhs->start_pose)))
  {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->goal_pose), &(rhs->goal_pose)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Response * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // start_state
  if (!moveit_msgs__msg__RobotState__copy(
      &(input->start_state), &(output->start_state)))
  {
    return false;
  }
  // goal_state
  if (!moveit_msgs__msg__RobotState__copy(
      &(input->goal_state), &(output->goal_state)))
  {
    return false;
  }
  // start_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->start_pose), &(output->start_pose)))
  {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->goal_pose), &(output->goal_pose)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__srv__PreviewRRT_Response *
aubo_rrt_interfaces__srv__PreviewRRT_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__PreviewRRT_Response * msg = (aubo_rrt_interfaces__srv__PreviewRRT_Response *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Response));
  bool success = aubo_rrt_interfaces__srv__PreviewRRT_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__srv__PreviewRRT_Response__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__init(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__PreviewRRT_Response * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__srv__PreviewRRT_Response *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__srv__PreviewRRT_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(&data[i - 1]);
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
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__fini(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array)
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
      aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(&array->data[i]);
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

aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence *
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array = (aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__srv__PreviewRRT_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__srv__PreviewRRT_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__srv__PreviewRRT_Response * data =
      (aubo_rrt_interfaces__srv__PreviewRRT_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__srv__PreviewRRT_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__srv__PreviewRRT_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
