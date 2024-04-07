#include "MarioPlayer.h"

MarioPlayer::MarioPlayer() : SDLGameObject()
{
    m_velocity = vec2f(0,0);
    m_acceleration = vec2f(0,0);
    m_force = vec2f(0,0);
    m_gravity = 9.81f;
    m_mass = 30;
    m_FacingDir = mario_Facing::MARIO_RIGHT;
    m_bisFliped = false;
    m_bisGrounded = false;
    m_bisDucking = false;
    m_bIsJumping = false;
    m_bCanJump = false;
    m_DownPressed = false;
    m_DownReleased = false;
    m_UpPressed = false;
    m_bisblinkingOn= false;
    m_bisBlinking = false;
    m_currentFrame =0;
    m_frameRate = 1;
    m_numFrame = 1;
//    Speed = 50.5;
    m_marioState = MarioState::BIGMARIO;

    m_speed = 0;
    m_velocity = vec2f(0,0);
    this->m_marioAnmationState = MarioAnmationState::IDLE;
}
MarioPlayer::~MarioPlayer()
{

} bool MarioPlayer::isGrounded()
{
    return m_bisGrounded;
}
bool MarioPlayer::isDucking()
{
    return m_bisDucking;
}
bool MarioPlayer::isJumping()
{
    return m_bIsJumping;
}

