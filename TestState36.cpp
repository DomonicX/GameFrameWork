#include "TestState36.h"

TestState36::TestState36()
{
    //ctor
}

TestState36::~TestState36()
{
    //dtor
    for(int i = 0 ; i < (int)m_layers.size(); i++)
    {
        delete m_layers[i];
        m_layers.erase(m_layers.begin() + i);
    }
    m_layers.clear();
}

void  TestState36::Render(SDL_Renderer* r)
{

//  TextureManager::Instance()->drawSprite("BackGround3",0,0,640,360,r,SDL_FLIP_NONE);
    for(int i = 0 ; i < m_layers.size(); i++ )
//        m_layers[i]->Render(r,Application::Instance()->GetCamera().GetWorldPos().x,Application::Instance()->GetCamera().GetWorldPos().y);
        m_layers[i]->Render(r,-Application::Instance()->GetCamera().GetWorldPos().x,-Application::Instance()->GetCamera().GetWorldPos().y);
    for(int i = 0 ; i < m_gameObects.size(); i++ )
        m_gameObects[i]->Render(r,-APP->GetCamera().GetWorldPos().x,-APP->GetCamera().GetWorldPos().y);

    TextureManager::Instance()->DrawVector(r,Application::Instance()->GetCamera().GetCentre(),vec2f(16,0),Colour_red);
    TextureManager::Instance()->DrawVector(r,Application::Instance()->GetCamera().GetCentre(),vec2f(0,16),Colour_blue);


    std::string str=   dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetDir();
    std::string str2=  dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetState();


       // std::cout << "inc1 = " <<  Application::Instance()->GetCamera().GetWorldPos() << "\n";
    {
        std::stringstream ww;
        ww <<str << " " << str2;
        TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),ww.str(),CAMRECT.w/2,CAMRECT.h/2,Colour_yellow,Align_Center,16);

    }    for(int i = 0 ; i < m_collisons.size(); i++ )
    {
        TextureManager::Instance()->DrawRect(r,dynamic_cast<SDLGameObject*>(m_collisons[i])->GetSDLRect(),Colour_darkgreen,false);
    }

    ////    SDL_Rect SpriteRect =  ani.GetCurrentTile();
    ////    TextureManager::Instance()->Draw(APP->GetRenderer(),"lights",SpriteRect, {MOUSEPOSITION.x+16+16+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
    ////
    ////
    ////    for(int i = 0; i< 10 ; i++)
    ////    {
    ////
    ////        TextureManager::Instance()->DrawVector(r,WindowOrigin,p[i],Colour_darkmagenta);
    ////
    ////   // for(int j = 0; j< 10 ; j++)
    ////
    ////    //    TextureManager::Instance()->DrawVector(r,WindowOrigin+p[j],p[i],Colour_darkmagenta);
    ////   SDL_FRect aa = {WindowOrigin.x+p[i].x-21,WindowOrigin.y+p[i].y-8,42,16};
    ////   SDL_Rect bb = {0,0,42,16};
    ////SDL_FPoint dd = {21,16};
    ////   TextureManager::Instance()->SDLDraw(r,"lights",&bb,&aa, 90+vec2f::vectorAngle(WindowOrigin+p[i],vec2f(WindowOrigin+vec2f(1,0))),&dd,SDL_FLIP_VERTICAL);
    //////   TextureManager::Instance()->drawSprite("lights",WindowOrigin.x+p[i].x-21,WindowOrigin.y+p[i].y-8,42,16,r,SDL_FLIP_NONE);
    ////    }
    ////     TextureManager::Instance()->Drawcircle(r,WindowOrigin.x,WindowOrigin.y,Colour_red,128,false);
    ////       TextureManager::Instance()->DrawVector(r,WindowOrigin+p[0],vec2f(0,16),Colour_blanchedalmond);
    ////       TextureManager::Instance()->DrawVector(r,WindowOrigin+p[0],vec2f(WindowOrigin-p[0]-WindowOrigin).GetOrtho(),Colour_blanchedalmond);
    ////       TextureManager::Instance()->DrawVector(r,WindowOrigin,vec2f(128,0),Colour_blanchedalmond);
    ////
    ////       std::cout << vec2f::vectorAngle(WindowOrigin+p[0],vec2f(WindowOrigin+vec2f(1,0)))<<"\n";
    ////     TextureManager::Instance()->Drawcircle(r,WindowOrigin.x,WindowOrigin.y,Colour_red,64,true);
    ////     TextureManager::Instance()->Drawcircle(r,48+24,12+64,Colour_red,12,true);
    ////     TextureManager::Instance()->DrawRect(r,SDL_FRect{0,64,24,24},Colour_green,FALSE);
    //
    //
    //    vec2f m = MOUSEPOSITION;
    //    m =  alignToVec2Position(m+Application::Instance()->GetCamera().GetPos(),16);
    //
    //    TextureManager::Instance()->DrawRect(r,m,16,16,Colour_red);
    //    TextureManager::Instance()->DrawGrid(m.x,m.y,5,5,16,Colour_black,r);
    ////    TextureManager::Instance()->Drawcircle(r,m.x+8,m.y+8,Colour_black,8*3,true);
    //    for(int i = 0; i < m_circle.size(); i++)
    //
    //
    //        TextureManager::Instance()->Drawcircle(r,m_circle[i].x+8,m_circle[i].y+8,Colour_red,8,true);
    //
    //    for(int i = 0; i <120 ; i++)
    //        for(int j = 0; j < 67; j++)
    //        {
    ////            if( num[i][j])
    ////            {
    ////                TextureManager::Instance()->DrawPoint(r,i*16+4,j*16+5,Colour_gold);
    //////                TextureManager::Instance()->DrawPoint(r,i*16+7,j*16+7,Colour_pink);
    ////
    ////            }
    //        }
    //
    //TextureManager::Instance()->DrawRect(r,SDL_FRect{MOUSEPOSITION.x,MOUSEPOSITION.y,16,16},Colour_navy,true);

    //    TextureManager::Instance()->DrawRect(r,Application::Instance()->GetCamera().GetWorldRectF(),Colour_black,false);


    vec2f playerPos = dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition();

    float uintX = vec2f(MOUSEPOSITION-WindowOrigin).x;
    float uintY = vec2f(MOUSEPOSITION-WindowOrigin).y;
    for(int i = 0 ; i < 32; i++ )
        for(int j = 0 ; j < 32; j++ )
        {
            TextureManager::Instance()->DrawPoint(r,(i*uintX)+WindowOrigin.x,(j*uintY)+WindowOrigin.y,Colour_gold);


        }
    TextureManager::Instance()->DrawVector(r,CAMCENTRE,vec2f(0,CAMRECT.h-CAMCENTRE.y),Colour_blanchedalmond);
    float til = 16;
    //APP->GetGameTime();


    float inc = 0;
    for(int i = 0 ; i < 640; i++ )
    {
        float p = i/(float)640;
        inc = til*(float) std::cos(p/(float)M_PI2*(float)180);

        TextureManager::Instance()->DrawPoint(r,i,CAMCENTRE.y-inc,Colour_gold);
//            if(i%til==0)
//                 TextureManager::Instance()->DrawVector(r,vec2f(i,CAMRECT.h-inc),vec2f(i,CAMRECT.h-inc).GetOrtho(),Colour_blanchedalmond);

    }
    float p = MOUSEPOSITION.x/(float)640;
    float p2 = (MOUSEPOSITION.x+til)/(float)640;
    float  inc1 = til*(float) std::cos(p/(float)M_PI2*(float)180);
    float inc2 = til*(float) std::cos(p2/(float)M_PI2*(float)180);
    vec2f dx    = vec2f(MOUSEPOSITION.x,CAMCENTRE.y-inc1);
    vec2f dt   = vec2f(MOUSEPOSITION.x+til,CAMCENTRE.y-inc2)-vec2f(MOUSEPOSITION.x,CAMCENTRE.y-inc1);
    vec2f dtx = dt-dx;


    float s = vec2f::Dot(vec2f(inc1,inc2).GetNormalise(),dt.GetNormalise());
    TextureManager::Instance()->DrawVector(r,vec2f(0,CAMRECT.h/2),vec2f(CAMRECT.w,0),Colour_blanchedalmond);
    TextureManager::Instance()->DrawVector(r,vec2f(0,CAMRECT.h/2+16),vec2f(CAMRECT.w,0),Colour_blanchedalmond);
    TextureManager::Instance()->DrawVector(r,vec2f(0,CAMRECT.h/2-16),vec2f(CAMRECT.w,0),Colour_blanchedalmond);



    TextureManager::Instance()->DrawVector(r,vec2f(300,CAMRECT.h/2),vec2f(dt).GetOrtho(),Colour_blanchedalmond);
    TextureManager::Instance()->DrawVector(r,dx,vec2f(dt).GetOrtho(),Colour_blanchedalmond);
    TextureManager::Instance()->DrawVector(r,dx,vec2f(0,-dt.Length()),Colour_white);
    if(s>0)
    {
        TextureManager::Instance()->DrawVector(r,dx,dt,Colour_yellow);
        TextureManager::Instance()->DrawVector(r,dx,dt.GetOrtho(),Colour_green);
    }
    else
    {
        TextureManager::Instance()->DrawVector(r,dx,-dt.GetOrtho(),Colour_red);
        TextureManager::Instance()->DrawVector(r,dx,dt,Colour_blue);
    }
