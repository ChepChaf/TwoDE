#pragma once

#include "Core.h"

#include "Window.h"
#include "Renderer.h"

namespace TwoDE
{
	class TWO_DLL Application
	{
		Window* m_Window = nullptr;
		Renderer* m_Renderer = nullptr;

	public:
		void init();
		bool shouldClose();
		virtual void update();
	};

	Application* createApplication();
}

