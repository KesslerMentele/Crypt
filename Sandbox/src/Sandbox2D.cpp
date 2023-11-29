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

		float fps = 1000 / duration;

		std::cout << m_Name <<": " << duration << "ms (" << fps << ") Frames per second." << std::endl;
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
	Timer timer = Timer("OnUpdate");
	
	// Update
	m_CameraController.OnUpdate(ts);


	// Render Submit
	Crypt::Renderer2D::ResetStats();
	Crypt::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Crypt::RenderCommand::Clear();

	Crypt::Renderer2D::BeginScene(m_CameraController.GetCamera());


	// DrawQuad( Position, Size, 'Rotation', 'Texture', 'TilingFactor', Color) 

	static float rotation = 0.0f;
	rotation += ts * 50.0f;

	Crypt::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Crypt::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.3f, 0.2f, 0.8f, 1.0f });
	Crypt::Renderer2D::DrawQuad({ 1.5f, -0.5f }, { 0.5f, 0.75f }, 25.0f, { 0.3f, 0.2f, 0.8f, 1.0f });
	Crypt::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
	Crypt::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
	Crypt::Renderer2D::EndScene();

	Crypt::Renderer2D::BeginScene(m_CameraController.GetCamera());
	for (float y = -5.0f; y < 5.0f; y += 0.1f)
	{
		for (float x = -5.0f; x < 5.0f; x += 0.1f)
		{
			glm::vec4 color = { (x + 0.5f) / 10.0f, 0.3f, (y + 0.5f) / 10.0f, 1.0f};
			Crypt::Renderer2D::DrawQuad({ x + 0.25f, y + 0.25f, 0.0f }, { 0.1f, 0.1f }, color);
		}

	}
	Crypt::Renderer2D::EndScene();

	timer.Stop();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");

	auto stats = Crypt::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::Checkbox("Rotation", &m_Rotate);
	m_CameraController.SetRotation(m_Rotate);
	ImGui::End();
}

void Sandbox2D::OnEvent(Crypt::Event& event)
{
	m_CameraController.OnEvent(event);
}
