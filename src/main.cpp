#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

Game game;

AnimatedSprite2D sprite;

void init(){
	// loads texture for sprites to use in identifier `lemon`
    TextureService::loadTexture("lemon.png", "lemon");

	// makes a animated sprite with the pos, frame size and the identifier of the texture to use	
    sprite = AnimatedSprite2D("lemon", Vec2(0, 0), Vec2(64, 64), 20);    

    // adds a animation row
    // you can also use set, get Row/Col to manually set row and col
    sprite.addAnimation("lemon ultra", 1, 2);

    // makes it loop
    sprite.setLoop(true);
}

void draw(){
	// draw non existent texture to test the checkerboard pattern
    GraphicsRenderer::drawTexture(20, 20, "hehehe");
}

void update(float dt){
	// changes animation when left button clicked
    if (Mouse::isButtonHit(Mouse::LeftButton)){
        sprite.selectAnimation("lemon ultra");
    }

    // updates animation
    sprite.updateAnimation();
}

void unload(){
// textures are auto unloaded.
// this area is used for audio unloading
}


int main(int argc, char const *argv[])
{	
	// sets game background to forest (darkish green)
    game.setBackgroundColor(Colors::Forest);

    // sets fps
    game.setFps(30);

    // starts game
    game.start(
        init,
        draw,
        update,
        unload
    );
    return 0;
}
