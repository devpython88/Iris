#include "iris/iris_window.h"
#include "iris/iris_input.h"

Sprite2D sprite;
Game game;

void init(){
    TextureService::loadTexture("build/apple.png", "apple");
    sprite = Sprite2D("apple", 20, 20);
    sprite.setScale(5.0f, 5.0f);
    sprite.setOrigin(sprite.getScaledSize() * ORIGIN_CENTER);

    sprite.setFlip(false, true);
}

void draw(){
    GraphicsRenderer::drawSprite(sprite);
}

void update(float dt){
    sprite.lookAt(Mouse::getPosition());
    sprite.step(100 * dt);
}

void unload(){
}


int main(int argc, char const *argv[])
{
    game.setBackgroundColor(Colors::Forest);
    game.start(
        init,
        draw,
        update,
        unload
    );
    return 0;
}
