#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Filbert {
	typedef std::shared_ptr<spdlog::logger> Logger;

	class FLB_API Log
	{
	public:
		static void Init();
		static inline Logger& GetEngineLogger() { return m_EngineLogger; }
		static inline Logger& GetAppLogger() { return m_AppLogger; }

	private:
		static Logger m_EngineLogger;
		static Logger m_AppLogger;
	};

#ifdef NDEBUG
#define FLB_CRITICAL(...)    
#define FLB_ERROR(...)       
#define FLB_WARNING(...)     
#define FLB_TRACE(...)       
#define FLB_INFO(...)        

#define FLB_APP_CRITICAL(...)
#define FLB_APP_ERROR(...)   
#define FLB_APP_WARNING(...) 
#define FLB_APP_TRACE(...)   
#define FLB_APP_INFO(...) 
#else
#define FLB_CRITICAL(...)     ::Filbert::Log::GetEngineLogger()->critical(__VA_ARGS__)
#define FLB_ERROR(...)        ::Filbert::Log::GetEngineLogger()->error(__VA_ARGS__)
#define FLB_WARNING(...)      ::Filbert::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define FLB_TRACE(...)        ::Filbert::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define FLB_INFO(...)         ::Filbert::Log::GetEngineLogger()->info(__VA_ARGS__)

#define FLB_APP_CRITICAL(...) ::Filbert::Log::GetAppLogger()->critical(__VA_ARGS__)
#define FLB_APP_ERROR(...)    ::Filbert::Log::GetAppLogger()->error(__VA_ARGS__)
#define FLB_APP_WARNING(...)  ::Filbert::Log::GetAppLogger()->warn(__VA_ARGS__)
#define FLB_APP_TRACE(...)    ::Filbert::Log::GetAppLogger()->trace(__VA_ARGS__)
#define FLB_APP_INFO(...)     ::Filbert::Log::GetAppLogger()->info(__VA_ARGS__)
#endif
}