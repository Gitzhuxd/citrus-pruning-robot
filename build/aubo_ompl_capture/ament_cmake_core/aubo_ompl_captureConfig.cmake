# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_aubo_ompl_capture_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED aubo_ompl_capture_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(aubo_ompl_capture_FOUND FALSE)
  elseif(NOT aubo_ompl_capture_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(aubo_ompl_capture_FOUND FALSE)
  endif()
  return()
endif()
set(_aubo_ompl_capture_CONFIG_INCLUDED TRUE)

# output package information
if(NOT aubo_ompl_capture_FIND_QUIETLY)
  message(STATUS "Found aubo_ompl_capture: 0.1.0 (${aubo_ompl_capture_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'aubo_ompl_capture' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${aubo_ompl_capture_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(aubo_ompl_capture_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${aubo_ompl_capture_DIR}/${_extra}")
endforeach()
