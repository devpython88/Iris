#pragma once
#include <raylib.h>
#include "iris_math.h"
#include "iris_window.h"

class ViewCamera;

class Keyboard {
    public:
    // Alphabet keys
    static const int KeyA = KEY_A;
    static const int KeyB = KEY_B;
    static const int KeyC = KEY_C;
    static const int KeyD = KEY_D;
    static const int KeyE = KEY_E;
    static const int KeyF = KEY_F;
    static const int KeyG = KEY_G;
    static const int KeyH = KEY_H;
    static const int KeyI = KEY_I;
    static const int KeyJ = KEY_J;
    static const int KeyK = KEY_K;
    static const int KeyL = KEY_L;
    static const int KeyM = KEY_M;
    static const int KeyN = KEY_N;
    static const int KeyO = KEY_O;
    static const int KeyP = KEY_P;
    static const int KeyQ = KEY_Q;
    static const int KeyR = KEY_R;
    static const int KeyS = KEY_S;
    static const int KeyT = KEY_T;
    static const int KeyU = KEY_U;
    static const int KeyV = KEY_V;
    static const int KeyW = KEY_W;
    static const int KeyX = KEY_X;
    static const int KeyY = KEY_Y;
    static const int KeyZ = KEY_Z;

    // Number keys
    static const int Key0 = KEY_ZERO;
    static const int Key1 = KEY_ONE;
    static const int Key2 = KEY_TWO;
    static const int Key3 = KEY_THREE;
    static const int Key4 = KEY_FOUR;
    static const int Key5 = KEY_FIVE;
    static const int Key6 = KEY_SIX;
    static const int Key7 = KEY_SEVEN;
    static const int Key8 = KEY_EIGHT;
    static const int Key9 = KEY_NINE;

    // Modifier keys
    static const int LeftCtrl = KEY_LEFT_CONTROL;
    static const int RightCtrl = KEY_RIGHT_CONTROL;
    static const int LeftShift = KEY_LEFT_SHIFT;
    static const int RightShift = KEY_RIGHT_SHIFT;
    static const int LeftAlt = KEY_LEFT_ALT;
    static const int RightAlt = KEY_RIGHT_ALT;
    static const int LeftSuper = KEY_LEFT_SUPER;   // Windows key (left)
    static const int RightSuper = KEY_RIGHT_SUPER; // Windows key (right)

    // Other common keys
    static const int Enter = KEY_ENTER;
    static const int Escape = KEY_ESCAPE;
    static const int Space = KEY_SPACE;
    static const int Tab = KEY_TAB;
    static const int Backspace = KEY_BACKSPACE;
    static const int Insert = KEY_INSERT;
    static const int Delete = KEY_DELETE;
    static const int Home = KEY_HOME;
    static const int End = KEY_END;
    static const int PageUp = KEY_PAGE_UP;
    static const int PageDown = KEY_PAGE_DOWN;
    static const int CapsLock = KEY_CAPS_LOCK;
    static const int ScrollLock = KEY_SCROLL_LOCK;
    static const int NumLock = KEY_NUM_LOCK;
    static const int PrintScreen = KEY_PRINT_SCREEN;
    static const int Pause = KEY_PAUSE;

    // Arrow keys
    static const int Up = KEY_UP;
    static const int Down = KEY_DOWN;
    static const int Left = KEY_LEFT;
    static const int Right = KEY_RIGHT;

    // Function keys
    static const int F1 = KEY_F1;
    static const int F2 = KEY_F2;
    static const int F3 = KEY_F3;
    static const int F4 = KEY_F4;
    static const int F5 = KEY_F5;
    static const int F6 = KEY_F6;
    static const int F7 = KEY_F7;
    static const int F8 = KEY_F8;
    static const int F9 = KEY_F9;
    static const int F10 = KEY_F10;
    static const int F11 = KEY_F11;
    static const int F12 = KEY_F12;

    // Keypad keys
    static const int KP0 = KEY_KP_0;
    static const int KP1 = KEY_KP_1;
    static const int KP2 = KEY_KP_2;
    static const int KP3 = KEY_KP_3;
    static const int KP4 = KEY_KP_4;
    static const int KP5 = KEY_KP_5;
    static const int KP6 = KEY_KP_6;
    static const int KP7 = KEY_KP_7;
    static const int KP8 = KEY_KP_8;
    static const int KP9 = KEY_KP_9;
    static const int KPDecimal = KEY_KP_DECIMAL;
    static const int KPDivide = KEY_KP_DIVIDE;
    static const int KPMultiply = KEY_KP_MULTIPLY;
    static const int KPSubtract = KEY_KP_SUBTRACT;
    static const int KPAdd = KEY_KP_ADD;
    static const int KPEnter = KEY_KP_ENTER;
    static const int KPEqual = KEY_KP_EQUAL;

    // Symbols and punctuation
    static const int Apostrophe = KEY_APOSTROPHE;
    static const int Comma = KEY_COMMA;
    static const int Minus = KEY_MINUS;
    static const int Period = KEY_PERIOD;
    static const int Slash = KEY_SLASH;
    static const int Semicolon = KEY_SEMICOLON;
    static const int Equal = KEY_EQUAL;
    static const int LeftBracket = KEY_LEFT_BRACKET;
    static const int Backslash = KEY_BACKSLASH;
    static const int RightBracket = KEY_RIGHT_BRACKET;
    static const int Grave = KEY_GRAVE;

    // Misc
    static const int Menu = KEY_MENU;

    static bool isKeyHit(int key);
    static bool isKeyHeld(int key);
    static bool isKeyUp(int key);
    static bool isKeyReleased(int key);
};



class Mouse {
    public:

    static const int LeftButton = MOUSE_BUTTON_LEFT;
    static const int RightButton = MOUSE_BUTTON_RIGHT;
    static const int MiddleButton = MOUSE_BUTTON_MIDDLE;
    static const int BackButton = MOUSE_BUTTON_BACK;
    static const int ForwardButton = MOUSE_BUTTON_FORWARD;
    static const int ExtraButton = MOUSE_BUTTON_EXTRA;
    static const int SideButton = MOUSE_BUTTON_SIDE;

    static Vec2 getPosition();
    static Vec2 getWorldPosition(ViewCamera camera);
    static Vec2 getScrollVec();
    static float getScroll();
    static bool isButtonHit(int btn);
    static bool isButtonHeld(int btn);
    static bool isButtonReleased(int btn);
    static bool isButtonUp(int btn);
};