#ifndef STATE_PACMAN_READY_H
#define STATE_PACMAN_READY_H



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
#include <FontManager.h>

class State_Pacman_Ready : public GameState
{
    public:
        State_Pacman_Ready();
        virtual ~State_Pacman_Ready();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "State_Pacman_Ready";
    }
    protected:

    private:
        float dt = 0.0;
       bool m_blink = false;
};


class State_Pacman_ReadyCreater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new State_Pacman_Ready();
    }
};

#endif // STATE_PACMAN_READY_H

