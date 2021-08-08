#pragma  once

#include "ISystem.h"

namespace TwoDE
{
    class OnClickSystem : public ISystem
    {
    public:
        void update() override;
        void start() override;
    };
}
