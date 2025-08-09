All of this is in `iris/iris_graphics.md` aswell

## Spritesheets

by default in iris you can use Sprite2D and its cutout feature to make simple spritesheets

But what if you want framerate control and automatic row-col management?

Well you should learn about AnimatedSprite2D!

## Animated sprites

AnimatedSprite2D is a subclass of Sprite2D that manages framerate control and row-col for you.

Constructor: `AnimatedSprite2D(std::string textureName, Vec2 pos, Vec2 frameSize)`

It has six extra fields: `rows`, `columns`, `row`, `column`, `fps` and `loop`

You can update the animation with `updateAnimation`
And handle pausing with `setPause`, `pause()`, `resume()` and `isPaused()`
And finally handle looping with `setLoop` and `doesLoop`

## Drawing

You can draw both `Sprite2D`s and `AnimatedSprite2D`s with `GraphicsRenderer::drawSprite`

## Mapped animations

In `AnimatedSprite2D` you can use `addAnimation(std::string id, int row, int col)` to add a animation by identifier

Then use `selectAnimation(std::string id)` to move to it.
You can also `removeAnimation(std::string id)` and `hasAnimation(std::string id)`.
