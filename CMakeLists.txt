cmake_minimum_required(VERSION 3.27)
project(MondEngine)

set(CMAKE_CXX_STANDARD 23)

#dll copy
function(copy_dlls_to_target target_name dll_list)
    copy_dlls_to_target_when(${target_name} ${target_name} ${dll_list})
endfunction(copy_dlls_to_target)

function(copy_dlls_to_target_when target_name when dll_list)
    # Check if target exists
    if (NOT TARGET ${target_name})
        message(ERROR "Target '${target_name}' does not exist")
        return()
    endif ()
    if (NOT TARGET ${when})
        message(ERROR "Target '${when}' does not exist")
        return()
    endif ()

    # Get the target binary directory
    get_target_property(target_binary_dir ${target_name} BINARY_DIR)

    # Check if directory exists
    if (NOT EXISTS ${target_binary_dir})
        message(ERROR "Target binary directory '${target_binary_dir}' does not exist")
        return()
    endif ()
    # Loop through each DLL and copy it
    foreach (dll ${dll_list})

        message(STATUS "Adding '${dll}' to '${target_binary_dir}'")
        # execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
        #       ${dll} ${target_binary_dir})
        add_custom_command(
                TARGET ${when}
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                ${dll}
                ${target_binary_dir}
        )
    endforeach ()
endfunction(copy_dlls_to_target_when)

# FMT
add_subdirectory(libs/fmt)

# SPDLOG
include_directories(${FMT_HEADERS})
set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(libs/spdlog)



# SDL2
#set(SDL2_DIR libs/SDL2-2.30.0/cmake)
#find_package(SDL2 REQUIRED)


# GLEW
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew-2.1.0)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

# GLFW
add_subdirectory(libs/glfw)

# DLLs
set(MOND_ENGINE_REQUIRED_DLLS "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2-2.30.0/lib/x64/SDL2.dll"
        "${CMAKE_CURRENT_SOURCE_DIR}/libs/glew-2.1.0/bin/Release/x64/glew32.dll"
)

set(MOND_ENGINE_REQUIRED_DLLS ${MOND_ENGINE_REQUIRED_DLLS} PARENT_SCOPE)

# Shared Lib
add_library(MondEngine SHARED
        src/engine/log.cpp
        include/engine/log.h
        src/engine/engine.cpp
        include/engine/engine.h
        src/engine/init.cpp
        include/engine/init.h
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
        src/engine/init.cpp
        include/engine/init.h
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
)

target_precompile_headers(MondEngine_lib REUSE_FROM MondEngine)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE)

# Linking
target_link_libraries(MondEngine PUBLIC glfw fmt::fmt spdlog ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(MondEngine_lib PUBLIC glfw fmt::fmt spdlog ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})


# Include directories
target_include_directories(MondEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libs/glm ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

target_include_directories(MondEngine_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libs/glm ${GLEW_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

add_subdirectory(tests)
