#include "State_PacMan.h"

State_PacMan::State_PacMan()
{
    //ctor
}

State_PacMan::~State_PacMan()
{
    //dtor

}

void State_PacMan::Render()
{
    /**<
    //
    //   // TextureManager::Instance()->SetColour(Colour_black,App->GetRenderer());
    //    //if(isTrue)
    //   //     TextureManager::Instance()->SetColour(Colour_black,App->GetRenderer());
    //
    //    TextureManager::Instance()->drawTextureText(App->GetRenderer(),"PacManBackGround",m_viewport);

    //
    //            if(m_PacmanTileGrid[i][j]==paccman_isOver)
    //                TextureManager::Instance()->DrawRectFilled(SDL_Rect{m_tiles[i][j].x,m_tiles[i][j].y,8,8},Colour_navy,App->GetRenderer());
    //            if(m_PacmanTileGrid[i][j]==paccman_Soild)
    //                TextureManager::Instance()->DrawRectFilled(SDL_Rect{m_tiles[i][j].x,m_tiles[i][j].y,8,8},Colour_royalblue,App->GetRenderer());

    //            if(m_PacmanTileGrid[i][j]==paccman_Empty)
    //                TextureManager::Instance()->DrawRectFilled(SDL_Rect{m_tiles[i][j].x,m_tiles[i][j].y,8,8},Colour_gainsboro,App->GetRenderer());

    //    vec2f  mouse = InputHandler::Instance()->GetMousePosition();
    //
    //    SDL_Rect aaa = alignToTilePosition(mouse.x,mouse.y,8);
    //   // mouse = vec2f(aaa.x,aaa.y);
    //  TextureManager::Instance()->DrawRectFilled(aaa,Colour_white,App->GetRenderer());
    //    if(isTrue)

    //    TextureManager::Instance()->SetColour(Colour_black,App->GetRenderer());
    //    SDL_Rect textbox = FontManager::Instance()->QueryText("READY!","Sans");
    //    TextureManager::Instance()->DrawText("READY!",App->GetOrigin().x /2- textbox.w/2,App->GetOrigin().y/2 - textbox.h/2,Colour_yellow,fontManager->GetFont("Sans"),App->GetRenderer());
    ////     buffer[NE]
    //
    //
    //
    //SDL_Rect textOffset = log_ofpacmanDir.GetBounds();
    //
    //
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x - textOffset.w,mouse.y - textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x + textOffset.w,mouse.y + textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x +textOffset.w,mouse.y - textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x - textOffset.w,mouse.y + textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x - textOffset.w- textOffset.w,mouse.y + textOffset.h + textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x + textOffset.w+ textOffset.w,mouse.y + textOffset.h + textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x- textOffset.w-textOffset.w,mouse.y - textOffset.h - textOffset.h);
    //    log_ofpacmanDir.LoadFromRenderedText(App->GetRenderer(),pacmanDir,mouse.x+ textOffset.w+textOffset.w,mouse.y - textOffset.h - textOffset.h);
    //

    // Application::Instance()->GetCamera().SetPos(InputHandler::Instance()->GetMousePosition());

    */
    SDL_Rect ss = {Application::Instance()->GetCamera().GetPos().x,Application::Instance()->GetCamera().GetPos().y,Application::Instance()->GetCamera().GetSize().x,Application::Instance()->GetCamera().GetSize().y};

 //   TextureManager::Instance()->DrawRectFilled(ss,Colour_black,App->GetRenderer());

    if(isTrue)
    {
//        TextureManager::Instance()->SetColour(Colour_darkcyan,App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[NW],App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[N],App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[NE],App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[W],App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[M],App->GetRenderer());
//
//        TextureManager::Instance()->DrawRectFilled(buffer[E],App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[SW],App->GetRenderer());
//        TextureManager::Instance()->DrawRectFilled(buffer[S],App->GetRenderer());
    //    TextureManager::Instance()->DrawRectFilled(buffer[SE],App->GetRenderer());

    }
    for(int i = 0 ; i < Pac_Man_Tile_col; i++)
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
        {
            pacmanBackGroundTiles[i][j]->Render(APP->GetRenderer(),0,0);
        }


    g->Render(APP->GetRenderer(),0,0);
    {
        SDL_Rect bb = {Application::Instance()->GetCamera().GetPos().x,Application::Instance()->GetCamera().GetPos().y,Application::Instance()->GetCamera().GetSize().x,Application::Instance()->GetCamera().GetSize().y};

//        TextureManager::Instance()->DrawRect(bb,Colour_green,App->GetRenderer());
        //TextureManager::Instance()->DrawGrid(0,24+8*3,28,31,8,Colour_lightgray,App->GetRenderer());
        std::stringstream dirtext;

        dirtext << " / Cells : " << Pac_Man_Cells <<" /  empty :"  <<  m_emptyTileSize;

//        TextureManager::Instance()->DrawText(dirtext.str(), 0,370,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());
    }
    {


        std::stringstream dirtext;

        dirtext << g->GetPosition() <<  vec2f(buffer[NW].x,buffer[NW].y);

//        TextureManager::Instance()->DrawText(dirtext.str(), 0,340,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());

    }
    {


        std::stringstream dirtext;
        dirtext << dynamic_cast<GameObject_PacMan*>(g)->GetDir();
//        TextureManager::Instance()->DrawText(dirtext.str(), 0,310,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());

    }
    vec2f  mouse = InputHandler::Instance()->GetMousePosition();
    SDL_FRect aaa = alignToTilePosition(mouse.x,mouse.y,8);
    // mouse = vec2f(aaa.x,aaa.y);
    //TextureManager::Instance()->DrawRectFilled(aaa,Colour_white,App->GetRenderer());
    {


        std::stringstream dirtext;
        mouse.y+=-Application::Instance()->GetWindow()->GetWidget()->GetChild(1).GetHitBox().y;
        dirtext << mouse;
//        TextureManager::Instance()->DrawText(dirtext.str(), 0,350,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());


    }
    {


        std::stringstream dirtext;
        dirtext <<   m_tiles[1][1];
//        TextureManager::Instance()->DrawText(dirtext.str(), 0,380,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());

    }
    {


        std::stringstream dirtext;
        dirtext <<   Application::Instance()->GetCamera().GetPos();
//        TextureManager::Instance()->DrawText(dirtext.str(), 0,400,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());

    }
    {


        std::stringstream dirtext;
        dirtext << "Camera Pixel Positions   " << m_camRect.rectTopLeft << "   " <<m_camRect.rectBottomRight ;
//        TextureManager::Instance()->DrawText(dirtext.str(), 0,420,Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());

    }
//   TextureManager::Instance()->DrawRectFilled(m_camRect,Colour_cornflowerblue,App->GetRenderer());

    SDL_Rect l_pacmanRect = dynamic_cast<SDLGameObject*>(g)->GetSDLRect();
//    TextureManager::Instance()->DrawRectFilled(l_pacmanRect,Colour_blue,App->GetRenderer());

     RenderScore();
     Renderlevel();
     Renderlives();
     RenderCurrentPlaying();

}
void State_PacMan::Update()
{
    Application::Instance()->GetCamera().SetSize(InputHandler::Instance()->GetMousePosition());
    isTrue = false;
    g->Update(0);
    vec2f  mouse = InputHandler::Instance()->GetMousePosition();
    SDL_Rect l_pacmanRect = dynamic_cast<SDLGameObject*>(g)->GetSDLRect();

    l_pacmanRect.x = (8*(int)l_pacmanRect.x/8);
    l_pacmanRect.y = (8*(int)l_pacmanRect.y/8);

    mouse.x = (8*(int)mouse.x/8);
    mouse.y =(8*(int)mouse.y/8);

    buffer = MakeGrid(3,3,8);

    buffer[M].x = dynamic_cast<SDLGameObject*>(g)->GetCentre().x;
    buffer[M].y = dynamic_cast<SDLGameObject*>(g)->GetCentre().y;


    buffer[NW].x   = buffer[M].x-8;
    buffer[N].x     = buffer[M].x;
    buffer[NE].x = buffer[M].x+8;
    buffer[NW].y   = buffer[M].y-8;
    buffer[N].y       = buffer[M].y-8;
    buffer[NE].y = buffer[M].y-8;

    buffer[W].x = buffer[M].x-8;
    buffer[E].x =  buffer[M].x+8;
    buffer[W].y  = buffer[M].y;
    buffer[E].y = buffer[M].y;

    buffer[SW].x   = buffer[M].x-8;
    buffer[S].x     = buffer[M].x;
    buffer[SE].x = buffer[M].x+8;
    buffer[SW].y   = buffer[M].y+8;
    buffer[S].y    = buffer[M].y+8;
    buffer[SE].y =  buffer[M].y+8;

 for(int i = 0 ; i < Pac_Man_Tile_col; i++)
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
        {
            pacmanBackGroundTiles[i][j]->Update(0);
        }


    for(int i = 0 ; i < Pac_Man_Tile_col; i++)
    {
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
        {
            SDL_Rect tile = {m_tiles[i][j].x,m_tiles[i][j].y,8,8};


            SDL_Rect  RectPacman = l_pacmanRect;


            if(m_PacmanTileGrid[i][j]!=paccman_Empty)
                if(InputHandler::Instance()->HasIntersection(RectPacman,tile))
                {

                    std::cout << "collision Ssssssssssssssssssss new to do point in rect to test centre\n";



//       g->GetPosition().y = m_tiles[i][j].y;
                    //g->GetPosition() = dynamic_cast<SDLGameObject*>(g)->GetlastPosition();
                    g->Collision();
// g->GetPosition().x -=tile.x+tile.w/2- g->GetPosition().x;
// g->GetPosition().y -=tile.y+tile.y/2- g->GetPosition().y;
                    isTrue = true;
//
                }
            tile = {m_tiles[i][j].x,m_tiles[i][j].y,4,4};
            RectPacman  = { dynamic_cast<SDLGameObject*>(g)->GetCentre().x,dynamic_cast<SDLGameObject*>(g)->GetCentre().y,4, 4};
            if(m_PacmanTileGrid[i][j]!=paccman_Empty)
                if(InputHandler::Instance()->HasIntersection(RectPacman,tile))
                {
                    g->Collision();
                    isTrue = true;
                }




            if(InputHandler::Instance()->MouseinRect(tile))
            {
//                if(m_PacmanTileGrid[i][j]==paccman_Empty)
//                    m_PacmanTileGrid[i][j] = paccman_isOver;
            }

            if(InputHandler::Instance()->HasIntersection(buffer[NW],tile))
            {
                if(m_PacmanTileGrid[i][j]!=paccman_Empty)

                {}
                //             std::cout << "buffer[NW]\n";
            }
            if(InputHandler::Instance()->HasIntersection(buffer[N],tile))
            {

                if(m_PacmanTileGrid[i][j]!=paccman_Empty) {}
                //            std::cout << "buffer[N]\n";
            }
            if(InputHandler::Instance()->HasIntersection(buffer[NE],tile))
            {

                if(m_PacmanTileGrid[i][j]!=paccman_Empty) {}
                //       std::cout << "buffer[NE]\n";

            }
        }

    }
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))

    {
        for(int i = 0 ; i < Pac_Man_Tile_col; i++)
            for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
            {

                vec2f  tileCentre = vec2f(m_tiles[i][j].x+8,m_tiles[i][j].y+8);
                if(InputHandler::Instance()->GetMousePosition().Dist(tileCentre)<=8)
                {
                    l_grid[i/8 + (( j/8)*8)] = m_tiles[i][j];
                    m_PacmanTileGrid[i][j] = paccman_Empty;
//                    m_tiles[i][j] = vec2f(-16,-16);
                }

            }

    }
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::RIGHT))
    {
        for(int i = 0 ; i < Pac_Man_Tile_col; i++)
            for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
            {

                vec2f  tileCentre = vec2f(m_tiles[i][j].x+8,m_tiles[i][j].y+8);
                if(InputHandler::Instance()->GetMousePosition().Dist(tileCentre)<=8)
                {
                    l_grid[i/8 + (( j/8)*8)] = vec2f(-1,-1);
                    m_PacmanTileGrid[i][j] = paccman_Soild;
//                    m_tiles[i][j] = vec2f(-16,-16);
                }
            }
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        std::ofstream ofs;
        ofs.open ("PacManCollisionMap.txt", std::ofstream::out);


        for(int i = 0 ; i < Pac_Man_Tile_col; i++)
        {
            for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
            {
                pacmanBackGroundTiles[i][j]->Update(0);
                if(m_PacmanTileGrid[i][j]==paccman_Soild)
                {

                    ofs <<  '1';
                }

                if(m_PacmanTileGrid[i][j]==paccman_Empty)
                {
                    ofs <<  '2';
                }
                if(m_PacmanTileGrid[i][j]==paccman_isOver)
                {

                    ofs <<  '3';
                }
            }
            ofs  <<"\n";
        }
        ofs.close();
    }

    float cir_mass = 4;
