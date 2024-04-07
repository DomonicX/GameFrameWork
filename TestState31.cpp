#include "TestState31.h"

TestState31::TestState31()
{
    //ctor
}

TestState31::~TestState31()
{
    //dtor
}

void TestState31::Render()
{
//    TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),CAMCENTRE,CAMCENTRE-MOUSEPOSITION,Colour_lime);
    vec2f m = MOUSEPOSITION;
    m =  alignToVec2Position(m+Application::Instance()->GetCamera().GetPos(),16);
    vec2f l = m-vec2f(CAMRECT.x,CAMRECT.y);

//dynamic_cast<SDLGameObject*>(m_gameobjects[i])->GetSDLRectF();

    //   TextureManager::Instance()->DrawGrid(CAMCENTRE.x,CAMCENTRE.y,25,25,8,Colour_red,Application::Instance()->GetRenderer());
//   TextureManager::Instance()->DrawGrid(CAMRECT.x+CAMRECT.w/(float)2,CAMRECT.y+CAMRECT.h/(float)2,24,28,16,Colour_green,Application::Instance()->GetRenderer());
//   TextureManager::Instance()->DrawGrid((CAMRECT.x+CAMRECT.w/(float)2)-CAMRECT.w/(float)2,(CAMRECT.y+CAMRECT.h/(float)2)-CAMRECT.h/(float)2,24,42,12,Colour_green,Application::Instance()->GetRenderer());

//    TextureManager::Instance()->DrawRect(APP->GetRenderer(),WindowRect,Colour_black,true);
//    TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),CAMRECT,Colour_white,true);

    // std::cout << MOUSEPOSITION <<  "\n";
    LTexture *ltexture = new LTexture();
    ltexture->LoadFromRendered(APP->GetRenderer(),16,16,Colour_white,SDL_BLENDMODE_BLEND);

    for(int j = 0 ; j < CAMRECT.w; j+=16 )
        for(int i = 0 ; i <  CAMRECT.h; i+=16 )
            ltexture->Render(APP->GetRenderer(),CAMRECT.x+j,CAMRECT.y+i);
    delete ltexture;

    TextureManager::Instance()->DrawGrid(CAMRECT.x,CAMRECT.y,CAMRECT.w/8,CAMRECT.h/8,8,Colour_darkgrey,Application::Instance()->GetRenderer());
//    TextureManager::Instance()->DrawGrid(CAMRECT.x,CAMRECT.y,CAMRECT.w/64,CAMRECT.h/64,64,Colour_grey,Application::Instance()->GetRenderer());
    vec2f aa = vec2f(CAMCENTRE+-MOUSEPOSITION+vec2f(CAMRECT.x,CAMRECT.y));
    aa.Rotate(0);
//    for(int i = 0; i < 4 ; i++)
//    {
//        //  aa.Rotate(M_PI);
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),CAMCENTRE,vec2f(CAMRECT.x,CAMRECT.y)+MOUSEPOSITION,Colour_blue);
//

    Anim2 = Animation(vec2f(256,16),16,16/(float)60,ANIMATION_HORIZONTAL);
//    }
    for(int i = 0 ; i < m_gameobjects.size(); i+=1 )

        if(GetPointInRectF(SDL_FPoint({ m_gameobjects[i]->GetPosition().x+ Application::Instance()->GetCamera().GetRect().x,
                                        m_gameobjects[i]->GetPosition().y+ Application::Instance()->GetCamera().GetRect().y}),Application::Instance()->GetCamera().GetRectF()) && !m_gameobjects[i]->Dead())
        {
            m_gameobjects[i]->Render(Application::Instance()->GetRenderer(),CAMRECT.x,CAMRECT.y);
        }

////    textureManager->DrawVector(App->GetRenderer(),WindowOrigin,alignToVec2Position(MousePosition,16));
//        }
    TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),CAMRECT,Colour_red,false);
    SDL_FRect MouseSelectRect = SDL_FRect{alignToTilePosition(INPUTHANDLER->GetMousePosition().x,INPUTHANDLER->GetMousePosition().y,16)};
    MouseSelectRect.w = 16;
    MouseSelectRect.h =16;
    TextureManager::Instance()->DrawRect(APP->GetRenderer(),MouseSelectRect,Colour_antiquewhite,true);
