#include "MarioEnemy.h"

IMarioEnemyState::IMarioEnemyState() {}
IMarioEnemyState::~IMarioEnemyState() {}
RedTurtle::RedTurtle() {}
RedTurtle::~RedTurtle() {}
GreenTurtle::GreenTurtle() {}
GreenTurtle::~GreenTurtle() {}
BlueTurtle::BlueTurtle() {}
BlueTurtle::~BlueTurtle() {}
Goomba::Goomba() {}
Goomba::~Goomba() {}
BlueGoomba::BlueGoomba() {}
BlueGoomba::~BlueGoomba() {}
GreyGoomba::GreyGoomba() {}
GreyGoomba::~GreyGoomba() {}
ManEatingPlant::ManEatingPlant() {}
ManEatingPlant::~ManEatingPlant() {}
GreyManEatingPlant::GreyManEatingPlant() {}
GreyManEatingPlant::~GreyManEatingPlant() {}
HammerThrowTurtle::HammerThrowTurtle() {}
HammerThrowTurtle::~HammerThrowTurtle() {}
GreyHammerThrowTurtle::GreyHammerThrowTurtle() {}
GreyHammerThrowTurtle::~GreyHammerThrowTurtle() {}
Browser::Browser() {}
Browser::~Browser() {}

MarioEnemy::MarioEnemy()
{
    //ctor
    m_mass = 10;
    m_gravity = 9.8;
    m_bisGrounded = false;
    m_acceleration = vec2f(0,0);

}
MarioEnemy::~MarioEnemy()
{
    //dtor
}
void MarioEnemy::SetEnemyState(std::string  enemyType)
{
    if(enemyType=="GreenTurtle")
        m_EmenyState =GREENTURTLE;
    else if(enemyType=="RedTurtle")
        m_EmenyState =REDTURTLE;
    else if(enemyType=="BlueTurtle")
        m_EmenyState =BLUETURTLE;
    else if(enemyType=="Goomba")
        m_EmenyState = GOOMBA;
    else if(enemyType=="BlueGoomba")
        m_EmenyState = BLUEGOOMBA;
    else if(enemyType=="GreyGoomba")
        m_EmenyState = GREYGOOMBA;
    else if(enemyType=="GreyManEatingPlant")
        m_EmenyState = GREYMANEATINGPLANT;
    else if(enemyType=="ManEatingPlant")
        m_EmenyState = MANEATINGPLANT;
    else if(enemyType=="HammerThrowTurtle")
        m_EmenyState = HAMMERTHROWTURTLE;
    else if(enemyType=="GreyHammerThrowTurtle")
        m_EmenyState = GREYHAMMERTHROWTURTLE;
    else if(enemyType=="Browser")
        m_EmenyState = BROWSER;

}
void MarioEnemy::Load(char* filename)
{
    // SDLGameObject::Load("asset/Mario/MarioBlock.txt");
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_bisFilled;
    ifs.close();

    m_Type = filename;

    std::string filenameStr  = filename;

    if(filenameStr=="GreenTurtle")
    {
        m_state = new GreenTurtle();
        m_srcRect = {0,0,16,32};
        m_desRect = {16,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="RedTurtle")
    {
        m_state = new RedTurtle();
        m_Type = "RedTurtle";
        m_srcRect = {0,0,16,32};
        m_desRect = {16,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="BlueTurtle")
    {
        m_state = new BlueTurtle();
        m_Type = "BlueTurtle";
        m_srcRect = {0,0,16,32};
        m_desRect = {16,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Goomba")
    {

        m_state = new Goomba();
        m_Type = "Goomba";
        m_srcRect = {0,0,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="BlueGoomba")
    {
        m_state = new BlueGoomba();
        m_Type = "BlueGoomba";
        m_srcRect = {0,0,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="GreyGoomba")
    {
        m_state = new GreyGoomba();
        m_Type = "GreyGoomba";
        m_srcRect = {0,0,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }

    else if(filenameStr=="GreyManEatingPlant")
    {
        m_state = new GreyManEatingPlant();
        m_Type = "GreyManEatingPlant";
        m_srcRect = {0,0,16,32};
        m_desRect = {32,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="ManEatingPlant")
    {
        m_state = new ManEatingPlant();
        m_Type = "ManEatingPlant";
        m_srcRect = {0,0,16,32};
        m_desRect = {32,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="HammerThrowTurtle")
    {
        m_state = new HammerThrowTurtle();
        m_Type = "HammerThrowTurtle";
        m_srcRect = {0,0,16,32};
        m_desRect = {32,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="GreyHammerThrowTurtle")
    {
        m_state = new GreyHammerThrowTurtle();
        m_Type = "GreyHammerThrowTurtle";
        m_srcRect = {0,0,16,32};
        m_desRect = {32,0,16,32};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Browser")
    {
        m_state = new Browser();
        m_Type = "Browser";
        m_srcRect = {0,0,16,32};
        m_desRect = {32,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
        SetEnemyState(filenameStr);


    m_width = getWidth();
    m_height = getHeight();
}

std::string MarioEnemy::Type()
{
    return m_state->getState();
}
void MarioEnemy::Update()
{
    float   dt = Application::Instance()->GetDeltaTime();
    // m_position.y++;

//    m_state->Update();

    //m_state->Draw();


    m_force.y  -= m_mass *  m_gravity * dt*2;
    m_velocity.y += m_force.y * dt*2;

    if(m_bisGrounded)
    {
        if(iSFacingRight())
        {
            m_acceleration.x = -18;
            //  m_velocity.x = 0;
        }
        else
        {

            // m_velocity.x = 0;
            m_acceleration.x = 18;
        }
    }
    else
    {
        m_acceleration.x = 0;
        m_position.y -= m_velocity.y* dt;
    }



    //
    m_velocity.x += m_acceleration.x * dt*2;
    m_position.x -= m_velocity.x* dt;

    m_frameRate = 300;
    m_numFrame = 2;
    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
                     );
    m_srcRect.x = m_currentFrame*16;
    // std::cout << m_currentFrame << "  ssssssssssssss "<<"\n";
    m_bisGrounded = false;
}
void MarioEnemy::Render()
{

    float x = Application::Instance()->GetCamera()->getpos().x;
    float y = Application::Instance()->GetCamera()->getpos().y;
    if(!isIgnoreCamera())
    {
        x = Application::Instance()->GetCamera()->getpos().x;
        y = Application::Instance()->GetCamera()->getpos().y;
    }
    else
    {
        x = 0;
        y = 0;
    }


    m_desRect = {m_position.x-x,m_position.y,GetState()->GetWidth(),GetState()->GetHeight()};

  //  TextureManager::Instance()->DrawBackGround(Texture(),App::Instance()->GetRenderer());
    TextureManager::Instance()->SDLDraw( Application::Instance()->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,SDL_FLIP_NONE);
    if(iSFacingRight())
        TextureManager::Instance()->DrawLine(m_desRect.x,m_desRect.y,m_desRect.x+46,m_desRect.y+m_desRect.h/2,Application::Instance()->GetRenderer());
    else
        TextureManager::Instance()->DrawLine(m_desRect.x,m_desRect.y,m_desRect.x-46,m_desRect.y+m_desRect.h/2,Application::Instance()->GetRenderer());


}

std::string MarioEnemy::Texture()
{
    return m_state->Texture();
}

int MarioEnemy::getWidth()
{
    return m_state->GetWidth();
}

int MarioEnemy::getHeight()
{
    return m_state->GetHeight();
}

void MarioEnemy::Turn()
{
    if(b_mFacingRight)
    {
        b_mFacingRight = false;
    }
    else b_mFacingRight = true;
}
bool MarioEnemy::iSFacingRight()
{
    return b_mFacingRight;
};


