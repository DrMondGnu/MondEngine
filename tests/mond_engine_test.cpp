//
// Created by MondGnu on 16.02.2024.
//
#include "gtest/gtest.h"
#include "engine/log.h"


TEST(GetOneTest, HandlesWrongOutput) {
    mondengine::Log::init();
    EXPECT_TRUE(mondengine::Log::get_mond_engine_logger() != nullptr);
    ASSERT_TRUE(mondengine::Log::get_app_logger() != nullptr);
}
