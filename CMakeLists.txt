###################################################
# Project name: ivs2-mathlib
# Date:         2023-04-10
# File:         CMakeLists.txt
#
# Author: Zdeněk Borovec <xborov08@vutbr.cz>
# Author: Tomáš Krejčí   <xkrejc84@vutbr.cz>
# Author: Jan Lozrt      <xlozrt00@vutbr.cz>
# Author: Jakub Mitrenga <xmitre07@vutbr.cz>
#
# Description: 
#   This library aims to serve the needs of our second IVS project in the
#   academic year of 2022/2023 on BUT.
# 
###################################################

# == SETUP ==
cmake_minimum_required(VERSION 3.16)

set(namespace "ivsm")
project("ivs2-mathlib"
        VERSION 0.1
        DESCRIPTION "Math library for our IVS project"
)

set(CMAKE_CXX_STANDARD 17)


# == LIBRARY SETUP ==
add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/ivs-math.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # location of internal library headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # location of headers for use by tests
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        # location of headers for external projects
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set(public_headers inc/ivs-math.hpp)
# cmake modules location
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Install)


# == GOOGLETEST ==
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
option(INSTALL_GTEST OFF) # prevent including googletest in install
FetchContent_MakeAvailable(googletest)

# Test targets
enable_testing()

include(GoogleTest)

include_directories("inc")
include_directories("tst")
include_directories("src")

add_executable(tests tst/tests.cpp src/ivs-math.cpp)
target_link_libraries(tests gtest_main gmock_main)
gtest_discover_tests(tests)
