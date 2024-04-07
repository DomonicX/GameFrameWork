#include "GameObject_Player.h"

GameObject_Player::GameObject_Player()
{
    m_lastPos = vec2f(0,0);
    m_force  = vec2f(0,0);
    m_width = 8;
    m_speed = 1;
    m_height = 8;
    m_acceleration = vec2f(0,m_speed);
    m_DirFlag = PLAYER::Move::MOVING_NA;
    m_velocity = vec2f(0,0);
    m_position = vec2f(0,0);
    m_mass = 8;
    m_isDead = false;
    m_isVisable = true;
    m_velocityMax = 600;
    //ctor
    m_colour = {0,0,0};
}

GameObject_Player::~GameObject_Player()
{
    //dtor
}

void GameObject_Player::Load(std::string FileName)
{

//    TextureManager::Instance()->Load("Img/BackGround_256.png","BackGround_256",APP->GetRenderer());

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
    m_textureID = "char";
    m_width = 64;
    m_height = 64;

}
void GameObject_Player::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    if(!Dead())
    {

        if(m_angle > 0)
        {}//m_textureID = "char3";
//std::cout << m_angle+90 << " aaaa\n";
//    SDL_FPoint sp = SDL_FPoint({TextureManager::Instance()->getTextureMap()[m_textureID]->GetWidth()/2,
//                                TextureManager::Instance()->getTextureMap()[m_textureID]->GetHeight()/2});
//    SDL_RendererFlip    rfp = SDL_FLIP_NONE;
        //  m_desRect = {m_position.x - OffsetX ,m_position.y - OffsetY,getWidth(),getHeight()};
        m_desRect = {m_position.x,m_position.y,getWidth(),getHeight()};
  // GetCenterOfMass() = SDL_FPoint({getWidth()/2,getHeight()/2});
//std::cout << m_position.vectorAngle(m_velocity.x,m_velocity.y) <<"\n";
        if(m_DirFlag==PLAYER::Move::MOVING_LEFT)

//   m_flip = SDL_FLIP_HORIZONTAL;

            SDL_RenderCopyExF(Ren,TextureManager::Instance()->getTextureMap()[m_textureID]->GetSDLTexture(),NULL,&m_desRect,m_angle,&GetCenterOfMass(),m_flip);

      //  TextureManager::Instance()->DrawRect(Ren,m_desRect,m_colour,true);

       // SDL_RenderCopyExF(Ren,TextureManager::Instance()->getTextureMap()["tile2"]->GetSDLTexture(),NULL,&m_desRect,m_angle,&GetCenterOfMass(),m_flip);
        SDL_RenderCopyExF(Ren,TextureManager::Instance()->getTextureMap()[m_textureID]->GetSDLTexture(),NULL,&m_desRect,m_angle,&GetCenterOfMass(),m_flip);

//
//    if(m_isbFilled)
//        TextureManager::Instance()->drawSprite(m_textureID,m_position.x+OffsetX,m_position.y+OffsetY,m_width,m_height,Ren,SDL_FLIP_HORIZONTAL);
//    else
//        TextureManager::Instance()->drawSprite(m_textureID,m_position.x+OffsetX,m_position.y+OffsetY,m_width,m_height,Ren,SDL_FLIP_NONE);
//
//    TextureManager::Instance()->DrawVector(Ren,m_position+vec2f(OffsetX,OffsetY),vec2f(0,m_height));
//    TextureManager::Instance()->DrawVector(Ren,CAMCENTRE,vec2f(0,buttonTimer*60));
//    TextureManager::Instance()->DrawVector(Ren,m_position+vec2f(m_width,0)+vec2f(OffsetX,OffsetY),vec2f(0,m_position.y+360+m_height));
        {
            std::stringstream ww;
            ww <<GetDir();
            TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),ww.str(),WindowOrigin.x,0,Colour_yellow,Align_Right,32);

            {
                vec2f l_dXy = vec2f(m_desRect.x,m_desRect.y+m_desRect.h/2);
                vec2f l_dXX = vec2f(m_desRect.x+m_desRect.w,m_desRect.y);
                vec2f l_Normalvec =l_dXX - l_dXy;
                vec2f l_dX = vec2f(m_desRect.x+l_dX2.x,m_desRect.y+m_desRect.h+l_dX2.y);
//     l_Normalvec.Normalise();
//     l_Normalvec*=16;
                l_Normalvec.Rotate(-GetAngle());
                l_Normalvec.Ortho();
                TextureManager::Instance()->DrawVector(Ren,l_dX,l_Normalvec,Colour_white);
            }
        }
    }

