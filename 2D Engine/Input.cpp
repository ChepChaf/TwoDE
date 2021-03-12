#include "Input.h"
#include "Locator.h"

void TwoDE::Input::init()
{
}

void TwoDE::Input::buttonClicked(int button)
{
	ButtonEventInfo info{ .button = (BUTTON)button };
	Locator::getEventSystem().publish("button_clicked", info);
}
