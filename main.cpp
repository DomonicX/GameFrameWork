
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>

#include <Application.h>
#include <CallBack.h>
#define  resScaler 1
#include <IWidget.h>
#include <Lmaths.h>
#include <TileMapManagerWidget.h>
#include <DirectoryManagerWidget.h>
#include <GameManagerWidget.h>
#include <FileMenuManager.h>
#include <CommandLineWidget.h>



#include <WidgetFactory.h>
#include <Quad.h>

#define SsmHd       vec2f(80,45) //*24 for 1920,1080
#define smHd           vec2f(160,90) //*12 for 1920,1080
#define mHD             vec2f(320,180) //*6 for 1920,1080
#define nHD             vec2f(640,360) // *3 for 1920,1080
#define qHD             vec2f(960,540) // *2
#define HD	            vec2f(1280,720) // *1.5
#define HDplus             vec2f(1600,900) //*1.2
#define FHD	            vec2f(1920,1080)
#define WQHD            vec2f(2560,1440)
#define QHD+	        vec2f(3200,1800)
#define FourKUHD	    vec2f(3840,2160)
#define FiveK           vec2f(5120,2880)
#define EightKUHD       vec2f(7680,4320)
#define Sixteenk	    vec2f(15360,8640)

#define marioScreen vec2f(256,224)
#define PacmanScreen vec2f(256,224)
#define PacmanScreen2 vec2f(768,672)
#define PacmanScreen3 vec2f(256*4,224*4)
//


SDL_Event e;
using namespace Gui;

