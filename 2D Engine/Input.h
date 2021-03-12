#pragma once

#include "Core.h"

#include <GLFW/glfw3.h>

namespace TwoDE
{
	class TWO_DLL Input
	{
	public:
		// TODO: make this glfw agnostic
		enum class BUTTON
		{
			RIGHT_KEY = GLFW_KEY_RIGHT,
			LEFT_KEY = GLFW_KEY_LEFT,
			UP_KEY = GLFW_KEY_UP,
			DOWN_KEY = GLFW_KEY_DOWN
		};
		struct ButtonEventInfo
		{
			BUTTON button;
		};

		void init();
		void buttonClicked(int button);
	};
}

