cmake_minimum_required(VERSION 3.27)

add_executable(MondEngineTests doctest.h src/logging_test.cpp
        src/node_tests.cpp
        src/DoctestImpl.cpp
        src/EventTests.cpp
        src/PlatformTests.cpp)

target_link_libraries(MondEngineTests MondEngine)