#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>  // Correct



namespace Vex
{
    class VEX_API Log
    {
        static std::shared_ptr<spdlog::logger> m_sCoreLogger; // Logger for engine
        static std::shared_ptr<spdlog::logger> m_sClientLogger; // Logger for client app
    public:
        static void Init();
        
        static std::shared_ptr<spdlog::logger>& GetCoreLogger() noexcept {return m_sCoreLogger;}
       
        static std::shared_ptr<spdlog::logger>& GetClientLogger() noexcept {return m_sClientLogger;}
    
    };
}


#define VEX_CORE_TRACE(...)     ::Vex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VEX_CORE_INFO(...)      ::Vex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VEX_CORE_WARN(...)      ::Vex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VEX_CORE_ERROR(...)     ::Vex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VEX_CORE_FATAL(...)     ::Vex::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define VEX_TRACE(...)          ::Vex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VEX_INFO(...)           ::Vex::Log::GetClientLogger()->info(__VA_ARGS__)
#define VEX_WARN(...)           ::Vex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VEX_ERROR(...)          ::Vex::Log::GetClientLogger()->error(__VA_ARGS__)
#define VEX_FATAL(...)          ::Vex::Log::GetClientLogger()->fatal(__VA_ARGS__)



