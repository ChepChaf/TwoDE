#include "Locator.h"

namespace TwoDE
{
	void Locator::init(Input& input, PubSub& pubsub, ResourceManager& resourceManager, Scene& sceneManager)
	{
		Locator::inputSystem.init();
		Locator::eventSystem.init();
		Locator::resourceManagerSystem.init();
		Locator::sceneManagerSystem.init();
	}

	inline Input& Locator::getInputSystem()
	{
		return inputSystem;
	}
	inline PubSub& Locator::getEventSystem()
	{
		return eventSystem;
	}
	inline ResourceManager& Locator::getResourceManagerSystem()
	{
		return resourceManagerSystem;
	}
	inline Scene& Locator::getSceneManagerSystem()
	{
		return sceneManagerSystem;
	}
}
