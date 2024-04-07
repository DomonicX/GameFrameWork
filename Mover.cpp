#include "Mover.h"

Mover::Mover()
{

    location =  vec2f(0,0);
    velocity =  vec2f(0,0);
    acceleration =  vec2f(-0.0,0.01);
    topspeed = 10;
}

Mover::Mover(int width,int height)
{
    m_width = width;
    m_height = height;
    location =  vec2f(width/2,height/2);
    velocity =  vec2f(0,0);
    acceleration=  vec2f(-0.001,0.01);
    topspeed = 10;

}
Mover::~Mover()
{
    //dtor
}
void Mover::update()
{
    // Velocity change by acceleration and is limited by topspeed.
    velocity +=  acceleration;
    location += velocity;
}

void Mover::Display()
{

SDL_RenderDrawLine(Game::Instance()->GetRenderer(),location.x,location.y,velocity.x,velocity.y);
//Arrow::Draw2(location,velocity,White);
}
//Circle test
