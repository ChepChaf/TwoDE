#include "Locator.h"

namespace TwoDE
{
    void Locator::initLocator(Input &input, PubSub &pubsub, ResourceManager &resourceManager, Scene &sceneManager,
                              SystemRegistry &systemRegistry)
    {
        this->inputSystem = input;
        this->eventSystem = pubsub;
        this->resourceManagerSystem = resourceManager;
        this->sceneManagerSystem = sceneManager;
        this->systemRegistry = systemRegistry;

        inputSystem.init();
        eventSystem.init();
        resourceManagerSystem.init();
        sceneManagerSystem.init();
        systemRegistry.init();

        this->camera = sceneManagerSystem.CreateEntity();
    }

    Input &Locator::getInputSystem()
    {
        return inputSystem;
    }

    PubSub &Locator::getEventSystem()
    {
        return eventSystem;
    }

    ResourceManager &Locator::getResourceManagerSystem()
    {
        return resourceManagerSystem;
    }

    Scene &Locator::getSceneManagerSystem()
    {
        return sceneManagerSystem;
    }

    SystemRegistry &Locator::getSystemRegistry()
    {
        return systemRegistry;
    }

    Transform &Locator::getCamera()
    {
        auto registry = TwoDE::Locator::getLocator().getSceneManagerSystem().GetRegistry();

        return registry->get<Transform>(camera);
    }

    Entity &Locator::getCameraEntity()
    {
        return camera;
    }
}
