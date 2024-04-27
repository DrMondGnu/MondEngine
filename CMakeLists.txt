cmake_minimum_required(VERSION 3.27)
project(MondEngine)

set(CMAKE_CXX_STANDARD 23)

# Add libs
add_subdirectory(libs)

# GLEW
list(APPEND CMAKE_PREFIX_PATH libs/glew-2.1.0)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)


# Shared Lib
add_library(MondEngine STATIC
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
        src/engine/window.cpp
        include/engine/window.h
        src/platform/windows/windows_window.cpp
        include/platform/windows/windows_window.h
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
        src/engine/event/KeyEvent.cpp
        include/engine/event/KeyEvent.h
)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE)
# Linking
target_link_libraries(MondEngine PUBLIC stb glfw fmt::fmt spdlog GLEW::glew ${OPENGL_LIBRARIES} EventSystem)

# Include directories
target_include_directories(MondEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libs/glm ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

# PCH
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


add_subdirectory(tests)
