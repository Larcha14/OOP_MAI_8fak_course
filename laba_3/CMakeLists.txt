cmake_minimum_required(VERSION 3.10)
project(Laba_3_OOP)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(())

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp coord.cpp figure.cpp figure_array.cpp hexagon.cpp octagon.cpp hexagon.cpp triangle.cpp)


enable_testing()
add_executable(test_zero test.cpp  coord.cpp figure.cpp figure_array.cpp hexagon.cpp octagon.cpp hexagon.cpp triangle.cpp)
target_link_libraries(test_zero ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test_zero)