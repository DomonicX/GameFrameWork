#include "TestState29.h"

TestState29::TestState29()
{
    //ctor
}

TestState29::~TestState29()
{
    //dtor
}

void TestState29::Render()
{

    vec2f a = WindowOrigin-MOUSEPOSITION;

    a.Normalise();
//a.Ortho();
    a *= vec2f::Dist(MOUSEPOSITION,WindowOrigin);
    a+=WindowOrigin;
// TextureManager::Instance()->DrawVectorArrow(APP->GetRenderer(),WindowOrigin,WindowOrigin-MOUSEPOSITION,Colour_goldenrod);

//    std::cout << vec2f::Dot(WindowOrigin.GetNormalise(),MOUSEPOSITION.GetNormalise()) << "\n";


// TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),WindowOrigin,a,Colour_goldenrod);
//
//    TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION,Colour_goldenrod);
// TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),MOUSEPOSITION,vec2f(0,0),Colour_goldenrod);
// TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),MOUSEPOSITION,WindowOrigin,Colour_goldenrod);
// TextureManager::Instance()->DrawVectorArrow(APP->GetRenderer(),WindowOrigin,WindowOrigin-MOUSEPOSITION,Colour_goldenrod);
    {
        std::stringstream ww;
        ww <<       s.GetTicks()/1000;//time;
        TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),WindowOrigin.x,0,Colour_green,Align_Center);

    }
    {
        std::stringstream ww;
        ww <<    vec2f::Dist(MOUSEPOSITION,WindowOrigin) << pos << vel << acc;

        TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),WindowOrigin.x,WindowOrigin.y,Colour_green,Align_Center);

    }
float disratio = WindowWidth/640;
    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),pos.x,pos.y,Colour_chartreuse,8*disratio,true);
    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),pos.x+vel.x,pos.y+vel.y,Colour_red);
    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),pos.x,pos.y,Colour_blue);
    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),oldpos.x,oldpos.y,Colour_yellow);

    LTexture sa;



sa.LoadFromRendered(APP->GetRenderer(),WindowWidth,WindowHeight);
sa.SetAlpha(125);
sa.SetColorMod(0,0,0);
sa.Render(APP->GetRenderer(),0,int(0),0,NULL);



}
void TestState29::Update()
{
    dt = APP->GetDeltaTime();
    oldpos = pos;

    vel += acc * dt;

    vel.Truncate(WindowWidth*0.1);
    pos += vel * dt*2;
   // friction = vel*0.9;
//    pos +=  vel;// - friction;

if(pos.Length()>=vec2f(WindowOrigin.x*2,WindowOrigin.y*2).Length())
{
if(time==0)
//  time =  s.GetTicks();
  time = s.GetTicks()/(float)1000;
vel = vec2f(0,0);
  vel -= acc *dt;
 pos = oldpos;
//vel = vec2f(0,0);

}
//    counter += 1;
//
//    fen = 1/(float)60;
//
//    time += dt*counter;
//    std::cout << fen*counter << "\n";

}
bool TestState29:: OnEnter()
{
    friction= vec2f(0,0);
    oldpos= vec2f(0,0);

    vec2f oM = vec2f(WindowOrigin.x*2,WindowOrigin.y*2);

    vec2f uintVec = oM.Normalise();

    float  WWidth = uintVec.Length();

float disratio = WindowWidth/640;
    acc = uintVec*WWidth*disratio;

    vel = vec2f(0,0);

    pos = vec2f(0,0);
    s.Start();


    return true;

}
bool TestState29::onExit() {}
void TestState29::resume() {}

void TestState29::HandleEvent(SDL_Event &e)
{
    if(INPUTHANDLER->GetMouseButtonState(mouse_Buttons::LEFT))
    {

    }
    if(INPUTHANDLER->isKeyDown(SDL_Scancode::SDL_SCANCODE_A))
    {

    vel = vec2f(0,0);
acc*=-1;
    }
}