//     TextureManager::Instance()->DrawVector(APP->GetRenderer(),CAMCENTRE,vec2f(CAMRECT.x,CAMRECT.y)+MOUSEPOSITION,Colour_blue);

    line AxisX = line({vec2f(CAMRECT.x,CAMCENTRE.y),vec2f(CAMRECT.x+CAMRECT.w,CAMCENTRE.y)});
    line AxisY = line({vec2f(CAMCENTRE.x,CAMRECT.y),vec2f(CAMCENTRE.x,CAMRECT.h+CAMRECT.y)});
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),AxisX,Colour_black);
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),AxisY,Colour_black);
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),CAMCENTRE.x,CAMCENTRE.y,MOUSEPOSITION.x,MOUSEPOSITION.y,Colour_blue);
//            TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),"1",CAMCENTRE.x+1+4,CAMCENTRE.y-14,Colour_blue,Align_Right);
//y * CAMRECT + j
   // SDL_SetRenderDrawBlendMode(APP->GetRenderer(),SDL_BlendMode::SDL_BLENDMODE_NONE);
    for(int j = 0 ; j < CAMRECT.w; j++ )
    {

        vec2f p = vec2f{j,std::sin(j/180*M_PI2)+j};
        TextureManager::Instance()->DrawPoint(APP->GetRenderer(),p.x+CAMCENTRE.x,p.y+CAMCENTRE.y);
    }
//
//SDL_Rect l_button_Idie_= {96,160,16,16};
//SDL_Rect l_buttonLastAction = {112,160,16,16};
//SDL_Rect l_buttonISAction = {128,160,16,16};
//SDL_Rect l_buttonToggled_On = {144,160,16,16};
//        TextureManager::Instance()->Draw(APP->GetRenderer(),"GUI_TileSheet",l_button_Idie_,  {MOUSEPOSITION.x,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//        TextureManager::Instance()->Draw(APP->GetRenderer(),"GUI_TileSheet",l_buttonLastAction,  {MOUSEPOSITION.x+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//        TextureManager::Instance()->Draw(APP->GetRenderer(),"GUI_TileSheet",l_buttonISAction,  {MOUSEPOSITION.x+16+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//        TextureManager::Instance()->Draw(APP->GetRenderer(),"GUI_TileSheet",l_buttonToggled_On,  {MOUSEPOSITION.x+16+16+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//
//
    vec2f mouse = MOUSEPOSITION;
    line mouseY = line({vec2f(CAMRECT.x,CAMRECT.y),vec2f(CAMCENTRE.x,CAMRECT.y)});
    TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),vec2f(CAMRECT.x,CAMRECT.y)-CAMCENTRE,vec2f(CAMRECT.x,CAMRECT.y)+mouse,Colour_lime);

    TextureManager::Instance()->DrawLine(Application::Instance()->GetRenderer(),mouseY,Colour_lime);


    TextureManager::Instance()->SetColour(APP->GetRenderer(),Colour_lime);

    textureManager->DrawSineWave(vec2f(CAMRECT.x,CAMCENTRE.y+8),CAMRECT.w,vec2f::Dist(m_gameobjects.back()->GetPosition(),CAMCENTRE),0.1,5,0,APP->GetRenderer());

    TextureManager::Instance()->SetColour(APP->GetRenderer(),Colour_lime);

    vec2f uint = vec2f(CAMRECT.w,CAMRECT.h);

    uint.Normalise();

