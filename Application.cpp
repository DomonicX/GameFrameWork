#include "Application.h"

Application *Application::s_pInstance = 0;

Application::Application():
    m_window(NULL),
    m_ren(NULL),
    m_pGameStateMachine(NULL),
    m_camera(vec2f(0,0),vec2f(0,0),0)
{

}
/**<
//
//    SDL_Event ev;
//    ev.type = userType;
//
//    ev.user.code = 232;
//    ev.user.data1 = new std::string("hello");
//    ev.user.data2 = new std::string("world");
//
//    SDL_PushEvent(&ev);
//
//    std::cout << userType << "\n";
//   SDL_Delay(1000);

//int userType = SDL_RegisterEvents(1);

 */

vec2f Application::GetMousePosition() const
{
    return vec2f(x,y);
}
Application::ShowSimpleMessageBox(Uint32 flags, const char *title, const char *message, SDL_Window *window)
{

    SDL_ShowSimpleMessageBox(flags,title, message, NULL);
}
/**<
// m_pGameStateMachine->PopState();
//
//
//Gui::WindowImp* temp = new Gui::WindowImp(*GetWindow());
//temp->Init("Window",{0,0,ScreenSize.x,ScreenSize.y});
//    SetWidgetWindow(temp);
//
//    Gui::Frame *frameTemp = new Gui::Frame(*temp,0);
//    frameTemp->Init("sdsds",{0,0,ScreenSize.x,ScreenSize.y});
//
//    temp->Add(frameTemp);
//m_widget = temp;
SDL_TEXTUREACCESS_STREAMING
//SDL_Surface *surf;
//surf = SDL_CreateRGBSurface(0,ScreenSize.x,ScreenSize.y,32,0,0,0,0);
//Uint8 r,g,b;
//Uint32 pixel= *(Uint32*)surf->pixels;
//SDL_GetRGB(pixel,surf->format,&r,&g,&b);
//
//std::cout << " r " <<(int)r<<"\n";
//
////SDL_PixelFormat p = *surf->format;
//Uint32 c = SDL_MasksToPixelFormatEnum(p.BitsPerPixel,p.Rmask,p.Gmask,p.Bmask,p.Amask);
//

//    void SetRenderScale(){SDL_RenderSetScale}
//    void SetRenderViewport(){SDL_RenderSetViewport}
//SDL_RenderSetScale SDL_RenderWindowToLogical
//    SDL_Rect i = {0,0,ScreenSize.x,ScreenSize.y};
//    SDL_RenderSetViewport(&m_render->GetRender(),&i);
//    SDL_RenderSetLogicalSize(;
//    void SetRenderLogicalSize(&m_render->GetRender(),640,360);
// SDL_Rect viewport = {0,0,224,288};
//
//    SDL_RenderSetViewport(GetRenderer(),&viewport);
////    SDL_RenderSetClipRect(GetRenderer(),&viewport);
//////SDL_RenderIsClipEnabled(GetRenderer());
//SDL_RenderSetLogicalSize(GetRenderer(),224,288);
//   SDL_RenderSetIntegerScale(GetRenderer(),SDL_TRUE);
// SDL_RenderSetScale(GetRenderer(),2,2);
////
//
//IWidget* temp = new Gui::WindowImp(*GetWindow());
//    SetWidgetWindow(temp);


//    cmdStateMachine("Push_State",std::string("State_PacMan"));

// cmdStateMachine("Pop_State","Pop_State");
// m_pGameStateMachine->PopState();
// cmdStateMachine("Change_State",std::string("State_PacMan"));

////
//Change_State:
//    SDL_Event UserEvent;
//    UserEvent.type =  SDL_USEREVENT;
//    UserEvent.user.code = Create_Gameobject;
//    UserEvent.user.data1  = GameObjectFactory::Instance()->Create("GameObjectProxy");
//    UserEvent.user.data2 = new std::string();
//    SDL_PushEvent(&UserEvent);
//     PushCommand_Window("Show","");
    //    void Application::SetWidgetWindow(IWidget* winImp)
//    {
//        m_widget = winImp;
//    } */
bool Application::Init(const char *title, int x, int y, int w,int h,Uint32 flags,std::string State, IWidget* widget)
{
    m_bRunning = true;

    std::cout << "OS : <" <<InputHandler::Instance()->Get_OS() << ">\n";
    //std::cout << DirectoryHandler::Instance()->GetFileBase() << "\n";

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_INFO);
//   if(!INPUTHANDLER->SetAppState()) m_bRunning = false;
    userType = SDL_RegisterEvents(1);

    if (userType == ((uint32_t) -1))
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_ERROR,SDL_LogPriority::SDL_LOG_PRIORITY_CRITICAL,"Error.. userType EVENT register Fail\n");

        m_bRunning = false;
    }
    std::string AppUser = "AppUser";
    std::string LogUser = "LogUser";
    std::string GuiUser = "GuiUser";


// SDL_CreateWindowAndRenderer(640,360,-1,gWindow,m_ren);

//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");x
////
    // dynamic_cast<WindowImp*>(widget)->Save("WidgetLayout.txt");
//   std::cout <<widget->Type()<< "\n";
    APP->GetCamera().SetScaler(1);
