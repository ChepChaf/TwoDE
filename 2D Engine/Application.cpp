#include "Application.h"
#include "Color.h"
#include "EngineTime.h"
#include "Logger.h"

#include <iostream>
#include <memory>
#include <ctime>

namespace TwoDE
{
    void Application::init()
    {
        Logger::init();
        TWODE_CORE_INFO("Hello from Application init");

        resourceManager = std::make_unique<ResourceManager>();

        window = Window::createWindow();

        int width = 800;
        int height = 640;

        if (window->init("TwoDEngine", &width, &height) < 0)
        {
            // TODO: Log error
            std::cout << "Error initializing window" << std::endl;
        }

        renderer = Renderer::createRenderer();

        if (renderer->init(width, height) < 0)
        {
            std::cout << "Error initializing renderer" << std::endl;
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

        renderer->draw();
        window->swapBuffers();
    }
}

