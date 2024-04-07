#include "GameManagerWidget.h"

GameManagerWidget::GameManagerWidget()
{

    //ctor
}

GameManagerWidget::~GameManagerWidget()
{
    //dtor
}

void GameManagerWidget::Load(std::string FileLocation)
{
    {
        //        Vscrollbar m_Vscrollbar; // vscrollbar if contents is to big
//        Hscrollbar m_Hscrollbar ; // hscrollbar if contents is to bigPanel* m_Panel = new Panel();
//
 Gui::TabList *m_TabList = new TabList();
    Gui::Tab   *m_Tab = new Tab();

    m_TabList->Init("TabList",SDL_Rect({GetHitBox()}));
    m_Tab->SetPadding(0,0,0,0);
    m_Tab->SetFocus(true);
    m_Tab->Init("Scene1",SDL_Rect({0,0,48,24}));

   Add(m_TabList);
   m_TabList->Add(m_Tab);
    m_TabList->Add(WIDGETFACTORY->Create("Tab","a",SDL_Rect({m_TabList->GetHitBox().x+78,m_TabList->GetHitBox().y,48,24})));


//Add(    WIDGETFACTORY->Create("Panel","GameManagerPanel",GetHitBox()));
//Find("GameManagerPanel")->Add(WIDGETFACTORY->Create("Hscrollbar","HscrollbarPanel",SDL_Rect({GetHitBox().x+6,GetHitBox().y+GetHitBox().h-20,GetHitBox().w-16,16})));
//
//        {
//            auto a = &Find("HscrollbarPanel")->GetChild(GetChildSize()-1);
//            if(a!=NULL)
//            {
//                dynamic_cast<Hscrollbar*>(a)->SetConTextSize(300);
//                dynamic_cast<Hscrollbar*>(a)->SetScrollWidth(300);
//                 dynamic_cast<Hscrollbar*>(a)->Init("HscrollbarPanel",SDL_Rect({GetHitBox().x+6,GetHitBox().y+GetHitBox().h-24,GetHitBox().w-12,16}));
//                std::cout <<"GetScrolledValue"<< dynamic_cast<Hscrollbar*>(a)->GetScrolledValue() << "\n";
//                std::cout <<"GetScrolledValue"<< dynamic_cast<Hscrollbar*>(a)->GetScrollWidth() << "\n";
//
//            }
////GetChild(GetChildSize())->SetPadding(8,8,8,8);
//        }
//        SDL_Rect pannelOffset = {GetHitBox().x-6,GetHitBox().y-6,GetHitBox().w+12,GetHitBox().h+12};
//        Add(WIDGETFACTORY->Create("Panel","GameManagerPanel",pannelOffset));

//Panel*   m_Panel = new Panel();
//    m_Panel->Init("GameManagerPanel",GetHitBox());
//Add(m_Panel);
//

//
//        m_Panel = new Panel();
//        m_TabList = new TabList();
//         m_Tab = new Tab();
//        m_Panel->Init("GameScene",GetHitBox());
//        m_TabList->Init("TabList",SDL_Rect({m_Panel->GetHitBox().x,m_Panel->GetHitBox().y-16,m_Panel->GetHitBox().w,16}),{(0,0,0,0)});
//        m_Tab->Init("NAMEHOLDER",SDL_Rect({m_Panel->GetHitBox().x,m_Panel->GetHitBox().y-32,48,32}));
//        m_Tab->SetPadding(-8,0,0,4);
//        Add(m_Panel);
//        Add(m_TabList);
//        m_TabList->Add(m_Tab);
        struct s
        {
            int a;
            std::string v;

        };
        s f;
        f.a =SDL_GetTicks();
        f.v ="hello";
        double buff=3.14;                         // buffer for integers
        int i = 9;
        std::string  fileType =  ".dat";
        std::ofstream os({"intdata" + fileType  }, std::ios::binary);  // create output stream os

        os.write((char*)&f, sizeof(s));
        os.close();
        f.v = "";
        f.a = SDL_GetTicks();
        std::ifstream is("intdata.dat", std::ios::binary | std::ios::in);  // create input stream is
        is.read((char*)&f, sizeof(s));      // read from it
//   is.read((char*)&i, sizeof(i));      // read from it

//   std::cout << buff << std::endl;                     // display it

        std::cout << "\n";
        std::cout << f.a;
        std::cout << "\n";
        std::cout << f.v;
        std::cout << "\n";
        is.close();
    }
    {
        int MAX = 5;
        int buff[MAX];                            // buffer for integers


        for(int i=0; i<MAX; i++)
            buff[i] = i+1;                           // put some data into the buffer

        std::ofstream os("intdata1.dat", std::ios::binary);  // create output stream os

        os.write((char*)buff, MAX*sizeof(int));   // write to it

        os.close();                               // must close it before opening another
        // stream associated with the same file
        for(int i=0; i<MAX; i++)
            buff[i] =i;                            // clear buffer

        std::ifstream is("intdata1.dat", std::ios::binary);  // create input stream is
        is.read((char*)buff, MAX*sizeof(int));    // read from it

        for(int i=0; i<MAX; i++)
            std::cout << buff[i] << std::endl;               // display it
        is.close();
    }
    currentStateID = Type();
    if(!DirectoryHandler::Instance()->Load(FileLocation))
    {

        Config  = "error";
        return;
    }
    LFile & configtext = *DirectoryHandler::Instance()->GetFileMap()[FileLocation];
    Config = configtext.GetFileData();



//    m_titleText.LoadFromRenderedText(r,GetContextCentre().x-m_titleText.GetBounds().w/2,textpos.y+8);  m_Label.Init("DirectoryManager\n");
//     fps = 60;
//        currentStateID = Application::Instance()->GetStateMachine()->GetCurrentStateID();
//WorldView = WindowOrigin;
//PixelView = WindowOrigin*2;
//CameraView = Application::Instance()->GetCamera().GetPos();
//SceneView = WindowOrigin;

}

