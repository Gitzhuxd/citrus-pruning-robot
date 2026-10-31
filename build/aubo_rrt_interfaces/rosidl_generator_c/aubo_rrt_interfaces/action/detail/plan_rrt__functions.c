// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aubo_rrt_interfaces:action/PlanRRT.idl
// generated code does not contain a copyright notice
#include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"

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
aubo_rrt_interfaces__action__PlanRRT_Goal__init(aubo_rrt_interfaces__action__PlanRRT_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // start
  if (!aubo_rrt_interfaces__msg__Endpoint__init(&msg->start)) {
    aubo_rrt_interfaces__action__PlanRRT_Goal__fini(msg);
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__msg__Endpoint__init(&msg->goal)) {
    aubo_rrt_interfaces__action__PlanRRT_Goal__fini(msg);
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
aubo_rrt_interfaces__action__PlanRRT_Goal__fini(aubo_rrt_interfaces__action__PlanRRT_Goal * msg)
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
aubo_rrt_interfaces__action__PlanRRT_Goal__are_equal(const aubo_rrt_interfaces__action__PlanRRT_Goal * lhs, const aubo_rrt_interfaces__action__PlanRRT_Goal * rhs)
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
aubo_rrt_interfaces__action__PlanRRT_Goal__copy(
  const aubo_rrt_interfaces__action__PlanRRT_Goal * input,
  aubo_rrt_interfaces__action__PlanRRT_Goal * output)
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

aubo_rrt_interfaces__action__PlanRRT_Goal *
aubo_rrt_interfaces__action__PlanRRT_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Goal * msg = (aubo_rrt_interfaces__action__PlanRRT_Goal *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_Goal));
  bool success = aubo_rrt_interfaces__action__PlanRRT_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_Goal__destroy(aubo_rrt_interfaces__action__PlanRRT_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Goal * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_Goal *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_Goal__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_Goal__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence *
aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_Goal * data =
      (aubo_rrt_interfaces__action__PlanRRT_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// Member `output_directory`
#include "rosidl_runtime_c/string_functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_Result__init(aubo_rrt_interfaces__action__PlanRRT_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    aubo_rrt_interfaces__action__PlanRRT_Result__fini(msg);
    return false;
  }
  // output_directory
  if (!rosidl_runtime_c__String__init(&msg->output_directory)) {
    aubo_rrt_interfaces__action__PlanRRT_Result__fini(msg);
    return false;
  }
  // iterations
  // tree_nodes
  // path_nodes
  // planning_seconds
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_Result__fini(aubo_rrt_interfaces__action__PlanRRT_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // output_directory
  rosidl_runtime_c__String__fini(&msg->output_directory);
  // iterations
  // tree_nodes
  // path_nodes
  // planning_seconds
}

bool
aubo_rrt_interfaces__action__PlanRRT_Result__are_equal(const aubo_rrt_interfaces__action__PlanRRT_Result * lhs, const aubo_rrt_interfaces__action__PlanRRT_Result * rhs)
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
  // output_directory
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->output_directory), &(rhs->output_directory)))
  {
    return false;
  }
  // iterations
  if (lhs->iterations != rhs->iterations) {
    return false;
  }
  // tree_nodes
  if (lhs->tree_nodes != rhs->tree_nodes) {
    return false;
  }
  // path_nodes
  if (lhs->path_nodes != rhs->path_nodes) {
    return false;
  }
  // planning_seconds
  if (lhs->planning_seconds != rhs->planning_seconds) {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_Result__copy(
  const aubo_rrt_interfaces__action__PlanRRT_Result * input,
  aubo_rrt_interfaces__action__PlanRRT_Result * output)
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
  // output_directory
  if (!rosidl_runtime_c__String__copy(
      &(input->output_directory), &(output->output_directory)))
  {
    return false;
  }
  // iterations
  output->iterations = input->iterations;
  // tree_nodes
  output->tree_nodes = input->tree_nodes;
  // path_nodes
  output->path_nodes = input->path_nodes;
  // planning_seconds
  output->planning_seconds = input->planning_seconds;
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_Result *
aubo_rrt_interfaces__action__PlanRRT_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Result * msg = (aubo_rrt_interfaces__action__PlanRRT_Result *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_Result));
  bool success = aubo_rrt_interfaces__action__PlanRRT_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_Result__destroy(aubo_rrt_interfaces__action__PlanRRT_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Result * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_Result *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_Result__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_Result__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_Result__Sequence *
aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_Result__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_Result__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_Result * data =
      (aubo_rrt_interfaces__action__PlanRRT_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `phase`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_Feedback__init(aubo_rrt_interfaces__action__PlanRRT_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__init(&msg->phase)) {
    aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(msg);
    return false;
  }
  // iterations
  // tree_nodes
  // elapsed_seconds
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(aubo_rrt_interfaces__action__PlanRRT_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // phase
  rosidl_runtime_c__String__fini(&msg->phase);
  // iterations
  // tree_nodes
  // elapsed_seconds
}

bool
aubo_rrt_interfaces__action__PlanRRT_Feedback__are_equal(const aubo_rrt_interfaces__action__PlanRRT_Feedback * lhs, const aubo_rrt_interfaces__action__PlanRRT_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->phase), &(rhs->phase)))
  {
    return false;
  }
  // iterations
  if (lhs->iterations != rhs->iterations) {
    return false;
  }
  // tree_nodes
  if (lhs->tree_nodes != rhs->tree_nodes) {
    return false;
  }
  // elapsed_seconds
  if (lhs->elapsed_seconds != rhs->elapsed_seconds) {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_Feedback__copy(
  const aubo_rrt_interfaces__action__PlanRRT_Feedback * input,
  aubo_rrt_interfaces__action__PlanRRT_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // phase
  if (!rosidl_runtime_c__String__copy(
      &(input->phase), &(output->phase)))
  {
    return false;
  }
  // iterations
  output->iterations = input->iterations;
  // tree_nodes
  output->tree_nodes = input->tree_nodes;
  // elapsed_seconds
  output->elapsed_seconds = input->elapsed_seconds;
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_Feedback *
aubo_rrt_interfaces__action__PlanRRT_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Feedback * msg = (aubo_rrt_interfaces__action__PlanRRT_Feedback *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_Feedback));
  bool success = aubo_rrt_interfaces__action__PlanRRT_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_Feedback__destroy(aubo_rrt_interfaces__action__PlanRRT_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Feedback * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_Feedback *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence *
aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_Feedback * data =
      (aubo_rrt_interfaces__action__PlanRRT_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__action__PlanRRT_Goal__init(&msg->goal)) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  aubo_rrt_interfaces__action__PlanRRT_Goal__fini(&msg->goal);
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__are_equal(const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * lhs, const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__action__PlanRRT_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__copy(
  const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * input,
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!aubo_rrt_interfaces__action__PlanRRT_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request *
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * msg = (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request));
  bool success = aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__destroy(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence *
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request * data =
      (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__are_equal(const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * lhs, const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__copy(
  const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * input,
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response *
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * msg = (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response));
  bool success = aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__destroy(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence *
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response * data =
      (aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__are_equal(const aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * lhs, const aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__copy(
  const aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * input,
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_GetResult_Request *
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * msg = (aubo_rrt_interfaces__action__PlanRRT_GetResult_Request *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request));
  bool success = aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__destroy(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_GetResult_Request *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence *
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Request * data =
      (aubo_rrt_interfaces__action__PlanRRT_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!aubo_rrt_interfaces__action__PlanRRT_Result__init(&msg->result)) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  aubo_rrt_interfaces__action__PlanRRT_Result__fini(&msg->result);
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__are_equal(const aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * lhs, const aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!aubo_rrt_interfaces__action__PlanRRT_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__copy(
  const aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * input,
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!aubo_rrt_interfaces__action__PlanRRT_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_GetResult_Response *
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * msg = (aubo_rrt_interfaces__action__PlanRRT_GetResult_Response *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response));
  bool success = aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__destroy(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_GetResult_Response *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence *
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_GetResult_Response * data =
      (aubo_rrt_interfaces__action__PlanRRT_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "aubo_rrt_interfaces/action/detail/plan_rrt__functions.h"

bool
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__init(&msg->feedback)) {
    aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  aubo_rrt_interfaces__action__PlanRRT_Feedback__fini(&msg->feedback);
}

bool
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__are_equal(const aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * lhs, const aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__copy(
  const aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * input,
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!aubo_rrt_interfaces__action__PlanRRT_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage *
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * msg = (aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage));
  bool success = aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__destroy(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__init(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(&data[i - 1]);
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
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__fini(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * array)
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
      aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(&array->data[i]);
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

aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence *
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * array = (aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__destroy(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__are_equal(const aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * lhs, const aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence__copy(
  const aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * input,
  aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage * data =
      (aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__action__PlanRRT_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
