#pragma once

#include "Crypt.h"

#include "ParticleSystem.h"

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
	Crypt::Ref<Crypt::Framebuffer> m_Framebuffer;

	Crypt::Ref<Crypt::Texture2D> m_CheckerboardTexture;
	Crypt::Ref<Crypt::Texture2D> m_SpriteSheet;	
	Crypt::Ref<Crypt::SubTexture2D> m_TextureStairs, m_TextureBarrel, m_TextureTree, m_TextureAllGrass;

	// ---------------

	Crypt::OrthographicCameraController m_CameraController;

	bool m_Rotate = false;

	glm::vec4 m_SquareColor = { 0.2f,0.3f, 0.8f, 1.0f };

	ParticleSystem m_ParticleSystem;
	ParticleProps m_Particle;

	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, Crypt::Ref<Crypt::SubTexture2D>> s_TextureMap;
};