
cmake_minimum_required(VERSION 3.17.0)

if(NOT CMAKE_VERSION MATCHES "ReactOS")
    message(WARNING "Building with \"${CMAKE_COMMAND}\", which is not the custom CMake included in RosBE, might cause build issues...")
endif()

include(CMakeDependentOption)

# CMAKE_CROSSCOMPILING and MSVC_IDE are not set until project() is called, so let's test this instead
if ((DEFINED CMAKE_TOOLCHAIN_FILE) AND (CMAKE_GENERATOR MATCHES "Visual Studio.*"))
# Do not use MSVC_RUNTIME_LIBRARY target property. We use our own flags instead
message(WARNING "Setting policy CMP0091 to OLD behaviour")
cmake_policy(SET CMP0091 OLD)
endif()


enable_language(ASM)
enable_language(RC)

project(JARVISOS)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_SKIP_PREPROCESSED_SOURCE_RULES TRUE)
set(CMAKE_SKIP_ASSEMBLY_SOURCE_RULES TRUE)
set(CMAKE_COLOR_MAKEFILE OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE OFF)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
#set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)

if(NOT ARCH)
    message(FATAL_ERROR "Target architecture (ARCH) is not defined. Please, choose one of: i386")
endif()

string(TOLOWER ${ARCH} ARCH)
