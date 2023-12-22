#pragma once

#include "Crypt/Renderer/OrthographicCamera.h"
#include "Crypt/Renderer/Camera.h"

#include "Crypt/Renderer/Texture.h"
#include "SubTexture2D.h"

namespace Crypt {

	class Renderer2D
	{
	public:

		static void Init();
		static void Shutdown();

		static void Flush();

		static void BeginScene(const Camera& camera, const glm::mat4& transform);  // TODO: Remove
		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		// Primitives

		// Draw flat color non-rotated
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);

		// Draw texture non-rotated
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));

		// Draw texture region non-rotated
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));

		// Draw from transform
		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color);
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawQuad(const glm::mat4& transform, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingfactor, glm::vec4& tintcolor);

		// Draw flat color rotated
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float angleInDegrees, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float angleInDegrees, const glm::vec4& color);

		// Draw texture rotated
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float angleInDegrees, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float angleInDegrees, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));

		// Draw texture region rotated
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float angleInDegrees, const Ref<SubTexture2D>& subtexture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float angleInDegrees, const Ref<SubTexture2D>& subtexture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));


		// Stats
		struct Statistics
		{
			uint32_t DrawCalls;
			uint32_t QuadCount;

			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndexCount() { return QuadCount * 6; }

		};

		static void ResetStats();
		static Statistics GetStats();

	private:
		
		static void FlushAndReset();
	};



}