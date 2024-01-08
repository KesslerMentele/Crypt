#pragma once

#include "Crypt/Core/Core.h"

#include "Crypt/Core/Window.h"
#include "Crypt/Core/LayerStack.h"
#include "Crypt/Events/Event.h"
#include "Crypt/Events/ApplicationEvent.h"

#include "Crypt/ImGui/ImGuiLayer.h"

#include "Crypt/Core/Timestep.h"

int main(int argc, char** argv);

namespace Crypt {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			CRY_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};


	class Application
	{
	public:
		Application(const std::string& name = "Crypt App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		inline static Application& Get() { return *s_Instance; }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		ApplicationCommandLineArgs m_CommandLineArgs;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:

		static Application* s_Instance;
		friend int ::main(int argc, char** argv);

	};	

	// To be defined in Client
	Application* CreateApplication();
	Application* CreateApplication(ApplicationCommandLineArgs args);
}

