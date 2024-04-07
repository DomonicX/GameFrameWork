#include "GameObject_Tile.h"

GameObject_Tile::GameObject_Tile()
{
    m_textureID = "No TExture";
    //ctor
    m_height = 16;
    m_width = 16;
}

GameObject_Tile::~GameObject_Tile()
{
    //dtor
}
void GameObject_Tile::Collision() {};

void GameObject_Tile::Collision( GameObject* g)

{

    if(m_srcRect.x == 16 )
    {
        dynamic_cast<SDLGameObject*>(g)->GetColour() = Colour_green;

    }
    if(m_srcRect.x == 0 )
    {

        dynamic_cast<SDLGameObject*>(g)->GetColour() = Colour_blueviolet;
    }
    if(m_srcRect.x == 48 )
    {

        dynamic_cast<SDLGameObject*>(g)->GetColour() = Colour_rosybrown;
    }
    if(m_srcRect.x == 32 )
    {

        dynamic_cast<SDLGameObject*>(g)->GetColour() = Colour_gold;
    }
//(g)->GetPosition() =  dynamic_cast<SDLGameObject*>(g)->GetlastPosition();

//dynamic_cast<GameObject_Ball*>(g)->FlipYspeed();
//        dynamic_cast<GameObject_Ball*>(g)->FlipXspeed();

//        dynamic_cast<SDLGameObject*>(g)->GetAcceleration() *= -1;
}

void GameObject_Tile::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    if(!Dead())
    {
        if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
GetAngle()+=1;
            if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::RIGHT))
GetAngle()-=1;
            if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::MIDDLE))
    GetAngle()-=1;
    //GetAngle()+=1;

GetCenterOfMass() = SDL_FPoint({0,0});
        SDL_FRect des = {m_position.x+OffsetX,m_position.y+OffsetY,m_width* Application::Instance()->GetCamera().GetScaler(),m_height * Application::Instance()->GetCamera().GetScaler()};
        m_srcRect = {0,0,getWidth(),getHeight()};

        SDL_Rect cr = CAMRECT;
        if(des.x>cr.w || des.y>cr.h)
        {

            textureManager->DrawRect(Ren,des,Colour_darkgreen,true);
        }
        else
        {

//     textureManager->drawSprite( Texture(),des.x,des.y,m_width,m_height,Ren,SDL_FLIP_NONE);

        }
        textureManager->Draw(APP->GetRenderer(),Texture(),m_srcRect,des,m_angle,&GetCenterOfMass(),SDL_FLIP_NONE);
//
//            vec2f ds = vec2f(des.x,des.y);
//            vec2f dz = vec2f(des.w,des.h);
//        {
//            vec2f l_dX2 = vec2f(des.x+des.w/2,des.y+des.h/2);
//            vec2f l_dXy = vec2f(des.x,des.y);
//            vec2f l_dXX = vec2f(des.x+des.w,des.y);
//            vec2f l_Normalvec =l_dXX - l_dXy;
//
////     l_Normalvec.Normalise();
////     l_Normalvec*=16;be
//            l_Normalvec.Rotate(GetAngle());
//            l_Normalvec.Ortho();
//            l_Normalvec.Normalise();
//            l_Normalvec*=16;
//            TextureManager::Instance()->DrawVector(Ren,l_dX2,l_Normalvec,Colour_red);
//        }
  TextureManager::Instance()->DrawPoint(Ren,GetCentre(),Colour_black);
        }
};
