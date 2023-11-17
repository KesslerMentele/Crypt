#pragma once

#include "Crypt/Core/Core.h"

#include "Crypt/Core/Window.h"
#include "Crypt/Core/LayerStack.h"
#include "Crypt/Events/Event.h"
#include "Crypt/Events/ApplicationEvent.h"

#include "Crypt/ImGui/ImGuiLayer.h"

#include "Crypt/Core/Timestep.h"

namespace Crypt {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void MoveCamera(KeyPressedEvent& e);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
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

	};	

	// To be defined in Client
	Application* CreateApplication();
}

