#pragma once

#include "Core.h"

namespace TwoDE
{
    class TWO_DLL ISystem
    {
    public:
        virtual void update();

        virtual void start();
    };
}
