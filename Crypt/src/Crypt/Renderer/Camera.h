#pragma once

#include <glm/glm.hpp>

namespace Crypt{

	class Camera
	{
	public:
		Camera(const glm::mat4& projection)
			: m_Projection(projection) {}

		const glm::mat4& GetProjection() const { return m_Projection; }

		// TODO:
		//void SetPerspective()
		// ---

	private:
		glm::mat4 m_Projection;
	};

}