// dynamic_cast<WindowImp*>(widget)->Save("WidgetLayout.txt");

    std::cout << "NumVideoDisplays " << SDL_GetNumVideoDisplays() << " \n";
    for(int i=0; i < SDL_GetNumVideoDisplays(); ++i)

    {

        int should_be_zero = SDL_GetCurrentDisplayMode(i, &m_DisplayMode);
        if(should_be_zero != 0)
            // In case of error...
            std::cout << "Could not get display mode for video display #" << i << ": " << SDL_GetError();

        else
            // On success, print the current display mode.
            std::cout << "Display #" << i
                      << ": current display mode is " << m_DisplayMode.w << 'x' << m_DisplayMode.h
                      << "px @ " << m_DisplayMode.refresh_rate << "hz. \n";


        m_frameRate = m_DisplayMode.refresh_rate;
        m_frameDelay = 1000.f/(float)m_frameRate;
        m_aspectRatio = m_DisplayMode.w/(float)m_DisplayMode.h;
        m_scale   =m_DisplayMode.w/(float)w;
    }
    std::cout <<"\n\n m_aspectRatio ";
    std::cout <<   m_aspectRatio;
    std::cout <<"\n  m_scale ";
    std::cout <<   m_scale;
    std::cout <<"\n\n\n";



    m_window =  new Window(title,x,y,w,h,flags,widget);
    if(m_window->GetWindow()==nullptr)
    {


        std::cout << SDL_GetError();
        std::cout << " \nCreateWindow  error \n";
        SDL_ClearError();


    }

    m_ren = SDL_CreateRenderer(m_window->GetWindow(),-1,SDL_RENDERER_ACCELERATED);


    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    if(m_ren==nullptr)
    {

        std::cout << SDL_GetError();
        std::cout << " \nSDL_CreateRenderer  error \n";
        SDL_ClearError();


    }


    if(SDL_GetRendererInfo(GetRenderer(),&m_Renderer_info))
    {


        std::cout << SDL_GetError();
        std::cout << " \SDL_GetRendererInfo  error \n";
        SDL_ClearError();
    }


    int lw,lh;
    if(SDL_GetRendererOutputSize(m_ren,&lw,&lh))
    {

        std::cout << SDL_GetError();
        std::cout << " \nSDL_CreateRenderer  error \n";
        SDL_ClearError();

    }
    std::cout << lw;
    std::cout << " \n";
    std::cout << lh;
    std::cout << " \n";
    {

        std::cout << "\nSDL_GetRendererInfo   \n";
        std::cout <<m_Renderer_info.flags<< "\n";
        std::cout <<m_Renderer_info.max_texture_height<< "\n";
        std::cout <<m_Renderer_info.max_texture_width<< "\n";
        std::cout <<m_Renderer_info.name<< "\n";
        std::cout <<m_Renderer_info.num_texture_formats<< "\n";
        std::cout <<*m_Renderer_info.texture_formats<< "\n";
        std::cout << "\nSDL_GetRendererOutputSize   \n";
        std::cout <<lw<< "\n";

        std::cout <<lh<< "\n";

    }

//    m_render =  new Render();
//Render::Render(SDL_Window * window,int index, Uint32 flags)
//{
//
//
//
//}
//    m_render =  new Render(m_window->GetWindow(),-1,SDL_RENDERER_ACCELERATED);
    //SDL_RenderSetVSync(&m_render->GetRender(),0);
//  SDL_RenderSetVSync(&m_render->GetRender(),0);
////    std::cout << "TargetSupported " <<"";
//    m_render->isRenderTargetSupported() ?     std::cout << "<Yes>" :     std::cout << "<No>";

    SDL_Log("GameStaetMachine Initializing");
    m_pGameStateMachine  = new GameStateMachine();

    SDL_Log("PushState : State_BlankScreen");
    m_pGameStateMachine->PushState(new State_BlankScreen());

    SDL_Log("Changing State to :\%s ",State.c_str() );
// SDL_Log( );
    m_pGameStateMachine->ChangeState(StateFactory::Instance()->Create(State));

    {
        m_AppInfoStr              <<
                                  "OS:" <<InputHandler::Instance()->Get_OS() <<
                                  "\nFPS:" <<GetFps() <<
                                  "\nStateID:" <<GetStateMachine()->GetCurrentStateID()<<
                                  "\nEngineflag:" << GetEngineflag() <<
                                  "\nDir:" << DirectoryHandler::Instance()->GetFileBase() <<
                                  "\nm_DisplayMode.w:" << m_DisplayMode.w <<
                                  "\nm_DisplayMode.h:" << m_DisplayMode.h ;
    }

    SDL_Log("SetShowWindow");

    std::cout << "\n"<<SDL_GetTicks()<< " SDL_GetTicks\n";
    SDL_TimerID timerID = SDL_AddTimer( 10000, callbackj, (char*)"PushState : fffffffffffffffffffffffffffff\n\n\n\n"  );
    //    SDL_RemoveTimer(timerID );

    SDL_ShowWindow(GetWindow()->GetWindow());
    x =0;
    y=0;
    SDL_GetMouseState(&x,&y);


    return m_bRunning;

}

