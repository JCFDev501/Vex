#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vex
{
    std::shared_ptr<spdlog::logger> Log::m_sCoreLogger;
    std::shared_ptr<spdlog::logger> Log::m_sClientLogger;
    
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_sCoreLogger = spdlog::stdout_color_mt("VEX");
        m_sCoreLogger->set_level(spdlog::level::trace);
        
        m_sClientLogger = spdlog::stdout_color_mt("APP");
        m_sClientLogger->set_level(spdlog::level::trace);
    }
}