void MarioPlayer::isOnGround()
{
    m_bisGrounded= true;
    m_bIsJumping = true;
}
void  MarioPlayer::Shrink()
{
    m_bisBlinking = true;
}
bool  MarioPlayer::isBinking()
{
    return m_bisBlinking;
}
void MarioPlayer::Load(char* filename)
{

//       SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

    std::string temp = filename;
    m_Playertype= filename;
    if(temp=="SmallMario")
    {
        m_state = new SmallMario();
        m_width = 16;
        m_height = 16;
        m_Type = "SmallMario";
        m_srcRect = {1,9,m_width,m_height};
        m_desRect = {0,0,m_width,m_height};


        running.AddSrect(  43, 9,  m_state->GetWidth(), m_state->GetHeight() );
        running.AddSrect( 60,  9,  m_state->GetWidth(), m_state->GetHeight() );
        running.AddSrect( 77,  9,  m_state->GetWidth(), m_state->GetHeight() );

        running.maxFrame = 3;
        running.frameRate = 100;

        jumping.AddSrect( 119,  9,  m_state->GetWidth(), m_state->GetHeight() );
        idle.AddSrect( 1, 9,m_state->GetWidth(), m_state->GetHeight() );
        ducking.AddSrect( 1, 9,m_state->GetWidth(), m_state->GetHeight() );
        sliding.AddSrect( 98, 9,  m_state->GetWidth(), m_state->GetHeight() );



    }
    if(temp=="FireMario" )
    {
        m_state = new FireMario();
        m_height = 32;

        m_width = 16;
        m_Type = "FireMario";
        m_textureID = "FireMario";

        m_srcRect = {1,140,m_width,m_height};
        m_desRect = {0,0,m_width,m_height};


    }
    if( temp=="BigMario" )
    {
        m_state = new BigMario();
        m_width = 16;
        m_height = 32;
        m_Type = "MairoBig";
        m_textureID = m_state->Texture();

        m_srcRect = {1,26,m_width,m_height};
        m_desRect = {0,0,m_width,m_height};

        running.AddSrect(  43, 26,  m_state->GetWidth(), m_state->GetHeight() );
        running.AddSrect( 60,  26,  m_state->GetWidth(), m_state->GetHeight() );
        running.AddSrect( 77,  26,  m_state->GetWidth(), m_state->GetHeight() );

        running.maxFrame = 3;
        running.frameRate = 100;

        jumping.AddSrect( 119,  26,  m_state->GetWidth(), m_state->GetHeight() );
        idle.AddSrect( 1, 26,m_state->GetWidth(), m_state->GetHeight() );
        ducking.AddSrect(22,  26,  m_state->GetWidth(), m_state->GetHeight() );
        sliding.AddSrect( 98, 26,  m_state->GetWidth(), m_state->GetHeight() );



    }
    m_DownPressed = false;
    m_RightPressed = false;
    m_LeftPressed = false;
    m_UpPressed = false;

    m_bisBlinking = false;
    m_setBlinkingTimer= true;
    m_bStartBlinking =false;
    std::cout << "\n" << m_state->getState();
    m_isStaticSprite = true;
    m_isAnimationSprite = false;
    IsBlinkingAble = false;
}
void MarioPlayer::Render()
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

    m_desRect = {m_position.x-x,
                 m_position.y-y,
                 m_state->GetWidth(),
                 m_state->GetHeight()
                };

    if(!m_bDead && !m_bisblinkingOn)
    {

        TextureManager::Instance()->DrawRect( m_desRect,Application::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText(m_velocity.x,0,0,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("vel",128,0,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText(m_acceleration.x,0,64,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("acc",128,64,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText(GetAnimationState(),128,128,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());

        if(m_UpPressed)
            TextureManager::Instance()->DrawRectFilled( 16,0,16,16,Application::Instance()->GetRenderer());
        else
            TextureManager::Instance()->DrawRect(16,0,16,16,Application::Instance()->GetRenderer());

        if(m_DownPressed)
            TextureManager::Instance()->DrawRectFilled( 16,16,16,16,Application::Instance()->GetRenderer());
        else
            TextureManager::Instance()->DrawRect(16,16,16,16,Application::Instance()->GetRenderer());

        if(m_RightPressed)
            TextureManager::Instance()->DrawRectFilled(32,16,16,16,Application::Instance()->GetRenderer());
        else
            TextureManager::Instance()->DrawRect(32,16,16,16,Application::Instance()->GetRenderer());

        if(m_LeftPressed)
            TextureManager::Instance()->DrawRectFilled( 0,16,16,16,Application::Instance()->GetRenderer());
        else
            TextureManager::Instance()->DrawRect(0,16,16,16,Application::Instance()->GetRenderer());

}}


std::string MarioPlayer::Texture()
{
    return m_state->Texture();
}
void MarioPlayer::Update()
{
    float   dt = Application::Instance()->GetDeltaTime();
    if(IsBlinkingAble)
    {

        if(m_bStartBlinking)
        {
            if(m_setBlinkingTimer)
            {
                m_bisBlinking = true;
                m_blinkingTimer = Application::Instance()->GetGameTime()+4;

                m_setBlinkingTimer = false;
            }
        }
        if(m_blinkingTimer <= Application::Instance()->GetGameTime())
        {
            if((int)Application::Instance()->GetGameTime()%2==0)
            {
                m_bisblinkingOn = false;
            }
            else m_bisblinkingOn = true;

        }
        else
        {
            m_bStartBlinking = false;
            m_bisBlinking = false;
        }

    }

    if(m_bCanJump)
    {
        m_bCanJump=false;
        m_bIsJumping = true;

        if(m_bIsJumping)
        {
            this->m_marioAnmationState = MarioAnmationState::JUMMPING;

            m_bisGrounded = false;
            m_bIsJumping = false;

            if(m_state->getState()=="BigMario")
                SoundManager::Instance()->SetPlay("smb_jump-super");

            if(m_state->getState()=="SmallMario")
                SoundManager::Instance()->SetPlay("smb_jump-small");
            m_force.y = 200;

        }
    }

//
    if(m_acceleration.Length()==0.0)
    {
        m_FacingDir = mario_Facing::MARIO_RIGHT;
        SetAnimationState(MarioAnmationState::IDLE);
    }
    if(m_velocity.Length()>1.0)
    {
        m_FacingDir = mario_Facing::MARIO_RIGHT;
        SetAnimationState(MarioAnmationState::RUNNING_RIGHT);
    }


    if(m_RightPressed)
    {
        SetAnimationState(MarioAnmationState::RUNNING_RIGHT);
        m_FacingDir = mario_Facing::MARIO_RIGHT;
        m_acceleration.x   += m_speed;
    }
    if(m_LeftPressed)
    {
        SetAnimationState(MarioAnmationState::RUNNING_LEFT);
        m_FacingDir = mario_Facing::Mario_LEFT;
        m_acceleration.x   -= m_speed;

    }
    if(!m_LeftPressed && !m_RightPressed)
    {

        if(m_velocity.Length()<0.9)
        {

            m_velocity = vec2f(0,0);
        }
        m_acceleration.x = 0;
        m_velocity.x *= 0.90;

    }
    if(m_DownPressed)
    {
        SetAnimationState(MarioAnmationState::DUCKING);
        m_acceleration.x = 0;
    }
    if(m_UpPressed)
    {
        if(isJumping())
            m_bCanJump = true;
    }




    if(m_FacingDir == mario_Facing::MARIO_RIGHT)
        m_Flip = SDL_FLIP_NONE;
    else
        m_Flip = SDL_FLIP_HORIZONTAL;

    m_force.y  -= m_mass *  m_gravity * dt;
    m_velocity.y += m_force.y * dt;
    m_position.y -= m_velocity.y* dt;
    m_velocity.x  +=   m_acceleration.x*  dt;
    m_position.x += m_velocity.x *  dt;

}
SDL_Rect MarioPlayer::GetSDLRect()
{

    return {m_position.x,m_position.y,m_width,m_state->GetHeight()};

}
void MarioPlayer::HandleEvent(SDL_Event& e )
{
    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_DOWN)
        m_DownPressed = true;
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_DOWN)
        m_DownPressed = false;

    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_RIGHT)
        m_RightPressed = true;
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_RIGHT)
        m_RightPressed = false;

    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_LEFT)
        m_LeftPressed = true;
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_LEFT)
        m_LeftPressed = false;

    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_UP)
        m_UpPressed = true;
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_UP)
        m_UpPressed = false;

}
std::string MarioPlayer::getState()
{

    switch(m_marioState)
    {
    case SMALLMARIO:
        return "SmallMario";
        break;
    case BIGMARIO:
        return "BigMario";
        break;
    case FIREMARIO:
        return "FireMario";
        break;

    }
}
std::string MarioPlayer::GetAnimationState()
{
    switch(m_marioAnmationState)
    {
    case IDLE:
        return "IDLE";
        break;
    case DUCKING:
        return "DUCKING";
        break;
    case JUMMPING:
        return "JUMMPING";
        break;
    case RUNNING_LEFT:
        return "RUNNING_LEFT";
        break;
    case RUNNING_RIGHT:
        return "RUNNING_RIGHT";
        break;
    case SLIDING_LEFT:
        return "SLIDING_LEFT";
        break;
    case SLIDING_RIGHT:
        return "SLIDING_RIGHT";
        break;

    }
}
void MarioPlayer::Collision()
{


    if(m_state->getState()=="BigMario")
    {
        m_state = new SmallMario();
    }

    if(m_state->getState()=="SmallMario")
    {
        if(!m_onHit)
        {
            SoundManager::Instance()->SetPlay("smb_mariodie");

            m_position.y=-16;
            m_onHit = true;
        }
    }


}

