#include "TestState37.h"

TestState37::TestState37()
{
    //ctor
}

TestState37::~TestState37()
{
    std::cout  << "~TestState37\n";
    //dtor
    m_gameObects.clear();
    obj.clear();
    OBJECT.clear();
    obj2.clear();
}

void  TestState37::Render(SDL_Renderer* r)
{

    /**<
        TextureManager::Instance()->SetColorMod("blank",Colour_greenyellow);
        for(int i = 0; i <= CAMRECT.w/16; i++)
            for(int j = 0; j <= CAMRECT.h/16; j++)
                TextureManager::Instance()->drawSprite("Block",i*16,j*16,16,16,r,SDL_FLIP_NONE);
    //  TextureManager::Instance()->DrawRects(r,&tempRect[0],tempRect.size(),Colour_blueviolet,false);
        int tile = 24;
        TextureManager::Instance()->DrawGrid(0,0,CAMRECT.w/((float)tile * CAMSCALER),CAMRECT.h/((float)tile * CAMSCALER),(tile * CAMSCALER),Colour_white,r);

        SDL_Rect m = {MOUSEPOSITION.x,MOUSEPOSITION.y,32,32};
        m = alignToTilePosition((int)MOUSEPOSITION.x,(int)MOUSEPOSITION.y,32);
        SDL_Rect mt = InputHandler::Instance()->HasPointinRects(m.x,m.y,&tempRect[0],tempRect.size());


        TextureManager::Instance()->DrawRect(r,mt,Colour_blueviolet,false);
        // std::cout << +timer.GetTicks()/1000 << "\n ";

        if(!obj.empty())
            for(int i = 0 ; i < obj.size(); i++)

                if(obj[i]!=NULL)
                    obj[i]->Render(r,0,0);

        m_player->Render(r,0,0);
        TextureManager::Instance()->drawSprite("Spikes",(MOUSEPOSITION.x+64)+16,(MOUSEPOSITION.y+64),32,16,r,SDL_FLIP_NONE);

    //   TextureManager::Instance()->Drawcircle(r,MOUSEPOSITION.x,MOUSEPOSITION.y,Colour_white,32,true);
    //TextureManager::Instance()->SetBlendMode("Block",SDL_BLENDMODE_MUL)
        LTexture *lt =new  LTexture();
        lt->LoadFromRendered(r,640,360,SDL_Color({45,45,45}),SDL_BLENDMODE_BLEND,64);
        SDL_FPoint aaaaa = SDL_FPoint({0,0});

        std::vector<vec2f>dd;
        for(int i = 0; i < 32; i++)
        for(int j = 0; j < 28; j++)
        {
            dd.push_back(vec2f(j*8,i*8));
        }

        if(!dd.empty())
        {

    //size_t size1 = sizeof(dd) / sizeof(dd[0]);
    // std::vector<vec2f>  nn = Findpath(&dd[0],dd.size(),vec2f(GameGrid[4][4],GameGrid[4][4]),vec2f(6,10),28,8);
    //std::cout << nn[0] <<"\n";
        }
    //    std::vector<SDL_FPoint>  nn  = FindPath3(alignToVec2Position(vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y),24),alignToVec2Position(WindowOrigin,24),24);

        for(int i = 0 ; i  < OBJECT.size(); i ++)
        {
            OBJECT[i]->Render(r,0,0);
    //
    //  std::cout <<  OBJECT[i]->Type() << "\n";

        }
        SDL_FRect b2 {200,200,200,200};
        SDL_FRect b3 {MOUSEPOSITION.x,MOUSEPOSITION.y,100,100};

        SDL_FRect ss =  GetIntersectRect(b3,b2);
    //TextureManager::Instance()->DrawRect(r,b3,Colour_green,true);
    //TextureManager::Instance()->DrawRect(r,b2,Colour_red,true);
    //TextureManager::Instance()->DrawRect(r,ss,Colour_gainsboro,true);

        for(int i = 0 ; i < 10 ; i++)
        {
            float w =  (i/(float)10);

            //   std::cout << w<< " w \n";
            TextureManager::Instance()->DrawPoint(r,i,WindowHeight/2,Colour_darkgray);
        }
        // std::cout << "Frame end\n";


        vec2f m2 = -(WindowOrigin-MOUSEPOSITION);

        TextureManager::Instance()->DrawVector(r,WindowOrigin,m2,Colour_red);
        m2.Ortho();
        TextureManager::Instance()->DrawVector(r,WindowOrigin,m2,Colour_blue);
        TextureManager::Instance()->DrawVector(r,WindowOrigin+m2,-(WindowOrigin-MOUSEPOSITION),Colour_green);
        TextureManager::Instance()->DrawVector(r,WindowOrigin+m2+-(WindowOrigin-MOUSEPOSITION),vec2f(WindowOrigin-MOUSEPOSITION).GetOrtho(),Colour_green);


        m_ParticleSystem.Render(r,"circle");


    //    TextureManager::Instance()->DrawVector(r,Offset+m_pos,Offset+vec2f(m_endPoint-m_pos).GetRotation(m_fuzziDegree),Colour_darkblue);
    //    TextureManager::Instance()->DrawVector(r,Offset+m_pos,Offset+vec2f(m_endPoint-m_pos).GetRotation(-m_fuzziDegree),Colour_darkblue);
    //    TextureManager::Instance()->Drawcircle(r,Offset.x+m_pos.x+Offset.x,m_pos.y+Offset.y,Colour_red,16,false);

    //
    //    for(int i = 0 ; i < Pac_Man_Tile_col ; i++)
    //        for(int j = 0 ; j < Pac_Man_Tile_Row; j++)
    //
    //            if(!Gamemap[i][j])
    //    TextureManager::Instance()->DrawRects(r,&m_Path[0],m_Path.size(),Colour_red,false);

       // TextureManager::Instance()->DrawVector(r,m_pacman->GetPosition()+8,dynamic_cast<SDLGameObject*>(m_pacman)->GetVelocity() *dynamic_cast<SDLGameObject*>(m_pacman)->GetMass(),Colour_darkseagreen);

    //    std::cout << dynamic_cast<GameObject_PacMan*>(m_pacman)->GetDir() << "\n";
    //
    //    std::vector<SDL_FPoint>  nn  = FindPath3(alignToVec2Position(m_pacman->GetPosition()+vec2f(m_pacman->getWidth()/2,m_pacman->getHeight()/2),8),alignToVec2Position(MOUSEPOSITION,8),8);
    //    if(!nn.empty())
    //    {
    //
    //       // for(int i = 0; i < nn.size(); i++) std::cout << nn[i];
    // for(int i = 1; i < nn.size(); i++)
    // {
    //   TextureManager::Instance()->DrawLine(r,nn[i].x,nn[i].y,nn[i-1].x,nn[i-1].y,Colour_forestgreen);
    ////   TextureManager::Instance()->DrawVector(r,vecToPoint(nn[i]),vec2f(0,100),Colour_white);
    // }
    // std::cout << nn.size() << "\n";
    //    }
      */


    vec2f pacmanBackGroundSize = vec2f((WindowWidth/224)*(int)224,(WindowHeight/248)*(int)248);
    vec2f PacmanBackGroundPos = vec2f(CAMCENTRE.x-pacmanBackGroundSize.x/2,CAMCENTRE.y-pacmanBackGroundSize.y/2);
    TextureManager::Instance()->drawSprite("PacManBackGround",PacmanBackGroundPos.x,PacmanBackGroundPos.y,pacmanBackGroundSize.x,pacmanBackGroundSize.y,r,SDL_FLIP_NONE);
//    draw fruits
//    draw ghost
//    draw powerpoellet
    m_pacman->Render(r,0,0);
//m_Path1
    for(int i = 0 ; i < Pac_Man_Tile_col ; i++)
        for(int j = 0 ; j < Pac_Man_Tile_Row; j++)
            if(!Gamemap[i][j])
                TextureManager::Instance()->DrawRect(r,SDL_FRect{j*8+4,i*8+4,4,4},Colour_navy,false);

    SDL_RenderDrawPoints(r,&m_Path1[0],m_Path1.size());

//Node.

}

