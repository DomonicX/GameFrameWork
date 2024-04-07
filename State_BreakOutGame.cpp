#include "State_BreakOutGame.h"

State_BreakOutGame::State_BreakOutGame() {}
State_BreakOutGame::~State_BreakOutGame() {}
void State_BreakOutGame::Render()
{
    GameObject_Ball& gb = *dynamic_cast<GameObject_Ball*>(m_gameobjects.back());
//   RenderColour();
    TextureManager::Instance()->SetColour(Colour_blanchedalmond,APP->GetRenderer());

    for(int i = 0 ; i < m_gameobjects.size(); i++)
        m_gameobjects[i]->Render(APP->GetRenderer(),0,0);

    vec2f camsize = APP->GetCamera().GetSize();
    vec2f campos = APP->GetCamera().GetPos();

    SDL_Rect camRect = {campos.x,campos.y,camsize.x,camsize.y};
//std::cout << s.x << " " <<s.y<<"\n";
    //TextureManager::Instance()->DrawRect(camRect,Colour_red,App->GetRenderer());
    TextureManager::Instance()->SetColour(Colour_green,APP->GetRenderer());
    // TextureManager::Instance()->DrawGrid(campos.x,campos.y,camRect.w/64,camRect.h/64,64,App->GetRenderer());
    float aa = vec2f::Dot(gb.GetVelocity().GetNormalise(),vec2f(0,-1));
    aa*=2;
//    TextureManager::Instance()->DrawText(gb.GetWallHitCounter(),
//                                         200,200,
//                                         FontManager::Instance()->GetFont("OpenSans-Regular"),
//                                         App->GetRenderer());
//
//    TextureManager::Instance()->DrawText(aa,
//                                         200,300,
//                                         FontManager::Instance()->GetFont("OpenSans-Regular"),
//                                         App->GetRenderer());
//if(aa<0)
// TextureManager::Instance()->DrawVector(gb.GetPosition(),gb.GetVelocity(),gb.GetVelocity().Length(),Colour_antiquewhite,APP->GetRenderer());
}

void State_BreakOutGame::Update()
{

    for(int i = 0 ; i < m_gameobjects.size(); i++)
    {
//        m_gameobjects[i]->Update();
    }
    if(isBallSpawn)
    {
        BallSpawnUpdate();
    }
    else
    {
        DoPaddleHit();
        DoWallHit();
        DoBlockHit();
    }


    for(int i = 0 ; i < m_gameobjects.size()-2; i++)
    {
        if(m_gameobjects[i]->Dead())
        {
            delete m_gameobjects[i];
            m_gameobjects.erase(m_gameobjects.begin()+i);
        }
    }
    if(m_gameobjects.size()==2)
    {
    //   App->PushCommand_StateMachine("Pop_State","State_BreakOutGame");
    //    App->PushCommand_StateMachine("Push_State","State_BreakOutGame");
    }
    vec2f camsize = APP->GetCamera().GetSize();
    vec2f campos = APP->GetCamera().GetPos();

    SDL_Rect camRect = {campos.x,campos.y,camsize.x,camsize.y};


    for(int i = 0 ; i < m_gameobjects.size(); i++)
    {
        SDL_Rect gameobjectVisableRect = {m_gameobjects[i]->GetPosition().x,m_gameobjects[i]->GetPosition().y,m_gameobjects[i]->getWidth(),m_gameobjects[i]->getHeight()};
        if(!InputHandler::Instance()->HasIntersection(gameobjectVisableRect,camRect))
        {
            m_gameobjects[i]->SetDead(true);
        }
        //   else

//m_gameobjects[i]->SetDead(false);
    }

}
bool State_BreakOutGame::OnEnter()
{



//    auto* p =   dynamic_cast<GUI_Frame*>(App->GetWindow()->GetWigdet())->Find("SceneTree");
 //   p->SetVisable(false);
//std::vector<std::string> a = Application::Instance()->GetAllStatesID();

//
////gui_label code doesnt work and this fails because of it
//    for(int i = 0 ; i <  a.size(); i++ )
//    {
//
//    GUI_Wigdet * label = guiFactory->Create("GUI_Label");
//
//    dynamic_cast<GUI_Label*>(label)->Init(a[i],a[i],FontManager::Instance()->GetFont("OpenSans-Regular"),
//SDL_FRect({p->GetHitBox().x,p->GetHitBox().y+i*24,300,24}),
//                                          ALIGN::LEFFT_ALIGN);
//    label->SetPosition(vec2f(p->GetHitBox().x,p->GetHitBox().y));
//    label->SetHitBox(SDL_FRect({p->GetHitBox().x,p->GetHitBox().y+i*24,300,24}));
//    p->Add(label);
//    }
//
//
//   int textureFilePath = App->GetAllTextureFilePath().size();
//for(int i = 0 ; i <  textureFilePath; i++ )
//    {
//
//    GUI_Wigdet * label = guiFactory->Create("GUI_Label");
//
//    dynamic_cast<GUI_Label*>(label)->Init(App->GetAllTextureFilePath()[i],App->GetAllTextureFilePath()[i],FontManager::Instance()->GetFont("OpenSans-Regular"),
//SDL_FRect({p->GetHitBox().x,p->GetHitBox().y+i*24,200,24}),
//                                          ALIGN::RIGHT_ALIGN);
//    label->SetPosition(vec2f(p->GetHitBox().x,p->GetHitBox().y*200));
//    label->SetHitBox(SDL_FRect({p->GetHitBox().x,200+i*24,200,24}));
//    p->Add(label);
//
//    }
// App->PushCommand_StateMachine("Push_State","State_SimpleDialogBox");
    vec2f o = WindowOrigin;
    vec2f camsize = APP->GetCamera().GetSize();
    vec2f campos = APP->GetCamera().GetPos();
    float scaler  = APP->GetCamera().GetScaler();


    boarder =  {campos.x, campos.y,camsize.x, camsize.y};
    boarder2 = {campos.x, campos.y,camsize.x, camsize.y};


    vec2f camOrigin = vec2f(camsize/2);

    float camOriginLength = camOrigin.Length();

//    std::cout << "boarder.w " << boarder.w << "\n";
    for(int i = 0 ; i <  boarder.h/2; i+=16 )
        for(int j = 0 ; j < boarder.w+200; j+=64 )
        {
            m_gameobjects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Block"));
            m_gameobjects.back()->Load("FileName_BreakOut_Block.txt");
            m_gameobjects.back()->GetPosition() = vec2f(j,i);


//            CollisionManager::Instance()->AddRect(SDL_Rect{j*64,i*32,64,16});
        }
    m_gameobjects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Paddle"));
    m_gameobjects.back()->Load("FileName_BreakOut_Paddle.txt");

    m_gameobjects.back()->GetPosition().x = 0;
    m_gameobjects.back()->GetPosition().y =camsize.y-16;


    m_gameobjects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Ball"));
    m_gameobjects.back()->Load("FileName_BreakOut_Ball.txt");

    BallSpawnUpdate();
    isBallSpawn = true;


    return true;

}
bool State_BreakOutGame::onExit() {}
void State_BreakOutGame::resume() {}
void State_BreakOutGame::HandleEvent(SDL_Event &e )
{
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        isBallSpawn = false;
    }
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::RIGHT))
    {
    }
    for(int i = 0 ; i < m_gameobjects.size(); i+=1 ) m_gameobjects[i]->HandleEvent(e);
}

