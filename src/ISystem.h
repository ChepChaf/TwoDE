#pragma once

namespace TwoDE
{
    class ISystem
    {
    public:
        virtual void update();

        virtual void start();
    };
}