//  dynamic_cast<SDLGameObject*>(obj)->GetAngle() = 45;

    vec2f bb = vec2f(0,-dt.Length());
    vec2f aa = dt.GetOrtho();
    TextureManager::Instance()->DrawVector(r,dx,vec2f(0,-dt.Length()),Colour_white);
    TextureManager::Instance()->DrawVector(r,dx,dt.GetOrtho(),Colour_green);
    dynamic_cast<SDLGameObject*>(obj)->GetAngle() = vec2f::vectorAngle(aa,vec2f(0,-1));
    if(vec2f::Dist(dx,m_layers.back()->m_gameObjects.back()->GetPosition())<=16)
    {
       // std::cout << "inc1 = " <<  inc1 << "\n";

        dynamic_cast<SDLGameObject*>(m_layers.back()->m_gameObjects.back())->GetAngle()= dynamic_cast<SDLGameObject*>(obj)->GetAngle() ;
    }
//obj->GetPosition().x= dx.x;
//obj->GetPosition().y = dx.y-dt.Length();
//obj->GetPosition().x= MOUSEPOSITION.x;
//obj->GetPosition().y =MOUSEPOSITION.y;
    // std::cout << "angle = " <<  vec2f::Dot(bb,aa) << "\n";
//   std::cout << "angle = " <<  vec2f::vectorAngle(aa,bb) << "\n";
//   std::cout << "angle = " <<    dynamic_cast<SDLGameObject*>(obj)->GetAngle() << "\n";
    for(int i = 0 ; i < CAMRECT.w; i+=16 )
    {
        TextureManager::Instance()->Drawcircle(r,i,CAMRECT.h/2,Colour_white,8,false);

    }
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
        //     ee.render(APP->GetRenderer(),"par_effect");
    }
    psys.Render(APP->GetRenderer(),"par_effect");
    LmouseClick = WindowOrigin-MOUSEPOSITION;

    TextureManager::Instance()->DrawVector(r,WindowOrigin,vec2f(x,WindowOrigin.y),Colour_blue);
    TextureManager::Instance()->DrawVector(r,WindowOrigin,-LmouseClick,Colour_blue);
    std::vector<SDL_Rect>grid = MakeGrid(0,0,640/(float)32,360/(float)32,32);
    TextureManager::Instance()->DrawRects(r,&grid[0],grid.size(),Colour_beige,false);
