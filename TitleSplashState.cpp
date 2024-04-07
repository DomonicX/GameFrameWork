#include "TitleSplashState.h"

TitleSplashState::TitleSplashState()
{
    //ctor
}

TitleSplashState::~TitleSplashState()
{
    //dtor
}


void TitleSplashState::Render()
{

  //  TextureManager::Instance()->DrawRectFilled(0,0,Game::Instance()->GetWidth(),Game::Instance()->GetWindow()->getHeight(),Game::Instance()->GetRenderer());


}
void TitleSplashState::Update()
{
if( InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {

    Game::Instance()->GetStateMachine()->PopState();
    }
}
bool TitleSplashState::OnEnter()
{
    std::cout<< "Entering : "<< GetStateID() << " \n";

    return true;
}
bool TitleSplashState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void TitleSplashState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}
