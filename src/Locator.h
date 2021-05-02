#pragma once

#include "Core.h"

#include "Input.h"
#include "PubSub.h"
#include "ResourceManager.h"
#include "Scene.h"

#include <memory>

namespace TwoDE
{
	class TWO_DLL Locator
	{
		inline static Input inputSystem;
		inline static PubSub eventSystem;
		inline static ResourceManager resourceManagerSystem;
		inline static Scene sceneManagerSystem;

	public:
		inline static void init(Input&, PubSub&, ResourceManager&, Scene&);
		inline static Input&  getInputSystem();
		inline static PubSub& getEventSystem();
		inline static ResourceManager& getResourceManagerSystem();
		inline static Scene& getSceneManagerSystem();
	};
}

