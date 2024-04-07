#include "TestState32.h"

TestState32::TestState32()
{
    //ctor
}

TestState32::~TestState32()
{
    //dtor
}
void TestState32::Render()
{
/**<
//    TextureManager::Instance()->Load("Img/1.png","Tile_wood",APP->GetRenderer());
//    TextureManager::Instance()->Load("Img/2.png","Tile_wood_Mask",APP->GetRenderer());
//    TextureManager::Instance()->Load("Img/3.png","Tile_wood_Mask2",APP->GetRenderer());
//    TextureManager::Instance()->Load("Img/4.png","Tile_wood_Mask3",APP->GetRenderer());
//for(int i = 0 ; i <= 64*6; i+=64)
//{
//}
//    TextureManager::Instance()->drawSprite("Tile_wood",MOUSEPOSITION.x,MOUSEPOSITION.y+64,64,64,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x,MOUSEPOSITION.y+64,64,64,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask2",MOUSEPOSITION.x,MOUSEPOSITION.y+64,64,64,APP->GetRenderer(),SDL_FLIP_NONE);

    TextureManager::Instance()->DrawRect(APP->GetRenderer(),WindowRect,Colour_black,true);


    SDL_Vertex vertex_1 = {{320,0}, Colour_white, {0, 0}};
    SDL_Vertex vertex_2 = {{0,360}, Colour_blue, {1, 1}};
    SDL_Vertex vertex_3 = {{640,360}, Colour_black, {0, 1}};
// Put them into array
    SDL_Vertex vertices[] =
    {
        vertex_1,
        vertex_2,
        vertex_3
    };
    SDL_RenderGeometry(APP->GetRenderer(), NULL, vertices,3, NULL, 0);
    TextureManager::Instance()->SetAhpla("Tile_wood_Mask",64);
    TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),vec2f(0,0),vec2f(0,360),vec2f(320,0),Colour_darkcyan);
    TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),vec2f(320,0),vec2f(640,0),vec2f(640,360),Colour_darkcyan);
    TextureManager::Instance()->SetBlendMode("blur4",SDL_BLENDMODE_ADD);
    TextureManager::Instance()->SetBlendMode("blur5",SDL_BLENDMODE_MUL);
//     TextureManager::Instance()->SetAhpla("blur4",128);
//    TextureManager::Instance()->SetColorMod("blur4",Colour_red);

    TextureManager::Instance()->SetBlendMode("Tile_wood_Mask",SDL_BLENDMODE_ADD);
    for(int i = 0 ; i < WindowOrigin.x*2/16; i++)
        for (int j = 0; j <  WindowOrigin.y*2/16; j ++)
        {

            if(vec2f::Dist(MOUSEPOSITION+vec2f(8,8),vec2f(i*16+8,j*16+8))<46)
            {

                TextureManager::Instance()->drawSprite("Tile_wood",i*16,j*16,16,16,APP->GetRenderer(),SDL_FLIP_NONE);

                TextureManager::Instance()->drawSprite("Tile_wood_Mask",i*16-8,j*16-8,16,16,APP->GetRenderer(),SDL_FLIP_NONE);
            }
        }



//    TextureManager::Instance()->drawSprite("Tile_wood",MOUSEPOSITION.x,MOUSEPOSITION.y,64,64,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->drawSprite("Tile_wood",MOUSEPOSITION.x+64,MOUSEPOSITION.y,64,64,APP->GetRenderer(),SDL_FLIP_NONE);
//      TextureManager::Instance()->SetAhpla("Tile_wood_Mask",128);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x,MOUSEPOSITION.y,16,16,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x+16,MOUSEPOSITION.y+16,16,16,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x,MOUSEPOSITION.y+16,16,16,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x+16,MOUSEPOSITION.y,16,16,APP->GetRenderer(),SDL_FLIP_NONE);
    TextureManager::Instance()->drawSprite("blur4",MOUSEPOSITION.x-112/(float)2,MOUSEPOSITION.y-112/(float)2,112,112,APP->GetRenderer(),SDL_FLIP_NONE);


    TextureManager::Instance()->drawSprite("blur5",MOUSEPOSITION.x-112/(float)2,MOUSEPOSITION.y-112/(float)2,112,112,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->SetAhpla("blur3",64);
//extureManager::Instance()->drawSprite("Tile_wood",MOUSEPOSITION.x+64,MOUSEPOSITION.y,64,64,APP->GetRenderer(),SDL_FLIP_NONE);
//
//    TextureManager::Instance()->SetAhpla("Tile_wood_Mask",255);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x,MOUSEPOSITION.y,16,16,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->SetAhpla("circle2",128);
//    TextureManager::Instance()->SetBlendMode("circle2",SDL_BLENDMODE_ADD);
//    TextureManager::Instance()->drawSprite("circle2",MOUSEPOSITION.x,MOUSEPOSITION.y,128,128,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->SetAhpla("circle2",64);
//    TextureManager::Instance()->drawSprite("circle2",MOUSEPOSITION.x+128,MOUSEPOSITION.y,128,128,APP->GetRenderer(),SDL_FLIP_NONE);
//
//    TextureManager::Instance()->SetAhpla("Tile_wood_Mask",255);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask",MOUSEPOSITION.x,MOUSEPOSITION.y,128,128,APP->GetRenderer(),SDL_FLIP_NONE);


//    TextureManager::Instance()->SetAhpla("blur2",64);
//    TextureManager::Instance()->SetBlendMode("blur2",SDL_BLENDMODE_ADD);
//    TextureManager::Instance()->drawSprite("blur2",MOUSEPOSITION.x,MOUSEPOSITION.y,234,240,APP->GetRenderer(),SDL_FLIP_NONE);

//    TextureManager::Instance()->SetBlendMode("background",SDL_BLENDMODE_MOD);
//    TextureManager::Instance()->drawSprite("background",0,0,640,360,APP->GetRenderer(),SDL_FLIP_NONE);

    //TextureManager::Instance()->SetBlendMode("blur2",SDL_BLENDMODE_MUL);
    //TextureManager::Instance()->drawSprite("blur2",MOUSEPOSITION.x,MOUSEPOSITION.y,64,64,APP->GetRenderer(),SDL_FLIP_NONE);


//    TextureManager::Instance()->SetAhpla("blur",64);

//    TextureManager::Instance()->SetBlendMode("blur3",SDL_BLENDMODE_MUL);
//    TextureManager::Instance()->drawSprite("blur3",MOUSEPOSITION.x,MOUSEPOSITION.y,64,64,APP->GetRenderer(),SDL_FLIP_NONE);

//
//TextureManager::Instance()->
//    TextureManager::Instance()->SetBlendMode("Tile_wood_Mask",SDL_BLENDMODE_BLEND);
//
//      TextureManager::Instance()->SetAhpla("Tile_wood_Mask2",255);
//    TextureManager::Instance()->SetBlendMode("Tile_wood_Mask2",SDL_BLENDMODE_BLEND);
//    TextureManager::Instance()->drawSprite("Tile_wood_Mask2",MOUSEPOSITION.x+128,MOUSEPOSITION.y,64,64,APP->GetRenderer(),SDL_FLIP_NONE);
//    TextureManager::Instance()->SetBlendMode("Tile_wood_Mask2",SDL_BLENDMODE_NONE);
    {


        LTexture *s;
        s = new LTexture();
        s->CreateBlankTexture(APP->GetRenderer(),200,200);
        s->SetColorMod(128,128,128);
        s->SetBlendMode(SDL_BLENDMODE_MOD);
        s->SetAlpha(128);
        s->Render(APP->GetRenderer(),20,20);

        delete s;


    }
    if(InputHandler::Instance()->isTextInputActive())
    {
        std::string Text =  InputHandler::Instance()->GetTextInput();

        if(Text!="")
        {

            TextureManager::Instance()->DrawTextWrappedShaded(APP->GetRenderer(),
                    fontManager->GetFont("CONSOLAB"),
                    Text,            vec2f(MOUSEPOSITION),
                    0,
                    Colour_white,Colour_black,Align_Left,
                    0,
                    SDL_FPoint({0,0}),
                    SDL_FLIP_NONE);

        }
    }


    TextureManager::Instance()->drawSprite("level1_BackGround",0,0,640,360,APP->GetRenderer(),SDL_FLIP_NONE);
    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),m_player.x,m_player.y,Colour_red,16,true);
    {
        std::stringstream ww;
        ww <<APP->GetGameTime();
        TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),ww.str(),CAMRECT.h,0,Colour_yellow,Align_Right);

    }
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin+vec2f::projB(WindowOrigin,MOUSEPOSITION));
    vec2f m = vec2f(WindowOrigin-MOUSEPOSITION);
//    std::cout <<  vL<< "            vL\n";
//    std::cout << uL<< "               uL\n";
//    std::cout << dotUV << "            dotUV\n";
//    std::cout <<  vL << "            dotUV\n";
//    std::cout <<  v2 << "            dotUV\n";
    vec2f vvvv = vec2f::projB(vec2f(WindowWidth,0),m);
//    std::cout << vvvv << "\n";
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vvvv,Colour_red);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f::projB(vec2f(0,360),m),Colour_yellow);
//TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin+MOUSEPOSITION,Colour_cadetblue);
//m.Truncate(320);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,m,Colour_blue);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,m,Colour_green);
//    std::cout << vec2f::Dot(vec2f(1,2),vec2f(3,-8))/(float)std::sqrt((vec2f(3,-8).Length()*vec2f(3,-8).Length()))<< "           99999\n";
//    std::cout << vec2f::Dot(vec2f(1,2),vec2f(3,-8)) << "\n";
//    std::cout << vec2f::projB(vec2f(-8,3),vec2f(2,1)) << "\n";


    vec2f aa = vec2f(1.6,1);
    aa.Rotate(360);
    std::stringstream  TempstrStream ;
    TempstrStream << "\n"<< m_displacement<< "\n"
                  << m_player << "\n"
                  << m_scrollSpeedvel.y  << "\n"
                  <<m_scrollSpeedacc.y
                  << "\n"    << aa  << "\n"    ;
//

    TextureManager::Instance()->DrawTextWrappedShaded(APP->GetRenderer(),
            fontManager->GetFont("CONSOLA"),
            TempstrStream.str(),
            vec2f(MOUSEPOSITION),
            0,
            Colour_black,Colour_white,Align_Left,
            0,
            SDL_FPoint({0,0}),
            SDL_FLIP_NONE);
    TempstrStream.clear();


    vec2f dd = vec2f::GetReflection(vec2f(1,0),m_scrollSpeedvel);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,m,Colour_blue);

    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin-WindowOrigin+dd,Colour_blue);

for(int i = 0; i < 1; i++)
{
    std::cout << "chunk number " << i << "  size of chunk "<<lR2[i].size() << "\n";
  // if(CAMRECT.w > i*640)
   //{

std::vector<SDL_Rect> f = lR2[i];
    TextureManager::Instance()->DrawRects(APP->GetRenderer(),&f[0],lR2[i].size(),Colour_red,false);
    std::cout <<vec2f::Dot(m_scrollSpeedacc,vec2f(1,0))  << "\n";
   }
  */
    TextureManager::Instance()->DrawRect(APP->GetRenderer(),WindowRect,Colour_black,true);

SDL_FRect boxRect {m_pos.x,m_pos.y,m_width,m_height};
//    TextureManager::Instance()->DrawRect(APP->GetRenderer(),boxRect,Colour_red,true);

  vec2f vvv  = vec2f(vec2f::Dist(vec2f(0,0),m_pos),WindowOrigin.y);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,(WindowOrigin/4)-vvv,Colour_blue);
// TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,k,Colour_blue);

//         SDL_SetRenderTarget(APP->GetRenderer(),s->GetSDLTexture());
//
//         SDL_SetRenderTarget(APP->GetRenderer(),NULL);
//     dd.Rotate(90);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,dd,Colour_blue);

vec2f ww = vec2f(WindowOrigin-MOUSEPOSITION);
//ww.Rotate(MOUSEPOSITION.Length());
ww.Rotate(0);
vec2f sn = vec2f(ww.x*std::cos(0),ww.y*std::sin(0));
vec2f sc = vec2f(ww.x*std::cos(0),ww.y*std::sin(0));
ww += WindowOrigin;
sn += WindowOrigin;
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION-ww,Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION-sc,Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION+sc,Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin+sc,Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin-sn,Colour_red);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin+sc,Colour_yellow);

//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,MOUSEPOSITION,Colour_red);

//m g sin ( theta ) +  m L ((d 2 theta)/dt 2)  = 0
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f(a),Colour_white);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f(ab),Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin+a,vec2f(ab+a),Colour_grey);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, a,Colour_tan);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f(a.x*std::sin(angle),a.y*std::cos(angle)),Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f(a.x*std::cos(angle),a.y*std::sin(angle)),Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f(0,length),Colour_royalblue);

//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f(a),Colour_white);

    //TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x+vec2f(length,length).x,WindowOrigin.y+vec2f(length,length).y,Colour_white,16,false);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,vec2f(WindowOrigin.x,WindowOrigin.y+a.y),Colour_white);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+a,vec2f(0,64),Colour_saddlebrown);
