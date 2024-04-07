#include "TestState34.h"

TestState34::TestState34()
{
    //ctor
}

TestState34::~TestState34()
{
    //dtor
}

void TestState34::Render()
{
    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),1,1,Colour_black);
//    printf("\n");


//vec2f p = vec2f(MOUSEPOSITION);
//SDL_FRect pr = {200,0,200,200};
//
//if(InputHandler::Instance()->HasPointinRect(p,pr))
//{
//        TextureManager::Instance()->DrawRect(APP->GetRenderer(),pr,Colour_GUIForeGround,true);
//}else
//        TextureManager::Instance()->DrawRect(APP->GetRenderer(),pr,Colour_blanchedalmond,true);


    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x+x,WindowOrigin.y,Colour_darkseagreen,16,true);
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),WindowOrigin.x+x,WindowOrigin.y,WindowOrigin.x,WindowOrigin.y,Colour_red);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin+MOUSEPOSITION,Colour_blanchedalmond);

    for(int i = 0 ; i < t1.size(); i++)
//GetSDLRectCenter
    {
        vec2f s2 = vec2f(GetSDLRectCenter(t1[i]));
//    vec2f s3 = vec2f(8,8);
//s3.GetRotation(framecount);
// TextureManager::Instance()->DrawRect(APP->GetRenderer(),s2,Colour_blanchedalmond,false);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),s2,vec2f(8,0),Colour_red);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),s2,vec2f(-8,0),Colour_blue);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),s2,vec2f(0,-8),Colour_green);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),s2,vec2f(0,8),Colour_blanchedalmond);
    }

    std::cout  << x << "\n";
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f::projB(vec2f(MOUSEPOSITION.x,WindowOrigin.y),MOUSEPOSITION),Colour_green);
// for(int i = 0; i < mrects.size(); i++)
// {
//     if(lat)
// }
    for(int i = 0 ; i < 640; i++)
    {
//
//float x =GetSimpleHarmonicMotion(640/2,APP->GetGameTime(),APP->GetDeltaTime());
// TextureManager::Instance()->DrawPoint(APP->GetRenderer(),i,x + WindowOrigin.y,Colour_red);
    }
// TextureManager::Instance()->DrawRect(APP->GetRenderer(),MOUSEPOSITION,8,8,Colour_darkseagreen,true);
//
// TextureManager::Instance()->DrawRects(APP->GetRenderer(),&mrects[0],mrects.size(), Colour_silver,false);
// TextureManager::Instance()->DrawRects(APP->GetRenderer(),&t3[0],t3.size(), Colour_red,false);
// TextureManager::Instance()->DrawRects(APP->GetRenderer(),&t2[0],t2.size(), Colour_green,false);
    TextureManager::Instance()->DrawRects(APP->GetRenderer(),&t1[0],t1.size(), Colour_green,false);

    TextureManager::Instance()->drawSprite("TS_ALPHA",0,0,640,360,APP->GetRenderer(),SDL_FLIP_NONE);
    SDL_FRect re = {0,0,32,32};
    for(int i = 0; i < WindowOrigin.y*2; i+=32)
    TextureManager::Instance()->DrawTileHorizontal(APP->GetRenderer(),"blank3",32,640,0,i,&re,0,NULL,SDL_FLIP_NONE);
re = {0,0,64,32};
    TextureManager::Instance()->DrawTileHorizontal(APP->GetRenderer(),"platformTile",re.w,640,0,360-re.h,&re,0,NULL,SDL_FLIP_NONE);
   // TextureManager::Instance()->drawSprite("TS_ALPHA",0,0,640,360,APP->GetRenderer(),SDL_FLIP_NONE);
//LTexture atext = LTexture();
//atext.CreateBlankTexture(APP->GetRenderer(),640,360);

