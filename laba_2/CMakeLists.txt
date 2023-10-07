cmake_minimum_required(VERSION 3.10)
project(Laba_2_OOP)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp hex.cpp)


enable_testing()
add_executable(test_zero test.cpp  hex.cpp)
target_link_libraries(test_zero ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test_zero)