// BASE POINT



    vec2f w =  WindowOrigin;
   TextureManager::Instance()->DrawGrid(0,0,25,25,8,Colour_red,Application::Instance()->GetRenderer());

  //std::cout << f <<"\n";

    //TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+vec2f(0,64),b,Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+vec2f(0,64),vec2f(64,0),Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+vec2f(0,64)+vec2f(64,0),vec2f(0,0),Colour_mediumblue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,vec2f(90,-86),Colour_darkblue);

//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,a,Colour_white);
//// ball
//    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),w.x+a.x,w.y+a.y,Colour_white,16,false);
//    //
//
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+a,vec2f(std::cos(0)*-a.x,std::sin(0)*a.y),Colour_red);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+vec2f(0,64),a,Colour_red);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+vec2f(0,64),vec2f(std::cos(0)*a.x,std::sin(0)*a.y),Colour_blue);
////    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,vec2f(std::sin(0)*a.x,std::cos(0)*a.y),Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+a,w-vec2f(0,64),Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,vec2f(0,64),Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+a,vec2f(std::sin(0)*a.x,std::cos(0)*a.y),Colour_green);


//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w+a,w,Colour_saddlebrown);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,a2,Colour_white);

//    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),w.x+a.x,w.y+a.y,Colour_white,16,false);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),MOUSEPOSITION, vec2f(sss.x*std::sin(0),sss.y*std::cos(0)),Colour_green);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),MOUSEPOSITION, vec2f(sss.x*std::cos(0),sss.y*std::sin(0)),Colour_blue);

