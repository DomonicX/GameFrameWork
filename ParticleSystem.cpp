#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(){}

ParticleSystem::~ParticleSystem()
{//std::cout  << "~ParticleSystem\n";
    //dtor
}
void ParticleSystem::Clear(){

    for(int i = 0; i < m_emitters.size(); i++)
    {
//          delete m_emitters[i];
    m_emitters.erase(m_emitters.begin()+i);

    }
    m_emitters.clear();
}


    void ParticleSystem::Add(ParticleEmitter emitter)
    {
    m_emitters.push_back(emitter);

    }
void ParticleSystem::Update(float DeltaTime)
{
//    for(int i = 0; i < m_NumOfPartices ; i++ )
//    {
//          if(!s[i].Dead())
//    {
//        printf("sdsd");
//    }
//        s[i].Update(DeltaTime);
//    }
//    for(int i = 0; i < m_NumOfPartices ; i++ )
//    {
//        s[i].Update(DeltaTime);
//    }
    for(int i = 0; i < m_emitters.size() ; i++ )
        m_emitters[i].Update(DeltaTime);

}
void ParticleSystem::Render(SDL_Renderer *Ren,std::string texID , float OffSetX,float OffSetY,float Alpha, SDL_Color ModColour)
{
//     for(int i = 0; i < m_NumOfPartices ; i++ )
//        s[i].Render();

    for(int i = 0; i < m_emitters.size() ; i++ )
    {

        m_emitters[i].render(Ren,texID,vec2f(OffSetX,OffSetY),Alpha,ModColour);
    }

}


