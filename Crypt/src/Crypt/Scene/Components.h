#pragma once

#include "Crypt/Renderer/Texture.h"
#include "Crypt/Renderer/SubTexture2D.h"
#include "SceneCamera.h"
#include "ScriptableEntity.h"
#include <glm/glm.hpp>


#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>


#include <glm/gtc/matrix_transform.hpp>
#include <optional>


namespace Crypt {
	
	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}

		void Update(const std::string& newTag)
		{
			Tag = newTag;
		}

	};

	struct CameraComponent
	{
		SceneCamera Camera;
		bool Primary = true; // TODO: Move to Scene
		bool FixedAspectRatio = false;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const bool primary, const bool fixedAspectRatio)
			: Primary(primary), FixedAspectRatio(fixedAspectRatio) {}

		void Update(const std::optional<bool>& primary = std::nullopt,
			const std::optional<bool>& fixedAspectRatio = std::nullopt)
		{
			if (primary) Primary = *primary;
			if (fixedAspectRatio) FixedAspectRatio = *fixedAspectRatio;
		}

	};

	struct TransformComponent
	{
		glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& translation)
			: Translation(translation) {}
		TransformComponent(const glm::vec3& translation, const glm::vec3& rotation, const glm::vec3& scale)
			: Translation(translation), Rotation(rotation), Scale(scale) {}

		void Update(const std::optional<glm::vec3>& translation = std::nullopt,
			const std::optional<glm::vec3>& rotation = std::nullopt,
			const std::optional<glm::vec3>& scale = std::nullopt)
		{
			if (translation) Translation = *translation;
			if (rotation) Rotation = *rotation;
			if (scale) Scale = *scale;
		}

		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation)
				* rotation
				* glm::scale(glm::mat4(1.0f), Scale);
		}
	};

	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f,1.0f,1.0f,1.0f };
		Ref<Texture2D> Tex;
		Ref<SubTexture2D> SubTexture;
		float TilingFactor = 1.0f;

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color)
			: Color(color) {}
		SpriteRendererComponent(const glm::vec4& color, float tilingFactor)
			: Color(color), TilingFactor(tilingFactor){}
		SpriteRendererComponent(const glm::vec4& color, Ref<Texture2D>& texture)
			:Color(color), Tex(texture) {
		}
		SpriteRendererComponent(const glm::vec4& color, Ref<SubTexture2D>& subTexture)
			:Color(color), SubTexture(subTexture) {
		}

		void Update(glm::vec4& color)
		{
			Color = color;
		}
		void Update(glm::vec4& color, float tilingFactor)
		{
			Color = color;
			TilingFactor = tilingFactor;
		}

		operator glm::vec4& () { return Color; }
		operator const glm::vec4& () const { return Color; }
	};


	struct NativeScriptComponent
	{
		ScriptableEntity* Instance = nullptr;

		ScriptableEntity*(*InsantiateScript)();
		void (*DestroyScript)(NativeScriptComponent*);

		void Update() {}

		template< typename T>
		void Bind()
		{
			InsantiateScript = []() {return static_cast<ScriptableEntity*>(new T());  };
			DestroyScript = [](NativeScriptComponent* nsc) {delete nsc->Instance; nsc->Instance = nullptr;  };

		}
	};


}
