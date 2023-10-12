#include <Crypt.h>


class Sandbox : public Crypt::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Crypt::Application* Crypt::CreateApplication()
{
	return new Sandbox();
}