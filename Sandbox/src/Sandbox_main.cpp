#include <Filbert.h>

#include "Sandbox.h"


Filbert::Application* Filbert::CreateApplication()
{
	return new Sandbox();
}