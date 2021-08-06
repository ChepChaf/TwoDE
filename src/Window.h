#pragma once

#include <string>

namespace TwoDE
{
	class Window
	{
	public:
		virtual int init(std::string windowName, int* width, int* height) = 0;
		virtual void destroy() = 0;
		virtual bool shouldClose() = 0;
		virtual void swapBuffers() = 0;
		static Window* createWindow();
	};
}


