#include "Locator.h"

namespace TwoDE
{
	void Locator::init(Input& input, PubSub& pubsub, ResourceManager& resourceManager)
	{
		Locator::inputSystem = std::make_unique<Input>(input);
		Locator::eventSystem = std::make_unique<PubSub>(pubsub);
		Locator::resourceManagerSystem = std::make_unique<ResourceManager>(resourceManager);

		Locator::inputSystem->init();
		Locator::eventSystem->init();
		Locator::resourceManagerSystem->init();
	}

	Input& Locator::getInputSystem()
	{
		return *Locator::inputSystem.get();
	}
	PubSub& Locator::getEventSystem()
	{
		return *Locator::eventSystem.get();
	}
	ResourceManager& Locator::getResourceManagerSystem()
	{
		return *Locator::resourceManagerSystem.get();
	}
}
