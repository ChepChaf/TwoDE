#include "EngineMath.h"

namespace TwoDE
{
    float EngineMath::clamp(float v, float min, float max)
    {
        if (v < min)
            return min;
        if (v > max)
            return max;
        return v;
    }
    Vector2 EngineMath::clamp(Vector2 v, float min, float max)
    {
        return Vector2(clamp(v.getX(), min, max), clamp(v.getY(), min, max));
    }
}

