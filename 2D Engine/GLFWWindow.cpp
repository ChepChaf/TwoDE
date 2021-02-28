#include "GLFWWindow.h"

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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
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