//std::cout <<grid[1 * (640/8) + 1].x << "  "<< grid[1 * (640/8) + 1].h << "\n";
 vec2f m = alignToVec2Position(MOUSEPOSITION,32);

 SDL_Rect gggggg;


      for (int i = 0; i < grid.size(); i++)
      {
           if(InputHandler::Instance()->HasPointinRect(MOUSEPOSITION,grid[i]))
           {
               gggggg = grid[i];
           }
{

}
      }
    std::vector<GameObject*> temp = m_layers[m_layers.size()-2]->GetGameObejcts();
      for (int i = 0; i < temp.size(); i++)
      {
          if(InputHandler::Instance()->HasIntersection(gggggg, dynamic_cast<SDLGameObject*>(temp[i])->GetSDLRect()))
    TextureManager::Instance()->DrawRect(r,dynamic_cast<SDLGameObject*>(temp[i])->GetSDLRect(),Colour_red,true);
      }
    vec2f *aaa = &rand_pos[0];
    TextureManager::Instance()->DrawVector(r, &rand_pos[0],rand_pos.size(),Colour_dodgerblue);
    for(int i = 0 ; i < grid.size(); i++)
    {
        if(INPUTHANDLER->HasPointinRect(MOUSEPOSITION.x,MOUSEPOSITION.y,grid[i]))
        {
            TextureManager::Instance()->DrawRect(r,grid[i],Colour_beige,true);

        }
    }

    TextureManager::Instance()->DrawRect(r,SDL_FRect({0,360,640,16}),Colour_black,true);
    TextureManager::Instance()->DrawRect(r,SDL_FRect({360,360-16,640,16}),Colour_black,true);
    //TextureManager::Instance()->drawSprite("background2",0,0,640,360,r,SDL_FLIP_NONE);
 // TextureManager::Instance()->drawSprite("platformTile2",MOUSEPOSITION.x,MOUSEPOSITION.y,64,64,r,SDL_FLIP_NONE);
 // TextureManager::Instance()->drawSprite("platformTile3",MOUSEPOSITION.x,MOUSEPOSITION.y,64,64,r,SDL_FLIP_NONE);
 // TextureManager::Instance()->drawSprite("platformTile3",MOUSEPOSITION.x+64,MOUSEPOSITION.y,64,64,r,SDL_FLIP_NONE);
 // TextureManager::Instance()->drawSprite("platformTile4",MOUSEPOSITION.x,MOUSEPOSITION.y+64,64,64,r,SDL_FLIP_NONE);
  TextureManager::Instance()->drawSprite("Spikes",MOUSEPOSITION.x+64,MOUSEPOSITION.y+64,32,16,r,SDL_FLIP_NONE);
  TextureManager::Instance()->drawSprite("table",MOUSEPOSITION.x+32,MOUSEPOSITION.y+64,64,64,r,SDL_FLIP_NONE);
  TextureManager::Instance()->drawSprite("chair",MOUSEPOSITION.x,MOUSEPOSITION.y+64,64,64,r,SDL_FLIP_NONE);
  TextureManager::Instance()->drawSprite("Bubble",MOUSEPOSITION.x,MOUSEPOSITION.y+64,64,64,r,SDL_FLIP_NONE);
  TextureManager::Instance()->drawSprite("Heart",MOUSEPOSITION.x,MOUSEPOSITION.y+64,32,24,r,SDL_FLIP_NONE);

    LTexture *ltexture = new LTexture();
    ltexture->LoadFromRendered(APP->GetRenderer(),vec2f::Dist(MOUSEPOSITION,WindowOrigin),16,Colour_white,SDL_BLENDMODE_BLEND);

    SDL_FPoint aaaaa = SDL_FPoint({vec2f::Dist(MOUSEPOSITION,WindowOrigin)/2,8});
