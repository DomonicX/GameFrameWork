#include "SDLGameObject.h"


SDLGameObject::SDLGameObject()
{
    m_colour = {255,255,255};
};


void SDLGameObject::Load(std::string FileName )

{
    {
        m_filename = FileName;
        std::ifstream ifs;
        ifs.open (FileName, std::ifstream::in);
//


//    if(ifs.fail() || ifs.bad())
//    if(ifs.good())
//        std::cout << "Good\n";

        ifs >> m_textureID;
        ifs >> m_isAnimated;
        ifs >> m_isbFilled;
        ifs >> m_isStaticSprite;
        ifs >> m_currentFrame;
        ifs >> m_frameRate;
        ifs >> m_numFrame;
        ifs >> m_srcRect.x;
        ifs >> m_srcRect.y;
        ifs >> m_srcRect.w;
        ifs >> m_srcRect.h;
        ifs >> m_position.x;
        ifs >> m_position.y;
        ifs >> m_velocity.x;
        ifs >> m_velocity.y;
        ifs >> m_force.x;
        ifs >> m_force.y;
        ifs >> m_acceleration.x;
        ifs >> m_acceleration.y;
        ifs >>m_lastPos.x;
        ifs >> m_lastPos.y;
        ifs >> m_mass;
        ifs >> m_gravity;
        ifs >> m_isDead;
        ifs >> m_isIgnoreCamera;
        ifs >> m_height;
        ifs >> m_width;
        ifs >> m_speed;
        ifs >> (int&)m_flip;
        ifs >> m_angle;

//        std::cout <<  m_textureID<< " ";
//        std::cout <<  m_isAnimated << " ";
//        std::cout <<  m_isbFilled  << " ";
//        std::cout <<  m_isStaticSprite<< " ";
//        std::cout <<  m_currentFrame<< " ";
//        std::cout <<  m_frameRate<< " ";
//        std::cout <<  m_numFrame<< " ";
//        std::cout <<  m_srcRect.x<< " ";
//        std::cout <<  m_srcRect.y<< " " ;
//        std::cout <<  m_srcRect.w<< " " ;
//        std::cout <<  m_srcRect.h<< " " ;
//        std::cout <<  m_position.x<< " " ;
//        std::cout <<  m_position.y<< " " ;
//        std::cout <<  m_velocity.x<< " " ;
//        std::cout <<  m_velocity.y<< " " ;
//        std::cout <<  m_force.x<< " " ;
//        std::cout <<  m_force.y<< " " ;
//        std::cout <<  m_acceleration.x<< " " ;
//        std::cout <<  m_acceleration.y<< " " ;
//        std::cout << m_lastPos.x<< " " ;
//        std::cout << m_lastPos.y<< " " ;
//        std::cout << m_mass<< " " ;
//        std::cout <<  m_gravity<< " " ;
//        std::cout <<  m_isDead<< " " ;
//        std::cout <<  m_isIgnoreCamera<< " " ;
//        std::cout << m_height<< " " ;
//        std::cout <<  m_width<< " " ;
//        std::cout <<  m_speed<< " " ;
//        std::cout <<  m_flip<< " " ;
//        std::cout <<  m_Rotation<< " \n done loading sdlgameobject \n"  ;

        ifs.close();
    }

    std::string temp = std::string("BluePrint_" + Type() + "/Base/.txt");

    std::ofstream ifs;
    ifs.open (temp, std::ofstream::out);

    ifs << "m_textureID      \n";
    ifs << "m_isAnimated  \n";
    ifs << "m_isbFilled       \n" ;
    ifs << "m_isStaticSprite   \n";
    ifs << "m_currentFrame      \n";
    ifs << "m_frameRate      \n";
    ifs << "m_numFrame         \n";
    ifs << "m_srcRect.x        \n";
    ifs << "m_srcRect.y     \n";
    ifs << "m_srcRect.w        \n";
    ifs << "m_srcRect.h       \n";
    ifs << "m_position.x   \n";
    ifs << "m_position.y       \n";
    ifs << "m_velocity.x       \n";
    ifs << "m_velocity.y        \n";
    ifs << "m_force.x           \n";
    ifs << "m_force.y          \n";
    ifs << "m_acceleration.x  \n";
    ifs << "m_acceleration.y    \n";
    ifs << "m_lastPos.x       \n";
    ifs << "m_lastPos.y        \n";
    ifs << "m_mass           \n";
    ifs << "m_gravity        \n";
    ifs << "m_isDead           \n";
    ifs << "m_isIgnoreCamera    \n";
    ifs << "m_height            \n";
    ifs << "m_width           \n";
    ifs << "m_speed          \n";
    ifs << "m_flip             \n";
    ifs << "m_angle          \n";


    ifs.close();

}
void SDLGameObject::Update() {};
void SDLGameObject::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{

    if(!isVisable() || Dead())
    {
 m_desRect = GetSDLRectF();
//    m_desRect.w = m_width * Application::Instance()->GetCamera().GetScaler();
//    m_desRect.h = m_height * Application::Instance()->GetCamera().GetScaler();
//
//
//
//m_desRect.h = 16* Application::Instance()->GetCamera().GetScaler();
//m_desRect.w = 16* Application::Instance()->GetCamera().GetScaler();
 m_desRect.x -= 3;
m_desRect.y -= 2;
vec2f desPos = vec2f(GetCentre().x,GetCentre().y);

SDL_Color c = {m_position.Length()+0%255,m_position.Length()+0%128,m_position.Length()+0%255};
//TextureManager::Instance()->DrawRectWithBoarder(SDL_FRect{m_desRect.x,m_desRect.y,m_desRect.w,m_desRect.h},c,Colour_aqua,4,Ren);

   }





} ;
void SDLGameObject::Clean() {};
void SDLGameObject::Collision() {} ;





