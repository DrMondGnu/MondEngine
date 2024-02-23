cmake_minimum_required(VERSION 3.27)
project(MondEngine)

set(CMAKE_CXX_STANDARD 23)

# SPDLOG
set(spdlog_DIR libs/spdlog/build)
find_package(spdlog REQUIRED)
include_directories(libs/spdlog/include)

# SDL2
set(SDL2_DIR libs/SDL2-2.30.0/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# GLEW
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs  /glew-2.1.0)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

# GLM
include_directories(libs/glm)

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
)

# Static Lib for Tests
add_library(MondEngine_lib STATIC
        src/engine/log.cpp
        include/engine/log.h
        src/engine/init.cpp
        include/engine/init.h
)

target_compile_definitions(MondEngine PRIVATE MOND_ENGINE_COMPILE)

# Linking
target_link_libraries(MondEngine PRIVATE spdlog::spdlog ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(MondEngine_lib PRIVATE spdlog::spdlog ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES})


# Include directories
target_include_directories(MondEngine PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MondEngine_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(tests)
