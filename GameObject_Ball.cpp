#include "GameObject_Ball.h"

GameObject_Ball::GameObject_Ball() {};
GameObject_Ball::~GameObject_Ball()
{
};
void GameObject_Ball::Update(float dt)
{

//m_colour = Colour_blue;
    GetlastPosition() = GetPosition();

    if(m_clicked_D)
    {
        m_acceleration.Rotate(m_angle * dt);
        m_velocity.Rotate(m_angle * dt);
    }
    if(m_clicked_A)
    {
        m_acceleration.Rotate(-m_angle * dt);
        m_velocity.Rotate(-m_angle * dt);
    }

//    vec2f mp = INPUTHANDLER->GetMousePosition();
//need to fix i think its not frame independent
//need to do animation step using sdluser event in widgets
//std::cout << APP->GetFps() *  APP->GetDeltaTime()<< "\n";

    m_velocity += m_acceleration *(float) dt;
//    m_position
//m_velocity.Rotate(dt);


   m_velocity.Truncate(128);



    m_position += m_velocity*(float) dt;

    if(GetPosition().x+ getWidth()> CAMRECT.w )
    {
        GetPosition().x= CAMRECT.w-getWidth();
       FlipXspeed();
    }
    if(GetPosition().x < 0)

        FlipXspeed();

         if(GetPosition().y+ getHeight() > CAMRECT.h )
    {
        GetPosition().y= CAMRECT.h- getHeight();
       FlipYspeed();
    }
    if(GetPosition().y < 0)

        FlipYspeed();

}

//updatePositionWithMouse();

//    GetlastPosition() = GetPosition();
//
//    m_velocity += m_acceleration *  APP->GetDeltaTime()*2;
////    m_velocity.Limit(APP->GetFps());
//    m_velocity.Limit(10);
////if(m_velocity.Length()==(WindowWidth*0.1))
////{
////
////std::cout  <<"Fps" << APP->GetGameTime() <<"\n";
////
////}else
////
////std::cout  <<"Fps" << APP->GetFps()  <<" DeltaTime " << APP->GetDeltaTime()  << " WindowWidth*0.1 " << WindowWidth*0.01<< "\n";
//    m_position += m_velocity *  APP->GetDeltaTime();


void GameObject_Ball::Load(std::string FileName)
{


//std::cout << "load \n";
//    TextureManager::Instance()->Load("Img/BackGround_256.png","BackGround_256",APP->GetRenderer());
    {
        std::ifstream ifs;
        ifs.open (FileName, std::ifstream::in);


        ifs >> m_filename;
        ifs >> speedX;
        ifs >> speedY;
        ifs >> wallHitCounter;
//        std::cout << m_filename<< "  filename\n";
//        std::cout << speedX<< "  speedx\n";
//        std::cout << speedY<< "  speedy\n";
//        std::cout<< wallHitCounter<< "  wallhitcounter\n";


        ifs.close();
    }
    SDLGameObject::Load(m_filename);

    {
        std::string temp = std::string("BluePrint_" + Type()  + ".txt");
        std::ofstream ifs;
        ifs.open (temp, std::ofstream::out);
        ifs << "m_parentFileName    \n" << m_filename <<          "\n";
        ifs << "speedX              \n" << speedX<<               "\n";
        ifs << "speedY              \n" << speedY<<               "\n";
        ifs << "wallHitCounter      \n" << wallHitCounter<<       "\n";

        ifs.close();

//    if(ifs.fail() || ifs.bad())
//    if(ifs.good())
//        std::cout << "Good\n";
//FlipXspeed();
//FlipYspeed();

        //m_acceleration = vec2f(0,-16);
    }
    m_textureID = "BackGround_256";
    m_width = m_mass*2;
    m_height = m_mass*2;
    SetIgnoreCamera(true);
 m_width *= Application::Instance()->GetCamera().GetScaler();
 m_height *= Application::Instance()->GetCamera().GetScaler();
m_colour = Colour_black;
}
void GameObject_Ball::Clean() {}
void GameObject_Ball::Collision()
{
//m_velocity*=2;
//    FlipYspeed();
//FlipXspeed();
//
//    m_bCollision = true;
//    //m_lastPos =  GetlastPosition();
//   // std::cout << Type() <<" - Collision\n";
// SetDead(true);
////FlipYspeed();
////FlipXspeed();
//if(m_colour.g!=255)
//m_colour = Colour_green;
//else
//
//m_colour = Colour_red;

}

    void GameObject_Ball::Collision( GameObject* g)
    {
        //SetDead(true);
//
//if(dynamic_cast<SDLGameObject*>(g)->GetSDLRect().x == 0 && g->Type() != "BreakOut_Ball")
//{
//     m_colour = Colour_honeydew;
//
//}
//if(dynamic_cast<SDLGameObject*>(g)->GetSDLRect().x == 16 && g->Type() != "BreakOut_Ball")
//{
//     m_colour = Colour_bisque;
//
//}
//if(dynamic_cast<SDLGameObject*>(g)->GetSDLRect().x == 32 && g->Type() != "BreakOut_Ball")
//{
//      m_colour = Colour_antiquewhite;
//
//}
//if(dynamic_cast<SDLGameObject*>(g)->GetSDLRect().x == 48 && g->Type() != "BreakOut_Ball")
//{
//      m_colour = Colour_blue;
//
//}
//m_acceleration
//m_colour = Colour_red;


//      vec2f vel,vel1;
//      vec2f pos,pos1;
//       vel = m_velocity;
//       vel1 = dynamic_cast<SDLGameObject*>(g)->GetVelocity();
//float dotp = vec2f::Dot(GetVelocity().GetNormalise(),dynamic_cast<SDLGameObject*>(g)->GetVelocity().GetNormalise());
//if(dotp>0)
//{
//
//dynamic_cast<SDLGameObject*>(g)->GetVelocity()=-vel;
//m_velocity = vel1.GetOrtho();
//
//}else
//{
//
//dynamic_cast<SDLGameObject*>(g)->GetVelocity()=vel.GetOrtho();
//m_velocity = -vel1;
//}
////pos =GetPosition();
////pos1 =g->GetPosition();
////    GetPosition().x = pos1.x;
////    GetPosition().y = pos1.y;
////    g->GetPosition().y = pos.y;
////    g->GetPosition().x = pos.x;
//std::cout << dotp << "\n ";
    };

