#include "iris_window.h"

void ViewCamera::enterCameraMode()
{

    BeginMode2D(camera);   
}

void ViewCamera::exitCameraMode()
{
    EndMode2D();
}
