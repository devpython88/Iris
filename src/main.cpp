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
