#include "Locator.h"

namespace TwoDE
{
	void Locator::init(Input& input, PubSub& pubsub)
	{
		Locator::inputSystem = std::make_unique<Input>(input);
		Locator::eventSystem = std::make_unique<PubSub>(pubsub);

		Locator::inputSystem->init();
		Locator::eventSystem->init();
	}

	Input& Locator::getInputSystem()
	{
		return *Locator::inputSystem.get();
	}
	PubSub& Locator::getEventSystem()
	{
		return *Locator::eventSystem.get();
	}
}
