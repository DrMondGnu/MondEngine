cmake_minimum_required(VERSION 3.27)

add_executable(MondEngineTests lib/doctest.h src/logging_test.cpp
        src/node_tests.cpp
        src/DoctestImpl.cpp
        src/Event/EventTests.cpp
        src/PlatformTests.cpp
        src/Graphics/RendererTests.cpp
        src/File/FileReaderTests.cpp
        src/Graphics/ShapesTests.cpp
        src/Graphics/TestingUtil.cpp)

target_include_directories(MondEngineTests PUBLIC lib)

target_link_libraries(MondEngineTests MondEngine)

target_compile_definitions(MondEngineTests PUBLIC MOND_ENGINE_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources")