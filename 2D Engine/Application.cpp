#include "Application.h"
#include "Color.h"

#include <iostream>

namespace TwoDE
{
    void Application::init()
    {
        m_Window = Window::createWindow();

        int width = 800;
        int height = 640;

        if (m_Window->init("TwoDEngine", width, height) < 0)
        {
            // TODO: Log error
            std::cout << "Error initializing window" << std::endl;
        }

        m_Renderer = Renderer::createRenderer();
        if (m_Renderer->init(width, height) < 0)
        {
            std::cout << "Error initializing renderer" << std::endl;
        }
    }
    bool Application::shouldClose()
    {
        return m_Window->shouldClose();
    }
    void Application::update()
    {
        m_Renderer->clear(Color(0.5f, 0.5f, 0.0f, 1.0f));
        m_Window->swapBuffers();
    }
}

