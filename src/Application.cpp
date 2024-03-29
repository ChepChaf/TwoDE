#include "Application.h"
#include "Color.h"
#include "EngineTime.h"
#include "Logger.h"
#include "PubSub.h"
#include "Locator.h"
#include "Input.h"

#include <iostream>
#include <memory>
#include <ctime>
#include <Systems/OnClickSystem.h>

namespace TwoDE
{
    void Application::init()
    {
        Logger::init();

        Input inputSystem;
        PubSub pubsub;
        ResourceManager resourceManager;
        Scene sceneManager;
        SystemRegistry systemRegistry;

        Locator::getLocator().init(inputSystem, pubsub, resourceManager, sceneManager, systemRegistry);

        TWODE_CORE_INFO("Hello from Application init");

        camera = Locator::getLocator().getCameraEntity();

        Transform trans;
        trans.setScale({8.f, 8.f, 0.0f});
        trans.setPosition({590.f, 120.f, 0.f});
        Locator::getLocator().getSceneManagerSystem().AddComponent<Transform>(camera, trans);

        window = Window::createWindow();

        int width = 800;
        int height = 640;

        if (window->init("TwoDEngine", &width, &height) < 0) {
            // TODO: Log error
            TWODE_CORE_ERROR("Error initializing window");
        }

        renderer = Renderer::createRenderer();

        if (renderer->init(width, height) < 0) {
            TWODE_CORE_ERROR("Error initializing renderer");
        }

        systemRegistry.subscribe<OnClickSystem>();
    }

    bool Application::shouldClose()
    {
        return window->shouldClose();
    }

    void Application::update()
    {
        auto current = std::clock();
        EngineTime::deltaTime = current - elapsed;
        EngineTime::deltaTime /= 1000;

        elapsed = current;

        for (auto&[_, system] : Locator::getLocator().getSystemRegistry().getActiveSystems()) {
            system->update();
        }

        renderer->draw(getEntityRegistry()->get<Transform>(camera));
        window->swapBuffers();
    }

    EntityRegistry *Application::getEntityRegistry()
    {
        return Locator::getLocator().getSceneManagerSystem().GetRegistry();
    }

    SystemRegistry *Application::getSystemRegistry()
    {
        return &Locator::getLocator().getSystemRegistry();
    }
}

