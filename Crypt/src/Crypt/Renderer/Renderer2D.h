#pragma once

#include "Crypt/Renderer/OrthographicCamera.h"
#include "Crypt/Renderer/Camera.h"

#include "Crypt/Renderer/Texture.h"
#include "Crypt/Renderer/SubTexture2D.h"
#include "Crypt/Renderer/EditorCamera.h"

#include "Crypt/Scene/Components.h"

namespace Crypt {

	class Renderer2D
	{
	public:

		static void Init();
		static void Shutdown();


		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void BeginScene(const EditorCamera& camera); 
		static void BeginScene(const OrthographicCamera& camera); // TODO: Remove
		static void EndScene();
		static void Flush();


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
		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color, int entityID = -1);
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f), int entityID = -1);
		static void DrawQuad(const glm::mat4& transform, const Ref<SubTexture2D>& subtexture, float tilingfactor, glm::vec4& tintcolor, int entityID = -1);

		// Draw flat color rotated
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float angleInDegrees, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float angleInDegrees, const glm::vec4& color);

		// Draw texture rotated
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float angleInDegrees, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float angleInDegrees, const Ref<Texture2D>& texture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));

		// Draw texture region rotated
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float angleInDegrees, const Ref<SubTexture2D>& subtexture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float angleInDegrees, const Ref<SubTexture2D>& subtexture, float tilingfactor = 1.0f, glm::vec4& tintcolor = glm::vec4(1.0f));

		// Draws Solid Circles
		static void DrawCircle(const glm::mat4& transform, const glm::vec4& color, float thickness = 1.0f, float fade = 0.005f, int entityID = -1);

		// Chooses Textured or Solid DrawQuad
		static void DrawSprite(const glm::mat4& transform, SpriteRendererComponent& src, int entityID);

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
		static void StartBatch();
		static void NextBatch();
	};



}
