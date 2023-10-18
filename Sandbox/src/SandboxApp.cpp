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

	}

	void OnEvent(Crypt::Event& event) override
	{
		if (event.GetEventType() == Crypt::EventType::KeyPressed)
		{
			Crypt::KeyPressedEvent& e = (Crypt::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CRY_KEY_TAB)
				CRY_TRACE("Tab key is pressed!");

			CRY_TRACE("{0}", (char)e.GetKeyCode());
		}
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