//
// Created by MondGnu on 2/16/2024.
//

#ifndef MONDENGINE_LOG_H
#define MONDENGINE_LOG_H

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "library.h"

namespace mondengine {

    class Log {
    public:
        MOND_API static void init();

        MOND_API static const std::shared_ptr<spdlog::logger> &get_mond_engine_logger();

        MOND_API static const std::shared_ptr<spdlog::logger> &get_app_logger();

    private:
        static std::shared_ptr<spdlog::logger> mp_mond_engine_logger;
        static std::shared_ptr<spdlog::logger> mp_app_logger;
    };

} // mondengine

#define MOE_TRACE(...) mondengine::Log::get_mond_engine_logger()->trace(__VA_ARGS__)
#define MOE_DEBUG(...) mondengine::Log::get_mond_engine_logger()->debug(__VA_ARGS__)
#define MOE_INFO(...) mondengine::Log::get_mond_engine_logger()->info(__VA_ARGS__)
#define MOE_WARN(...) mondengine::Log::get_mond_engine_logger()->warn(__VA_ARGS__)
#define MOE_ERROR(...) mondengine::Log::get_mond_engine_logger()->error(__VA_ARGS__)

#define APP_TRACE(...) mondengine::Log::get_app_logger()->trace(__VA_ARGS__)
#define APP_DEBUG(...) mondengine::Log::get_app_logger()->debug(__VA_ARGS__)
#define APP_INFO(...) mondengine::Log::get_app_logger()->info(__VA_ARGS__)
#define APP_WARN(...) mondengine::Log::get_app_logger()->warn(__VA_ARGS__)
#define APP_ERROR(...) mondengine::Log::get_app_logger()->error(__VA_ARGS__)


#endif //MONDENGINE_LOG_H
