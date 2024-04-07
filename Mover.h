#ifndef MOVER_H
#define MOVER_H
#include <iostream>
#include <Vector2D.h>
#include <Arrow.h>
#include <SDL2/SDL.h>
#include <Game.h>
class Mover
{
    public:
        Mover();
        Mover(int width,int height);
int m_width,m_height;
        virtual ~Mover();
       // Arrow m_Location;
 vec2f location;
  vec2f velocity;
  // Acceleration is the key!
  vec2f acceleration;
  // The variable, topspeed, will limit the magnitude of velocity.
  float topspeed;

void Display();
  void update();

    protected:

    private:
};

#endif // MOVER_H
