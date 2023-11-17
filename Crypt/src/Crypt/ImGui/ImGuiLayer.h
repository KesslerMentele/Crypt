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
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;

	};
}