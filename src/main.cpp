#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

AnimatedSprite2D sprite;
Game game;

void init(){
    TextureService::loadTexture("build/apple.png", "apple");
    sprite = AnimatedSprite2D("apple", Vec2(100, 100), Vec2(8, 8), 3);
    sprite.setScale(5.0f, 5.0f);
    sprite.setLoop(true);
    sprite.setOrigin(sprite.getScaledSize() * ORIGIN_CENTER);
    sprite.setFlip(false, true);
}

void draw(){
    GraphicsRenderer::drawSprite(sprite);
}

void update(float dt){
    sprite.lookAt(Mouse::getPosition());
    sprite.step(100 * dt);
    sprite.updateAnimation();
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
