#include "crypch.h"
#include "Scene.h"

#include "Components.h"
#include "Crypt/Renderer/Renderer2D.h"

#include "Entity.h"

#include <glm/glm.hpp>

namespace Crypt {

	
	Scene::Scene()
	{


		entt::entity entity = m_Registry.create();
		auto& transform = m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
		
		//m_Registry.on_construct<TransformComponent>().connect<&DoSomething>();
		
		
		


		if (m_Registry.all_of<TransformComponent>(entity))
			TransformComponent& transform = m_Registry.get<TransformComponent>(entity);

		auto view = m_Registry.view<TransformComponent>();
		for (auto entity : view)
		{
			TransformComponent& transform = view.get<TransformComponent>(entity);

		}

	
	}
	Scene::~Scene()
	{
		
	}
	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>(name);
		
		tag.Tag = name.empty() ? "Entity" : name;

		return entity;
	}
	void Scene::OnUpdate(Timestep ts)
	{
		// Render 2D
		Camera* mainCamera = nullptr;
		glm::mat4* cameraTransform = nullptr;
		{
			auto view = m_Registry.view<CameraComponent, TransformComponent>();
			for (auto entity : view)
			{
				auto& [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);
				
				if (camera.Primary)
				{
					mainCamera = &camera.Camera;
					cameraTransform = &transform.Transform;
					break;
				}
			}
		}

		if (mainCamera)
		{
			Renderer2D::BeginScene(mainCamera->GetProjection(), *cameraTransform);

			auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
			for (auto entity : group)
			{
				auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
				Renderer2D::DrawQuad(transform, sprite.Color);

			}
			Renderer2D::EndScene();
		}
	}
}