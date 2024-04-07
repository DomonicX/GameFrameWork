#include "StateSnakeGame.h"

StateSnakeGame::StateSnakeGame()
{
    //ctor
}

StateSnakeGame::~StateSnakeGame()
{
    //dtor
}

void StateSnakeGame::Render()
{
//
//    vec2f a = vec2f(MOUSEPOSITION);
//    vec2f b = vec2f(1,1);
//        vec2f bc = vec2f(-1,1);
//    vec2f ba = vec2f::projB(a,b);
//    float c = vec2f::Dot(a,b);
//
//
////    std::cout  << ba*a << "\n"<< "\n";
////    std::cout  << MOUSEPOSITION << "\n"<< "\n";
////    std::cout  << std::acos(vec2f::Dot(b,bc)/(float)(b.Length()*bc.Length()))*180/M_PI << "\n"<< "\n";
////    std::cout  << vec2f::Dot(b,bc)/(float)(b.Length()*bc.Length()) << "\n"<< "\n";
//

//    auto *window = APP->GetWindow()->GetWidget()->Find("Window");
//
//    TextureManager::Instance()->DrawRects(APP->GetRenderer(),&rects[0],rects.size(),Colour_olive,false);
//
//    {
////    {
////        std::vector<SDL_Rect> xx = MakeGrid(0,0,WindowWidth/8,WindowHeight/8,8);
////        TextureManager::Instance()->DrawRects(APP->GetRenderer(),&xx[0],xx.size(), Colour_silver,false);
////    }
TextureManager::Instance()->DrawGrid(0,0,WindowWidth/16,WindowHeight/16,16,Colour_chocolate,APP->GetRenderer());
//        {
//            std::stringstream ww;
//
//            ww <<    " Points " << m_fruitCounter << " Lives " << m_points << " raito " << d << " " << vec2f(16,9).GetNormalise();
//
//            isTouching ? ww << "touching" : ww<< "not Touching" ;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),WindowOrigin.x,0,Colour_white,Align_Center);
//        }
//        {
//            std::stringstream ww;
//            ww << "Width " <<   window->GetHitBox().w;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*3,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//           ww << "Height " <<   window->GetHitBox().h;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*4,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww << "AspectRaito " <<  window->GetHitBox().w/(float)window->GetHitBox().h;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*5,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww << "time " << gametimercounter;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*6,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww << "CameraSize " << Application::Instance()->GetCamera().GetSize();
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*7,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            dirc ?
//            ww << "Left" : ww << "Right";
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*8,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww <<pos;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*9,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww <<s.GetTicks()/1000;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*10,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww <<m_dt*60;
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h,Colour_white,Align_Left);
//        }
//        {
//            std::stringstream ww;
//            ww <<APP->GetFps();
//            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*12,Colour_white,Align_Left);
//        }
float w =vec2f::vectorAngle(vec2f(WindowOrigin),vec2f(MOUSEPOSITION));
        {

       float x =  WindowOrigin.x - MOUSEPOSITION.x;
      float y  =  WindowOrigin.y -   MOUSEPOSITION.y;
 vec2f aa, bb  =  vec2f(0,0);
 aa = vec2f(1,1);
 bb = vec2f(1,1);
 aa.Rotate(M_PI/2);

TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,aa,Colour_green);
 //bb.Rotate(-M_PI);

//      std::cout <<  vec2f::DegToRad(45) << "\n";

// bb.Rotate(90);
            std::stringstream ww;
            if(vec2f::isPerpendicular(aa,bb))
          ww << "isPerpendicular"<<"\n";

          ww << aa<<"      ";
//          ww << bb<<"      ";
  ww << w<<"\n";
  //          ww << std::atan2(y,x)*180/M_PI <<"\n";
            TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),0,FontManager::Instance()->QueryText("A","OpenSans-Regular").h*12,Colour_white,Align_Left);
        }
    SDL_Rect src = {0,0,320,180};
        SDL_Rect srsc = {WindowOrigin.x-320/2,WindowOrigin.y-180,320,180};
////
//
    SDL_RenderCopyEx(APP->GetRenderer(),textureManager->getTextureMap()["SnakeGameBackGround"]->GetSDLTexture(),&src,&srsc,w,NULL,SDL_FLIP_NONE);
////
//         LText t;
//        t.SetTextColour(Colour_burlywood);
//        t.ChangeText("sds",FontManager::Instance()->GetFont("OpenSans-Regular"),APP->GetRenderer());
//        t.LoadFromRenderedText(APP->GetRenderer(),WindowOrigin.x,WindowOrigin.y);
vec2f aa = vec2f(WindowOrigin+- MOUSEPOSITION);
aa.Normalise();
aa *= -vec2f::Dist(WindowOrigin,MOUSEPOSITION);
aa += WindowOrigin;
        TextureManager::Instance()->DrawSqaure(APP->GetRenderer(),WindowOrigin.x,WindowOrigin.y,32,Colour_darkgoldenrod,false);

TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0,0),aa,Colour_green);
TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0,0),aa,Colour_green);
//std::cout  <<  vec2f::vectorAngle(vec2f(aa.y,0),aa) << " \n";
TextureManager::Instance()->DrawSineWave(MOUSEPOSITION,300,30,0.5,1,0,APP->GetRenderer());
 vec2f ba = vec2f::Proj(vec2f(0,aa.y),aa);

//
//line l = line({vec2f(1,0),vec2f(10,10)});
//vec2f v = vec2f::Lerp(l.Min,l.Max,0.5);
//
////v =  Lerp(l.Min,l.Max,0.5); = [0][5]
//
//std::cout  <<  v << " \n";
//
//TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(WindowOrigin.y,0),ba,Colour_green);


//        TextureManager::Instance()->DrawSqaure(APP->GetRenderer(),m_fruitPos.x+8,m_fruitPos.y+8,8,Colour_black,true);
//        vec2f st(rects[300].x,rects[100].y);
//        std::vector<SDL_Rect> xx = MakeGrid(0,0,WindowWidth/64,WindowHeight/64,64);
////
//    }
//    TextureManager::Instance()->SetColour(Colour_blue,APP->GetRenderer());
//    if(!tail.empty())
//    {
//        for(int i = 0; i < tail.size(); i++)
//        {
//
//            SDL_FRect rret = SDL_FRect({tail[i].x,tail[i].y, 16,16});
//
//            TextureManager::Instance()->DrawRect(APP->GetRenderer(),rret, Colour_brown,true);
//        }
//
//        SDL_FRect rret = SDL_FRect({tail[0].x,tail[0].y, 16,16});
//
//        TextureManager::Instance()->DrawRect(APP->GetRenderer(),rret, Colour_green,true);
////        TextureManager::Instance()->DrawRects(APP->GetRenderer(),&tail[0],tail.size(), Colour_silver,true);
//    }
//    SDL_FRect rret = SDL_FRect({pos.x,pos.y, 16,16});
//
//    TextureManager::Instance()->DrawRect(APP->GetRenderer(),rret, Colour_red,true);
//    ParticleSystem P = ParticleSystem(vec2f(),100);
//    P.Update(m_dt);
//    P.Render();

//// TextureManager::Instance()->DrawVectorArrow(APP->GetRenderer(),WindowOrigin,WindowOrigin-MOUSEPOSITION,Colour_goldenrod);

//TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION,Colour_goldenrod);
vec2f aaa = vec2f( MOUSEPOSITION-WindowOrigin);
aaa.Normalise();
aaa *= vec2f::Dist(WindowOrigin,MOUSEPOSITION);
aaa += WindowOrigin;


TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,aaa,Colour_green);
TextureManager::Instance()->DrawLine(APP->GetRenderer(),line({WindowOrigin,WindowOrigin+vec2f(WindowOrigin.x,0)}),Colour_green);
//
////TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),WindowOrigin,vec2f(MOUSEPOSITION.x,WindowOrigin.y),Colour_goldenrod);
//
//// std::cout  <<  vec2f::vectorAngle(MOUSEPOSITION,WindowOrigin-vec2f(MOUSEPOSITION.x,WindowOrigin.y)) << "\n"<< "\n";
// std::cout  <<  vec2f::vectorAngle(aa,WindowOrigin) << "\n"<< "\n";
//vec2f aa = vec2f( WindowOrigin+-MOUSEPOSITION);
//aa.Normalise();
//aa *= vec2f::Dist(WindowOrigin,MOUSEPOSITION);
//aa += WindowOrigin;
//
//vec2f aaa = vec2f( WindowOrigin.x,WindowOrigin.y);
//line ll = line{MOUSEPOSITION,aa};
//line l = line{aaa,WindowOrigin};
//
////TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION,Colour_green);
//
//TextureManager::Instance()->DrawLine(APP->GetRenderer(),l,Colour_blue);
//TextureManager::Instance()->DrawLine(APP->GetRenderer(),ll,Colour_green);
//
////TextureManager::Instance()->DrawVectorArrow2(APP->GetRenderer(),WindowOrigin,vec2f(MOUSEPOSITION.x,WindowOrigin.y),Colour_goldenrod);
//
//// std::cout  <<  vec2f::vectorAngle(MOUSEPOSITION,WindowOrigin-vec2f(MOUSEPOSITION.x,WindowOrigin.y)) << "\n"<< "\n";
// std::cout  <<  vec2f::vectorAngle(aa,aaa) << " \n";
//    SDL_FRect rret = SDL_FRect({WindowOrigin.x/2,WindowOrigin.y/2, WindowOrigin.x,WindowOrigin.y});
//
//    TextureManager::Instance()->DrawRect(APP->GetRenderer(),rret, Colour_red,true);

}
void StateSnakeGame::Update()
{
    m_dt = APP->GetDeltaTime();
    if(m_startGame)
    {
        SDL_Rect cam = APP->GetCamera().GetRect();
//    if(s.GetTicks()/1000 == gametimercounter)
        gametimercounter =s.GetTicks()/1000;
//

        if(oldTime + frameRate < s.GetTicks())
        {
            pos+=acc;
            oldTime = s.GetTicks();
            if(acc.x>0)
                dirc =  m_left;
            if(acc.x<0)
                dirc = m_right;
            if(pos.y<cam.y)
            {
                pos.y = cam.y+cam.h-4;
            }
            else if(pos.x<cam.x)
            {
                pos.x = cam.x+cam.w-16;
            }
            else if(pos.x>=cam.x+cam.w)
            {
                pos.x = cam.x;
            }
            else if(pos.y>=cam.y+cam.h)
            {
                pos.y = cam.y;
            }
            if(pos.Dist(m_fruitPos)<=1)
            {

                tail.push_back(pos);
                pos = m_fruitPos;
                float rando = 0;
                rando =  GetRandomNumber()%rects.size();
                m_fruitCounter++;
                m_fruitPos = vec2f(rects[rando].x,rects[rando].y);
            }
            if(!tail.empty())
                tail[0] = pos;

            if(!tail.empty())
                for(int i = 0; i < tail.size()-1; i++)
                {
                    std::swap(tail[i],tail[i+1]);
                }
        }

    }
}
bool StateSnakeGame::OnEnter()
{

    InputHandler::Instance()->registerNewEventcode("StartGame");

    TextureManager::Instance()->Load("Img/SnakeGameBackGround.png","SnakeGameBackGround",APP->GetRenderer());

    InputHandler::Instance()->pushEvent(0,"StartGame","StartGame");



    frameRate = 100;
    SDL_Rect cam = APP->GetCamera().GetRect();

     for(int i = 0 ; i <cam.h; i+=16)
       for(int j = 0 ; j< cam.w; j+=16)
          rects.push_back(SDL_Rect({ cam.x+j, cam.y+i,16,16}));

    points.push_back(vec2f(WindowOrigin));
    s.Start();
    Maxspeed = 16*(WindowWidth/640);
    pos = vec2f(cam.x+16*4,cam.y+16*4);
    v = WindowOrigin;



    d = (WindowOrigin*2).GetNormalise()*Maxspeed;

//d.Limit(10);
//        APP->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);

    acc=vec2f(16,0);

    m_spawnFruit = true;

    float rando = GetRandomNumber()%rects.size();
    std::cout << rando << "\n\n";
    m_fruitPos = vec2f(rects[rando].x,rects[rando].y);
    rando = GetRandomNumber()%rects.size();
    m_fruitPos = vec2f(rects[rando].x,rects[rando].y);
    m_fruitCounter = 0;
////
//  SDL_Rect m_viewport =      Application::Instance()->GetCamera().GetRect();
//////SDL_RenderIsClipEnabled(App->GetRenderer());
//////SDL_RenderSetIntegerScale(App->GetRenderer(),SDL_TRUE);
//////
//  SDL_RenderSetLogicalSize(    Application::Instance()->GetRenderer(),m_viewport.w,m_viewport.h);
////SDL_RenderSetClipRect(Application::Instance()->GetRenderer(),&m_viewport);
//   SDL_RenderSetScale(    Application::Instance()->GetRenderer(),2,2);
    return true;
}
bool StateSnakeGame::onExit() {}
void StateSnakeGame::resume() {}
void StateSnakeGame::HandleEvent(SDL_Event &e )
{


    if(e.type == SDL_USEREVENT)
        if(e.user.code == InputHandler::Instance()->GetEventCode("StartGame"))
        {
            m_startGame = true;
            delete e.user.data1;
            delete e.user.data2;
        }


//    acc = vec2f(0,0);
    if(InputHandler::Instance()->isKeyDown(SDL_Scancode::SDL_SCANCODE_W))
    {
        acc=vec2f(0,-16);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_Scancode::SDL_SCANCODE_A))
    {
        acc=vec2f(-16,0);

    }
    if(InputHandler::Instance()->isKeyDown(SDL_Scancode::SDL_SCANCODE_S))
    {

        acc=vec2f(0,16);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_Scancode::SDL_SCANCODE_D))
    {
        acc=vec2f(16,0);

    }

}


