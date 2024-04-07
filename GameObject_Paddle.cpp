#include "GameObject_Paddle.h"

GameObject_Paddle::GameObject_Paddle()
{
    int tempW = WindowWidth;

    int tempH = WindowHeight*0.05;
    SetWidth(64);
    SetHeight(16);
    GetPosition() = vec2f(tempW-getWidth()/2,tempH-getHeight()/2);

    GetVelocity() = vec2f(0,0);
    GetMass() = 1;
    GetAcceleration() = vec2f(0,0);
    GetSpeed() = -10;
    //ctor
}

GameObject_Paddle::~GameObject_Paddle()
{
    //dtor
}
void GameObject_Paddle::Update(float dt)
{
    m_collisionFlag = false;
    GetPosition().x = Mouse.x-getWidth()/2 ;

    if(GetPosition().x <=0 )
        GetPosition().x = 0;
    else if(GetPosition().x  >= WindowWidth)
        GetPosition().x =  WindowWidth;



//    float dt = App->GetDeltaTime();
    //  m_speed = 100*App->GetDeltaTime();
    //  GetAcceleration() *= m_mass*m_speed;
    //  m_force = GetAcceleration()*m_mass;
    //  m_velocity = GetAcceleration() * App->GetDeltaTime();
//  GetAcceleration().x +=  m_speed * dt;
//    GetPosition() += m_velocity + GetAcceleration();
}

void GameObject_Paddle::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{

   SDL_Rect des = {m_position.x+Application::Instance()->GetCamera().GetPos().x,
     m_position.y+Application::Instance()->GetCamera().GetPos().y,m_width,m_height};
   // TextureManager::Instance()->DrawRectFilled(des,Colour_white,App->GetRenderer());

    //ctor
    // SDL_FRect tempRect = {GetPosition().x-App->GetCamera().m_pos.x,GetPosition().y-App->GetCamera().m_pos.y,getWidth(),getHeight()};

//    TextureManager::Instance()->DrawRectFilled(tempRect,Colour_blue,App->GetRenderer());
//    if(m_collisionFlag)
//    {
//
//    TextureManager::Instance()->DrawRectFilled(tempRect,Colour_navy,App->GetRenderer());
//
//    }
}

void  GameObject_Paddle::HandleEvent(SDL_Event& e )
{

    Mouse = vec2f(INPUTHANDLER->GetMousePosition());
    Mouse -=Application::Instance()->GetCamera().GetPos();

    if(INPUTHANDLER->isKeyDown(SDL_SCANCODE_A))
    {
        GetSpeed() *= -1;
    }


}
void GameObject_Paddle::Clean() {}
void GameObject_Paddle::Collision()
{
    CollisionManager::Instance()->AddCollision(this);
// m_collisionFlag = true;
}


std::string GameObject_Paddle::Type()
{
    return "BreakOut_Paddle";
}
std::string GameObject_Paddle::Texture() {}