void TestState37::Update(float dt)
{
    /**<
        ani.Update(dt);

        m_pacman->Update(dt);
        m_ParticleSystem.Update(dt);

        if(!obj.empty())
            for( GameObject* i : obj)
            {
                if(i!=NULL)
                {
                    if( auto * s =  dynamic_cast<GameObject_Ghost*>(i) )
                        dynamic_cast<GameObject_Ghost*>(s)->SetTarget(MOUSEPOSITION);

                    i->Update(dt);

                    if(CollisionManager::Instance()->Check(i))
                    {
                        //  std::cout << i->Type() << "\n";
                        //  i->Collision();


                        //CollisionManager::Instance()->Remove(i);
                    }
                    if(i->Dead())
                    {

    //                    CollisionManager::Instance()->Remove(i);
                    }
                }

            }
        m_player->Update(dt);

        int ssss = CollisionManager::Instance()->check(m_player).size();
        std::vector<GameObject*> ss= CollisionManager::Instance()->check(m_player);
        for(int i = 0 ; i < ssss ; i++)
        {
            //   std::cout << ss[i]->Type() << " Collision  -  player\n";
            //     if(ss[i]->Type()=="Spikes")
            m_player->Collision(ss[i]);
        }

        ss.clear();

        int d3 =CollisionManager::Instance()->check(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre()).size();
        //       std::cout << d3 << "\n";
        std::vector<GameObject*> Es= CollisionManager::Instance()->check(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre());
        for(int i = 0 ; i < d3 ; i++)
        {
    //        std::cout << ss[i]->Type() << " Collision  -  player\n";
    //          if(Es[i]->Type()=="blank")
            if(Es[i]->Type()=="tile3")
                m_pacman->Collision(Es[i]);
        }

        if(CollisionManager::Instance()->Check(m_player))
        {
    //   m_player->Collision();

    //       playerBot = GetRectHitPoint(8,dynamic_cast<SDLGameObject*>(m_player)->GetSDLRectF());
    //
    //       if(InputHandler::Instance()->HasPointinRect(playerBot,dynamic_cast<SDLGameObject*>(m_player)->GetSDLRectF()))
    //       {
    //           SDL_Quit();
    //       }
        }

        if(checkIfOffPath(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre()))
        {
    //    SDL_Quit();
            m_pacman->GetPosition().x  = dynamic_cast<SDLGameObject*>(m_pacman)->GetlastPosition().x;
            m_pacman->GetPosition().y  = dynamic_cast<SDLGameObject*>(m_pacman)->GetlastPosition().y;
        }
        int cc = 0;
        for(int i = obj.size()-1 ; i >= 0; i--)
            if(obj[i]->Dead())
            {
                cc++;
                // delete obj[i];
    //                       CollisionManager::Instance()->Remove(obj[i]);
    //                    obj.erase(obj.begin()+ i);
            }
        //  std::cout << cc << "dead \n";
        if(cc==obj.size())
        {

            for(int i = obj.size()-1 ; i >= 0; i--)
            {
                delete obj[i];
                CollisionManager::Instance()->Remove(obj[i]);
                obj.pop_back();
            }
        }
     */

}