void Application::Restart(void)
{
    m_AppEditorFlag = _RESTART_;
    quit();
}
/**<
    APP_STATE = SDL_RegisterEvents(SDL_EventState(1,SDL_ENABLE));



    SDL_Event UserEvent;
    UserEvent.type =  APP_STATE;
    UserEvent.user.code = 1;
        UserEvent.user.data1  = new std::string("Change_State");
    UserEvent.user.data2 = new std::string("TestState2");

    SDL_PushEvent(&UserEvent);

 SDL_RenderSetLogicalSize(&m_render->GetRender(),m_WindowRect.w,m_WindowRect.h);
    need to see if sdlwindow is connected to getwindow or if widgets have it

        SDL_ShowSimpleMessageBox(0,"sddddddd","sddddddd",GetWindow()->GetWindow())

    App->PushCommand_Camera("SetCameraSize","",vec2f(App->GetOrigin().x*2,App->GetOrigin().y*2));
    App->PushCommand_Camera("SetCameraPos","",vec2f(0,0));
    App->PushCommand_Camera("SetScaler","",vec2f(1,0));


  SDL_Surface*  m_texture = IMG_Load("sdsd");
  if(m_texture!=NULL)
  {
      IMG_SetError("sdsd");
  }

  if(!IMG_GetError())
{
    inputHandler->pushEvent(AppUser,"IMG_GetError()","init");
    SDL_Quit();
m_bRunning = false;
}
    m_CommandLineDir["Create_State"]           =    StateFactoryCmd::Create_State;
    m_CommandLineDir["register_State"]         =    StateFactoryCmd::register_State;
    m_CommandLineDir["GetSize_StateFactory"]   =    StateFactoryCmd::GetSize_StateFactory;
    m_CommandLineDir["Select_State_Type"]      =    StateFactoryCmd::Select_State_Type;
    m_CommandLineDir["Save_State"]             =    StateFactoryCmd::Save_State;

    m_CommandLineDir["Show"]                   =    WindowCmd::Show;
    m_CommandLineDir["FullScreen_Destop"]      =    WindowCmd::FullScreen_Destop;
    m_CommandLineDir["FullScreen"]             =    WindowCmd::FullScreen;
    m_CommandLineDir["Hide"]                   =    WindowCmd::Hide;
    m_CommandLineDir["Restore"]                =    WindowCmd::Restore;

    m_CommandLineDir["Load_Texture"]           =    TextureManagerCmd::Load_Texture;
    m_CommandLineDir["Save_Texture"]           =    TextureManagerCmd::Save_Texture;
    m_CommandLineDir["Delete_Texture"]         =    TextureManagerCmd::Delete_Texture;
    m_CommandLineDir["GetSize_Texture"]        =    TextureManagerCmd::GetSize_Texture;
    m_CommandLineDir["Aplha_Texture"]          =    TextureManagerCmd::Aplha_Texture;
    m_CommandLineDir["rgb_Texture"]            =    TextureManagerCmd::rgb_Texture;
    m_CommandLineDir["Select_Texture_Type"]    =    TextureManagerCmd::Select_Texture_Type;
    m_CommandLineDir["Load_Text"]    =    TextureManagerCmd::Load_Text;


    m_CommandLineDir["Create_Gameobject"]      =    GameobjectFactoryCmd::Create_Gameobject;
    m_CommandLineDir["Remove_Gameobject"]      =    GameobjectFactoryCmd::Remove_Gameobject;
    m_CommandLineDir["GetSize_GameObject"]     =    GameobjectFactoryCmd::GetSize_GameObject;
    m_CommandLineDir["register_Gameobject"]    =    GameobjectFactoryCmd::register_Gameobject;
    m_CommandLineDir["Save_Gameobject"]        =    GameobjectFactoryCmd::Save_Gameobject;
    m_CommandLineDir["Select_Gameobject_Type"] =    GameobjectFactoryCmd::Select_Gameobject_Type;

    m_CommandLineDir["Create_GUI"]             =    GUIFactoryCmd::Create_GUI;
    m_CommandLineDir["GetSize_GUI"]            =    GUIFactoryCmd::GetSize_GUI;
    m_CommandLineDir["Remove_GUI"]             =    GUIFactoryCmd::Remove_GUI;
    m_CommandLineDir["Register_GUI"]           =    GUIFactoryCmd::Register_GUI;
    m_CommandLineDir["Save_GUI"]               =    GUIFactoryCmd::Save_GUI;
    m_CommandLineDir["Select_GUI_Type"]        =    GUIFactoryCmd::Select_GUI_Type;
    m_CommandLineDir["Load_GUI"]               =    GUIFactoryCmd::LOAD_GUI;

    m_CommandLineDir["Set_isClearDisplay"]     =    RenderCmd::Set_isClearDisplay;
    m_CommandLineDir["Close_Render"]           =    RenderCmd::Close_Render;
    m_CommandLineDir["SetScale"]               =    RenderCmd::SetScale;

    m_CommandLineDir["Push_State"]             =    GameStateMachineCmd::Push_State;
    m_CommandLineDir["Pop_State"]              =    GameStateMachineCmd::Pop_State;
    m_CommandLineDir["Remove_State"]           =    GameStateMachineCmd::Remove_State;
    m_CommandLineDir["Clear_State"]            =    GameStateMachineCmd::Clear_State;
    m_CommandLineDir["Change_State"]           =    GameStateMachineCmd::Change_State;

    m_CommandLineDir["SetCameraPos"]           =    CameraCmd::SetCameraPos;
    m_CommandLineDir["SetCameraSize"]          =    CameraCmd::SetCameraSize;
    m_CommandLineDir["SetScaler"]              =    CameraCmd::SetScaler;
    m_CommandLineDir["SetAction"]              =    CameraCmd::SetAction;
    m_CommandLineDir["Load_GameState"]         =    GameStateCmd::Load_GameState;

    m_CommandLineDir["Set_Frame"]              =   AppCmd::Set_Frame;
    m_CommandLineDir["Add_Pannel"]             =   AppCmd::Add_Pannel;
    m_CommandLineDir["Add_Button"]             =   AppCmd::Add_Button;
    m_CommandLineDir["Add_MenuBar"]             =   AppCmd::Add_MenuBar;
    m_CommandLineDir["Add_Menu"]               =   AppCmd::Add_Menu;
    m_CommandLineDir["Add_SubMenu"]            =   AppCmd::Add_SubMenu;
    m_CommandLineDir["Add_Label"]              =   AppCmd::Add_Label;
    m_CommandLineDir["Add_ScrollBar"]          =   AppCmd::Add_ScrollBar;
    m_CommandLineDir["Clear_Frame"]             =   AppCmd::Clear_Frame;
    m_CommandLineDir["Set_FrameLayout"]        =   AppCmd::Set_FrameLayout;

    std::cout << "command line dir size: " << CommandLineSize() << "\n";

     char *ptr;
   int length;
 Find length of pattern
    length = strlen(pattern);
     Search pattern inside input string
    ptr = strstr(string, pattern);
    const char* s = "Hello";
    std::printf("Strings:\n"); // same as std::puts("Strings:");
    std::printf("\t[%10s]\n",          s);
    std::printf("\t[%-10s]\n",         s);
    std::printf("\t[%*s]\n",       10, s);
    std::printf("\t[%-10.*s]\n",    4, s);
    std::printf("\t[%-*.*s]\n", 10, 4, s);

    std::printf("Characters:\t%c %%\n", 'A');

    std::printf("Integers:\n");
    std::printf("\tDecimal:    \t%i %d %.6i %i %.0i %+i %i\n",
                1, 2,   3, 0,   0,  4,-4);
    std::printf("\tHexadecimal:\t%x %x %X %#x\n",
                5,10,10,  6);
    std::printf("\tOctal:      \t%o %#o %#o\n",
                10, 10,  4);

    std::printf("Floating point:\n");
    std::printf("\tRounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
    std::printf("\tPadding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
    std::printf("\tScientific:\t%E %e\n", 1.5, 1.5);
    std::printf("\tHexadecimal:\t%a %A\n", 1.5, 1.5);
    std::printf("\tSpecial values:\t0/0=%g 1/0=%g\n", 0.0/0.0, 1.0/0.0);

    std::printf("Variable width control:\n");
    std::printf("\tright-justified variable width: '%*c'\n", 5, 'x');
    int r = std::printf("\tleft-justified variable width : '%*c'\n", -5, 'x');
    std::printf("(the last printf printed %d characters)\n", r);

    std::printf("Fixed-width types:\n");
    std::uint32_t val = std::numeric_limits<std::uint32_t>::max();
    std::printf("\tLargest 32-bit value is %" PRIu32 " or %#" PRIx32 "\n",
                val,            val);
    printf(   "\n");
    printf("%-200s", "initialization...\n");
    std::cout << "frameRate " << m_frameRate << " \n";
    std::cout << "m_frameDelay " << (double)m_frameDelay << " \n";
    setFileBase();

    std::string str ("bin/Debug ");
    std::cout << "The size of str is " << str.length() << " bytes.\n";

    std::string stest = "\bin\Debug\\";

   int len = std::strlen("\bin\Debug\\");
    std::string ss  =   GetFileBase();
    ss.resize( ss.length()-str.length());
    .substr(0,0);
        std::cout <<ss << "\n";
          std::cout <<m_AppFileAsset << "\n";

    m_AppFileAsset= ss + "asset\\";
    m_AppFileFont= ss + "font\\";
    m_AppFileImg= ss + "img\\";
    m_AppFileLevel= ss + "level\\";

s2.push_back('s');


    float Scaler = 2.5;
    App->GetCamera().SetScaler(Scaler);
    App->GetCamera().SetSize(vec2f(37,360));
        App->GetCamera().SetPos(vec2f(40,0));
    if(Scaler==1)
    {



    }
    else
        App->GetCamera().SetPos(vec2f(0,32));
    m_WindowRect =  widget->GetHitBox();
    std::cout << "WindowRect.x " << m_WindowRect.x << " \n";

    std::cout << "WindowRect.y " << m_WindowRect.y << " \n";

    std::cout << "WindowRect.w " << m_WindowRect.w << " \n";

    std::cout << "WindowRect.h " << m_WindowRect.h << " \n";

      m_menuBarSize = vec2f(0,widget->GetChild(0).GetSize().y);
    m_WindowRect.y+=m_menuBarSize.y;
   m_WindowRect.h-=m_menuBarSize.y;
   std::cout << "menubar " << m_menuBarSize << " \n";

 */