void GameManagerWidget::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
//
//std::cout << InputHandler::Instance()->GetMousePosition() << "\n";
}
void  GameManagerWidget::Update(float DeltaTime)
{

    deltaTime = DeltaTime;
    GameTime += DeltaTime;
    for(int i = 0 ; i < m_layers.size(); i++ )
    {

        m_layers[i]->Update(deltaTime);

    }
    for(int i = 0 ; i < m_gameObects.size(); i++ )
    {
        m_gameObects[i]->Update(deltaTime);


    }
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
}
void GameManagerWidget::Render(SDL_Renderer *r)
{

// TextureManager::Instance()->DrawRect(APP->GetRenderer(),APP->GetCamera().GetRect(),Colour_darkgrey,true);
// TextureManager::Instance()->DrawRect(APP->GetRenderer(),APP->GetCamera().GetRect(),Colour_red,true);
// TextureManager::Instance()->Drawcircle(r,GetHitBoxCentre().x+2,GetHitBoxCentre().y+2,Colour_green,16,true);
// TextureManager::Instance()->DrawGrid(GetPosition().x,GetPosition().y,(GetHitBox().w/8),(GetHitBox().h/8),8,Colour_black,r);

//TextureManager::Instance()->DrawLine(r,GetHitBox().x,GetHitBox().y,GetHitBox().w+GetHitBox().x,GetHitBox().h+GetHitBox().y,Colour_black);
// TextureManager::Instance()->DrawLine(r,GetHitBox().x+GetHitBox().w,GetHitBox().y,GetHitBox().x,GetHitBox().h+GetHitBox().y,Colour_black);
    for(int i = 0 ; i < m_layers.size(); i++ )
    {
        m_layers[i]->Render(r,Application::Instance()->GetCamera().GetWorldPos().x,Application::Instance()->GetCamera().GetWorldPos().x);
    }
    for(int i = 0 ; i < m_gameObects.size(); i++ )
    {
        m_gameObects[i]->Render(r,SceneView.x,SceneView.y);
    }
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);

//auto s = m_MenuBar->Find("GameManagerPanel");
//if(s!=NULL)
//s->SetVisable(false);



//
//    TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
//            fontManager->GetFont("OpenSans-Regular24"),
//            Config,
//            vec2f(0,32),
//            WindowOrigin.x*2,
//            Colour_white,
//            Align_Left,
//            0,
//            SDL_FPoint({150,32}),
//            SDL_FLIP_NONE);
//
//    TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
//            fontManager->GetFont("OpenSans-Regular24"),
//            Type(),
//            vec2f(),
//            WindowOrigin.x*2,
//            Colour_white,
//            Align_Left,
//            0,
//            SDL_FPoint({150,32}),
//            SDL_FLIP_NONE);
//    TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),str.str(),GetHitBox().x+4,GetHitBox().y+4,Colour_black,Align_Left);
////
//    TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
//            fontManager->GetFont("OpenSans-Regular24"),
//            "SceneView CameraView WorldView PixelView",
//            vec2f(),
//            WindowOrigin.x*2
//            Colour_white,
//            Align_Left,
//            0,
//            SDL_FPoint({150,32}),
//            SDL_FLIP_NONE);

}
void GameManagerWidget::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
void  GameManagerWidget::Add(IWidget* Child)
{
    m_children.push_back(Child);
}
