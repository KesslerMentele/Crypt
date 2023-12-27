#pragma once

#include "Crypt/Renderer/Texture.h"
#include "Crypt/Renderer/SubTexture2D.h"
#include "SceneCamera.h"
#include "ScriptableEntity.h"
#include <glm/glm.hpp>


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
		glm::mat4 Transform{ 1.0f };
		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
			: Transform(transform) {}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }
	};

	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f,1.0f,1.0f,1.0f };
		Ref<Texture2D> Tex;
		Ref<SubTexture2D> SubTexture;
		bool isSubTex;


		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color, Ref<Texture2D>& texture)
			:Color(color), Tex(texture) {
			isSubTex = false;
		}
		SpriteRendererComponent(const glm::vec4& color, Ref<SubTexture2D>& subTexture)
			:Color(color), SubTexture(subTexture) {
			isSubTex = true;
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