//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f(MOUSEPOSITION.x*std::cos(0),MOUSEPOSITION.y*std::sin(0)),Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin, vec2f(MOUSEPOSITION.x*std::sin(0),MOUSEPOSITION.y*std::cos(0)),Colour_blue);
//
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin-MOUSEPOSITION, vec2f(MOUSEPOSITION.x*-std::cos(0),MOUSEPOSITION.y*std::sin(0)),Colour_blue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin-MOUSEPOSITION, vec2f(MOUSEPOSITION.x*std::sin(0),MOUSEPOSITION.y*-std::cos(0)),Colour_blue);
//
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(w.x-32,w.y),vec2f(64,0),Colour_darkblue);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,b,Colour_blue);
//    TextureManager::Instance()->DrawLineDotted(APP->GetRenderer(),line({vec2f(24,24),vec2f(128,64)}),Colour_red);
//    TextureManager::Instance()->DrawLineDotted(APP->GetRenderer(),line({w,MOUSEPOSITION}),Colour_blue);
  //std::cout << sn<<"\n";
//std::cout << w+b << " b \n";
//std::cout << w+vec2f(0,length) << " a \n";

////b.Rotate(-(angle*APP->GetGameTime()));
//b.Rotate(-15);
//  t = M_PI*(float)2/(float)APP->GetGameTime();
//  f = 1/(float)60;    vec2f pe = vec2f(64* std::cos(m_vel.Length()),64* std::sin(m_vel.Length()));

float mass = 2;
     float length = 256;
     float angle = 16;

    vec2f r = vec2f(0,(WindowHeight/4)*l);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,r,Colour_lightblue);
    r.Rotate(_angle*(float)13);

// std::cout << _angle*(float)13 << " _angle \n  ";
// std::cout << -9.81 /(float) l << " -9.81 /(float) l \n  ";

    TextureManager::Instance()->DrawVector(APP->GetRenderer(),w,r,Colour_green);
    vec2f pos = m_pos+WindowOrigin;
    vec2f res = m_rest+WindowOrigin;

