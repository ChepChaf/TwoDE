#include "Input.h"
#include "Locator.h"


namespace TwoDE
{
	void Input::init()
	{
	}

	void Input::buttonClicked(int button)
	{
		ButtonEventInfo info{ .button = (BUTTON)button };
		Locator::getEventSystem().publish("button_clicked", info);
	}

	void Input::buttonReleased(int button)
	{
		ButtonEventInfo info{ .button = (BUTTON)button };
		Locator::getEventSystem().publish("button_released", info);
	}
	void Input::mouseClick(int button, Vector2 position)
	{
		MouseEventInfo info{ .position=position, .button = (MOUSE_BUTTON)button };
		Locator::getEventSystem().publish("mouse_click", info);
	}
	void Input::mouseRelease(int button, Vector2 position)
	{
		MouseEventInfo info{ .position=position, .button = (MOUSE_BUTTON)button };
		Locator::getEventSystem().publish("mouse_release", info);
	}
	void Input::mouseScroll(Vector2 position, Vector2 offset)
	{
		ScrollEventInfo info{ .position = position, .offset = offset };
		Locator::getEventSystem().publish("mouse_scroll", info);
	}
	void Input::setCursorPosition(Vector2 position)
	{
		currentMousePosition = position;
	}
	Vector2 Input::getCursorPosition()
	{
		return currentMousePosition;
	}
}
