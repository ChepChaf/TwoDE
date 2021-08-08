#pragma once

#include <Vector3.h>

namespace TwoDE
{
    class ColliderComponent2D
    {
    public:
        virtual bool collision(Vector3 position, Vector3 collisionPoint);
    };

    bool ColliderComponent2D::collision(Vector3 position, Vector3 collisionPoint)
    {
        return false;
    }
}