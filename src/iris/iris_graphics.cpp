#include "iris_graphics.h"


float TextStyling::spacing = 1.0f;
float TextStyling::lineSpacing = 0.0f;
Vec4 TextStyling::padding = Vec4(2, 2, 2, 2);
std::unordered_map<std::string, Font> TextStyling::fonts = std::unordered_map<std::string, Font>();
std::string TextStyling::fontName = "default";

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

void GraphicsRenderer::drawRectangle(float x, float y, float w, float h, RGBAColor color)
{
    DrawRectangle(x, y, w, h, color);
}

void GraphicsRenderer::drawRectangle(Vec2 pos, Vec2 size, RGBAColor color, float rotation, Vec2 origin)
{
    DrawRectanglePro(
        Rectangle{pos.x, pos.y, size.x, size.y},
        origin, rotation, color
    );
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

void GraphicsRenderer::drawTextStyled(float x, float y, std::string text, int size, RGBAColor color)
{
    // Skip padding since no background

    auto font = TextStyling::getFont(TextStyling::getFontName());

    const Font& value = font.has_value() ? font.value() : GetFontDefault();

    DrawTextEx(
        value,
        text.c_str(), Vector2{x, y}, size, TextStyling::getSpacing(), color
    );
}

// srry i used chatgpt for this one 
void GraphicsRenderer::drawTextStyledBG(Vec2 pos, std::string text, int size, RGBAColor fg, RGBAColor bg)
{
    // Get font
    auto fontOpt = TextStyling::getFont(TextStyling::getFontName());
    const Font& font = fontOpt ? fontOpt->get() : GetFontDefault();
    
    const Vec4& padding = TextStyling::getPadding();

    // Measure text size
    Vector2 textSizeR = MeasureTextEx(font, text.c_str(), size, TextStyling::getSpacing());
    float textWidth = textSizeR.x;
    float textHeight = textSizeR.y;

    // Calculate background size with padding
    Vec2 bgSize{
        textWidth + padding.x + padding.z,
        textHeight + padding.y + padding.w
    };

    // Draw background rectangle
    DrawRectangleRec(Rectangle{pos.x, pos.y, bgSize.x, bgSize.y}, bg);

    // Calculate actual text position inside padded area
    Vec2 textPos{
        pos.x + padding.x,
        pos.y + padding.y
    };


    // Draw the text using proper position
    DrawTextEx(
        font,
        text.c_str(),
        Vector2{textPos.x, textPos.y},
        static_cast<float>(size),
        TextStyling::getSpacing(),
        fg
    );
}


void GraphicsRenderer::drawTexture(float x, float y, std::string id, Vec2 scale)
{
    if (!TextureService::textureExists(id)){
        DrawRectangle(x, y, 30, 30, PURPLE);
        DrawRectangle(x + 30, y, 30, 30, BLACK);
        DrawRectangle(x + 30, y + 30, 30, 30, PURPLE);
        DrawRectangle(x, y + 30, 30, 30, BLACK);
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

void Obj2D::update(bool frameIndependent)
{
    float mul = (frameIndependent ? GetFrameTime() : 1.0f);
    x += velocity.x * mul;
    y += velocity.y * mul;

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

    velocity.x = dx;
    velocity.y = dy;
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

void Obj2D::moveTowards(float tx, float ty, float speed)
{
    float mx = 0.0f, my = 0.0f;

    if (x <= tx) mx = speed;
    if (x >= tx) mx = -speed;
    if (y <= ty) my = speed;
    if (y >= ty) my = -speed;

    if (!MathUtils::isZero(mx)) velocity.x = mx;
    if (!MathUtils::isZero(my)) velocity.y = my;
}

void Obj2D::moveTowards(Vec2 target, float speed)
{
    moveTowards(target.x, target.y, speed);
}

std::unordered_map<std::string, Texture> TextureService::textures = std::unordered_map<std::string, Texture>();


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

void AnimatedSprite2D::addAnimation(const std::string &identifier, int row_, int col_)
{
    if (!hasAnimation(identifier)){
        RowCol rowcol{row_, col_};
        animations[identifier] = rowcol;
    }
}

void AnimatedSprite2D::removeAnimation(const std::string &identifier)
{
    if (hasAnimation(identifier)){
        animations.erase(identifier);
    }
}

bool AnimatedSprite2D::hasAnimation(const std::string &identifier)
{
    return animations.find(identifier) != animations.end();
}

void AnimatedSprite2D::selectAnimation(const std::string & identifier)
{
    if (hasAnimation(identifier)){
        auto anim = animations[identifier];

        row = anim.row;
        column = anim.col;
    }
}

void TextStyling::loadFont(std::string id, std::string path)
{
    if (fontExists(id)) return;

    Font font = LoadFont(path.c_str());
    fonts[id] = font;
}

void TextStyling::unloadFont(std::string id)
{
    if (fontExists(id)){
        if (IsFontValid(fonts[id])) UnloadFont(fonts[id]);
    }
}

void RGBAColor::brighten(float value)
{
    r = r + value > 255 ? 255 : r + value;
    g = g + value > 255 ? 255 : g + value;
    b = b + value > 255 ? 255 : b + value;
}

void RGBAColor::darken(float value)
{
    r = r - value > 0 ? 0 : r - value;
    g = g - value > 0 ? 0 : g - value;
    b = b - value > 0 ? 0 : b - value;
}
