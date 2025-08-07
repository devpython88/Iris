#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

Game game;

AnimatedSprite2D sprite;

void init(){
    TextureService::loadTexture("lemon.png", "lemon");
    sprite = AnimatedSprite2D("lemon", Vec2(0, 0), Vec2(64, 64), 20);    
    sprite.addAnimation("lemon ultra", 1, 2);
    sprite.setLoop(true);
}

void draw(){
    GraphicsRenderer::drawSprite(sprite);
}

void update(float dt){
    if (Mouse::isButtonHit(Mouse::LeftButton)){
        sprite.selectAnimation("lemon ultra");
    }
    sprite.updateAnimation();
}

void unload(){
}


int main(int argc, char const *argv[])
{
    game.setBackgroundColor(Colors::Forest);
    game.setFps(30);
    game.start(
        init,
        draw,
        update,
        unload
    );
    return 0;
}
