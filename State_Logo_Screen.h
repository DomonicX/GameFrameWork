#ifndef STATE_LOGO_SCREEN_H
#define STATE_LOGO_SCREEN_H
#include <GameState.h>
#include <StateFactory.h>

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

class State_Logo_Screen : public GameState
{
    public:
        State_Logo_Screen();
        virtual ~State_Logo_Screen();

    void Render();
    void Update(){}
    void Update(float dt)   ;
    bool OnEnter();
    bool onExit();
    void resume();
        void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "State_Logo_Screen";
    }
protected:

private:LTimer timer;
float cf = 0;
bool up = true;    };

class State_Logo_ScreenCreater : public StateBaseCreater
{

public :
    State_Logo_Screen* CreateState() const
    {
        return new State_Logo_Screen();
    }
};
#endif // STATE_LOGO_SCREEN_H
