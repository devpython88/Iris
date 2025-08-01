#pragma once

#include "iris_math.h"
#include "iris_logging.h"
#include <inttypes.h>
#include <map>
#include <vector>
#include <string>

enum class TextureResult {
    LoadFailed,
    LoadSuccess
};


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

    bool canCollide;
    bool visible;

    public:

    Obj2D() = default;
    Obj2D(float x, float y, float width, float height):
    x(x), y(y), width(width), height(height), velocity(0, 0), rotation(0), origin(0, 0),
    visible(true), canCollide(true){}

    float getX() const { return x - origin.x; }
    float getRawX() const { return x; }
    void setX(float x_) { x = x_; }

    float getY() const { return y - origin.y; }
    float getRawY() const { return y; }
    void setY(float y_) { y = y_; }

    float getWidth() const { return width; }
    void setWidth(float width_) { width = width_; }

    float getHeight() const { return height; }
    void setHeight(float height_) { height = height_; }

    Vec2 getSize() const { return Vec2(width, height); }
    Vec2 getPosition() const { return Vec2(x, y); }

    void setSize(float w, float h) { width = w; height = h; }
    void setPosition(float x_, float y_){ x = x_; y = y_; }

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

    // Checks intersection between two bounding boxes
    static bool checkIntersection(Obj2D a, Obj2D b);

    // Checks intersection between a bouding box and a circle
    static bool checkIntersectionCircle(Obj2D a, Vec2 center, float radius);

    // Checks intersection between circles
    static bool checkIntersectionCircles(Vec3 a, Vec3 b);

    // Returns a raylib rectangle, mainly used in library
    Rectangle raylibRec(){ return Rectangle{x, y, width, height}; }

    bool getCanCollide() const { return canCollide; }
    void setCanCollide(bool canCollide_) { canCollide = canCollide_; }

    bool getVisible() const { return visible; }
    void setVisible(bool visible_) { visible = visible_; }
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

};





// renderer

class TextureService;
class Sprite2D;

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
    static void drawTexture(float x, float y, std::string id, Vec2 scale = Vec2(1.0f, 1.0f));
    static void drawSprite(Sprite2D sprite);
};






class TextureService {
    private:
    static std::map<std::string, Texture> textures;

    public:

    static TextureResult loadTexture(std::string path, std::string id);
    static bool textureExists(std::string id);
    static void unloadTexture(std::string id);
    static bool isLoaded(std::string id);
    static Texture* getRTexture(std::string id);
    static void unloadEverything();
     
    static std::map<std::string, Texture> getTextures() { return textures; }
};








class Sprite2D : public Obj2D {
    private:
    Texture* tex;
    Vec2 scale;
    bool flipX;
    bool flipY;

    Obj2D cutout;

    public:

    Sprite2D(): Obj2D(){}
    Sprite2D(std::string id, float x, float y): Obj2D(x, y, 0, 0), scale(1.0f, 1.0f), flipX(false), flipY(false){
        if (!TextureService::textureExists(id)){
            LogService::error("Sprite attempted to load nonexistent texture by identifier: ", id, ".");
            return;
        }

        tex = TextureService::getRTexture(id);

        if (tex == nullptr){
            LogService::error("Sprite attempted to load nonexistent texture by identifier: ", id, ".");
            return;
        }

        setSize(static_cast<float>(tex->width), static_cast<float>(tex->height));
        setCutout(0, 0, static_cast<float>(tex->width), static_cast<float>(tex->height));
    }

    Vec2 getScale() const { return scale; }
    void setScale(const Vec2 &scale_) { scale = scale_; }
    void setScale(float x, float y) { scale = Vec2(x, y); }

    Vec2 getScaledSize() const { return getSize() * getScale(); }

    bool getFlipX() const { return flipX; }
    void setFlipX(bool flipX_) { flipX = flipX_; }

    bool getFlipY() const { return flipY; }
    void setFlipY(bool flipY_) { flipY = flipY_; }

    Boolean2 getFlip() const { return Boolean2(flipX, flipY); }
    void setFlip(bool x, bool y) { flipX = x; flipY = y; }

    // Returns rectangle, Must be used when checking collision with scaled sprites as it provides a scaled rect
    Obj2D getRect() const { return Obj2D(x, y,
        width * scale.x,
        height * scale.y); }

    Texture* getTex() const { return tex; }

    Obj2D getCutout() const { return Obj2D(cutout.getRawX(), cutout.getRawY(),
        cutout.getWidth() * (flipX ? -1.0f : 1.0f),
        cutout.getHeight() * (flipY ? -1.0f : 1.0f)); }
    
    void setCutout(const Obj2D &cutout_) { cutout = cutout_; }
    void setCutout(float x, float y, float w, float h) { setCutout(Obj2D(x, y, w, h)); }
};



class AnimatedSprite2D : public Sprite2D {
    private:
    int fps;
    float lastFtime;
    int row;
    int rows;
    int column;
    int columns;
    Vec2 frameSize;
    bool loop;
    bool paused;

public:

    AnimatedSprite2D(): Sprite2D(){}

    AnimatedSprite2D(std::string id, Vec2 pos, Vec2 frameSize, int fps = 10): Sprite2D(id, pos.x, pos.y),
    frameSize(frameSize), row(0), column(0), fps(fps),
    loop(false), paused(false), columns(0), rows(0), lastFtime(1.0f / fps){
        if (getTex()->id != 0){
            columns = getTex()->width / frameSize.x;
            rows = getTex()->height / frameSize.y;
        }
    }

    
    int getFps() const { return fps; }
    void setFps(int fps_) { fps = fps_; }

    int getRow() const { return row; }
    void setRow(int row_) { row = row_; }

    int getRows() const { return rows; }
    void setRows(int rows_) { rows = rows_; }

    int getColumn() const { return column; }
    void setColumn(int column_) { column = column_; }

    int getColumns() const { return columns; }
    void setColumns(int columns_) { columns = columns_; }

    Vec2 getFrameSize() const { return frameSize; }
    void setFrameSize(const Vec2 &frameSize_) { frameSize = frameSize_; }

    bool doesLoop() const { return loop; }
    void setLoop(bool loop_) { loop = loop_; }

    // advances column by one and loops back if loop is enabled
    void advance(){ column = column + 1 < columns ? column + 1 : (loop ? 0 : column); }

    bool getPaused() const { return paused; }
    void setPaused(bool paused_) { paused = paused_; }

    void pause() { setPaused(true); }
    void resume() { setPaused(false); }
    void togglePause() { setPaused(!getPaused()); }

    // Updates the frame.
    void updateAnimation();
};