void  Application::HandleEvent()
{

    SDL_Event e;
    while(SDL_PollEvent(&e)!=0)
    {
//


        if(e.type==SDL_QUIT)
        {



//////
//    SDL_Event UserEvent;
//    UserEvent.type =  APP_STATE;
//    UserEvent.user.code = GameStateMachineCmd::Change_State;
//        UserEvent.user.data1  = new std::string("Change_State");
//    UserEvent.user.data2 = StateFactory::Instance()->Create("TestState2");
//
//    SDL_PushEvent(&UserEvent);

            std::cout << "QUITING\n";
            quit();

//            PushCommand(new Command("Quit"));


        }


//        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
//        {
////window is set to not fullscreenable by defaul
//            m_window->SetIsFullScreenAble(true);
//        }


        if(e.type==SDL_USEREVENT)
        {

            switch(e.user.code)
            {

            case 0:
            {
                int Data1 = (*(int*)(e.user.data1));
                int Data2 = (*(int*)(e.user.data2));

                SDL_SetWindowSize(GetWindow()->GetWindow(),Data1,Data2);
                break;
            }
            case 1:
            {
                std::string Data1 = (*(std::string*)(e.user.data1));
                std::string Data2 = (*(std::string*)(e.user.data2));
                delete (std::string*)(e.user.data1);
                delete (std::string*)(e.user.data2);
                  std::cout<<" code : <"  << e.user.code  << "> Data1 : <" <<  Data1 << "> Data2 : <" << Data2 << ">\n";
                  if(Data1==("Restart"))

                    Restart();

            }
            break;
            case 2:
            {

                std::string Data1 = (*(std::string*)(e.user.data1));
                std::string Data2 = (*(std::string*)(e.user.data2));
             //   std::cout  << " tick " << e.user.timestamp <<" code " <<  e.user.code <<" Data1 : <"<<  Data1   << ">  Data2 : <" << (std::string*)(e.user.data1)  <<"> ";
              //  std::cout << " Data2 : <"<<  Data2   << ">  Data2 : <" << (std::string*)(e.user.data2) <<">\n";
                  std::cout<<" code : <"  << e.user.code  << "> Data1 : <" <<  Data1 << "> Data2 : <" << Data2 << ">\n";
//             if(Data1==("State"))
//                {
//      GetStateMachine()->PushState(stateFactory->Create(Data2));
//                }
                        if(Data1==("State"))
                {
      GetStateMachine()->ChangeState(stateFactory->Create(Data2));
                }





 delete (std::string*)(e.user.data1);
 delete (std::string*)(e.user.data2);


                }
            break;
//                std::cout << " code 0\n";
//                break;
//            case 1:
//                std::cout << " code 1\n";
//                break;
//            case 2:
//                std::cout << " code 2\n";
//                break;
//            case 3:
//                std::cout << " code  3\n";
//                break;
//
//            default :
//     break;
//            };
//            std::string Data1 = (*(std::string*)(e.user.data1));
//            std::string Data2 = (*(std::string*)(e.user.data2));
//            std::cout  << " tick " << e.user.timestamp <<" code " <<  e.user.code <<" Data1 : <"<<  Data1   << ">  Data2 : <" << (std::string*)(e.user.data1)  <<"> ";
//            std::cout << " Data2 : <"<<  Data2   << ">  Data2 : <" << (std::string*)(e.user.data2) <<">\n";
//
//            delete (std::string*)(e.user.data1);
//            delete (std::string*)(e.user.data2);
            }
        }
        SDL_GetMouseState(&x,&y);
        INPUTHANDLER->HandleEvent(e);
        m_window->HandleEvent(e);
        m_pGameStateMachine->HandleEvent(e);


//DirectoryHandler::Instance()->Load("2222.txt");
//LFile & s = *DirectoryHandler::Instance()->GetFileMap()["2222.txt"];
//
//logg<< (std::string*)(e.user.data2)  <<"\n";
//
//DirectoryHandler::Instance()->ChangeData("2222.txt",logg.str());
//DirectoryHandler::Instance()->Save("2222.txt");



    }
}