void MarioPlayer::SetAnimationState(int newState)
{
    m_marioAnmationState = newState;
}
IMarioState::IMarioState() {}
IMarioState::~IMarioState() {}
SmallMario::SmallMario() {}
SmallMario::~SmallMario() {}
BigMario::BigMario() {}
BigMario::~BigMario() {}
FireMario::FireMario() {}
FireMario::~FireMario() {}
//
//    SetAnimationState( MarioAnmationState::IDLE);
//    m_FacingDir = mario_Facing::MARIO_RIGHT;

//            SetAnimationState( MarioAnmationState::DUCKING);
        //  SoundManager::Instance()->SetPlay("smb_jump-super");       //  delete m_state;
            // m_state = new SmallMario();//m_bStartBlinking
//m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//        m_position.y -= m_force * Game::Instance()->GetDeltaTime();
//std::cout << "sdsds\n " << dt << "\n"

//if(!m_DownPressed)
    //  updateMovements();
    // m_velocity.Limit(30);

//    switch(m_marioAnmationState)
//        {
//        case (DUCKING):
//        {
//
//            SDL_Rect l_srcrect = ducking.Srect[ducking.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        break;
//        case (RUNNING_RIGHT):
//        {
//            running.UpdateAnimation();
//            SDL_Rect l_srcrect = running.Srect[running.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//
//        }
//        break;
//        case (IDLE):
//
//            SDL_Rect l_srcrect = idle.Srect[idle.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//
//            break;
//        }
//    }
//
//    for(int i = 0; i  < m_blocks.size(); i++)
//    {   if(!m_blocks[i]->Dead())
//  TextureManager::Instance()->DrawLine( m_position.x,m_position.y,m_blocks[i]->GetPosition().x,m_blocks[i]->GetPosition().y, Game::Instance()->GetRenderer());
//
//    }

