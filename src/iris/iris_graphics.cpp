#include "iris_graphics.h"

RGBAColor Colors::Red = RGBAColor(255, 0, 0, 255);
RGBAColor Colors::Yellow = RGBAColor(255, 255, 0, 255);
RGBAColor Colors::Green = RGBAColor(0, 255, 0, 255);
RGBAColor Colors::Brown = RGBAColor(139, 69, 19, 255);
RGBAColor Colors::Sky = RGBAColor(135, 206, 235, 255);
RGBAColor Colors::Blue = RGBAColor(0, 0, 255, 255);
RGBAColor Colors::Cyan = RGBAColor(0, 255, 255, 255);
RGBAColor Colors::White = RGBAColor(255, 255, 255, 255);
RGBAColor Colors::Orange = RGBAColor(255, 165, 0, 255);
RGBAColor Colors::Teal = RGBAColor(0, 128, 128, 255);
RGBAColor Colors::Gray = RGBAColor(128, 128, 128, 255);
RGBAColor Colors::Grey = RGBAColor(128, 128, 128, 255);
RGBAColor Colors::Black = RGBAColor(0, 0, 0, 255);
RGBAColor Colors::LightGray = RGBAColor(211, 211, 211, 255);
RGBAColor Colors::Lime = RGBAColor(50, 205, 50, 255);
RGBAColor Colors::DarkGreen = RGBAColor(0, 100, 0, 255);
RGBAColor Colors::Forest = RGBAColor(34, 139, 34, 255);
RGBAColor Colors::Desert = RGBAColor(237, 201, 175, 255);
RGBAColor Colors::Ocean = RGBAColor(28, 107, 160, 255);
RGBAColor Colors::AutumnLeaves = RGBAColor(205, 92, 92, 255);

RGBAColor Colors::PastleRed = RGBAColor(255, 105, 97, 200);
RGBAColor Colors::PastleYellow = RGBAColor(253, 253, 150, 200);
RGBAColor Colors::PastleGreen = RGBAColor(119, 221, 119, 200);
RGBAColor Colors::PastleBrown = RGBAColor(181, 101, 29, 200);
RGBAColor Colors::PastleSky = RGBAColor(135, 206, 250, 200);
RGBAColor Colors::PastleBlue = RGBAColor(174, 198, 207, 200);
RGBAColor Colors::PastleCyan = RGBAColor(175, 238, 238, 200);
RGBAColor Colors::PastleWhite = RGBAColor(255, 255, 255, 200);
RGBAColor Colors::PastleOrange = RGBAColor(255, 179, 71, 200);
RGBAColor Colors::PastleTeal = RGBAColor(128, 216, 208, 200);
RGBAColor Colors::PastleGray = RGBAColor(200, 200, 200, 200);
RGBAColor Colors::PastleGrey = RGBAColor(200, 200, 200, 200);
RGBAColor Colors::PastleBlack = RGBAColor(50, 50, 50, 200);
RGBAColor Colors::PastleLightGray = RGBAColor(220, 220, 220, 200);
RGBAColor Colors::PastleLime = RGBAColor(204, 255, 144, 200);
RGBAColor Colors::PastleDarkGreen = RGBAColor(85, 107, 47, 200);
RGBAColor Colors::PastleForest = RGBAColor(144, 238, 144, 200);
RGBAColor Colors::PastleDesert = RGBAColor(237, 201, 175, 200);
RGBAColor Colors::PastleOcean = RGBAColor(135, 206, 250, 200);
RGBAColor Colors::PastleAutumnLeaves = RGBAColor(255, 160, 122, 200);

void GraphicsRenderer::drawRectangle(Rect2D rect)
{
    if (!rect.getVisible()) return;
    
    DrawRectanglePro(rect.raylibRec(), rect.getOrigin(), rect.getRotation(), rect.getColor());
}

void GraphicsRenderer::drawCircle(Vec2 center, float radius, RGBAColor color)
{
    DrawCircleV(center, radius, color);
}

void GraphicsRenderer::drawEllipse(Vec2 center, Vec2 size, RGBAColor color)
{
    DrawEllipse(center.x, center.y, size.x, size.y, color);
}

void GraphicsRenderer::drawCircleLines(Vec2 center, float radius, RGBAColor color)
{
    DrawCircleLinesV(center, radius, color);
}

void GraphicsRenderer::drawEllipseLines(Vec2 center, Vec2 size, RGBAColor color)
{
    DrawEllipseLines(center.x, center.y, size.x, size.y, color);
}

