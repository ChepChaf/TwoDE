#pragma once

#include "Core.h"
#include "Logger.h"

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace TwoDE
{
	class TWO_DLL Logger
	{
		public:
			static void init();

			inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define TWODE_CORE_TRACE(...) ::TwoDE::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define TWODE_CORE_INFO(...) ::TwoDE::Logger::getCoreLogger()->info(__VA_ARGS__)
#define TWODE_CORE_WARN(...) ::TwoDE::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define TWODE_CORE_ERROR(...) ::TwoDE::Logger::getCoreLogger()->error(__VA_ARGS__)
#define TWODE_CORE_FATAL(...) ::TwoDE::Logger::getCoreLogger()->fatal(__VA_ARGS__)

#define TWODE_TRACE(...) ::TwoDE::Logger::getClientLogger()->trace(__VA_ARGS__)
#define TWODE_INFO(...) ::TwoDE::Logger::getClientLogger()->info(__VA_ARGS__)
#define TWODE_WARN(...) ::TwoDE::Logger::getClientLogger()->warn(__VA_ARGS__)
#define TWODE_ERROR(...) ::TwoDE::Logger::getClientLogger()->error(__VA_ARGS__)
#define TWODE_FATAL(...) ::TwoDE::Logger::getClientLogger()->fatal(__VA_ARGS__)