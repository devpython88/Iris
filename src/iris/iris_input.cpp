#include "iris_input.h"

bool Keyboard::isKeyHit(int key)
{
    return IsKeyPressed(key);
}

bool Keyboard::isKeyHeld(int key)
{
    return IsKeyDown(key);
}

bool Keyboard::isKeyUp(int key)
{
    return IsKeyUp(key);
}

bool Keyboard::isKeyReleased(int key)
{
    return IsKeyReleased(key);
}

Vec2 Mouse::getPosition(){
    return Vec2(GetMouseX(), GetMouseY());
}

Vec2 Mouse::getWorldPosition(ViewCamera camera)
{
    return getPosition() + camera.getTarget();
}

Vec2 Mouse::getScrollVec(){
    return Vec2(GetMouseWheelMoveV().x, GetMouseWheelMoveV().y);
}

float Mouse::getScroll(){
    return GetMouseWheelMove();
}


bool Mouse::isButtonHit(int btn){
    return IsMouseButtonPressed(btn);
}

bool Mouse::isButtonHeld(int btn){
    return IsMouseButtonDown(btn);
}

bool Mouse::isButtonReleased(int btn){
    return IsMouseButtonReleased(btn);
}

bool Mouse::isButtonUp(int btn){
    return IsMouseButtonUp(btn);
}
