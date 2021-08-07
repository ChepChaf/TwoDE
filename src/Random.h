#pragma once

#include <cstdlib>
#include <ctime>

namespace TwoDE
{
    constexpr int numDecimals = 8;

    void SetSeed()
    {
        std::srand(std::time(nullptr));
    }

    float Random()
    {
        return static_cast<float>(rand()) / RAND_MAX;
    }
}