//    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),m_rest.x,m_rest.y,Colour_white,m,false);
    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x+r.x,WindowOrigin.y+r.y,Colour_white,m,false);
    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x,WindowOrigin.y,Colour_white,r.Length(),false);
    vec2f ke = pos-res;
    vec2f pe = (r)-pos-WindowOrigin;
    // pe.Rotate(m_pos.y);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,ke,Colour_rosybrown,m,true);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,pe,Colour_green,m,true);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,vec2f(std::cos(_angleVelocity)*r.Length(),std::sin(_angleVelocity)*r.Length()),Colour_green,m,true);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,vec2f(std::sin(_angleVelocity)*r.Length(),std::cos(_angleVelocity)*r.Length()),Colour_green,m,true);

//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,vec2f(std::cos(_angleVelocity)*r.Length(),-std::sin(_angleVelocity)*r.Length()),Colour_green,m,true);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos+vec2f(std::cos(_angleVelocity)*r.Length(),std::sin(_angleVelocity)*r.Length()),vec2f(std::sin(_angleVelocity)*r.Length(),std::cos(_angleVelocity)*r.Length()),Colour_green,m,true);
    vec2f s  = vec2f::Proj(WindowOrigin,MOUSEPOSITION);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,s,Colour_green,m,true);
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),m_pos,m_rest,Colour_khaki,m,true);
TextureManager::Instance()->DrawSineWave(MOUSEPOSITION,128,30,0.5,1,0,APP->GetRenderer());
  for(int i = 0; i < 640; i++)
  {
vec2f a = vec2f(i,WindowOrigin.y);
float inc = MOUSEPOSITION.y * std::sin(i*M_PI/180);
float incx = MOUSEPOSITION.x * std::cos(i*M_PI/180);
//a.Rotate(i);float inc = a.Length() * std::cos(20*M_PI/180);
    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),a.x,a.y+inc,Colour_lightblue);
    if(i % 10 == 0 )
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin ,a,Colour_red);
  }
//
//  for(int i = 0; i < 128; i++)
//    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),i,WindowOrigin.y+(std::sin(i)*(float)5),Colour_lightblue);
//for(int i = 0 ; i < 128; i+=1)
//    {
//        float rads = vec2f::Dist(MOUSEPOSITION,WindowOrigin)*M_PI/180;
//
//        float inc = APP->GetGameTime()* std::sin(i*rads);
//
//      TextureManager::Instance()->DrawPoint(APP->GetRenderer(),MOUSEPOSITION.x+inc,MOUSEPOSITION.y+i,Colour_wheat);
//    }
//  for(int i = 0 ; i < 640; i++) //34
//  for(int j = 0 ;j < 360; j++)
//    TextureManager::Instance()->DrawPoint(APP->GetRenderer(),i, j,Colour_lightblue);
 }
