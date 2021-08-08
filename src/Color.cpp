#include "Color.h"

bool TwoDE::Color::operator==(const TwoDE::Color &other)
{
    return r == other.r && g == other.g && b == other.b && alpha == other.alpha;
}
