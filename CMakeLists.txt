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
        src/Engine/log.cpp
        include/Engine/log.h
        src/Engine/engine.cpp
        include/Engine/engine.h
        include/types.h
        src/Engine/Shader/Shader.cpp
        include/Engine/Shader/Shader.h
        src/util/file.cpp
        include/util/file.h
        include/util/opengl.h
        include/util/general.h
        src/Engine/window.cpp
        include/Engine/window.h
        src/platform/windows/windows_window.cpp
        include/Platform/windows/windows_window.h
        src/Engine/TickObject.cpp
        include/Engine/TickObject.h
        src/node.cpp
        include/node.h
        src/Engine/texture.cpp
        include/Engine/texture.h
        src/Engine/transformable.cpp
        include/Engine/transformable.h
        src/Engine/Event/KeyEvent.cpp
        include/Engine/Event/KeyEvent.h
        include/Engine/Platform.h
        src/Engine/PlatformUtils.cpp
        src/Engine/Graphics/Drawable.cpp
        include/Engine/Graphics/Drawable.h
        src/Engine/Transform.cpp
        include/Engine/Transform.h
        src/Engine/Graphics/RenderObject.cpp
        include/Engine/Graphics/RenderObject.h
        src/Engine/Shader/DrawableShader.cpp
        include/Engine/Shader/DrawableShader.h
        src/Engine/Graphics/Renderer.cpp
        include/Engine/Graphics/Renderer.h
        src/Engine/File/FileReader.cpp
        include/Engine/File/FileReader.h
        src/Engine/Shader/ShaderCompiler.cpp
        include/Engine/Shader/ShaderCompiler.h
        src/Engine/Graphics/Shapes/Shape.cpp
        include/Engine/Graphics/Shapes/Shape.h
        src/Engine/Graphics/Shapes/Rectangle.cpp
        include/Engine/Graphics/Shapes/Rectangle.h
        src/Engine/Graphics/Core/VertexArray.cpp
        include/Engine/Graphics/Core/VertexArray.h
        include/Engine/Graphics/Core/Bindable.h
        src/Engine/Graphics/Core/VertexBuffer.cpp
        include/Engine/Graphics/Core/VertexBuffer.h
        src/Engine/Graphics/Core/IndexBuffer.cpp
        include/Engine/Graphics/Core/IndexBuffer.h
        src/platform/OpenGL/OpenGLVertexBuffer.cpp
        include/Platform/OpenGL/OpenGLVertexBuffer.h
        src/platform/OpenGL/OpenGLVertexArray.cpp
        include/Platform/OpenGL/OpenGLVertexArray.h
        src/platform/OpenGL/OpenGLIndexBuffer.cpp
        include/Platform/OpenGL/OpenGLIndexBuffer.h
        src/Engine/Graphics/Core/Buffer.cpp
        include/Engine/Graphics/Core/Buffer.h
        src/platform/OpenGL/OpenGLBuffer.cpp
        include/Platform/OpenGL/OpenGLBuffer.h
        include/Engine/PlatformUtils.h
        src/Engine/Graphics/Core/Bindable.cpp
)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE PUBLIC MOND_ENGINE_OPENGL)
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
