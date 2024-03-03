//
// Created by MondGnu on 2/16/2024.
//

#include "engine/log.h"

namespace mondengine {
    std::shared_ptr<spdlog::logger> Log::mp_mond_engine_logger;
    std::shared_ptr<spdlog::logger> Log::mp_app_logger;

    void Log::init() {
        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        stdout_sink->set_pattern("%n-%T-%l: %v");
        stdout_sink->set_level(spdlog::level::trace);
        mp_mond_engine_logger = std::make_shared<spdlog::logger>("MondEngine", stdout_sink);
        mp_mond_engine_logger->set_level(spdlog::level::trace);
        MOE_TRACE("MondEngine logger initialized!");
        mp_app_logger = std::make_shared<spdlog::logger>("App", stdout_sink);
        MOE_TRACE("App logger initialized!");
        mp_app_logger->set_level(spdlog::level::trace);
    }

    const std::shared_ptr<spdlog::logger> &Log::get_mond_engine_logger()
    {
        return mp_mond_engine_logger;
    }

    const std::shared_ptr<spdlog::logger> &Log::get_app_logger()
    {
        return mp_app_logger;
    }

} // mondengine