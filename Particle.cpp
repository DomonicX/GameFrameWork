#include "Particle.h"

Particle::Particle() : m_Position(0.0,0.0), m_Velocity(0.0,0.0), m_Acceleration(0.0,0.0), m_Speed(0) , m_dead(true)
{
    //ctor

}

Particle::~Particle()
{//std::cout  << "~Particle\n";
    //dtor
}

    void Particle::Update(float DeltaTime)
    {
        if(!Dead()){
        m_LifeSpan -= DeltaTime;

if(m_LifeSpan<=0)
{
m_dead = true;
    m_LifeSpan = m_Lifevar;
    //spawnLoc SetDead(true);
m_Position = spawnLoc;
m_Velocity = vec2f(0,0);
}
//      m_Force -= m_Acceleration.Length() * m_Mass *DeltaTime;
//m_Velocity += m_Acceleration * m_Force *DeltaTime;
//    m_Position += m_Velocity ;


//m_Velocity += m_Acceleration *m_Speed *  DeltaTime;
m_Velocity += m_Acceleration  *  DeltaTime;
//m_Velocity.Limit(4);
   m_Position += m_Velocity *  DeltaTime;
        }
}
    void Particle::Render(SDL_Renderer *Ren,std::string TextureID, float OffsetX,float OffsetY)
    {if(!Dead()){

    SDL_FRect temp = SDL_FRect{m_Position.x+OffsetX,m_Position.y+OffsetY,8,8};
    SDL_RenderFillRectF(Ren,&temp)  ;

//m_Mass = 64;
        SDL_FRect desrect = {m_Position.x+OffsetX,m_Position.y+OffsetY,m_Mass,m_Mass};
        if(m_Mass<16)
            m_Mass = 16;
        SDL_Rect srcrect = {0,0,m_Mass,m_Mass};
        TextureManager::Instance()->SDLDraw(Ren,   TextureID,
                                            &srcrect,
                                            &desrect,
                                            0,
                                            NULL,
                                            SDL_FLIP_NONE);
    }}
