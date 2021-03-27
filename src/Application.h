#pragma once

#include "Core.h"

#include "ResourceManager.h"
#include "Window.h"
#include "Renderer.h"
#include "Camera.h"

#include <memory>
#include <ctime>

namespace TwoDE
{
	class TWO_DLL Application
	{
		long elapsed = 0;
		Window* window = nullptr;
	protected:
		std::unique_ptr<Camera> camera;

		Renderer* renderer;

	public:
		void init();
		bool shouldClose();

		virtual void start() = 0;
		virtual void update();
	};

	Application* createApplication();
}

