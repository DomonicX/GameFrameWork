#include "TestState17.h"


TestState17::TestState17()
{
    //ctor
}

TestState17::~TestState17()
{
    //dtor
}
void TestState17::Render()
{
    vec2f CamWpos =  Application::Instance()->GetCamera().GetWorldPos();
  //  TextureManager::Instance()->DrawRectFilled(SDL_Rect({0,0,640,360}),Colour_black,App->GetRenderer());

    SDL_FRect mouseBox = alignToTilePosition(MOUSEPOSITION.x,MOUSEPOSITION.y,16);
  //  TextureManager::Instance()->DrawRectsFilled(App->GetRenderer(),&blocks[0],blocks.size(),Colour_blue);
    TextureManager::Instance()->SetColour(Colour_skyblue,APP->GetRenderer());
    for(int i = 0 ; i< 360 ; i++)
        for(int j = 0 ; j< 640 ; j++)
        {
            if(isPointBeingRender(j,i))
//                TextureManager::Instance()->DrawPoint(rects[i][j].x-CamWpos.x,rects[i][j].y-CamWpos.y,APP->GetRenderer());
{

}        }
    TextureManager::Instance()->SetColour(Colour_red,APP->GetRenderer());
//    TextureManager::Instance()->DrawVector(WindowOrigin,m_pos,APP->GetRenderer());

//    TextureManager::Instance()->DrawVector(WindowOrigin,WindowOrigin+vec2f(MOUSEPOSITION-WindowOrigin).GetNormalise().GetRotation(0)*MOUSEPOSITION.Dist(WindowOrigin),APP->GetRenderer());

    TextureManager::Instance()->SetColour(Colour_white,APP->GetRenderer());
    TextureManager::Instance()->SetColour(Colour_ghostwhite,APP->GetRenderer());
    if(isWhite && isBlack){}
    //        TextureManager::Instance()->DrawRectFilled(mouseBox,Colour_hotpink,App->GetRenderer());

 //   TextureManager::Instance()->DrawRects(App->GetRenderer(),&GridLinesRect[0],GridLinesRect.size(),Colour_green);

    line l2 = line({vec2f(WindowOrigin.x,MOUSEPOSITION.y),vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y)});
    line l4 = line({vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y),vec2f(MOUSEPOSITION.x,WindowOrigin.y)});
    line l5 = line({vec2f(WindowOrigin.x,WindowOrigin.y),vec2f(WindowOrigin.x,MOUSEPOSITION.y)});
    line l6 = line({vec2f(MOUSEPOSITION.x,WindowOrigin.y),vec2f(WindowOrigin.x,WindowOrigin.y)});

    TextureManager::Instance()->DrawLine(APP->GetRenderer(),l2,Colour_blanchedalmond);
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),l4,Colour_aqua);
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),l5,Colour_whitesmoke);
    TextureManager::Instance()->DrawLine(APP->GetRenderer(),l6,Colour_whitesmoke);
  //  TextureManager::Instance()->DrawRect(App->GetRenderer(),MousePosition,64,64,Colour_whitesmoke);
}
void TestState17::Update()
{  vec2f CamWpos =  Application::Instance()->GetCamera().GetWorldPos();

    m_oldpos =m_pos;
    m_speedY = 5;
    m_vel = vec2f(WindowOrigin+vec2f(MOUSEPOSITION-WindowOrigin));
    m_vel.Normalise();
    m_vel.Rotate(0);

    m_vel *= MOUSEPOSITION.Dist(WindowOrigin);
    m_pos = m_vel;
    vec2f mouse = vec2f(WindowOrigin+vec2f(MOUSEPOSITION-WindowOrigin).GetNormalise().GetRotation(0)*MOUSEPOSITION.Dist(WindowOrigin));

    SDL_Rect mouseBox = alignToTilePosition((int)MOUSEPOSITION.x,(int)MOUSEPOSITION.y,16);

    isBlack  = false;
    isWhite = false;
    for(int i = 0 ; i< blocks.size(); i++)
    {
        if(isPointBeingRender(blocks[i].x,blocks[i].y))
        if(isPointBeingRender(blocks[i].x+8,blocks[i].y+8))
        blocks[i].y+=1;
    }
    for(int i = 0 ; i< 360 ; i++)
        for(int j = 0 ; j< 640 ; j++)
        {

            vec2f r_tile = vec2f(rects[i][j].x,rects[i][j].y);
            SDL_Rect rect = SDL_Rect {MOUSEPOSITION.x,MOUSEPOSITION.y,1,1};
            SDL_Rect s = SDL_Rect {rects[i][j].x,rects[i][j].y,1,1};

            rects[i][j];
            isRenderAble[i][j];

            if(InputHandler::Instance()->HasPointinRect(rects[i][j],mouseBox))
            {
                if(isRenderAble[i][j])
                    isBlack = true;
                if(!isRenderAble[i][j])
                    isWhite = true;
            }


        }


// Application::Instance()->GetCamera().SetVirtualPos( Application::Instance()->GetCamera().GetWorldPos()+ vec2f(1,0));
//     Application::Instance()->GetCamera().SetVirtualPos((WindowOrigin+(WindowOrigin-MousePosition)));
//     Application::Instance()->GetCamera().SetVirtualPos(vec2f(0,0));
     Application::Instance()->GetCamera().SetVirtualPos(WindowOrigin-MOUSEPOSITION);
}