//std::cout << APP->GetGameTime() << "\n";

    for(int j = 0 ; j < 1; j++ )
    {

        SDL_FRect desrect = {MOUSEPOSITION.x-32,MOUSEPOSITION.y-32,16,16};
        SDL_Rect SpriteRect = {0,0,16,16};
        TextureManager::Instance()->SetAhpla("Test2",255);
//std::cout << vec2f::Dot(vec2f(0,-1),vec2f(CAMCENTRE-MOUSEPOSITION).GetNormalise())<<  "   -1dot \n";
//std::cout << vec2f::Dot(vec2f(1,1),vec2f(CAMCENTRE-MOUSEPOSITION).GetNormalise())<<  "   -1dot \n";
//if(vec2f::Dot(vec2f(0,-1),vec2f(CAMCENTRE-MOUSEPOSITION).GetNormalise())<0)
        if(vec2f::Dot(vec2f(1,1),vec2f(CAMCENTRE-MOUSEPOSITION).GetNormalise())<0)
            TextureManager::Instance()->Draw(APP->GetRenderer(),"Test2",SpriteRect,desrect,0,NULL,SDL_FLIP_NONE);
        else
        {
            TextureManager::Instance()->SetAhpla("Test2",75);
            TextureManager::Instance()->Draw(APP->GetRenderer(),"Test2",SpriteRect,desrect,0,NULL,SDL_FLIP_NONE);
        }

    }

    // std::cout << vec2f::Dot(vec2f(1,1),vec2f(CAMCENTRE-MOUSEPOSITION).GetNormalise())<<  "    1dot \n";

    //std::cout << vec2f::Dot(MOUSEPOSITION,vec2f(0,MOUSEPOSITION.y-32))<<  " dot \n";
        SDL_FRect z = {m_scrollingBoarderOffset,CAMRECT.y,640,360};
     {
        SDL_Rect d = {0,0,96,360};
        TextureManager::Instance()->Draw(APP->GetRenderer(),"BackGround1",d,z,0,NULL,SDL_FLIP_NONE);
    }
    {
        SDL_FRect z = {640+m_scrollingBoarderOffset,CAMRECT.y,640,360};
        SDL_Rect d = {0,0,640,360};
        TextureManager::Instance()->Draw(APP->GetRenderer(),"BackGround1",d,z,0,NULL,SDL_FLIP_NONE);
    }
    if(!m_gameObects.empty())
        for(int i = 0 ; i < m_gameObects.size(); i++ )
        {
            m_gameObects[i]->Render(APP->GetRenderer(),CAMRECT.x,CAMRECT.y);
        }
    for(int i = 0 ; i < m_gameObects.size(); i++ )
    {
        for(int j = 0 ; j < m_gameObects.size(); j++ )
        {
            vec2f V =  m_gameObects[i]->GetPosition();
            vec2f V2 =  m_gameObects[j]->GetPosition();

            TextureManager::Instance()->DrawVector(APP->GetRenderer(),V,V-V2,Colour_cornflowerblue);
        }

    }
    mouse = CAMCENTRE-mouse;

    vec2f mouseX = mouse.GetOrtho();
    vec2f mouseXX = mouseX;
    mouseXX.Rotate(M_PI/4);
    TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),CAMCENTRE,mouse,Colour_lime);
    TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),CAMCENTRE,mouseX,Colour_lime);
    TextureManager::Instance()->DrawVector(Application::Instance()->GetRenderer(),CAMCENTRE,mouseXX,Colour_lime);

    vec2f a4 = vec2f(CAMCENTRE);
    vec2f b4 = vec2f(CAMCENTRE).GetOrtho();;
    vec2f c4 = vec2f(32,32);
   // TextureManager::Instance()->DrawTriangle(Application::Instance()->GetRenderer(),a4,b4,c4,Colour_lime);
    /**<
     for(int j = 0 ; j <10; j+=16 )
          for(int i = 0 ; i<  10; i+=32 )
          {
              TextureManager::Instance()->DrawPoint(APP->GetRenderer(),j,i,Colour_lime);
              SDL_FRect bb = {j,i,16,32};
              SDL_Rect aaa=  Anim.GetCurrentTile();
    //    TextureManager::Instance()->SDLDraw(APP->GetRenderer(),"walking",&aaa,&bbb,0,NULL,SDL_FLIP_NONE);

              TextureManager::Instance()->drawTestTexture(APP->GetRenderer(),"ob");
              TextureManager::Instance()->drawTestTexture(APP->GetRenderer(),"ob2");
    //    TextureManager::Instance()->drawTestTexture(APP->GetRenderer(),"BackGround1");

              SDL_FRect desrect = {MOUSEPOSITION.x-32+j,MOUSEPOSITION.y-32+i,16,32};
              SDL_Rect SpriteRect =  Anim.GetCurrentTile();
              TextureManager::Instance()->Draw(APP->GetRenderer(),"ob3",SpriteRect,desrect,0,NULL,SDL_FLIP_NONE);
              TextureManager::Instance()->Draw(APP->GetRenderer(),"ob4",SpriteRect,desrect,0,NULL,SDL_FLIP_NONE);
          }
          */
 SDL_Rect Shape[] = {{0,0,16,16},{16,0,16,16},{32,0,16,16},{48,0,16,16},{64,0,16,16},{80,0,16,16}};
              TextureManager::Instance()->Draw(APP->GetRenderer(),"Shapes", Shape[0],{0,0,16,16},0,NULL,SDL_FLIP_NONE);
              TextureManager::Instance()->Draw(APP->GetRenderer(),"Shapes", Shape[1],{16,0,16,16},0,NULL,SDL_FLIP_NONE);
              TextureManager::Instance()->Draw(APP->GetRenderer(),"Shapes", Shape[2],{32,0,16,16},0,NULL,SDL_FLIP_NONE);
              TextureManager::Instance()->Draw(APP->GetRenderer(),"Shapes", Shape[5],{48,0,16,16},0,NULL,SDL_FLIP_NONE);
              TextureManager::Instance()->Draw(APP->GetRenderer(),"Shapes", Shape[3],{64,0,16,16},0,NULL,SDL_FLIP_NONE);
               for(int j = 0 ; j <320; j+=32 )

