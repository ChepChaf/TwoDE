#include <glm/gtc/matrix_transform.hpp>

#include "GLFWWindow.h"
#include "Locator.h"
#include "Logger.h"
#include "Transform.h"

namespace TwoDE
{
	GLFWWindow::GLFWWindow()
	{
		m_Window = nullptr;
	}

	int GLFWWindow::init(std::string windowName, int* width, int* height)
	{
		if (!glfwInit())
			return -1;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		m_Window = glfwCreateWindow(*width, *height, windowName.c_str(), NULL, NULL);

		if (!m_Window)
		{
			// TODO: Add Logging
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(m_Window);

		glfwGetFramebufferSize(m_Window, width, height);

		auto key_callback = [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS)
				Locator::getLocator().getInputSystem().buttonClicked(key);
			else if (action == GLFW_RELEASE)
				Locator::getLocator().getInputSystem().buttonReleased(key);
		};
		glfwSetKeyCallback(m_Window, key_callback);

		auto mouse_callback = [](GLFWwindow* window, int button, int action, int mods)
		{
			double x, y;

			glfwGetCursorPos(window, &x, &y);

			TWODE_CORE_TRACE("Mouse clicked at {0}, {1}", x, y);

			int width, height;
			glfwGetWindowSize(window, &width, &height);

			// Transform to OpenGL coordinates
			x = (x / width) + 0.5;
			y = 1-(y+0.5) / height;

			TWODE_CORE_TRACE("Mouse clicked at {0}, {1}", x, y);

			if (action == GLFW_PRESS)
			    Locator::getLocator().getInputSystem().mouseClick(button, glm::vec2{ static_cast<float>(x), static_cast<float>(y) });
			if (action == GLFW_RELEASE)
			    Locator::getLocator().getInputSystem().mouseRelease(button, glm::vec2{ static_cast<float>(x), static_cast<float>(y) });
		};
		glfwSetMouseButtonCallback(m_Window, mouse_callback);

		auto cursor_callback = [](GLFWwindow* window, double xpos, double ypos)
		{
			int width, height;
			glfwGetWindowSize(window, &width, &height);

			xpos = xpos / width;
			ypos = 1-ypos / height;

			Locator::getLocator().getInputSystem().setCursorPosition(glm::vec2{ static_cast<float>(xpos), static_cast<float>(ypos) });
		};
		glfwSetCursorPosCallback(m_Window, cursor_callback);

		auto scroll_callback = [](GLFWwindow* window, double xoffset, double yoffset)
		{
			double x, y;
			glfwGetCursorPos(window, &x, &y);

			int width, height;
			glfwGetWindowSize(window, &width, &height);

			x = x / width;
			y = 1-y / height;

			Locator::getLocator().getInputSystem().mouseScroll(glm::vec2{ static_cast<float>(x), static_cast<float>(y) },
				glm::vec2{ static_cast<float>(xoffset), static_cast<float>(yoffset) });
		};
		glfwSetScrollCallback(m_Window, scroll_callback);

		return 0;
	}

	void GLFWWindow::destroy()
	{
		glfwDestroyWindow(m_Window);
	}

	bool GLFWWindow::shouldClose()
	{
		glfwPollEvents();
		return glfwWindowShouldClose(m_Window);
	}

	void GLFWWindow::swapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
	void GLFWWindow::windowSizeCallback(GLFWwindow* window, int width, int height)
	{
		glfwSetWindowSize(window, width, height);
	}
}
