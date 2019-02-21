#include "filbertPCH.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Filbert {
	Logger Log::s_EngineLogger;
	Logger Log::s_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%H:%M:%S][%n %l]: %v%$");
		s_EngineLogger = spdlog::stdout_color_mt("Engine");
		s_AppLogger = spdlog::stdout_color_mt("App");
		s_EngineLogger->set_level(spdlog::level::trace);
	}
}
