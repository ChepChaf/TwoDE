#pragma once
#include "Core.h"

#include <entt/entt.hpp>

namespace TwoDE
{
	typedef entt::entity Entity;
	typedef entt::registry EntityRegistry;

	class TWO_DLL Scene
	{
		EntityRegistry* registry = nullptr;

	public:
		Scene() = default;
		void init();
		Entity CreateEntity();

		template<typename T, typename ...Args>
		T AddComponent(Entity, Args&& ...);

		EntityRegistry* GetRegistry();
	};
	template<typename T, typename ...Args>
	inline T Scene::AddComponent(Entity ent, Args&& ...args)
	{
		return registry->emplace<T>(ent, args...);
	}
}

