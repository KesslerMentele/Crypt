#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles = 
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW"
"WWWWWWWDDDDWWWWWWWWWWWWW"
"WWWWWDDGGGGDDDDDWWWWWWWW"
"WWWWDGGGGGGGGGGGDDDWWWWW"
"WWWDGGGGGGGDDDGGGGGDWWWW"
"WWWDGGGGGGDDDDDGGGGGDWWW"
"WWWDGGGGGGDDDDDDGGGDDWWW"
"WWWDGGGGGGDDDDDGGGGDDWWW"
"WWWWDGGGGGGDDGGGGGGDDWWW"
"WWWWWDDDDDDDDDDDDDDWWWWW"
"WWWWWWWWWWWWWWWWWWWWWWWW";

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
	
	m_SpriteSheet = Crypt::Texture2D::Create("assets/game/textures/RPGpack_sheet_2X.png");
	
	m_TextureStairs = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128,128 });
	m_TextureBarrel = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 9, 1 }, { 128,128 });
	m_TextureTree = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128,128 }, { 1, 2 });
	m_TextureAllGrass = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 1, 11 }, { 128,128 });

	 
	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

	s_TextureMap['G'] = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 1, 11 }, { 128,128 });
	s_TextureMap['W'] = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 11, 11 }, { 128,128 });
	s_TextureMap['D'] = Crypt::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 6, 11 }, { 128,128 });


	m_Particle.ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
	m_Particle.ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
	m_Particle.SizeBegin = 0.1f, m_Particle.SizeVariation = 0.3f, m_Particle.SizeEnd = 0.0f;
	m_Particle.LifeTime = 10.0f;
	m_Particle.Velocity = { 0.0f, -0.7f };
	m_Particle.VelocityVariation = { 1.0f, 0.5f };
	m_Particle.Position = { 0.0f, 0.0f };

	m_CameraController.SetZoomLevel(5.0f);

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

	m_Framebuffer->Bind();
	Crypt::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Crypt::RenderCommand::Clear();



	// DrawQuad( Position, Size, 'Rotation', 'Texture', 'TilingFactor', Color) 
#if 0
	{

		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		Crypt::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Crypt::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Crypt::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.3f, 0.2f, 0.8f, 1.0f });
		Crypt::Renderer2D::DrawQuad({ 1.5f, -0.5f }, { 0.5f, 0.75f }, 25.0f, { 0.3f, 0.2f, 0.8f, 1.0f });
		Crypt::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Crypt::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);

		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 0.5f) / 10.0f, 0.3f, (y + 0.5f) / 10.0f, 0.5f };
				Crypt::Renderer2D::DrawQuad({ x + 0.25f, y + 0.25f, 0.0f }, { 1.0f, 1.0f }, color);
			}

		}
		Crypt::Renderer2D::EndScene();
	}
#endif



	// Particles
	if (Crypt::Input::IsMouseButtonPressed(CRY_MOUSE_BUTTON_LEFT))
	{
		auto [x, y] = Crypt::Input::GetMousePosition();
		auto width = Crypt::Application::Get().GetWindow().GetWidth();
		auto height = Crypt::Application::Get().GetWindow().GetHeight();

		auto bounds = m_CameraController.GetBounds();
		auto pos = m_CameraController.GetCamera().GetPosition();
		x = (x / width) * bounds.GetWidth() - bounds.GetWidth() * 0.5f;
		y = bounds.GetHeight() * 0.5f - (y / height) * bounds.GetHeight();
		m_Particle.Position = { x + pos.x, y + pos.y };
		for (int i = 0; i < 5; i++)
		{
			m_ParticleSystem.Emit(m_Particle);
		}
	}

	m_ParticleSystem.OnUpdate(ts);
	m_ParticleSystem.OnRender(m_CameraController.GetCamera());

	Crypt::Renderer2D::BeginScene(m_CameraController.GetCamera());
	
	for (uint32_t y = 0; y < m_MapHeight; y++)
	{
		for (uint32_t x = 0; x < m_MapWidth; x++)
		{
			char tileType = s_MapTiles[x + y * m_MapWidth];
			Crypt::Ref<Crypt::SubTexture2D> texture;
			if (s_TextureMap.find(tileType) != s_TextureMap.end())
				texture = s_TextureMap[tileType];
			else
				texture = m_TextureBarrel;
			Crypt::Renderer2D::DrawQuad({ x - m_MapWidth / 2.0f, y - m_MapHeight / 2.0f, 0.0f }, { 1.0f,1.0f }, texture);
		}
	}


	//Crypt::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureAllGrass);
	//Crypt::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureStairs);
	//Crypt::Renderer2D::DrawQuad({ 1.0f, 1.0f, 0.5f }, { 1.0f, 1.0f }, m_TextureBarrel);
	//Crypt::Renderer2D::DrawQuad({ -1.0f, 0.5f, 0.5f }, { 1.0f, 2.0f }, m_TextureTree);
	Crypt::Renderer2D::EndScene();
	m_Framebuffer->Unbind();
	timer.Stop();
}

void Sandbox2D::OnImGuiRender()
{
	CRY_PROFILE_FUNCTION();

	
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