void GraphicsRenderer::drawLine(Vec2 start, Vec2 end, int thickness, RGBAColor color)
{
    DrawLineEx(start, end, thickness, color);
}

void GraphicsRenderer::drawPoint(Vec2 pos, RGBAColor color)
{
    drawCircle(pos, 1, color);    
}

void GraphicsRenderer::drawText(float x, float y, std::string text, int size, RGBAColor color)
{
    DrawText(text.c_str(), x, y, size, color);
}

void GraphicsRenderer::drawTexture(float x, float y, std::string id, Vec2 scale)
{
    if (!TextureService::textureExists(id)){
        DrawRectangle(x, y, 20, 20, RED);
        return;
    }

    Texture tex = *TextureService::getRTexture(id);

    float width = static_cast<float>(tex.width);
    float height = static_cast<float>(tex.height);

    DrawTexturePro(
        tex,
        Rectangle{0, 0, width, height},
        Rectangle{x, y, width * scale.x, height * scale.y},
        Vector2{0, 0}, 0, WHITE
    );
}

void GraphicsRenderer::drawSprite(Sprite2D sprite)
{
    if (!sprite.getVisible()) return;

    DrawTexturePro(
        *sprite.getTex(), sprite.getCutout().raylibRec(), sprite.getRect().raylibRec(),
        sprite.getOrigin(), sprite.getRotation(), WHITE
    );
}

void Obj2D::update()
{
    x += velocity.x;
    y += velocity.y;
}

void Obj2D::lookAt(Vec2 pos)
{
    float dx = pos.x - x;
    float dy = pos.y - y;
    float radians = std::atan2(dy, dx);
    rotation = radians * RAD2DEG;
}

void Obj2D::lookAt(float x, float y)
{
    lookAt(Vec2(x, y));
}

void Obj2D::step(float amount)
{
    float dx = cos(rotation * DEG2RAD) * amount;
    float dy = sin(rotation * DEG2RAD) * amount;

    x += dx;
    y += dy;
}

bool Obj2D::checkIntersection(Obj2D a, Obj2D b)
{
    if (!a.getCanCollide() || !b.getCanCollide()) return false;
    
    Rectangle rA = { a.getX(), a.getY(), a.getWidth(), a.getHeight() };
    Rectangle rB = { b.getX(), b.getY(), b.getWidth(), b.getHeight() };
    return CheckCollisionRecs(rA, rB);
}

bool Obj2D::checkIntersectionCircle(Obj2D a, Vec2 center, float radius)
{
    if (!a.getCanCollide()) return false;
    Rectangle rA = { a.getX(), a.getY(), a.getWidth(), a.getHeight() };
    return CheckCollisionCircleRec(center, radius, rA);
}

bool Obj2D::checkIntersectionCircles(Vec3 a, Vec3 b)
{
    return CheckCollisionCircles(Vector2{a.x, a.y}, a.z, Vector2{b.x, b.y}, b.z);
}

std::map<std::string, Texture> TextureService::textures = std::map<std::string, Texture>();


TextureResult TextureService::loadTexture(std::string path, std::string id)
{
    Texture tex = LoadTexture(path.c_str());

    if (tex.id == 0){
        LogService::error("Couldn't load texture `", path, "`.");
        return TextureResult::LoadFailed;
    }

    textures[id] = tex;
    LogService::info("Loaded texture `", path, "` with identifier `", id, "`.");
    return TextureResult::LoadSuccess;
}

bool TextureService::textureExists(std::string id)
{
    return textures.find(id) != textures.end();
}

void TextureService::unloadTexture(std::string id)
{
    if (!isLoaded(id)) return;

    UnloadTexture(textures[id]);
}

bool TextureService::isLoaded(std::string id)
{
    return textureExists(id) && textures[id].id != 0;
}

Texture* TextureService::getRTexture(std::string id)
{
    if (!textureExists(id)) return nullptr;
    return &textures[id];
}

void TextureService::unloadEverything()
{
    for (auto pair : textures){
        if (pair.second.id != 0) {
            UnloadTexture(pair.second);
            LogService::info("Unloaded texture with identifier `", pair.first, "`.");
        }
    }
}

void AnimatedSprite2D::updateAnimation()
{
    if (paused) return;

    if (lastFtime > 0.0f){
        lastFtime -= GetFrameTime();
        return;
    }

    lastFtime = 1.0f / fps;
    advance();
    setCutout(column * frameSize.x, row * frameSize.y, frameSize.x, frameSize.y);
}
