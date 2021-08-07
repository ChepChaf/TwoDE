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
}