//std::cout << vec2f::GetAngle(m_position.x,m_position.y,MOUSEPOSITION.x,MOUSEPOSITION.y) << ";\n";
}

std::string    GameObject_Player::GetState()
{
    switch (m_StateFlag)
    {
    case PLAYER::OBJECT::DEAD:
        return "DEAD";
        break;
    case PLAYER::OBJECT::DYING:
        return "DYING";
        break;
    case PLAYER::OBJECT::EATING_CHERRY:
        return "EATING_CHERRY";
        break;
    case PLAYER::OBJECT::EATING_GHOST:
        return "EATING_GHOST";
        break;
    case PLAYER::OBJECT::IDLE:
        return "IDLE";
        break;
    case PLAYER::OBJECT::MOVING:
        return "MOVING";
        break;
    };
}
std::string GameObject_Player::GetDir()
{
    switch (m_DirFlag)
    {
    case PLAYER::Move::MOVING_UP:
        return "MOVING_UP";
        break;
    case PLAYER::Move::MOVING_LEFT:
        return "MOVING_LEFT";
        break;
    case  PLAYER::Move::MOVING_RIGHT:
        return "MOVING_RIGHT";
        break;
    case  PLAYER::Move::MOVING_DOWN:
        return "MOVING_DOWN";
        break;
    case  PLAYER::Move::MOVING_NA:
        return "MOVING_NA";
        break;
    };
}

void GameObject_Player::Clean() {}
void GameObject_Player::Collision()
{
//std::cout << "GameObject_Player collision" << "\n";
    //isOnGround = true;
    m_collision = true;

}

void  GameObject_Player::Collision( GameObject* g)
{
    if(g->Type()=="blank" || g->Type()=="platformTile3")
    {Jump = false;
        isOnGround = true;
        m_angle =  dynamic_cast<SDLGameObject*>(g)->GetAngle();
//std::cout << g->GetPosition() << "\n";
//dynamic_cast<SDLGameObject*>(g)->GetCentre();
        SDL_FRect gRect = dynamic_cast<SDLGameObject*>(g)->GetSDLRectF();
        vec2f  l_dX2 = g->GetPosition();
        vec2f  l_dX3 = GetPosition();
vec2f playerCenter = vec2f(l_dX2.x,l_dX2.y);
vec2f Gcenter= vec2f(l_dX3.x,l_dX3.y);
vec2f Gp= vec2f(playerCenter-Gcenter);

//GetCenterOfMass() = dynamic_cast<SDLGameObject*>(g)->GetCenterOfMass();
//GetCenterOfMass() = {Gp.x+dynamic_cast<SDLGameObject*>(g)->GetCenterOfMass().x,Gp.y+dynamic_cast<SDLGameObject*>(g)->GetCenterOfMass().y};

//GetCenterOfMass() = SDL_FPoint({getWidth()/2,getHeight()/2});
GetCenterOfMass() = SDL_FPoint({Gp.x,Gp.y});

//dynamic_cast<SDLGameObject*>(g)->GetCenterOfMass() = SDL_FPoint({getWidth()/2,getHeight()/2});
//dynamic_cast<SDLGameObject*>(g)->GetCentre();

//std::cout << vec2f::Dist(playerCenter,Gcenter) << " dis \n";
//std::cout << Gp << " Gp \n";

        SDL_FRect ss =  GetIntersectRect(gRect,GetSDLRectF());

    //m_lastPos =  m_position  ;
        if(ss.w >=  ss.h )
        {

            m_velocity.y = 0;
//        SDL_FRect ss =  GetIntersectRect(gRect,GetSDLRectF());
            if(GetPosition().y  <=  g->GetPosition().y) //TOP
            {
                m_textureID = "pushingStickman2";
                GetPosition().y -= ss.h;
            }
            else                                     //bottom
            {
                m_textureID = "pushingStickman3";
                GetPosition().y += ss.h;
            }
        }
        else if(ss.w  <= ss.h)
        {

            m_velocity.x = 0;
            if(GetPosition().x <=  g->GetPosition().x)//Left
            {
                m_textureID = "pushingStickman4";
                GetPosition().x -= ss.w;
            }
            else                                    //right
            {
                m_textureID = "pushingStickman";
                GetPosition().x += ss.w;
            }
        }
    }

    if(g->Type()=="Spikes")
    {
        SetDead(true);
    }

}