void  State_BreakOutGame::RenderColour()
{
    vec2f camsize = APP->GetCamera().GetSize();
    vec2f campos = APP->GetCamera().GetPos();
    camsize/=2;
    TextureManager::Instance()->DrawRectWithBoarder(boarder,Colour_black,Colour_navy,2,APP->GetRenderer());
    GameObject_Ball& gb = *dynamic_cast<GameObject_Ball*>(m_gameobjects.back());
    {

        SDL_Rect redd {0,0,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_blue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_lightblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*2,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_royalblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*3,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_blueviolet,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*4,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_skyblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*5,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_slateblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*6,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_mediumblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*7,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_lightskyblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*8,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_aliceblue,App->GetRenderer());

    }
    {

        SDL_Rect redd {0,32*9,camsize.x*2,32};
//        TextureManager::Instance()->DrawRectFilled(redd,Colour_deepskyblue,App->GetRenderer());

    }
}
void State_BreakOutGame::DoBlockHit()
{

    vec2f o = WindowOrigin;
    GameObject_Ball& gb = *dynamic_cast<GameObject_Ball*>(m_gameobjects.back());
    int mass = gb.GetMass();
    gb.SetDead(true);
    for(int i = 0 ; i < m_gameobjects.size()-2; i+=1 )
    {
        if(!m_gameobjects[i]->Dead())
        {

//            GameObject_Block& block = *dynamic_cast<GameObject_Block*>(m_gameobjects[i]);
//
//            SDL_Rect intersect;
//            if(InputHandler::Instance()->HasIntersection(gb.GetSDLRect(), block.GetSDLRect()))
//
//            {
//                gb.FlipYspeed();
//
////                intersect = InputHandler::Instance()->IntersectRect(gb.GetSDLRect(), block.GetSDLRect(),intersect);
//                block.SetDead(true);
////            gb.GetPosition().x += intersect.w;
////            gb.GetPosition().y += intersect.h;
//          //     std::cout << intersect.w << "w | h << "<< intersect.h << "\n";
//
//            }
        }
    }

}
void  State_BreakOutGame::DoPaddleHit()
{
    vec2f o =WindowOrigin;
    GameObject_Ball& gb = *dynamic_cast<GameObject_Ball*>(m_gameobjects.back());
    GameObject_Paddle& bb = *dynamic_cast<GameObject_Paddle*>(m_gameobjects[m_gameobjects.size()-2]);
    int mass = gb.GetMass();

    SDL_Rect intersect;
    if(InputHandler::Instance()->HasIntersection(bb.GetSDLRect(),gb.GetSDLRect()))

    {
//        intersect = InputHandler::Instance()->IntersectRect(bb.GetSDLRect(),gb.GetSDLRect(),intersect);
        std::cout << intersect.w << "w | h << "<< intersect.h << "\n";
        gb.FlipYspeed();
    }

}

