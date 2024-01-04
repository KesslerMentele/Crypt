#include "crypch.h"
#include "Crypt/Scene/SceneSerializer.h"

#include "Crypt/Scene/Entity.h"
#include "Crypt/Scene/SceneCamera.h"
#include "Crypt/Scene/Components.h"

#include <yaml-cpp/yaml.h>

#include <optional>
#include <fstream>

namespace YAML
{
	template<>
	struct convert<glm::vec3>
	{
		static Node encode(const glm::vec3& rhs)
		{
			Node node;
			node.push_back(rhs.x);
			node.push_back(rhs.y);
			node.push_back(rhs.z);
			node.SetStyle(EmitterStyle::Flow);
			return node;
		}

		static bool decode(const Node& node, glm::vec3& rhs)
		{
			if (!node.IsSequence() || node.size() != 3)
				return false;

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();
			rhs.z = node[2].as<float>();
			return true;
		}
	};
	
	template<>
	struct convert<glm::vec4>
	{
		static Node encode(const glm::vec4& rhs)
		{
			Node node;
			node.push_back(rhs.x);
			node.push_back(rhs.y);
			node.push_back(rhs.z);
			node.push_back(rhs.w);
			node.SetStyle(EmitterStyle::Flow);
			return node;
		}

		static bool decode(const Node& node, glm::vec4& rhs)
		{
			if (!node.IsSequence() || node.size() != 4)
				return false;
			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();
			rhs.z = node[2].as<float>();
			rhs.w = node[3].as<float>();
			return true;
		}
	};

}


