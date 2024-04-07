#include "MarioLevelState.h"

MarioLevelState::~MarioLevelState()
{
    m_topcol,m_botcol,m_Rightcol,m_leftcol = false;
    //dtor
}
MarioLevelState::MarioLevelState()
{


}
void MarioLevelState::DrawMarioObjects()
{


        for(int i = 0 ; i < MarioBackGrounds.size(); i++)
            MarioBackGrounds[i]->Render();
    for(int i = 0 ;  i < MarioItems.size(); i++)
    {
        MarioItems[i]->Render();
    }
    for(int i = 0 ;  i < MarioEnemies.size(); i++)
    {
        MarioEnemies[i]->Render();

    }
    for(int i = 0 ;  i < MarioBlocks.size(); i++)
    {
        MarioBlocks[i]->Render();
    }
    for(int i = 0 ;  i < MarioUIs.size(); i++)
    {
        MarioUIs[i]->Render();
    }

    if(dynamic_cast<GUI_Object*>(Widget_Box_Selection)->isFoucs())
    {
        for(int i = 0 ;  i < SelectableObjects.size(); i++)
        {
            SelectableObjects[i]->Render();
        }

    }

    if(m_MarioPlayer!=NULL)
        m_MarioPlayer->Render();
}
void MarioLevelState::Render()
{
    //  Widget_Box_Selection->Draw();
//
////
    //if(m_bisSelected)
    // TextureManager::Instance()->DrawText(m_isSelectedText,100,100,24,Game::Instance()->GetRenderer());
//
//    textObject->Draw();

//  //  m_Widget_ScrollBar->Draw();
//
//    std::stringstream s;
//    int ss = dynamic_cast<GUI_ScrollBar*>(m_Widget_ScrollBar)->GetCurrentPosition();
//    Game::Instance()->GetCamera()->Setpos(0,0);
//    s <<Game::Instance()->GetCamera()->getpos().x;
//
//    TextureManager::Instance()->DrawText(s.str(),0,0,48,Game::Instance()->GetRenderer());
//

    //TextureManager::Instance()->DrawFrame("Level_1-1",0,0,Game::Instance()->GetRenderer());

//
    if(Application::Instance()->Is_Debug())
    {

        m_MarioEditorlayer->Render();
        if(m_objectSelection!=NULL)
        {
            m_objectSelection->Render();
        }
        textObject->Render();


    }

//

    DrawMarioObjects();


//
  TextureManager::Instance()->SetColour(Colour_MarioBackGround_,Application::Instance()->GetRenderer());
}
void MarioLevelState::UpdateObjects()
{

    if(m_MarioPlayer!=NULL)
        m_MarioPlayer->Update();


    if(!MarioBackGrounds.empty())
        for(int i = 0 ; i < MarioBackGrounds.size(); i++)
            MarioBackGrounds[i]->Update();


    if(!MarioEnemies.empty())
        for(int i = 0 ; i < MarioEnemies.size(); i++)
            MarioEnemies[i]->Update();


    if(!MarioBlocks.empty())
        for(int i = 0 ;  i < MarioBlocks.size(); i++)
            MarioBlocks[i]->Update();


    if(!MarioItems.empty())
        for(int i = 0 ;  i < MarioItems.size(); i++)
            MarioItems[i]->Update();

    if(!MarioUIs.empty())
        for(int i = 0 ;  i < MarioUIs.size(); i++)
            MarioUIs[i]->Update();

}
void MarioLevelState::Update()
{
    m_bisSelected = false;

//    dynamic_cast<MarioEditorLayer*>(m_MarioEditorlayer)->Update(this);

    if(!bisPaused)
    {
        dt = Application::Instance()->GetDeltaTime();

        m_Widget_ScrollBar->Update();
        selectedingObject();

        UpdateObjects();
        Collision();
    }
}
void MarioLevelState::Collision()
{
    if(CollisionManager::Instance()->TestCollision(MarioBlocks,MarioItems))
    {
        Collision_Blocks_Items();
    }
    if(CollisionManager::Instance()->TestCollision(MarioBlocks,MarioEnemies))
    {
        Collision_Blocks_Enemies();
    }

    if(m_MarioPlayer!=NULL)
    {

        if(CollisionManager::Instance()->TestCollision(m_MarioPlayer,MarioBlocks))
        {
            Collision_MarioPlayer_Blocks();
        }
        if(CollisionManager::Instance()->TestCollision(m_MarioPlayer,MarioEnemies))
        {
            Collision_MarioPlayer_Enemies();
        }
        if(CollisionManager::Instance()->TestCollision(m_MarioPlayer,MarioItems))
        {
            Collision_MarioPlayer_Items();
        }
    }
}
void MarioLevelState::HandleEvent(SDL_Event &e )
{





    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_S)
        Save();
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_C)
        Clear();
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_R)
        Reset();
    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_L)
        Load();
    if(m_MarioPlayer!=NULL)
        m_MarioPlayer->HandleEvent(e);

    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_3)

        LoadPlayer("BigMario",16*3,16*11);

    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_4)

        LoadPlayer("SmallMario",16*3,16*12);


    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_5)
    {
//        Game::Instance()->PushState(new MarioEditorState());
    }

    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_LCTRL)
    {
        if(m_objectSelection==NULL)
        {
            GameObject *temp =  GameObjectFactory::Instance()->Create(MarioTypes[historyOfObjects.back()->Type()]);
            temp->Load((char*)historyOfObjects.back()->Type().c_str());
            temp->GetPosition() = InputHandler::Instance()->GetMousePosition();
            m_objectSelection = temp;
        }
    }

    if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_2)
    {
        offset+= -1;
//Game::Instance()->GetCamera()->Move(vec2f(offset,0),dt);

    }


    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_F1)
    {
        if(isEditing())
        {

            m_bisEditing = false;
        }
        else
        {
            m_bisEditing = true;
        }
    }

    if( e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_1)
    {
        if(isEditing())
        {

            SDL_RenderSetScale(Application::Instance()->GetRenderer(),4,4);

            m_bisEditing = false;
        }
        else
        {
            m_bisEditing = true;
            SDL_RenderSetScale(Application::Instance()->GetRenderer(),1,1);
        }

        // Save();
    }

    for(int i = 0 ;  i < MarioItems.size(); i++)
    {
        if(InputHandler::Instance()->MouseinRect((dynamic_cast<SDLGameObject*>(MarioItems[i])->GetSDLRect())))
        {
            m_bisSelected = true;
            m_isSelectedText = MarioItems[i]->Type();
        }

    }

    for(int i = 0 ; i < MarioEnemies.size(); i++)
    {
        if(InputHandler::Instance()->MouseinRect(dynamic_cast<SDLGameObject*>(MarioEnemies[i])->GetSDLRect()))
        {
            m_bisSelected = true;
            m_isSelectedText = MarioEnemies[i]->Type();
            //  std::cout << m_isSelectedText;
        }



        for(int i = 0 ;  i < MarioBlocks.size(); i++)
        {
            if(InputHandler::Instance()->MouseinRect((dynamic_cast<SDLGameObject*>(MarioBlocks[i])->GetSDLRect())))
            {
                m_bisSelected = true;
                m_isSelectedText = MarioBlocks[i]->Type();
            }
        }
        for(int i = 0 ;  i < MarioUIs.size(); i++)
        {
            if(InputHandler::Instance()->MouseinRect((dynamic_cast<SDLGameObject*>(MarioUIs[i])->GetSDLRect())))
            {
                m_bisSelected = true;
                m_isSelectedText = MarioUIs[i]->Type();
            }
        }
        if(InputHandler::Instance()->MouseinRect(dynamic_cast<SDLGameObject*>(m_MarioPlayer)->GetSDLRect()))
        {
            m_bisSelected = true;
            m_isSelectedText =  dynamic_cast<MarioPlayer*>(m_MarioPlayer)->getState();
        }

    }
    if(Application::Instance()->Is_Debug())
    {
//        dynamic_cast<MarioEditorLayer*>(m_MarioEditorlayer)->HandleEvent(e);

    }
}
bool MarioLevelState::OnEnter()
{
    tileSize = Application::Instance()->GetWindow()->getTile();
//    m_MarioEditorlayer = new MarioEditorLayer();
    bisPaused = false;
    std::cout << "OnEnter\n";

    Widget_Box_Selection = GameObjectFactory::Instance()->Create("GUI_RECT");
    Widget_Box_Selection->Load("asset/GUI_/GUI_RECT.txt");

    dynamic_cast<GUI_Object*>(Widget_Box_Selection)->SetSize({0,16*17,48*16+16+16,48*7});
    dynamic_cast<GUI_Object*>(Widget_Box_Selection)->changePos({0,16*17,48*16+16+16,48*7});

    m_Widget_ScrollBar = GameObjectFactory::Instance()->Create("GUI_ScrollBar");
    m_Widget_ScrollBar->Load("GUI_ScrollBar");

//    dynamic_cast<GUI_ScrollBar*>(m_Widget_ScrollBar)->SetSize({0,224,256,16});
//m_Widget_ScrollBar = new GUI_ScrollBar();


    MarioTypes["Goomba"]                          = "MarioEnemy";
    MarioTypes["BlueGoomba"]                      = "MarioEnemy";
    MarioTypes["GreyGoomba"]                      = "MarioEnemy";
    MarioTypes["GreenTurtle"]                     = "MarioEnemy";
    MarioTypes["BlueTurtle"]                      = "MarioEnemy";
    MarioTypes["RedTurtle"]                       = "MarioEnemy";
    MarioTypes["HammerThrowTurtle"]               = "MarioEnemy";
    MarioTypes["GreyHammerThrowTurtle"]           = "MarioEnemy";
    MarioTypes["ManEatingPlant"]                  = "MarioEnemy";
    MarioTypes["GreyManEatingPlant"]              = "MarioEnemy";

    MarioTypes["SqaureBrick"]                     = "MarioBlock";
    MarioTypes["BrickGround"]                     = "MarioBlock";
    MarioTypes["Brick"]                           = "MarioBlock";
    MarioTypes["Brick2"]                          = "MarioBlock";
    MarioTypes["QuestionMarkBlock"]               = "MarioBlock";
    MarioTypes["PipeL"]                     = "MarioBlock";
    MarioTypes["PipeR"]                     = "MarioBlock";
    MarioTypes["PipeBL"]                     = "MarioBlock";
    MarioTypes["PipeBR"]                     = "MarioBlock";

    MarioTypes["RedMushroom"]                     = "MarioItem";
    MarioTypes["GreenMushroom"]                   = "MarioItem";
    MarioTypes["StarPower"]                       = "MarioItem";
    MarioTypes["FireFlower"]                      = "MarioItem";
    MarioTypes["Coin"]                            = "MarioItem";

    MarioTypes["Timer"]                            = "MarioUI";

    MarioTypes["Cloud"]                           = "MarioBackGround";
    MarioTypes["Hill"]                            = "MarioBackGround";
    MarioTypes["Bush"]                            = "MarioBackGround";

    SelectableObjects.push_back(Add("Goomba",16,16*18));
    SelectableObjects.push_back(Add("BlueGoomba",16*3,16*18));
    SelectableObjects.push_back(Add("GreyGoomba",16*5,16*18));
    SelectableObjects.push_back(Add("GreenTurtle",16*7,16*18));
    SelectableObjects.push_back(Add("BlueTurtle",16*9,16*18));
    SelectableObjects.push_back(Add("RedTurtle",16*11,16*18));
    SelectableObjects.push_back(Add("HammerThrowTurtle",16*13,16*18));
    SelectableObjects.push_back(Add("GreyHammerThrowTurtle",16*15,16*18));
    SelectableObjects.push_back(Add("ManEatingPlant",16*17,16*18));
    SelectableObjects.push_back(Add("GreyManEatingPlant",16*19,16*18));

    SelectableObjects.push_back(Add("BrickGround",16*21,16*18));
    SelectableObjects.push_back(Add("SqaureBrick",16*21,16*20));
    SelectableObjects.push_back(Add("Brick2",16*23,16*20));
    SelectableObjects.push_back(Add("Brick",16*23,16*18));
    SelectableObjects.push_back(Add("QuestionMarkBlock",16*25,16*18));
    SelectableObjects.push_back(Add("PipeL",16*37,16*18));
    SelectableObjects.push_back(Add("PipeR",16*38,16*18));
    SelectableObjects.push_back(Add("PipeBL",16*37,16*19));
    SelectableObjects.push_back(Add("PipeBR",16*38,16*19));

    SelectableObjects.push_back(Add("RedMushroom",16*27,16*18));
    SelectableObjects.push_back(Add("GreenMushroom",16*29,16*18));
    SelectableObjects.push_back(Add("StarPower",16*31,16*18));
    SelectableObjects.push_back(Add("FireFlower",16*33,16*18));
    SelectableObjects.push_back(Add("Coin",16*35,16*18));
//
//
    SelectableObjects.push_back(Add("Hill",16,16*30));
    SelectableObjects.push_back(Add("Cloud",16*6,16*30));
    SelectableObjects.push_back(Add("Bush",16*8,16*32));
//


    textObject = GameObjectFactory::Instance()->Create("TextObject");
    dynamic_cast<TextObject*>(textObject)->SetfontName("OpenSans-Bold");
    dynamic_cast<TextObject*>(textObject)->SetColour(255,255,255,255);
    textObject->GetPosition().y = 0;
    textObject->GetPosition().x = 1100;
//
//    dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string("how are you?"));
//    dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string( "Whazzzup?"));

//    MarioUIs.push_back(Add("Timer",-16,0));
//    MarioItems.push_back(Add("GreenMushroom",-16,0));
//    MarioEnemies.push_back(Add("GreyGoomba",-16,0));

    // LoadPlayer("SmallMario",16*3,16*11);Load();

//
//    MarioBlocks.push_back(Add("Brick",16*0,16*11));
//    MarioBlocks.push_back(Add("Brick",16*5,16*11));
//    MarioBlocks.push_back(Add("Brick",16*4,16*11));
//    MarioBlocks.push_back(Add("Brick",16*3,16*11));
//    MarioBlocks.push_back(Add("Brick",16*2,16*11));
//    MarioBlocks.push_back(Add("Brick",16*1,16*11));
//    MarioBlocks.push_back(Add("Brick",16*5,16*12));
//    MarioBlocks.push_back(Add("Brick",16*5,16*13));
//
//    MarioBlocks.push_back(Add("Brick",16*0,16*12));
//    MarioBlocks.push_back(Add("Brick",16*0,16*13));
//

    // MarioBlocks.clear();

//    CollisionManager::Instance()->Add(MarioBlocks,"MarioBlocks");
//    CollisionManager::Instance()->Add(MarioEnemies,"MarioEnemies");
//    CollisionManager::Instance()->Add(MarioItems,"MarioItems");
//
//    int a,b,c,d,e = 0;
//
//
//    //  CollisionManager::Instance()->RemoveLayer("MarioBlocks");
//
////doesnt work
////    CollisionManager::Instance()->Clear();
//
//    b = CollisionManager::Instance()->GetObjectSize("MarioBlocks");
//    c = CollisionManager::Instance()->GetObjectSize("MarioItems");
//    e = CollisionManager::Instance()->GetObjectSize("MarioEnemies");
//
//    std::cout << " MarioBlocks  " << b
//              <<  " MarioItems " << c
//              << " MarioEnemies" <<e
//              <<" GetNumOfLayers " << CollisionManager::Instance()->GetNumOfLayers() <<  "\n";
//
//    std::cout<< "Entering : "<< GetStateID() << " \n";

    Application::Instance()->GetCamera()->setCameraArea(256,224);
//    textObject = GameObjectFactory::Instance()->Create("TextObject");
//    std::stringstream ss;
//    ss << "w /h : " << cam.w  << "/" << cam.h;
//    dynamic_cast<TextObject*>(textObject)->ChangeMessage(ss.str().c_str());
//
//

    for(int i = 0 ;  i < SelectableObjects.size(); i++)
    {
        SelectableObjects[i]->SetToIgnoreCamera();
    }
//
//    CollisionManager::Instance()->isCollision("MarioBlocks","MarioEnemies") ;

//
    // Save();
    return true;

}//
bool MarioLevelState::onExit()
{
    bisPaused = true;
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void MarioLevelState::resume()
{
    bisPaused = false;
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}
SDLGameObject* MarioLevelState::Add(std::string type,int x,int y)
{

    if(type=="Na")
    {
        return NULL;
    }
    GameObject * temp = GameObjectFactory::Instance()->Create(MarioTypes[type]);
    temp->Load((char*)type.c_str());
    temp->GetPosition() = vec2f(x,y);
    //   std::cout << type << std::endl;
    historyOfObjects.push_back(temp);
    std::cout << "size of historyOfObjects" << historyOfObjects.size() << "\n";

    return (SDLGameObject*)temp ;
}
void MarioLevelState::selectedingObject()
{

    SDL_Rect rr = {0,16*17,48*16+16+16,48*7};
    if(InputHandler::Instance()->MouseinRect(rr))
        dynamic_cast<GUI_Object*>(Widget_Box_Selection)->setFoucs();

    if(m_objectSelection==NULL)
        for(int i = 0 ;  i < SelectableObjects.size(); i++)
        {
            // SelectableObjects[i]->Update();
            if(InputHandler::Instance()->MouseinRect(dynamic_cast<SDLGameObject*>(SelectableObjects[i])->GetSDLRect()))
            {
                m_bisSelected = true;
                m_isSelectedText = SelectableObjects[i]->Type();


                if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
                {
                    m_objectSelection = GameObjectFactory::Instance()->Create(MarioTypes[SelectableObjects[i]->Type()]);
                    m_objectSelection->Load((char*)SelectableObjects[i]->Type().c_str());

                    m_leftClickDown = true;
                    break;
                }

            }
        }

    if(m_objectSelection!=NULL)
    {

        if(m_leftClickDown)
            if(!InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
            {
                m_leftClickDown = false;
                //    std::cout << m_objectSelection->Type() << " :  " << MarioTypes[ m_objectSelection->Type() ] <<"\n";
            }

        float  x = Application::Instance()->GetCamera()->getpos().x;
        float y = Application::Instance()->GetCamera()->getpos().y;

        SDL_Rect rr= {0,0,256*4,224};

        if(InputHandler::Instance()->MouseinRect(rr))
            if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
            {




                if( MarioTypes[ m_objectSelection->Type() ]=="MarioBackGround")
                    MarioBackGrounds.push_back(Add(m_objectSelection->Type(),m_objectSelection->GetPosition().x+x,m_objectSelection->GetPosition().y+y));
                if( MarioTypes[ m_objectSelection->Type() ]=="MarioBlock")
                    MarioBlocks.push_back(Add(m_objectSelection->Type(),m_objectSelection->GetPosition().x+x,m_objectSelection->GetPosition().y+y));
                if( MarioTypes[ m_objectSelection->Type() ]=="MarioEnemy")
                    MarioEnemies.push_back(Add(m_objectSelection->Type(),m_objectSelection->GetPosition().x+x,m_objectSelection->GetPosition().y+y));
                if( MarioTypes[ m_objectSelection->Type() ]=="MarioItem")
                    MarioItems.push_back(Add(m_objectSelection->Type(),m_objectSelection->GetPosition().x,m_objectSelection->GetPosition().y));
                if( MarioTypes[ m_objectSelection->Type() ]=="MarioUI")
                    MarioUIs.push_back(Add(m_objectSelection->Type(),m_objectSelection->GetPosition().x,m_objectSelection->GetPosition().y));

                delete m_objectSelection;
                m_objectSelection = NULL;
                return;
            }
        //  MarioBlocks.push_back()
        m_objectSelection->Update();
        m_objectSelection->GetPosition().x = (int)((InputHandler::Instance()->GetMousePosition().x)/16 )*16;
        m_objectSelection->GetPosition().y = (int)((InputHandler::Instance()->GetMousePosition().y)/16 )*16 ;
        m_objectSelection->SetToIgnoreCamera();

        if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::RIGHT))
        {
            delete m_objectSelection;
            m_objectSelection = NULL;

        }
    }
}
void MarioLevelState::Load()
{
    std::ifstream ifs;
    std::string l_type;
    int l_x,l_y = 0;
 {


        ifs.open (MarioBackGrounds_filename, std::ofstream::in);
        while(!ifs.eof())
        {
            ifs >> l_type;
            if(l_type=="Na")
                break;

            ifs >> l_x;
            ifs >> l_y;

            MarioBackGrounds.push_back(Add(l_type,l_x,l_y));
            dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string(l_type));
        }

        ifs.close() ;
    }
    {


        ifs.open (MarioBlocks_filename, std::ofstream::in);
        while(!ifs.eof())
        {
            ifs >> l_type;
            if(l_type=="Na")
                break;

            ifs >> l_x;
            ifs >> l_y;

            MarioBlocks.push_back(Add(l_type,l_x,l_y));
            dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string(l_type));
        }

        ifs.close() ;
    }
    {


        ifs.open (MarioItems_filename, std::ofstream::in);
        while(!ifs.eof())
        {
            if(ifs.good())
            {
                ifs >> l_type;
                if(l_type=="Na")
                    break;
                ifs >> l_x;
                ifs >> l_y;
                MarioItems.push_back(Add(l_type,l_x,l_y));
                dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string(l_type));
            }
        }
        ifs.close() ;

    }
    {
        ifs.open (MarioEnemies_filename, std::ofstream::in);

        while(!ifs.eof())
        {
            if(ifs.good())
            {
                ifs >> l_type;
                if(l_type=="Na")
                    break;
                ifs >> l_x;
                ifs >> l_y;
                MarioEnemies.push_back(Add(l_type,l_x,l_y));
                dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string(l_type));
            }
        }
        ifs.close() ;
    }
    {
        ifs.open (MarioUIs_filename, std::ofstream::in);
        while(!ifs.eof())
        {
            if(ifs.good())
            {
                ifs >> l_type;
                if(l_type=="Na")
                    break;
                ifs >> l_x;
                ifs >> l_y;
                MarioUIs.push_back(Add(l_type,l_x,l_y));
                dynamic_cast<TextObject*>(textObject)->AddSentence(new std::string(l_type));
            }
        }
        ifs.close() ;

    }
    LoadPlayer("BigMario",16*3,16*11);

}
void MarioLevelState::Save()
{
    std::ofstream ifs;

    {


        ifs.open (MarioBackGrounds_filename, std::ofstream::out);
        if(MarioBackGrounds.empty())
            ifs << "Na"  ;

        else
            for(int i = 0; i <MarioBackGrounds.size(); i++)
                ifs<< " " <<  MarioBackGrounds[i]->Type() << " " << (int)MarioBackGrounds[i]->GetPosition().x << " " << (int)MarioBackGrounds[i]->GetPosition().y;
        ifs.close() ;
    }
    {


        ifs.open (MarioBlocks_filename, std::ofstream::out);
        if(MarioBlocks.empty())
            ifs << "Na"  ;

        else
            for(int i = 0; i <MarioBlocks.size(); i++)
                ifs<< " " <<  MarioBlocks[i]->Type() << " " << (int)MarioBlocks[i]->GetPosition().x << " " << (int)MarioBlocks[i]->GetPosition().y;
        ifs.close() ;
    }
    {


        ifs.open (MarioItems_filename, std::ofstream::out);
        if(MarioItems.empty())
            ifs << "Na"  ;

        else
            for(int i = 0; i < MarioItems.size(); i++)
                ifs<< " " <<  MarioItems[i]->Type() << " " << (int)MarioItems[i]->GetPosition().x << " " << (int)MarioItems[i]->GetPosition().y;
        ifs.close() ;
    }
    {
        ifs.open (MarioEnemies_filename, std::ofstream::out);

        if(MarioEnemies.empty())
            ifs << "Na"  ;

        else
            for(int i = 0; i <MarioEnemies.size(); i++)
                ifs << " " <<   MarioEnemies[i]->Type() << " " << (int)MarioEnemies[i]->GetPosition().x << " " << (int)MarioEnemies[i]->GetPosition().y;
        ifs.close() ;
    }
    {

        ifs.open (MarioUIs_filename, std::ofstream::out);

        if(MarioUIs.empty())
            ifs << "Na"  ;
        else
            for(int i = 0; i < MarioUIs.size(); i++)
                ifs << " " <<   MarioUIs[i]->Type() << " " << (int)MarioUIs[i]->GetPosition().x << " " << (int)MarioUIs[i]->GetPosition().y;
        ifs.close() ;
    }
}
void MarioLevelState::Reset()
{
    //  Game::Instance()->ChangeGameState(new MarioLevelState());
    Clear();
    CollisionManager::Instance()->Clear();
    OnEnter();
    Load();

    //  OnEnter();
}
void MarioLevelState::Clear()
{

    for(int i = 0; i <MarioBackGrounds.size(); i++)
    {
        delete MarioBackGrounds[i];
        MarioBackGrounds.erase(MarioBackGrounds.begin()+i);
    }

    for(int i = 0; i <MarioBlocks.size(); i++)
    {
        delete MarioBlocks[i];
        MarioBlocks.erase(MarioBlocks.begin()+i);
    }
    for(int i = 0; i < MarioItems.size(); i++)
    {
        delete MarioItems[i];
        MarioItems.erase(MarioItems.begin()+i);

    }
    for(int i = 0; i <MarioEnemies.size(); i++)
    {
        delete MarioEnemies[i];
        MarioEnemies.erase(MarioEnemies.begin()+i);

    }
    for(int i = 0; i < MarioUIs.size(); i++)
    {

        delete MarioUIs[i];
        MarioUIs.erase(MarioUIs.begin()+i);
    }
//    for(int i = 0; i < SelectableObjects.size(); i++)
//    {
//
//        delete SelectableObjects[i];
//        SelectableObjects.erase(SelectableObjects.begin()+i);
//    }
    for(int i = 0; i < historyOfObjects.size(); i++)
    {


        historyOfObjects.erase(historyOfObjects.begin()+i);
    {

historyOfObjects.erase(MarioBackGrounds.begin()+i);

    }
    }

for(int i = 0; i < historyOfObjects.size(); i++)
    m_MarioPlayer = NULL;
    MarioBackGrounds.clear();
    MarioBlocks.clear();
    historyOfObjects.clear();
    MarioItems.clear();
    MarioEnemies.clear();
    MarioUIs.clear();
    //  SelectableObjects.clear();

    textObject->Clean();
}
void MarioLevelState::Collision_Blocks_Enemies()
{
    for(int i = 0; i < MarioBlocks.size(); i++)
    {
        for(int j = 0; j < MarioEnemies.size(); j++)
        {

            SDL_Point centre = {MarioEnemies[j]->GetPosition().x + (MarioEnemies[j]->getWidth()/2),
                                MarioEnemies[j]->GetPosition().y + (MarioEnemies[j]->getHeight()/2)
                               };
            SDL_Rect temp = dynamic_cast<SDLGameObject*>(MarioBlocks[i])->GetSDLRect();

            SDL_Point top = centre;
            top.y -=  MarioEnemies[j]->getHeight()/2;
            SDL_Point bottom = centre;
            bottom.y += MarioEnemies[j]->getHeight()/2;
            SDL_Point right = centre;
            right.x += MarioEnemies[j]->getWidth()/2;
            SDL_Point right2 = right;
            right2.y -=1;
            SDL_Point left = centre;
            left.x -= MarioEnemies[j]->getWidth()/2;
            SDL_Point left2 = left;
            left2.y -=1;
            SDL_Rect temp2 = dynamic_cast<SDLGameObject*>(MarioEnemies[j])->GetSDLRect();
            if(SDL_HasIntersection(&temp,&temp2))
            {
                MarioEnemies[j]->GetPosition().y = MarioBlocks[i]->GetPosition().y - (dynamic_cast<SDLGameObject*>(MarioEnemies[j])->GetSDLRect()).h;
                MarioEnemies[j]->GetVelocity().y = 0;
                MarioEnemies[j]->GetAcceleration().y = 0;
                MarioEnemies[j]->GetForce().y = 0 ;
//
//                dynamic_cast<MarioEnemy*>(MarioEnemies[j])->isOnGround();
            }
            else if(SDL_PointInRect(&left,&temp) || SDL_PointInRect(&left2,&temp))
            {
                if(!dynamic_cast<MarioEnemy*>(MarioEnemies[j])->iSFacingRight())
                {
                    dynamic_cast<MarioEnemy*>(MarioEnemies[j])->Turn();
                }
                MarioEnemies[j]->GetPosition().x +=MarioBlocks[i]->GetPosition().x +  MarioBlocks[i]->getWidth()- MarioEnemies[j]->GetPosition().x ;
                //  MarioEnemies[j]->GetAcceleration().x  =0;

            }
            else  if(SDL_PointInRect(&right,&temp) || SDL_PointInRect(&right2,&temp))
            {
                if(dynamic_cast<MarioEnemy*>(MarioEnemies[j])->iSFacingRight())
                {
                    dynamic_cast<MarioEnemy*>(MarioEnemies[j])->Turn();
                }
                MarioEnemies[j]->GetPosition().x += MarioBlocks[i]->GetPosition().x - MarioEnemies[j]->GetPosition().x - MarioEnemies[j]->getWidth();
                //   MarioEnemies[j]->GetVelocity().x =0;
                //   MarioEnemies[j]->GetAcceleration().x  =0;
            }
        }
    }
}
void MarioLevelState::Collision_Blocks_Items()
{
    for(int i = 0; i < MarioBlocks.size(); i++)
    {
        SDL_Rect temp = dynamic_cast<SDLGameObject*>(MarioBlocks[i])->GetSDLRect();


        for(int j = 0; j < MarioItems.size(); j++)
        {
            SDL_Rect temp2 = dynamic_cast<SDLGameObject*>(MarioItems[j])->GetSDLRect();

            if(SDL_HasIntersection(&temp,&temp2))
            {
                MarioItems[j]->GetPosition().y = MarioBlocks[i]->GetPosition().y - (dynamic_cast<SDLGameObject*>(MarioItems[j])->GetSDLRect()).h;
                MarioItems[j]->GetVelocity().y = 0;
                MarioItems[j]->GetAcceleration().y = 0;
                MarioItems[j]->GetForce().y = 0 ;
            }
        }

    }
}
void MarioLevelState::Collision_MarioPlayer_Blocks()
{

    SDL_Point centre = {m_MarioPlayer->GetPosition().x + (m_MarioPlayer->getWidth()/2),
                        m_MarioPlayer->GetPosition().y + (m_MarioPlayer->getHeight()/2)
                       };
    SDL_Point top = centre;
    top.y -=  m_MarioPlayer->getHeight()/2;
    SDL_Point bottom = centre;
    bottom.y += m_MarioPlayer->getHeight()/2;
    SDL_Point right = centre;
    right.x += m_MarioPlayer->getWidth()/2;
    SDL_Point right2 = right;
    right2.y -=1;
    SDL_Point left = centre;
    left.x -= m_MarioPlayer->getWidth()/2;
    SDL_Point left2 = left;
    left2.y -=1;
    // SDL_Point right = {temp2.xtemp2.w2,temp2.y};

    for(int i = 0; i < MarioBlocks.size(); i++)
    {
        if(MarioBlocks[i]->Dead())
        {
        }
        else
        {

            SDL_Rect temp = dynamic_cast<SDLGameObject*>(MarioBlocks[i])->GetSDLRect();


            if(SDL_PointInRect(&bottom,&temp))
            {
                m_MarioPlayer->GetPosition().y = MarioBlocks[i]->GetPosition().y - dynamic_cast<MarioPlayer*>(m_MarioPlayer)->GetSDLRect().h;
                m_MarioPlayer->GetVelocity().y = 0 ;
                m_MarioPlayer->GetForce().y = 0 ;
                dynamic_cast<MarioPlayer*>(m_MarioPlayer)->isOnGround();
//dynamic_cast<MarioBlock*>(MarioBlocks[i])->Type();

            }
            else if(SDL_PointInRect(&top,&temp))
            {
                if(m_MarioPlayer->Type()!="SmallMario")
                {

                    MarioBlocks[i]->Collision();

                }
                else
                    dynamic_cast<MarioBlock*>(MarioBlocks[i])->Bump();

                m_MarioPlayer->GetPosition().y +=MarioBlocks[i]->GetPosition().y +MarioBlocks[i]->getHeight() -m_MarioPlayer->GetPosition().y;
                m_MarioPlayer->GetVelocity().y = 0 ;
                m_MarioPlayer->GetForce().y = 0 ;
                //  MarioBlocks[i]->Collision();

                //     SoundManager::Instance()->SetPlay("smb_bump");

            }
            else if(SDL_PointInRect(&left,&temp) || SDL_PointInRect(&left2,&temp))
            {
                m_MarioPlayer->GetPosition().x +=MarioBlocks[i]->GetPosition().x +  MarioBlocks[i]->getWidth()-m_MarioPlayer->GetPosition().x ;
                m_MarioPlayer->GetVelocity().x  =0;
                m_MarioPlayer->GetAcceleration().x  =0;
                m_MarioPlayer->GetForce().y = 0 ;

            }
            else  if(SDL_PointInRect(&right,&temp) || SDL_PointInRect(&right2,&temp))
            {

                m_MarioPlayer->GetPosition().x +=MarioBlocks[i]->GetPosition().x -m_MarioPlayer->GetPosition().x -m_MarioPlayer->getWidth();
                m_MarioPlayer->GetVelocity().x =0;
                m_MarioPlayer->GetAcceleration().x  =0;
                m_MarioPlayer->GetForce().y = 0 ;
            }
        }
    }
}
void MarioLevelState::Collision_MarioPlayer_Enemies()
{
    SDL_Rect temp2 = dynamic_cast<SDLGameObject*>(m_MarioPlayer)->GetSDLRect();

    for(int i = 0; i < MarioEnemies.size(); i++)
    {
        SDL_Rect temp = dynamic_cast<SDLGameObject*>(MarioEnemies[i])->GetSDLRect();


        if(SDL_HasIntersection(&temp,&temp2))
        {
            if(m_MarioPlayer->Type()=="SmallMario")
            {
                // m_MarioPlayer->SetDead();
            }
            if(m_MarioPlayer->Type()!="SmallMario")
            {
                dynamic_cast<MarioPlayer*>(m_MarioPlayer)->Shrink();
            }

            // SDL_Quit();


        }
    }
}
void MarioLevelState::Collision_MarioPlayer_Items()
{
    SDL_Rect temp2 = dynamic_cast<SDLGameObject*>(m_MarioPlayer)->GetSDLRect();
    for(int i = 0; i < MarioItems.size(); i++)
    {
        SDL_Rect temp = dynamic_cast<SDLGameObject*>(MarioItems[i])->GetSDLRect();
        if(SDL_HasIntersection(&temp,&temp2))
        {}
    }
}
void MarioLevelState::LoadPlayer(std::string marioState,int x,int y)
{
    m_MarioPlayer = new MarioPlayer();
    m_MarioPlayer->Load((char*)marioState.c_str());
    m_MarioPlayer->GetPosition() = vec2f(x,y);
    m_MarioPlayer->GetSpeed() = 5.6  ;


}

