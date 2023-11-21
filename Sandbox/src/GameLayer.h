#pragma once

#include "Crypt.h"

#include "Level.h"
#include <imgui/imgui.h>

class GameLayer : public Crypt::Layer
{
	GameLayer();
	virtual ~GameLayer() = default;

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate(Crypt::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Crypt::Event& e) override;
	bool OnMouseButtonPressed(Crypt::MouseButtonPressedEvent& e);
	bool OnWindowResize(Crypt::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);
private:
	Crypt::Scope<Crypt::OrthographicCamera> m_Camera;
	Level m_Level;
	ImFont* m_Font;
	float m_Time = 0.0f;
	bool m_Blink = false;


	enum class GameState
	{
		Play = 0, MainMenu = 1, GameOver = 2
	};

	GameState m_State = GameState::MainMenu;
};