bool initGL();
bool InitSdl();
IWidget* CreateWindowImp();
void printLetter();
void foo();
void RestartCurrentState();
void RunGame();
void foo2();
void foo222(int argc, char* argv[])
{
    if (SDL_Init(0) == -1)
    {
        printf("SDL_Init: %s\n", SDL_GetError());
        exit(1);
    }
    if (SDLNet_Init() == -1)
    {
        printf("SDLNet_Init: %s\n", SDLNet_GetError());
        exit(2);
    }

    bool done = false;

    if (argc == 2 && strcmp(argv[1], "server") == 0)
    {
        printf("Starting server...\n");
        TCPsocket server, client;
        IPaddress ip;
        if (SDLNet_ResolveHost(&ip, NULL, 9999) == -1)
        {
            printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
            exit(1);
        }
        server = SDLNet_TCP_Open(&ip);
        if (!server)
        {
            printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
            exit(2);
        }
        while (!done)
        {
            /* try to accept a connection */
            client = SDLNet_TCP_Accept(server);
            if (!client)   /* no connection accepted */
            {
                /*printf("SDLNet_TCP_Accept: %s\n",SDLNet_GetError()); */
                SDL_Delay(100); /*sleep 1/10th of a second */
                continue;
            }

            /* get the clients IP and port number */
            IPaddress *remoteip;
            remoteip = SDLNet_TCP_GetPeerAddress(client);
            if (!remoteip)
            {
                printf("SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
                continue;
            }

            /* print out the clients IP and port number */
            Uint32 ipaddr;
            ipaddr = SDL_SwapBE32(remoteip->host);
            printf("Accepted a connection from %d.%d.%d.%d port %hu\n", ipaddr >> 24,
                   (ipaddr >> 16) & 0xff, (ipaddr >> 8) & 0xff, ipaddr & 0xff,
                   remoteip->port);

            while (1)
            {
                /* read the buffer from client */
                char message[1024];
                int len = SDLNet_TCP_Recv(client, message, 1024);
                if (!len)
                {
                    printf("SDLNet_TCP_Recv: %s\n", SDLNet_GetError());
                    break;
                }
                /* print out the message */
                printf("Received: %.*s\n", len, message);
                if (message[0] == 'q')
                {
                    printf("Disconecting on a q\n");
                    break;
                }
                if (message[0] == 'Q')
                {
                    printf("Closing server on a Q.\n");
                    done = true;
                    break;
                }
            }
            SDLNet_TCP_Close(client);
        }
    }
    else if (argc == 2 && strcmp(argv[1], "client") == 0)
    {
        printf("Starting client...\n");
        IPaddress ip;
        TCPsocket tcpsock;

        if (SDLNet_ResolveHost(&ip, "192.168.1.2", 9999) == -1)
        {
            printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
            exit(1);
        }

        tcpsock = SDLNet_TCP_Open(&ip);
        if (!tcpsock)
        {
            printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
            exit(2);
        }

        while (1)
        {
            printf("message: ");
            char message[1024];
            fgets(message, 1024, stdin);
            int len = strlen(message);

            /* strip the newline */
            message[len - 1] = '\0';

            if (len)
            {
                int result;

                /* print out the message */
                printf("Sending: %.*s\n", len, message);

                result =
                    SDLNet_TCP_Send(tcpsock, message, len); /* add 1 for the NULL */
                if (result < len)
                    printf("SDLNet_TCP_Send: %s\n", SDLNet_GetError());
            }

            if (len == 2 && tolower(message[0]) == 'q')
            {
                break;
            }
        }

        SDLNet_TCP_Close(tcpsock);
    }
    else
    {
        printf("Choose server or client\n");
    }

    SDLNet_Quit();
    SDL_Quit();
}
void CreateFileSubWidget();

IWidget* CreateWindowImp2();
IWidget* CreateWindowImp3();
IWidget* CreateWindowNa();
void ShutDownApp();
void LoadFont();
void LoadGameObjects();
void LoadSoundObjects();
void LoadStateObjects();
void LoadFiles();
void CallBackFileNewApp();

Uint32 callback( Uint32 interval, void* param );
int MyEventFunction(void *userdata, SDL_Event *event);

int MyEventFunction(void *userdata, SDL_Event *event)
{
    // Do things with userdata and event
//std::cout << (char*)event.window.type << "\n";
    printf("%i \n ", event->type);
    printf( "Callback called back with message: %s\n  %i \n", reinterpret_cast<char*>(userdata));
    return 0; // Value will be ignored
}
Uint32 callback( Uint32 interval, void* param )
{
    if(param==NULL)
    {

    }

    //APP->GetWindow()->SetMinimizeWindow();
    //Print callback message
    printf( "Callback called back with message: %s\n  %i \n", reinterpret_cast<char*>(param));

    return 0;
}
// ...
int main(int argc, char* argv[])
{

//    Quad center(Point(0, 0), Point(8, 8));
//    Node a(Point(1, 1), 1);
//    Node b(Point(2, 5), 2);
//    Node c(Point(7, 6), 3);
//    center.insert(&a);
//    center.insert(&b);
//    center.insert(&c);
//    cout << "Node a: " << center.search(Point(2, 2))->data
//         << "\n";
//    cout << "Node b: " << center.search(Point(2, 5))->data
//         << "\n";
//    cout << "Node c: " << center.search(Point(7, 6))->data
//         << "\n";
//    cout << "Non-existing node: "
//         << center.search(Point(5, 5));
    /**<


         game loop
        //////////
        Movement
        Harvest
        Grab
        Craft
        Attack
        Talk
        Shop
        //////////
              game Objects
        //////////
        Player
        NPC
        Enemy
        Items
        Resources
        //////////

vec2f spacing
vec2f margin
vec2f numberOfCells;
vec2f Size;

 std::map<std::pair<int,int>,std::string>GameMap;

    GameMap[ {3,3}] = "hello";
    GameMap[ {3,0}] = "world";
    std::string hello = GameMap[ {3,9}] ;
    std::string s = GameMap[ {3,0}] ;

    std::cout << hello << "world\n";
    std::cout << s << "world\n";

    // initGL();
    //init();
    //glewInit();
    vec2f b3 = vec2f(255,0);
    vec2f a3 = vec2f();

    vec2f c3 = vec2f::Lerp(vec2f(),b3,1/(float)640);

    while (a3.Length() < b3.Length())
    {
    a3+=c3;
    //        std::cout << a3 << "\n";
    }
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Lanuching App"); */
    //SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
//
// SDL_LogError(SDL_LOG_CATEGORY_ERROR,"App Initializing");

//thses cant be placed after app init need to fixed
 do {
            if(!InitSdl())
    {
        return 0;
    }
    SDL_LogSetAllPriority( SDL_LOG_PRIORITY_WARN );
    SDL_Log("SDL Initializing");
//
//     ? SDL_LogError(SDL_LOG_CATEGORY_ERROR,"Error.. InitSDL")  :  SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"Init SDL.. Done\n");
//

       srand (time(NULL));
    SDL_Log("Loading Assets");
    LoadFiles();
    LoadFont();
    LoadStateObjects();
 //   LoadSoundObjects();
    LoadGameObjects();
argv[1] = "client";
argc = 2;
   // foo222(argc,argv);
// "State_Logo_Screen"TestState30
// TestState31 State_Logo_Screen TestState32 TestState33 TestState34 TestState35 TestState36 TestState37
    if(!APP->Init("GameEngine",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,360,SDL_WINDOW_HIDDEN, "TestState37",CreateWindowNa()))
    {}
    SDL_TimerID timerID = SDL_AddTimer( 3 * 1000, callback,  (char*)"3 seconds waited!"  );
    SDL_RemoveTimer( timerID );
    TCPsocket sd, csd; /* Socket descriptor, Client socket descriptor */ IPaddress ip, *remoteIP;
    int quit, quit2;
    char buffer[512];

    if(SDLNet_ResolveHost(&ip, NULL, 8099) == -1)
    {
        fprintf(stderr, "ER: SDLNet_ResolveHost: %sn", SDLNet_GetError());
        exit(-1);
    }

    SDL_AddEventWatch(MyEventFunction,  (char*)"SDL_AddEventWatch\n"  );
    SDL_DelEventWatch(MyEventFunction,  (char*)"SDL_AddEventWatch\n"  );

    {
//     SDL_RendererInfo
        int MAX = 5;
        vec2f buff[MAX];                            // buffer for integers


        for(int i=0; i<MAX; i++)
            buff[i] = vec2f(i-1,i*i-i );                           // put some data into the buffer

        std::ofstream os("Config.File", std::ios::binary);  // create output stream os

        os.write((char*)buff, MAX*sizeof(vec2f));   // write to it

        os.close();                               // must close it before opening another
        // stream associated with the same file
        for(int i=0; i<MAX; i++)
            buff[i] = vec2f(i,i);
        // clear buffer

        std::ifstream is("Config.File", std::ios::binary);  // create input stream is
        is.read((char*)buff, MAX*sizeof(vec2f));    // read from it

        for(int i=0; i<MAX; i++)
            std::cout << buff[i] << " s" <<std::endl;               // display it
        is.close();
    }


    TextureManager::Instance()->Load("Img/GUI_TileSheet.png","GUI_TileSheet",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Shapes.png","Shapes",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Tile_Floor_Wood.png","Tile_Floor_Wood",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/BackGround_256.png","BackGround_256",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/1.png","Tile_wood",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/2.png","Tile_wood_Mask",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/3.png","Tile_wood_Mask2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/4.png","Tile_wood_Mask3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/circle2.png","circle2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur3.png","blur3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Background.png","Background",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/background1.png","background1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/level1_BackGround.png","level1_BackGround",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur4.png","blur4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur5.png","blur5",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/spriteSheet01.png","Sheet01",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/bush.png","bush",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree.png","tree",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree1.png","tree1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree2.png","tree2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree3.png","tree3",Colour_white,APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree4.png","tree4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Rock.png","Rock",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/char.png","char",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/cannon.png","cannon",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/backgroundS.png","backgroundS",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/rocks.png","rocks",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/walking1.png","walking1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/compass.png","compass",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/par_effect.png","par_effect",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/TS.png","TS",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/TS_ALPHA.png","TS_ALPHA",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/32x32.png","32x32",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blank.png","blank",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blank2.png","blank2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blank3.png","blank3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Block.png","Block",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/circle.png","circle",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/circle2.png","circle2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Block1.png","Block1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/BallBouncing.png","BallBouncing",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/swirl.png","swirl",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/pushingStickman.png","pushingStickman",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/pushingStickman2.png","pushingStickman2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/pushingStickman3.png","pushingStickman3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/pushingStickman4.png","pushingStickman4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/pushingStickman1.png","pushingStickman1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tile2.png","tile2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/PacmanWall.png","PacmanWall",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/PacManBackGround.png","PacManBackGround",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Pac-Man.png","Pac-Man",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tile3.png","tile3",APP->GetRenderer());





 if(DirectoryHandler::Instance()->Load("AppConfig.txt"))
    {

    LFile * ss = DirectoryHandler::Instance()->GetFileMap()["AppConfig.txt"];
     ss->ChangeData(Application::Instance()->m_AppInfoStr.str());

    DirectoryHandler::Instance()->Save("AppConfig.txt");
// ss->GetFileData().resize(10);
    std::cout <<   ss->GetFileData()<< "\n";

    }else {
                    SDL_ShowSimpleMessageBox(0,"Error no config","OK",APP->GetWindow()->GetWindow());
    std::cout <<   "bad bit" << "\n";}

    while (APP->running())
    {}
    std::cout << Application::Instance()->GetEngineflag() <<"\n";
    Application::Instance()->Clean();
    SDL_Delay(1000);
}
 while(Application::Instance()->m_AppEditorFlag ==_RESTART_);
    return 0;
}
void LoadFiles()
{
    DirectoryHandler::Instance()->SetFileBase();
}
void LoadFont()
{
    fontManager->LoadFont("Fonts/OpenSans/OpenSans-Regular.TTF","OpenSans-Regular");
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-Regular.TTF","Sans");

    fontManager->LoadFont("Fonts/Consolas-Font/CONSOLA.TTF","CONSOLA");
    fontManager->LoadFont("Fonts/Consolas-Font/CONSOLAB.TTF","CONSOLAB");
    fontManager->LoadFont("Fonts/Consolas-Font/consolai.TTF","consolai");
    fontManager->LoadFont("Fonts/Consolas-Font/Consolas.TTF","Consolas");
    fontManager->LoadFont("Fonts/Consolas-Font/consolaz.TTF","consolaz");
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-Italic.TTF","OpenSans-Italic",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-LightItalic.TTF","OpenSans-LightItalic",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-Light.TTF","OpenSans-Light",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-Bold.TTF","OpenSans-Bold",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-BoldItalic.TTF","OpenSans-BoldItalic",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-Semibold.TTF","OpenSans-Semibold",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-SemiboldItalic.TTF","OpenSans-SemiboldItalic",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-ExtraBold.TTF","OpenSans-ExtraBold",16);
//    fontManager->LoadFont("Fonts/OpenSans/OpenSans-ExtraBoldItalic.TTF","OpenSans-ExtraBoldItalic",16);
}
void LoadGameObjects()
{
    GameObjectFactory::Instance()->registerType("GameObjectProxy",new GameObjectProxyCreater());
    GameObjectFactory::Instance()->registerType("TextObject",new TextObjectCreater());
    GameObjectFactory::Instance()->registerType("BreakOut_Ball",new GameObject_BallCreater());
//    GameObjectFactory::Instance()->registerType("BreakOut_Block",new CreateGameObject_Block());
    GameObjectFactory::Instance()->registerType("BreakOut_Paddle",new CreateGameObject_Paddle());
    GameObjectFactory::Instance()->registerType("GameObject_PacMan",new GameObject_PacManCreater());
    GameObjectFactory::Instance()->registerType("GameObject_PacManTile",new GameObject_PacManTileCreater());
    GameObjectFactory::Instance()->registerType("GameObject_Ghost",new GameObject_GhostCreater());
    GameObjectFactory::Instance()->registerType("GameOBject_RocketShip",new GameOBject_RocketShipCreater());
    GameObjectFactory::Instance()->registerType("GameObjectTree",new GameObject_TreeCreater());
    GameObjectFactory::Instance()->registerType("GameObject_Player",new GameObject_PlayerCreater());
    GameObjectFactory::Instance()->registerType("GameObject_Tile",new GameObject_TileCreater());
    GameObjectFactory::Instance()->registerType("GameObject_PacmanWall",new GameObject_PacmanWallCreater());


//   GameObjectFactory::Instance()->registerType("SDLGameObject",new SDLGameObjectCreater());
}
void LoadSoundObjects()
{
    SoundManager::Instance()->Load("MP3/Cymatic Empire - Bornvibe.MP3","Cymatic_Empire");
    SoundManager::Instance()->Load("MP3/Sfx_BreakOut_WallHit.WAV","Sfx_BreakOut_WallHit");
    SoundManager::Instance()->Load("MP3/Sfx_BreakOut_WallHitTop.WAV","Sfx_BreakOut_WallHitTop");
    SoundManager::Instance()->Load("MP3/pacman/pacman_beginning.WAV","pacman_beginning");
    SoundManager::Instance()->Load("MP3/pacman/pacman_death.WAV","pacman_death");
    SoundManager::Instance()->Load("MP3/pacman/pacman_chomp.WAV","pacman_chomp");
    SoundManager::Instance()->Load("MP3/pacman/pacman_eatfruit.WAV","pacman_eatfruit");
    SoundManager::Instance()->Load("MP3/pacman/pacman_eatghost.WAV","pacman_eatghost");
    SoundManager::Instance()->Load("MP3/pacman/pacman_extrapac.WAV","pacman_extrapac");
    SoundManager::Instance()->Load("MP3/pacman/pacman_intermission.WAV","pacman_intermission");
    std::cout << "Finished loading data in Blank screen:On Enter \n";
}
void LoadStateObjects()
{
    StateFactory::Instance()->registerType("TestState",new TestStateCreater());
    StateFactory::Instance()->registerType("TestState32",new TestState32Creater());
    StateFactory::Instance()->registerType("TestState33",new TestState33Creater());
    StateFactory::Instance()->registerType("TestState34",new TestState34Creater());
    StateFactory::Instance()->registerType("TestState35",new TestState35Creater());
    StateFactory::Instance()->registerType("TestState36",new TestState36Creater());
    StateFactory::Instance()->registerType("TestState37",new TestState37Creater());
    StateFactory::Instance()->registerType("State_MainMenu_Settings",new State_MainMenu_SettingsCreater());
    StateFactory::Instance()->registerType("State_Logo_Screen",new State_Logo_ScreenCreater());

}
void printLetter()
{
    std::cout << "jjjjjjjjjjjjjjjjjjjjfoo\n";
//    std::string s = i;
}
void foo()
{
    Application::Instance()->Instance()->GetWindow()->closePopUp();
    //  foo2();
    // Application::Instance()->cmdStateMachine("Push_State","State_Pacman_Ready");
//Application::Instance()->GetWindow()->GetWidget()->GetChild(1).SetVisable(false);
}
void foo2()
{
    std::cout <<    Application::Instance()->GetWindow()->GetWidget()->GetChild(0).GetChild(0).GetChild(0).GetChildSize()<<"\n";
    std::cout <<    Application::Instance()->GetWindow()->GetWidget()->GetChild(0).GetChild(0).GetChild(0).GetTitle()<<"\n";

    int siz =            Application::Instance()->GetWindow()->GetWidget()->GetChild(0).GetChild(0).GetChildSize();
    Menu *b = new Menu();

    b->Init(APP->GetStateMachine()->GetCurrentStateID(),
    {
        Application::Instance()->GetWindow()->GetWidget()->GetChild(0).GetChild(0).GetHitBox().x +

        Application::Instance()->GetWindow()->GetWidget()->GetChild(0).GetChild(0).GetHitBox().w,(int)InputHandler::Instance()->GetMousePosition().y,64,64
    });
//       b->SetVisable(false);
    Application::Instance()->GetWindow()->GetWidget()->GetChild(0).GetChild(0).Add(b);
//  Application::Instance()->cmdStateMachine("Pop_State","");
    //  Application::Instance()->GetWindow()->GetWidget()->GetChild(1).SetVisable(false);

}
void RunGame()
{
    Application::Instance()->GetWindow()->GetWidget()->GetChild(0).SetVisable(false);

    Application::Instance()->GetWindow()->GetWidget()->GetChild(1).SetVisable(false);
    Application::Instance()->GetWindow()->GetWidget()->GetChild(2).SetVisable(false);

    SoundManager::Instance()->SetPlay("pacman_eatfruit");
    int MenubarSize = FontManager::Instance()->GetFontSize("OpenSans-Regular");
    SDL_Rect Rect_window = WindowRect;
    SDL_Rect Rect_MenuBar = {0,0,Rect_window.w, MenubarSize};
    SDL_Rect Rect_Frame = {0,MenubarSize,WindowRect.w, WindowRect.h-MenubarSize};
    float t = WindowRect.w/640.0f;
    APP->GetCamera() = Camera(vec2f(0,MenubarSize),vec2f(640, 360),(t));

//   SDL_Rect m_viewport =  APP->GetCamera().GetRect();
//SDL_RenderIsClipEnabled(App->GetRenderer());
//SDL_RenderSetIntegerScale(App->GetRenderer(),SDL_TRUE);
//
//  SDL_RenderSetLogicalSize(App->GetRenderer(),m_viewport.w,m_viewport.h);
////SDL_RenderSetClipRect(App->GetRenderer(),&m_viewport);
//   SDL_RenderSetScale(App->GetRenderer(),1,1);

}
void foo3()
{
    Application::Instance()->GetStateMachine()->PopState();
//    Application::Instance()->cmdStateMachine("Pop_State","");
    Application::Instance()->GetWindow()->GetWidget()->SetVisable(false);

//   Application::Instance()->cmdStateMachine("Push_State","TestState23");

}
void RestartCurrentState()
{
    std::string currentStateId =  Application::Instance()->GetStateMachine()->GetCurrentStateID();
    Application::Instance()->GetStateMachine()->PopState();
    Application::Instance()->GetStateMachine()->PushState(StateFactory::Instance()->Create(currentStateId));

}
bool InitSdl()
{

//        if(TTF_WasInit())
    if(!SDL_Init(SDL_INIT_EVERYTHING))
        if(!SDL_Init(TTF_Init()))
            if(!SDLNet_Init())
           //    if(!SoundManager::Instance()->Init(   MIX_INIT_FLAC   |MIX_INIT_MOD  |MIX_INIT_MP3  |MIX_INIT_OGG  |MIX_INIT_OPUS))
                    if(!IMG_Init(IMG_INIT_PNG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP))
                        return false;
    return true;
}
//
//    StateFactory::Instance()->registerType("TestState1",new TestState1Creater());
//    StateFactory::Instance()->registerType("TestState2",new TestState2Creater());
//    StateFactory::Instance()->registerType("TestState3",new TestState3Creater());
//    StateFactory::Instance()->registerType("TestState4",new TestState4Creater());
//    StateFactory::Instance()->registerType("TestState5",new TestState5Creater());
//
//    StateFactory::Instance()->registerType("TestState6",new TestState6Creater());
//
//
//    StateFactory::Instance()->registerType("TestState10",new TestState10Creater());
//    StateFactory::Instance()->registerType("TestState12",new TestState12Creater());
//    StateFactory::Instance()->registerType("TestState13",new TestState13Creater());
//    StateFactory::Instance()->registerType("TestState14",new TestState14Creater());
//    StateFactory::Instance()->registerType("TestState15",new TestState15Creater());
    // StateFactory::Instance()->registerType("TestState16",new TestState16Creater());
