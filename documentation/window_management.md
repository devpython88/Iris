Creating and managing a window in iris is pretty simple.


## Creating window

To create a window follow these steps:
1. Import `iris/iris_window.h`.

    Many features of iris are seperated into modules.

2. Create a `Game` object

    The game object has three constructors.
    1. `Game()`: Enables VSYNC and AntiAliasing and sets the default window title and size
    2. `Game(std::string title, int w, int h)`: Enables VSYNC and AntiAliasing and allows for window customization
    3. `Game(std::string title, Vec2 size, int flags)`: Allows for custom [flags](#window-flags).



## Rendering a basic screen
You can change the window background color by using the `setBackgroundColor` method along with the `Colors` class.

Example: `window.setBackgroundColor(Colors::PastelGreen)`

The `Game` class comes with two functions named `start`

One will take callbacks, the other will use defaults.

Example:
1. `window.start()`: Continues to fill a screen
2. `window.start(initFunc, drawFunc, updateFunc, unloadFunc)`: Handle many things but allows for custom logic

The function signatures are as follows:
1. `init`: `()`
2. `draw`: `()`
3. `update`: `(float deltaTime)`
4. `unload`: `()`

You can directly pass the functions as parameters, No need for convertion

For a full graphical tutorial, go to `graphics.md` but here i will show you how you can draw a simple text onto the screen:

Paste this in `draw`:

`GraphicsRenderer::drawText(20, 20, "Your text", 16, Colors::PastelBlack);`


## Window flags

Window flags are just int values that you can combine using `|` to customize the window

### Flags:
- `FlagVsynchronous`: Makes the window sync to the monitor refresh rate
- `FlagAntiAliased`: Makes the window draw stuff and blend it for smoother and finer edges
- `FlagFullscreen`: Makes the window fullscreen
- `FlagMinimized`: Minimizes the window
- `FlagMaximized`: Maximizes the window
- `FlagNoDecoration`: Removes the title bar

### How to use:
To pass flags, you can do this `flag1 | flag2 | flag3`

Example: `FlagFullscreen | FlagVsynchronous | FlagAntiAliased`