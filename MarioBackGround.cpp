#include "MarioBackGround.h"

MarioBackGround::MarioBackGround()
{
    //ctor
}

MarioBackGround::~MarioBackGround()
{
    //dtor
}

void MarioBackGround::Load(char* filename)
{
    m_position = vec2f();
    std::string filenameStr  = filename;

    if(filenameStr=="Cloud")
    {
        m_Type = "Cloud";
        m_BackGroundType = MarioBackGroundType::CLOUD;

        m_width = 16*2;
        m_height = 16*2;

        m_srcRect = {14*16,3*16,m_width,m_height};
        m_desRect = {0,0,m_width,m_height};
    }
    if(filenameStr=="Hill")
    {
        m_width = 16*5;
        m_height = 16*3;
        m_Type = "Hill";
        m_BackGroundType = MarioBackGroundType::HILL;
        m_srcRect = {8*16,3*16,m_width,m_height};
        m_desRect = {0,0,m_width,m_height};
    }
    if(filenameStr=="Bush")
    {
        m_width = 16*3;
        m_height = 16*1;
        m_Type = "Bush";
        m_BackGroundType = MarioBackGroundType::BUSH;
        m_srcRect = {16*13,16*5,m_width,m_height};
        m_desRect = {0,0,m_width,m_height};
    }

}

void MarioBackGround::Render()
{
    float x = App->GetCamera()->getpos().x;
    float y = App->GetCamera()->getpos().y;
    if(!isIgnoreCamera())
    {
        x =App->GetCamera()->getpos().x;
        y = App->GetCamera()->getpos().y;
    }
    else
    {
        x = 0;
        y = 0;
    }
    if(!Dead())
    {
        m_desRect = {m_position.x - x,m_position.y - y,m_width,m_height};
        TextureManager::Instance()->SDLDraw( App->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,SDL_FLIP_NONE);


    }
}
void MarioBackGround::Update()

{
}
//
//
//        m_isAnimationSprite = true;
//        m_isStaticSprite  = false;
//        Ilde.AddSrect( 16, 3*16,16, 16 );
//        Ilde.AddSrect( 32, 3*16,16, 16 );
//        Ilde.AddSrect( 48, 3*16,16,16 );
//        //    Ilde.AddSrect( 64, 3*16,16,16 );
//        Ilde.maxFrame = 3;
//        Ilde.frameRate = 150;
//        Ilde.currentFrame = 0;

