// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from aubo_rrt_interfaces:srv/PreviewRRT.idl
// generated code does not contain a copyright notice

#ifndef AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__FUNCTIONS_H_
#define AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "aubo_rrt_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "aubo_rrt_interfaces/srv/detail/preview_rrt__struct.h"

/// Initialize srv/PreviewRRT message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * aubo_rrt_interfaces__srv__PreviewRRT_Request
 * )) before or use
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__init(aubo_rrt_interfaces__srv__PreviewRRT_Request * msg);

/// Finalize srv/PreviewRRT message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Request__fini(aubo_rrt_interfaces__srv__PreviewRRT_Request * msg);

/// Create srv/PreviewRRT message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
aubo_rrt_interfaces__srv__PreviewRRT_Request *
aubo_rrt_interfaces__srv__PreviewRRT_Request__create();

/// Destroy srv/PreviewRRT message.
/**
 * It calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Request__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Request * msg);

/// Check for srv/PreviewRRT message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Request * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Request * rhs);

/// Copy a srv/PreviewRRT message.
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
aubo_rrt_interfaces__srv__PreviewRRT_Request__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Request * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Request * output);

/// Initialize array of srv/PreviewRRT messages.
/**
 * It allocates the memory for the number of elements and calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__init(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array, size_t size);

/// Finalize array of srv/PreviewRRT messages.
/**
 * It calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__fini(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array);

/// Create array of srv/PreviewRRT messages.
/**
 * It allocates the memory for the array and calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence *
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__create(size_t size);

/// Destroy array of srv/PreviewRRT messages.
/**
 * It calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * array);

/// Check for srv/PreviewRRT message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * rhs);

/// Copy an array of srv/PreviewRRT messages.
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
aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Request__Sequence * output);

/// Initialize srv/PreviewRRT message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * aubo_rrt_interfaces__srv__PreviewRRT_Response
 * )) before or use
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__init(aubo_rrt_interfaces__srv__PreviewRRT_Response * msg);

/// Finalize srv/PreviewRRT message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Response__fini(aubo_rrt_interfaces__srv__PreviewRRT_Response * msg);

/// Create srv/PreviewRRT message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
aubo_rrt_interfaces__srv__PreviewRRT_Response *
aubo_rrt_interfaces__srv__PreviewRRT_Response__create();

/// Destroy srv/PreviewRRT message.
/**
 * It calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Response__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Response * msg);

/// Check for srv/PreviewRRT message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Response * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Response * rhs);

/// Copy a srv/PreviewRRT message.
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
aubo_rrt_interfaces__srv__PreviewRRT_Response__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Response * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Response * output);

/// Initialize array of srv/PreviewRRT messages.
/**
 * It allocates the memory for the number of elements and calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__init(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array, size_t size);

/// Finalize array of srv/PreviewRRT messages.
/**
 * It calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__fini(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array);

/// Create array of srv/PreviewRRT messages.
/**
 * It allocates the memory for the array and calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence *
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__create(size_t size);

/// Destroy array of srv/PreviewRRT messages.
/**
 * It calls
 * aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
void
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__destroy(aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * array);

/// Check for srv/PreviewRRT message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aubo_rrt_interfaces
bool
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__are_equal(const aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * lhs, const aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * rhs);

/// Copy an array of srv/PreviewRRT messages.
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
aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence__copy(
  const aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * input,
  aubo_rrt_interfaces__srv__PreviewRRT_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUBO_RRT_INTERFACES__SRV__DETAIL__PREVIEW_RRT__FUNCTIONS_H_