//atext.Render(APP->GetRenderer(),232,227);
vec2f  ad= vec2f(WindowRect.w,WindowRect.h).Normalise();

    vec2f sss = vec2f::Lerp(vec2f(),vec2f(640,0),APP->GetDeltaTime());
    std::stringstream ww;
    ww  << ad << " ";
     TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),ww.str(),vec2f(WindowOrigin.x,WindowOrigin.y*2- FontManager::Instance()->GetFontSize("CONSOLA")));
    ww.clear();

    TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(232,227),vec2f(10,10),Colour_black);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),MOUSEPOSITION,WindowOrigin,Colour_black);

    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,-vec2f(320,0).GetNormalise()*320,Colour_black);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,-vec2f(320,0).GetNormalise()*((0.5)*320),Colour_black);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,-vec2f(320,0).GetNormalise()*((0.1)*320),Colour_black);

        TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x,WindowOrigin.y,Colour_black,vec2f::Dist(MOUSEPOSITION,WindowOrigin),false);


//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin+ab,a8.GetRotation(60),Colour_green);
//            TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x+ab.x,WindowOrigin.y+ab.y,Colour_cornflowerblue,16,true);

    TextureManager::Instance()->drawSprite("32x32",0,0,32,32,APP->GetRenderer(),SDL_FLIP_NONE);

    vec2f m = alignToVec2Position(MOUSEPOSITION,16);

   // TextureManager::Instance()->drawSprite("blank2",m.x,m.y,32,32,APP->GetRenderer(),SDL_FLIP_NONE);

 TextureManager::Instance()->DrawVector(APP->GetRenderer(),m_pos,m_vel,Colour_red);
 vec2f pv = m_pos+m_vel;

    vec2f ab = WindowOrigin-MOUSEPOSITION;
    vec2f ab2= ab;

    ab2.Ortho();
    vec2f ab3 = ab-ab2;
    ab3.Ortho();


    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,-WindowOrigin+ab,Colour_blue);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin+ab,ab2,Colour_green);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin+ab,ab2-ab,Colour_red);

// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,m_vel.GetNormalise()*64,Colour_darkgreen);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,m_acc.GetNormalise()*64,Colour_blue);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,m_pos.GetNormalise()*64,Colour_darksalmon);

 TextureManager::Instance()->DrawVector(APP->GetRenderer(),m_pos,pv.GetNormalise()*64,Colour_darkgreen);
 TextureManager::Instance()->DrawVector(APP->GetRenderer(),pv,m_acc.GetNormalise()*64,Colour_darkgreen);
 TextureManager::Instance()->DrawVector(APP->GetRenderer(),m,m_vel.GetNormalise()*64,Colour_darkgreen);
 TextureManager::Instance()->DrawVector(APP->GetRenderer(),m,m_acc.GetNormalise()*64,Colour_blue);
 TextureManager::Instance()->DrawVector(APP->GetRenderer(),m,m_pos.GetNormalise()*64,Colour_darksalmon);
// TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),WindowOrigin+ab-ab2,WindowOrigin-ab,WindowOrigin-ab3,Colour_green);


    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION-WindowOrigin,Colour_white);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),MOUSEPOSITION,MOUSEPOSITION+vec2f(0,WindowOrigin.y-MOUSEPOSITION.y),Colour_green);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(-0.3,-0.3),vec2f(0.3,0.3),WindowOrigin*2,Colour_darksalmon);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0.3,-0.3),vec2f(-0.3,0.3),WindowOrigin*2,Colour_darksalmon);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0,-0.3),vec2f(0,0.3),WindowOrigin*2,Colour_darksalmon);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0.3,0),vec2f(0.3,0.3),WindowOrigin*2,Colour_darksalmon);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f(64,64).GetRotation(-90),Colour_royalblue);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f(64,64).GetRotation(-45),Colour_aquamarine);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f(64,64).GetRotation(45),Colour_green);
 Application::Instance()->GetAspectRatio();


    for (int i = 0; i < m_e.size(); i++)
    {
//   float a =GetRandomNumber() % 640;
//   float b =GetRandomNumber() % 360;

        ParticleEmitter & ee  = *m_e[i];
//        TextureManager::Instance()->Drawcircle(APP->GetRenderer(),ee.m_pos.x,ee.m_pos.y, ee.m_c,16,true);
//
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ee.m_pos,ee.m_vel,Colour_blue);
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ee.m_pos+ee.m_vel,ee.m_acc.GetOrtho(),Colour_red);
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ee.m_pos,ee.m_vel+ee.m_acc.GetOrtho(),Colour_green);
        ee.render(APP->GetRenderer(),"par_effect");
    }

}
void TestState34::Update(float dt)
{
    x = GetSimpleHarmonicMotion(64,framecount,100);
    vec2f sss = vec2f::Lerp(vec2f(),vec2f(CAMRECT.w,0),dt);
    int a = std::atoi("1");

    framecount+=1;
    // std::setprecision(1);
    // std::cout  << (double)dt;
    for (int i = 0; i < m_e.size(); i++)
    {
        m_e[i]->Update(dt);
//   float a =GetRandomNumber() % 640;
//   float b =GetRandomNumber() % 360;
    };Application::Instance()->GetAspectRatio();


    for (int i = 0; i < m_e.size(); i++)
    {
//   float a =GetRandomNumber() % 640;
//   float b =GetRandomNumber() % 360;

        ParticleEmitter & ee  = *m_e[i];
//        TextureManager::Instance()->Drawcircle(APP->GetRenderer(),ee.m_pos.x,ee.m_pos.y, ee.m_c,16,true);
//
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ee.m_pos,ee.m_vel,Colour_blue);
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ee.m_pos+ee.m_vel,ee.m_acc.GetOrtho(),Colour_red);
//        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ee.m_pos,ee.m_vel+ee.m_acc.GetOrtho(),Colour_green);
        ee.render(APP->GetRenderer(),"par_effect");
    }


