#include "iris/iris_window.h"
#include "iris/iris_input.h"

Rect2D rec;
std::vector<Vec2> lines;

void init(){
    rec = Rect2D(20, 20, 50, 50, Colors::Desert);
    rec.setOrigin(rec.getSize() * ORIGIN_CENTER);

    lines.push_back(Vec2(100, 100));
    lines.push_back(Vec2(150, 100));
    lines.push_back(Vec2(150, 130));
}

void draw(){
    GraphicsRenderer::drawRectangle(rec);
}

void update(float dt){
    rec.lookAt(Mouse::getPosition());
    rec.step(1);

    rec.update();
}

void unload(){}


int main(int argc, char const *argv[])
{
    Game game;
    game.setBackgroundColor(Colors::Forest);
    game.start(
        init,
        draw,
        update,
        unload
    );
    return 0;
}
