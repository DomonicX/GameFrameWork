#include "GameObject_PacManTile.h"

GameObject_PacManTile::GameObject_PacManTile()
{
    m_width = 8;
    m_height = 8;
    m_isVisable = true;
    TextureManager::Instance()->SetColorMod("PacManTileSet",Colour_black);
    //ctor
}

GameObject_PacManTile::~GameObject_PacManTile()
{
    //dtor
}

void GameObject_PacManTile::Load(std::string FileName) {
if(FileName=="Pellets")
{
m_type = "Pellets";
    m_width = 2;
    m_height = 2  ;

     m_colour = Colour_lightgreen;
}if(FileName=="PowerPellet")
{
m_type = "PowerPellet";

    m_width = 4;
    m_height = 4  ;

     m_colour = Colour_lavender;
}

}
void GameObject_PacManTile::Update(float dt)  //updatePositionWithMouse();
{
}
void GameObject_PacManTile::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
//    TextureManager::Instance()->SetAhpla("PacManTileSet",10);//
//    m_desRect.x = m_position.x+ Application::Instance()->GetCamera().GetPos().x;
//    m_desRect.y= m_position.y+ Application::Instance()->GetCamera().GetPos().y;
    if(!Dead())
    {

    m_desRect = GetSDLRectF();

    m_srcRect = {9,7,1,1};
    m_desRect.w = m_width * Application::Instance()->GetCamera().GetScaler();
    m_desRect.h = m_height * Application::Instance()->GetCamera().GetScaler();



//   TextureManager::Instance()->drawTextureText(App->GetRenderer(),"PacManTileSet",m_desRect,m_srcRect);
      //  TextureManager::Instance()->DrawRectFilled(m_desRect,m_colour,App->GetRenderer());

    }
}
void GameObject_PacManTile::Clean() {}
void GameObject_PacManTile::Collision() {}
void GameObject_PacManTile::HandleEvent(SDL_Event& e ) {}
