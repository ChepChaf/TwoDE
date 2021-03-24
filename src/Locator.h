#pragma once

#include "Core.h"

#include "Input.h"
#include "PubSub.h"

#include <memory>

namespace TwoDE
{
	class TWO_DLL Locator
	{
		inline static std::unique_ptr<Input> inputSystem;
		inline static std::unique_ptr<PubSub> eventSystem;
	public:
		static void init(Input& input, PubSub& pubsub);
		static Input&  getInputSystem();
		static PubSub& getEventSystem();
	};
}

