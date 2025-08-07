## ViewCamera

Cameras are a essential part of games as they provide you with the ability to have a game world larger than the screen size

`ViewCamera` allows you to do just that!

Constructor: `ViewCamera(Vec2 target, float zoom = 1.0f, float rotation = 0.0f, Vec2 offset = Vec2(0.0f, 0.0f))`


Methods:
`void enterCameraMode()`: Anything drawn after this's called is in the game world instead of the screen-space
`void exitCameraMode()`: Anything drawn after is in the screen-space
`void centerTo(float x, float y)`: Centers the camera to a certain point
`void centerTo(const Vec2& pos)`: Centers the camera to a certain point