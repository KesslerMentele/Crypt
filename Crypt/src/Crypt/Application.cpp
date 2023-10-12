#include "crypch.h"
#include "Application.h"

#include "Crypt/Events/ApplicationEvent.h"
#include "Crypt/Log.h"

namespace Crypt {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CRY_TRACE(e);
		while (true);
		
	}
}
