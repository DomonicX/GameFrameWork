#ifndef MARIOLEVELSTATE_H
#define MARIOLEVELSTATE_H
#include <sstream>
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <map>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <CollisionManager.h>
#include <GUI_Object.h>
#include <math.h>
#include <vector>
#include <MarioPlayer.h>
#include <MarioBlock.h>
#include <MenuState.h>
#include <MarioEnemy.h>
#include <GUI_ScrollBar.h>
#include <GUI_Button.h>
#define RowsLevel_1 217
#define colsLevel_1 14
#include <CollisionManager.h>
#define MaxPannel_Level_1 12


#define maxLevel_Width 3,072
#define maxLevel_Height 240

#include <TextObject.h>

#define Rows 192
#define Cols 15
//column

#define camWidth 256
#define camheight 256
#define Pannel_width 256
#define Pannel_Height 240
#define Pannel_Tile_width 15
#define Pannel_Tile_Height 14
#include <ILayer.h>
#include <TextObject.h>

class MarioLevelState : public GameState
{
public:
    int PannelPos[13];
    int m_level_1[13][15][14];
    int level[15][14];
    MarioLevelState();
    virtual ~MarioLevelState();
    void Save();
    void Clear();
    void Reset();
    void Load();
    void Render();
    void Update();
    void UpdateObjects();
    bool OnEnter();
    bool onExit();
    void resume();
    void LoadPlayer(std::string marioState,int x,int y);

    void DrawMarioObjects();
    void Collision();
    void Collision_MarioPlayer_Blocks();
    void Collision_MarioPlayer_Enemies();
    void Collision_MarioPlayer_Items();
    void Collision_Blocks_Enemies();
    void Collision_Blocks_Items();
    void HandleEvent(SDL_Event &e );
    SDLGameObject* Add(std::string type,int x,int y);
    std::string GetStateID()
    {
        return "MarioLevelState";
    }
    bool bisPaused;
    vec2f player;
    float gravity = 9.98;
    vec2f    o,vel,acc,pos;
    bool m_bisSelected;
    bool m_leftClickDown = false;
    bool m_leftClickup = false;
    std::string m_isSelectedText;
    bool m_topcol,m_botcol,m_Rightcol,m_leftcol;
    bool isEditing()
    {
        return m_bisEditing;
    }
    void selectedingObject();
    float timer;

protected:

private:
    int tileSize = 0;
    int  offset = 0;
    bool   m_bisEditing = true;
    ILayer *m_MarioEditorlayer;
    GameObject *textObject = NULL;
    GameObject *button = NULL;
    GameObject *Widget_Box_Selection = NULL;
    GameObject *m_Widget_ScrollBar = NULL;
    GameObject *m_objectSelection = NULL;
    std::vector<GameObject*>SelectableObjects;
    std::vector<GameObject*>historyOfObjects;
    GameObject * m_MarioPlayer;
    std::vector<GameObject*>MarioBackGrounds;
    std::vector<GameObject*>MarioBlocks;
    std::vector<GameObject*>MarioItems;
    std::vector<GameObject*>MarioEnemies;
    std::vector<GameObject*>MarioUIs;
    std::map<std::string,std::string> MarioTypes;

        float dt = 0.0;
    std::string MarioBlocks_filename = "MarioBlocks.Txt";
    std::string MarioItems_filename = "MarioItems.Txt";
    std::string MarioUIs_filename = "MarioUIs.Txt";
    std::string MarioEnemies_filename = "MarioEnemies.Txt";
    std::string MarioBackGrounds_filename = "MarioBackGrounds.Txt";

};


#endif // MARIOLEVELSTATE_H








//    if(InputHandler::Instance()->isKeyDown())
//    {
//      //  m_MarioPlayer->GetPosition().y = 0;
//        //delete  m_MarioPlayer;
//        //  LoadPlayer();
//    }
//
// if( e.type == SDL_KEYDOWN && e.key.keysym.scancode==SDL_SCANCODE_SPACE)
//    {
//bisPaused = true;
//
//}
//
//
//    std::cout << Game::Instance()->GetWindowHeight() << "getwidth\n";
//


//    int a,b,c,d,e = 0;
//    // CollisionManager::Instance()->RemoveLayer("MarioBlocks");

//
////SDL_Delay(200);
//button = GameObjectFactory::Instance()->Create("GUI_Button");

//    button->Load("GUI_Button");
//    GUI_Button * s = new GUI_Button(&Game::Instance()->Clean);
//    s->call();
//    GUI_Button->
// dynamic_cast<GUI_Button*>(button)->Action();
// LoadGround();

// LoadData1();
//  LoadEnemies();
// LoadItems();

//
//     for(int i = 0 ;  i < MarioItems.size(); i++)
//    {
//
//    }
//    for(int i = 0 ;  i < MarioEnemies.size(); i++)
//    {
//
//    }
//    for(int i = 0 ;  i < MarioBlocks.size(); i++)
//    {
//ifs << MarioBlocks[i]->Type() << "\n";
//    }
//    for(int i = 0 ;  i < MarioUIs.size(); i++)
//    {
//
//    }




//
//
//     SDL_Surface* pScreenShot = SDL_CreateRGBSurface(0, 1920, 1080, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
//
//   if(pScreenShot)
//   {
//      // Read the pixels from the current render target and save them onto the surface
//      SDL_RenderReadPixels(Game::Instance()->GetRenderer(), NULL, SDL_GetWindowPixelFormat(Game::Instance()->GetWindow()->GetWindow()), pScreenShot->pixels, pScreenShot->pitch);
//
//      // Create the bmp screenshot file
//      SDL_SaveBMP(pScreenShot, "Screenshot.bmp");
//
//      // Destroy the screenshot surface
//      SDL_FreeSurface(pScreenShot);
//   }

//TextureManager::Instance()->DrawLine(startpoint.x,startpoint.y,startpointEnd.x,startpointEnd.y,Game::Instance()->GetRenderer());
// TextureManager::Instance()->DrawLine(midpoint.x+a.x,midpoint.y+a.y,midpoint.x+b.x,midpoint.y+ b.y,Game::Instance()->GetRenderer());
// TextureManager::Instance()->DrawLine(midpoint.x+a.x,midpoint.y+a.y,midpoint.x+b.x,midpoint.y- a.y,Game::Instance()->GetRenderer());
//TextureManager::Instance()->DrawBackGround("GUI_RECT",Game::Instance()->GetRenderer());
// TextureManager::Instance()->Draw("GUI_RECT",dsrect.x,dsrect.y,dsrect.w,dsrect.h,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);
// TextureManager::Instance()->Draw("GUI_RECT",dsrec.x,dsrec.y,dsrec.w,dsrec.h,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);

