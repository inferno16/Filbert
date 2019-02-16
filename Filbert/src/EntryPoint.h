#pragma once

extern Filbert::Application* Filbert::CreateApplication();

int main(int argc, char** argv)
{
	Filbert::Log::Init();
	FLB_INFO("Successfully failed to fail!");
	auto app = Filbert::CreateApplication();
	app->Run();
	delete app;
}