//    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_RIGHT)
//    {
//        SetAnimationState( MarioAnmationState::RUNNING_RIGHT);
//
//        m_FacingDir = mario_Facing::MARIO_RIGHT;
//    }
//    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_LEFT)
//    {
//        SetAnimationState( MarioAnmationState::RUNNING_LEFT);
//        m_LeftPressed = true;
//        m_FacingDir = mario_Facing::Mario_LEFT;
//
////    }
//    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_UP)
//    {
//        m_UpPressed = true;
//        if(isJumping())
//            m_bCanJump = true;
//    }
//  Game::Instance()->GetCamera()->Setpos(m_position.x,m_position.y);


//        switch(m_marioAnmationState)
//        {
//        case (DUCKING):

//        break;
//        case (IDLE):
//        {
//
//        }
//        break;
//        case (JUMMPING):
//        {
//            SDL_Rect l_srcrect = jumping.Srect[jumping.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        break;
//        case (RUNNING_LEFT):
//        {
//            running.UpdateAnimation();
//            SDL_Rect l_srcrect = running.Srect[running.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        break;
//        break;
//        case (SLIDING_LEFT):
//        {
//            SDL_Rect l_srcrect = sliding.Srect[sliding.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        break;
//        case (SLIDING_RIGHT):
//        {
//            SDL_Rect l_srcrect = sliding.Srect[sliding.currentFrame];
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        break;
//        }
//
//
//        SDL_Colour s = Game::Instance()->GetWindow()->GetColour();
//        Game::Instance()->GetWindow()->SetColour(255,255,255,0);
//    }

//    if(m_LeftPressed)
//        Speed = -50;
// m_acceleration.x  = Speed;
//m_acceleration.x = m_force.x * dt;

//
//    if(!m_RightPressed && !m_LeftPressed)
//    {
//        std::cout << "right pressed\n";
//        if(m_velocity.Length()<0.9)
//        {
//            m_velocity = vec2f(0,0);
//        }
//        else
//
//
////    }
// if(m_LeftPressed)
//        {
//             switch(m_FacingDir)
//    {
//    case mario_Facing::MARIO_RIGHT:
//        if(m_LeftPressed)
//        {
//m_Flip = SDL_FLIP_NONE;
//            Speed *= -1;
//        }
//        else
//m_Flip = SDL_FLIP_HORIZONTAL;
//        break;
//    case mario_Facing::Mario_LEFT:
//        if(m_RightPressed)
//        {
//m_Flip = SDL_FLIP_HORIZONTAL;
//            Speed *= -1;
//        }
//        else
//        break;
//    }
//m_velocity.x*=-0.8;
//    m_velocity.Limit(m_acceleration.Length());
// m_velocity.x*= 0.9;


//        m_force.y  -= m_mass *  m_gravity * dt;
//        m_velocity.y += m_force.y * dt;
//        m_position.y -= m_velocity.y* dt;
//        m_velocity.x  +=   m_acceleration.x*  dt;
//        m_position.x += m_velocity.x *  dt;


//
//    m_RightPressed = false;
//    m_LeftPressed = false;
//    m_acceleration = m_force / m_mass;
////Acceleration = force / mass
//
////Velocity = velocity + acceleration * deltaTime
//
////Position = position + velocity * deltaTime


//
//    if(isGrounded())
//    {
//        if(m_velocity.Length()<=1)
//            this->m_marioAnmationState = MarioAnmationState::IDLE;
//
//        if (isDucking())
//        {
//            this->m_marioAnmationState = MarioAnmationState::DUCKING;
//        }
//
//    }
//    if(m_RightPressed)
//    {
//        if(m_velocity.x >= 0)
//        {
//            this->m_marioAnmationState = MarioAnmationState::SLIDING_LEFT;
//
//            m_Flip = SDL_FLIP_HORIZONTAL;
//        }
//        else
//
//            this->m_marioAnmationState = MarioAnmationState::RUNNING_RIGHT;
//    }
//    if(m_LeftPressed)
//    {
//        if(m_velocity.x <= 0)
//        {
//
//            m_Flip = SDL_FLIP_NONE;
//            this->m_marioAnmationState = MarioAnmationState::SLIDING_RIGHT;
//
//        }
//        else
//
//            this->m_marioAnmationState = MarioAnmationState::RUNNING_LEFT;
//    }


