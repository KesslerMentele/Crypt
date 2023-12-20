#pragma once

#include "Crypt/Core/Layer.h"

#include "Crypt/Events/ApplicationEvent.h"
#include "Crypt/Events/KeyEvent.h"
#include "Crypt/Events/MouseEvent.h"

namespace Crypt {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnEvent(Event& e);

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;

	};
}