void GameObject_Ball::HandleEvent(SDL_Event& e )
{
    if(INPUTHANDLER->isKeyDown(SDL_SCANCODE_A))
{
//m_angle+=M_PI/(float)180;
        m_clicked_A = true;

}
    if(!INPUTHANDLER->isKeyDown(SDL_SCANCODE_A))
{
        m_clicked_A = false;

}
    if(INPUTHANDLER->isKeyDown(SDL_SCANCODE_D))
{
        m_clicked_D = true;
//m_angle-=M_PI/(float)180;

}

    if(!INPUTHANDLER->isKeyDown(SDL_SCANCODE_D))
{
        m_clicked_D = false;

}


}
void GameObject_Ball::FlipYspeed()
{
    m_acceleration.y *= -1;
    m_velocity.y  *= -1;
    // speedX *=-1;
}
void GameObject_Ball::FlipXspeed()
{
    m_acceleration.x *= -1;
    m_velocity.x  *= -1;
}
void GameObject_Ball::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    if(!Dead())
    {


    vec2f centre =  vec2f::GetMidPoint(m_position,vec2f(m_width,m_height)+m_position);
    SDL_FRect des =GetSDLRectF();
    SDL_Rect srcRect ={0,0,m_width,m_height};
    //TextureManager::Instance()->DrawRect(APP->GetRenderer(),SDL_FRect({des.x+OffsetX,des.y+OffsetY,m_mass*2,m_mass*2}),Colour_black,true);
    if(!m_isIgnoreCamera)
des.x+=OffsetX;des.y+=OffsetY;
//std::cout << des.w << "\n";
//SDL_Color ss = {255/m_mass,255/m_mass,255/m_mass};
//
//if(InputHandler::Instance()->HasIntersection(SDL_Rect({m_position.x+OffsetX-m_width/2,m_position.y+OffsetY-m_height/2,m_width*2,m_height*2}),Application::Instance()->GetCamera().GetRect()) && !Dead())
//   {

       TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),des,m_colour,true);
//
       //TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),des,Colour_black,true);
for(int i = 0 ; i < 9; i++ )
       TextureManager::Instance()->DrawPoint(Ren,GetRectHitPoint(i,des).x,GetRectHitPoint(i,des).y,Colour_white);
   // TextureManager::Instance()->Drawcircle(APP->GetRenderer(),m_position.x+OffsetX,m_position.y+OffsetY,Colour_black,m_mass,true);
//    vec2f a,b;
//    a = vec2f(m_position.x+OffsetX,m_position.y+OffsetY);
//    b = vec2f(m_velocity.x+OffsetX,m_velocity.y+OffsetY)*m_mass;
  //  TextureManager::Instance()->DrawVector(APP->GetRenderer(),a,-b,Colour_white);
//SDL_Rect srcRect = {m_srcRect.x,m_srcRect.y,m_width,m_height};
   //    TextureManager::Instance()->Draw(APP->GetRenderer(),Texture(),srcRect,des,0,NULL,SDL_FLIP_NONE);