void State_BreakOutGame::DoWallHit()
{
    vec2f camsize = APP->GetCamera().GetSize();
    vec2f campos = APP->GetCamera().GetPos();


    boarder =  {campos.x, campos.y,camsize.x, camsize.y};
    GameObject_Ball& gb = *dynamic_cast<GameObject_Ball*>(m_gameobjects.back());
    int mass = gb.GetMass();

    if(gb.GetPosition().y+ mass >= boarder.h)
    {
//        this->isBallSpawn = true;

        gb.GetPosition().y= boarder.h-mass;
        gb.FlipYspeed();

        //  gb.FlipXspeed();
    }
    if(gb.GetPosition().y-mass <= 0)


        gb.FlipYspeed();

    if(gb.GetPosition().x+ mass >= boarder.w )
    {
        gb.GetPosition().x= boarder.w-mass;
        gb.FlipXspeed();
    }
    if(gb.GetPosition().x-mass <= 0)

        gb.FlipXspeed();
}
void State_BreakOutGame::BallSpawnUpdate()
{
    GameObject_Ball& gb = *dynamic_cast<GameObject_Ball*>(m_gameobjects.back());


    float paddleWidth = m_gameobjects[m_gameobjects.size()-2]->getWidth();
    float paddleHeight = m_gameobjects[m_gameobjects.size()-2]->getHeight();
    gb.GetPosition() = m_gameobjects[m_gameobjects.size()-2]->GetPosition();
    gb.GetPosition().x +=  paddleWidth/2;
    gb.GetPosition().y -=   paddleHeight;


}

