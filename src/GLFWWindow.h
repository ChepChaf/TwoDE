#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace TwoDE
{
	class GLFWWindow : public Window
	{
		GLFWwindow* m_Window;

	public:
		// Inherited via Window
		GLFWWindow();
		virtual int init(std::string windowName, int* width, int* height) override;
		virtual void destroy() override;
		virtual bool shouldClose() override;
		virtual void swapBuffers() override;
	private:
		static void windowSizeCallback(GLFWwindow* window, int width, int height);
	};
}

