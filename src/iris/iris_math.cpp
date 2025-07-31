#include "iris_math.h"

bool MathUtils::isZero(float v)
{
    return fabsf(v) <= 1e-6;
}

float MathUtils::getDistance(Vec2 a, Vec2 b)
{
    return fabsf((b.x - a.x) + (b.y - a.y));
}