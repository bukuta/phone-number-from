#include "Logger.hpp"
#include <spdlog/sinks/stdout_sinks.h>

std::shared_ptr<spdlog::logger> Logger::console =
    spdlog::stdout_color_mt("console");