//         ltexture->Render(APP->GetRenderer(),200,200,vec2f::vectorAngle(vec2f(1,0),WindowOrigin-MOUSEPOSITION),&aaaaa);
//         ltexture->Render(APP->GetRenderer(),200,200,180-vec2f::vectorAngle(vec2f(1,0),WindowOrigin-MOUSEPOSITION),&aaaaa);
//         ltexture->Render(APP->GetRenderer(),200,200,45-vec2f::vectorAngle(vec2f(1,0),WindowOrigin-MOUSEPOSITION),&aaaaa);
//         ltexture->Render(APP->GetRenderer(),200,200,135-vec2f::vectorAngle(vec2f(1,0),WindowOrigin-MOUSEPOSITION),&aaaaa);

        delete ltexture;
 for(int i = 0 ; i < CAMRECT.w; i++ )
    {
        TextureManager::Instance()->DrawPoint(r,i,CAMRECT.h/2,Colour_purple);

    }

//std::cout << CAMCENTRE*2 << "\n";
//std::cout << WindowOrigin*2 << "\n";
//std::cout << WindowRect.w << "\n";
//std::cout << WindowOrigin.Length()*(float)2 << "\n";

//    TextureManager::Instance()->DrawRect(r,WindowRect,Colour_black,true);//   obj->Render(r,0,0);
//    vec2f ab = vec2f(WindowRect.w,WindowRect.h);
//    ab.Normalise();
// for(int i = 0 ; i < WindowOrigin.Length()*(float)2; i++ )
//    {
//        TextureManager::Instance()->DrawPoint(r,ab*i,Colour_white);
//
//    }
//    TextureManager::Instance()->DrawRect(r,SDL_Rect({m.x,m.y,8,8}),Colour_blue,true);//
//    TextureManager::Instance()->DrawVector(r,WindowOrigin,MOUSEPOSITION-WindowOrigin,Colour_white);

    for(int i = 0 ; i < trace_pos.size(); i++ )
    {

        TextureManager::Instance()->DrawLine(r,trace_pos[i].x,trace_pos[i].y,trace_pos[i].x,trace_pos[i].y+4,Colour_purple);
    }

