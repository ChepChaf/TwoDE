//
// Created by chep on 7/8/21.
//

#pragma once

namespace TwoDE
{
    class ClickableComponent
            {
            public:
                std::function<void(const Entity&)> onClickEvent;

                ClickableComponent() = default;
                ClickableComponent(std::function<void(const Entity&)> onClickEvent) : onClickEvent(onClickEvent){}
            };
}