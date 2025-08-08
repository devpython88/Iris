#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

Game game;

void init(){
}

void draw(){
}

void update(float dt){
	
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