//    StateFactory::Instance()->registerType("TestState11",new TestState11Creater());
//    StateFactory::Instance()->registerType("TestState17",new TestState17Creater());
//    StateFactory::Instance()->registerType("TestState18",new TestState18Creater());
//    StateFactory::Instance()->registerType("TestState20",new TestState20Creater());
//    StateFactory::Instance()->registerType("TestState21",new TestState21Creater());
//    StateFactory::Instance()->registerType("TestState22",new TestState22Creater());
//    StateFactory::Instance()->registerType("TestState23",new TestState23Creater());
//    StateFactory::Instance()->registerType("TestState24",new TestState24Creater());
//    StateFactory::Instance()->registerType("TestState25",new TestState25Creater());
//    StateFactory::Instance()->registerType("TestState26",new TestState26Creater());
//    StateFactory::Instance()->registerType("TestState27",new TestState27Creater());
//    StateFactory::Instance()->registerType("TestState28",new TestState28Creater());
//    StateFactory::Instance()->registerType("TestState29",new TestState29Creater());

//    StateFactory::Instance()->registerType("State_Template",new State_TemplateCreater());
//    StateFactory::Instance()->registerType("State_BreakOutGame",new State_BreakOutGameCreater());


    //  StateFactory::Instance()->registerType("State_Frame_GUI",new State_Frame_GUICreater());
    // StateFactory::Instance()->registerType("State_SimpleDialogBox",new State_SimpleDialogBoxCreater());
