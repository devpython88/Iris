#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

Game game;
Rect2D rec1;

void init(){
    rec1 = Rect2D(20, 20, 50, 50, Colors::Red);
}

void draw(){
    GraphicsRenderer::drawRectangle(rec1);
}

void update(float dt){
	rec1.resizeEx(0, 10 * dt, 0, 20 * dt);
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
