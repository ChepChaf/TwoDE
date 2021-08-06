#include "Window.h"

#include "GLFWWindow.h"

namespace TwoDE
{
	Window* Window::createWindow()
	{
		return new GLFWWindow();
	}
}

