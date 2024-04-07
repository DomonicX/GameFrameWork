#ifndef STATESNAKEGAME_H
#define STATESNAKEGAME_H

#include <GameState.h>
#include <StateFactory.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <Animation.h>
enum{m_left,m_right} typedef snakeGameDir;
class StateSnakeGame: public GameState
{
public:
    StateSnakeGame();
    virtual ~StateSnakeGame();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
        void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "StateSnakeGame";
    }
protected:

private:
    double m_dt = 0.0;
    double m_time = 0.0;
    bool m_startGame =  false;
  Uint32 frameRate = 0;
    Uint32 oldTime = 0;
    bool m_spawnFruit = false;
    vec2f m_fruitPos = vec2f(0,0);
    int m_fruitCounter = 0;

    std::vector<vec2f> points;
std::vector<SDL_Rect>rects;
std::vector<vec2f>tail;
    bool isTouching = false;
    int m_points = 0;
    int m_lives = 5;
    vec2f v;
    vec2f d;
    vec2f pos;
    vec2f acc;
    vec2f vel;
    line bottomScreen;
    float Maxspeed;
    LTimer s ;
    int dirc = 0;

int gametimercounter = 0;
};


class StateSnakeGameCreater : public StateBaseCreater
{

public :  StateSnakeGame* CreateState() const
    {
        return new StateSnakeGame();
    }
};//
#endif // STATESNAKEGAME_H
