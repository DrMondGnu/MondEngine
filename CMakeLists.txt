cmake_minimum_required(VERSION 3.27)
project(MondEngine)

set(CMAKE_CXX_STANDARD 23)

set(spdlog_DIR libs/spdlog/build)

find_package(spdlog REQUIRED)

include_directories(libs/spdlog/include)

add_library(MondEngine SHARED
        src/engine/log.cpp
        include/engine/log.h
)
add_library(MondEngine_lib STATIC
        src/engine/log.cpp
        include/engine/log.h
)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE)

target_link_libraries(MondEngine PRIVATE spdlog::spdlog)
target_link_libraries(MondEngine_lib PRIVATE spdlog::spdlog)

target_include_directories(MondEngine PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MondEngine_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(tests)
