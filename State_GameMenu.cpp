#include "State_GameMenu.h"

State_GameMenu::State_GameMenu()
{
    //ctor
}

State_GameMenu::~State_GameMenu()
{
    //dtor
}

 void State_GameMenu::Render()
 {
//     vec2f a,b;
//     a = vec2f(3,0);
//     b = vec2f(0,4);
//
//
//
// vec2f     c = a+b;
//
//   // std::cout << App->GetDeltaTime()<< "\n";
//
// vec2f     m = WindowOrigin-MousePosition;
// vec2f s = m.GetNormalise()*-MousePosition.Dist(WindowOrigin)*0.5;
// vec2f d = m.GetNormalise()*MousePosition.Dist(WindowOrigin)*0.5;
// d = s.GetOrtho();
// vec2f dd = -s.GetOrtho();
//
//textureManager->DrawVector(App->GetRenderer(),WindowOrigin,WindowOrigin+s);
//textureManager->DrawVector(App->GetRenderer(),WindowOrigin,WindowOrigin+d);
//textureManager->DrawVector(App->GetRenderer(),WindowOrigin,WindowOrigin+dd);

//TextureManager::Instance()->DrawSineWave(WindowOrigin,WindowOrigin.x,100,1,1,App->GetGameTime(),App->GetRenderer());
//textureManager->DrawVector(App->GetRenderer(),WindowOrigin,MousePosition);
 TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),"MainMenu",CAMCENTRE.x,CAMCENTRE.y,Colour_white,Align_Center);

 }


    void State_GameMenu::Update()
    {

    }
    bool State_GameMenu::OnEnter()
    {
//
//         SDL_Rect screensize =SDL_Rect({0,0,640,360});
//    SDL_RenderSetViewport(Application::Instance()->GetRenderer(),&screensize );
//    SDL_RenderSetIntegerScale(Application::Instance()->GetRenderer(),SDL_TRUE);
//    SDL_RenderSetLogicalSize(Application::Instance()->GetRenderer(),640,360);
//    SDL_RenderSetScale(Application::Instance()->GetRenderer(),1,1);
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);

return true;
}
    bool State_GameMenu::onExit(){}

    void State_GameMenu::resume(){}

    void State_GameMenu::HandleEvent(SDL_Event &e ){}
