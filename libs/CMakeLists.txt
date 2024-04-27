cmake_minimum_required(VERSION 3.26)

# Options
option(MOND_ENGINE_STB_EXTERNAL "Use external stb library" OFF)
option(MOND_ENGINE_FMT_EXTERNAL "Use external fmt library" OFF)
option(MOND_ENGINE_SPDLOG_EXTERNAL "Use external spdlog library" OFF)
option(MOND_ENGINE_GLFW_EXTERNAL "Use external glfw library" OFF)
option(MOND_ENGINE_LUA_EXTERNAL "Use external lua library" OFF) # TODO: add lua

# FMT
if(NOT MOND_ENGINE_FMT_EXTERNAL)
    add_subdirectory(fmt)
endif()

# SPDLOG
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(SPDLOG_FMT_EXTERNAL ON)
if(NOT MOND_ENGINE_SPDLOG_EXTERNAL)
    add_subdirectory(spdlog)
endif()


# GLFW
if(NOT MOND_ENGINE_GLFW_EXTERNAL)
    add_subdirectory(glfw)
endif()

# stb
if(NOT MOND_ENGINE_STB_EXTERNAL)
add_library(stb STATIC util/stb_image.h
        util/stb_image.cpp)
target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libs/util)
endif ()

# EventSystem
add_subdirectory(EventSystem)