void TestState17::HandleEvent(SDL_Event &e )
{
    if(e.button.type==SDL_MOUSEBUTTONDOWN)
        blocks.push_back(alignToTilePosition((int)MOUSEPOSITION.x,(int)MOUSEPOSITION.y,16));

}
bool TestState17::OnEnter()
{

    std::string  configInfo = "Land_TileMap.txt";

    std::ifstream ifs;
    ifs.open (configInfo, std::ifstream::in);
    if(ifs.good())
        std::cout << "ifstream loaded "<< configInfo<< ": good\n";
    if(ifs.fail())
        std::cout << "fail\n";
    if(ifs.bad())
        std::cout << "bad\n";

    for(   int i = 0 ; i < 360; i++)

        for(int j = 0 ; j < 640; j++)

        {

            std::string isRender;


            rects[i][j]= SDL_Point{j,i};
            isRender = ifs.get();
            if(isRender == "1")
            {

                isRenderAble[i][j]= true;
            }
            if(isRender=="0")
            {
                isRenderAble[i][j]= false;
            }


        }

    GridLinesRect = MakeGrid(0,0,WindowWidth/8,WindowHeight/8,16);
//    std::cout << rects[800].y<<"jjjjjjjj\n";
    ifs.close();
//
//    SDL_Rect screensize =SDL_Rect({0,0,640,360});
//    SDL_RenderSetViewport(Application::Instance()->GetRenderer(),&screensize );
//    SDL_RenderSetIntegerScale(Application::Instance()->GetRenderer(),SDL_TRUE);
//    SDL_RenderSetLogicalSize(Application::Instance()->GetRenderer(),640,360);
//    SDL_RenderSetScale(Application::Instance()->GetRenderer(),1,1);
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
    return true;
}
bool TestState17::onExit()
{
    return true;
}
void TestState17::resume()
{

}
/** \brief
 *
 * \param
 * \param
 * \return
 *

/** \brief
 *
 * \param
 * \param
 * \return
 *


//m_vel.Normalise();

//        if(!InputHandler::Instance()->HasIntersection(rects[i],alignToTilePosition(MousePosition.x,MousePosition.y,4)))

//            isRenderAble[i][j] = true;

                {

//           isRenderAble[i][j] = true;
                }
//            if(!TileEdge.empty());
//
//            {
//            TileEdge.pop_back();}
//            for(int t = 0; t < GridLinesRect.size(); t++)
//            {
//                if(   (InputHandler::Instance()->hasPointinRect(rects[i][j],GridLinesRect[t])&& !isRenderAble[i][j])
//                        &&
//                        (InputHandler::Instance()->hasPointinRect(rects[i][j],GridLinesRect[t])&& !isRenderAble[i][j]))
//                    TileEdge.push_back(GridLinesRect[t]);
//            }


//m_vel += m_acc * App->GetDeltaTime();
    //  m_pos,m_vel,m_acc,m_oldpos
//
//    vec2f CameraCentre=  Application::Instance()->GetCamera().GetCentre();
//    vec2f Camerapos =  Application::Instance()->GetCamera().GetPos();
//    vec2f CameraSize =  Application::Instance()->GetCamera().GetSize();
//  //  Application::Instance()->GetCamera().GetWorldPos().x += App->GetGameTime();
//
//    m_oldpos= m_pos;
//
////m_acc = vec2f(m_speedY,m_speedY);
//
//    m_vel += m_acc * App->GetDeltaTime();
//
//    m_vel.Limit(5);
////  m_fricton = -m_vel*0.9;
////vec2f::Clamp(0,10,m_vel);
////    m_pos += m_vel + m_fricton;
//    m_pos += m_vel;
// vec2f cc = Application::Instance()->GetCamera().GetCentre();
//
//    if(cc.Dist(m_pos)<=m_mass+128)
//    {
//std::cout << vec2f::Dot(m_pos.GetNormalise(),m_oldpos.GetNormalise())<<"  dot \n";
//   m_pos=  m_oldpos;
//   if(vec2f::Dot(m_pos.GetNormalise(),cc.GetNormalise())>=1)
//{
//        m_vel.Rotate(-90);
//        m_acc.Rotate(-90);
//}else{
//        m_vel.Rotate(90);
//        m_acc.Rotate(90);
//
//        }
////        m_speedY*=-1;
////   m_vel.Rotate(90);
//    }
//
//    if(m_pos.x<=Camerapos.x+m_mass || m_pos.x>=Camerapos.x+CameraSize.x-m_mass)
//    {
//   m_pos=  m_oldpos;
//
//        m_vel.x*=-1;
//        m_acc.x*=-1;
//
//    }
//
//
//    if(m_pos.y<=Camerapos.y+m_mass ||m_pos.y>=Camerapos.y+CameraSize.y-m_mass)
//    {
//   m_pos=  m_oldpos;
//
//        m_vel.y*=-1;
//     m_acc.y*=-1;
//
//    }
//
//
//
//
//
//
//    /**<
//
//
//
//    //    if(!m_spawnBlocks)
//    //    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
//    //    {
//    //    m_spawnBlocks = true;
//    //    }
//    //    else
//    //    {
//    //    m_spawnBlocks = false;
//    //
//    //    }
//
//    //    if(inputHandler->GetMouseButtonState(mouse_Buttons::RIGHT))
//    //    {
//    //          for (int i = 0 ; i < p->GetNumberOfPartices() ; i++)
//    //
//    //         if(!p->getParticles(i).Dead())
//    //    p->getParticles(i).SetDead(true);
//    //
//    Rectangle a = {WindowOrigin,WindowOrigin+(MousePosition-WindowOrigin)};
//
//    vec2f  b = (MousePosition);
//    b-=WindowOrigin;
//
//    b.Normalise();
////    b.GetRotation(90);
//    b*=vec2f::Dist(WindowOrigin,MousePosition);
//    b+=WindowOrigin;
//    std::cout << b << " : " << vec2f::Dist(WindowOrigin,MousePosition)  <<"\n";
//    //a.rectBottomRight.Rotate(45);
//// a.rectTopLeft.Rotate(45);
//    TextureManager::Instance()->SetColour(Colour_green,App->GetRenderer());
////   SDL_RenderDrawLine(App->GetRenderer(),a.rectBottomRight.x,a.rectBottomRight.y,a.rectBottomRight.x+a.rectTopLeft.x,a.rectBottomRight.y);
////   SDL_RenderDrawLine(App->GetRenderer(),a.rectBottomRight.x,a.rectBottomRight.y,a.rectBottomRight.x,a.rectBottomRight.y+a.rectTopLeft.y);
////   SDL_RenderDrawLine(App->GetRenderer(),a.rectBottomRight.x+a.rectTopLeft.x,a.rectBottomRight.y+a.rectTopLeft.y,a.rectBottomRight.x,a.rectBottomRight.y+a.rectTopLeft.y);
////   SDL_RenderDrawLine(App->GetRenderer(),a.rectBottomRight.x+a.rectTopLeft.x,a.rectBottomRight.y+a.rectTopLeft.y,a.rectBottomRight.x+a.rectTopLeft.x,a.rectBottomRight.y);
//
//
//    TextureManager::Instance()->SetColour(Colour_violet,App->GetRenderer());
////TextureManager::Instance()->DrawVector(MousePosition,WindowOrigin,App->GetRenderer());
//    TextureManager::Instance()->DrawVector(WindowOrigin,b,App->GetRenderer());

//
//TextureManager::Instance()->DrawGrid(0,0,640,360,4,Colour_greenyellow,App->GetRenderer());
////  2*|a|(n.a)/a
////r=    2(d.n)n
////r = reflection vector
////d = normalised incoming vector
////n = normalised of surface its reflecting off
////(d.n) = is the dot product of d and n;
////v,dn,sn,ref
//    {
//
//
//
//        TextureManager::Instance()->SetColour(Colour_grey,App->GetRenderer());
//        vec2f Camerapos =  Application::Instance()->GetCamera().GetPos();
//        vec2f CameraSize = Application::Instance()->GetCamera().GetSize();
//        vec2f m = inputHandler->GetMousePosition() ;
//        vec2f o =  Application::Instance()->GetCamera().GetCentre();
//        SDL_Rect CameraPixelPos = App->GetWindow()->GetWidget()->GetChild(1).GetHitBox();
//        int CameraOffSet = Application::Instance()->GetCamera().GetWorldPos().x;
//
//
//        Rectangle rectCamera = Application::Instance()->GetCamera().GetRectangle();
//        SDL_Rect  Rectcam =  Application::Instance()->GetCamera().GetRect();
//
//
//        TextureManager::Instance()->DrawRectFilled(CameraPixelPos,Colour_black,App->GetRenderer());
//
//        for (int i = 0 ; i < p->GetNumberOfPartices() ; i++)
//        {
//            Rectangle t = {   p->getParticles(i).GetPosition(),vec2f(16,16)};
//
//            SDL_Rect prect = {p->getParticles(i).GetPosition().x, p->getParticles(i).GetPosition().y,16,16};
//
//            if(InputHandler::Instance()->HasIntersection(prect,Rectcam))
//                TextureManager::Instance()->DrawRectFilled(t,Colour_aqua,App->GetRenderer());
//            else
//                TextureManager::Instance()->DrawRectFilled(t,Colour_hotpink,App->GetRenderer());
//
//        }
////TextureManager::Instance()->DrawRect(Rectcam,Colour_white,1,App->GetRenderer());
//        //  TextureManager::Instance()->DrawLine(Camerapos,Camerapos+CameraSize,App->GetRenderer());
//        TextureManager::Instance()->DrawRect(rectCamera,Colour_salmon,App->GetRenderer());
//        Yaxis = vec2f(0,-CameraSize.y/2);
//
//       // TextureManager::Instance()->DrawVector(o,o+Yaxis,App->GetRenderer());
//        Xaxis = vec2f(CameraSize.x/2,0);
//
//        TextureManager::Instance()->DrawVector(o,o+Xaxis,App->GetRenderer());
//
//       TextureManager::Instance()->DrawVector(o,o+Yaxis,App->GetRenderer());
//                 TextureManager::Instance()->DrawVector(o,m,0,Colour_antiquewhite,App->GetRenderer());
////   std::cout <<  vec2f::Dist(o,m)  <<"    "<< o.Dist(m) <<"    "<< CameraSize <<"dot " << vec2f::Dot(Yaxis.Normalise(),Xaxis.Normalise()) <<"\n";
//
// vec2f cc = Application::Instance()->GetCamera().GetCentre();
//
//        vec2f pos = m_pos;
//        float r = -2;
//    if(cc.Dist(m_pos)<=m_mass+64)
//    {
//        cc.Normalise();
//        pos.Normalise();
//        r = vec2f::Dot(pos,cc);
////m_vel.Rotate(-r);
//    }
// TextureManager::Instance()->DrawText((float)r,rectCamera.rectTopLeft.x,rectCamera.rectTopLeft.y+256,FontManager::Instance()->GetFont("OpenSans-Regular"),App->GetRenderer());
//
//
//        TextureManager::Instance()->DrawText(m_vel.Length(),rectCamera.rectTopLeft.x,rectCamera.rectTopLeft.y,FontManager::Instance()->GetFont("OpenSans-Regular"),App->GetRenderer());
//        TextureManager::Instance()->DrawText(m_acc.Length(),rectCamera.rectTopLeft.x,rectCamera.rectTopLeft.y+64,FontManager::Instance()->GetFont("OpenSans-Regular"),App->GetRenderer());
//        TextureManager::Instance()->DrawText((int)App->GetGameTime(),rectCamera.rectTopLeft.x,rectCamera.rectTopLeft.y+128,FontManager::Instance()->GetFont("OpenSans-Regular"),App->GetRenderer());
//
//    }
//
//    /**<
//
//
//
//    //     TextureManager::Instance()->DrawVector(o+Yaxis,o+Xaxis,App->GetRenderer());
//
//    //TextureManager::Instance()->DrawVector(o,o+Xaxis,0,Colour_black,App->GetRenderer());
//    //        TextureManager::Instance()->DrawRectFilled(r[index],Colour_hotpink,App->GetRenderer());
//    // TextureManager::Instance()->Drawcircle(App->GetRenderer(),Colour_bisque,8,false);
//    //TextureManager::Instance()->DrawPoint(  p->getParticles(i).GetPosition().x,  p->getParticles(i).GetPosition().y,App->GetRenderer());
//    // TextureManager::Instance()->DrawLine(  p->getParticles(i).GetPosition().x,  p->getParticles(i).GetPosition().y,p->getParticles(i).GetPosition().x,0,Colour_aqua,App->GetRenderer());
//    //TextureManager::Instance()->DrawRects(App->GetRenderer(),&r[0],r.size());
//    //TextureManager::Instance()->SetColour(Colour_darkcyan,App->GetRenderer());
//    //TextureManager::Instance()->DrawVector(s,App->GetOrigin(),App->GetRenderer());
//    //framec=vec2f::Dist(m,o);
//    //  TextureManager::Instance()->DrawLine(0,0,App->GetWindowWidth()/2,App->GetWindowHeight()/2,Colour_cornflowerblue,App->GetRenderer());
//    //std::vector<SDL_Rect> r = MakeGrid(CameraPixelPos.x,
//    //                                   CameraPixelPos.y,31,18,32);
//    //  yAxis.Normalise();
//    // xAxis.Normalise();
//    // yAxis *= App->GetYAxis().Length()/2;
//    // xAxis *= App->GetXAxis().Length()/2;
//
//    // yAxis=m+o ;
//    //yAxis.Limit(o.Dist(m));
//    //     TextureManager::Instance()->SetColour(Colour_white,App->GetRenderer());
//    //  TextureManager::Instance()->DrawVector(o,yAxis+o,App->App->GetRenderer());
//    //  TextureManager::Instance()->DrawVector(o,xAxis+o,App->App->GetRenderer());
//    //     TextureManager::Instance()->SetColour(Colour_black,App->GetRenderer());
//    //  TextureManager::Instance()->DrawVector(yAxis+o,xAxis+o,App->App->GetRenderer());
//    //  TextureManager::Instance()->DrawLine(App->GetWindowWidth()/2+100,App->GetWindowHeight()/2,App->GetWindowWidth()/2,App->GetWindowHeight()/2,Colour_cornflowerblue,App->GetRenderer());
//    //
//
//    //  TextureManager::Instance()->DrawLine(App->GetWindowWidth()/2,App->GetWindowHeight()/2-100,App->GetWindowWidth()/2,App->GetWindowHeight()/2,Colour_cornflowerblue,App->GetRenderer());
//
//    TextureManager::Instance()->Drawcircle(App->GetRenderer(),
//                                           Application::Instance()->GetCamera().GetCentre().x,
//                                           Application::Instance()->GetCamera().GetCentre().y,Colour_red
//                                           ,128
//                                           ,false);
//
//    TextureManager::Instance()->Drawcircle(App->GetRenderer(),m_pos.x,m_pos.y,Colour_red,m_mass,true);
//    vec2f m = m_vel;
//    m.Normalise();
//    m*=m_mass;
//    m+=m_pos;
//    float l = m.Length();
//    TextureManager::Instance()->DrawLine(m_pos.x,m_pos.y,m.x,m.y,Colour_aqua,App->GetRenderer());
//    TextureManager::Instance()->DrawLine(Application::Instance()->GetCamera().GetCentre().x,Application::Instance()->GetCamera().GetCentre().y,
//                                         m.x,m.y,
//                                         Colour_aqua,
//                                         App->GetRenderer());
//
//  TextureManager::Instance()->DrawVector(Application::Instance()->GetCamera().GetCentre(),
//                                         Application::Instance()->GetCamera().GetPos(),
//                                         App->GetRenderer());
//
//
//vec2f Mouse = inputHandler->GetMousePosition() ;
//
//    SDL_Rect CameraPixelPos = App->GetWindow()->GetWidget()->GetChild(1).GetHitBox();
//
//framec++;
////
////    SDL_Surface *ss =   SDL_CreateRGBSurface(0,m_pos.x,m_pos.y,32,0,0,0,0);
////    SDL_FillRect(ss,&CameraPixelPos, SDL_MapRGBA(ss->format,0,255,0,0));
////
////    SDL_Texture  * tt = SDL_CreateTextureFromSurface(App->GetRenderer(),ss);
//////    SDL_SetTextureBlendMode(tt,SDL_BLENDMODE_ADD);
////    SDL_SetTextureAlphaMod(tt,framec%255);
////    SDL_SetTextureColorMod(tt,0,126,126);
////    SDL_RenderCopy(App->GetRenderer(),tt,NULL,NULL);
//
////
//////std::cout << RectCamera.x << " " << RectCamera.y << " " << RectCamera.w << " " << RectCamera.h << "\n";
//
//  LTexture t;
//  if(t.LoadFromRendered(App->GetRenderer(),CameraPixelPos.w/2,CameraPixelPos.h/2,Colour_darkseagreen,SDL_BLENDMODE_ADD,128)){
////std::cout << "should work1\n";
//  }
//
//
//
//
//
//
//
////    SDL_RenderCopy(App->GetRenderer(),t.GetSDLTexture(),NULL,NULL);
//
////    SDL_FreeSurface(ss);
//  //  SDL_DestroyTexture(tt);
//
//
//    vec2f CameraCentre=  Application::Instance()->GetCamera().GetCentre();
//  t.Render(App->GetRenderer(),CameraCentre.x,CameraCentre.y);




//  TextureManager::Instance()->DrawLine(m_pos.x,m_pos.y,m_pos.x,App->GetCamera().GetPos().y+App->GetCamera().GetSize().y,Colour_aqua,App->GetRenderer());
//TextureManager::Instance()->DrawLine(m_pos.x,m_pos.y,App->GetCamera().GetPos().x,m_pos.y,Colour_aqua,App->GetRenderer());
//TextureManager::Instance()->DrawLine(m_pos.x,m_pos.y,App->GetCamera().GetPos().x+App->GetCamera().GetSize().x,m_pos.y,Colour_aqua,App->GetRenderer());
//


//         SDL_Rect m_hitBox = {100,100,48*10,48*10};
//
//        TextureManager::Instance()->DrawRectFilled(m_hitBox,Colour_white,App->GetRenderer());
//
//
//       SDL_Rect src = {0,0,48,48};
//        TextureManager::Instance()->DrawTileBox(App->GetRenderer(),"GUI_TileSheet",16,m_hitBox,src);
//
//
//SDL_Rect src = Application::Instance()->GetWindow()->GetWidget()->GetChild(1).GetHitBox();
//  TextureManager::Instance()->DrawRectFilled(src,Colour_white,App->GetRenderer());
//TextureManager::Instance()->drawTextureText(App->GetRenderer(),"Sprite-0003",src);
 */