//    TextureManager::Instance()->SetAhpla("background4",57);
//  TextureManager::Instance()->drawSprite("background4",-Application::Instance()->GetCamera().GetWorldPos().x,-Application::Instance()->GetCamera().GetWorldPos().y,640,360,r,SDL_FLIP_NONE);

    TextureManager::Instance()->DrawRect(r,camB,Colour_red,false);


};

void TestState36::Update(float dt)
{
    vec2f sss = vec2f::Lerp(vec2f(),vec2f(CAMRECT.w,0),dt);
     camB = SDL_Rect{0,0,CAMCENTRE.x*2,CAMCENTRE.y*2};
    int a = std::atoi("1");

    // std::setprecision(1);
    // std::cout  << (double)dt;
    for (int i = 0; i < m_e.size(); i++)
    {
        m_e[i]->Update(dt);
//   float a =GetRandomNumber() % 640;
//   float b =GetRandomNumber() % 360;
    };
//
// dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition().x = p4.x;
// dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition().y = p4.y;
    Application::Instance()->GetAspectRatio();

    acc = vec2f(dir *24,0);
    vel  = acc * dt;
//    vel.Truncate(1);S

objplayer =   (m_layers.back()->m_gameObjects.back());
 CollisionManager::Instance()->Check(objplayer);
m_collisons.clear();
m_collisons = CollisionManager::Instance()->check(objplayer);

while(!CollisionManager::Instance()->FindResult().empty())
{
break;
}
   // Application::Instance()->GetCamera().Move(vec2f(sss.x,0).GetNormalise());
    for(int i = 0 ; i < m_layers.size(); i++ )
    {
        m_layers[i]->Update(dt);
    }
    for(int i = 0 ; i < m_gameObects.size(); i++ )
    {
        m_gameObects[i]->Update(dt);
    }  vec2f p =  dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition();

    vec2f pS =  vec2f(m_layers.back()->m_gameObjects.back()->getWidth(),m_layers.back()->m_gameObjects.back()->getHeight());
if(p.y+pS.y > camB.y+camB.h)
    {
    dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->OnGround();
        dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition().y =  camB.y+camB.h- pS.y;
    }
if(p.x+pS.x > camB.x+camB.w)
    {
//    dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->OnGround();
        dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition().x =  camB.w+camB.x- pS.x;
    }

     trace_pos.push_back( dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition());

//    p.clear();
//    for(int i = 0; i< 10 ; i++)
//    {
//    p.push_back(MOUSEPOSITION-WindowOrigin);
//        p.back().Rotate(i*36);
//        p.back().Truncate(128);
//        p.back().Limit(128);
//    }

    f =(float) -k *(float)x;
//  std::cout << f << "\n";

    ani.Update(dt);
    psys.Update(dt);
    // m_layers.back()->m_gameObjects.back()->GetPosition().x = obj->GetPosition().x;
    //  m_layers.back()->m_gameObjects.back()->GetPosition().y =  obj->GetPosition().y;
//    dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetDir();
    x -= 0.5 *(float ) 10 * (float ) dt ;
    obj->Update(dt);
//    Quad qt = Quad(Point(0,0),Point(640,360));
//   Node aa = Node(Point(30,30),20);
//    qt.insert(&aa);
//
//    std::cout << "data" << qt.search(Point(30,30))->data << "\n";

vec2f p3 =  dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetPosition();
vec2f p4 =  CAMCENTRE;
Application::Instance()->GetCamera().SetVirtualPos(vec2f(p3.x,0));

}

