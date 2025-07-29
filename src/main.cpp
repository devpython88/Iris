#include "iris/iris_window.h"
#include "iris/iris_input.h"

Rect2D rec;

void init(){
    // Create rectangle
    rec = Rect2D(20, 20, 50, 50, Colors::Desert);

    // Multiply size by a const value to get origin
    rec.setOrigin(rec.getSize() * ORIGIN_CENTER);

    // Load texture
    TextureService::loadTexture("build/apple.png", "apple");
}

void draw(){
    // Draw rect
    GraphicsRenderer::drawRectangle(rec);

    // Draw texture
    GraphicsRenderer::drawTexture(100, 100, "apple");
}

void update(float dt){
    // Make rect look towards the mouse
    rec.lookAt(Mouse::getPosition());

    // make rect step forward in the direction its facing
    rec.step(1);

    // Update movement
    rec.update();
}

void unload(){
}


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