//

//dtor


//    m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));
//   m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));


//   m_lastPos = m_position;
//
//    if(m_oldTime + m_frameRate < SDL_GetTicks())
//    {
//        m_currentFrame++;
//        m_oldTime = SDL_GetTicks();
//    }
//    if(m_currentFrame == m_maxFrame)
//    {
//        m_currentFrame = 0;
//    }
//    // m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//    // m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//
//m_force -= m_mass * m_gravity * dt
//
//    m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//    m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//
//
//
//
//    m_velocity += m_acceleration * Speed *= Game::Instance()->GetDeltaTime();
//    m_position +=  m_velocity;
////
//if(m_position.y>=Game::Instance()->GetWindowHeight())
//
//    m_position.y =0;

//VEL + acc + dt
//pos  += vel
//f = MA;
//
////        velocity += acceleration *= Game::Instance()->GetDeltaTime();
////        m_velocity.x = velocity*= 0.99;
////        m_position +=  m_velocity;
//    m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
////           m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
////            //    m_position.y -= m_force * Game::Instance()->GetDeltaTime();
////        } m_force -= 1;
////        m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
////        m_position.y -= m_force * Game::Instance()->GetDeltaTime();
////        velocity += acceleration *= Game::Instance()->GetDeltaTime();
//    float l_dt= Game::Instance()->GetDeltaTime();
//m_velocity  -= m_acceleration + l_dt*2;
//m_position  -= m_velocity;

//        if(m_marioAnmationState==MarioAnmationState::DUCKING)
//        {
//            SDL_Rect l_srcrect = m_srcRect;
//            l_srcrect.x+=16;
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,29,0,m_Flip);
//        }
//        else if(m_marioAnmationState==MarioAnmationState::IDLE)
//        {
//            SDL_Rect l_srcrect = m_srcRect;
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//        }
//        else if(m_marioAnmationState==MarioAnmationState::RUNNING_RIGHT)
//        {
//            SDL_Rect l_srcrect = m_srcRect;
//            l_srcrect.x += 16*2;
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//        }
//        else if(m_marioAnmationState==MarioAnmationState::SLIDING_RIGHT)
//        {
//            SDL_Rect l_srcrect = m_srcRect;
//            l_srcrect.x += 16*5;
//            m_Flip = SDL_FLIP_NONE;
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//            m_Flip = SDL_FLIP_HORIZONTAL;
//        }
//        else if(m_marioAnmationState==MarioAnmationState::JUMMPING)
//        {
//            SDL_Rect l_srcrect = m_srcRect;
//            l_srcrect.x += 16*6;
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        else if(m_marioAnmationState==MarioAnmationState::IDLE)
//        {
//            SDL_Rect l_srcrect = m_srcRect;
//            l_srcrect.x += 16*14;
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&l_srcrect, &m_desRect,0,0,m_Flip);
//
//        }
//        else
//        {
//            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,m_Flip);
//
//        }

//            TextureManager::Instance()->DrawLine(GameObject::bottomLeft().x,GameObject::bottomLeft().y,GameObject::BottomRight().x,GameObject::BottomRight().y,Game::Instance()->GetRenderer());
//            TextureManager::Instance()->DrawLine(GameObject::topLeft().x,GameObject::topLeft().y,GameObject::topRight().x,GameObject::topRight().y,Game::Instance()->GetRenderer());
//            TextureManager::Instance()->DrawLine(GameObject::topLeft().x,GameObject::topLeft().y, GameObject::bottomLeft().x,GameObject::bottomLeft().y,Game::Instance()->GetRenderer());
//            TextureManager::Instance()->DrawLine(GameObject::topRight().x,GameObject::topRight().y,GameObject::BottomRight().x,GameObject::BottomRight().y,Game::Instance()->GetRenderer());
//
//            TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::BottomRight().x,GameObject::BottomRight().y,Game::Instance()->GetRenderer());
//            TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::bottomLeft().x,GameObject::bottomLeft().y,Game::Instance()->GetRenderer());
//            TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::topRight().x, GameObject::topRight().y,Game::Instance()->GetRenderer());
//            TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::topLeft().x,GameObject::topLeft().y,Game::Instance()->GetRenderer());
