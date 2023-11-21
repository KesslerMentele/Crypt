#pragma once

#include "Crypt.h"

class Player
{

public:
	void OnRender();
	void OnImGuiRender();
	void LoadAssets();
	void Reset();
	float GetRotation();
	const glm::vec2 GetPosition() const { return m_Position; }
	void OnUpdate(Crypt::Timestep ts);
	const uint32_t GetScore() const { return m_Score; }

private:
	uint32_t m_Score = 0;
	glm::vec2 m_Position;

};

