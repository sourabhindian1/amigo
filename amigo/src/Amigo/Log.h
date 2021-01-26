#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Amigo {
    class AMIGO_API Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Log Macros
#define AMIGO_CORE_TRACE(...)       ::Amigo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AMIGO_CORE_INFO(...)        ::Amigo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AMIGO_CORE_WARN(...)        ::Amigo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AMIGO_CORE_ERROR(...)       ::Amigo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AMIGO_CORE_FATAL(...)       ::Amigo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define AMIGO_CLIENT_TRACE(...)     ::Amigo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AMIGO_CLIENT_INFO(...)      ::Amigo::Log::GetClientLogger()->info(__VA_ARGS__)
#define AMIGO_CLIENT_WARN(...)      ::Amigo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AMIGO_CLIENT_ERROR(...)     ::Amigo::Log::GetClientLogger()->error(__VA_ARGS__)
#define AMIGO_CLIENT_FATAL(...)     ::Amigo::Log::GetClientLogger()->fatal(__VA_ARGS__)