void TestState32::Update(float dt)
{
//    LQaudTree *qt = new LQaudTree(0,WindowRect);
//    std::cout << "nw " << qt->getSubBox()[0].x << " " << qt->getSubBox()[0].y << " " << qt->getSubBox()[0].w << " " << qt->getSubBox()[0].h <<"\n" ;
//    std::cout << "ne " << qt->getSubBox()[1].x << " " << qt->getSubBox()[1].y << " " << qt->getSubBox()[1].w << " " << qt->getSubBox()[1].h <<"\n" ;
//    std::cout << "sw " << qt->getSubBox()[2].x<< " " << qt->getSubBox()[2].y << " " << qt->getSubBox()[2].w << " " << qt->getSubBox()[2].h <<"\n" ;
//    std::cout << "se " << qt->getSubBox()[3].x<< " " << qt->getSubBox()[3].y << " " << qt->getSubBox()[3].w << " " << qt->getSubBox()[3].h <<"\n" ;
//delete qt;
g = 9.81;// g
    m_displacement = m_player;

a = M_PI/(float)4;

    t = 2 *(float) M_PI *(float) std::sqrt( l/(float) g);






_dt = dt;


      _angleAccel = -9.81 /(float) l *(float) std::sin(_angle);
            _angleVelocity += _angleAccel * _dt;
            _angle += _angleVelocity * _dt;

 // std::cout << _angleVelocity << "_angleVelocity\n";

  // std::cout << _angleAccel << "_angleAccel\n";
//
//    $dt = now - $now;
//    $now = now;
//    $vel+=$g/$len*sin($Θ)*$ppi*$dt;
//    $Θ   += $vel * $dt;
//    my $bx = $ax + sin($Θ) * $len;
//    my $by = $ay + cos($Θ) * $len;
//
//    SDL_SetRenderDrawColor($render, 255, 255, 255, 255);
//    SDL_RenderDrawLine($render, |($ax, $ay, $bx, $by)».round);
//    SDL_RenderCopy( $render, $bob_texture, Nil,
//      SDL_Rect.new($bx - 16, $by - 16, 32, 32)
//    );
//    SDL_RenderPresent($render);
//    SDL_SetRenderDrawColor($render, 0, 0, 0, 0);
//    SDL_RenderClear($render);
//
//    std::cout  << " inc " << inc << "\n";
//    std::cout  << " inc " << inc*(float)dt << "\n";
//    std::cout  << " inc " <<2    *(float) M_PI *(float) 1/(float)inc   *(float) 0.2 << "\n";
//    std::cout  << " inc " << ((2 *(float) M_PI *(float) 1/(float)inc)  *
//                              (2 *(float) M_PI *(float) 1/(float)inc)) * (float) 0.2 << "\n";
// std::cout << -m*(float)g*(float)std::sin(a) << " s\n" ;
//m_acc = vec2f(t* std::cos(m_vel.Length()),t* std::sin(m_vel.Length())) ;
//m_acc = vec2f(0,g) ;
//   m_vel += m_acc * dt;
//    m_pos += m_vel;
//m_pos = MOUSEPOSITION;

// if(vec2f::Dist(m_pos,WindowOrigin)>l*(float)WindowOrigin.y)
//    {
//   vec2f a = (m_pos - WindowOrigin);
//   a.Normalise();
//   a*=l*(float)64;
//   m_pos = a+WindowOrigin;
//
//    }
     k = vec2f(vec2f::Dist(vec2f(64,0),m_pos),m_height/2);


   // m_pos  += -k *dt ;
    //m_pos.y=m_height/2;
//x = -kx;
  vec2f vvv  = vec2f(vec2f::Dist(vec2f(0,0),m_pos),WindowOrigin.y);

    m_scrollSpeedvel += m_scrollSpeedacc * dt;
    m_player += m_scrollSpeedvel ;
    m_scrollSpeedvel.Truncate(1);

//m_scrollSpeedvel.Normalise()*(float)dt;
//m_scrollSpeedvel*=1;
//m_scrollSpeedvel.Truncate((WindowWidth/(float)640)*88/(float)60);
//m_scrollSpeedvel.Limit(1);

//    m_scrollSpeedvel = vec2f::projB(m_scrollSpeedvel,m_scrollSpeedacc);

   /**< z
    if(m_player.y<0)
    {
        if(vec2f::Dot(m_scrollSpeedvel,vec2f(1,0))<0)
        {
            m_scrollSpeedacc.Rotate(270);
            m_scrollSpeedvel.Rotate(270);
        }
        else
        {

            m_scrollSpeedacc.Rotate(90);
            m_scrollSpeedvel.Rotate(90);

        }
        m_player = m_displacement;

    }
    else  if(m_player.x<0)
    {

        if(vec2f::Dot(m_scrollSpeedvel,vec2f(-1,0))>0)
        {
            std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            m_scrollSpeedacc.Rotate(-90);
            m_scrollSpeedvel.Rotate(-90);
        }
        else
        {
            std::cout << "ssssssssssssssssss\n";

            m_scrollSpeedacc.Rotate(90);
            m_scrollSpeedvel.Rotate(90);

        }
        m_player.x=50;
//        m_player = m_displacement;
        //  m_player.x=0;

    }
    else if(m_player.y>WindowHeight)
    {
        if(vec2f::Dot(m_scrollSpeedvel,vec2f(1,0))==1)
        {
            std::cout << "right-up\n";
            m_scrollSpeedacc.Rotate(270);
            m_scrollSpeedvel.Rotate(270);
        }
        else
        {

            std::cout << "left-up\n";
            m_scrollSpeedacc.Rotate(-90);
            m_scrollSpeedvel.Rotate(-90);

        }
        m_player = m_displacement;
    }
    else if(m_player.x>WindowWidth)
    {
        if(vec2f::Dot(m_scrollSpeedvel,vec2f(0,-1))==1)
        {
            m_scrollSpeedacc.Rotate(-90);
            m_scrollSpeedvel.Rotate(-90);
        }
        else
        {

            m_scrollSpeedacc.Rotate(90);
            m_scrollSpeedvel.Rotate(90);

        }
        m_player = m_displacement;
        //   m_player.x=WindowWidth;
    }

 */
//     std::cout <<vec2f::Dot(m_scrollSpeedacc,vec2f(1,0).GetNormalise())  << "\n \n";
//
//  std::cout << vec2f::Dot(m_scrollSpeedvel.GetNormalise(),vec2f(0,1))<< "\n\n\n \n";
//        if(vec2f::Dot(m_scrollSpeedvel.GetNormalise(),vec2f(0,1))>=0)
//        {
//    if(m_player.y>WindowHeight)
//    {
//            std::cout << "right-up\n";
//  std::cout << vec2f::Dot(m_scrollSpeedvel.GetNormalise(),vec2f(0,1))<< "\n\n\n \n";
//            m_scrollSpeedacc.Rotate(270);
//            m_scrollSpeedvel.Rotate(270);
//m_player = m_displacement;
//        }
//
//
//    }    if(vec2f::Dot(m_scrollSpeedvel.GetNormalise(),vec2f(0,1))<0)
//        {
//if(m_player.x>WindowWidth)
//    {
//            std::cout << "right-up\n";
//  std::cout << vec2f::Dot(m_scrollSpeedvel.GetNormalise(),vec2f(0,1))<< "\n\n\n \n";
//            m_scrollSpeedacc.Rotate(-90);
//            m_scrollSpeedvel.Rotate(-90);
//m_player = m_displacement;
//        }
//
//}
//std::cout << lR.size() << "\n";
//std::cout << 8400*2400 << "\n";
//
//for(int i = 0; i < 13; i++)
//{
////    std::cout << "chunk number " << i << "  size of chunk "<<lR2[i].size() << "\n";
//}
}

