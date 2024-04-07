#include "GameObjectTree.h"

GameObjectTree::GameObjectTree()
{
    m_width = 70;
    m_height = 184;
    //ctor
    m_angle = 0;
}

GameObjectTree::~GameObjectTree()
{
    //dtor
}

void GameObjectTree::setTreeHeight(int treeheight)
{
    m_treeHeight = treeheight;
};
void GameObjectTree::Load(std::string FileName)
{
    std::ifstream ifs;
    ifs.open (FileName, std::ifstream::in);


    ifs >> m_filename;;


    ifs.close();

    SDLGameObject::Load(m_filename);

    {
        std::string temp = std::string("BluePrint_" + Type()  + ".txt");
        std::ofstream ifs;
        ifs.open (temp, std::ofstream::out);
        ifs << "m_parentFileName    \n" << m_filename <<          "\n";

        ifs.close();

//    if(ifs.fail() || ifs.bad())
//    if(ifs.good())
//        std::cout << "Good\n";
//FlipXspeed();
//FlipYspeed();

        //m_acceleration = vec2f(0,-16);
    }
    m_textureID = "tree3";
    m_isDead = false;

}
void GameObjectTree::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    if(!Dead())
    {
        TextureManager::Instance()->SetAhpla(m_textureID,255);
        SDL_Point sp = SDL_Point({getWidth()/2,
                                  getHeight()});
        TextureManager::Instance()->DrawRect(Ren,GetSDLRectF(),Colour_green);
//TextureManager::Instance()->drawSprite(m_textureID,m_position.x+OffsetX,m_position.y+OffsetY,70,184,Ren,SDL_FLIP_NONE);
        SDL_Rect dsre =  {m_position.x+OffsetX,m_position.y+OffsetY,getWidth(),getHeight()};
        SDL_Rect srsc = {m_srcRect.x,m_srcRect.y,getWidth(),getHeight()};
        TextureManager::Instance()->SDLDraw(APP->GetRenderer(),m_textureID,&srsc,&dsre,m_angle,&sp,SDL_FLIP_NONE);
//    TextureManager::Instance()->SetColorMod(m_textureID,Colour_white);
        if(m_startShaking)
        {

            m_LeavesFallingSystem.Render(Ren,"Bubble",OffsetX,OffsetY,255,Colour_white);
        }
    }
}
void GameObjectTree::Update(float dt)
{
    if(!Dead())
    {

        m_LeavesFallingSystem.Update(dt);
//    TextureManager::Instance()->SetColorMod(m_textureID,Colour_white);
        if(m_startShaking)
        {
            SDL_FRect Playerfrect = SDL_FRect
            {
                m_playerTarget->GetPosition().x,
                m_playerTarget->GetPosition().y,
                m_playerTarget->getWidth(),m_playerTarget->getHeight()};
            if(!InputHandler::Instance()->HasIntersection(Playerfrect,GetSDLRectF()))
            {
                m_lifeTime=255;
                m_startShaking = false;
                m_velocity = vec2f(0,0);
                m_angle = 0 ;
                m_srcRect.x = 0;

            }
            else
            {
                m_acceleration.x  = -9.81 /(float) 0.5 *(float) std::sin(m_angle);
                m_velocity.x+= m_acceleration.x * dt;
                m_angle  += m_velocity.x * dt;

                m_lifeTime-=vec2f::Lerp(vec2f(0,0),vec2f(255,0),dt ).x/(float)3;
                if(m_lifeTime<=0)
                {
                    SetDead(true);

                }
                std::cout <<  Application::Instance()->GetGameTime() << " m_angle \n";
            }
//        std::cout << vec2f::Lerp(vec2f(1,0),vec2f(255,0),dt )<< "\n";

        }
        if(m_lifeTime<=0)

        {
            m_srcRect.x = 0;
        }
        if(GetLifeTime()<=128)
        {
            m_srcRect.x = 70;
        }
        if(GetLifeTime()<=128/2.0)
        {
            m_srcRect.x = 70*2;
        }
    }
}
//m_startShaking = false;

//m_angle = MOUSEPOSITION.Length();


void GameObjectTree::Clean() {}

void GameObjectTree::Collision()
{
    if(!Dead())
    {

        if(!m_startShaking)
        {
            m_lifeTime = 255;

            m_srcRect.x = 0;
            m_angle = M_PI/4;
            m_LeavesFallingSystem.Clear();
//    TextureManager::Instance()->Load("Img/BackGround_256.png","BackGround_256",APP->GetRenderer());

            m_LeaveFallingEmitter =  ParticleEmitter(m_position,vec2f(0,0),vec2f(0,16),vec2f(0,0),100,Colour_green,255,0,255,0,200);
            for(int i = 0; i < 4; i++)
            {
                float xr = GetRandomNumber()%m_width;
                float yr = GetRandomNumber()%m_height/2;
                m_LeaveFallingEmitter.Add(Particle(vec2f(xr,yr),vec2f(0,i),vec2f(std::cos(i*M_PI/(float)180),std::sin(i*M_PI/(float)180))));
            }

            m_LeavesFallingSystem.Add(m_LeaveFallingEmitter);


        }
        if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
            m_startShaking = true;
        if(!InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
            m_startShaking = false;
//m_textureID = "tree4";
//m_textureID = "tree4";

//std::cout << m_position <<"collision" << "\n";
//    TextureManager::Instance()->SetColorMod(m_textureID,Colour_black);
    }
}


void GameObjectTree::HandleEvent(SDL_Event& e ) {}
