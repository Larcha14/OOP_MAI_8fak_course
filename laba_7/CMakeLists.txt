cmake_minimum_required(VERSION 3.20)

project(lab7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMPILE_FILES
    src/Menu.cpp
    src/NPC.cpp
    src/NPCFabric.cpp
    src/ObserverConsolOutput.cpp
    src/ObserverFileOutput.cpp
    src/Visitor.cpp
    src/DeathHandler.cpp
    src/UI.cpp
    src/FightHandler.cpp
)

add_executable(lab7 main.cpp ${COMPILE_FILES})
add_executable(tests7 tests)

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(tests7 PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(NAME LAB7 COMMAND tests7)
