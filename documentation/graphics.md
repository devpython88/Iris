All of this is in `iris/iris_graphics.h`


# Understanding shapes

All shapes inherit from a base class called `Obj2D`
`Obj2D` contains the angle, origin, velocity, position, size, canCollide and isVisible properties of an object

`Obj2D` itself isn't a visual thing, It is just a wrapper for objects.

All properties have setters and getters

Aswell as some other functions:
`move(Vec2) or move(float, float)`: Changes the velocity by the given vector/xy
`addRotation(float)`: Adds the value to the rotation, use `-` operator to subtract (since adding position + negative = subtraction)
`getPosition(): Vec2`: The position and size are in x, y, width, height so this is used when you want the x and y together
`getSize(): Vec2`: Same as above, both of these functions also have their setter counterparts

`update(bool frameIndependent)`: The parameter is true by default, Updates the velocity and multiplies it by deltaTime if you wanted it to be frame independent

`lookAt(Vec2) or lookAt(float, float)`: Makes the object's angle face towards the given point

`step(float)`: Moves the object by `steps` in the direction the angle is facing

> Sidenote: getX and getY return x and y relative to their center, getRawX and getRawY dont. same goes for getRawPosition




## Origins

In iris there are some origin constant vectors that are helpers for origining.

You can simply multiply the size of the object by their values to get the desired origin.

These are the constant's names:
- `ORIGIN_TOPLEFT`
- `ORIGIN_TOPRIGHT`
- `ORIGIN_TOP`
- `ORIGIN_CENTERLEFT`
- `ORIGIN_CENTER`
- `ORIGIN_CENTERRIGHT`
- `ORIGIN_BOTTOMLEFT`
- `ORIGIN_BOTTOM`
- `ORIGIN_BOTTOMRIGHT`

Example:

`obj.setOrigin(obj.getSize() * ORIGIN_CENTER)`


## Visual shapes

For a rectangle, you can use the `Rect2D` which is just `Obj2D` but with a color field.

Example:
```cpp
Rect2D rec(20, 20, 50, 50, Colors::Green);
GraphicsRenderer::drawRectangle(rec);
```

For non-box shapes (such as circles, polygons) use immediate mode functions

> `Colors` class provides `RGBAColor` colors just so you don't get confused.

- `drawCircle(Vec2 center, float radius, RGBAColor color);`
- `drawEllipse(Vec2 center, Vec2 size, RGBAColor color);`
- `drawCircleLines(Vec2 center, float radius, RGBAColor color);`
- `drawEllipseLines(Vec2 center, Vec2 size, RGBAColor color);`
- `drawLine(Vec2 start, Vec2 end, int thickness, RGBAColor color);`
- `drawPoint(Vec2 pos, RGBAColor color);`


## Textures

To load a texture.
Simply use `TextureService`

And use `GraphicsRenderer` to draw it

Example:
```cpp
TextureService::loadTexture("MyTexture.png", "MyTextureName");

GraphicsRenderer::drawTexture("MyTextureName", xPos, yPos);
```


For rotation, scaling and other you can use [Sprite2D](#sprites)


## Sprites

`Sprite2D` is a `Obj2D` subclass that wraps around a texture and provides you with cutouts, scaling and other


`Sprite2D` has setters and getters for scaling and the cutout to draw.

For collision use `getScaledRect` to get the scaled cutout rectangle.

Cutout has two setters
`setCutout(x, y, w, h)`
`setCutout(const Obj2D&)`

To construct a sprite:
`Sprite2D sprite("TextureName", x, y);`

To draw a sprite:
`GraphicsRenderer::drawSprite(sprite)`

> If you are still confused, Cutout rectangle will just take a piece from your whole texture and draw it instead of the whole texture, By default the cutout is the whole texture



## Collision

Obj2D has three static collision methods:

- `bool checkIntersection(Obj2D a, Obj2D b);`: Checks collision between two boxes
- `bool checkIntersectionCircle(Obj2D a, Vec2 center, float radius);`: Checks collision between a box and a circle
- `bool checkIntersectionCircles(Vec3 a, Vec3 b);`: Checks collision between circles

> Tip: For sprites with custom cutouts (Like spritesheets) use `getScaledRect()` to get the scaled Obj2D cutout box.

