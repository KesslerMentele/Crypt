#pragma once

#ifdef CRY_PLATFORM_WINDOWS

extern Crypt::Application* Crypt::CreateApplication();

int main(int argc, char** argv)
{
	Crypt::Log::Init();
	CRY_CORE_WARN("Initailized Log!");
	int a = 5;
	CRY_INFO("Hello! Var={0}", a);

	auto app = Crypt::CreateApplication();
	app->Run();
	delete app;
}

#endif  