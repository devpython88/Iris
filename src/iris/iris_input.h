#pragma once
#include <raylib.h>
#include "iris_math.h"

class Keyboard {
    public:

    static bool isKeyHit(int key);
    static bool isKeyHeld(int key);
    static bool isKeyUp(int key);
    static bool isKeyReleased(int key);
};



class Mouse {
    public:

    static Vec2 getPosition();
    static Vec2 getScrollVec();
    static float getScroll();

    static bool isButtonHit(int btn);
    static bool isButtonHeld(int btn);
    static bool isButtonReleased(int btn);
    static bool isButtonUp(int btn);
};