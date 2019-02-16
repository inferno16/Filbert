#pragma once

extern Filbert::Application* Filbert::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Filbert::CreateApplication();
	app->Run();
	delete app;
}
