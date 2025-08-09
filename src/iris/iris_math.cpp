#include "iris_math.h"

const Direction Directions::DirectionUp = Vec2(0, -1);
const Direction Directions::DirectionDown = Vec2(0, 1);
const Direction Directions::DirectionLeft = Vec2(-1, 0);
const Direction Directions::DirectionRight = Vec2(1, 0);

bool MathUtils::isZero(float v)
{
    return fabsf(v) < 1e-6f;
}

float MathUtils::getManhattanDistance(Vec2 a, Vec2 b)
{
    return fabsf(b.x - a.x) + fabsf(b.y - a.y);
}

float MathUtils::getEuclideanDistance(Vec2 a, Vec2 b)
{
    float dx = b.x - a.x;
    float dy = b.y - a.y;

    return sqrtf((dx * dx) + (dy * dy));
}

float MathUtils::getManhattanDistance(float x1, float y1, float x2, float y2)
{
    return getManhattanDistance(Vec2(x1, y1), Vec2(x2, y2));
}

float MathUtils::getEuclideanDistance(float x1, float y1, float x2, float y2)
{
    return getEuclideanDistance(Vec2(x1, y1), Vec2(x2, y2));
}
