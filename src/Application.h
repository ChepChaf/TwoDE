#pragma once

#include "Core.h"

#include "ResourceManager.h"
#include "Window.h"
#include "Renderer.h"
#include "Scene.h"
#include "Locator.h"

#include <memory>
#include <ctime>

namespace TwoDE
{
	class TWO_DLL Application
	{
		long elapsed = 0;
		Window* window = nullptr;
	protected:
		Entity camera;

		Renderer* renderer;
	public:
		void init();
		bool shouldClose();

		virtual void start() = 0;
		virtual void update();
		EntityRegistry* getEntityRegistry();
	};

	Application* createApplication();
}

