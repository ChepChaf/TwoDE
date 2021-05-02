#include "Scene.h"

namespace TwoDE
{
    void Scene::init()
    {
        registry = new entt::registry();
    }

    Entity Scene::CreateEntity()
    {
        return registry->create();
    }

    EntityRegistry* Scene::GetRegistry()
    {
        return registry;
    }
}
