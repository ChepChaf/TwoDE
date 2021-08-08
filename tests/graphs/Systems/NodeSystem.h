#pragma once

#include "../Components/NodeComponent.h"

#include <TwoDE.h>
#include <Components/ClickableComponent.h>

class NodeSystem : public TwoDE::ISystem
{
public:
    void update() override;

    void start() override;
};

void NodeSystem::update()
{
    ISystem::update();
}

void NodeSystem::start()
{
    ISystem::start();

    auto registry = TwoDE::Locator::getLocator().getSceneManagerSystem().GetRegistry();
    auto sceneManager = TwoDE::Locator::getLocator().getSceneManagerSystem();
    auto view = registry->view<NodeComponent, TwoDE::Sprite>();

    TwoDE::Color red = {0.8f, 0.2f, 0.2f, 1.0f};
    TwoDE::Color gray = {0.2f, 0.2f, 0.2f, 1.0f};

    auto clickEvent = TwoDE::ClickableComponent(std::function(
            [=, this](TwoDE::Entity entity) {
                auto& sprite = registry->get<TwoDE::Sprite>(entity);

                if (sprite.color == red) {
                    sprite.color = gray;
                } else {
                    sprite.color = red;
                }
            }
    ));

    for (auto entity : view) {
        sceneManager.AddComponent<TwoDE::ClickableComponent>(entity, clickEvent);
    }
}
