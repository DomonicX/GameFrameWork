#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H


#include <InputHandler.h>
#include <Lmaths.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>
#include <Lmaths.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Particle.h>
class ParticleEmitter
{

public:
    ParticleEmitter(vec2f pos, vec2f vel,vec2f acc, vec2f endPoint,float  Size = 0, SDL_Color c = Colour_darkkhaki,  float alpha=0,float shape=0,float lifetime=0, float drag=0, float VarSpeed =0,float fuzziDegree = 0,float emission= 0) ;
    ParticleEmitter();
    ~ParticleEmitter();
    vec2f m_pos, m_vel,m_acc,m_endPoint;
    float m_Size;
    SDL_Color m_c;
    float m_alpha;
    float m_shape;
    float m_lifetime;
    float m_drag;
    float m_VarSpeed;
    float m_MeanSpeed;
    float m_InitialSpeed = 0;
    vec2f m_spawnPos,m_spawnvel;
    float m_AliveCounter =0.0;
    float m_alphaCounter =255;
//    MeanSpeed;
float m_emission = 0;
    bool dead = false;
float m_fuzziDegree = 0;
public :
    void Update(float dt);
    void Add(Particle p){m_Particles.push_back(p);  m_Particles.back().SetPosition(m_Particles.back().GetPosition()+m_pos); m_Particles.back().SetMass(m_Size);}
    void render(SDL_Renderer* r, std::string textureID,vec2f Offset = vec2f(), float Alpha = 255,SDL_Color modColour = Colour_white);
private:

    std::vector<Particle>m_Particles;
};
#endif // PARTICLEEMITTER_H
