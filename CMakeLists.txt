cmake_minimum_required(VERSION 3.27)
project(MondEngine)

set(CMAKE_CXX_STANDARD 23)

# SPDLOG
set(spdlog_DIR libs/spdlog/build)
find_package(spdlog REQUIRED)
include_directories(libs/spdlog/include)

# SDL2
set(SDL2_DIR libs/SDL2/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Shared Lib
add_library(MondEngine SHARED
        src/engine/log.cpp
        include/engine/log.h
)

# Static Lib for Tests
add_library(MondEngine_lib STATIC
        src/engine/log.cpp
        include/engine/log.h
)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE)

# Linking
target_link_libraries(MondEngine PRIVATE spdlog::spdlog ${SDL2_LIBRARIES})
target_link_libraries(MondEngine_lib PRIVATE spdlog::spdlog ${SDL2_LIBRARIES})


# Include directories
target_include_directories(MondEngine PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MondEngine_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(tests)
