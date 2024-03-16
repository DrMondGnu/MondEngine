cmake_minimum_required(VERSION 3.29)
project(MondEngine)

include(cmake/util.cmake)
set(CMAKE_CXX_STANDARD 23)

# Options
option(MOND_ENGINE_FMT_EXTERNAL "Use external fmt library" OFF)
option(MOND_ENGINE_SPDLOG_EXTERNAL "Use external spdlog library" OFF)
option(MOND_ENGINE_GLFW_EXTERNAL "Use external glfw library" OFF)

# FMT
if(NOT MOND_ENGINE_FMT_EXTERNAL)
    add_subdirectory(libs/fmt)
endif()

# SPDLOG
set(SPDLOG_FMT_EXTERNAL ON)
if(NOT MOND_ENGINE_SPDLOG_EXTERNAL)
    add_subdirectory(libs/spdlog)
endif()

# GLEW
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew-2.1.0)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

# GLFW
if(NOT MOND_ENGINE_GLFW_EXTERNAL)
    add_subdirectory(libs/glfw)
endif()

# DLLs
set(MOND_ENGINE_REQUIRED_DLLS
        "${CMAKE_CURRENT_SOURCE_DIR}/libs/glew-2.1.0/bin/Release/x64/glew32.dll"
)

# stb
add_library(stb STATIC libs/util/stb_image.h
        libs/util/stb_image.cpp)
target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libs/util)
set(MOND_ENGINE_REQUIRED_DLLS ${MOND_ENGINE_REQUIRED_DLLS} PARENT_SCOPE)

# Shared Lib
add_library(MondEngine SHARED
        src/engine/log.cpp
        include/engine/log.h
        src/engine/engine.cpp
        include/engine/engine.h
        include/types.h
        src/engine/shader.cpp
        include/engine/shader.h
        src/util/file.cpp
        include/util/file.h
        include/engine/graphics/vao.h
        src/engine/graphics/vao.cpp
        src/engine/graphics/vbo.cpp
        include/engine/graphics/vbo.h
        src/engine/glid.cpp
        include/engine/glid.h
        include/util/opengl.h
        include/util/general.h
        src/engine/graphics/ebo.cpp
        include/engine/graphics/ebo.h
        src/engine/event/key_event.cpp
        include/engine/event/key_event.h
        src/engine/event/event.cpp
        include/engine/event/event.h
        src/engine/window.cpp
        include/engine/window.h
        src/platform/windows/windows_window.cpp
        include/platform/windows/windows_window.h
        src/engine/event/window_event.cpp
        include/engine/event/window_event.h
        src/engine/graphics/cube.cpp
        include/engine/graphics/cube.h
        include/engine/graphics/shapes.h
        src/engine/game_object.cpp
        include/engine/game_object.h
        src/node.cpp
        include/node.h
        src/engine/graphics/renderer.cpp
        include/engine/graphics/renderer.h
        src/engine/texture.cpp
        include/engine/texture.h
        src/engine/sprite.cpp
        include/engine/sprite.h
        src/engine/shapes/rectangle.cpp
        include/engine/shapes/rectangle.h
        src/engine/shapes/shape.cpp
        include/engine/shapes/shape.h
        src/engine/transformable.cpp
        include/engine/transformable.h
)

target_precompile_headers(MondEngine PUBLIC
        <iostream>
        <fstream>
        <memory>
        <utility>
        <algorithm>
        <functional>
        <string>
        <sstream>
        <vector>
        <unordered_map>
        <unordered_set>
        <GL/glew.h>
        <GLFW/glfw3.h>
)

get_target_property(MOND_ENGINE_BIN_DIR MondEngine BINARY_DIR)
set(MOND_ENGINE_DLL ${MOND_ENGINE_BIN_DIR}/MondEngine.dll PARENT_SCOPE)


# Static Lib for Tests
add_library(MondEngine_lib STATIC
        src/engine/log.cpp
        include/engine/log.h
        src/engine/engine.cpp
        include/engine/engine.h
        include/types.h
        src/engine/shader.cpp
        include/engine/shader.h
        src/util/file.cpp
        include/util/file.h
        include/engine/graphics/vao.h
        src/engine/graphics/vao.cpp
        src/engine/graphics/vbo.cpp
        include/engine/graphics/vbo.h
        src/engine/glid.cpp
        include/engine/glid.h
        include/util/opengl.h
        include/util/general.h
        src/engine/graphics/ebo.cpp
        include/engine/graphics/ebo.h
        src/engine/event/key_event.cpp
        include/engine/event/key_event.h
        src/engine/event/event.cpp
        include/engine/event/event.h
        src/engine/window.cpp
        include/engine/window.h
        src/platform/windows/windows_window.cpp
        include/platform/windows/windows_window.h
        src/engine/event/window_event.cpp
        include/engine/event/window_event.h
        src/engine/graphics/cube.cpp
        include/engine/graphics/cube.h
        include/engine/graphics/shapes.h
        src/engine/game_object.cpp
        include/engine/game_object.h
        src/node.cpp
        include/node.h
        src/engine/graphics/renderer.cpp
        include/engine/graphics/renderer.h

        src/engine/texture.cpp
        include/engine/texture.h
        src/engine/sprite.cpp
        include/engine/sprite.h
        src/engine/shapes/rectangle.cpp
        include/engine/shapes/rectangle.h
        src/engine/shapes/shape.cpp
        include/engine/shapes/shape.h
        src/engine/transformable.cpp
        include/engine/transformable.h
)

target_precompile_headers(MondEngine_lib REUSE_FROM MondEngine)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE)

# Linking
target_link_libraries(MondEngine PUBLIC stb glfw fmt::fmt spdlog ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(MondEngine_lib PUBLIC stb glfw fmt::fmt spdlog ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})


# Include directories
target_include_directories(MondEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libs/glm ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

target_include_directories(MondEngine_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libs/glm ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

add_subdirectory(tests)