//    for(int i = 0 ; i < 14; i++)
//    {
//        for(int j = 0 ; j < 18 ; j++)
//
//        {
////if(mouse.Dist(vec2f(grid[i][j].x,grid[i][j].y))<cir_mass)
////  m_PacmanTileGrid[i][j] = paccman_isOver;
//        }
//
//    }

}
bool State_PacMan::OnEnter()
{


    m_camRect = {Application::Instance()->GetCamera().GetPos(),Application::Instance()->GetCamera().GetSize()};

//SDL_IsTextInputShown();
//SDL_LogMessage("nnn");
//    CollisionManager::Instance()->Grid(0,0,16);

    float header = Application::Instance()->GetWindow()->GetWidget()->GetChild(1).GetHitBox().y;

    for(int i = 0 ; i <= Pac_Man_Tile_col; i++)
    {
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
        {
            m_tiles[i][j] = vec2f(j*8,i*8+header+24);
            pacmanBackGroundTiles[i][j] = GameObjectFactory::Instance()->Create("GameObject_PacManTile");

            pacmanBackGroundTiles[i][j]->GetPosition().x =   m_tiles[i][j].x;
            pacmanBackGroundTiles[i][j]->GetPosition().y =  m_tiles[i][j].y;
        }
    }
    std::string  configInfo = "PacManCollisionMap.txt";

    std::ifstream ifs;
    ifs.open (configInfo, std::ifstream::in);
    if(ifs.good())
        std::cout << "ifstream loaded "<< configInfo<< ": good\n";
    if(ifs.fail())
        std::cout << "fail\n";
    if(ifs.bad())
        std::cout << "bad\n";

    char l_readInt =  0;
    for(int i = 0 ; i <= Pac_Man_Tile_col; i++)
    {
        for(int j = 0 ; j< Pac_Man_Tile_Row ; j++)
        {
            //    m_tiles[i][j] = vec2f(j*8,i*8);
            ifs >> l_readInt;
            if(l_readInt=='1')
            {

                // std::cout << l_readInt;

                m_emptyTileSize+=1;
                m_PacmanTileGrid[i][j]=paccman_Empty;
                pacmanBackGroundTiles[i][j]->SetDead(true);
            }
            if(l_readInt=='2')
            {
                pacmanBackGroundTiles[i][j]->SetDead(false);
                m_PacmanTileGrid[i][j]=paccman_Soild;
            }

            if(l_readInt=='3')
            {
                m_PacmanTileGrid[i][j]=paccman_isOver;
            }


        }
        //  std::cout << "\n";
    }


    g = NULL;
    g = gameobjectFactory->Create("GameObject_PacMan");
    g->Load("PacManGameObject.txt");

    g->GetPosition()=   m_tiles[1][1];
    for(int i = 0 ; i <= Pac_Man_Tile_col; i++)
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
        {
            l_grid[i/8 + (( j/8)*8)] = m_tiles[i][j];
            if(m_PacmanTileGrid[i][j]==paccman_Soild)
                l_grid[i/8 + (( j/8)*8)] = vec2f(-1,-1);

            vec2f b  = l_grid[i/8 + (( j/8)*8)];

            // std::cout << b.x << "x/y " << b.y << "\n";
        }


//dynamic_cast<GameObject_PacMan*>(g)->SetGrid(l_grid);
//
//    dynamic_cast<GameObject_PacMan*>(g)->SetGrids(&l_grid[((int)Pac_Man_Tile_col * Pac_Man_Tile_Row)]);
//    dynamic_cast<GameObject_PacMan*>(g)->SetGrid(m_tiles);
//
//   SDL_RenderSetLogicalSize(App->GetRenderer(),0,0);
// m_viewport = {0,header,244,288};
//SDL_RenderSetClipRect(App->GetRenderer(),&m_viewport);
//   SDL_RenderSetViewport(App->GetRenderer(),&m_viewport);
////SDL_RenderIsClipEnabled(GetRenderer());
// SDL_RenderSetIntegerScale(App->GetRenderer(),SDL_TRUE);
//
//    SDL_RenderSetScale(App->GetRenderer(),2,2);

    // InputHandler::Instance()->ShowMouse(false);

  //  Application::Instance()->cmdStateMachine("Push_State","State_Pacman_Ready");
    return true;
}
bool State_PacMan::onExit()
{
}
void State_PacMan::resume() {}
void State_PacMan::HandleEvent(SDL_Event &e )
{
//SDL_IsTextInputShown();
//up
//vec2f gtop = vec2f(alignToTilePosition(g->GetPosition().x,g->GetPosition().y,16).x,
//                   alignToTilePosition(g->GetPosition().x,g->GetPosition().y,16).y);
//                   if(
//dynamic_cast<GameObject_PacMan*>(g)->IsAbleToMove(gtop,m_PacmanTileGrid[(int)gtop.y][(int)gtop.x]))
//{
//
//}  //        m_DirFlag =   PacMan::Animation::MOVING_LEFT;
    //     m_velocity.x =-16;
    //GetPosition().x-=8;
//     //        m_DirFlag =   PacMan::Animation::MOVING_DOWN;

//   GetPosition().y+=8;
//    m_DirFlag =  PacMan::Animation::MOVING_RIGHT;

// m_velocity.x =16;
//   GetPosition().x+=8;x

    //Application::Instance()->GetCamera().SetScaler(InputHandler::Instance()->GetMousePosition().Length()/24);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
    {
        pacmanDir = "Up";
        dynamic_cast<GameObject_PacMan*>(g)->Move_Up();
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
    {
        pacmanDir = "Left";
        dynamic_cast<GameObject_PacMan*>(g)->Move_Left();
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
    {
        pacmanDir = "Right";
        dynamic_cast<GameObject_PacMan*>(g)->Move_Right();
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
    {
        pacmanDir = "Down";
        dynamic_cast<GameObject_PacMan*>(g)->Move_Down();
    }

    log_ofpacmanDir.ChangeText(pacmanDir,FontManager::Instance()->GetFont("Sans"),Application::Instance()->GetRenderer());
    for(int i = 0 ; i <= Pac_Man_Tile_col; i++)
        for(int j = 0 ; j < Pac_Man_Tile_Row ; j++)
        {
            pacmanBackGroundTiles[i][j]->HandleEvent(e);
        }
    g->HandleEvent(e);

//    g->GetPosition().x = (16*(int)(e.motion.x/16));
//    g->GetPosition().y = (16*(int)(e.motion.y/16));


}

int State_PacMan::GetScore()
{
    return m_CurrentPlayersection.Score;
}
int State_PacMan::GetLives()
{
    return m_CurrentPlayersection.lives;
}
bool State_PacMan::isPlayer1up()
{
    if(m_CurrentPlayersection.CurrentPlaying == PLAYER1);
    return  true;
}
int State_PacMan::GetLevel()
{
    return m_CurrentPlayersection.level;
}

void State_PacMan::RenderScore()
{
   std::stringstream dirtext;
        dirtext <<  (int)GetScore();
      //  TextureManager::Instance()->DrawText(dirtext.str(), m_camRect.rectTopLeft.x+8,m_camRect.rectTopLeft.y+FontManager::Instance()->GetFontSize("OpenSans-Regular8"),Colour_white,fontManager->GetFont("OpenSans-Regular12"),Application::Instance()->GetRenderer());

}
void State_PacMan::Renderlevel()
{
}
void State_PacMan::Renderlives()
{
}
void State_PacMan::RenderCurrentPlaying()
{
//    if(isPlayer1up())
//
//        TextureManager::Instance()->DrawText("1st", m_camRect.rectTopLeft.x+8,m_camRect.rectTopLeft.y,Colour_white,fontManager->GetFont("OpenSans-Regular8"),Application::Instance()->GetRenderer());
//
//    else
//
//        TextureManager::Instance()->DrawText("2nd", m_camRect.rectTopLeft.x+8,m_camRect.rectTopLeft.y,Colour_white,fontManager->GetFont("OpenSans-Regular8"),Application::Instance()->GetRenderer());


}

