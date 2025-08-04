#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

Rect2D rectangle;
Game game;
ViewCamera camera;

void init(){
    rectangle = Rect2D(20, 20, 50, 50, Colors::Red);
    rectangle.setOrigin(rectangle.getSize() * ORIGIN_CENTER);
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
