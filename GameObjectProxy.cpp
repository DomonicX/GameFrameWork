#include "GameObjectProxy.h"

GameObjectProxy::GameObjectProxy()
{
    m_width = 16;
    m_height = 16;
    //ctor
}

GameObjectProxy::~GameObjectProxy()
{
    //dtor
}

void GameObjectProxy::Collision()
{
    SetDead(true);
}
void GameObjectProxy::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    if(!Dead())
    {

    SDL_FRect des = {m_position.x+OffsetX,m_position.y+OffsetY,m_width,m_height};
    SDL_Rect cr = CAMRECT;
    if(des.x>cr.w || des.y>cr.h)
    {

        textureManager->DrawRect(Ren,des,Colour_darkgreen,true);
    }
    else
        textureManager->drawSprite( Texture(),des.x,des.y,m_width,m_height,Ren,SDL_FLIP_NONE);

}
    }
