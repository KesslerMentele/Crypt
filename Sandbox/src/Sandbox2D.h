#pragma once

#include "Crypt.h"

class Sandbox2D : public Crypt::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Crypt::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Crypt::Event& event) override;
private:
	// ---Temporary---
	Crypt::Ref<Crypt::VertexArray> m_SquareVA;
	Crypt::Ref<Crypt::Shader> m_FlatColorShader;
	Crypt::Ref<Crypt::Texture2D> m_CheckerboardTexture;
	// ---------------

	Crypt::OrthographicCameraController m_CameraController;

	bool m_Rotate = false;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor = { 0.2f,0.3f, 0.8f, 1.0f };
};