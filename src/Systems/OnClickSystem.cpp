#include <Locator.h>
#include <Components/ColliderComponent2D.h>
#include <Transform.h>
#include <Components/ClickableComponent.h>
#include <Components/CircleColliderComponent2D.h>
#include "OnClickSystem.h"

void TwoDE::OnClickSystem::update()
{
    ISystem::update();
}

void TwoDE::OnClickSystem::start()
{
    ISystem::start();

    Locator::getLocator().getEventSystem().subscribe("mouse_click", TwoDE::Event(
            std::function([=](TwoDE::Input::MouseEventInfo &params) {
                auto registry = TwoDE::Locator::getLocator().getSceneManagerSystem().GetRegistry();

                auto view = registry->view<CircleColliderComponent2D, Transform, ClickableComponent>();

                for (auto entity : view)
                {
                    auto col = view.get<CircleColliderComponent2D>(entity);
                    auto transform = view.get<Transform>(entity);

                    if (col.collision(glm::vec3{params.position, 0.0f}, transform.getPosition()))
                    {
                        auto click = view.get<ClickableComponent>(entity);
                        click.onClickEvent(entity);

                        return;
                    }
                }
            })));
}
