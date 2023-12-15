cmake_minimum_required(VERSION 3.14)
project(Laba_5_OOP)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})
add_executable(main main.cpp)


enable_testing()
add_executable(test_zero test.cpp  )
target_link_libraries(test_zero ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test_zero)