#pragma once

#include "Crypt/Renderer/OrthographicCamera.h"
#include "Crypt/Core/Timestep.h"

#include "Crypt/Events/ApplicationEvent.h"
#include "Crypt/Events/MouseEvent.h"

namespace Crypt{

class OrthographicCameraController
{

public:
	OrthographicCameraController(float aspectRatio, bool rotation = false); 

	void OnUpdate(Timestep ts);
	void OnEvent(Event& e);

	void SetRotation(bool rotate) { m_Rotation = rotate; }

	OrthographicCamera& GetCamera() { return m_Camera; }
	const OrthographicCamera& GetCamera() const { return m_Camera; }

	float GetZoomLevel() { return m_ZoomLevel; }
	void SetZoomLevel(float level) { m_ZoomLevel = level; }

private:
	bool OnMouseScrolled(MouseScrolledEvent& e);
	bool OnWindowResized(WindowResizeEvent& e);
private:
	float m_AspectRatio;
	float m_ZoomLevel = 1.0f;

	OrthographicCamera m_Camera;

	bool m_Rotation = false;
	glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};
	float m_CameraRotation = 0.0f; //In degrees, in the counter-clockwise direction

	float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
};

}