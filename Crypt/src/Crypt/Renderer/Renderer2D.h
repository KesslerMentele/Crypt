#pragma once

#include "Crypt/Renderer/OrthographicCamera.h"

#include "Crypt/Renderer/Texture.h"

namespace Crypt {

	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		// Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position,const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));

		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotateRadians, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotateRadians, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotateRadians, const Ref<Texture2D>& texture, 
			float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotateRadians, const Ref<Texture2D>& texture, 
			float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));


	};



}