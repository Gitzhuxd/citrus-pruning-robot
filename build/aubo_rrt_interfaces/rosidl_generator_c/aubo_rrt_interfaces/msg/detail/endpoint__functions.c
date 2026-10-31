// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aubo_rrt_interfaces:msg/Endpoint.idl
// generated code does not contain a copyright notice
#include "aubo_rrt_interfaces/msg/detail/endpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
aubo_rrt_interfaces__msg__Endpoint__init(aubo_rrt_interfaces__msg__Endpoint * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    aubo_rrt_interfaces__msg__Endpoint__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    aubo_rrt_interfaces__msg__Endpoint__fini(msg);
    return false;
  }
  return true;
}

void
aubo_rrt_interfaces__msg__Endpoint__fini(aubo_rrt_interfaces__msg__Endpoint * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
}

bool
aubo_rrt_interfaces__msg__Endpoint__are_equal(const aubo_rrt_interfaces__msg__Endpoint * lhs, const aubo_rrt_interfaces__msg__Endpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
aubo_rrt_interfaces__msg__Endpoint__copy(
  const aubo_rrt_interfaces__msg__Endpoint * input,
  aubo_rrt_interfaces__msg__Endpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

aubo_rrt_interfaces__msg__Endpoint *
aubo_rrt_interfaces__msg__Endpoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__msg__Endpoint * msg = (aubo_rrt_interfaces__msg__Endpoint *)allocator.allocate(sizeof(aubo_rrt_interfaces__msg__Endpoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aubo_rrt_interfaces__msg__Endpoint));
  bool success = aubo_rrt_interfaces__msg__Endpoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aubo_rrt_interfaces__msg__Endpoint__destroy(aubo_rrt_interfaces__msg__Endpoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aubo_rrt_interfaces__msg__Endpoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aubo_rrt_interfaces__msg__Endpoint__Sequence__init(aubo_rrt_interfaces__msg__Endpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__msg__Endpoint * data = NULL;

  if (size) {
    data = (aubo_rrt_interfaces__msg__Endpoint *)allocator.zero_allocate(size, sizeof(aubo_rrt_interfaces__msg__Endpoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aubo_rrt_interfaces__msg__Endpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aubo_rrt_interfaces__msg__Endpoint__fini(&data[i - 1]);
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
aubo_rrt_interfaces__msg__Endpoint__Sequence__fini(aubo_rrt_interfaces__msg__Endpoint__Sequence * array)
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
      aubo_rrt_interfaces__msg__Endpoint__fini(&array->data[i]);
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

aubo_rrt_interfaces__msg__Endpoint__Sequence *
aubo_rrt_interfaces__msg__Endpoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aubo_rrt_interfaces__msg__Endpoint__Sequence * array = (aubo_rrt_interfaces__msg__Endpoint__Sequence *)allocator.allocate(sizeof(aubo_rrt_interfaces__msg__Endpoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aubo_rrt_interfaces__msg__Endpoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aubo_rrt_interfaces__msg__Endpoint__Sequence__destroy(aubo_rrt_interfaces__msg__Endpoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aubo_rrt_interfaces__msg__Endpoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aubo_rrt_interfaces__msg__Endpoint__Sequence__are_equal(const aubo_rrt_interfaces__msg__Endpoint__Sequence * lhs, const aubo_rrt_interfaces__msg__Endpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aubo_rrt_interfaces__msg__Endpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aubo_rrt_interfaces__msg__Endpoint__Sequence__copy(
  const aubo_rrt_interfaces__msg__Endpoint__Sequence * input,
  aubo_rrt_interfaces__msg__Endpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aubo_rrt_interfaces__msg__Endpoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aubo_rrt_interfaces__msg__Endpoint * data =
      (aubo_rrt_interfaces__msg__Endpoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aubo_rrt_interfaces__msg__Endpoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aubo_rrt_interfaces__msg__Endpoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aubo_rrt_interfaces__msg__Endpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
