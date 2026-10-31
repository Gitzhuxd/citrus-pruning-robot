# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.22.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(aubo_sdk-populate NONE)



include(ExternalProject)
ExternalProject_Add(aubo_sdk-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://download.aubo-robotics.cn/sdk/aubo_sdk-0.24.1-rc.3-Linux_x86_64+318754d.zip"
                    SOURCE_DIR          "/home/zhuxd/aubo_ws/build/aubo_ros2_driver/_deps/aubo_sdk-src"
                    BINARY_DIR          "/home/zhuxd/aubo_ws/build/aubo_ros2_driver/_deps/aubo_sdk-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