bool TestState32::OnEnter()
{

_angle = M_PI/(float)4;
 inc =  2*(float)  M_PI *(float) std::sqrt(2/(float)9.81);
_length= 1;
l = 1; // m
m = 10;
TR = MakeGrid(0,0,8400,2400,4);
for(int i = 0; i < 13; i++)
{
     std::vector<SDL_Rect> rR;
rR = MakeGrid(640*i,360*i,640/4,360/4,4);
lR2.push_back(rR);
}

lR = MakeGrid(0,0,640/4,360/4,4);
m_width = 128;
m_height = 128;
//


//rR = MakeGrid(640,360,640/4,360/4,4);
m_acc = vec2f(0,0);
m_pos.x+=0;
m_pos.y+=64*(float)l;
m_rest = m_pos;
    float onesec =WindowWidth;
    float onesec2 =WindowHeight;
    m_levelSize = vec2f(1920,1080);
    m_scrollSpeed =onesec;
    m_scrollSpeedvel = vec2f(0,0);
    m_scrollSpeedacc= vec2f(onesec/(float)640,onesec2/(float)360);
    m_player = vec2f(0,0);
//    m_player.x-=WindowOrigin.x;
    SDL_Rect rect= WindowRect;
    rect.w= 160;
    rect.h=90;
    m_displacement = m_player;
//     m_scrollSpeedvel.y = 0;
//     m_scrollSpeedacc.y = 0;
//
//    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//  if(!SDL_RenderSetViewport(APP->GetRenderer(),&rect))
//    std::cout << SDL_GetError();

//    InputHandler::Instance()->StartTextInput();
    return true;
}
bool TestState32::onExit()
{
    std::cout<< "Exiting : "<< Type() << " \n";
}
void TestState32::resume()
{
    std::cout<< "Resuming : "<< Type() << " \n";
}

void TestState32::HandleEvent(SDL_Event &e )
{
     if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {

      m_pos.x = MOUSEPOSITION.x - m_width/2;

    }
    {

    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
        m_player.y--;

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
        m_player.y++;
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
        m_player.x++;
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
        m_player.x--;
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        std::string Text =  InputHandler::Instance()->GetTextInput();

        if(Text!="")
        {
            SDL_Event UserEvent;
            UserEvent.type =  SDL_USEREVENT;
            UserEvent.user.code = 0;
            UserEvent.user.data1  = new int(stoi(Text));
            UserEvent.user.data2 = new int(((stoi(Text))/(float)1.77777778));
            SDL_PushEvent(&UserEvent);

        }

//InputHandler::Instance()->StopTextInput();
    }
}
