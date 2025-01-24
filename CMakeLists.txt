cmake_minimum_required(VERSION 3.28)

project(filter_cpp)

# ##############################################################################
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ##############################################################################
# Download and make GoogleTest availablewher
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip)

# NOTE: For Windows - Prevent overriding the parent project's compiler/linker
# settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ##############################################################################
# Add tests
enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
