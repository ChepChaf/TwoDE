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

namespace TwoDE
{
    void Application::init()
    {
        Logger::init();

        Input inputSystem;
        PubSub pubsub;
     
        Locator::init(inputSystem, pubsub);

        TWODE_CORE_INFO("Hello from Application init");

        resourceManager = std::make_unique<ResourceManager>();
        camera = std::make_unique<Camera>();

        window = Window::createWindow();

        int width = 800;
        int height = 640;

        if (window->init("TwoDEngine", &width, &height) < 0)
        {
            // TODO: Log error
            TWODE_CORE_ERROR("Error initializing window");
        }

        renderer = Renderer::createRenderer();

        if (renderer->init(width, height) < 0)
        {
            TWODE_CORE_ERROR("Error initializing renderer");
        }
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

        renderer->draw(*camera.get());
        window->swapBuffers();
    }
}