bool TestState37::checkIfOffPath(vec2f v)
{
    bool  isOffPath = true;
    for(int i =0 ; i < m_Path.size(); i++)
        if(InputHandler::Instance()->HasPointinRect(v,m_Path[i]))
        {
            isOffPath = false;
        }
    return isOffPath;

}
bool TestState37::OnEnter()
{      std::cout  << "OnEnter \n";
    SDL_Rect ss = {0,0,224,248};

//    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//     SDL_RenderSetViewport(APP->GetRenderer(),&ss);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),224,248);
////    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
////SDL_RenderSetClipRect(APP->GetRenderer(),&ss);
//
//
////Application::Instance()->GetWindow()->ResizeWindow(1920,1080);
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN);
////    Application::Instance()->GetCamera().SetSize(vec2f(1920,1080));
////  Application::Instance()->GetCamera().SetScaler(3);
////    for(int i = 0 ; i < 10 ; i++)
//    for(int j = 0 ; j < 10 ; j++)
//    Gamemap[i][j] = ;
//(j+(i*40))vec2f(256,224)
    int sx = 256/8;
    int sy = 224/8;

    std::cout <<sx << "\n";
    std::cout <<sy << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout <<sx << "\n";
    std::cout <<sy << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout <<sx << "\n";
    std::cout <<sy << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout <<sx << "\n";
    std::cout <<sy << "\n";
    for(int i = 0 ; i <= Pac_Man_Tile_col ; i++)
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
            Gamemap[i][j] = true;

    DirectoryHandler::Instance()->Load("PacManCollisionMap.txt");
    LFile & File = *DirectoryHandler::Instance()->GetFileMap()["PacManCollisionMap.txt"];
    std::string sssss= File.GetFileData();

    std::cout <<  sssss << "\n";
    File.OutPutTxtFile("pacmanc.txt",DirectoryHandler::Instance()->GetFileBase());
//std::stringstream aa;
////dd
//aa << sssss;
//"pacmanc.txt"

