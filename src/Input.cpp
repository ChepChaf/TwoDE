#include "Input.h"
#include "Locator.h"
#include "Event.h"

#include <functional>

namespace TwoDE
{
    void Input::init()
    {
        Locator::getLocator().getEventSystem().subscribe("button_clicked",
                                                         Event(std::function([=, this](ButtonEventInfo &params) {
                                                                                 keyboardButtonsPressed[params.button] = true;
                                                                             }
                                                         )));

        Locator::getLocator().getEventSystem().subscribe("button_released",
                                                         Event(std::function([=, this](ButtonEventInfo &params) {
                                                                                 keyboardButtonsPressed[params.button] = false;
                                                                             }
                                                         )));
    }

    void Input::buttonClicked(int button)
    {
        ButtonEventInfo info{.button = (BUTTON) button};
        Locator::getLocator().getEventSystem().publish("button_clicked", info);
    }

    void Input::buttonReleased(int button)
    {
        ButtonEventInfo info{.button = (BUTTON) button};
        Locator::getLocator().getEventSystem().publish("button_released", info);
    }

    void Input::mouseClick(int button, glm::vec2 position)
    {
        MouseEventInfo info{.position=position, .button = (MOUSE_BUTTON) button};
        Locator::getLocator().getEventSystem().publish("mouse_click", info);
    }

    void Input::mouseRelease(int button, glm::vec2 position)
    {
        MouseEventInfo info{.position=position, .button = (MOUSE_BUTTON) button};
        Locator::getLocator().getEventSystem().publish("mouse_release", info);
    }

    void Input::mouseScroll(glm::vec2 position, glm::vec2 offset)
    {
        ScrollEventInfo info{.position = position, .offset = offset};
        Locator::getLocator().getEventSystem().publish("mouse_scroll", info);
    }

    bool Input::buttonPressed(BUTTON button)
    {
        return keyboardButtonsPressed[static_cast<BUTTON>(button)];
    }

    void Input::setCursorPosition(glm::vec2 position)
    {
        currentMousePosition = position;
    }

    glm::vec2 Input::getCursorPosition()
    {
        return currentMousePosition;
    }
}