namespace Crypt {

	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec3& v)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << v.x << v.y << v.z << YAML::EndSeq;
		return out;
	}

	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec4& v)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << v.x << v.y << v.z << v.w << YAML::EndSeq;
		return out;
	}

	SceneSerializer::SceneSerializer(const Ref<Scene>& scene)
		:m_Scene(scene)
	{

	}

	static void SerializeEntity(YAML::Emitter& out, Entity entity)
	{
		out << YAML::BeginMap; // Entity
		out << YAML::Key << "Entity" << YAML::Value << "245982924"; // Entity ID

		if (entity.HasComponent<TagComponent>())
		{
			out << YAML::Key << "TagComponent";
			out << YAML::BeginMap; // TagComponent
			auto& tag = entity.GetComponent<TagComponent>().Tag;
			out << YAML::Key << "Tag" << YAML::Value << tag;
			out << YAML::EndMap; // TagComponent
		}

		if (entity.HasComponent<CameraComponent>())
		{
			out << YAML::Key << "CameraComponent";
			out << YAML::BeginMap; // CameraComponent
			
			auto& cameraComponent = entity.GetComponent<CameraComponent>();
			auto& camera = cameraComponent.Camera;
			out << YAML::Key << "Camera";
			out << YAML::BeginMap; // Camera
			out << YAML::Key << "ProjectionType" << YAML::Value << (int)camera.GetProjectionType();
			out << YAML::Key << "Ortho Size" << YAML::Value << camera.GetOrthographicSize();
			out << YAML::Key << "Ortho FarClip" << YAML::Value << camera.GetOrthographicFarClip();
			out << YAML::Key << "Ortho NearClip" << YAML::Value << camera.GetOrthographicNearClip();
			out << YAML::Key << "Perspective VerticalFOV" << YAML::Value << camera.GetPerspectiveVerticalFOV();
			out << YAML::Key << "Perspective FarClip" << YAML::Value << camera.GetPerspectiveFarClip();
			out << YAML::Key << "Perspective NearClip" << YAML::Value << camera.GetPerspectiveNearClip();
			out << YAML::EndMap; // Camera

			out << YAML::Key << "Primary" << YAML::Value << cameraComponent.Primary;
			out << YAML::Key << "FixedAspectRatio" << YAML::Value << cameraComponent.FixedAspectRatio;

			out << YAML::EndMap; // CameraComponent
		}

		if (entity.HasComponent<TransformComponent>())
		{
			out << YAML::Key << "TransformComponent";
			out << YAML::BeginMap; // TransformComponent

			auto& tc = entity.GetComponent<TransformComponent>();
			out << YAML::Key << "Translation" << YAML::Value << tc.Translation;
			out << YAML::Key << "Rotation" << YAML::Value << tc.Rotation;
			out << YAML::Key << "Scale" << YAML::Value << tc.Scale;

			out << YAML::EndMap; // TransformComponent

		}

		if (entity.HasComponent<SpriteRendererComponent>())
		{
			out << YAML::Key << "SpriteRendererComponent";
			out << YAML::BeginMap; // SpriteRendererComponent
			auto& sprite = entity.GetComponent<SpriteRendererComponent>();

			out << YAML::Key << "Color" << YAML::Value << sprite.Color;
			out << YAML::Key << "Has Texture" << YAML::Value << sprite.hasTexture;
			out << YAML::Key << "Texture" << YAML::Value << "Not Yet Implemented!";
			out << YAML::Key << "Has SubTexture" << YAML::Value << sprite.hasSubTex;
			out << YAML::Key << "SubTexture" << YAML::Value << "Not Yet Implemented!";

			out << YAML::EndMap; // SpriteRendererComponent
		}

		if (entity.HasComponent<NativeScriptComponent>())
		{
			out << YAML::Key << "NativeScriptComponent";
			out << YAML::BeginMap; // NativeScriptComponent
			auto& sprite = entity.GetComponent< NativeScriptComponent>();
			out << YAML::Key << "Script" << YAML::Value << "Not Yet Implemented!";

			out << YAML::EndMap; // NativeScriptComponent
		}

		out << YAML::EndMap; // Entity
	}

	void SceneSerializer::SerializeText(const std::string& filepath)
	{
		YAML::Emitter out;
		out << YAML::BeginMap;
		out << YAML::Key << "Scene" << YAML::Value << "Untitled";
		out << YAML::Key << "Entities" << YAML::Value << YAML::BeginSeq;
		m_Scene->m_Registry.each([&](auto entityID)
			{
				Entity entity = { entityID, m_Scene.get() };
				if (!entity)
					return;
				SerializeEntity(out, entity);
			});
		out << YAML::EndSeq;
		out << YAML::EndMap;

		std::ofstream fout(filepath);
		fout << out.c_str();
	}

	void SceneSerializer::SerializeBinary(const std::string& filepath)
	{
		// Not Implemented
		CRY_CORE_ASSERT(false);

	}

	bool SceneSerializer::DeserializeText(const std::string& filepath)
	{
		if (!filepath.empty())
		{
			YAML::Node data = YAML::LoadFile(filepath);
			if (!data["Scene"])
				return false;
			std::string sceneName = data["Scene"].as<std::string>();
			CRY_CORE_TRACE("Deserializing scene '{0}'", sceneName);

			auto entities = data["Entities"];
			if (entities)
			{
				for (auto entity : entities)
				{
					uint64_t uuid = entity["Entity"].as<uint64_t>();
					std::string name;
					auto tagComponent = entity["TagComponent"];
					if (tagComponent)
					{
						name = tagComponent["Tag"].as<std::string>();
					}

					CRY_CORE_TRACE("Deserialized entity with ID = {0}, name = {1}", uuid, name);

					Entity deserializedEntity = m_Scene->CreateEntity(name);

					auto cameraComponent = entity["CameraComponent"];
					if (cameraComponent)
					{
						auto& cc = deserializedEntity.AddOrUpdateComponent<CameraComponent>(cameraComponent["Primary"].as<bool>(), cameraComponent["FixedAspectRatio"].as<bool>());
						auto& cameraProps = cameraComponent["Camera"];
						cc.Camera.SetProjectionType((SceneCamera::ProjectionType)cameraProps["ProjectionType"].as<int>());
						cc.Camera.SetOrthographicSize(cameraProps["Ortho Size"].as<float>());
						cc.Camera.SetOrthographicFarClip(cameraProps["Ortho FarClip"].as<float>());
						cc.Camera.SetOrthographicNearClip(cameraProps["Ortho NearClip"].as<float>());
						cc.Camera.SetPerspectiveVerticalFOV(cameraProps["Perspective VerticalFOV"].as<float>());
						cc.Camera.SetPerspectiveFarClip(cameraProps["Perspective FarClip"].as<float>());
						cc.Camera.SetPerspectiveNearClip(cameraProps["Perspective NearClip"].as<float>());

					}

					auto transformComponent = entity["TransformComponent"];
					if (transformComponent)
					{
						auto& tc = deserializedEntity.AddOrUpdateComponent<TransformComponent>(transformComponent["Translation"].as<glm::vec3>(),
							transformComponent["Rotation"].as<glm::vec3>(),
							transformComponent["Scale"].as<glm::vec3>());
					}

					auto spriteRendererComponent = entity["SpriteRendererComponent"];
					if (spriteRendererComponent)
					{
						auto& sprite = deserializedEntity.AddOrUpdateComponent<SpriteRendererComponent>(spriteRendererComponent["Color"].as<glm::vec4>());
						// TODO: Add Tex and SubTex Support
					}

					auto nativeScriptComponent = entity["NativeScriptComponent"];
					if (nativeScriptComponent)
					{
						//TODO: Make this work
					}

				}
			}
			return true;
		}
		return false;
	}

	bool SceneSerializer::DeserializeBinary(const std::string& filepath)
	{
		// Not Implemented
		CRY_CORE_ASSERT(false);
		return false;

	}
}