//    StateFactory::Instance()->registerType("TestStateUnitTestPannel",new TestStateUnitTestPannelCreater());
//    StateFactory::Instance()->registerType("State_GameEngine_EmptyProject",new State_GameEngine_EmptyProjectCreater());
//    StateFactory::Instance()->registerType("State_GameEngine_File_New",new State_GameEngine_File_NewCreater());
//    StateFactory::Instance()->registerType("State_GameEngine_File_Load",new State_GameEngine_File_LoadCreater());
//    StateFactory::Instance()- >registerType("State_BlankScreen",new State_BlankScreenCreater());

//
//    StateFactory::Instance()->registerType("State_Pacman_Ready",new State_Pacman_ReadyCreater());
//    StateFactory::Instance()->registerType("State_GameMenu",new State_GameMenuCreater());
//    StateFactory::Instance()->registerType("TestState19",new TestState19Creater());
//    StateFactory::Instance()->registerType("State_PacMan",new State_PacManCreater());
//    StateFactory::Instance()->registerType("StateSnakeGame",new StateSnakeGameCreater());
//    StateFactory::Instance()->registerType("TestState30",new TestState30Creater());
//    StateFactory::Instance()->registerType("TestState31",new TestState31Creater());
//bool initGL()
//{
//    //Initialize Projection Matrix
//    glMatrixMode( GL_PROJECTION );
//    glLoadIdentity();
//
//    //Initialize Modelview Matrix
//    glMatrixMode( GL_MODELVIEW );
//    glLoadIdentity();
//
//    //Initialize clear color
//    glClearColor( 0.f, 0.f, 0.f, 1.f );
//
//    //Check for error
//    GLenum error = glGetError();
//    if( error != GL_NO_ERROR )
//    {
//        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
//        return false;
//    }
//
//    return true;
//}
//
//bool initGL()
//{
//    //Initialize Projection Matrix
//    glMatrixMode( GL_PROJECTION );
//    glLoadIdentity();
//
//    //Initialize Modelview Matrix
//    glMatrixMode( GL_MODELVIEW );
//    glLoadIdentity();
//
//    //Initialize clear color
//    glClearColor( 0.f, 0.f, 0.f, 1.f );
//
//    //Check for error
//    GLenum error = glGetError();
//    if( error != GL_NO_ERROR )
//    {
//        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
//        return false;
//    }
//
//    return true;
//}



