#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
class GameState
{
public :
    virtual ~GameState() {};
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual void Update(float dt){};
    virtual void Render(SDL_Renderer* r){};
    virtual bool OnEnter() = 0;
    virtual bool onExit() = 0;
    virtual void resume() =0;
    virtual  void HandleEvent(SDL_Event &e ) =0;
    virtual std::string Type()=0;
protected:
    bool m_loadingComplete;
    bool m_exiting;

    GameState() : m_loadingComplete(false),m_exiting(false)
    {

    }
private:

};

#endif // GAMESTATE_H
