cmake_minimum_required(VERSION 3.16)
project(ivs2-mathlib)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
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
