#include "State_Pacman_Ready.h"

State_Pacman_Ready::State_Pacman_Ready()
{
    //ctor
}

State_Pacman_Ready::~State_Pacman_Ready()
{
    //dtor
}

void State_Pacman_Ready::Render()
{
   {
        SDL_Rect bb = {Application::Instance()->GetCamera().GetPos().x,Application::Instance()->GetCamera().GetPos().y,Application::Instance()->GetCamera().GetSize().x,Application::Instance()->GetCamera().GetSize().y};

      //  TextureManager::Instance()->DrawRect(bb,Colour_green,App->GetRenderer());
        //TextureManager::Instance()->DrawGrid(0,24+8*3,28,31,8,Colour_lightgray,App->GetRenderer());
        std::stringstream dirtext;

        dirtext << " Ready!!";
if(m_blink)
{
//TextureManager::Instance()->TextRect(App->GetRenderer());

//   TextureManager::Instance()->DrawText(dirtext.str(), 150,150,Colour_white,fontManager->GetFont("OpenSans-Regular64"),Application::Instance()->GetRenderer());

}
         }

      }



void State_Pacman_Ready::Update() { dt += APP->GetDeltaTime();

if(dt>=4.5)
{
//    Application::Instance()->cmdStateMachine("Pop_State","State_PacMan_Ready");
}

if((int)std::floor(dt)%2==0)
{
    m_blink = true;
}
else m_blink = false;


};
bool State_Pacman_Ready::OnEnter()
{
        SoundManager::Instance()->SetPlay("pacman_beginning");
    return true;
};
bool State_Pacman_Ready::onExit()
{
    return true;
};
void State_Pacman_Ready::resume() {};
void State_Pacman_Ready::HandleEvent(SDL_Event &e ) {};
