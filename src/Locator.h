#pragma once

#include "Core.h"

#include "Input.h"
#include "PubSub.h"
#include "ResourceManager.h"
#include "Scene.h"

#include <memory>

namespace TwoDE {
    class TWO_DLL Locator
    {
        Input inputSystem;
        PubSub eventSystem;
        ResourceManager resourceManagerSystem;
        Scene sceneManagerSystem;

    public:
        inline static void init(Input &input, PubSub &pubsub, ResourceManager &rm, Scene &scene)
        {
            getLocator().initLocator(input, pubsub, rm, scene);
        }

        inline static Locator &getLocator()
        {
            static Locator locator;
            return locator;
        }

        void initLocator(Input &, PubSub &, ResourceManager &, Scene &);

        Input &getInputSystem();

        PubSub &getEventSystem();

        ResourceManager &getResourceManagerSystem();

        Scene &getSceneManagerSystem();
    };
}