//    vec2f ab = WindowOrigin-MOUSEPOSITION;
//    vec2f ab2= ab;
//
//    ab2.Ortho();
//    vec2f ab3 = ab-ab2;
//    ab3.Ortho();
//
//
//    m_acc = ab3;
//   m_acc.Normalise();
 // m_acc*= vec2f::Dist(MOUSEPOSITION,WindowOrigin);
 m_acc = vec2f(1,1);
m_vel += m_acc * dt;
m_vel.Limit(15);
m_pos += m_vel* dt;
}

bool TestState34::OnEnter()
{
 m_pos = WindowOrigin;

    mrects = MakeGrid(0,0,WindowOrigin.x*2/(float)8,WindowOrigin.y*24/(float)24,24);
    Quad qt;

    t1 = MakeGrid(0,0,WindowOrigin.x*2/(float)16,WindowOrigin.y*2/(float)16,16);
    t2 =  MakeGrid(0,0,WindowOrigin.x*2/(float)16,WindowOrigin.y*2/(float)16,16);
    t3 = MakeGrid(0,0,WindowOrigin.x*2/(float)16,WindowOrigin.y*2/(float)16,16);

     TextureManager::Instance()->SetAhpla("blank3",128);
    TextureManager::Instance()->SetColorMod("blank3",Colour_red);

//
//    SDL_Rect www = WindowRect;
//        SDL_RenderSetViewport(APP->GetRenderer(),&www);
//SDL_SetWindowPosition(APP->GetWindow()->GetWindow(),0,0);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
////    SDL_Rect ss = WindowRect;
//SDL_RenderSetClipRect(APP->GetRenderer(),&ss);
//        Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
    return true;



};
bool TestState34::onExit() {};
void TestState34::resume() {};
void TestState34::HandleEvent(SDL_Event &e )
{


        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F1))
        {

            Application::Instance()->GetStateMachine()->PushState(stateFactory->Create("TestState35"));

        return;
        }
    if(!isdown)
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
            isdown = true;


   vec2f  w =vec2f(0,0);
 vec2f acc;
if(isdown)
    if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        for (int i = 0; i < 360; i++)
        {
//           w+=  vec2f(i,0);
//w.Normalise();
// //         w.Rotate(360/64);
//           acc+= vec2f(1,0);
//            acc.Rotate(i);
            //acc.Rotate(GetRandomNumber()%360);
//      vec2f(GetRandomNumber()%640,GetRandomNumber()%360)
// SDL_Color({128/(float)16*i,255/(float)16*i,255/(float)16*i,255/(float)16*i})
            m_e.push_back(new ParticleEmitter(MOUSEPOSITION,vec2f(0,0),WindowOrigin,acc,16,Colour_white,255,1, 255, 0.9 ,1));
            isdown = false;
        }


}
