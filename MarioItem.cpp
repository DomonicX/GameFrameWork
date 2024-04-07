#include "MarioItem.h"

MarioItem::MarioItem()
{
    //ctor
}

MarioItem::~MarioItem()
{
    //dtor
}
void MarioItem::Load(char* filename)
{

m_velocity= vec2f(0,0);
        m_force = vec2f(0,0);
        m_mass = 10;
m_gravity = 9.98;

    // SDLGameObject::Load("asset/Mario/MarioBlock.txt");
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_bisFilled;
    ifs.close();

    m_Type = filename;
    m_width = 16;
    m_height = 16;

    std::string filenameStr  = filename;
    if(filenameStr=="RedMushroom")
    {
        m_Type = "RedMushroom";
        m_Itemtype = RedMushroom;
        m_srcRect = {16*4,0,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="GreenMushroom")
    {
        m_Type = "GreenMushroom";
        m_Itemtype = GreenMushroom;
        m_srcRect = {16*4,0,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;

    }

    else if(filenameStr=="Coin")
    {
        m_Type = "Coin";
        m_Itemtype = Coin;
        m_srcRect = {0,16*2,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="FireFlower")
    {
        m_Type = "FireFlower";
        m_Itemtype = FireFlower;
        m_srcRect = {0,0,16,16};
        m_desRect = {0,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="StarPower")
    {
        m_Type = "StarPower";
        m_Itemtype = StarPower;
        m_srcRect = {1,11,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
}
void MarioItem::Update()
{
 float   dt = Application::Instance()->GetDeltaTime();
    // m_position.y++;

    if(m_Type=="GreenMushroom" || "RedMushroom" )
    {


    m_force.y  -= m_mass *  m_gravity * dt*2;
    m_velocity.y += m_force.y * dt*2;
//
//    m_velocity.x += m_acceleration.x * dt*2;
   m_position-= m_velocity* dt;

   // m_bisGrounded = false;
    }
//    m_desRect = GetSDLRect();
//    m_desRect.x  += m_position.x;
//    m_position.y += m_position.y;
}
void MarioItem::Draw()
{
    float x =App->GetCamera()->getpos().x;
    float y = App->GetCamera()->getpos().y;
if(!isIgnoreCamera())
{
    x = App->GetCamera()->getpos().x;
     y =App->GetCamera()->getpos().y;
}
else { x = 0; y = 0;}
    m_desRect = {m_position.x-x,m_position.y,getWidth(),getHeight()};

    //TextureManager::Instance()->DrawBackGround(Texture(),Game::Instance()->GetRenderer());
    TextureManager::Instance()->SDLDraw( App->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,SDL_FLIP_NONE);

}
void MarioItem::Clean() {}
void MarioItem::Collision() {}
