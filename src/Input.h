#pragma once

#include "Core.h"
#include "Vector2.h"

#include <GLFW/glfw3.h>

#include <map>

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
			DOWN_KEY = GLFW_KEY_DOWN,
			SPACE_KEY = GLFW_KEY_SPACE
		};

		enum class MOUSE_BUTTON
		{
			LEFT_BUTTON = GLFW_MOUSE_BUTTON_LEFT,
			RIGHT_BUTTON = GLFW_MOUSE_BUTTON_RIGHT,
			MIDDLE_BUTTON = GLFW_MOUSE_BUTTON_MIDDLE
		};

		struct ButtonEventInfo
		{
			BUTTON button;
		};

		struct MouseEventInfo
		{
			Vector2 position;
			MOUSE_BUTTON button;
		};

		struct ScrollEventInfo
		{
			Vector2 position;
			Vector2 offset;
		};

		void init();
		void buttonClicked(int button);
		void buttonReleased(int button);

		void mouseClick(int button, Vector2 position);
		void mouseRelease(int button, Vector2 position);

		void mouseScroll(Vector2 position, Vector2 offset);

		bool buttonPressed(BUTTON button);


		void setCursorPosition(Vector2 position);
		Vector2 getCursorPosition();
	private:
		Vector2 currentMousePosition;

		std::map<BUTTON, bool> keyboardButtonsPressed;
	};
}

