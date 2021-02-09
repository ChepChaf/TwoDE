#pragma once

#include "Core.h"

#include "ResourceManager.h"
#include "Window.h"
#include "Renderer.h"

#include <memory>
#include <ctime>

namespace TwoDE
{
	class TWO_DLL Application
	{
		long elapsed = 0;
		Window* window = nullptr;
	protected:
		std::unique_ptr<ResourceManager> resourceManager;
		Renderer* renderer;

	public:
		void init();
		bool shouldClose();

		virtual void start() = 0;
		virtual void update();
	};

	Application* createApplication();
}

