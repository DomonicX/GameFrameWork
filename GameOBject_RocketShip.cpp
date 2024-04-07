#include <GameOBject_RocketShip.h>

GameOBject_RocketShip::GameOBject_RocketShip()
{
    m_velocity = vec2f(0,0);
    m_speed =1;
    m_acceleration = vec2f(m_speed,m_speed);

    m_height=   TextureManager::Instance()->getTextureMap()[Texture()]->GetWidth();
    m_width =  TextureManager::Instance()->getTextureMap()[Texture()]->GetHeight();
}
GameOBject_RocketShip::~GameOBject_RocketShip() {}

void GameOBject_RocketShip::Load(std::string FileName) {}
void GameOBject_RocketShip::Collision() {}
void GameOBject_RocketShip::HandleEvent(SDL_Event& e )
{
if(INPUTHANDLER->isKeyDown(SDL_SCANCODE_LEFT))
    {

m_angle++;
m_acceleration.Rotate(1);

}
    if(INPUTHANDLER->isKeyDown(SDL_SCANCODE_RIGHT))
    {

m_angle--;
m_acceleration.Rotate(-1);
    }
    if(INPUTHANDLER->isKeyDown(SDL_SCANCODE_UP))
    {
        m_acceleration = vec2f(0,-m_speed);
    }
}
//      m_velocity  *= m_speed;
void GameOBject_RocketShip::Update(float dt)
{
    m_lastPos = m_position;
    m_velocity += m_acceleration * APP->GetDeltaTime();
// m_velocity.Limit(4);
//       m_acceleration.Rotate(m_angle);
    m_position += m_velocity * APP->GetDeltaTime();

}
void GameOBject_RocketShip::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
//    SDL_FPoint sp = SDL_FPoint({TextureManager::Instance()->getTextureMap()[Texture()]->GetWidth()/2,
//                                TextureManager::Instance()->getTextureMap()[Texture()]->GetHeight()/2});

    m_desRect = {GetPosition().x - OffsetX ,GetPosition().y - OffsetY,getWidth(),getHeight()};
//    m_srcRect = {0,0,m_width,m_height};
//std::cout << m_position.vectorAngle(m_velocity.x,m_velocity.y) <<"\n";

//    SDL_RenderCopyExF(Ren,TextureManager::Instance()->getTextureMap()["Tile_wood"]->GetSDLTexture(),NULL,&m_desRect,m_angle+90,&sp,SDL_FLIP_NONE);
//   SDL_RenderCopyExF(Ren,TextureManager::Instance()->getTextureMap()["Tile_wood"]->GetSDLTexture(),&m_srcRect,&m_desRect,0,NULL,SDL_FLIP_NONE);
    TextureManager::Instance()->drawSprite(Texture(),m_desRect.x,m_desRect.y,m_desRect.w,m_desRect.h,Ren,SDL_FLIP_NONE);


//    TextureManager::Instance()->DrawVector(Ren,MOUSEPOSITION,WindowOrigin,Colour_blueviolet);

  //  TextureManager::Instance()->Drawcircle(Ren,m_position.x - OffsetX ,m_position.y - OffsetY,SDL_Colour{GetColour().r,GetColour().g,GetColour().b},16,true);
}
void GameOBject_RocketShip::Clean() {}
