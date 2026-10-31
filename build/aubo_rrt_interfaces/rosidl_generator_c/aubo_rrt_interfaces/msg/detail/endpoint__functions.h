// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from aubo_rrt_interfaces:msg/Endpoint.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__FUNCTIONS_H_
#define AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "aubo_rrt_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "aubo_rrt_interfaces/msg/detail/endpoint__struct.h"

/// Initialize msg/Endpoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * aubo_rrt_interfaces__msg__Endpoint
 * )) before or use
 * aubo_rrt_interfaces__msg__Endpoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__msg__Endpoint__init(aubo_rrt_interfaces__msg__Endpoint * msg);

/// Finalize msg/Endpoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__msg__Endpoint__fini(aubo_rrt_interfaces__msg__Endpoint * msg);

/// Create msg/Endpoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * aubo_rrt_interfaces__msg__Endpoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
aubo_rrt_interfaces__msg__Endpoint *
aubo_rrt_interfaces__msg__Endpoint__create();

/// Destroy msg/Endpoint message.
/**
 * It calls
 * aubo_rrt_interfaces__msg__Endpoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__msg__Endpoint__destroy(aubo_rrt_interfaces__msg__Endpoint * msg);

/// Check for msg/Endpoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__msg__Endpoint__are_equal(const aubo_rrt_interfaces__msg__Endpoint * lhs, const aubo_rrt_interfaces__msg__Endpoint * rhs);

/// Copy a msg/Endpoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__msg__Endpoint__copy(
  const aubo_rrt_interfaces__msg__Endpoint * input,
  aubo_rrt_interfaces__msg__Endpoint * output);

/// Initialize array of msg/Endpoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * aubo_rrt_interfaces__msg__Endpoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__msg__Endpoint__Sequence__init(aubo_rrt_interfaces__msg__Endpoint__Sequence * array, size_t size);

/// Finalize array of msg/Endpoint messages.
/**
 * It calls
 * aubo_rrt_interfaces__msg__Endpoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__msg__Endpoint__Sequence__fini(aubo_rrt_interfaces__msg__Endpoint__Sequence * array);

/// Create array of msg/Endpoint messages.
/**
 * It allocates the memory for the array and calls
 * aubo_rrt_interfaces__msg__Endpoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
aubo_rrt_interfaces__msg__Endpoint__Sequence *
aubo_rrt_interfaces__msg__Endpoint__Sequence__create(size_t size);

/// Destroy array of msg/Endpoint messages.
/**
 * It calls
 * aubo_rrt_interfaces__msg__Endpoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__msg__Endpoint__Sequence__destroy(aubo_rrt_interfaces__msg__Endpoint__Sequence * array);

/// Check for msg/Endpoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__msg__Endpoint__Sequence__are_equal(const aubo_rrt_interfaces__msg__Endpoint__Sequence * lhs, const aubo_rrt_interfaces__msg__Endpoint__Sequence * rhs);

/// Copy an array of msg/Endpoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__msg__Endpoint__Sequence__copy(
  const aubo_rrt_interfaces__msg__Endpoint__Sequence * input,
  aubo_rrt_interfaces__msg__Endpoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUBO_RRT_INTERFACES__MSG__DETAIL__ENDPOINT__FUNCTIONS_H_
