#include "iris_window.h"

void ViewCamera::enterCameraMode()
{

    BeginMode2D(camera);   
}

void ViewCamera::exitCameraMode()
{
    EndMode2D();
}

void ViewCamera::centerTo(float x, float y)
{
    setTarget(x + (GetScreenWidth() / 2), y + (GetScreenHeight() / 2));
}

void ViewCamera::centerTo(const Vec2& pos)
{
    centerTo(pos.x, pos.y);
}
