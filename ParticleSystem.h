#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <Particle.h>
#include <Vector2D.h>
#include <iostream>
#include <ParticleEmitter.h>

class ParticleSystem
{
public:
    ParticleSystem();
    ~ParticleSystem();
    void Update(float DeltaTime);
       void Render(SDL_Renderer *Ren = NULL,std::string texID = "", float OffSetX = 0,float OffSetY = 0,float Alpha = 255, SDL_Color ModColour = {255,255,255,255  });

    void Clear();
  void Add(ParticleEmitter emitter);
private :

     vec2f m_position;

protected:

private:
    std::vector<ParticleEmitter>m_emitters;
};

//
//class GridSystem : public ParticleSystem
//{
//public:
//    GridSystem(vec2f position,int  NumOfPartices) : ParticleSystem(position,NumOfPartices)
//    {
//std::cout << "sssssssssssss gr9d" << "\n";
//    };
//    ~GridSystem() {};
//private :
//
//protected:
//
//private:
//};

#endif // PARTICLESYSTEM_H
