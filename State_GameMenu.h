#ifndef STATE_GAMEMENU_H
#define STATE_GAMEMENU_H



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
#include <StateFactory.h>

 typedef enum {New,Conutiure,Load,Settings,Credits,Quit}  MainMenu_Text;


class State_GameMenu : public GameState
{
    public:
        State_GameMenu();
        virtual ~State_GameMenu();
 void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "State_GameMenu";
    }
    protected:

    private:
};
class State_GameMenuCreater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new State_GameMenu();
    }
};

#endif // STATE_GAMEMENU_H
