#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Timer
{
public: 
	Timer(const char* name)
		: m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		m_Stopped = true;

		float duration = (end - start) * 0.001f;

		std::cout << m_Name <<": " << duration << "ms" << std::endl;
	}

private:
	const char* m_Name;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
};

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}
void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Crypt::Texture2D::Create("assets/textures/Checkerboard.png");
	

}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Crypt::Timestep ts)
{
	Timer timer("Sandbox2D::OnUpdate");
	

	// Update
	m_CameraController.OnUpdate(ts);


	// Render Submit
	Crypt::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Crypt::RenderCommand::Clear();

	Crypt::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Crypt::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Crypt::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.3f, 0.2f, 0.8f, 1.0f });
	Crypt::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Crypt::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
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
