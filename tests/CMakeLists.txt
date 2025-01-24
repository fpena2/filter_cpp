cmake_minimum_required(VERSION 3.28)

project(filter_cpp_tests)

# ##############################################################################
# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# ##############################################################################
# Add the test executable
file(GLOB SOURCES *.cpp)

add_executable(filter_cpp_tests ${SOURCES})

# ##############################################################################
# Link libraries
target_link_libraries(filter_cpp_tests GTest::gtest_main)

# ##############################################################################
# Register tests
include(GoogleTest)
gtest_discover_tests(filter_cpp_tests)
