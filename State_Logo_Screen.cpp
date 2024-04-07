#include "State_Logo_Screen.h"

State_Logo_Screen::State_Logo_Screen()
{
    //ctor
}

State_Logo_Screen::~State_Logo_Screen()
{
    //dtor
}


void State_Logo_Screen::Render()
{
//
//
//
//
 TextureManager::Instance()->DrawRect(APP->GetRenderer(),vec2f(0,0),WindowWidth,WindowHeight,Colour_black,true);
//up ?
//cf+=APP->GetDeltaTime()*60 : cf-=APP->GetDeltaTime()*60;
//if(cf>255)
//{up = false;
//    cf = 255;
//}
//if(cf<=0)
//{up = true;
//    cf = 0;
//}
//
//std::cout << cf << "\n";
//            SDL_Rect srsc = {0,0,1005,1005};
//
//    SDL_Rect dsre =  WindowRect;
////            {0,0,MousePosition.x,MousePosition.y};
//
////        SDL_RenderCopy(App->GetRenderer(),textureManager->getTextureMap()["Chicken_Logo"]->GetSDLTexture(),&srsc,NULL);
//
//TextureManager::Instance()->SetColorMod("Chicken_Logo",Colour_green);
//
////TextureManager::Instance()->SetAhpla("Chicken_Logo",App->GetGameTime());
//TextureManager::Instance()->SetAhpla("Chicken_Logo",cf);
//
//        TextureManager::Instance()->SDLDraw(APP->GetRenderer(),"Chicken_Logo",&srsc,&dsre,0,NULL,SDL_FLIP_NONE);
//TextureManager::Instance()->SetColorMod("Chicken_Logo",Colour_white);
//float h = FontManager::Instance()->GetFontSize("OpenSans-Regular24");
//vec2f camCenter =  Application::Instance()->GetCamera().GetCentre();
//camCenter.y-=h;
//camCenter.x-=256/4;
//SDL_FRect camRect = Application::Instance()->GetCamera().GetRectF();
//
//
////bring up console command like minecraft !!!!!!!!!!
////TextureManager::Instance()->DrawRect(APP->GetRenderer(), Application::Instance()->GetCamera().GetRectF(),Colour_magenta,true);
//
//        TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
//                                                    fontManager->GetFont("OpenSans-Regular24"),
//                                                 std::string("Current State :" + Type()),
//                                                    camCenter,
//                                                    256,
//                                                    Colour_white,Align_Left,
//                                                    0,
//                                                    SDL_FPoint({150,32}),
//                                                    SDL_FLIP_NONE);
///**
//
//
//*/
//
//        TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
//                                                    fontManager->GetFont("OpenSans-Regular24"),
//                                                 "have outside the camera a fade out view of world map so camera is in middle",
//                                                    MOUSEPOSITION,
//                                                    256,
//                                                    Colour_white,Align_Left,
//                                                    0,
//                                                    SDL_FPoint({150,32}),
//                                                    SDL_FLIP_NONE);
//                                                            TextureManager::Instance()->drawTestTexture(APP->GetRenderer(),"BackGround_256");

// TextureManager::Instance()->DrawRect(APP->GetRenderer(),vec2f(0,0),WindowWidth,WindowHeight,Colour_GUIBackGround,false);
//  TextureManager::Instance()->drawTestTexture(APP->GetRenderer(),"GUI_TileSheet");
////Application::Instance()->GetWindow()->GetWidget()->Find("GameManager")->SetPosition(MOUSEPOSITION);
//textureManager->DrawSineWave(MOUSEPOSITION,300,20,0.1,5,0,APP->GetRenderer());
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y+53),300,20,0.25,5,0,APP->GetRenderer());
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y+106),300,20,0.5,5,0,APP->GetRenderer());
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y+159),300,20,0.75,5,0,APP->GetRenderer());
//
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x+300,MOUSEPOSITION.y),300,20,0.1,5,0,APP->GetRenderer());
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x+300,MOUSEPOSITION.y),300,20,0.25,5,0,APP->GetRenderer());
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x+300,MOUSEPOSITION.y),300,20,0.5,5,0,APP->GetRenderer());
//textureManager->DrawSineWave(vec2f(MOUSEPOSITION.x+300,MOUSEPOSITION.y),300,20,0.75,5,0,APP->GetRenderer());
//
//    vec2f aa = vec2f(640,360);
//    vec2f o = Application::Instance()->GetCamera().GetCentre();
//    vec2f c = Application::Instance()->GetCamera().GetPos();
//    vec2f c2 = Application::Instance()->GetCamera().GetSize();
//    vec2f Xaxis = vec2f(640,0);
//    vec2f Xunit = Xaxis.GetNormalise();
//    vec2f Yaxis = vec2f(0,360);
//    vec2f Yunit = Yaxis.GetNormalise();
//    aa.Normalise();
//
//    for(int j = 0; j < vec2f(Xaxis+Yaxis).Length(); j++)
//    {
////        SDL_RenderDrawPoint(APP->GetRenderer(), Application::Instance()->GetCamera().GetPos().x+j*aa.x, Application::Instance()->GetCamera().GetPos().y+j*aa.y);
//        TextureManager::Instance()->SetColour(APP->GetRenderer(),Colour_white);
//        SDL_RenderDrawPoint(APP->GetRenderer(),
//                            Application::Instance()->GetCamera().GetPos().x+j*aa.x,
//                            Application::Instance()->GetCamera().GetPos().y+j*aa.y);
////                            if(j%16==0)
////    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),
////                            Application::Instance()->GetCamera().GetPos().x+j*aa.x,
////                            Application::Instance()->GetCamera().GetPos().y+j*aa.y,Colour_white,8,true);
//
//
//    }
//
//    for(int j = 0; j < Xaxis.Length(); j++)
//    {
//        float incy = std::cos(j)*aa.Length();
//        float inc = std::sin(j)*aa.Length();
//              TextureManager::Instance()->Drawcircle(APP->GetRenderer(), o.x+j*inc,
//                          o.y+j*incy,Colour_green,2,true);
//
//                           SDL_RenderDrawPoint(APP->GetRenderer(),
//                            o.x+j*inc,
//                          o.y+j*incy);
//
//
//    }
////    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),o.x,o.y,Colour_white,o.Length()*0.75,false);
////    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),o.x,o.y,Colour_white,o.Length()*0.5,false);
////    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),o.x,o.y,Colour_white,o.Length()*0.25,false);
////    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),o.x,o.y,Colour_white,128,false);
//
//    TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),
//                                           o,
//                                           o-MOUSEPOSITION,
//                                           Colour_antiquewhite);
//    std::stringstream str;
//    str << (MOUSEPOSITION-o).Length();
//    TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),str.str(),o.x,o.y,Colour_white,Align_Center);
//    TextureManager::Instance()->DrawSqaure(APP->GetRenderer(),o.x,o.y,(MOUSEPOSITION-o).Length(),Colour_green,false,0);
//    TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),MOUSEPOSITION,c,o,Colour_green);
//FontManager::Instance()->SetSize("OpenSans-Regular",MOUSEPOSITION.Length());