std::string SDLGameObject::Type()
{
    return "SDLGameObject";
};









std::string SDLGameObject::Texture()
{
    return m_textureID;
};



void SDLGameObject::HandleEvent(SDL_Event& e ) {};


void SDLGameObject::updatePositionWithMouse()
{
    m_position = InputHandler::Instance()->GetMousePosition();
}
//void SDLGameObject::Update()
//{
////m_Data->ToString();
//
//}
//void SDLGameObject::Render()
//{
//    TextureManager::Instance()->DrawRectFilled(  m_srcRect,Colour_blue,App->GetRenderer());
//    TextureManager::Instance()->SetColour(255,255,255,255, App->GetRenderer());
//    TextureManager::Instance()->DrawRectFilled(  m_srcRect,Colour_chartreuse,App->GetRenderer());
//}
//
//void SDLGameObject::Clean()
//{
//
//}
//void SDLGameObject::Collision()
//{}
//std::string SDLGameObject::Type()
//{
//    return m_Type;
//}
//std::string SDLGameObject::Texture()
//{
//    return m_textureID;
//}
//void SDLGameObject::HandleEvent(SDL_Event& e )
//{
//    std::cout <<" created SDLGameObject\n";
//}
////    else if(!m_SDLData->m_isbFilled)
////    {
////        TextureManager::Instance()->DrawRectFilled(m_SDLData->m_desRect.x, m_SDLData->m_desRect.y, m_SDLData->m_desRect.w, m_SDLData->m_desRect.h, App->GetRenderer());
////    }
////    else if(m_SDLData->m_textureID=="TextBox")
////    {
////        TextureManager::Instance()->DrawRectFilled( m_SDLData->m_desRect.x, m_SDLData->m_desRect.y,m_SDLData->m_desRect.w, m_SDLData->m_desRect.h, App->GetRenderer());
////    }
////    if(m_SDLData->m_isStaticSprite)
////    {
////        TextureManager::Instance()->SDLDraw( App->GetRenderer(),Texture(),&m_SDLData->m_srcRect, &m_SDLData->m_desRect,0,0,SDL_FLIP_NONE);
////    }
////    else if(Dead())
////    {
////        TextureManager::Instance()->SDLDraw( App->GetRenderer(),Texture(),&m_SDLData->m_desRect, &m_SDLData->m_srcRect,0,0,SDL_FLIP_NONE);
////    }
//
//
//// TextureManager::Instance()->SetColour(0,0,0,255, App->GetRenderer());
//// TextureManager::Instance()->SetColour(0,0,255,255, App->GetRenderer());
//
//// TextureManager::Instance()->SetColour(0,0,255,255, App->GetRenderer());

//
//
//    ifs << "m_textureID       " << m_textureID<<        "\n";
//    ifs << "m_isAnimated      " << m_isAnimated<<       "\n";
//    ifs << "m_isbFilled       " << m_isbFilled<<        "\n";
//    ifs << "m_isStaticSprite  " << m_isStaticSprite<<   "\n";
//    ifs << "m_currentFrame    " << m_currentFrame<<     "\n";
//    ifs << "m_frameRate       " << m_frameRate<<        "\n";
//    ifs << "m_numFrame        " << m_numFrame<<         "\n";
//    ifs << "m_srcRect.x       " << m_srcRect.x<<        "\n";
//    ifs << "m_srcRect.y       " << m_srcRect.y<<        "\n";
//    ifs << "m_srcRect.w       " << m_srcRect.w<<        "\n";
//    ifs << "m_srcRect.h       " << m_srcRect.h<<        "\n";
//    ifs << "m_position.x      "<<  m_position.x<<       "\n";
//    ifs << "m_position.y      "<<  m_position.y<<       "\n";
//    ifs << "m_velocity.x      "<<  m_velocity.x<<       "\n";
//    ifs << "m_velocity.y      "<<  m_velocity.y<<       "\n";
//    ifs << "m_force.x         "<<  m_force.x<<          "\n";
//    ifs << "m_force.y         "<<  m_force.y<<          "\n";
//    ifs << "m_acceleration.x  "<<  m_acceleration.x<<   "\n";
//    ifs << "m_acceleration.y  "<<  m_acceleration.y<<   "\n";
//    ifs << "m_lastPos.x       "<< m_lastPos.x<<         "\n";
//    ifs << "m_lastPos.y       "<< m_lastPos.y<<         "\n";
//    ifs << "m_mass            "<< m_mass<<              "\n";
//    ifs << "m_gravity         "<<  m_gravity<<          "\n";
//    ifs << "m_isDead          "<<  m_isDead<<           "\n";
//    ifs << "m_isIgnoreCamera  "<<  m_isIgnoreCamera<<   "\n";
//    ifs << "m_height          "<< m_height<<            "\n";
//    ifs << "m_width           "<<  m_width<<            "\n";
//    ifs << "m_speed           "<<  m_speed<<            "\n";
//    ifs << "m_flip            "<<  m_flip<<             "\n";
//    ifs << "m_Rotation        "<<  m_Rotation<<          "\n";
//
