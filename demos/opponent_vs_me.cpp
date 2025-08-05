#include "iris/iris_window.h"
#include "iris/iris_input.h"
#include "iris/iris_audio.h"

// oppoennet and me
Rect2D opponent;
Rect2D me;

// powers
int power;
int oppenentPower;
int powerIncrement;

// timer
float timer;

Game game;

void init(){
    // set timer
    timer = 8.0f;

    // set powers
    oppenentPower = 1000; // customizable
    power = 20; // customizable
    powerIncrement = 30; // customizable, represents how much power is added per click

    // set oppoenent
    opponent = Rect2D(200, 100, 50, 50, Colors::Red);
    opponent.setOrigin(opponent.getSize() * ORIGIN_CENTER);

    // set me rect
    me = Rect2D(30, 100, 20, 20, Colors::Blue);
    me.setOrigin(me.getSize() * ORIGIN_CENTER);
}

void draw(){
    // draw both
    GraphicsRenderer::drawRectangle(opponent);
    GraphicsRenderer::drawRectangle(me);

    // draw power
    std::stringstream ss;
    ss << "Power: " << power;
    GraphicsRenderer::drawText(0, 0, ss.str(), 20, Colors::Black);

    std::stringstream ss2;
    ss2 << "Opponent power: " << oppenentPower;
    GraphicsRenderer::drawText(0, 24, ss2.str(), 20, Colors::Black);

    // draw win/lose
    if (Obj2D::checkIntersection(me, opponent)){
        GraphicsRenderer::drawText(100, 200, 
            (power > oppenentPower) ? "you won" : "you lose", 24, 
            (power > oppenentPower) ? Colors::Green : Colors::Red);
    }
}

void update(float dt){
    // update timer
    timer -= dt;

    // increase power when clicked and timer not finsihed
    if (Mouse::isButtonHit(Mouse::LeftButton) && timer >= 0.0f){
        power += powerIncrement;
    }

    // when timer finished, make me move forward

    if (timer < 0.0f){
        me.setVelocity(Vec2(50, 0));
    }

    // if intersecting, then stop moving

    if (Obj2D::checkIntersection(me, opponent)){
        me.setVelocity(Vec2(0, 0));
    }

    // update me

    me.update();
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
