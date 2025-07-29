#pragma once

#include "iris_math.h"
#include <inttypes.h>
#include <vector>
#include <string>



class RGBAColor {
    public:
    uint8_t r, g, b, a;

    RGBAColor(): r(0), g(0), b(0), a(0){}
    RGBAColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a): r(r), g(g), b(b), a(a){}
    RGBAColor(Color rCol): r(rCol.r), g(rCol.g), b(rCol.b), a(rCol.a){}

    operator Color(){
        return Color{r, g, b, a};
    }
};

class Colors {
    public:
    static RGBAColor Red;
    static RGBAColor Yellow;
    static RGBAColor Green;
    static RGBAColor Brown;
    static RGBAColor Sky;
    static RGBAColor Blue;
    static RGBAColor Cyan;
    static RGBAColor White;
    static RGBAColor Orange;
    static RGBAColor Teal;
    static RGBAColor Gray;
    static RGBAColor Grey;
    static RGBAColor Black;
    static RGBAColor LightGray;
    static RGBAColor Lime;
    static RGBAColor DarkGreen;
    static RGBAColor Forest;
    static RGBAColor Desert;
    static RGBAColor Ocean;
    static RGBAColor AutumnLeaves;
    
    static RGBAColor PastleRed;
    static RGBAColor PastleYellow;
    static RGBAColor PastleGreen;
    static RGBAColor PastleBrown;
    static RGBAColor PastleSky;
    static RGBAColor PastleBlue;
    static RGBAColor PastleCyan;
    static RGBAColor PastleWhite;
    static RGBAColor PastleOrange;
    static RGBAColor PastleTeal;
    static RGBAColor PastleGray;
    static RGBAColor PastleGrey;
    static RGBAColor PastleBlack;
    static RGBAColor PastleLightGray;
    static RGBAColor PastleLime;
    static RGBAColor PastleDarkGreen;
    static RGBAColor PastleForest;
    static RGBAColor PastleDesert;
    static RGBAColor PastleOcean;
    static RGBAColor PastleAutumnLeaves;
};








class Obj2D {
    protected:
    float x;
    float y;
    float width;
    float height;

    Vec2 velocity;
    float rotation;
    Vec2 origin;

    public:

    Obj2D() = default;
    Obj2D(float x, float y, float width, float height):
    x(x), y(y), width(width), height(height), velocity(0, 0), rotation(0), origin(0, 0){}

    float getX() const { return x; }
    void setX(float x_) { x = x_; }

    float getY() const { return y; }
    void setY(float y_) { y = y_; }

    float getWidth() const { return width; }
    void setWidth(float width_) { width = width_; }

    float getHeight() const { return height; }
    void setHeight(float height_) { height = height_; }

    Vec2 getSize() const { return Vec2(width, height); }
    Vec2 getPosition() const { return Vec2(x, y); }

    // moves
    void move(float dx, float dy) { addVelocity(dx, dy); }

    // moves
    void move(Vector2 delta){ move(delta.x, delta.y); }


    // updates position on velocity
    void update();
    
    Vec2 getVelocity() const { return velocity; }
    void setVelocity(const Vec2 &velocity_) { velocity = velocity_; }

    // adds to the velocity
    void addVelocity(float dx, float dy){ velocity = velocity + Vec2(dx, dy); }

    float getRotation() const { return rotation; }
    void setRotation(float rotation_) { rotation = rotation_; }

    // adds to the rotation
    void addRotation(float val) { rotation += val; }

    Vec2 getOrigin() const { return origin; }
    void setOrigin(const Vec2 &origin_) { origin = origin_; }

    // looks at something
    void lookAt(Vec2 pos);

    // looks at something
    void lookAt(float x, float y);

    // Steps forward relative to the rotation
    void step(float amount);
};




class Rect2D : public Obj2D {
    private:
    RGBAColor color;

    public:

    Rect2D(): Obj2D(){}
    Rect2D(float x, float y, float w, float h, RGBAColor color):
    Obj2D(x, y, w, h), color(color){}

    RGBAColor getColor() const { return color; }
    void setColor(const RGBAColor &color_) { color = color_; }

    Rectangle raylibRec(){ return Rectangle{x, y, width, height}; }
};





// renderer

class GraphicsRenderer {
    public:

    static void drawRectangle(Rect2D rect);
    static void drawCircle(Vec2 center, float radius, RGBAColor color);
    static void drawEllipse(Vec2 center, Vec2 size, RGBAColor color);
    static void drawCircleLines(Vec2 center, float radius, RGBAColor color);
    static void drawEllipseLines(Vec2 center, Vec2 size, RGBAColor color);
    static void drawLine(Vec2 start, Vec2 end, int thickness, RGBAColor color);
    static void drawPoint(Vec2 pos, RGBAColor color);
    static void drawText(float x, float y, std::string text, int size, RGBAColor color);
};