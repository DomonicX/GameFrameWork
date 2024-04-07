#include "TestState33.h"

TestState33::TestState33()
{
    //ctor
}

TestState33::~TestState33()
{
    //dtor
}
void TestState33::Render()
{

     SDL_Rect ssrcf  = alignToTilePosition((int)MOUSEPOSITION.x+8 ,(int)MOUSEPOSITION.y+8,16*APP->GetCamera().GetScaler());

ssrcf.x -= (CAMRECT.x%(int)16*APP->GetCamera().GetScaler());

    TextureManager::Instance()->DrawGrid(-APP->GetCamera().GetPos().x,0,80,16,64*APP->GetCamera().GetScaler(),Colour_red,Application::Instance()->GetRenderer());


        SDL_FRect   dsrcf  = {0,0,16,16};

   TextureManager::Instance()->drawSprite("backgroundS",0,0,640,360,APP->GetRenderer(),SDL_FLIP_NONE);
 //TextureManager::Instance()->DrawRect(APP->GetRenderer(),ssrcf);
  // TextureManager::Instance()->drawTestTexture(APP->GetRenderer(),"bush");

//TextureManager::Instance()->DrawGrid(-CAMRECT.x,CAMRECT.y,CAMRECT.w/16,CAMRECT.h/16,16,Colour_black,APP->GetRenderer());

//TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),WindowOrigin-vec2f(0,32),WindowOrigin-vec2f(64,0),WindowOrigin+vec2f(64,0),Colour_blanchedalmond);
//TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),MOUSEPOSITION,vec2f::projB(WindowOrigin,MOUSEPOSITION),WindowOrigin,Colour_red);
 if(!m_gameObects.empty())
        for(int i = 0; i< m_gameObects.size()-1; i++)
            m_gameObects[i]->Render(APP->GetRenderer(),-APP->GetCamera().GetPos().x,0);
            m_gameObects.back()->Render(APP->GetRenderer(),0,0);

     //SDL_Rect rr2  = {WindowOrigin.x-MOUSEPOSITION.x+640/2,WindowOrigin.y-MOUSEPOSITION.y+360/2,640,360};
 //TextureManager::Instance()->DrawRect(APP->GetRenderer(),rr2,Colour_green,false);

              {
        std::stringstream ww;
        ww <<vec2f(ssrcf.x,ssrcf.y)/16 << " " << m_vel;
        TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),ww.str(),CAMRECT.w/2,CAMRECT.h/2,Colour_yellow,Align_Center,16);

    }
 TextureManager::Instance()->DrawRect(APP->GetRenderer(), SDL_Rect({0,360-8,640,8}),Colour_green,true);


}

void TestState33::Update(float dt) {
m_acc = vec2f(90,0);
   m_vel = m_acc *dt;
  m_pos +=   m_vel;
   Application::Instance()->GetCamera().SetPos(m_pos);

  if(!m_gameObects.empty())
        for(int i = 0; i< m_gameObects.size()-1; i++)
        {
          SDL_Rect cp =  dynamic_cast<SDLGameObject*>( m_gameObects.back())->GetSDLRect();
          cp.x +=  CAMRECT.x;
         SDL_Rect ro =   dynamic_cast<SDLGameObject*>(m_gameObects[i])->GetSDLRect();
      //   ro.x += -CAMRECT.x;
            if(InputHandler::Instance()->HasIntersection(cp,ro))
            {
 m_gameObects[i]->SetDead(true);

//         m_gameObects[i]->Collision();
            }else  m_gameObects[i]->SetDead(false);



        }
  if(!m_gameObects.empty())
        for(int i = 0; i< m_gameObects.size(); i++)
            m_gameObects[i]->Update(dt);

   }




bool TestState33::OnEnter()
{
    std::cout  << " Entering " << Type() << "\n";

//    m_gameObects->push_back(new ILayer());
    for(int j = 0 ; j < 10; j++ )
    {

        m_gameObects.push_back(GameObjectFactory::Instance()->Create("GameObjectTree"));
        m_gameObects.back()->Load("GameObjectTree.txt");
        m_gameObects.back()->GetPosition() = vec2f(j*288,22*16-186);

        dynamic_cast<GameObjectTree*>(m_gameObects.back())->setTreeHeight(0);
    }

      for(int j = 0 ; j < 28; j++ )
    {

        m_gameObects.push_back(GameObjectFactory::Instance()->Create("GameObjectTree"));
        m_gameObects.back()->Load("GameObjectTree.txt");
        m_gameObects.back()->GetPosition() = vec2f(j*192,22*16-42);

        dynamic_cast<GameObjectTree*>(m_gameObects.back())->setTreeHeight(10);
    }
        m_gameObects.push_back(GameObjectFactory::Instance()->Create("GameObject_Player"));
        m_gameObects.back()->Load("GameObject_Player.txt");
        m_gameObects.back()->GetPosition() = vec2f(32,WindowOrigin.y*2-64);


//    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//SDL_RenderSetScale(APP->GetRenderer(),1,1);
//        Application::Instance()->GetWindow()->RescaleWindow(2);

//    //SDL_Rect www = WindowRect;
//  //      SDL_RenderSetViewport(APP->GetRenderer(),&www);
////SDL_SetWindowPosition(APP->GetWindow()->GetWindow(),0,0);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
////    SDL_Rect ss = WindowRect;
////SDL_RenderSetClipRect(APP->GetRenderer(),&ss);
//        Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
////  if(!SDL_RenderSetViewport(APP->GetRenderer(),&rect))
//

    return true;
}
bool TestState33::onExit() {}
void TestState33::resume()
{}
void TestState33::HandleEvent(SDL_Event &e )
{
    if(!m_gameObects.empty())
        for(int i = 0; i< m_gameObects.size(); i++)
            m_gameObects[i]->HandleEvent(e);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        Application::Instance()->GetCamera().SetSize(vec2f(1920,1080));
        Application::Instance()->GetCamera().SetScaler(3);


        Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);

    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
    {

        Application::Instance()->GetCamera().SetSize(vec2f(640,360));
        Application::Instance()->GetCamera().SetScaler(1);

            Application::Instance()->GetWindow()->SetIsFullScreenAble(true);
            Application::Instance()->GetWindow()->SetFullScreen(true);
    }

}


//int m_scrollingBoarderOffset = 0;
//    m_scrollingBoarderOffset -= dt * (float)m_scrollingspeed;
//    //  std::cout << dt * (float)m_scrollingspeed<< "\n";
//
//    if( m_scrollingBoarderOffset < -textureManager->getTextureMap()["BackGround1"]->GetWidth())
//
//    {
//        m_scrollingBoarderOffset = 0;
//    }
//      SDL_FRect z = {m_scrollingBoarderOffset,CAMRECT.y,640,360};
//     {
//        SDL_Rect d = {0,0,96,360};
//        TextureManager::Instance()->Draw(APP->GetRenderer(),"BackGround1",d,z,0,NULL,SDL_FLIP_NONE);
//    }
//    {
//        SDL_FRect z = {640+m_scrollingBoarderOffset,CAMRECT.y,640,360};
//        SDL_Rect d = {0,0,640,360};
//        TextureManager::Instance()->Draw(APP->GetRenderer(),"BackGround1",d,z,0,NULL,SDL_FLIP_NONE);
//    }
