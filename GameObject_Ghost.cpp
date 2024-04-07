#include "GameObject_Ghost.h"

GameObject_Ghost::GameObject_Ghost()
{
    //ctor
    m_width = 16;
    m_height = 16;
    m_textureID = "PacManTileSet";
}

GameObject_Ghost::~GameObject_Ghost()
{
    //dtor
}

void  GameObject_Ghost::SetTarget(vec2f v)
{
   m_targetPos = v;
}
void GameObject_Ghost::Load(std::string FileName) {}
void GameObject_Ghost::Collision() {}
std::string GameObject_Ghost::Type()
{
    return "GameObject_Ghost";
}
std::string GameObject_Ghost::Texture() {return m_textureID;}
void GameObject_Ghost::HandleEvent(SDL_Event& e ) {}
void GameObject_Ghost::Update(float dt)
{
if(m_targetPos.Dist(m_position)>=16)
{ m_acceleration = m_targetPos-m_position;
m_acceleration.Normalise();
//m_acceleration*=m_targetPos.Dist(m_position);
//vec2f::Clamp(1,10,m_acceleration);
   m_velocity += m_acceleration * APP->GetDeltaTime();
m_position += m_velocity;
}
else m_velocity = vec2f(0,0);


}
void GameObject_Ghost::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    m_srcRect = {0,0,16,16};
m_desRect = {m_position.x,m_position.y,m_width,m_height};
//TextureManager::Instance()->drawTextureText(App->GetRenderer(),Texture(),m_desRect ,m_srcRect);
 TextureManager::Instance()->DrawRect(Ren,GetSDLRect(),Colour_aqua,true);
//      TextureManager::Instance()->DrawVector(m_position,m_targetPos,APP->GetRenderer());

}
void GameObject_Ghost::Clean() {}
