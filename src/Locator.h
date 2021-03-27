#pragma once

#include "Core.h"

#include "Input.h"
#include "PubSub.h"
#include "ResourceManager.h"

#include <memory>

namespace TwoDE
{
	class TWO_DLL Locator
	{
		inline static std::unique_ptr<Input> inputSystem;
		inline static std::unique_ptr<PubSub> eventSystem;
		inline static std::unique_ptr<ResourceManager> resourceManagerSystem;

	public:
		static void init(Input& input, PubSub& pubsub, ResourceManager& resourceManager);
		static Input&  getInputSystem();
		static PubSub& getEventSystem();
		static ResourceManager& getResourceManagerSystem();
	};
}