//std::cout << aa.str() << "\n";
    int cc = 0;
    for(int i = 0 ; i < sssss.size(); i++ )
    {

        char a = sssss[i];
        int x = (i%Pac_Man_Tile_Row)*8;
        int y = (i/(int)Pac_Man_Tile_Row)*8;

        if(a=='2')
        {
            Gamemap[y/8][x/8] = true;

        }
        else if(a=='1')
        {
            Gamemap[y/8][x/8] = false;
            cc+=1;
            m_Path.push_back(SDL_Rect({x,y,8,8}));
            m_Path1.push_back(SDL_Point({x+8,y+8}));
            addTOOBJECT("tile3","tile3",8,8,x,y,0);
        }



//            addTOOBJECT("blank","blank",8,8,x,y,0);
//        if(a=='2')
//        {
//            {
//
//                auto *a = gameobjectFactory->Create("GameObject_PacmanWall");
//                dynamic_cast<SDLGameObject*>(a)->setTexture("PacmanWall");
//                if(a->Type()=="GameObject_PacmanWall")
//                {
//
//                }
//                //SDL_Quit();
//                a->GetPosition().x =x;
//                a->GetPosition().y= y;
//                a->SetWidth(8);
//                a->SetHeight(8);
////                    CollisionManager::Instance()->Add(a);
//
//                OBJECT.push_back(a);
//            }
//        }
//    addTOOBJECT("blank3","blank3",8,8,x,y,0);


//    g = gameobjectFactory->Create("GameObject_PacMan");
//    g->Load("PacManGameObject.txt");
//
//                g->GetPosition()= m_tiles[30][21].m_Pos;



//std::cout <<  ",";else
//std::cout << a;
    }
    int G[5][5]= {{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
    int n=6;
    int u=0;
    dijkstra(G,n,u);


    std::cout << cc << "\n";
    for(int i = 0; i < OBJECT.size(); i++)
        for(int h = 0 ; h < 9; h ++)
            if(OBJECT[i]->Type()=="GameObject_PacmanWall")
                dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(true,h);
//need to make function so cant outbound arry
    for(int i = 0; i < OBJECT.size(); i++)
    {
        if(isinBound(i))
            if(OBJECT[i]->Type()=="GameObject_PacmanWall")
            {
                if(OBJECT[(i-28-1)]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,0);

                if(OBJECT[i-28]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,1);

                if(OBJECT[i-28+1]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,2);

                if(OBJECT[i-1]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,3);

                if(OBJECT[i+1]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,4);

                if(OBJECT[i+28-1]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,5);

                if(OBJECT[i+28]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,6);

                if(OBJECT[i+28+1]->Type()=="GameObject_PacmanWall")
                    dynamic_cast<GameObject_PacmanWall*>(OBJECT[i])->SetNeighbour(false,7);
            }

    }
    std::cout <<  sssss.size() << "\n"<< "\n";





    m_pacman = gameobjectFactory->Create("GameObject_PacMan");
    m_pacman->Load("PacManGameObject.txt");
    int x = GetRandomNumber()% OBJECT.size();
    int y = GetRandomNumber()% OBJECT.size();
    dynamic_cast<GameObject_PacMan*>(m_pacman)->AssignWall(&Gamemap[0]);
    dynamic_cast<GameObject_PacMan*>(m_pacman)->SetDir(PacMan::MOVING_LEFT);
// m_pacman->GetPosition().Set(OBJECT[x]->GetPosition().x,OBJECT[y]->GetPosition().y);
    dynamic_cast<SDLGameObject*>(m_pacman)->SetCenter(vec2f(dynamic_cast<SDLGameObject*>(OBJECT[x])->GetCentre()));



    //dynamic_cast<SDLGameObject*>(OBJECT[i])->setTexture("blank");

    ani = Animation(vec2f(350,44),35,35/(float)60,ANIMATION_HORIZONTAL);

    timer = LTimer();
    timer.Start();
    {

        m_player = gameobjectFactory->Create("GameObject_Player");
        m_player->Load("GameObject_Player.txt");
        m_player->GetPosition().x= CAMCENTRE.x-m_player->getWidth()/2-48;
        m_player->GetPosition().y= 0;

        CollisionManager::Instance()->Add(m_player);
    }
    /**<

    //    std::cout << nn[i];
    //    if( SDL_SetRenderTarget(r,lt->GetSDLTexture()))
    //    {
    //        std::cout << SDL_GetError() << "\n";
    //    }

    //
    //    lt->Render(r,0,0,0,&aaaaa);
    //    delete lt;
    //    TextureManager::Instance()->SetBlendMode("circle",SDL_BLENDMODE_ADD);
    //    TextureManager::Instance()->drawSprite("circle",MOUSEPOSITION.x-32,MOUSEPOSITION.y-32,64,64,r,SDL_FLIP_NONE);;
    //    TextureManager::Instance()->SetBlendMode("circle2",SDL_BLENDMODE_ADD);
    //    TextureManager::Instance()->drawSprite("circle2",MOUSEPOSITION.x-32,MOUSEPOSITION.y-32,64,64,r,SDL_FLIP_NONE);
    //    TextureManager::Instance()->drawSprite("bubblemaker",CAMCENTRE.x,CAMCENTRE.y*2-28,64,28,r,SDL_FLIP_NONE);
    //    TextureManager::Instance()->drawSprite("blur",MOUSEPOSITION.x,CAMCENTRE.y*2-28,64,64,r,SDL_FLIP_NONE);
    //    TextureManager::Instance()->drawSprite("BallBouncing",MOUSEPOSITION.x,MOUSEPOSITION.y,350,44,r,SDL_FLIP_NONE);
    //
    //    TextureManager::Instance()->SetColorMod("blur",Colour_purple);
    //    TextureManager::Instance()->SetBlendMode("blur",SDL_BLENDMODE_MOD);
    //    TextureManager::Instance()->drawSprite("blur",MOUSEPOSITION.x,CAMCENTRE.y,64,64,r,SDL_FLIP_NONE);
    //    TextureManager::Instance()->SetBlendMode("blur2",SDL_BLENDMODE_ADD);
    //    TextureManager::Instance()->SetColorMod("blur2",Colour_purple);
    //    TextureManager::Instance()->drawSprite("blur2",MOUSEPOSITION.x,MOUSEPOSITION.x,64,64,r,SDL_FLIP_NONE);
    //    TextureManager::Instance()->SetBlendMode("blur2",SDL_BLENDMODE_BLEND);
    //    TextureManager::Instance()->drawSprite("blur2",MOUSEPOSITION.x+64,CAMCENTRE.y,64,64,r,SDL_FLIP_NONE);
    ////     SDL_SetRenderTarget(r,NULL);
    //
    //    std::vector<GameObject*> s2=  CollisionManager::Instance()->FindResult();
    //    if(!s2.empty())
    //    {
    //
    //        int s =   CollisionManager::Instance()->FindResult().size();
    //        for(int i = 0 ; i < s; i++)
    //        {
    //            if("GameObject_Ghost"!=s2[i]->Type())
    //                for(int j = 0 ; j < 9; j++ )
    //                {
    //
    //                    TextureManager::Instance()->DrawPoint(r,
    //                                                          GetRectHitPoint(j,dynamic_cast<SDLGameObject*>(s2[i])->GetSDLRectF()).x,
    //                                                          GetRectHitPoint(j,dynamic_cast<SDLGameObject*>(s2[i])->GetSDLRectF()).y,
    //                                                          Colour_white);
    //                }
    //
    //        }
    //        //  TextureManager::Instance()->DrawRect(r,dynamic_cast<SDLGameObject*>(s2[i])->GetSDLRectF(),Colour_blueviolet,true);
    //        s2.clear();
    //        TextureManager::Instance()->DrawLine(r,playerBot.x,playerBot.y,WindowOrigin.x*2,WindowOrigin.y*2,Colour_cornsilk);
    //
    //     //   int ssss = CollisionManager::Instance()->check(m_player).size();
    //       // std::vector<GameObject*> ss= CollisionManager::Instance()->check(m_player);
    ////        for(int i = 0 ; i < ssss ; i++)
    ////        {
    ////            std::cout << ss[i]->Type() << "ssssssssssss\n";
    ////
    ////            if(ss[i]->Type()=="GameObject_Tile")
    ////            {
    ////                // std::cout << ss[i]->Type() << " -Type \n";
    ////                m_player->GetPosition().y = ss[i]->GetPosition().y-m_player->getHeight();
    ////                dynamic_cast<GameObject_Player*>(m_player)->isGround();
    ////                vec2f playerCenter = GetSDLRectFCenter(   dynamic_cast<SDLGameObject*>(m_player)->GetSDLRectF());
    ////                vec2f TesterCenter = GetSDLRectFCenter(   dynamic_cast<SDLGameObject*>(ss[i])->GetSDLRectF());
    ////                TextureManager::Instance()->DrawLine(r,
    ////                                                     TesterCenter.x,
    ////                                                     TesterCenter.y,
    ////                                                     playerCenter.x,
    ////                                                     playerCenter.y,
    ////                                                     Colour_white);
    ////
    ////
    //////  m_player->GetPosition().x =   dynamic_cast<SDLGameObject*>(m_player)->GetlastPosition().x;
    ////// m_player->GetPosition().y =   dynamic_cast<SDLGameObject*>(m_player)->GetlastPosition().y;
    ////            }
    ////        }
    ////        ss.clear();
    //    }
    //
    //    SDL_Rect SpriteRect =  ani.GetCurrentTile();
    //    SpriteRect.h = 44;
    //    TextureManager::Instance()->Draw(APP->GetRenderer(),"BallBouncing",SpriteRect, {MOUSEPOSITION.x+16+16+16,MOUSEPOSITION.y,35,44},0,NULL,SDL_FLIP_NONE);
    //
    //    //TextureManager::Instance()->drawSprite("background2",0,0,640,360,r,SDL_FLIP_NONE);
    //
    //
    //
    //
    //
    //    for(int i = 0 ; i < 23 ; i++)
    //    {
    //        for(int j = 0 ; j < 40 ; j++)
    //            if( Gamemap[i][j])
    //                TextureManager::Instance()->DrawRect(r,SDL_FRect({j*16,i*16,16,16}),Colour_cornsilk,false);
    //    }
    //    vec2f xd = MOUSEPOSITION-WindowOrigin;
    ////    vec2f m2 = MOUSEPOSITION-WindowOrigin;
    ////    std::cout << xd << "\n";
    //
    //    vec2f xy = vec2f(xd.x,0);
    //    vec2f xyd = vec2f::Proj(xd,xy);
    ////
    ////    TextureManager::Instance()->DrawVector(r,WindowOrigin,xd,Colour_red);
    //////    TextureManager::Instance()->DrawVector(r,WindowOrigin,xyd,Colour_blue);
    ////
    ////    vec2f c11 = vec2f(10,1);
    ////    vec2f c22 = vec2f(1,10);
    ////     vec2f c33 =vec2f::Proj(c22,c11);
    ////    TextureManager::Instance()->DrawVector(r,WindowOrigin,m2,Colour_greenyellow);
    ////    TextureManager::Instance()->DrawVector(r,WindowOrigin,-c44,Colour_red);
    //    vec2f m2 = -(WindowOrigin-MOUSEPOSITION);
    //     vec2f c44 = vec2f::GetMidPoint(WindowOrigin,m2);
    //    TextureManager::Instance()->DrawVector(r,WindowOrigin,c44,Colour_navy);
    //
    ////TextureManager::Instance()->DrawRects(r,&collisionManager->FindResult()[0],collisionManager->FindResult().size(),Colour_darkgray);

       for(int i = 0 ; i < 1; i++)
        {
            auto *a = gameobjectFactory->Create("GameObject_Tile");

            a->Load("GameObject_Tile.txt");
            a->GetPosition()  = vec2f(GetRandomNumber()%CAMRECT.w,GetRandomNumber()%360);
            dynamic_cast<SDLGameObject*>(a)->setTexture("Shapes");
            dynamic_cast<SDLGameObject*>(a)->SetsrcRect({0,0,16,16});
            a->SetWidth(16);
            a->SetHeight(16);
            CollisionManager::Instance()->Add(a);
            obj.push_back(a);
        }


        for(int i = 0 ; i < 1; i++)
        {
            auto *a = gameobjectFactory->Create("BreakOut_Ball");

            a->Load("FileName_BreakOut_Ball.txt");

            a->GetPosition()  = vec2f(GetRandomNumber()%CAMRECT.w,GetRandomNumber()%360);


            CollisionManager::Instance()->Add(a);
            obj.push_back(a);
        }
        //std::cout  << "\n"<<   "\n rrrrrrrr "<<               CollisionManager::Instance()->GetCollision(0,13).Type() << "\n";

        for(int i = 0 ; i < 0; i++)
        {
            auto *a = gameobjectFactory->Create("GameObject_Ghost");

            a->Load("GameObject_Ghost.txt");

            a->GetPosition()  = vec2f(GetRandomNumber()%CAMRECT.w,GetRandomNumber()%360);

            dynamic_cast<GameObject_Ghost*>(a)->SetTarget(CAMCENTRE);

            CollisionManager::Instance()->Add(a);
            obj.push_back(a);
        }
        //std::cout  << "\n"<<   "\n rrrrrrrr "<<               CollisionManager::Instance()->GetCollision(0,13).Type() << "\n";
        {


            for(int j = 0; j <= CAMRECT.w/16; j++)
            {
                {
                    auto *a = gameobjectFactory->Create("GameObject_Tile");
                    dynamic_cast<SDLGameObject*>(a)->setTexture("swirl");
                    a->GetPosition().x = j*16;
                    a->GetPosition().y= CAMCENTRE.y*2-4;
                    a->SetWidth(16);
                    a->SetHeight(4);
                    CollisionManager::Instance()->Add(a);

                    obj.push_back(a);
                }
                {


                    auto *a = gameobjectFactory->Create("GameObject_Tile");
                    dynamic_cast<SDLGameObject*>(a)->setTexture("tile");
                    a->GetPosition().x = j*32;
                    a->GetPosition().y= 0;
                    a->SetWidth(32);
                    a->SetHeight(32);
                    CollisionManager::Instance()->Add(a);

                    obj.push_back(a);
                }

            }
        }

        {


            for(int j = 0; j <= CAMRECT.w/32; j++)
            {
                {
                    auto *a = gameobjectFactory->Create("GameObject_Tile");
                    dynamic_cast<SDLGameObject*>(a)->setTexture("tile");
                    a->GetPosition().x =CAMCENTRE.x*2-32 ;
                    a->GetPosition().y= j*32;
                    a->SetWidth(32);
                    a->SetHeight(32);
                    CollisionManager::Instance()->Add(a);

                    obj.push_back(a);
                }
                {


                    auto *a = gameobjectFactory->Create("GameObject_Tile");
                    dynamic_cast<SDLGameObject*>(a)->setTexture("tile");
                    a->GetPosition().x = 0;
                    a->GetPosition().y= j*32;
                    a->SetWidth(32);
                    a->SetHeight(32);
                    CollisionManager::Instance()->Add(a);
                    obj.push_back(a);
                }

            }
        }
        {
            {
                auto *a = gameobjectFactory->Create("GameObject_Tile");
                dynamic_cast<SDLGameObject*>(a)->setTexture("bubblemaker");
                a->GetPosition().x = CAMCENTRE.x;
                a->GetPosition().y= CAMCENTRE.y*2-28;
                a->SetWidth(64);
                a->SetHeight(28);
                CollisionManager::Instance()->Add(a);
                obj.push_back(a);
            }

            {
                auto *a = gameobjectFactory->Create("GameObject_Tile");
                dynamic_cast<SDLGameObject*>(a)->setTexture("blank");
                a->GetPosition().x = CAMCENTRE.x;
                a->GetPosition().y= CAMCENTRE.y*2-75;
                a->SetWidth(4);
                a->SetHeight(75);
                CollisionManager::Instance()->Add(a);
                obj.push_back(a);
            }

        }
     */
//   addTOOBJECT("chair","chair",16,32);
//   addTOOBJECT("bubblemaker","bubblemaker",64,28);
//   addTOOBJECT("Spikes","Spikes",32,16);
//   addTOOBJECT("blank","blank",128,64,0,CAMRECT.h/1.5);
    for(int i = 0; i < (CAMRECT.w/2)/16; i++)
    {
        addTOOBJECT("platformTile3","platformTile3",16,16,i*16,CAMRECT.h-16);
    }
    for(int i = 0; i < (CAMRECT.w/2)/16; i++)
    {
        addTOOBJECT("Spikes","Spikes",16,8,CAMCENTRE.x+i*16,CAMRECT.h-8);
    }
    addTOOBJECT("blank","blank",128,16,CAMCENTRE.x-128/2,CAMCENTRE.y,0);
//   addTOOBJECT("blank","blank",128,64,128+128,CAMRECT.h/3);
//   addTOOBJECT("blank","blank",128,64, CAMCENTRE.x,200,90);
//   addTOOBJECT("blank","blank",128,64, CAMCENTRE.x-35/(float)2,200,90);




    CollisionManager::Instance()->Add(obj);


    m_ParticleEmitter =  ParticleEmitter(vec2f(64,64),vec2f(0,0),vec2f(0,-16),vec2f(200,200),1,Colour_green,255,29,255,10,200,10);


    float  Size =  100;

    for(int i = 0 ; i < Size ; i ++)
    {

        float xr = CAMCENTRE.x;
        float yr = CAMCENTRE.y;

        float f = i/(float)Size;
        float t = 180*(float)f;
        vec2f w =  vec2f(std::cos(t),std::sin(t));
        w.Normalise();

        vec2f m_vel ;

        //std::cout <<  w << "f  \n";

//            w.Rotate(-t);

        /**<

        t = anglr timer
        f = rotation fen


         */
//        m_ParticleEmitter.Add(Particle(WindowOrigin,vec2f(0,0),vec2f(0,0)));
        m_ParticleEmitter.Add(Particle(
//                                  vec2f(CAMCENTRE.x,
//                                        CAMCENTRE.y*2-28),
                                  vec2f(0,0),
                                  vec2f(0,
                                        0),
                                  vec2f(w.x*i,-32*std::sin(i))));



    }


//    std::cout  << CollisionManager::Instance()->FindResult().size() <<" \n";
//
//    while(!CollisionManager::Instance()->FindResult().empty())
//    {
//        std::vector<GameObject*> s2=  CollisionManager::Instance()->FindResult();
//        //  std::cout  << CollisionManager::Instance()->FindResult().size() <<" \n";
//        int s =   CollisionManager::Instance()->FindResult().size();
//        for(int i = 0 ; i < s; i++)
//        {
//            s2[i]->GetPosition()  = vec2f(GetRandomNumber()%640,GetRandomNumber()%360);
//        }
//        s2.clear();
//
//    }
//m_ParticleEmitter = NULL;
    m_ParticleSystem.Add(m_ParticleEmitter);






    m_pos2.y = WindowOrigin.y;
    m_pos.y = WindowOrigin.y;
    m_pos2.x = WindowOrigin.x;
    SDL_Rect www = WindowRect;
    tempRect = MakeGrid(0,0,80/(float)3,45/(float)3,32);

    return true;
}

void TestState37::addTOOBJECT(std::string type,std::string Texture,int w, int h, int x, int y, float degree )
{
// float x = GetRandomNumber() % 640 ;
// float y = GetRandomNumber() % 360 ;

    auto *a = gameobjectFactory->Create("GameObject_Tile");
    dynamic_cast<SDLGameObject*>(a)->setTexture(Texture);
    dynamic_cast<SDLGameObject*>(a)->GetAngle() = degree;
    dynamic_cast<GameObject_Tile*>(a)->SetType(type);
    a->GetPosition().x = x;
    a->GetPosition().y= y;
    a->SetWidth(w);
    a->SetHeight(h);
    CollisionManager::Instance()->Add(a);
    OBJECT.push_back(a);
    //obj.push_back(a);

}

/**<

    {

        float  Size =  60;

        for(int i = 0 ; i < Size ; i ++)
        {

            float xr = WindowOrigin.x;
            float yr = WindowOrigin.y;

            float f = i/(float)Size;
            float t = 360*(float)f;
            vec2f w =  vec2f(std::cos(t),std::sin(t));
            w.Normalise();

            vec2f m_vel ;

            //std::cout <<  w << "f  \n";

            w.Rotate(-t);

            /**<

            t = anglr timer
            f = rotation fen


            m_ParticleEmitter.Add(Particle(WindowOrigin,m_vel,w));
        }
//m_ParticleEmitter = NULL;
        m_ParticleSystem.Add(m_ParticleEmitter);


    }




        SDL_RenderSetViewport(APP->GetRenderer(),&www);
    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
    SDL_Rect ss = {0,0,640,360};
//SDL_RenderSetClipRect(APP->GetRenderer(),&ss);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
Application::Instance()->GetCamera().SetSize(vec2f(1920,1080));

 */
bool TestState37::onExit()
{
    return true;
}
void TestState37::resume() {}
void TestState37::HandleEvent(SDL_Event &e )
{
    m_pacman->HandleEvent(e);
    m_mass = 64;
    m_mass = 16;

    m_player->HandleEvent(e);
    vec2f m_force;

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
    {

        if(!checkIfOffPath(vec2f(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().x,dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().y-8)))
            dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Up();

        dynamic_cast<GameObject_PacMan*>(m_pacman)->SetDir(PacMan::Moving::UP);
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
    {
        if(!checkIfOffPath(vec2f(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().x-8,dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().y)))
            dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Left();

        dynamic_cast<GameObject_PacMan*>(m_pacman)->SetDir(PacMan::Moving::LEFT);
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) ||  InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
    {
        if(!checkIfOffPath(vec2f(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().x+8,dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().y)))
            dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Right();

        dynamic_cast<GameObject_PacMan*>(m_pacman)->SetDir(PacMan::Moving::RIGHT);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) ||  InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
    {
        if(!checkIfOffPath(vec2f(dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().x,dynamic_cast<SDLGameObject*>(m_pacman)->GetCentre().y+8)))
            dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Down();

        dynamic_cast<GameObject_PacMan*>(m_pacman)->SetDir(PacMan::Moving::DOWN);
    }

    if(e.key.state == SDL_PRESSED && InputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
    {
        Application::Instance()->PushEvent(1,new string("Restart"),new string("Restart"));
    }
    if(e.key.state == SDL_PRESSED && InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
    {
        Application::Instance()->PushEvent(2,new string("State"),new string("TestState36"));
    }
    if(e.key.state == SDL_PRESSED && InputHandler::Instance()->isKeyDown(SDL_SCANCODE_V))
    {
// TestState31 State_Logo_Screen TestState32 TestState33 TestState34 TestState35 TestState36 TestState37
        Application::Instance()->PushEvent(2,new string("State"),new string("TestState37"));
        SDL_Delay(1000);
    }
    if( e.key.state == SDL_PRESSED && InputHandler::Instance()->isKeyDown(SDL_SCANCODE_C))
    {
        Application::Instance()->quit();
    }
//
//
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
//    {
//       dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Left();
//
//        m_force += vec2f(-1,0);
//        m_Leftdown = true;
//    }
//    else m_Leftdown = false;
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
//    {
//       dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Right();
//        m_force += vec2f(1,0);
//        m_rightdown = true;
//    }
//    else  m_rightdown = false;
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
//    {
//       dynamic_cast<GameObject_PacMan*>(m_pacman)->Move_Down();
//
//        m_force += vec2f(0,0);
//        m_Downdown = true;
//    }
//    else    m_Downdown = false;
//
//    m_acc = m_force*m_mass;
//    m_acc2 = m_force*m_mass2;
}
/**<     TextureManager::Instance()->Draw(r,"boxPlayer", {0,0,16,16}, {m_pos.x,m_pos.y,m_mass,m_mass});
    {
        vec2f f = m_acc/(float)m_mass;
        std::stringstream ww;
        ww << m_mass << "  " <<m_acc << f;
        TextureManager::Instance()->drawText(r,FontManager::Instance()->GetFont("CONSOLA"),ww.str(),CAMRECT.w/2,CAMRECT.h/2,Colour_yellow,Align_Center,16);
    }
    std::vector<GameObject*> collisionRef = CollisionManager::Instance()->FindResult();
if(!collisionRef.empty())
        for(int i = 0 ; i < collisionRef.size(); i++)
               TextureManager::Instance()->DrawRect(APP->GetRenderer(),dynamic_cast<SDLGameObject*>(collisionRef[i])->GetSDLRectF(),Colour_green,true);
//    std::vector<GameObject*>m_gameObects;
////    std::vector<GameObject*>m_collisons;
//for(int i = 0; i < 1  ; i++)
//{
// float x = GetRandomNumber() % 640 ;
// float y = GetRandomNumber() % 360 ;
//
//         auto *a = gameobjectFactory->Create("GameOBject_RocketShip");
//                a->Load("GameOBject_RocketShip.txt");
//                a->GetPosition().x = x ;
//                a->GetPosition().y =y;
//
//m_gameObects.push_back(a);
//CollisionManager::Instance()->Add(a);
//
//
//    m_v2.push_back(vec2f(x,y));
//
//}
//            for(int i = 0 ; i < obj.size(); i++)
//                while(!CollisionManager::Instance()->check(obj[i]).empty())
//                {
//
//                std::cout << "shuffling" <<"\n" ;
//                    obj[i]->GetPosition()  = vec2f(vec2f(GetRandomNumber()%640,GetRandomNumber()%360));
//                    // obj[i]->Collision();
//                }
//    SDL_Rect www = WindowRect;
//        SDL_RenderSetViewport(APP->GetRenderer(),&www);
//    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
//    SDL_Rect ss = {0,0,640,360};
////SDL_RenderSetClipRect(APP->GetRenderer(),&ss);
////    SDL_RenderSetLogicalSize(APP->GetRenderer(),640,360);
////    SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
//
//    m_ParticleEmitter =  ParticleEmitter(vec2f(WindowOrigin),vec2f(),vec2f(),vec2f());
//Application::Instance()->GetWindow()->RescaleWindow(3);
//SDL_SetWindowPosition(APP->GetWindow()->GetWindow(),0,0);

//Application::Instance()->GetCamera().SetSize(vec2f(1920,1080));
//        for(int i = 0 ; i < obj.size(); i++)
//        {
//
//            delete obj[i];
//            CollisionManager::Instance()->Remove(obj[i]);
//            obj.clear();
//
//        }
//
//
//    }
//std::vector<GameObject*> collisionRef = CollisionManager::Instance()->FindResult();
//if(!collisionRef.empty())
//        for(int i = 0 ; i < collisionRef.size(); i++)
//        {
//               TextureManager::Instance()->DrawRect(APP->GetRenderer(),dynamic_cast<SDLGameObject*>(collisionRef[i])->GetSDLRectF(),Colour_green,true);

//while(!CollisionManager::Instance()->FindResult().empty())
//{
//break;
//}
//}







//
//       for(int i = 0 ; i < obj.size(); i++)
//  {
//                    CollisionManager::Instance()->Remove(obj[i]);
//                    obj.erase(obj.begin() + i);
//                }
//While(!obj.empty())
//       for(int i = 0 ; i < obj.size(); i++)
//  {
//                    CollisionManager::Instance()->Remove(obj[i]);
//                    obj.erase(obj.begin() + i);
//                }

//    m_ParticleSystem.Clear();
//
// m_ParticleEmitter =  ParticleEmitter();
//float  Size =  100;
//dtt += dt;
//for(int i = 0 ; i < Size ; i ++)
//
//
//        float xr = WindowOrigin.x;
//        float yr = WindowOrigin.y;
//float ss = i*i;
//vec2f m_vel ;
//vec2f m_acc = vec2f(0,i);
//  float t = 360*(float)(i/(float)40);
//        float f = 40*(float)i/(float)255;
//        vec2f w =  vec2f(-i,0);
//        w.Rotate(-t);
//w.GetNormalise() *=(float) 0.01;
//m_ParticleEmitter.Add(Particle(vec2f(xr,yr),vec2f(),w));
//
//
////m_ParticleEmitter = NULL;
//m_ParticleSystem.Add(m_ParticleEmitter);
//    std::cout << "results of collision num  " << CollisionManager::Instance()->FindResult().size() << " \n";


//                std::cout <<  obj[i]->Type() << "\n";



//if(!obj.empty())
//    for(int i = 0 ; i < obj.size(); i++)
//        if(obj[i]!=NULL)
    //  if(CollisionManager::Instance()->Check(obj[i]))
    //

//m_ParticleSystem.Update(dtt);

//
//    m_ParticleSystem.Update(MOUSEPOSITION.x/(float)640);


//
//for(int i = 0 ; i < m_gameObects.size(); i ++ )
//    m_gameObects[i]->Update(dt);
////
//m_collisons.clear();
//for(int i = 0 ; i < m_gameObects.size(); i ++ )
//{
//
//m_collisons = CollisionManager::Instance()->check(m_gameObects[i]);
//
//while(!m_collisons.empty())
//{
//    for(int i = 0 ; i < m_collisons.size(); i ++ )
//{
//
////    std::cout << m_collisons[i]->GetPosition() << "\n";
//
//}break;
//}
//}

//for(int i = 0 ; i < m_gameObects.size(); i ++ )
//  if(m_gameObects[i]
//for(int i = 0 ; i < m_v2.size(); i ++ )
//    TextureManager::Instance()->DrawVector(r,m_v2[i],m_v2[i],Colour_black);
//  std::cout <<  GetRandomNumber() % 100 << "\n";
//
//for(int i = 0 ; i < m_gameObects.size(); i ++ )
//{
//   SDL_Rect rr =  dynamic_cast<SDLGameObject*>(m_gameObects[i])->GetSDLRect();
//   rr.x-=32;
//   rr.y-=32;
//   rr.w+=64;
//   rr.h+=64;
//    //if(InputHandler::Instance()->MouseinRect(rr))
//    m_gameObects[i]->Render(r,0,0);
//}
 */
