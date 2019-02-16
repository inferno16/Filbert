#include "filbertPCH.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Filbert {
	Logger Log::m_EngineLogger;
	Logger Log::m_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%H:%M:%S][%n %l]: %v%$");
		m_EngineLogger = spdlog::stdout_color_mt("Engine");
		m_AppLogger = spdlog::stdout_color_mt("App");
	}
}
