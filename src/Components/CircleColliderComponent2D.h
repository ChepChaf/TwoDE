#pragma once

#include "ColliderComponent2D.h"

namespace TwoDE
{
    class CircleColliderComponent2D : public ColliderComponent2D
    {
        float radius = 0.f;

    public:
        bool collision(glm::vec3 position, glm::vec3 collisionPoint) override;
        CircleColliderComponent2D(float radius) : radius(radius) {}
    };

    bool CircleColliderComponent2D::collision(glm::vec3 position, glm::vec3 collisionPoint)
    {
        return glm::length(collisionPoint-position) < radius;
    }
}
