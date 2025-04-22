/*
* @file Log.cpp
 * @brief Implementation of the logging system for the Vex Engine.
 *
 * This file initializes and configures the logging system using spdlog.
 * It provides two loggers:
 * - Core Logger (VEX): Used for logging internal engine messages.
 * - Client Logger (APP): Used for logging messages from applications using the engine.
 *
 * The log format is set to include a timestamp, logger name, and message, with color formatting.
 */

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h" // Provides colored console output

namespace Vex
{
    // Define static logger instances
    std::shared_ptr<spdlog::logger> Log::m_sCoreLogger;
    std::shared_ptr<spdlog::logger> Log::m_sClientLogger;
    
    /**
     * @brief Initializes the loggers for the engine and client.
     *
     * Sets up a colored console output with a timestamp format and initializes
     * two separate loggers: one for the Vex engine and another for client applications.
     * Log levels are set to `trace` to capture all log messages.
     */
    void Log::Init()
    {
        // Set log message format: [HH:MM:SS] LoggerName: Message (with color formatting)
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // Create core logger (engine)
        m_sCoreLogger = spdlog::stdout_color_mt("VEX");
        m_sCoreLogger->set_level(spdlog::level::trace);

        // Create client logger (application)
        m_sClientLogger = spdlog::stdout_color_mt("APP");
        m_sClientLogger->set_level(spdlog::level::trace);
    }
}