void GameObject_Player::HandleEvent(SDL_Event& e )
{

    if(m_key_Up)
        if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && e.key.state==SDL_RELEASED)
            m_key_Up = false;

    if(!m_key_Up)
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && e.key.state==SDL_PRESSED)
            m_key_Up = true;

    if(m_key_down)
        if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && e.key.state==SDL_RELEASED)

            m_key_down = false;

    if(!m_key_down)
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && e.key.state==SDL_PRESSED)

            m_key_down = true;

    if(m_key_right)
        if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && e.key.state==SDL_RELEASED)

            m_key_right = false;

    if(!m_key_right)
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && e.key.state==SDL_PRESSED)

            m_key_right = true;

    if(m_key_left)
        if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && e.key.state==SDL_RELEASED)

            m_key_left = false;

    if(!m_key_left)
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && e.key.state==SDL_PRESSED)

            m_key_left = true;

}

void GameObject_Player::Update(float dt)
{

    m_textureID = "pushingStickman1";
    m_colour = {0,127,0};
    m_collision = false;
    buttonDown = false;
//if(!isOnGround)



//
//if(!isOnGround)
//m_speed = 50;
//else
//m_speed = 100;

    m_DirFlag = PLAYER::Move::MOVING_NA;
    m_StateFlag =  PLAYER::OBJECT::IDLE;



    if(m_key_down)
    {
        m_textureID = "char";
        m_DirFlag = PLAYER::Move::MOVING_DOWN;

        m_acceleration = vec2f(0,m_speed);
    }
    if(m_key_left)
    {
        m_textureID = "char3";
        m_DirFlag = PLAYER::Move::MOVING_LEFT;
        m_acceleration = vec2f(-m_speed,0);

    }
    if(m_key_right)
    {
        m_textureID = "char3";
        m_DirFlag = PLAYER::Move::MOVING_RIGHT;
        m_acceleration = vec2f(m_speed,0);

    }
    if(m_key_Up)
    {
        m_textureID = "char2";
        m_DirFlag = PLAYER::Move::MOVING_UP ;
        if(canJump())
        {
            m_velocity += vec2f(0,-300);
            Jump = true;
            isOnGround =false;
        }
    }
    if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && !InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {

    }
//
//
//    if(m_DirFlag!=PLAYER::Move::MOVING_NA)
//    {
//if(m_velocity.Length()<1)
//{
//    m_velocity = vec2f(0,0);
//}else
//m_velocity *= 0.9;
//        m_textureID = "char";
//        m_StateFlag =  PLAYER::OBJECT::MOVING;
//        m_acceleration = vec2f(0,0);
//    }
//
//
//
//



    m_force = m_acceleration *m_mass ;

    vec2f friction;
    m_lastPos =  m_position  ;
    m_velocity += m_acceleration *(float) dt;
    m_velocity.y += 9.81;
    m_position += m_velocity *(float)  dt ;
//    m_velocity.Limit(1);
//   vec2f::Clamp(0,m_velocityMax*(float)  dt,m_velocity);
//  //  if(!isOnGround)
//friction = -m_velocity*(float)0.25;
//      std::cout << (-friction*(float)4)<< "      -m_velocity/(float)dt\n";


//
// friction = -m_velocity * m_Friction;
//
//if(m_velocity.Length() < m_Friction *(float) dt)
//{
//
//friction = (-m_velocity/(float)dt);
//
//} else
//friction = -m_velocity.GetNormalise() *(float) m_Friction;

    //  std::cout << m_velocity << "\n";
//        if(m_velocity.Length()>=1)
//        {
//        m_velocity *= (float)0.99;
//        }
//        else {
//            m_acceleration = vec2f(0,0);
//            m_velocity = vec2f(0,0);
//        }


    // isOnGround = false;
//    if(m_DirFlag != PLAYER::Move::MOVING_NA)
//        buttonDown = true;
//   if(buttonDown)
//  buttonTimer += dt;
//     else
//     {
//         buttonTimer = 0;
//     }
    //  std::cout << buttonTimer << "\n";


//    std::cout << g->Type() << "  -  player\n";
//    if(!m_collision)
//    {
//ss.w,ss.h
//    std::cout <<ss.w  << "  - ss.w r\n";
//    std::cout <<ss.h  << "  - ss.h r\n";
//if(ss.w >ss.h)
//{
//
//    std::cout <<"TOP - BOTTOM  \n";
//}
//if(ss.w  < ss.h)
//{
//    std::cout <<" LEFT -RIGHT \n";
//    }

//
//
//        if(g->GetPosition().x<GetPosition().x)
//        {
//
//
//
//
//
//            m_textureID = "pushingStickman";
//            // pushingStickman
//            //|| InputHandler::Instance()->HasPointinRect(TR,gRect)
//            m_flip = SDL_FLIP_HORIZONTAL;
//            m_colour = {0,255,255};
//            //   m_position.x = g->getWidth() + g->GetPosition().x;
//        }
//
//
//
//        if(g->GetPosition().x+g->getWidth()>GetPosition().x)
//        {
//            m_textureID = "pushingStickman";
//            m_flip = SDL_FLIP_NONE ;
//            m_colour = {0,255,0};
//            //  m_position.x =  g->GetPosition().x - getWidth();
//        }
//        if(g->GetPosition().y+g->getHeight()<GetPosition().y)
//        {
//            m_textureID = "pushingStickman";
//            std::cout << " TR IN RECT \n";
//            m_flip = SDL_FLIP_NONE ;
//            m_colour = {0,255,0};
//            //  m_position.y =  g->GetPosition().y - getHeight();
//        }
//
//if(g->GetPosition().y<GetPosition().y)
//    m_colour = {0,255,125};

//        if(g->Type()=="Spikes")
//        {
//            m_colour = {255,0,255};
//            std::cout << Application::Instance()->GetStateMachine()->GetCurrentStateID() << "Spikes \n";
//        }
//        if(g->Type()=="bubblemaker")
//        {
//            m_colour = {0,0,255};
//            std::cout << Application::Instance()->GetStateMachine()->GetCurrentStateID() << "bubblemaker \n";
//        }
//        if(g->Type()=="chair")
//        {
//            m_colour = {0,255,255};
//            std::cout << Application::Instance()->GetStateMachine()->GetCurrentStateID() << "chair \n";
//        }
//    }
//    m_collision = true;
//
//        SDL_FPoint TL  =GetRectHitPoint(0,GetSDLRectF());
//        SDL_FPoint ML   =GetRectHitPoint(3,GetSDLRectF());
//        SDL_FPoint BL  =GetRectHitPoint(6,GetSDLRectF());
//        SDL_FPoint TR   =GetRectHitPoint(2,GetSDLRectF());
//        SDL_FPoint MR  =GetRectHitPoint(5,GetSDLRectF());
//        SDL_FPoint BR  =GetRectHitPoint(8,GetSDLRectF());
//        SDL_FRect gRect = dynamic_cast<SDLGameObject*>(g)->GetSDLRectF();
//
//        SDL_FRect ss =  GetIntersectRect(gRect,GetSDLRectF());


    //  SDLGameObject::updatePositionWithMouse();
}