void Application::Update()
{
    GetWindow()->update((m_deltaTime));
    // m_pGameStateMachine->Update();
    m_pGameStateMachine->Update((m_deltaTime));
}
void Application::Draw()
{

    SDL_RenderClear(GetRenderer());

    TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),WindowRect,Colour_GUIForeGround,true);
    textureManager->SetColour(Colour_indianred,GetRenderer());

    m_pGameStateMachine->Render(GetRenderer());


    m_window->Render(GetRenderer());

    TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),CAMRECT,Colour_blue,false);

    {
        std::stringstream ww;
        ww <<GetDeltaTime();
        TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLA"),ww.str(),CAMCENTRE.x*2,0,Colour_yellow,Align_Right,16);
    }


// std::stringstream  TempstrStream ;
//    TempstrStream              <<
//        "\nDir:     " << DirectoryHandler::Instance()->GetFileBase() <<
//       " OS:        " <<InputHandler::Instance()->Get_OS() <<
//        "\nFPS:     " <<GetFps() <<
//        "\nW:       " <<WindowOrigin*2 <<
//        "\nState    " <<GetStateMachine()->GetCurrentStateID()<<
//        "\nMode:    " << GetEngineflag() <<
//        "\ncam:     " << GetCamera() <<
//        "\nGameTime:" << GetGameTime();
//
//
//
//FontManager::Instance()->SetSize("CONSOLA",8*m_camera.GetScaler());
//      TextureManager::Instance()->DrawTextWrappedShaded(GetRenderer(),fontManager->GetFont("CONSOLA"),TempstrStream.str(),vec2f(),WindowOrigin.y/2,Colour_white,Colour_black,Align_Left,0,SDL_FPoint({0,0}),SDL_FLIP_NONE);
//TempstrStream.clear();

    SDL_RenderPresent(GetRenderer());
}
std::string Application::GetEngineflag()
{
    switch(m_AppEditorFlag)
    {
    case _NA_:
        return "_NA_";
        break;
    case _DEBUG_:
        return "_DEBUG_";
        break;
    case _GAME_:
        return "_GAME_";
        break;
    case _RESTART_:
        return "_RESTART_";
        break;
    case _TERMINATE_:
        return "_TERMINATE_";
        break;
    }
}
float Application::GetAspectRatio() const
{
    return m_window->getAspectRaito();
}
/*
////  m_AppInfo.SetWrapped(true);
//    m_AppInfo.ChangeText(m_AppInfoStr.str(),FontManager::Instance()->GetFont("CONSOLA"),APP->GetRenderer());
//
//    m_AppInfo.LoadFromRenderedText(GetRenderer(),WindowOrigin.x,WindowOrigin.x);
    /**<

    { std::stringstream  TempstrStream ;

             /TextureManager::Instance()->DrawTextWrappedShaded(GetRenderer(),fontManager->GetFont("CONSOLA"),m_AppInfoStr.str(),vec2f(),0,Colour_black,Colour_white,Align_Left,0,SDL_FPoint({0,0}),SDL_FLIP_NONE);TempstrStream.clear();
    }

//    TextureManager::Instance()->drawSprite("Tile_Floor_Wood",WindowOrigin.x,WindowOrigin.y,64,32,APP->GetRenderer(),SDL_FLIP_NONE);


//    vec2f b3 = vec2f(255,0);
//    vec2f a3 = vec2f();
//
//vec2f c3 = vec2f::Lerp(vec2f(),b3,1/(float)640);
//for(int i=0; i < 640 ; i++)
//
//   {  a3+=c3;
//   SDL_Color rr= SDL_Color{a3.Length()-MOUSEPOSITION.y+1%(int)255,a3.Length()-MOUSEPOSITION.x+1%(int)255,a3.Length()-MOUSEPOSITION.Length()+1%(int)255};
//
//textureManager->DrawLine(GetRenderer(),i,0,i,4,rr);
//    }
//    vec2f b3 = vec2f(255,0);
//    vec2f a3 = vec2f();
//
//vec2f c3 = vec2f::Lerp(vec2f(),b3,1/(float)640);
//for(int i=0; i < 640 ; i++)
//
//   {  a3+=c3;
//   SDL_Color rr= SDL_Color{a3.Length()-MOUSEPOSITION.y+1%(int)255,a3.Length()-MOUSEPOSITION.x+1%(int)255,a3.Length()-MOUSEPOSITION.Length()+1%(int)255};
//
//textureManager->DrawLine(GetRenderer(),i,0,i,4,rr);
//    }
//        std::cout << a3 << "\n";
//    textureManager->SetColour(Colour_dimgray,GetRenderer());
//
//      {
//        std::stringstream ww;
//        ww <<
//          GetDeltaTime();
//        TextureManager::Instance()->DrawText(GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),ww.str(),WindowOrigin.x*2,0,Colour_yellow,Align_Right);
//
//
//    }
//SDL_Rect tempRect = GetCamera().GetRect();
//tempRect.x += tempRect.w /4;
//tempRect.y += tempRect.h /4;
//tempRect.w = tempRect.w /2;
//tempRect.h = tempRect.h /2;
//
//SDL_Rect tempRect2 = tempRect;
//tempRect2.x += tempRect.w /4;
//tempRect2.y += tempRect.h /4;
//tempRect2.w = tempRect.w /2;
//tempRect2.h = tempRect.h /2;
//   TextureManager::Instance()->DrawRect(GetRenderer(),GetCamera().GetRect(),Colour_blue,true);
//   TextureManager::Instance()->DrawRect(GetRenderer(),tempRect,Colour_green,true);
//   TextureManager::Instance()->DrawRect(GetRenderer(),tempRect2,Colour_brown,true);
////   TextureManager::Instance()->DrawGrid(8,40,22,16,Colour_green,GetRenderer());
//
//TextureManager::Instance()->DrawGrid(0,0,WindowWidth/8,WindowHeight/8,16,Colour_lightgreen,APP->GetRenderer());
//TextureManager::Instance()->DrawGrid(0,0,WindowWidth/8,WindowHeight/8,32,Colour_darkgreen,APP->GetRenderer());
//TextureManager::Instance()->DrawGrid(0,0,WindowWidth/8,WindowHeight/8,64,Colour_green,APP->GetRenderer());
//
//        TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
//                                                    fontManager->GetFont("OpenSans-Regular24"),
//                                                    "SceneView CameraView WorldView PixelView",
//                                                    vec2f(0,0),
//                                                    200,
//                                                    Colour_white,Align_Left,
//                                                    0,
//                                                    SDL_FPoint({150,32}),
//                                                    SDL_FLIP_NONE);

//sdddd
//dsdsd
*/