//
//    int randomRotation = App->GetRandomNumber()%360;
//        ccount++;
//    if(ccount > 60)
//    {
//
//        ccount = 0;
//    index = App->GetRandomNumber()%r.size();
//    }
//    if(m_spawnBlocks)
//    {
//        m_spawnBlocks = false;
//        for (int i = 0 ; i < p->GetNumberOfPartices() ; i++)
//        {
//            if(p->getParticles(i).Dead())
//            {
//                // p->getParticles(i).SetDead(false);
//                p->getParticles(i).SetPosition(vec2f(InputHandler::Instance()->GetMousePosition()));
//
//                p->getParticles(i).SetSpeed(App->GetRandomNumber()/100);
//                p->getParticles(i).GetAcceleration().Normalise().Rotate(90);
//                if(App->GetRandomNumber()/100<=50)
//                    p->getParticles(i).SetAcceleration(vec2f(1,-1));
//                else
//                    p->getParticles(i).SetAcceleration(vec2f(-1,1));
//
//                break;
//            }
//        }
//    }
//
//    p->Update(App->GetDeltaTime());
//
//    //  std::cout << Application::Instance()->GetCamera().GetPos().x << "\n";
//    for (int i = 0 ; i < p->GetNumberOfPartices() ; i++)
//    {
//        if(p->getParticles(i).GetPosition().x> App->GetOrigin().x*2|| p->getParticles(i).GetPosition().x < 0)
//        {
//
//            p->getParticles(i).SetPosition(vec2f(i,0));
//        }
//        if(p->getParticles(i).GetPosition().y>= App->GetOrigin().y*2)
//        {
//
//            p->getParticles(i).SetPosition(vec2f(   p->getParticles(i).GetPosition().x,App->GetOrigin().y*2));
//        }
//    }
//    */
/**<


//            if(InputHandler::Instance()->hasPointinRect(j,i,alignToTilePosition(MousePosition.x,MousePosition.x,8))
//            if(InputHandler::Instance()->hasPointinRect(j,i,box))
//               {
//
//    TextureManager::Instance()->SetColour(Colour_violet,App->GetRenderer());
//
//            if(isRenderAble[i][j])
//                TextureManager::Instance()->DrawPoint(rects[i][j].x,rects[i][j].y,App->GetRenderer());
//
//               }else
//
//    TextureManager::Instance()->SetColour(Colour_seashell,App->GetRenderer());
//  if(isRenderAble[i][j])
//  TextureManager::Instance()->DrawRectFilled(alignToTilePosition(MousePosition.x,MousePosition.y,256),App->GetRenderer());
//    if(!TileEdge.empty())
//        TextureManager::Instance()->DrawRectsFilled(App->GetRenderer(),&TileEdge[0],TileEdge.size(),Colour_skyblue);

         if(InputHandler::Instance()->HasIntersection(s,rect))
                if(r_tile.Dist(MousePosition)>64 )
            SDL_Point pos = SDL_Point({m_pos.x,m_pos.y});
            if(InputHandler::Instance()->hasPointinRect(pos,s) && !isRenderAble[i][j])
            {
                m_pos = m_oldpos;
            }
        }
//    vec2f camsize = App->GetCamera().GetSize();
//    vec2f campos = App->GetCamera().GetPos();
////std::cout << App->GetCamera().GetScaler() << "\n";
//    SDL_Rect cam  = {campos.x,campos.y,camsize.x,camsize.y};
//    TextureManager::Instance()->DrawRectFilled(cam,Colour_green,App->GetRenderer());
//    TextureM
//
//if(App->isChangingState())
//{ App->PushCommand_StateMachine("Push_State","TestState16");
//
// //App->PushCommand_StateMachine("Push_State","TestState18");
//
// App->SetLevelComplete(false);
//}
//    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
//    {
//
//
//
//    }
void TestState17::CreateFrame()
{
    SDL_FRect cam  = {App->GetCamera().GetPos().x,
    App->GetCamera().GetPos().y,
    App->GetCamera().GetSize().x,
    App->GetCamera().GetSize().y};

    vec2f o =  App->GetOrigin();
    GUI_Wigdet * frame = guiFactory->Create("GUI_Frame");
    App->PushCommand_Wigdet(frame,"Set_Frame","Frame");
    dynamic_cast<GUI_Frame*>(frame)->init("Frame", {0,0, o.x*2, o.y*2});


}

void TestState17::CreatePannels()
{
 SDL_FRect cam  = {App->GetCamera().GetPos().x,
 App->GetCamera().GetPos().y,
 App->GetCamera().GetSize().x,
 App->GetCamera().GetSize().y};

    vec2f o =  App->GetOrigin();
    GUI_Wigdet *  pannel = guiFactory->Create("GUI_Pannel");
    App->PushCommand_Wigdet(pannel,"Add_Pannel","Header");
    pannel->SetVisable(false);
    dynamic_cast<GUI_Pannel*>(pannel)->Init(SDL_FRect{cam.x,0,o.x*2,cam.y});

    pannel = guiFactory->Create("GUI_Pannel");
    App->PushCommand_Wigdet(pannel,"Add_Pannel","GameView");
    dynamic_cast<GUI_Pannel*>(pannel)->Init(SDL_FRect{cam.x,cam.y,cam.w,cam.h});

    pannel = guiFactory->Create("GUI_Pannel");
    App->PushCommand_Wigdet(pannel,"Add_Pannel","SceneTree");
    pannel->SetVisable(false);
    dynamic_cast<GUI_Pannel*>(pannel)->Init(SDL_FRect{cam.w+cam.x,cam.y,o.x*2-cam.x-cam.w,o.y*2/2});


    pannel = guiFactory->Create("GUI_Pannel");
    App->PushCommand_Wigdet(pannel,"Add_Pannel","GameObjectSelection");
    pannel->SetVisable(false);
    dynamic_cast<GUI_Pannel*>(pannel)->Init(SDL_FRect{cam.w+cam.x,cam.y+o.y*2/2,o.x*2-cam.x-cam.w,o.y*2/2});



    pannel = guiFactory->Create("GUI_Pannel");
    App->PushCommand_Wigdet(pannel,"Add_Pannel","GameObjectEditor");
    pannel->SetVisable(false);
    dynamic_cast<GUI_Pannel*>(pannel)->Init(SDL_FRect{cam.x,cam.y+cam.h,cam.w,o.y*2-cam.y-cam.h});


//    pannel = guiFactory->Create("GUI_Pannel");
//    dynamic_cast<GUI_Pannel*>(pannel)->SetHitBox(SDL_FRect{8,360+76,o.x,o.y*2-360-76-12});
//    pannel->SetVisable(true);
//    App->PushCommand(new Cmd::AppCommands(App->GetWindow(),
//                                          pannel,
//                                          "Add_Pannel","GameObjectEditer"));


    // Application::Instance()->PushCommand_StateMachine("Pop_State","");
}


void TestState17::CreateCamera()
{
}

{

    frame->Add(guiFactory->Create("GUI_Pannel"));
    frame->GetChild(0).SetHitBox(SDL_FRect{0,0,o.x,o.y});
    frame->GetChild(0).SetPosition(vec2f(frame->Getposition().x+26,frame->Getposition().y));

    frame->Add(guiFactory->Create("GUI_Pannel"));
    frame->GetChild(1).SetHitBox(SDL_FRect{o.x,0,o.x,o.y});
    frame->GetChild(1).SetPosition(vec2f(frame->Getposition().x+26,frame->Getposition().y+26));

    frame->Add(guiFactory->Create("GUI_Pannel"));
    frame->GetChild(2).SetHitBox(SDL_FRect{o.x,o.y,o.x,o.y});
    frame->GetChild(2).SetPosition(vec2f(frame->Getposition().x+26,frame->Getposition().y+26+26));

    frame->Add(guiFactory->Create("GUI_Pannel"));
    frame->GetChild(3).SetHitBox(SDL_FRect{0,o.y,o.x,o.y});
 frame->GetChild(3).SetPosition(vec2f(frame->Getposition().x+26,frame->Getposition().y+26+26+26));

   frame->GetChild(3).Add(guiFactory->Create("GUI_Menu"));
frame->GetChild(3).GetChild(0).SetPosition(vec2f(frame->Getposition().x,frame->Getposition().y+26+26+26));
    App->PushCommand(new Cmd::AppCommands(App->GetWindow(),
                                          frame,
                                          "Set_Frame",""));
   App->PushCommand_Wigdet(frame,"Set_Frame","");


    GUI_Wigdet * pannel = guiFactory->Create("GUI_Pannel");

  dynamic_cast<GUI_Pannel*>(pannel)->SetHitBox(SDL_FRect{0,100,o.y,26});
  dynamic_cast<GUI_Pannel*>(pannel)->SetPosition(vec2f(o.x,0));
 App->PushCommand_Wigdet(pannel,"Add_Pannel","Add_Pannel");
  dynamic_cast<GUI_Pannel*>(pannel)->SetHitBox(SDL_FRect{209,100,o.y,26});
 App->PushCommand_Wigdet(pannel,"Add_Pannel","Add_Pannel");

    frame->Add(guiFactory->Create("GUI_Pannel"));
    frame->GetChild(0).SetHitBox(SDL_FRect{o.x*2-512,26+2,512,o.y+242});
    frame->GetChild(0).SetPosition(vec2f(o.x,o.y));


    frame->Add(guiFactory->Create("GUI_Pannel"));
    frame->GetChild(1).SetHitBox(SDL_FRect{0,26+2,o.x/3,o.y+242});
    frame->GetChild(1).SetPosition(vec2f(o.x,o.y+32));

    frame->GetChild(0).Add(guiFactory->Create("GUI_Menu"));
    frame->Add(guiFactory->Create("GUI_Pannel"));
    GUI_Wigdet * pannel = guiFactory->Create("GUI_Pannel");

  dynamic_cast<GUI_Pannel*>(pannel)->SetHitBox(SDL_FRect{0,5,o.x*2,26});
  dynamic_cast<GUI_Pannel*>(pannel)->SetPosition(vec2f(o.x,0));


    App->PushCommand(new Cmd::AppCommands(App->GetWindow(),
                                          pannel,
                                          "Add_Pannel","Add_Pannel"));

}

{

    GUI_Wigdet * pannel = guiFactory->Create("GUI_Pannel");

  dynamic_cast<GUI_Pannel*>(pannel)->SetHitBox(SDL_FRect{0,100,o.y,26});
//  dynamic_cast<GUI_Pannel*>(pannel)->SetPosition(vec2f(o.x,0));

    App->PushCommand(new Cmd::AppCommands(App->GetWindow(),
                                          pannel,
                                          "Add_Pannel","Add_Pannel"));

}
   */
