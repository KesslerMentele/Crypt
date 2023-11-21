#pragma once
#include "Crypt/Core/Core.h"


#ifdef CRY_PLATFORM_WINDOWS

extern Crypt::Application* Crypt::CreateApplication();

int main(int argc, char** argv)
{
	Crypt::Log::Init();
	CRY_PROFILE_BEGIN_SESSION("Startup", "CryptProfile-Startup.json");
	auto app = Crypt::CreateApplication();
	CRY_PROFILE_END_SESSION();

	CRY_PROFILE_BEGIN_SESSION("Runtime", "CryptProfile-Runtime.json");
	app->Run();
	CRY_PROFILE_END_SESSION();

	CRY_PROFILE_BEGIN_SESSION("Shutdown", "CryptProfile-Shutdown.json");
	delete app;
	CRY_PROFILE_END_SESSION();
}

#endif  