/**<

hints
textureManager->DrawGrid(0,8,40,22,16,Application::Instance()->GetRenderer());
   TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
            fontManager->GetFont("OpenSans-Regular24"),
            Config,
            vec2f(0,32),
            WindowOrigin.x*2,
            Colour_white,
            Align_Left,
            0,
            SDL_FPoint({150,32}),
            SDL_FLIP_NONE);

SceneView
CameraView
WorldView
PixelView
 */


Application::~Application()
{


}
void Application::Clean()
{

    std::cout << "shutting_Down\n";


    m_pGameStateMachine->Clean();
    TextureManager::Instance()->Clean();
    SoundManager::Instance()->Close();
    FontManager::Instance()->Close();
    CollisionManager::Instance()->Clear();
    StateFactory::Instance()->Close();
    GameObjectFactory::Instance()->Close();
    InputHandler::Instance()->Clean();
    DirectoryHandler::Instance()->Clean();
    SDL_DestroyRenderer(m_ren);
    delete m_window;
//    delete m_render;

    SDLNet_Quit();

//
//    ICommand *c = new Command("PrintModuleInfo");
//    c->excute();
//   delete c;
    // delete m_GameLogger;
    std::cout << "GOOD BYE -__-\n";


    SDL_Quit();
    //delete this;
}
double Application::GetDeltaTime()
{
//   if(!m_window->IsFocus()) {return 0;}
    return m_deltaTime;
}
int Application::GetGameTime()
{
//   if(!m_window->IsFocus()) {return 0;}
    return m_Timer.GetTicks()/1000.f;
}


void  Application::quit()
{
//    m_ApplicationLogger.log("quitting \n");
    //  m_ApplicationLogger.ToString();
    m_bRunning = false;
}
bool Application::running()
{

    std::cout << SDL_GetTicks() << "\n";

    SDL_TimerID timerID = SDL_AddTimer(1000/(float)m_frameRate,callbackj,(char*)"hello"  );

    while (m_bRunning)
    {
        m_Timer.Start();


        m_frameStart = SDL_GetTicks();


        HandleEvent();

        Update();

        Draw();

        m_Timer.Pause();

        if(m_frameDelay >= m_Timer.GetTicks())
        {
            SDL_Delay(m_frameDelay - m_Timer.GetTicks());
        }
        m_deltaTime = (double(SDL_GetTicks() - m_frameStart)/(double)1000.f) ;

//        std::setbase(8);
//        std::setprecision(8)//
        //   std::cout <<  std::setprecision(0) << 1/(double)10000 << "\n";
    }
    SDL_RemoveTimer( timerID );

    return m_bRunning;
//std::cout << m_frameCount<< "\n";

}
/**<
        m_frameStart = m_Timer.GetTicks();
std::cout <<   m_Timer.GetTicks()/1000.f << "\n";
 m_Timer.Stop();
      //  m_Timer.UnPause();

        m_Timer.GetTicks();Pause();




        m_Timer.Start();

        m_frameStart = m_Timer.GetTicks();

        HandleEvent(e);

        Update();

        Draw();

        if(m_frameDelay >= m_Timer.GetTicks())
        {
            SDL_Delay(m_frameDelay - m_Timer.GetTicks());
        }
        m_deltaTime = 1000.f/m_Timer.GetTicks();

        m_Timer.Stop();

         */


GameStateMachine* Application::GetStateMachine()
{
    return m_pGameStateMachine;
}
Camera& Application::GetCamera()
{
    return m_camera;
}

SDL_Renderer* Application::GetRenderer() const
{
    return m_ren;
//    return m_render;
}
Window*  Application::GetWindow()
{
    return m_window;
}

const int  Application::GetFps()
{
    return m_frameRate;
}
//std::vector<std::string>Application::GetAllStatesID()
//{
//    std::vector<std::string>l_stateID;
//    if(! m_pGameStateMachine->GetGameState().empty())
//        for(int i = 0; i < m_pGameStateMachine->GetGameState().size(); i++)
//            l_stateID.push_back(m_pGameStateMachine->getStack()[i]->Type());
//    else
//    {
//        l_stateID.push_back(" ");
//        return l_stateID;
//    }
//    return l_stateID;
//}



void Application::PushEvent(int code, void* data1, void* data2)
{

    SDL_Event UserEvent;
    UserEvent.type =   userType;
    UserEvent.user.code =  code;
    UserEvent.user.data1  = data1;
    UserEvent.user.data2 = data2;

    SDL_PushEvent(&UserEvent);
}

