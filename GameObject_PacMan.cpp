#include "GameObject_PacMan.h"

GameObject_PacMan::GameObject_PacMan()
{
    //ctor
    m_lastPos = vec2f(0,0);
    m_force  = vec2f(0,0);
    m_width = 8;
    m_speed = 88;
    m_height = 8;
    m_acceleration = vec2f(-m_speed,0);
    m_DirFlag = PacMan::Animation::MOVING_LEFT;
    m_velocity = vec2f(0,0);
    m_position = vec2f(0,0);
    m_mass = 8;
    m_isDead = false;
    m_isVisable = true;
}

GameObject_PacMan::~GameObject_PacMan()
{
    //dtor
}
std::string GameObject_PacMan::GetDir()
{
    if(m_DirFlag==PacMan::Moving::LEFT)
    {
        return "Left";
    }
    if(m_DirFlag==PacMan::Moving::RIGHT)
    {
        return "Right";
    }
    if(m_DirFlag==PacMan::Moving::UP)
    {
        return "Up";
    }
    if(m_DirFlag==PacMan::Moving::DOWN)
    {
        return "Down";
    }
//        if( m_acceleration == vec2f(0,-m_speed))
//        {
//
//    m_DirFlag = PacMan::Animation::MOVING_UP;
//            return "MOVING_UP";
//        }
//        if( m_acceleration == vec2f(-m_speed,0))
//        {
//    m_DirFlag = PacMan::Animation::MOVING_LEFT;
//            return "MOVING_LEFT";
//
//        }
//        if(
//        m_acceleration == vec2f(m_speed,0))
//        {
//    m_DirFlag = PacMan::Animation::MOVING_RIGHT;
//
//            return "MOVING_RIGHT";
//        }
//
//        if(m_acceleration == vec2f(0,m_speed))
//        {
//    m_DirFlag = PacMan::Animation::MOVING_DOWN;
//
//        return "MOVING_DOWN";
//
//        }
//            return "BLOCKED";
}
void GameObject_PacMan::Load(std::string FileName)
{
    //std::cout << FileName << "\n";
    //std::cout << FileName << "\n";

    m_Pacman_animation_MovingUp.frameRate = 100;
    m_Pacman_animation_MovingUp.AddSrect(0,32,16,16);
    m_Pacman_animation_MovingUp.AddSrect(16,32,16,16);
    m_Pacman_animation_MovingUp.AddSrect(32,0,16,16);
    m_Pacman_animation_MovingUp.maxFrame = 3;

    m_Pacman_animation_MovingLeft.frameRate = 100;
    m_Pacman_animation_MovingLeft.AddSrect(0,16,16,16);
    m_Pacman_animation_MovingLeft.AddSrect(16,16,16,16);
    m_Pacman_animation_MovingLeft.AddSrect(32,0,16,16);
    m_Pacman_animation_MovingLeft.maxFrame = 3;

    m_Pacman_animation_MovingDown.frameRate = 100;
    m_Pacman_animation_MovingDown.AddSrect(0,48,16,16);
    m_Pacman_animation_MovingDown.AddSrect(16,48,16,16);
    m_Pacman_animation_MovingDown.AddSrect(32,0,16,16);
    m_Pacman_animation_MovingDown.maxFrame = 3;

    m_Pacman_animation_MovingRight.frameRate = 100;
    m_Pacman_animation_MovingRight.AddSrect(0,0,16,16);
    m_Pacman_animation_MovingRight.AddSrect(16,0,16,16);
    m_Pacman_animation_MovingRight.AddSrect(32,0,16,16);
    m_Pacman_animation_MovingRight.maxFrame = 3;

    m_CurrentAnmation =  &m_Pacman_animation_MovingUp;
    m_width = 16;
    m_height = 16;
}
void GameObject_PacMan::Update(float dt)
{

    m_lastPos =  m_position  ;

//    std::cout << GetDir() << "\n";
////
    if(m_velocity.x > 0 )
    {
std::cout <<  " Right \n";
    }

    if(m_velocity.x < 0 )
    {
std::cout <<  " Left \n";

    }

    if(m_velocity.y > 0)
    {
std::cout <<  " Down \n";

    }

     if(m_velocity.y < 0)
    {

std::cout <<  " Up \n";
    }

//need to get the dirction using velcity to get a fucking base line then use getdir fucntion to understand the corning
   int x = GetCentre().x/8;
        int y = GetCentre().y/8;
        int tt= 0;


        for(int i = x; i< (28-x) ; i++)
        {

       if(Gamemap[y][i+x])
       {
           break;
       }
       else {tt++;}

        }
        std::cout << tt << "\n";
    if( GetDir()=="Left")
    {
        int x = GetCentre().x/8;
        int y = GetCentre().y/8;
        if(!Gamemap[y][x-1])
        {
            m_acceleration = vec2f(-m_speed,0);
            std::cout << "Turning : Left << \n";
//            m_position = GameCoord[y][x-1];

        }

    }
    if( GetDir()=="Right")
    {
        int x = GetCentre().x/8;
        int y = GetCentre().y/8;
        if(!Gamemap[y][x+1])
        {
            if(!m_acceleration.y==0)
                std::cout << "Turning : Right << \n";
            m_acceleration = vec2f(m_speed,0);
//            m_position = GameCoord[y][x+1];
        }


    }

    if( GetDir()=="Up")
    {
        int x = GetCentre().x/8;
        int y = GetCentre().y/8;
        if(!Gamemap[y-1][x])
        {
            m_acceleration = vec2f(0,-m_speed);
            std::cout << "Turning : Up << \n";
//            m_position = GameCoord[y-1][x];
        }



    }

    if( GetDir()=="Down")
    {
        int x = GetCentre().x/8;
        int y = GetCentre().y/8;
        if(!Gamemap[y+1][x])
        {

            std::cout << "Turning : Down << \n";
            m_acceleration = vec2f(0,m_speed);
//            m_position = GameCoord[y+1][x];

        }
    }

////
////
//    m_force = m_acceleration * m_mass;
//
//    m_acceleration += vec2f(1,-1);

//  m_acceleration.Limit(1);
    m_velocity = m_acceleration *(float) APP->GetDeltaTime();

    m_velocity.Limit(1);
    vec2f::Clamp(0,1,m_velocity);
// m_velocity = m_acceleration *  App->GetDeltaTime();
// m_velocity.Limit(88* App->GetDeltaTime());

// m_velocity.x = std::ceil(m_velocity.x);
// m_velocity.y = std::ceil(m_velocity.y);
    vec2f pacmanDirVector = alignToVec2Position(GetCentre()+m_velocity.Normalise()*(float)8,16);
    vec2f ss = GetDirSenser();
    ss = ss/8;
    if(Gamemap[(int)ss.y][(int)ss.x])
        m_velocity = vec2f(0,0);
        m_position += m_velocity ;
//GetSDLRectCenter
// m_position += m_velocity.GetNormalise()*m_acceleration.Length();
//   updatePositionWithMouse();
//alignToTilePosition(inputHandler->GetMousePosition().x,inputHandler->GetMousePosition().y,8);
    //  alignToTilePosition(m_position.x,m_position.y,16);
//    m_position += m_velocity  * App->GetDeltaTime();

//       else   m_isVisable = true;
//    m_position += m_velocity.GetNormalise()*m_acceleration.Length();

}


