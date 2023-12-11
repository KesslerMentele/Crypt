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
	class Application
	{
	public:
		Application(const std::string& name = "Crypt App");
		virtual ~Application();


		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		//void MoveCamera(KeyPressedEvent& e); - Unnecessary?

		void Close();

		inline static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
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
}