bool TestState36::OnEnter()
{
//    SDL_Rect www = WindowRect;
//        SDL_RenderSetViewport(APP->GetRenderer(),&www);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//    SDL_Rect ss = {0,0,640,360};
////SDL_RenderSetClipRect(APP->GetRenderer(),&ss);
////    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
////    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
//Application::Instance()->GetCamera().SetSize(vec2f(1920,1080));
//

    for (int i = 0; i < 2; i++)
    {
        float xr = GetRandomNumber()%640;
        float yr = GetRandomNumber()%360;
        rand_pos.push_back(vec2f(xr,yr));
      //  std::cout << rand_pos.back() << "\n";
        rand_pon.push_back(SDL_Point{xr,yr});
    }

//Particle 0,0 soild(255)

    psys = ParticleSystem();
//
//    for (int i = 0; i < 1; i++)
//    {
//        float t = 360*(float)(i/(float)40);
//        float f = 40*(float)i/(float)255;
//        vec2f w =  vec2f(-i,0);
//        w.Rotate(-t);
//
//        float ap = (GetRandomNumber()%255);
//        float ss = i/(float)f;
//        vec2f huj=     vec2f(0,0);
//        SDL_Color aa= SDL_Color({ss,ss,ss,ss});
//        m_e.push_back(new ParticleEmitter(huj+CAMCENTRE,vec2f(0,0),w,16,aa,ap,1,10,0.9,1));
//        psys.Add( m_e.back());
//    };
    dir = 1;
    ani = Animation(vec2f(64,32),16,20/(float)60,ANIMATION_HORIZONTAL);
//
    int m_maxWidth = 640*20;
    int m_maxHeight = 1080;

    Application::Instance()->GetCamera().SetVirtualSize(vec2f(m_maxWidth,m_maxHeight));


//    for(int i = 0; i <120 ; i++)
//        for(int j = 0; j < 67; j++)
//        {
//
//            num[i][j] = false;
//
//        }

//    m_layers.push_back(new TileLayer());
//    {
//        auto *a = gameobjectFactory->Create("GameObjectProxy");
//        a->Load("GameObjectProxy.txt");
//
//        a->GetPosition().x = 0;
//        a->GetPosition().y =0;
//
//        a->SetWidth(640);
//        a->SetHeight(360);
//
//        m_layers.back()->Add(a);
//    }
//    m_layers.push_back(new EnemyLayer(0.5));
//    {
//        GameObject *a = gameobjectFactory->Create("GameObjectProxy");
//        a->Load("GameObjectProxy.txt");
//        a->GetPosition().x = 16;
//        a->GetPosition().y = CAMRECT.h-a->getHeight();
//
//        a->SetWidth(640-32);
//        a->SetHeight(16);
//
//        m_layers.back()->Add(a);
//
//    }
//
//    {
//        auto *a = gameobjectFactory->Create("GameObjectProxy");
//        a->Load("GameObjectProxy.txt");
//        a->GetPosition().x = 640-16;
//        a->GetPosition().y =0;
//        a->SetWidth(16);
//        a->SetHeight(360);
//
//
//        m_layers.back()->Add(a);
//
//    }
//    {
//        auto *a = gameobjectFactory->Create("GameObjectProxy");
//        a->Load("GameObjectProxy.txt");
//        a->GetPosition().x = 256;
//        a->GetPosition().y =256;
//        a->SetWidth(16);
//        a->SetHeight(360);
//
//
//        m_layers.back()->Add(a);
//
//    }

//    dynamic_cast<SDLGameObject*>(m_layers.back()->m_gameObjects.back())->SetTexture("BackGround3");
    m_layers.push_back(new TileLayer());
    {

        for(int i = 0; i < m_maxWidth; i+=16)
            for(int j= 0; j < m_maxHeight; j+=16)
            {
if(j % 10 == 0){
                auto *a = gameobjectFactory->Create("GameObjectProxy");
                a->Load("GameObjectProxy.txt");
                a->GetPosition().x = i ;
                a->GetPosition().y =j;
                a->SetWidth(16);
                a->SetHeight(16);


                m_layers.back()->Add(a);

            }
            }
    }


    m_layers.push_back(new TileLayer());
     for(int i = 0 ; i < CAMRECT.w; i++)
    {

        auto *a = gameobjectFactory->Create("GameObject_Tile");
 dynamic_cast<SDLGameObject*>(a)->setTexture("platformTile3");
        a->GetPosition().x = i*64;
        a->GetPosition().y= CAMRECT.h-64;
   a->SetHeight(64);
   a->SetWidth(64);
        m_layers.back()->Add(a);

    }
    for(int i = 0 ; i < CAMRECT.w; i++)
    {

        auto *a = gameobjectFactory->Create("GameObject_Tile");
 dynamic_cast<SDLGameObject*>(a)->setTexture("platformTile5");
        a->GetPosition().x = i*16;
        a->GetPosition().y= CAMRECT.h-16;
        m_layers.back()->Add(a);

    }

    m_layers.push_back(new EnemyLayer(0));
    for(int j = 0 ; j < 10; j++ )
    {   auto *a = gameobjectFactory->Create("GameObjectTree");

a->Load("GameObjectTree.txt");
        a->GetPosition() = vec2f(j*288,CAMCENTRE.y*2-186);

   a->SetHeight(184);
   a->SetWidth(70);
        dynamic_cast<GameObjectTree*>(a)->setTreeHeight(0);
                m_layers.back()->Add(std::move(a));
                CollisionManager::Instance()->Add(a);
    }
//    m_layers.push_back(new EnemyLayer(0.25));

    m_layers.push_back(new EnemyLayer(0));

      for(int j = 0 ; j < 1; j++ )

    {   auto *a = gameobjectFactory->Create("BreakOut_Ball");

a->Load("FileName_BreakOut_Ball.txt");
        a->GetPosition()  = vec2f(vec2f(GetRandomNumber()%640,GetRandomNumber()%360));
                m_layers.back()->Add(a);
                CollisionManager::Instance()->Add(a);

}

{
        auto *a = gameobjectFactory->Create("GameObject_Tile");
 dynamic_cast<SDLGameObject*>(a)->setTexture("bubblemaker");
        a->GetPosition().x = 160;
        a->GetPosition().y= CAMRECT.h-64;
        a->SetWidth(64);
        a->SetHeight(64);
        m_layers.back()->Add(a);
                CollisionManager::Instance()->Add(a);

 }
    m_layers.push_back(new TileLayer());
    {

        auto *a = gameobjectFactory->Create("GameObject_Player");
        a->Load("GameObject_Player.txt");
        a->GetPosition().x= CAMCENTRE.x;
        a->GetPosition().y= CAMCENTRE.y;

        m_layers.back()->Add(a);

    }
    obj = gameobjectFactory->Create("GameOBject_RocketShip");
    obj->Load("GameOBject_RocketShip.txt");
    obj->GetPosition().x = CAMCENTRE.x;
    obj->GetPosition().y = CAMCENTRE.y;
    dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetDir();
    dynamic_cast<GameObject_Player*>(m_layers.back()->m_gameObjects.back())->GetState();
//    dynamic_cast<SDLGameObject*>(m_layers.back()->m_gameObjects.back())->GetMaxVelocity() =  88;

    for(int i = 0 ; i < m_layers[m_layers.size()-3]->GetGameObejcts().size(); i++ )
   dynamic_cast<GameObjectTree*>(m_layers[m_layers.size()-3]->GetGameObejcts()[i])->SetplayerTarget(m_layers.back()->m_gameObjects.back());


    return true;
}
bool TestState36::onExit()
{
    return true;
}
void TestState36::resume() {}
void TestState36::HandleEvent(SDL_Event &e )
{

    for(int i = 0 ; i < m_layers.size(); i++ )
    {

        m_layers[i]->HandleEvent(e);

    }
    bool isvald = true;
    if(e.button.type == SDL_MOUSEBUTTONDOWN && e.button.state == SDL_PRESSED)
    {
trace_pos.clear();
//        x = MOUSEPOSITION.x;
//        std::cout << "SDL_PRESSED\n";
//        vec2f m = MOUSEPOSITION;
//        m =  alignToVec2Position(m+Application::Instance()->GetCamera().GetPos(),16);
//
//        for(int i = 0 ; i  < m_circle.size(); i++)
//        {
//            if(m==m_circle[i]+Application::Instance()->GetCamera().GetWorldPos())
//            {
//                isvald = false;
//            }
//        }
//        if(isvald)
//        {
//            auto *a = gameobjectFactory->Create("GameObjectProxy");
//            a->Load("GameObjectProxy.txt");
//            a->GetPosition().x = (int)(m.x-Application::Instance()->GetCamera().GetPos().x+Application::Instance()->GetCamera().GetWorldPos().x);
//            a->GetPosition().y = (int)(m.y-Application::Instance()->GetCamera().GetPos().y+Application::Instance()->GetCamera().GetWorldPos().y);
//            if(InputHandler::Instance()->HasPointinRect(m,CAMRECT))
//                m_layers[1]->Add(a);
//
//
//            m_circle.push_back(m);
//            int q= m_circle.back().x/16;
//            int k = m_circle.back().y/16;
//            num[q][k] = true;
//        }
    }

    if(e.button.type == SDL_MOUSEBUTTONUP && e.button.state == SDL_RELEASED)
    {
        std::cout << "SDL_RELEASED\n";
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
    {
        dir= -1;


    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
    {
        dir= 1;

    }

}
