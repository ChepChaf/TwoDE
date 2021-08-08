#pragma once

#include "Core.h"

#include "Input.h"
#include "PubSub.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "SystemRegistry.h"
#include "Transform.h"

#include <memory>

namespace TwoDE
{
    class TWO_DLL Locator
    {
        Input inputSystem;
        PubSub eventSystem;
        ResourceManager resourceManagerSystem;
        Scene sceneManagerSystem;
        SystemRegistry systemRegistry;

        Entity camera;
    public:
        inline static void
        init(Input &input, PubSub &pubsub, ResourceManager &rm, Scene &scene, SystemRegistry &systemRegistry)
        {
            getLocator().initLocator(input, pubsub, rm, scene, systemRegistry);
        }

        inline static Locator &getLocator()
        {
            static Locator locator;
            return locator;
        }

        void initLocator(Input &, PubSub &, ResourceManager &, Scene &, SystemRegistry &);

        Input &getInputSystem();

        PubSub &getEventSystem();

        ResourceManager &getResourceManagerSystem();

        Scene &getSceneManagerSystem();

        SystemRegistry &getSystemRegistry();

        Transform &getCamera();
        Entity &getCameraEntity();
    };
}

