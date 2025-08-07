## Keyboard input

To get keyboard input, Use `Keyboard` from `iris/iris_input.h`.

Key constants:
`KeyA`
`KeyB`
`KeyC`
`KeyD`
`KeyE`
`KeyF`
`KeyG`
`KeyH`
`KeyI`
`KeyJ`
`KeyK`
`KeyL`
`KeyM`
`KeyN`
`KeyO`
`KeyP`
`KeyQ`
`KeyR`
`KeyS`
`KeyT`
`KeyU`
`KeyV`
`KeyW`
`KeyX`
`KeyY`
`KeyZ`
`Key0`
`Key1`
`Key2`
`Key3`
`Key4`
`Key5`
`Key6`
`Key7`
`Key8`
`Key9`
`LeftCtrl`
`RightCtrl`
`LeftShift`
`RightShift`
`LeftAlt`
`RightAlt`
`LeftSuper`
`RightSuper`
`eys`
`Enter`
`Escape`
`Space`
`Tab`
`Backspace`
`Insert`
`Delete`
`Home`
`End`
`PageUp`
`PageDown`
`CapsLock`
`ScrollLock`
`NumLock`
`PrintScreen`
`Pause`
`Up`
`Down`
`Left`
`Right`
`F1`
`F2`
`F3`
`F4`
`F5`
`F6`
`F7`
`F8`
`F9`
`F10`
`F11`
`F12`
`KP0`
`KP1`
`KP2`
`KP3`
`KP4`
`KP5`
`KP6`
`KP7`
`KP8`
`KP9`
`KPDecimal`
`KPDivide`
`KPMultiply`
`KPSubtract`
`KPAdd`
`KPEnter`
`KPEqual`
`Apostrophe`
`Comma`
`Minus`
`Period`
`Slash`
`Semicolon`
`Equal`
`LeftBracket`
`Backslash`
`RightBracket`
`Grave`
`Menu`




Functions:

`bool isKeyHit(int key)`: checks if key is pressed once
`bool isKeyHeld(int key)`: checks if key is held
`bool isKeyUp(int key)`: checks if key is not held (not pressed, not released, not nothing)
`bool isKeyReleased(int key)`: checks if key was pressed but just got released


## Mouse Input

### Position and scroll
Use `getWorldPosition(ViewCamera)` to get the world mouse position, and `getPosition` to get the screen-space position
Use `getScroll` to get the y scroll, `getScrollVec` to get both x and y scroll

### Input

Constants:
`LeftButton`
`RightButton`
`MiddleButton`
`BackButton`
`ForwardButton`
`ExtraButton`
`SideButton`

Functions:
`isButtonHit(int btn)`
`isButtonHeld(int btn)`
`isButtonReleased(int btn)`
`isButtonUp(int btn)`