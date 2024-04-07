#include "TileLayer.h"

TileLayer::TileLayer()
{
    //ctor
}

TileLayer::~TileLayer()
{
    //dtor
}
void TileLayer::Update(float DeltaTime)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
        m_gameObjects[i]->Update(DeltaTime);
};
void TileLayer::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
        m_gameObjects[i]->Render(Ren,OffsetX,OffsetY);
//    TextureManager::Instance()->drawSprite("background",OffsetX - CAMRECT.x ,OffsetY - CAMRECT.y ,640,360,Ren,SDL_FLIP_NONE);
//        TextureManager::Instance()->DrawGrid(0,0,120,67.5,16,Colour_green,r);
};
void TileLayer::HandleEvent(SDL_Event &e )
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
        m_gameObjects[i]->HandleEvent(e);
}