IWidget* CreateWindowImp2()
{
    int MenubarSize = FontManager::Instance()->GetFontSize("OpenSans-Regular");
    SDL_Rect Rect_window = {0,0,nHD.x,nHD.y};


    APP->GetCamera() = Camera(vec2f(0,0),nHD/2,1);


    IWidget* m_WidowImp = WIDGETFACTORY->Create("WindowImp");
    IWidget* m_WidowFrame = WIDGETFACTORY->Create("Frame");

    IWidget *m_Hscrollbar = WIDGETFACTORY->Create("Hscrollbar");
    IWidget *m_Vscrollbar = WIDGETFACTORY->Create("Vscrollbar");
    m_WidowImp->Init("Window",Rect_window);

    m_WidowFrame->Init("Frame",APP->GetCamera().GetRect());

    m_Hscrollbar->Init("hscrollbar", {0,m_WidowFrame->GetHitBox().h-16,m_WidowFrame->GetHitBox().w-16,16});
    m_Vscrollbar->Init("vscrollbar", {m_WidowFrame->GetHitBox().w-16,m_WidowFrame->GetHitBox().y,16,m_WidowFrame->GetHitBox().h-16});
//std::cout <<"GetScrolledValue"<< static_cast<Hscrollbar*>(m_Hscrollbar)->GetScrolledValue() << "\n";
//  m_Hscrollbar->SetPosition(vec2f(0,16));
//  m_Hscrollbar->SetSize(vec2f(90,16));

//  m_Vscrollbar->SetPosition(vec2f(16,0));
//  m_Vscrollbar->SetSize(vec2f(16,90));
//m_Vscrollbar->SetPosition(vec2f(0,90));
//m_Hscrollbar->SetPosition(vec2f(20,20));

//    auto *a = m_WidowImp->Find("Window");

    m_WidowImp->Add(m_WidowFrame);
    m_WidowFrame->Add(m_Hscrollbar);
    m_WidowFrame->Add(m_Vscrollbar);

//    std::cout << a->GetTitle() << "\n";
//    std::cout << a->Type() << "\n";
    std::cout << m_Hscrollbar->GetHitBox().x << " x" <<
              m_Hscrollbar->GetHitBox().y<< " y"<< "\n";
    std::cout << m_Vscrollbar->GetSize() << "\n";
    return m_WidowImp;


}
IWidget* CreateWindowImp3()
{
    SDL_Rect Rect_window = {0,0,qHD.x,qHD.y};

    IWidget* m_WidowImp = WIDGETFACTORY->Create("WindowImp","WindowImp", {48*2,48*2,48,48});
    IWidget* m_GameManager = new GameManagerWidget();

//    IWidget *m_Panel = new Panel();

    FontManager::Instance()->SetSize("OpenSans-Regular",10);
    int MenubarSize = FontManager::Instance()->GetFontSize("OpenSans-Regular");
    DirectoryManagerWidget* m_directoryManagerWidget = new DirectoryManagerWidget();
    TileMapManagerWidget* m_tileMapManagerWidget = new TileMapManagerWidget();
    FileMenuManager * m_FileMenuManager = new FileMenuManager();
    CommandLineWidget * m_CommandLineWidget= new CommandLineWidget();

    Gui::TabList *m_TabList = new TabList();
    Gui::Tab   *m_Tab = new Tab();

//std::string sss = Application::Instance()->GetFileAsset() + "TileMapManager.txt";
//    m_Frame->Add(m_directoryManagerWidget);// m_Frame->Add(m_PanelLeft);
//    m_Frame->Add(m_tileMapManagerWidget);  // m_Frame->Add(m_PanelRight);
    int tabh = 30;
    int camW = 640;
    int camH = 360;
    m_TabList->Init("TabList",SDL_Rect({Rect_window.x,16,Rect_window.w,24}));
    m_Tab->SetPadding(0,0,0,0);
    m_Tab->SetFocus(true);

    m_Tab->Init("Scene1",SDL_Rect({8,32,48,24}));
    m_WidowImp->Init("Window",Rect_window);
    m_FileMenuManager->Init("FileMenuManager",SDL_Rect({0,0,Rect_window.w,MenubarSize}));

    m_GameManager->Init("GameManager",SDL_Rect({8,32+m_TabList->GetHitBox().h+m_TabList->GetHitBox().y-1,camW+8,camH+16}));

    m_CommandLineWidget->Init("CommandLine",SDL_Rect({0,m_GameManager->GetHitBox().y+m_GameManager->GetHitBox().h,camW+16,110}));

    m_tileMapManagerWidget->Init("TileMapManager",SDL_Rect({camW+192+16,MenubarSize+32,Rect_window.w-(camW+192)-16,camH}));
    m_directoryManagerWidget->Init("DirectoryManager",SDL_Rect({camW+16,camH+MenubarSize+32,Rect_window.w-camW-16,Rect_window.h-(camH+MenubarSize+32)}));

//   m_OutputLogWidget->Load("txt");
    m_FileMenuManager->Load("txt");
    m_directoryManagerWidget->Load("txt");
    m_tileMapManagerWidget->Load("txt");
    m_GameManager->Load("txt");
    m_CommandLineWidget->Load("txt");
//    IWidget *m_Label = new Label();
//    m_Panel->Init("GameManagerPanel",m_GameManager->GetHitBox());
//       m_TabList->Init("TabList",SDL_Rect({0,0,192,16}));

    m_WidowImp->Add(m_CommandLineWidget);
    m_WidowImp->Add(m_directoryManagerWidget);
    m_WidowImp->Add(m_tileMapManagerWidget);
    m_WidowImp-> Add(m_TabList);
    m_TabList->Add(m_Tab);
    m_TabList->Add(WIDGETFACTORY->Create("Tab","a",SDL_Rect({m_TabList->GetHitBox().x+78,m_TabList->GetHitBox().y,48,24})));
    m_WidowImp->Add(m_FileMenuManager);
//m_WidowImp->Add(    WIDGETFACTORY->Create("Panel","GameManagerPanel",SDL_Rect({0,m_GameManager->GetHitBox().y,m_WidowImp->GetHitBox().w,m_WidowImp->GetHitBox().h-m_GameManager->GetHitBox().y})));


    m_WidowImp->Add(m_GameManager);
//    m_GameManager->Add(m_Panel);


//    Application::Instance()->GetCamera().SetPos(vec2f(m_GameManager->GetHitBox().x,m_GameManager->GetHitBox().y));
    Application::Instance()->GetCamera().SetPos(vec2f(m_GameManager->GetHitBox().x+8,m_GameManager->GetHitBox().y+8));
    Application::Instance()->GetCamera().SetSize(vec2f(camW,camH));
    Application::Instance()->GetCamera().SetVirtualPos(vec2f(0,0));
    Application::Instance()->GetCamera().SetVirtualSize(vec2f(qHD.x/2,qHD.y/2));

    return m_WidowImp;
}

