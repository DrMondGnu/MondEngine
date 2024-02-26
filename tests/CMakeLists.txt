project(MondEngine_tests)

add_subdirectory(gtest_lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(MondEngine_tests_run logging_test.cpp
        init_engine_tests.cpp
        file_util_tests.cpp)

target_link_libraries(MondEngine_tests_run MondEngine_lib)
target_link_libraries(MondEngine_tests_run gtest gtest_main)

copy_dlls_to_target(MondEngine_tests_run "${MOND_ENGINE_REQUIRED_DLLS}")
