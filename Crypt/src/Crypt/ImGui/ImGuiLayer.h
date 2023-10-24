#pragma once

#include "Crypt/Layer.h"

#include "Crypt/Events/ApplicationEvent.h"
#include "Crypt/Events/KeyEvent.h"
#include "Crypt/Events/MouseEvent.h"

namespace Crypt {
	class CRYPT_API ImGuiLayer : public Layer
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