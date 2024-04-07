#ifndef STATE_BLANKSCREEN_H
#define STATE_BLANKSCREEN_H

#include <GameObjectProxy.h>
#include <TextObject.h>
#include <sstream>
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <math.h>
#include <vector>
#include <istream>
#include <Application.h>
#include <FontManager.h>
#include <LTexture.h>
#include <StateFactory.h>

#include <TestState21.h>
#include <TestState17.h>
#include <TestState.h>
#include <TestState20.h>
#include <TestState22.h>
#include <TestState19.h>
#include <TestState23.h>
#include <TestState24.h>
#include <TestState25.h>
#include <TestState26.h>
#include <TestState27.h>
#include <TestState28.h>
#include <TestState29.h>
#include <TestState30.h>
#include <TestState31.h>
#include <TestState32.h>
#include <TestState33.h>
#include <TestState34.h>
#include <TestState35.h>
#include <TestState36.h>
#include <TestState37.h>
#include <State_Template.h>
#include <State_MainMenu_Settings.h>
#include <State_Logo_Screen.h>
#include <State_GameMenu.h>


#include <State_PacMan_Ready.h>


#include <TestState18.h>
//#include <TestState14.h>
#include <State_PacMan.h>
#include <State_BreakOutGame.h>
#include <GameObject_PacMan.h>
#include <GameObject_PacManWall.h>
#include <GameObject_PacManTile.h>
#include <GameObject_Ghost.h>
#include <GameOBject_RocketShip.h>
#include <GameObject_Tile.h>
#include <StateSnakeGame.h>
#include <GameObjectTree.h>
#include <GameObject_Player.h>



class State_BlankScreen: public GameState
{
public:
    State_BlankScreen();
    virtual ~State_BlankScreen();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "State_BlankScreen";
    }
//SimplexNoise n;
protected:

private:
};
class State_BlankScreenCreater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new State_BlankScreen();
    }
};
#endif // STATE_BLANKSCREEN_H
