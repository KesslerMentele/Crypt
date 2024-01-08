#pragma once

#include "Crypt.h"
#include "Panels/SceneHierarchyPanel.h"

#include "Crypt/Renderer/EditorCamera.h"

namespace Crypt
{


	class CryptIDLayer : public Layer
	{
	public:
		CryptIDLayer();
		virtual ~CryptIDLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& event) override;
	private:
		bool OnKeyPressed(KeyPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();

	private:
		
		// ---Temporary---
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		// ---------------

		Ref<Scene> m_ActiveScene;
		Entity m_SecondCamera;
		Entity m_CameraEntity;
		Entity m_HoveredEntity;

		bool m_PrimaryCamera = false;

		EditorCamera m_EditorCamera;

		Ref<Texture2D> m_CheckerboardTexture;

		bool m_Rotate = false;
		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = {0.0f, 0.0f};
		glm::vec2 m_ViewportBounds[2];

		glm::vec4 m_SquareColor = { 0.2f,0.3f, 0.8f, 1.0f };

		int m_GizmoType = -1;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
	};
}
