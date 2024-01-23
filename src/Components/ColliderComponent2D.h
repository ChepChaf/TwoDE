#pragma once

#include <glm/glm.hpp>

namespace TwoDE
{
    class ColliderComponent2D
    {
    public:
        virtual bool collision(glm::vec3 position, glm::vec3 collisionPoint);
    };

    bool ColliderComponent2D::collision(glm::vec3 position, glm::vec3 collisionPoint)
    {
        return false;
    }
}