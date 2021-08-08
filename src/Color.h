#pragma once

#include "Core.h"
#include <functional>
#include <string>

namespace TwoDE
{
    class TWO_DLL Color
    {
    public:
        float r, g, b, alpha;

        Color(float r, float g, float b, float a) : r(r), g(g), b(b), alpha(a){}
        bool operator==(const Color& other);
    };
}

namespace std
{
    template<>
    struct hash<TwoDE::Color>
    {
        std::size_t operator()(TwoDE::Color &k) const
        {
            using std::size_t;
            using std::hash;
            using std::string;

            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:

            return ((hash<float>()(k.r)
                     ^ (hash<float>()(k.g) << 1)) >> 1)
                   ^ (hash<float>()(k.b) << 1)
                   ^ (hash<float>()(k.alpha) << 1);
        }
    };
}

