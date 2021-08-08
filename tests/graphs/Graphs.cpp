#include "Graphs.h"

#include "Systems/NodeSystem.h"

#include <iostream>
#include <Components/CircleColliderComponent2D.h>

void GraphsApp::start()
{
    float size = 2.0;
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            auto circle = renderer->drawCircle({x * size, y * size, 0}, size, {0.2f, 0.2f, 0.2f, 1.0f});
            TwoDE::Locator::getLocator().getSceneManagerSystem().AddComponent<NodeComponent>(circle);
            TwoDE::Locator::getLocator().getSceneManagerSystem().AddComponent<TwoDE::CircleColliderComponent2D>(circle, 2.0);
        }
    }

    auto registry = getEntityRegistry();
    auto& cam = registry->get<TwoDE::Transform>(camera);

    cam.translate({-10, 0});
    cam.scale({25.f, 25.f});

    TwoDE::Locator::getLocator().getSystemRegistry().subscribe<NodeSystem>();
}

void GraphsApp::update()
{
    TwoDE::Application::update();

    auto registry = getEntityRegistry();

    renderer->clear({0.35f, 0.35f, 0.35f, 1.f});
}