#include "EntityManager.h"

namespace astro { namespace entity {

	EntityManager::EntityManager()
	{
	}

	EntityManager::~EntityManager()
	{
		for (size_t i = 0; i < m_Entities.size(); ++i) 
		{
			delete m_Entities[i];
		}
	}

	void EntityManager::Submit(Entity* entity)
	{
		m_Entities.push_back(entity);
	}

	void EntityManager::RemoveEntityAtIndex(const int& index)
	{
		m_Entities.erase(begin(m_Entities)+index);
	}

	void EntityManager::Clear()
	{
		m_Entities.clear();
	}

	void EntityManager::OnInput(const SDL_Event &event)
	{
		for (auto &entity : m_Entities) 
		{
			if (!entity->IsRemoved())
			{
				entity->OnInput(event);
			}
		}
	}
	
	void EntityManager::OnUpdate()
	{
		for (auto &entity : m_Entities) 
		{
			if (!entity->IsRemoved())
			{
				entity->OnUpdate();
			}
		}
	}

	void EntityManager::OnRender(graphics::Renderer2D *renderer)
	{
		for (auto &entity : m_Entities) 
		{
			if (!entity->IsRemoved())
			{
				entity->OnRender(renderer);
			}
		}
	}

} }