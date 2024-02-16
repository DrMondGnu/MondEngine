project(MondEngine_tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(MondEngine_tests_run logging_test.cpp)

target_link_libraries(MondEngine_tests_run MondEngine_lib)
target_link_libraries(MondEngine_tests_run gtest gtest_main)