IWidget* CreateWindowNa()
{
    Application::Instance()->GetCamera().SetPos(vec2f(0,0 ));
    Application::Instance()->GetCamera().SetSize(nHD);
    Application::Instance()->GetCamera().SetVirtualPos(vec2f(0,0));
    Application::Instance()->GetCamera().SetVirtualSize(vec2f(640,360));

    SDL_Rect Rect_window = {0,0,nHD.x,nHD.y};

    IWidget* m_WidowImp = WIDGETFACTORY->Create("WindowImp","WindowImp", {0,0,640,360});
//   m_WidowImp-> Add(    WIDGETFACTORY->Create("Panel","TestPanel"));
//   m_WidowImp->Find("TestPanel")->SetPadding(-64,-64,-64,-64);
//   m_WidowImp->Find("TestPanel")->SetHitBox(Rect_window);
//   m_WidowImp->Find("TestPanel")->SetFilled(true);
    return m_WidowImp;
}
IWidget* CreateWindowImp()
{
    DirectoryManagerWidget* m_directoryManagerWidget = new DirectoryManagerWidget();
    TileMapManagerWidget* m_tileMapManagerWidget = new TileMapManagerWidget();
    WindowImp*  m_WindowImp = new WindowImp();
    MenuBar* m_MenuBar =  new  MenuBar();
    Menu *File = new Menu();
    Menu *Edit = new Menu();
    Menu *View = new Menu();
    Menu *Search = new Menu();
    Frame *m_Frame =  new Frame();
    Panel *m_Panel  = new Panel ();
    Panel *m_PanelTop  = new Panel ();
    Panel *m_PanelLeft  = new Panel ();
    Panel *m_PanelRight  = new Panel ();
    Panel *m_PanelBottom  = new Panel ();
    Button *Button1 = new Button();
    Button *Button2 = new Button();
    TabList *m_tablist = new TabList();
    Tab *m_tab = new Tab();
    Tab *m_tab2 = new Tab();




//     IWidget *sdsd = WIDGETFACTORY->Create("TextEdit");
    int MenubarSize = FontManager::Instance()->GetFontSize("OpenSans-Regular");
    int tabSize = 32;
//    SDL_Rect Rect_window = {0,0,HD.x,HD.y+MenubarSize};
    SDL_Rect Rect_window = {0,0,HDplus.x,HDplus.y+MenubarSize};
    SDL_Rect Rect_MenuBar = {0,0,Rect_window.w, MenubarSize};
    SDL_Rect Rect_tabist = {0,Rect_MenuBar.h+Rect_MenuBar.y,Rect_window.w, tabSize};
    SDL_Rect Rect_Frame = {0,MenubarSize+tabSize,Rect_window.w, Rect_window.h-(MenubarSize+tabSize)};

    SDL_Rect Rect_panel = {Rect_window.x+Rect_window.w/2-640/2,Rect_window.y+Rect_window.h/2-360/2,640,360};



    APP->GetCamera() = Camera(vec2f(Rect_panel.x,Rect_panel.y),vec2f(Rect_panel.w,Rect_panel.h),1);


    m_Panel->Init("Panel",Rect_panel);
    m_PanelTop->Init("PanelTop", {Rect_Frame.x,Rect_Frame.y,Rect_Frame.w,Rect_panel.y-Rect_Frame.y});
    m_PanelLeft->Init("PanelLeft", {Rect_Frame.x,Rect_panel.y,Rect_panel.x, Rect_panel.h});
    m_PanelRight->Init("PanelRight", {Rect_panel.w+Rect_panel.x,Rect_panel.y,Rect_Frame.w- (Rect_panel.w+Rect_panel.x),Rect_panel.h});
    m_PanelBottom->Init("PanelBottom", {Rect_Frame.x,m_Panel->GetHitBox().h+m_Panel->GetHitBox().y,Rect_Frame.w,(Rect_Frame.y+Rect_Frame.h)-(m_Panel->GetHitBox().h+m_Panel->GetHitBox().y)});

    m_directoryManagerWidget->Init("DirectoryManager",m_PanelLeft->GetHitBox());
    m_tileMapManagerWidget->Init("TileMapManagerWidget",m_PanelRight->GetHitBox());
//std::string sss = Application::Instance()->GetFileAsset() + "TileMapManager.txt";
    m_tileMapManagerWidget->Load("TileMapManager.txt");

    m_directoryManagerWidget->Load("DirectoryManager.txt");

    File->Init("File", {0,0,0,0});
    File->SetPadding(16,0,16,0);
    Edit->Init("Edit");
    Edit->SetPadding(16,0,16,0);
    View->Init("View");
    View->SetPadding(16,0,16,0);
    Search->Init("Search");
    Search->SetPadding(16,0,16,0);


    m_tab2->SetPadding(16,0,16,0);


    m_WindowImp->Init("Window",Rect_window);


    m_MenuBar->Init("MenuBar",Rect_MenuBar);
    m_MenuBar->SetPadding(16,0,16,0);


    m_Frame->Init("Frame",Rect_Frame);
    m_tablist->Init("tablist",Rect_tabist, {0,0,0,0});

    m_tab->Init("Hello", {m_tablist->GetHitBox().x+8,m_tablist->GetHitBox().y,32,32});
    m_tab->SetPadding(8,4,8,0);

    m_tab2->Init("world", {m_tablist->GetHitBox ().x+m_tab->GetHitBox().w+m_tab->GetHitBox().x+21,m_tablist->GetHitBox().y,32,32});
    m_tab2->SetPadding(8,4,8,0);

    Button1->Init("Run",SDL_Rect({m_PanelBottom->GetContextRect().x+64,m_PanelBottom->GetContextRect().y,0,0}));
    Button2->Init("Restart State",SDL_Rect({m_PanelBottom->GetContextRect().x+Button1->GetHitBox().w+Button1->GetHitBox().x+16+64,m_PanelBottom->GetContextRect().y,0,0}));
    File->OnAction( new StaticCallBack(CreateFileSubWidget));
//    File_new->OnAction( new StaticCallBack(RunGame));
//    File_Quit->OnAction( new StaticCallBack(ShutDownApp));
    Button1->OnAction( new StaticCallBack(RunGame));
    Button2->OnAction( new StaticCallBack(RestartCurrentState));

    m_Panel->SetVisable(false);
//
//|--Window
//   '--MenuBar
//   |  '--menu
//   |     '--submenu
//   |--Frame
//      '--Pannel
    m_WindowImp->Add(m_Frame);
    m_WindowImp->Add(m_tablist);
    m_WindowImp->Add(m_MenuBar);

    m_MenuBar->Add(File);
    m_MenuBar->Add(Edit);
    m_MenuBar->Add(View);
    m_MenuBar->Add(Search);

    m_Frame->Add(m_PanelTop);
//    m_Frame->Add(m_Panel);
    m_Frame->Add(m_directoryManagerWidget);// m_Frame->Add(m_PanelLeft);
    m_Frame->Add(m_tileMapManagerWidget);  // m_Frame->Add(m_PanelRight);

// m_PanelTop->Add(Button1);
    m_Frame->Add(m_PanelBottom);
    m_PanelBottom->Add(Button1);
    m_PanelBottom->Add(Button2);

    m_tablist->Add(m_tab);
    m_tablist->Add(m_tab2);

//m_tablist->setFoucsTab(m_tab->GetTitle());

    m_WindowImp->Find("File")->SetVisable(true);
    return m_WindowImp;
}
void CreateFileSubWidget()
{
    int i = 0;
    while(Application::Instance()->GetWindow()->GetWidget()->Find("File")->GetChildSize()!=0)
    {

        delete &Application::Instance()->GetWindow()->GetWidget()->Find("File")->GetChild(i);

        i=+1;
    }
    Menu *File_new = new Menu();
    Menu *File_Open = new Menu();
    Menu *File_Save = new Menu();

    File_new->Init("New", {0,Application::Instance()->GetWindow()->GetWidget()->Find("File")->GetHitBox().y+Application::Instance()->GetWindow()->GetWidget()->Find("File")->GetHitBox().h,0,0});
    File_new->OnAction( new StaticCallBack(RunGame));
    File_new->SetPadding(16,0,16,0);

    File_Open->Init("Open", {0,File_new->GetPosition().y+File_new->GetSize().y,0,0});
    File_Open->SetPadding(16,0,16,0);
    File_Open->OnAction( new StaticCallBack(CallBackFileNewApp));
    File_Save->Init("Save", {0,File_Open->GetPosition().y+File_Open->GetSize().y,0,0});
    File_Save->SetPadding(16,0,16,0);
    File_Save->OnAction( new StaticCallBack(CallBackFileNewApp));
//m_WindowImp->Find("File")->SetVisable(true);


    Application::Instance()->GetWindow()->GetWidget()->Find("File")->Add(File_new);
    Application::Instance()->GetWindow()->GetWidget()->Find("File")->Add(File_Open);
    Application::Instance()->GetWindow()->GetWidget()->Find("File")->Add(File_Save);
}
void ShutDownApp()
{
    APP->quit();
}
void CallBackFileNewApp()
{
//SDL_LogMessage(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR,SDL_LogPriority::SDL_LOG_PRIORITY_ERROR,"CAllBackFileNewApp");
    WindowImp *WindowImpt = new WindowImp();
    Frame* framet = new Frame();
    Panel* Panelt = new Panel();
    Button *Close  = new Button();


    WindowImpt->Init("Window1",WindowRect);
    framet->Init("frame1");
    Panelt->Init("Panel1", {WindowRect.w/3,WindowRect.h/3,256*2,256});
    Close->Init("Close1", {WindowRect.w/2,WindowRect.h/2,200,200});
    Close->OnAction( new StaticCallBack(foo));
    Close->SetPadding(16,0,16,0);

    Application::Instance()->GetWindow()->AddPopUpWindow(WindowImpt);
    WindowImpt->Add(framet);
    framet->Add(Panelt);
    Panelt->Add(Close);
}

