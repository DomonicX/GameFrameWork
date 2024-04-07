#include "ParticleLayer.h"

ParticleLayer::ParticleLayer()
{
    //ctor
}

ParticleLayer::~ParticleLayer()
{
    //dtor
}
void ParticleLayer::Update(float DeltaTime)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
        m_gameObjects[i]->Update(DeltaTime);
};
void ParticleLayer::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
        m_gameObjects[i]->Render(Ren,CAMRECT.x,CAMRECT.y);
    TextureManager::Instance()->drawSprite("background",0,0,640,360,Ren,SDL_FLIP_NONE);
//        TextureManager::Instance()->DrawGrid(0,0,120,67.5,16,Colour_green,r);
};
void ParticleLayer::HandleEvent(SDL_Event &e )
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
        m_gameObjects[i]->HandleEvent(e);
}
