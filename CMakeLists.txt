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
        src/engine/Shader/Shader.cpp
        include/engine/Shader/Shader.h
        src/util/file.cpp
        include/util/file.h
        include/engine/Graphics/Core/vao.h
        src/engine/Graphics/Core/vao.cpp
        src/engine/Graphics/Core/vbo.cpp
        include/engine/Graphics/Core/vbo.h
        src/engine/glid.cpp
        include/engine/glid.h
        include/util/opengl.h
        include/util/general.h
        src/engine/Graphics/Core/ebo.cpp
        include/engine/Graphics/Core/ebo.h
        src/engine/window.cpp
        include/engine/window.h
        src/platform/windows/windows_window.cpp
        include/platform/windows/windows_window.h
        src/engine/TickObject.cpp
        include/engine/TickObject.h
        src/node.cpp
        include/node.h
        src/engine/texture.cpp
        include/engine/texture.h
        src/engine/transformable.cpp
        include/engine/transformable.h
        src/engine/event/KeyEvent.cpp
        include/engine/event/KeyEvent.h
        include/engine/Platform.h
        src/engine/Platform.cpp
        src/engine/Graphics/Drawable.cpp
        include/engine/Graphics/Drawable.h
        src/engine/Transform.cpp
        include/engine/Transform.h
        src/engine/Graphics/RenderObject.cpp
        include/engine/Graphics/RenderObject.h
        src/engine/Shader/DrawableShader.cpp
        include/engine/Shader/DrawableShader.h
        src/engine/Graphics/Renderer.cpp
        include/engine/Graphics/Renderer.h
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