/**

//
//    double cs = cos(45)*180/M_PI;
//double sn = (sin(45)*180)/M_PI;
//
//    if(vec2f::isPerpendicular(a,b))
//    {
//        std::cout << "a isPerpendicular to b "<< "\n";
//
//    }
//
//    std::cout << "a :" << a << "\n";
//    std::cout << "b :" << b << "\n";
//    std::cout << "C :" << c << "\n";
//

//
//double result_x =  3 * cs - 4 * sn;
//double result_y = 3 * sn + 4 * cs;

//
//    std::cout  << cs / sn << " / ";
//    std::cout  << sn << "\n"<< "\n";
//
//
//
//
//
//
//
//    vec2f b(0,0);
//    vec2f a(10,10);
//
//double angle = atan2f(4,3 )*180/M_PI;
//    std::cout  <<  angle<< " angle\n"<< "\n";
//
//    angle = atan2f(4,3 )*180/M_PI;
//    std::cout  <<  angle<< "\n angle\n"<< "\n";
//
//    angle = atan2f(4,3 )*180/M_PI;
//    std::cout  <<  angle<< " angle\n"<< "\n";
//
//
//    float c = vec2f::Dot(a,b);
//a.Rotate(std::sqrt(2/2));
//    std::cout  << std::acos(vec2f::Dot(a,b)/(float)(a.Length()*b.Length()))*180/M_PI << "\n"<< "\n";
//    std::cout  <<  c<< "\n";
//    std::cout  <<  a.Length()<< "\n";
//    std::cout  <<  b.Length()<< "\n";
//    std::cout  <<  cos(45) << "\n"<< "\n";
//    std::cout  <<  vec2f::GetMidPoint(a,b)<< "\n"<< "\n";
//    std::cout  <<    a.vectorAngle(5,4)<< "\n"<< "\n";
//    std::cout  <<   a.vectorAngle(3,4) +  a.vectorAngle(4,5) + a.vectorAngle(3,5) << "\n" << "\n" ;

//SDL_Delay(10000);

dynamic_cast<WindowImp*>(Application::Instance()->GetWindow()->GetWidget())->Save("WidgetLayout.txt");
| SDL_WINDOW_RESIZABLE
"TestState25",CreateWindowImp()))
"TestState26",CreateWindowImp2()))
"TestState27",CreateWindowImp2()))
"TestState28",CreateWindowImp2()))
  TestState2 TestState3 TestState4  TestState6  TestState10 TestState11
  TestState15  TestState17  TestState19  TestState20 TestState21 TestState22  TestState23 TestState24 TestState25 TestState26 TestState27 TestState28
 State_Pacman_Ready State_PacMan State_Template State_MainMenu_Settings State_GameMenu State_Logo_Screen TestState29 StateSnakeGame
    std::cout << App->GetFileBase() << "\n";

    std::cout << DirectoryHandler::Instance()->GetFileAsset() << "\n";
    std::cout << DirectoryHandler::Instance()->GetFileImg() << "\n";
    std::cout << DirectoryHandler::Instance()->GetFileFont() << "\n";
    std::cout << DirectoryHandler::Instance()->GetFileLevel() << "\n";

   std::ofstream ofs;

    ofs.open ("CameraSettings.txt", std::ofstream::out);

    ofs <<  "CameraPos                   : " << APP->GetCamera().GetPos() << "\n"<<
        "Camera Size                 : " << APP->GetCamera().GetSize() << "\n"<<
        "Camera Scale                : " << APP->GetCamera().GetScaler() << "\n"<<
        "Camera GetWorldPos          : " << APP->GetCamera().GetWorldPos()  << "\n"<<
        "Camera GetWorldSize         : " << APP->GetCamera().GetWorldSize() << "\n"<<
        "Camera GetWorldScaler       : " << APP->GetCamera().GetWorldScaler()  << "\n";
    ofs.close();


    SDL_Rect Rect_MenuBar = {0,0,Rect_window.w, MenubarSize};
    SDL_Rect Rect_Frame = {0,0,640,640};
  SDL_Rect Rect_panel = {Rect_Frame.x+Rect_Frame.w/4,Rect_Frame.y+Rect_Frame.h/4,640,360};
    App->GetCamera().SetVirtualSize(vec2f(256,256));
    Frame *m_Frame =  new Frame();
    m_Frame->Init("Frame",Rect_Frame);
m_WindowImp->Setboarder({0,NOFILLED});
 m_Frame->Setboarder({0,FILLED});

    m_WindowImp->Add(m_Frame);
 IWidget*  m_WindowImp = Create("WindowImp");

    std::string s = SDL_GetBasePath();
//std::string s2 = SDL_GetPrefPath();
std::cout << s <<"\n";

(float)std::atan2(25,9);
    std::cout << (float)(std::atan2(4,3)*180/M_PI)+(float)(std::atan2(3,4)*180/M_PI) << " atan2\n";
rectangle rr = {vec2f(0,0),vec2f(20,20)};

    vec2f vc = vecToPoint(GetRectCentre(rr));
    Vector2D<int>c = Vector2D<int>(3,4);
Vector2D<int>a = Vector2D<int>(3,0);
    Vector2D<int>b = Vector2D<int>(0,4);

    Vector2D<int>d = a+b;a



int MyEventFunction(void *userdata, SDL_Event *event) {
    // Do things with userdata and event

    return 0; // Value will be ignored
}

// ...
    //Success flag
	{
	//SDL will check this boolean to determine termination
	bool quit = false;

	//Initiate SDL window instance the GL context
	init();

	//Bootstrap CEGUI on the OpenGL context. All conditions have been met.
	//CEGUI::OpenGL3Renderer& myRen = CEGUI::OpenGL3Renderer::bootstrapSystem();

	//SDL event used for program termination
	SDL_Event e;
GLuint gVBO = 0;
GLuint gIBO = 0;
	//Loop runs waiting for user to terminate it
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
           //Initialize clear color
glClearColor( 0.f, 0.f, 0.f, 1.f );

                    //VBO data
                    GLfloat vertexData[] =
                    {
                        -0.5f, -0.5f,
                         0.5f, -0.5f,
                         0.5f,  0.5f,
                        -0.5f,  0.5f
                    };

                    //IBO data
                    GLuint indexData[] = { 0, 1, 2, 3 };

                    //Create VBO
                    glGenBuffers( 1, &gVBO );
                    glBindBuffer( GL_ARRAY_BUFFER, gVBO );
                    glBufferData( GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );

                    //Create IBO
                    glGenBuffers( 1, &gIBO );
                    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
                    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW );

	}
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
//gWindow = SDL_GL_GetCurrentWindow();
// SDL_GL_MakeCurrent(gWindow,gContext);
//    gContext = SDL_GL_CreateContext(    gWindow );

//    SDL_Window * gWindow;
//    SDL_GLContext gContext;
//    bool success = true;
//    GLuint gProgramID = 0;
//GLint gVertexPos2DLocation = -1;
//GLuint gVBO = 0;
//GLuint gIBO = 0; SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
//        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
//        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
//
//printf( "Unable to initialize OpenGL!\n" );
////
//         gContext = SDL_GL_CreateContext(    gWindow );
//
//printf( "Unable to initialize OpenGL!\n" );
//
//     if( gContext == NULL )
//            {
//                printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
//                success = false;
//            }
//            else
//            {
//                //Initialize GLEW
//                glewExperimental = GL_TRUE;
//                GLenum glewError = glewInit();
//                if( glewError != GLEW_OK )
//                {
//                    printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
//                }
//
//                //Use Vsync
//                if( SDL_GL_SetSwapInterval( 1 ) < 0 )
//                {
//                    printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
//                }
//                //Initialize OpenGL
////                if( !initGL() )
////                {
////                    printf( "Unable to initialize OpenGL!\n" );
////                    success = false;
////                }
//            }
//
//            SDL_Delay(1000);
////The window we'll be rendering to
////SDL_Window* gWindow = NULL;
////
//////OpenGL context
////SDL_GLContext gContext;
////
//////Render flag
////bool gRenderQuad = true;
////
////    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
////        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
////
////
////    glClear( GL_COLOR_BUFFER_BIT );
////    //Initialize Projection Matrix
////    glLoadIdentity();
////
////         glMatrixMode( GL_MODELVIEW );
////     glLoadIdentity();
////
////
////           glClearColor( 0.f, 0.f, 0.f, 1.f );
////     //Clear color buffer
////
////    //Render quad
////    if( gRenderQuad )
////    {
////        glBegin( GL_QUADS );
////            glVertex2f( -0.5f, -0.5f );
////            glVertex2f( 0.5f, -0.5f );
////            glVertex2f( 0.5f, 0.5f );
////            glVertex2f( -0.5f, 0.5f );
////        glEnd();
////    }
////
//
////    SDL_Event UserEvent;
////    UserEvent.type;
////    UserEvent.user.code =  7;
////        UserEvent.user.data1  = new std::string("Change_State");
////    UserEvent.user.data2 = StateFactory::Instance()->Create("TestState2");
////
////    SDL_PushEvent(&UserEvent);
////
////SDL_TimerCallback sii (500,new std::string("Change_Stat"));
////SDL_AddTimer(SDL_GetTicks()+500,sii,new std::string("Change_Stat"));
////
//
//
//
////SDL_AddEventWatch(NULLMyEventFunction);



aBoarderDecorator
aScrollDecrator
aTextView
 plan<-----
 click button to import Image
 use keyboard hotkey to import image
 drag image into software

 create pop up window that allows features and renaming
 then save it to file
 need a pannel to select images
 need a find bar
 need a viewer
 need a grid toggle button
 need tabs maybe



use dir mananger to select object,
object appears in the inspectMananger
object edditer which changes the file it reads

need to fix user events
need to make object inspecterManger
game engine new
name, location,

game engine load

texture asset
object asset
state asset
triggers asset
sound asset

game engine save
save
texture asset
object asset
state asset
triggers asset
sound asset

 */

