#pragma once
#include "Core.h"

namespace Filbert
{
	class FLB_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	// Used in the EntryPoint and should be defined by the user
	Application* CreateApplication();
}
