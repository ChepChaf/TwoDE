#include "Locator.h"

namespace TwoDE
{
    void Locator::initLocator(Input& input, PubSub& pubsub, ResourceManager& resourceManager, Scene& sceneManager)
	{
		inputSystem.init();
		eventSystem.init();
		resourceManagerSystem.init();
		sceneManagerSystem.init();
	}

	Input& Locator::getInputSystem()
	{
		return inputSystem;
	}
	PubSub& Locator::getEventSystem()
	{
		return eventSystem;
	}
	ResourceManager& Locator::getResourceManagerSystem()
	{
		return resourceManagerSystem;
	}
	Scene& Locator::getSceneManagerSystem()
	{
		return sceneManagerSystem;
	}
}
