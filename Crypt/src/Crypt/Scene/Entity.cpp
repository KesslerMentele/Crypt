#include "crypch.h"
#include "Entity.h"

namespace Crypt {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}
}
