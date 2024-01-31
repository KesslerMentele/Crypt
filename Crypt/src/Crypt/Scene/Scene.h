#pragma once

#include "Crypt/Core/Timestep.h"
#include "Crypt/Renderer/EditorCamera.h"
#include "Crypt/Core/UUID.h"

#include <entt.hpp>
#include <filesystem>

class b2World;

namespace Crypt {

	class Entity;

	class Scene
	{
	public:

		Scene();

		Scene(const std::filesystem::path& path)
			: m_ScenePath(path)
		{}

		~Scene(); 

		static Ref<Scene> Copy(Ref<Scene> other);
		
		Entity CreateEntity(const std::string& name = std::string());
		
		Entity CreateEntityWithUUID(UUID uuid, const std::string& name);
		
		void DestoryEntity(Entity entity);

		void OnRuntimeStart();
		void OnRuntimeStop();

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateEditor(Timestep ts, EditorCamera& camera);
		void OnViewportResize(uint32_t width, uint32_t height);

		std::filesystem::path GetPath() { return m_ScenePath; }
		void SetPath(const std::filesystem::path& path) { m_ScenePath = path; }

		void DuplicateEntity(Entity entity);

		Entity GetPrimaryCameraEntity();

	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);

	private:
		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
		std::filesystem::path m_ScenePath;

		b2World* m_PhysicsWorld = nullptr;

		friend class SceneSerializer;
		friend class Entity;
		friend class SceneHierarchyPanel;
	};
}