/**<
SDL_Event ev;
ev.type = InputHandler::Instance()->sdl_userEventSTATE;

ev.user.code = 1;
ev.user.data1 = NULL;
ev.user.data2 = NULL;

SDL_PushEvent(&ev); */
/**<

    m_camera = Camera(vec2f(1,1),vec2f(1,1),1);


    SDL_DisplayMode *dm;
    SDL_GetWindowDisplayMode(m_window->GetWindow(),dm);

    std::cout << "window displaymode w:h : " << dm->w << " " << dm->h <<"\n";
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","State_BlankScreen"));

    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));
  PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));

PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","State_BreakOutGame"));
PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState17"));
     PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState16"));
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState14"));
 PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState15"));


    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState12"));
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState13"));
    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));

    PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));


    while(!m_CommandQue.empty())
    {
        m_CommandQue[0]->excute();
        delete m_CommandQue[0];
        m_CommandQue.erase(m_CommandQue.begin()+0);
          m_CommandQueHistory.push_back(std::move(m_CommandQue[0]));
            m_CommandQue.erase(m_CommandQue.begin()+0);

    }


    enum
    {Push_State,Pop_State,Remove_State,Clear_State,ChangeState}
}
typedef StateManagerCmd ;

enum
{
    Create_State,register_State,GetSize_StateFactory,Select_State_Type,Save_State
} typedef StateFactoryCmd ;

m_window->SetWigdet(new GUI_Frame());

    SDL_FRect panel_HeaderRect = {((int)2),((int)2),((int)GetWindowWidth()-4),((int)GetWindowHeight())};
    GUI_Pannel *l_panel_Header = new GUI_Pannel("l_panel_Header",panel_HeaderRect,PANNEL_HEADER);

    SDL_FRect panel_GameStateRect = {(int)2,((int)GetWindowHeight() + 4),((int)GetWindowWidth()-4),((int)GetWindowHeight()-GetWindowHeight())};
    GUI_Pannel *l_panel_GameState = new GUI_Pannel("l_panel_GameState",panel_GameStateRect,PANNEL_GAMESTATE);

    GUI_Menu *File = new GUI_Menu(tempFrame,"File",0,0);
    GUI_Menu *Edit = new GUI_Menu(tempFrame,"Edit",79,0);



    Edit->Add(new GUI_Menu("Undo",new Command("Undo")));
    Edit->Add(new GUI_Menu("Redo",new Command("Redo")));

    l_panel_Header->Add(File);
    l_panel_Header->Add(Edit);

    tempFrame->Add(l_panel_GameState);
    tempFrame->Add(l_panel_Header);

PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));
PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Pop_State"));

PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","TestState13"));

PushCommand(new Cmd::GameStateMachine(m_pGameStateMachine,"Push_State","State_BlankScreen"));

PushCommand(new Command("PushState_TestState12"));

PushCommand(new Cmd::GUIFactory(m_window,"Create_GUI","GUI_Frame"));
PushCommand(new Cmd::Window(GetWindow()->GetWindow(),"FullScreen"));


    WindowCmd::FullScreen
    WindowCmd::FullScreen_Destop
    WindowCmd::Hide
    WindowCmd::Show

    TextureManagerCmd::Aplha
    TextureManagerCmd::Delete_Texture
    TextureManagerCmd::GetSize_Texture
    TextureManagerCmd::Load_Texture
    TextureManagerCmd::rgb
    TextureManagerCmd::Save_Texture
    TextureManagerCmd::Select_Texture_Type

    GameobjectFactoryCmd::Close_Gameobject
    GameobjectFactoryCmd::Create_Gameobject
    GameobjectFactoryCmd::GetSize_GameObject
    GameobjectFactoryCmd::register_Gameobject
    GameobjectFactoryCmd::Save_Gameobject
    GameobjectFactoryCmd::Select_Gameobject_Type

    c->excute();
    delete c;
    LogCommand("PushState_TestState12");

    LogCommand("CreateGUI:Frame");

/*

void Application::Log(std::string s,void (*func)())
{
    ICommand *TestCommand = new Command_Log(&m_ApplicationLogger,s);
    TestCommand->excute();
    delete TestCommand;
}
void Application::Log(std::string s)
{
       std::stringstream ss;
        ss << s;
    ICommand *TestCommand = new Command_Log(&m_ApplicationLogger,s);
    TestCommand->excute();
    delete TestCommand;
}
 SoundManager::Instance()->SetVolume(0);

    c = new Command("PushState_TestState12");
    c->excute();
    delete c;
    c = new Command("PrintModuleInfo");
    c->excute();
    delete c;
    c = new Command("State_BlankScreen");
    c->excute();

    delete c;
ChangeGameState(new TestState1());
 PushState(new TestState10());//
 textureManager->Clean();


m_window->GetWigdet()->Add(new GUI_Menu());
  m_window->GetWigdet()->Add(new GUI_Menu());
 m_window->GetWigdet()->Add(new GUI_Menu());

GUI_Wigdet * Game::GetWigdet()
{
    return m_window->GetWigdet();
}

  std::string s =  std::string{"s sss"};
    m_GameLogger->log(s);

Log(std::string{xpos});
    std::stringstream str;
    m_GameLogger = Logger();

    m_EngineFlag = Engine_Flag;
    str << RefreshRate <<"asas";
    m_GameLogger.log(str.str());

    m_frameDelay = 1000 / RefreshRate ;
    std::cout <<"m_GameLogger \n"   << *m_GameLogger.getLogs().back()<< "\n";

    m_bRunning = true;

  m_window->CreateWindow
m_render = new Render();

    if(!m_window->init(title,
                       xpos,
                       ypos,
                       width,
                       height,
                       RefreshRate,
                       ResScaler,
                       fullscreen,
                       Tile,
                       column,
                       row))

std::cout << Game::Instance()->GetStateMachine()->GetCurrentStateID() << "GetGameState\n";

void  Game::SetFrameStart(float ticks)
{
    m_framestart = ticks;
}
std::cout << e.common.timestamp << "\n";
        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_1)
        {
            std::cout << m_pGameStateMachine->GetCurrentStateID()<< "\n";
            inputText = "";
            SDL_StartTextInput();
        }
        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_BACKSPACE)
        {
            if(inputText != "")
                inputText.pop_back();
        }
        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_2)
        {
               isRenderText = true;
            isTyping = false;
            SDL_StopTextInput();
            std::cout << inputText <<"\n";
            m_GameLogger->log(inputText);
        }
        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_3)
        {
            isTextSemibold = true;
        }
        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_4)
        {
            isTextSemibold = false;
        }
        if(e.type==SDL_TEXTINPUT)
        {
            isTyping = true;
            std::cout <<"SDL_TEXTINPUT  " <<"\n";
            inputText += e.text.text;


        }
        if(e.type==SDL_TEXTEDITING)
        {
            std::cout <<"SDL_TEXTEDITING  " <<"\n";
            SDL_Rect a = {0,0,1000,1000};
            SDL_SetTextInputRect(&a);
            composition = e.edit.text;
            m_cursor = e.edit.start;
            m_selection_length = e.edit.length;

        }
        if(!isTyping)
        {

        }
  need to fix
 store the game width and height
    m_Origin = vec2f(0,0);
    m_Screen = vec2f(width,height);
    m_Centre = vec2f(m_Screen.Length()/2,m_Screen.Length()/2);

     if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
       GetStateMachine()->PopState();

       GetStateMachine()->PushState(new MenuState);
                std::cout << "pasued passed" << "\n";
    }

    SDL_SetRenderDrawColor(m_pRenderer,1,125,125,255);
 SDL_RenderClear(m_pRenderer);
 SDL_RenderPresent(m_pRenderer);
const  char* Game::GetTitle()
    {
        return m_windowTitle;
    }

    std::cout << Game::Instance()->GetTitle()  <<  "\n";

    const char* m_windowTitle;

const bool  Game::getLevelCompelte()
{

}
const bool  Game::getCurrentLevel()
{

}

bool Game::changingState()
{

    return m_bChangingState;
}

void Game::changingState(bool cs)
{
    m_bChangingState = cs;
}

SDL_Texture* RenderText(const std::string &message, const std::string &fontFlie, SDL_Color color, int fontSize, SDL_Renderer *render)
{

    TTF_Font *font = TTF_OpenFont(fontFlie.c_str(),fontSize);

    if(font==nullptr)
    {
        std::cout << " 1 error \n";
        return nullptr;
    }
    SDL_Surface *surf = TTF_RenderText_Blended(font,message.c_str(),color);
    if(surf==nullptr)
    {
        TTF_CloseFont(font);
        std::cout << " 2 error \n";
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
    if(texture==nullptr)
    {
        std::cout << " 3 error \n";
    }
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;


}




  m_windowTitle = title;

    int flags = 0;

     store the game width and height
    m_gameWidth = width;
    m_gameHeight = height;
    m_Origin = vec2f(0,0);
    m_Screen = vec2f(width,height);
    m_Centre = vec2f(m_Screen.Length()/2,m_Screen.Length()/2);

    m_pCamera = {0,0,width,height};
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

     attempt to initialise SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        TTF_Init();
        std::cout << "SDL init success\n";
         init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return true; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return true; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return true; // SDL init fail
    }


    GameObjectFactory::Instance()->registerType("GameError",new SDLGameObjectCreater());

    m_pGameStateMachine  = new GameStateMachine();
    m_pGameStateMachine->ChangeState(new MenuState());
m_bRunning = true;



   TextureManager::Instance()->Load("SpaceinvaderAssist/SpaceInvaders1.PNG","SpaceInvader",Game::GetRenderer());
 GameObjectFactory::Instance()->registerType("SpaceEnemy1",new EnemySpaceShipCreator());

 GameObjectFactory::Instance()->registerType("Eskeletor",g EskeletorCreater());

UI_Selection = NULL;

sdsd

 Map[Player][p]

Widget_TowersSelection



  GameObjectFactory::Instance()->registerType("Cell",new TowerObjectCreater());
    TextureManager::Instance()->Load("Img/Cell_ExitRed.PNG","Cell_ExitRed",Game::GetRenderer());
    TextureManager::Instance()->Load("Img/Cell_EnterGreen.PNG","Cell_EnterGreen",Game::GetRenderer());
    TextureManager::Instance()->Load("Img/GUI/Cell.PNG","Cell",Game::GetRenderer());
    TextureManager::Instance()->Load("Img/GUI/Cell1.PNG","Cell1",Game::GetRenderer());
    TextureManager::Instance()->Load("Img/GUI/Label_Decorator.PNG","Label_Decorator",Game::GetRenderer());

    GameObjectFactory::Instance()->registerType("Bonus01",new TowerObjectCreater());
    GameObjectFactory::Instance()->registerType("Bonus02",new TowerObjectCreater());
    GameObjectFactory::Instance()->registerType("Bonus03",new TowerObjectCreater());
    GameObjectFactory::Instance()->registerType("Bonus04",new TowerObjectCreater());

  m_pGameStateMachine->ChangeState(new StateLevel());
StateLevel
m_pGameStateMachine->PushState(new StateLevel());
   m_pGameStateMachine->ChangeState(new StateMapEditer());


    void AddMenu(std::string Label){}
    void AddSubMenu(std::string Label, std::string ParrentMenu){}

m_window->GetWigdet()->Add(new GUI_SubMenu("  File  ",32,32));


    tempFrame->AddMenu("  File  ",tempFrame->GetFrameRect().x,0);
    tempFrame->AddSubMenu("New","File",NULL,NULL);
    tempFrame->AddSubMenu("Open...","File",NULL,NULL);
    tempFrame->AddSubMenu("Save","File",NULL,NULL);
    tempFrame->AddSubMenu("SaveAs...","File",NULL,NULL);
    tempFrame->AddSubMenu("Properties...","File",NULL,NULL);

    tempFrame->AddMenu("  Edit  ",NULL,NULL);
    tempFrame->AddSubMenu("Undo","Edit",NULL,NULL);
    tempFrame->AddSubMenu("Redo","Edit",NULL,NULL);

    tempFrame->AddMenu(" View  ",NULL,NULL);
    tempFrame->AddSubMenu("Perspective...","View",NULL,NULL);

    tempFrame->AddMenu(" Search ",NULL,NULL);
    tempFrame->AddSubMenu("Find State ID","Search",NULL,NULL);
    tempFrame->AddSubMenu("Find Sprite ID","Search",NULL,NULL);
    tempFrame->AddSubMenu("Find TileMap ID","Search",NULL,NULL);
    tempFrame->AddSubMenu("Find GameObject ID","Search",NULL,NULL);

    tempFrame->AddMenu(" Project ",NULL,NULL);
    tempFrame->AddSubMenu("stateManager","Project",NULL,NULL);
    tempFrame->AddSubMenu("TileManager","Project",NULL,NULL);
    tempFrame->AddSubMenu("SoundManager","Project",NULL,NULL);
    tempFrame->AddSubMenu("FontManager","Project",NULL,NULL);

    tempFrame->AddMenu(" Build ",NULL,NULL);
    tempFrame->AddSubMenu("Build","Build",NULL,NULL);
    tempFrame->AddSubMenu("Compile Current File","Build",NULL,NULL);
    tempFrame->AddSubMenu("Run","Build",NULL,NULL);
    tempFrame->AddSubMenu("Build And Run","Build",NULL,NULL);
    tempFrame->AddSubMenu("ReBuild","Build",NULL,NULL);
    tempFrame->AddSubMenu("Clean","Build",NULL,NULL);



    tempFrame->Add(std::move(new GUI_Menu("File",1,0)));
    tempFrame->Add(std::move(new GUI_Menu("Edit",28,0)));
    tempFrame->Add(std::move(new GUI_Menu("View",60,0)));
    tempFrame->Add(std::move(new GUI_Menu("Search",98,0)));
    tempFrame->Add(std::move(new GUI_Menu("Project",152,0)));
    tempFrame->Add(std::move(new GUI_Menu("Build",208,0)));


 */

