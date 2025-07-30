#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

Sprite2D sprite;
Game game;
SoundAudio sound;

void init(){
    TextureService::loadTexture("build/apple.png", "apple");
    sprite = Sprite2D("apple", 20, 20);
    sprite.setScale(5.0f, 5.0f);
    sprite.setOrigin(sprite.getScaledSize() * ORIGIN_CENTER);
    sprite.setFlip(false, true);

    sound = SoundAudio("build/pickupCoin.wav");
    sound.setLoop(true);
    sound.play();
}

void draw(){
    GraphicsRenderer::drawSprite(sprite);
}

void update(float dt){
    sprite.lookAt(Mouse::getPosition());
    sprite.step(100 * dt);
    sound.update();

    if (Mouse::isButtonHit(MOUSE_BUTTON_LEFT)){
        sound.setLoop(false);
    }
}

void unload(){
    sound.unload();
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