//}
    }

}
int GameObject_Ball::GetWallHitCounter()
{
    return wallHitCounter;
}
/*

     GetVelocity().x *= -1;
    speedX *= -1;//    float dis = m_position.Dist(m_velocity);

    vec2f dis2 = m_velocity ;
    dis2.Normalise();
    dis2*=m_mass*2;

    dis2+=m_position;
    SDL_Rect des = {m_position.x, m_position.y,m_width,m_height};

    SDL_Rect srcRect = {0,0,m_mass,m_mass};
    TextureManager::Instance()->Draw(App->GetRenderer(),"BreakOutBall",des.x,des.y,&srcRect,0,NULL,SDL_FLIP_NONE);

 vec2f mp = inputHandler->GetMousePosition();

    vec2f v = GetVelocity();
    vec2f p = GetPosition();


    float dis = mp.Dist(p);

    p.Normalise();

    p*=dis*0.1;
GetPosition() +=  p ;



    GetlastPosition() = GetPosition();
    m_acceleration += vec2f(1,-1);

    m_velocity += m_acceleration * App->GetDeltaTime();
    m_velocity.Limit(32);
    m_position += m_velocity.GetNormalise().GetRoatate(m_acceleration.GetNormalise().x);

/
    GetPosition().x+=getWidth()/2;
    GetPosition().y+=getHeight()/2;
    m_Rotation += App->GetDeltaTime()*15;
    vec2f centreOfScreen = vec2f(App->GetWindowWidth()/2,App->GetWindowHeight()/2);
    SDL_Point dis = { (centreOfScreen.x -GetPosition().x),
                      (centreOfScreen.y- GetPosition().y)
                    } ;

    vec2f rDis = centreOfScreen-GetPosition();
    vec2f rDisN = rDis;
    rDisN.Normalise();
    rDisN.Roatate(m_Rotation);
    rDisN *= rDis.Length();
    rDisN += centreOfScreen;

TextureManager::Instance()->DrawLine(rDisN,centreOfScreen,App->GetRenderer());
    SDL_Rect l_clip = {m_srcRect.x,m_srcRect.y,m_srcRect.w,m_srcRect.h};
    vec2f l_pos = vec2f(m_position - m_velocity);

  vec2f  o =Application::Instance()->GetOrigin();
  vec2f po = o+l_pos;
  po.Normalise();
  po.Roatate(40);
  po*= m_velocity.Length();
  po.Roatate(ga);

   po += o;

    TextureManager::Instance()->DrawLine(po.x,po.y,o.x,o.y,Colour_red,App->GetRenderer());
    TextureManager::Instance()->DrawLine(m_position.x,m_position.y,l_pos.x+m_position.x,l_pos.y+m_position.y,Colour_red,App->GetRenderer());

    if(!Dead())
        TextureManager::Instance()->Draw(App->GetRenderer(),
                                        m_textureID,
                                         rDisN.x,
                                         rDisN.y,
                                         &l_clip,m_Rotation,0,m_flip);

    GetPosition().x-=getWidth()/2;
    GetPosition().y-=getHeight()/2;

    SDL_Rect DesRect = {GetPosition().x,GetPosition().y,getWidth(),getHeight()};
     TextureManager::Instance()->DrawRectFilled(DesRect,App->GetRenderer());

    vec2f screenSize = vec2f(App->GetWindowWidth(),App->GetWindowHeight());
    GetlastPosition() = GetPosition();
    float dt = App->GetDeltaTime();
    GetAcceleration() += m_mass * m_gravity
    GetAcceleration() = vec2f(speedX,speedY);
    GetVelocity() += GetAcceleration()* dt;
     GetVelocity().GetNormalise();
GetVelocity().Limit(600);

        vec2f screenSize1 = -vec2f(App->GetWindowWidth(),App->GetWindowHeight());


 screenSize1.x <<
  "  "<<
   screenSize.x   <<
     "\n"  ;else

 vec2f Pos = m_position.GetNormalise();
 vec2f vel = -Pos;

 m_position =  GetlastPosition();
 if(  vec2f::Dot(-Pos,-vel)!=0)
 {
   m_velocity.Roatate(vec2f::Dot(Pos,vel));
std::cout << "Created dot y "  << vec2f::Dot(Pos,vel)<< "\n";

std::cout << "Created GameObject_Ball y "  << m_position.y<< "\n";
std::cout << "Created GameObject_Ball x " << m_position.x<< "\n";


 }

  Pos.Normalise();
  Pos.Roatate(-90);

 GetPosition().x-=1;

 FlipXspeed();


 if(m_position.Dist(screenSize/2)> screenSize.x)
     GetPosition() = screenSize/2;
 if(m_position.Dist(vec2f(0,0))screenSize.x)
     GetPosition() = screenSize/2;
    GetPosition() += GetVelocity().GetNormalise();



        {m_velocity.y *= -1; speedY *=-1;}

    m_mass+=dt;
if(   GetPosition().y>= screenSize.y)
    {
        m_flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
        m_flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;
        wallHitCounter++;
        FlipYspeed();

        SoundManager::Instance()->SetPlay("Sfx_BreakOut_WallHitTop");

    }
    else if(  GetPosition().x >=  screenSize.x)
    {
        m_flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;
        wallHitCounter++;
        FlipXspeed();
        SoundManager::Instance()->SetPlay("Sfx_BreakOut_WallHitTop");
    }
    else if(   GetPosition() .y<= 0)
    {
        m_flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;
        m_flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
        wallHitCounter++;
        FlipYspeed();
        SoundManager::Instance()->SetPlay("Sfx_BreakOut_WallHitTop");
    }
    else if(  GetPosition() .x <= 0)
    {

        m_flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;
        m_flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
        wallHitCounter++;
        FlipXspeed();
        SoundManager::Instance()->SetPlay("Sfx_BreakOut_WallHitTop");
    }

     if(m_position.x-m_mass <= 0) {m_velocity.x *= -1; speedY *=-1;}


    {

           std::cout << "Created GameObject_Ball\n";
    }
vec2f xx =  m_lastPos;
vec2f xxx = m_position;
float a = 0;
xx.Normalise();
xxx.Normalise();

a = vec2f::Dot(xx,xxx);

    TextureManager::Instance()->SetColour(0,45,0,255, App->GetRenderer());
    TextureManager::Instance()->SetColour(0,0,255,255, App->GetRenderer());





   m_position =screenSize;


    GetPosition() = screenSize;
    GetVelocity() = vec2f(0,0);
    GetAcceleration() = vec2f(0,0);
    GetForce() = vec2f(0,0);
    GetSpeed( ) = 1;

    ctor
    GetForce();
    getHeight();
    getWidth();
    GetlastPosition();
    SetToIgnoreCamera(false) ;


    GetGravity() = 9.81;
    m_bDead = false;
    speedX = 200;
    speedY = 200;
    speedY = wallHitCounter = 0;

  m_position.y += m_speed * dt;



    TextureManager::Instance()->DrawLine(   m_lastPos.x,m_lastPos.y,
                                            GetPosition().x,GetPosition().y,
                                            App->GetRenderer());
    TextureManager::Instance()->DrawLine(GetPosition().x,GetPosition().y,m_lastPos.x,m_lastPos.y,App->GetRenderer());


   TextureManager::Instance()->DrawLine(
                                            App->GetWindowWidth()/2,
                                            App->GetWindowHeight()/2,0,0,
                                            App->GetRenderer());


TextureManager::Instance()->DrawLine(0,
                                    0,
                                     GetPosition().x,GetPosition().y,
                                     App->GetRenderer());

TextureManager::Instance()->DrawLine(0,
                                    0,
                                     InputHandler::Instance()->GetMousePosition().x,
                                     InputHandler::Instance()->GetMousePosition().y,
                                     App->GetRenderer());

  GetSpeed() = 100*App->GetDeltaTime();
  GetAcceleration() *= m_mass*GetSpeed();
  m_force = GetAcceleration()*m_mass;

        GetVelocity().x += GetSpeed()*dt;
            GetVelocity().y += GetSpeed() *dt;
    GetVelocity().Limit(25);
GetPosition() += GetVelocity();

GetVelocity().Normalise();
    vec2f mouse = vec2f(InputHandler::Instance()->GetMousePosition().x,InputHandler::Instance()->GetMousePosition().y);

GetVelocity().Roatate(90);
    GetVelocity() += GetPosition().GetNormalise();
    float d = GetPosition().Dist(mouse);
     std::cout << d << "\n";
    GetPosition() += GetVelocity().GetNormalise() * GetSpeed();
     m_force += m_mass*dt;
      GetAcceleration() = m_force + GetSpeed();
GetVelocity() = GetAcceleration();
    GetAcceleration().x += speedX *dt;
    GetAcceleration().y += speedY *dt;
    m_lastPos = (vec2f(mouse - GetPosition()).Normalise() * m_mass)+GetPosition();
m_lastPos.Limit(64);

GetAcceleration() += m_lastPos.GetNormalise()*1;
    GetPosition() += GetVelocity() + GetAcceleration() ;
    GetPosition()= mouse;

mouse.Normalise();
GetPosition().Normalise();
 std::cout << vec2f::Dot(mouse,GetPosition()) << "\n";
    m_lastPos = InputHandler::Instance()->GetMousePosition();
m_lastPos.Limit(m_mass);
VEL + acc + dt
pos  += vel
f = MA;
  */
