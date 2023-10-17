#include <Crypt.h>


class ExampleLayer : public Crypt::Layer 
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		CRY_INFO("ExampleLayer::Update");
	}

	void OnEvent(Crypt::Event& event) override
	{
		CRY_TRACE("{0}", event);
	}



};







class Sandbox : public Crypt::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Crypt::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Crypt::Application* Crypt::CreateApplication()
{
	return new Sandbox();
}