//void MarioLevelState::LoadGround()
//{
////    vec2f l_grd = vec2f(0,16*12);
////    for(int i = 0; i < 3328/16; i++)
////    {
////        for(int j= 0 ; j < 2 ; j++)
////        {
////            int yoffset = l_grd.y-j+1*16;
////            MarioBlocks.push_back(Add("BrickGround",16*i,j*16+yoffset));
////        }
////    }
//}
//void MarioLevelState::LoadData1()
//{
//    vec2f l_grd = vec2f(0,16*13);
//    MarioBlocks.push_back(Add("QuestionMarkBlock",16*4+16+16,l_grd.y-16-16-16-16-16-16-16));
//    MarioBlocks.push_back(Add("Brick",16*4+16,l_grd.y-16-16-16));
//    MarioBlocks.push_back(Add("Brick",16*3+16,l_grd.y-16-16-16));
//    MarioBlocks.push_back(Add("Brick",16*5+16,l_grd.y-16-16));
//}
//void MarioLevelState::LoadEnemies()
//{
//    vec2f l_grd = vec2f(0,Game::Instance()->GetWindowHeight()-16*3);
//    MarioEnemies.push_back(Add("Goomba",96+16*1,112));
//    MarioEnemies.push_back(Add("BlueGoomba",96+16*2,112));
//    MarioEnemies.push_back(Add("GreyGoomba",96+16*3,112));
//    MarioEnemies.push_back(Add("GreenTurtle",96+16*4,112));
//    MarioEnemies.push_back(Add("RedTurtle",96+16*5,112));
//    MarioEnemies.push_back(Add("BlueTurtle",96+16*6,112));
//    MarioEnemies.push_back(Add("ManEatingPlant",96+16*7,112));
//    MarioEnemies.push_back(Add("GreyManEatingPlant",96+16*8,112));
//    MarioEnemies.push_back(Add("HammerThrowTurtle",96+16*9,112));
//    MarioEnemies.push_back(Add("GreyHammerThrowTurtle",96+16*10,112));
//}
//void MarioLevelState::LoadItems()
//{
//    MarioItems.push_back(Add("RedMushroom",16*3,16*3));
//    MarioItems.push_back(Add("GreenMushroom",16*4,16*3));
//    MarioItems.push_back(Add("Coin",16*5,16*3));
//    MarioItems.push_back(Add("FireFlower",16*6,16*3));
//    MarioItems.push_back(Add("StarPower",16*7,16*3));
//}
