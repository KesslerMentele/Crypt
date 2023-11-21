#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}
void Sandbox2D::OnAttach()
{
	CRY_PROFILE_FUNCTION();
	
	m_CheckerboardTexture = Crypt::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	CRY_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Crypt::Timestep ts)
{
		CRY_PROFILE_FUNCTION();

		// Update
		m_CameraController.OnUpdate(ts);

		// Render Submit
		Crypt::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Crypt::RenderCommand::Clear();
		Crypt::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Crypt::Renderer2D::DrawRotatedQuad({ -1.0f,0.0f }, { 1.0f, 1.0f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Crypt::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.3f, 0.2f, 0.8f, 1.0f });
		Crypt::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, glm::radians(45.0f), m_CheckerboardTexture, 10.0f, glm::vec4(0.8f, 0.7f, 0.8f, 1.0f));
		Crypt::Renderer2D::EndScene();
		
}

void Sandbox2D::OnImGuiRender()
{
	CRY_PROFILE_FUNCTION();
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::Checkbox("Rotation", &m_Rotate);
	m_CameraController.SetRotation(m_Rotate);

	ImGui::End();
}

void Sandbox2D::OnEvent(Crypt::Event& event)
{
	m_CameraController.OnEvent(event);
}
