#pragma once

#include "Crypt/Renderer/Texture.h"
#include "Crypt/Renderer/SubTexture2D.h"
#include "SceneCamera.h"
#include "ScriptableEntity.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Crypt {
	
	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}

	};

	struct CameraComponent
	{
		SceneCamera Camera;
		bool Primary = true; // TODO: Move to Scene
		bool FixedAspectRatio = false;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;

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

		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), Rotation.x, { 1,0,0 })
				* glm::rotate(glm::mat4(1.0f), Rotation.y, { 0,1,0 })
				* glm::rotate(glm::mat4(1.0f), Rotation.z, { 0,0,1 });

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
		bool hasSubTex = false;
		bool hasTexture = false;

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color);
		SpriteRendererComponent(const glm::vec4& color, Ref<Texture2D>& texture)
			:Color(color), Tex(texture) {
			hasTexture = true;
		}
		SpriteRendererComponent(const glm::vec4& color, Ref<SubTexture2D>& subTexture)
			:Color(color), SubTexture(subTexture) {
			hasSubTex = true;
		}

		operator glm::vec4& () { return Color; }
		operator const glm::vec4& () const { return Color; }
	};


	struct NativeScriptComponent
	{
		ScriptableEntity* Instance = nullptr;

		ScriptableEntity*(*InsantiateScript)();
		void (*DestroyScript)(NativeScriptComponent*);


		template< typename T>
		void Bind()
		{
			InsantiateScript = []() {return static_cast<ScriptableEntity*>(new T());  };
			DestroyScript = [](NativeScriptComponent* nsc) {delete nsc->Instance; nsc->Instance = nullptr;  };

		}
	};


}
