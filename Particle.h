#ifndef PARTICLE_H
#define PARTICLE_H

#include <Vector2D.h>
#include <SDL2/SDL.h>
#include <TextureManager.h>
class Particle
{
    public:
        Particle();
        Particle(vec2f pos,vec2f vel, vec2f Acc) : m_Position(pos) ,m_Velocity(vel) ,m_Acceleration(Acc), spawnLoc(pos) {};
        virtual ~Particle();

    void Update(float DeltaTime);
    void Render(SDL_Renderer *Ren,std::string TextureID = "", float OffsetX = 0,float OffsetY = 0);
void SetDead(bool dead) {m_dead = dead;}
bool Dead(){return m_dead;}
void SetPosition(vec2f Position)             {m_Position = Position;}
void SetVelocity(vec2f Velocity)             {m_Velocity = Velocity;}
void SetSpeed(float Speed)                   {m_Speed = Speed;}
void SetMass(float Mass)                   {m_Mass = Mass;}
void SetAcceleration (vec2f Acceleration)    {m_Acceleration = Acceleration;}


vec2f GetPosition()                         {return m_Position;}
vec2f GetVelocity()                         {return m_Velocity;}
float GetSpeed()                            {return m_Speed;}
vec2f GetAcceleration ()                    {return m_Acceleration;}
    protected:

    private:
        float m_Lifevar = 10;
        float m_LifeSpan = m_Lifevar;
        bool m_dead = false;
        vec2f m_Position = vec2f();
        vec2f m_Velocity= vec2f();
        vec2f m_Acceleration = vec2f();
        float m_Speed = 0;
        float m_Mass = 0;
        float m_Force = 0;
        vec2f spawnLoc= vec2f();
};

#endif // PARTICLE_H