if((timer.GetTicks()/1000)%2==0)
  TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),"Loading...",CAMCENTRE.x,CAMCENTRE.y,Colour_white,Align_Center);

}      //  TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),vec2f(),

void State_Logo_Screen::Update(float dt)
{
    if(timer.GetTicks()>=5000)
    Application::Instance()->GetStateMachine()->ChangeState(StateFactory::Instance()->Create("State_GameMenu"));

//    if(APP->GetGameTime()>=10)
//    {
//        APP->GetStateMachine()->PushState(stateFactory->Create("TestState30"));
//    }
}
bool State_Logo_Screen::OnEnter()
{

//            SDL_Rect m_viewport =  APP->GetCamera().GetRect();
//       // SDL_RenderIsClipEnabled(APP->GetRenderer());
//        SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//        SDL_RenderSetLogicalSize(APP->GetRenderer(),m_viewport.w,m_viewport.h);
//
//       // SDL_RenderSetClipRect(APP->GetRenderer(),&m_viewport);
////
//
//        float scales = m_viewport.w /(float) m_viewport.h;
//        SDL_RenderSetScale(APP->GetRenderer(),scales,scales);
//        APP->GetCamera().SetScaler(3);
//        APP->GetCamera().SetPos(vec2f(0,0));
//
//        APP->GetCamera().SetSize(vec2f(1920,1080));
//        Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN);
timer.Start();
    return true;
}
bool State_Logo_Screen::onExit() {}
void State_Logo_Screen::resume() {}
void State_Logo_Screen::HandleEvent(SDL_Event &e ){}