/**<

    for(int i = 0 ; i <   CollisionManager::Instance()->getRects().size(); i+=1 )
        TextureManager::Instance()->DrawRect(CollisionManager::Instance()->getRects()[i],
                                             Colour_darkorange,
                                             App->GetRenderer());
    if(isBallSpawn)
    {

    }
    else
if(!InputHandler::Instance()->isTextInputActive())
TextureManager::Instance()->DrawText(InputHandler::Instance()->GetTextInput(),0,2,Colour_black,fontManager->GetFont("OpenSans-Regular"),Application::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(Ballv2.x,Ballv2.y,gb.GetPosition().x,gb.GetPosition().y,App->GetRenderer());

        Ballv =  gb.GetPosition().Dist(gb.GetVelocity());
        Ballv2 = gb.GetPosition() -gb.GetlastPosition()  ;
        Ballv2.Normalise();
        Ballv2*=Ballv;
        Ballv2.Limit(gb.GetMass());
        Ballv2+=gb.GetPosition();

        SDL_Point ball = { gb.GetPosition().x, gb.GetPosition().y};
        for(int i = 0 ; i <   CollisionManager::Instance()->getRects().size(); i+=1 )
            if(SDL_PointInRect(&ball,&CollisionManager::Instance()->getRects()[i]))
            {

m_gameobjects[i]->SetDead(true);
                vec2f ff =vec2f(CollisionManager::Instance()->getRects()[i].x+CollisionManager::Instance()->getRects()[i].h,CollisionManager::Instance()->getRects()[i].y+CollisionManager::Instance()->getRects()[i].h);
                ff-= gb.GetPosition();
                ff.Normalise();
                std::cout << vec2f::Dot(gb.GetPosition().GetNormalise(),ff) << "\n";

                if( vec2f::Dot(gb.GetPosition().GetNormalise(),ff)>0)
                {
                    gb.FlipXspeed();

                }
                else
                {
                    gb.FlipYspeed();
                }
m_gameobjects.back()->GetPosition().y = CollisionManager::Instance()->getRects()[i].y+CollisionManager::Instance()->getRects()[i].h +gb.GetMass() ;

                CollisionManager::Instance()->m_Rects.erase(CollisionManager::Instance()->m_Rects.begin()+i);
            }
    }

//
//
//
//
//  int TotalRowSize = rows*TileSize;
//    int TotalColumnSize = columns*TileSize;
//
//    for(int i = 0 ; i < rows; i++)
//    for(int j = 0 ; j < columns; j++)
//    {
//        DrawRect(i*TileSize+offsetX,j*TileSize+offsetY,TileSize,TileSize,render);
//    }
//    for(int i = 0 ; i < 5; i+=1 )
//        for(int j = 0 ; j < 5; j+=1 )
//        {
//            m_gameobjects.push_back(GameObjectFactory::Instance()->Create("BreakOut_Block"));
//            m_gameobjects.back()->Load("FileName_BreakOut_Block.txt");
//            m_gameobjects.back()->GetPosition() = vec2f(o.x*1.7+16-(j*65),o.y+16-(i*18));
//        }
////        dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetVelocity().y* -1;CV
//        m_gameobjects.back()->GetPosition()= vec2f(boarder.x+boarder.w/2,boarder.y+boarder.h/2);
// dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetPosition() = vec2f(200,200);
//gb.FlipXspeed();

//    for(int i = 0 ; i <   CollisionManager::Instance()->getGrid().size(); i+=1 )
//{vec2f collisionGrid = CollisionManager::Instance()->getGrid()[i];
//
//
// TextureManager::Instance()->DrawLine(collisionGrid.x,
//                                      collisionGrid.y,
//                                      collisionGrid.x,
//                                      collisionGrid.y+7,Colour_green,App->GetRenderer());
// TextureManager::Instance()->DrawLine(collisionGrid.x,
//                                      collisionGrid.y,
//                                      collisionGrid.x,
//                                      collisionGrid.y-7,Colour_red,App->GetRenderer());
//TextureManager::Instance()->DrawLine(collisionGrid.x,
//                                      collisionGrid.y,
//                                      collisionGrid.x+31,
//                                      collisionGrid.y,Colour_yellow,App->GetRenderer());
//TextureManager::Instance()->DrawLine(collisionGrid.x,
//                                      collisionGrid.y,
//                                      collisionGrid.x-31,
//                                      collisionGrid.y,Colour_blue,App->GetRenderer());
//
//}



// dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetVelocity().GetNormalise();




//    vec2f b =  m_gameobjects.back()->GetPosition();
//
//    vec2f a = dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetVelocity();
//    a.Normalise();
//
//    TextureManager::Instance()->DrawVector(a+m_gameobjects.back()->GetPosition(),
//                                           b,
//                                           100,
//                                           Colour_royalblue,
//                                           App->GetRenderer());
//    m_gameobjects[ m_gameobjects.size()-1];
//    vec2f bottomScreen = vec2f( m_gameobjects[ m_gameobjects.size()-1]->GetPosition().x,
//                                boarder.w);
//    vec2f bottomScreen2 = vec2f(m_gameobjects[ m_gameobjects.size()-1]->GetPosition().y,
//                                boarder.h);
//
//    TextureManager::Instance()->DrawLine(bottomScreen,bottomScreen2,App->GetRenderer());

    TextureManager::Instance()->DrawRectWithBoarder(boarder,Colour_sienna,Colour_honeydew,16,App->GetRenderer());
    for(int i = 0 ; i < m_gameobjects.size(); i+=1 )
        m_gameobjects[i]->Render();
dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetVelocity().GetNormalise();

    vec2f b =  m_gameobjects.back()->GetPosition();
    vec2f a = dynamic_cast<GameObject_Ball*>(m_gameobjects.back())->GetVelocity().GetNormalise();
    a.Normalise();

    TextureManager::Instance()->DrawVector(App->GetOrigin()+a,
                                           m_gameobjects.back()->GetPosition(),
                                           1006,
                                           Colour_royalblue,
                                           App->GetRenderer());



 if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        std::cout << "sdsdsddsds\n";
        s = inputHandler->GetMousePosition();
    }
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::RIGHT))
    {
        std::cout << "sdsdsddsds\n";
        s2 = inputHandler->GetMousePosition();
    }if(s.x && s.y != 0 && s2.x && s2.y != 0)
    {
        vec2f oo  = s2-s;
        oo = oo.GetOrtho();
        TextureManager::Instance()->DrawLine(s,s2,App->GetRenderer());
        TextureManager::Instance()->DrawLine(oo+s,s2,App->GetRenderer());
    }
//    SDL_Rect des = {m_position.x, m_position.y,m_width,m_height};

//    vec2f o = App->GetOrigin();
//
//     vec2f a = o;
//     a+= vec2f(0,100);
//     vec2f c = a-o;
    //
//    TextureManager::Instance()->DrawLine()
//for(int i = 0 ; i <  App->GetOrigin().x*2; i++ )
//TextureManager::Instance()->DrawLine(i,App->GetOrigin().y,i,1080,App->GetRenderer());
//
    // Application::Instance()->PushCommand(new Cmd::Window(App->GetWindow()->GetWindow(),"FullScreen"));
  */