{

              TextureManager::Instance()->Draw(APP->GetRenderer(),"Tile_Floor_Wood",{0,0,32,32}, {32+j,200,32,32},0,NULL,SDL_FLIP_NONE);
              TextureManager::Instance()->SetBlendMode("Tile_Floor_Wood",SDL_BLENDMODE_ADD);
              TextureManager::Instance()->Draw(APP->GetRenderer(),"Tile_Floor_Wood",{32,0,32,32}, {32+j,216,32,32},0,NULL,SDL_FLIP_NONE);
}
 std::cout << Shape[0].w << "\n";
};


void TestState31::Update(float dt)
{
    if(m_clicked)
    {
        if(m_gameObects.empty())
        {

            m_gameObects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Ball"));
            m_gameObects.back()->Load("FileName_BreakOut_Ball.txt");
            m_gameObects.back()->GetPosition() = vec2f(MOUSEPOSITION);
//            dynamic_cast<SDLGameObject*>(m_gameObects.back())->GetAcceleration() = vec2f(0,0);
//            dynamic_cast<SDLGameObject*>(m_gameObects.back())->GetVelocity() = vec2f(0,0);
//            dynamic_cast<SDLGameObject*>(m_gameObects.back())->GetAngle() = 0;
        }
        for(int i = 0 ; i < m_gameObects.size(); i++ )

            if  (vec2f::Dist(m_gameObects.back()->GetPosition(),MOUSEPOSITION)>48)
            {

                m_gameObects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Ball"));
                m_gameObects.back()->Load("FileName_BreakOut_Ball.txt");
                m_gameObects.back()->GetPosition() = vec2f(MOUSEPOSITION);
//                dynamic_cast<SDLGameObject*>(m_gameObects.back())->GetAcceleration() = vec2f(0,0);
//                dynamic_cast<SDLGameObject*>(m_gameObects.back())->GetVelocity() = vec2f(0,0);
//                dynamic_cast<SDLGameObject*>(m_gameObects.back())->GetAngle() = 0;
            }

//m_gameObects.push_back(GameObjectFactory::Instance()->Create(""))
    }



    if(!m_gameObects.empty())
        for(int i = 0 ; i < m_gameObects.size(); i++ )
        {
            if(m_gameObects[i]->GetPosition().x < 0 || m_gameObects[i]->GetPosition().x > 640)
                dynamic_cast<GameObject_Ball*>(m_gameObects[i])->FlipXspeed();
            if(m_gameObects[i]->GetPosition().y < 0 || m_gameObects[i]->GetPosition().y > 360)
                dynamic_cast<GameObject_Ball*>(m_gameObects[i])->FlipYspeed();

            m_gameObects[i]->Update(dt);
        }
    //Application::Instance()->GetCamera().Move(vec2f(dt *(float)60,0));
    /**<
      for(int i = 0 ; i < m_gameObects.size(); i++ )

              for(int j = i ; j< m_gameObects.size(); j++ )

                if  (vec2f::Dist(m_gameObects[i]->GetPosition(),m_gameObects[j]->GetPosition())<32)
                {
                    dynamic_cast<SDLGameObject*>(m_gameObects[i])->GetAcceleration() = vec2f(0,0);
                    dynamic_cast<SDLGameObject*>(m_gameObects[i])->GetVelocity() = vec2f(0,0);
                    dynamic_cast<SDLGameObject*>(m_gameObects[i])->GetAngle() = 0;
                } */

    m_scrollingBoarderOffset -= dt * (float)m_scrollingspeed;
    //  std::cout << dt * (float)m_scrollingspeed<< "\n";

    if( m_scrollingBoarderOffset < -textureManager->getTextureMap()["BackGround1"]->GetWidth())

    {
        m_scrollingBoarderOffset = 0;
    }

    for(int i = 0 ; i < m_gameobjects.size(); i+=1 )
    {

        m_gameobjects[i]->Update(dt);
        Anim2.Update(dt);
        Anim.Update(dt);
        Anim3.Update(dt);

    }
    if(m_gameobjects.back()->GetPosition().y < CAMCENTRE.y )
    {


        m_gameobjects.back()->Collision();
//dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetAcceleration() = vec2f(1,1);
//dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetRotation() = vec2f(0,0);

    }
//    std::cout << GetRandomNumber() % 9 << "\n";

//std::cout <<  <<"\n";

};
bool TestState31::OnEnter()
{
    TextureManager::Instance()->Load("Img/Test2.png","Test2",Colour_white,APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Ani_test.png","Ani_test",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/ob4.png","ob4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/ob3.png","ob3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/BackGround1.png","BackGround1",APP->GetRenderer());


    Anim2 = Animation(vec2f(256,16),16,16/(float)60,ANIMATION_HORIZONTAL);
    Anim = Animation(vec2f(256,16),16,16/(float)60,ANIMATION_HORIZONTAL);
    Anim3 = Animation(vec2f(256,16),16,16/(float)60,ANIMATION_HORIZONTAL);
    TextureManager::Instance()->Load("Img/ob.png","ob",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/ob2.png","ob2",APP->GetRenderer());
//    TextureManager::Instance()->SetAhpla("ob",125);
//    TextureManager::Instance()->SetAhpla("ob2",125);
    TextureManager::Instance()->SetBlendMode("ob",SDL_BLENDMODE_MOD);
    TextureManager::Instance()->SetBlendMode("ob2",SDL_BLENDMODE_MUL);
    TextureManager::Instance()->SetBlendMode("ob3",SDL_BLENDMODE_MOD);
    TextureManager::Instance()->SetBlendMode("ob4",SDL_BLENDMODE_ADD);
    vec2f uint = vec2f(CAMRECT.w,CAMRECT.h);
    uint.Normalise();
    for(int j = 0 ; j < 1; j++ )
    {

        m_gameobjects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Block"));
        m_gameobjects.back()->Load("FileName_BreakOut_Block.txt");
        m_gameobjects.back()->GetPosition() = vec2f(CAMCENTRE.x,CAMCENTRE.y+20);
        dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetAcceleration() = uint;
        dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetVelocity() = uint;
        dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetAcceleration() = vec2f();
        dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetVelocity() = vec2f();
    }
    // Application::Instance()->GetCamera().SetPos(vec2f(0,0));
//    for(int j = 0 ; j < CAMRECT.w; j+=16 )
//        for(int i = 0 ; i <  CAMRECT.h; i+=16 )
//        {
//            m_gameobjects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Ball"));
//            m_gameobjects.back()->Load("FileName_BreakOut_Ball.txt");
//            //   m_gameobjects.back()->GetPosition() = vec2f( GetRandomNumber() % CAMRECT.w,GetRandomNumber() % CAMRECT.h);
//            m_gameobjects.back()->GetPosition() = vec2f( j,i);
//////
//            //      dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetAcceleration() = vec2f();
//            //          dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetVelocity() = vec2f();
//            //   dynamic_cast<SDLGameObject*>(m_gameobjects.back())->GetCentre() = vec2f();
//        }
//Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOWEVENT_HIDDEN)
//InputHandler::Instance()->ShowMouse(false);
//Application::Instance()->GetCamera().SetPos(vec2f());
//      SDL_Rect m_viewport =  APP->GetCamera().GetRect();
//      std::cout << m_viewport.x<< "\n";
//      std::cout << m_viewport.y<<"\n";
//      std::cout << m_viewport.w<<"\n";
//      std::cout << m_viewport.h  <<"\n";
//SDL_RenderIsClipEnabled(APP->GetRenderer());
////SDL_RenderSetClipRect(APP->GetRenderer(),&m_viewport);
//SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//  SDL_RenderSetLogicalSize(APP->GetRenderer(),1920,1080);

//
//   SDL_RenderSetScale(APP->GetRenderer(),3,3);

    return true;
};

bool TestState31::onExit() {};
void TestState31::resume() {};

void TestState31::HandleEvent(SDL_Event &e)
{
    for(int i = 0 ; i < m_gameobjects.size(); i+=1 ) m_gameobjects[i]->HandleEvent(e);


    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
    {
        m_scrollingspeed++;
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
    {
        m_scrollingspeed--;
    }

    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
        m_clicked = true;
    if(!InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
        m_clicked = false;

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_G))
    {
        //std::cout << APP->GetWindow()->GetDisplayBounds().w << " / " << APP->GetWindow()->GetDisplayBounds().h << " : " << APP->GetWindow()->GetWidget()->GetTitle() <<  "\n";
        APP->GetWindow()->GetWidget()->SetVisable(false);

    }
    else
    {
        APP->GetWindow()->GetWidget()->SetVisable(true);
    }
    if(!m_gameObects.empty())
        for(int i = 0; i< m_gameObects.size(); i++)
            m_gameObects[i]->HandleEvent(e);
    //APP->GetWindow()->GetWidget()->Find("WindowImp")->SetVisable(true);
};
