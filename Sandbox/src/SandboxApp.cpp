#include <Crypt.h>
#include <Crypt/Core/EntryPoint.h>

#include "Game/GameLayer.h"

#include "Sandbox2D.h"

class Sandbox : public Crypt::Application
{
public:
	Sandbox()
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Crypt::Application* Crypt::CreateApplication()
{
	return new Sandbox();
}