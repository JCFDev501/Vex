/*
 * @file Log.h
 * @brief Logging system for the Vex Engine.
 *
 * This file defines the Log class, which provides a centralized logging system for both
 * the engine (core) and the client applications using spdlog. It also defines logging macros
 * for different log levels to make logging more convenient across the project.
 *
 * Usage:
 * - Call `Vex::Log::Init()` at the start of the application to initialize the loggers.
 * - Use `VEX_CORE_*` macros for engine-related logs.
 * - Use `VEX_*` macros for client application logs.
 *
 * @note Uses spdlog for logging.
 */

#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>  // For smart pointers

namespace Vex
{
    /**
     * @class Log
     * @brief Handles logging for the Vex Engine.
     *
     * This class initializes and manages two separate loggers:
     * - Core Logger: Used for internal engine logging.
     * - Client Logger: Used for logging from applications using the engine.
     */
    class VEX_API Log
    {
        static std::shared_ptr<spdlog::logger> m_sCoreLogger;   // Logger for engine messages
        static std::shared_ptr<spdlog::logger> m_sClientLogger; // Logger for client applications

    public:
        /**
         * @brief Initializes the loggers.
         * 
         * This method sets up the logging format and log levels for both core and client loggers.
         */
        static void Init();
        
        /**
         * @brief Gets the core engine logger.
         * @return Reference to the core logger.
         */
        static std::shared_ptr<spdlog::logger>& GetCoreLogger() noexcept { return m_sCoreLogger; }

        /**
         * @brief Gets the client application logger.
         * @return Reference to the client logger.
         */
        static std::shared_ptr<spdlog::logger>& GetClientLogger() noexcept { return m_sClientLogger; }
    };
}

// Logging macros for easy access

// Core (engine) logging macros
#define VEX_CORE_TRACE(...)     ::Vex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VEX_CORE_INFO(...)      ::Vex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VEX_CORE_WARN(...)      ::Vex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VEX_CORE_ERROR(...)     ::Vex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VEX_CORE_FATAL(...)     ::Vex::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client application logging macros
#define VEX_TRACE(...)          ::Vex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VEX_INFO(...)           ::Vex::Log::GetClientLogger()->info(__VA_ARGS__)
#define VEX_WARN(...)           ::Vex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VEX_ERROR(...)          ::Vex::Log::GetClientLogger()->error(__VA_ARGS__)
#define VEX_FATAL(...)          ::Vex::Log::GetClientLogger()->fatal(__VA_ARGS__)
