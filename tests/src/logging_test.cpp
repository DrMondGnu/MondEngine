//
// Created by MondGnu on 16.02.2024.
//
#include "doctest.h"
#include "engine/log.h"


TEST_CASE("LogInitTest") {
    mondengine::Log::init();
    REQUIRE(mondengine::Log::get_mond_engine_logger() != nullptr);
    CHECK(mondengine::Log::get_app_logger() != nullptr);
}
