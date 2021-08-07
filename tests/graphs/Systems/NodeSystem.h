#pragma once

#include "../Components/NodeComponent.h"

class NodeSystem : public TwoDE::ISystem
{
public:
    void update() override;
    void start() override;
};

void NodeSystem::update()
{
    ISystem::update();

    auto registry = TwoDE::Locator::getLocator().getSceneManagerSystem().GetRegistry();

    auto view = registry->view<NodeComponent, TwoDE::Sprite>();

    for (auto [_, node, sprite] : view.each())
    {
        TwoDE::Color color = { TwoDE::Random(), TwoDE::Random(), TwoDE::Random(), TwoDE::Random()};
        sprite.color = color;
    }
}

void NodeSystem::start()
{
    ISystem::start();
}
