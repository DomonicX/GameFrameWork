#ifndef STATE_MAINMENU_SETTINGS_H
#define STATE_MAINMENU_SETTINGS_H


#include <iostream>
#include <Vector2D.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <math.h>
#include <vector>
#include <istream>
#include <Application.h>
#include <FontManager.h>


#include <GameState.h>
#include <StateFactory.h>

typedef  struct
{
    int v = 0;
} cell;

typedef  struct
{
    cell blocks[3][3];
} block;
typedef  struct
{
    block game[3][3];
} suh;


static bool isPuzzleVaild(suh Game)
{

    for(int i = 0 ; i < 3; i++)
    {
    for(int j = 0 ; j < 3; j++)
    {
        if((Game.game[0][i].blocks[0][j].v &&
                Game.game[1][i].blocks[1][j].v &&
                Game.game[2][i].blocks[2][j].v ) > 0)
            return true;
    }
    }
    return false;

    return true;
}
static bool InsertValue(int x,int y, int newValue,suh Game)
{
    bool isPossiable = false;
    if(isPuzzleVaild(Game)) Game.game[0][0].blocks[0][0].v = x;
    return isPossiable;
}
//insertValue is for shufflePuzzle // Same for is vaild since i want to hide it
static bool ShufflePuzzle()
{
    return true;
}
class State_MainMenu_Settings: public GameState

{
public:
    State_MainMenu_Settings();
    virtual ~State_MainMenu_Settings();

                    std::vector<std::string>texturesTites;
IWidget *TextureManagerPannel;

 SDL_FRect cam;
 int counter = 0;
    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    float speed = 0;
    float angle = 0;
    vec2f pos,pos1,vel,vel1,acc,acc1 = vec2f(0,0);
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "State_MainMenu_Settings";
    }

    std::vector<SDL_Rect> maps;
protected:

private:

    std::vector<SDL_Rect> suhGrids = MakeGrid(0,32,9,9,32);

    std::vector<SDL_Rect> suhTextPosGrids = MakeGrid(9,32+9,9*2-1,9*2-1,16);

    std::vector<SDL_Rect> textCheck = MakeGrid(0,0,9,9,1);

    bool LeftUp,RightUp,MiddleUp= true;
    bool LeftDown,RightDown,MiddleDown = false;
};


class State_MainMenu_SettingsCreater : public StateBaseCreater
{

public :
    State_MainMenu_Settings* CreateState() const
    {
        return new State_MainMenu_Settings();
    }
};
#endif // STATE_MAINMENU_SETTINGS_H
