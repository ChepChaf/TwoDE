#pragma once

#include "ColliderComponent2D.h"

namespace TwoDE
{
    class CircleColliderComponent2D : public ColliderComponent2D
    {
        float radius = 0.f;

    public:
        bool collision(Vector3 position, Vector3 collisionPoint) override;
        CircleColliderComponent2D(float radius) : radius(radius) {}
    };

    bool CircleColliderComponent2D::collision(Vector3 position, Vector3 collisionPoint)
    {
        return (collisionPoint-position).magnitude() < radius;
    }
}