void  GameObject_PacMan::updateAnimation()
{
//        TextureManager::Instance()->SetColorMod("PacMan_Sprite",Colour_yellow);
    m_CurrentAnmation->UpdateAnimation();
    m_Pacman_animation_MovingDown.UpdateAnimation();
    m_Pacman_animation_MovingUp.UpdateAnimation();
    m_Pacman_animation_MovingRight.UpdateAnimation();
    m_Pacman_animation_MovingLeft.UpdateAnimation();


    switch(m_DirFlag)
    {
    case PacMan::Animation::MOVING_RIGHT:
        // m_position.x  += 1;
        m_CurrentAnmation =  &m_Pacman_animation_MovingRight;
        break;

    case PacMan::Animation::MOVING_LEFT:
        m_CurrentAnmation =  &m_Pacman_animation_MovingLeft;
        //     m_position.x -= 1;
        break;

    case PacMan::Animation::MOVING_UP:
        m_CurrentAnmation =  &m_Pacman_animation_MovingUp;
        //    m_position.y -= 1;
        break;

    case PacMan::Animation::MOVING_DOWN:
        m_CurrentAnmation =  &m_Pacman_animation_MovingDown;
        //    m_position.y += 1;
        break;
    }
}
void GameObject_PacMan::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{


    GetCenterOfMass() = SDL_FPoint({0,0});
    SDL_FRect des = {m_position.x+OffsetX,m_position.y+OffsetY,m_width* Application::Instance()->GetCamera().GetScaler(),m_height * Application::Instance()->GetCamera().GetScaler()};
    m_srcRect = {479,0,16,16};

    SDL_Rect des2 = {m_position.x+OffsetX,m_position.y+OffsetY,m_width* Application::Instance()->GetCamera().GetScaler(),m_height * Application::Instance()->GetCamera().GetScaler()};
    SDL_Rect cr = CAMRECT;
    if(des.x>cr.w || des.y>cr.h)
    {

     //   textureManager->DrawRect(Ren,des,Colour_darkgreen,true);
    }
    else
    {

//        textureManager->Draw(APP->GetRenderer(),Texture(),m_srcRect,des,m_angle,&GetCenterOfMass(),SDL_FLIP_NONE);
//        TextureManager::Instance()->DrawVector(Ren,GetCentre(),GetVelocity()*m_mass,Colour_blue);
//        TextureManager::Instance()->Drawcircle(Ren,GetCentre().x,GetCentre().y,Colour_yellow,GetMass(),true);
        textureManager->DrawRect(Ren,des,Colour_yellowgreen,true);
    }
    std::cout << GetCentre()<<"\n";
//// for(int i = 0; i < 32; i++)
////for(int j = 0; j < 28; j++)
////if(!Gamemap[i][j])
////textureManager->DrawRect(Ren,SDL_Rect({j*8,i*8,8,8}),Colour_darkgreen,false);
// int x = GetCentre().x/8;
//    int y = GetCentre().y/8;
//    if(Gamemap[y-1][x])
//        des.y -=16;
//    vec2f ss = GetDirSenser();
//    ss = ss/8;
//    if(!Gamemap[(int)ss.y][(int)ss.x])
//        textureManager->DrawVector(Ren,GetCentre(),-GetDirSenser(),Colour_blue);
//std::cout << GameCoord[y][x] << "\n";
//
//std::vector<SDL_Rect> grid = MakeGrid( alignToVec2Position(GetCentre(),8).x-(8*8)/2,alignToVec2Position(GetCentre(),8).y-(8*8)/2,8,8,8);
//    for(int i = 0 ; i < (8*8); i++)
//{
//  int gx =  grid[i].x/8;
//  int gy = grid[i].y/8;
//if(Gamemap[gy][gx])
//  {
//
//     grid[i].x =-16;
//      grid[i].y = -16;
//  }
//
//
//}
//TextureManager::Instance()->DrawRects(Ren,&grid[0],grid.size(),Colour_darkgreen);
//        textureManager->DrawVector(Ren,GetCentre(),GetVelocity().GetNormalise()*16,Colour_green);
//        TextureManager::Instance()->Drawcircle(Ren,GetCentre().x,GetCentre().y,Colour_red,m_mass,false);
//  for(int i = 0 ; i < (8*8); i++)
//{
//  int gx =  grid[i].x/8;
//  int gy = grid[i].y/8;
//
//if(Gamemap[gy][gx])
//
//if(INPUTHANDLER->HasLineinRect(GetCentre(),vec2f(),grid[i]))
//{
//    TextureManager::Instance()->DrawLine(Ren,GetCentre().x,GetCentre().y,gx*8+4,gy*8+4,Colour_red);
//
//}else
//
//continue;
//    }
}
vec2f GameObject_PacMan::GetDirSenser()
{
    vec2f pacmanDirVector = GetAcceleration().GetNormalise()*m_mass ;
    vec2f ss = GetCentre() + pacmanDirVector;
//  ss = ss/8;
//  if(!Gamemap[(int)ss.y][(int)ss.x])
//            textureManager->DrawVector(Ren,GetCentre(),pacmanDirVector,Colour_blue);
    return ss;
}
void GameObject_PacMan::Clean() {}
void GameObject_PacMan::Collision()
{
    m_collision = true;
    //      TextureManager::Instance()->SetColorMod("PacMan_Sprite",Colour_green);
    m_position =  m_lastPos;
    m_velocity = vec2f(0,0);
    m_acceleration = vec2f(0,0);
    SetStoreMove(false);

//    if(vec2f::Dot(m_position.GetNormalise(),vec2f(1,0))<=0)
//    {
//
//
//        m_acceleration = vec2f(1,0);
//    }
//    else

    //     m_acceleration = vec2f(m_acceleration.x * -1,0);
    // float len = m_velocity.Dist(m_lastPos);
    // m_velocity.Normalise();
    // m_velocity.Rotate(90);
    // m_velocity  *= -len;


}
std::string GameObject_PacMan::Texture()
{
    return "Pac-Man";
}
void GameObject_PacMan::HandleEvent(SDL_Event& e )
{





}
void  GameObject_PacMan::Move_Up()
{
    // m_DirFlag =   PacMan::Animation::MOVING_UP;
    m_acceleration = vec2f(0,-m_speed);
//        m_velocity = vec2f(0,0);
    //     m_position.y-=1;

}
void  GameObject_PacMan::Move_Left()
{
    // m_DirFlag =   PacMan::Animation::MOVING_LEFT;
    m_acceleration = vec2f(-m_speed,0);
//        m_velocity =vec2f (0,0);
    //    m_position.x-=1;
}
void GameObject_PacMan::Move_Right()
{
    //   m_DirFlag =   PacMan::Animation::MOVING_RIGHT;
    m_acceleration = vec2f(m_speed,0);
//        m_velocity =vec2f (0,0);
    //  m_position.x+=1;
}
void  GameObject_PacMan::Move_Down()
{
    // m_DirFlag =  PacMan::Animation::MOVING_DOWN;
    m_acceleration = vec2f(0,m_speed);
//        m_velocity =vec2f (0,0);
    // m_position.y+=1;
}
/**<
//    if(
//        InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
//    {
//        m_DirFlag =   PacMan::Animation::MOVING_LEFT;
//
//        //     m_velocity.x =-16;
//        //GetPosition().x-=8;
//    }
//    else if(
//        InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
//    {
//        m_DirFlag =  PacMan::Animation::MOVING_RIGHT;
//// m_velocity.x =16;
////   GetPosition().x+=8;x
//    }
//    else if(
//        InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
//    {
//        m_DirFlag =  PacMan::Animation::MOVING_UP;
//        //      m_velocity.y =-16;
////   GetPosition().y-=8;
//    }
//    else if(
//        InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
//    {
//        m_DirFlag =   PacMan::Animation::MOVING_DOWN;
//
////   GetPosition().y+=8;
//    }

//    else std::cout <<"no key\n";  */
