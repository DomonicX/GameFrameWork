#include "GameObject_PacmanWall.h"

GameObject_PacmanWall::GameObject_PacmanWall()
{
    //ctor
}

GameObject_PacmanWall::~GameObject_PacmanWall()
{
    //dtor
}

void  GameObject_PacmanWall::Update(float dt) {};
void  GameObject_PacmanWall::Clean() {};
void  GameObject_PacmanWall::Collision( GameObject* g) {};
void  GameObject_PacmanWall::Collision() {};
void  GameObject_PacmanWall::HandleEvent(SDL_Event& e ) {};
void GameObject_PacmanWall::Load(std::string FileName)
{

};
    void GameObject_PacmanWall::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
    {

GetCenterOfMass() = SDL_FPoint({0,0});
        SDL_FRect des = {m_position.x+OffsetX,m_position.y+OffsetY,m_width* Application::Instance()->GetCamera().GetScaler(),m_height * Application::Instance()->GetCamera().GetScaler()};
        m_srcRect = {0,0,8,8};

        SDL_Rect des2 = {m_position.x+OffsetX,m_position.y+OffsetY,m_width* Application::Instance()->GetCamera().GetScaler(),m_height * Application::Instance()->GetCamera().GetScaler()};
        SDL_Rect cr = CAMRECT;
        if(des.x>cr.w || des.y>cr.h)
        {

            textureManager->DrawRect(Ren,des,Colour_darkgreen,true);
        }
        else
        {
//std::vector<GameObject*>m_tiles;
//m_tiles.push_back(GameObjectFactory::Instance()->Create("GameObject_Tile"));
//
//for(int i = 0; i < m_tiles.size(); i++)
//{
////     GameObject_Tile
//    m_tiles[i]->Render(Ren,OffsetX,OffsetY);
//
//}
//     textureManager->drawSprite( Texture(),des.x,des.y,m_width,m_height,Ren,SDL_FLIP_NONE);

//if(!m_bNeighbour[0])
//if(!m_bNeighbour[1])
//if(!m_bNeighbour[2])
//if(m_bNeighbour[3])
        textureManager->Draw(APP->GetRenderer(),Texture(),m_srcRect,des,m_angle,&GetCenterOfMass(),SDL_FLIP_NONE);
//        TextureManager::Instance()->DrawTileBoxAroundRect(Ren,Texture(),6.63324958,des2,m_srcRect);
        }
//
    };

