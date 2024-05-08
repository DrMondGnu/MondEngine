//
// Created by MondGnu on 16.02.2024.
//
#include "doctest.h"
#include "engine/log.h"


TEST_CASE("LogInitTest") {
    Mond::Log::init();
    REQUIRE(Mond::Log::get_mond_engine_logger() != nullptr);
    CHECK(Mond::Log::get_app_logger() != nullptr);
}
