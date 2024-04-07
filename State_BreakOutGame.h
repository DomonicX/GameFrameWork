#ifndef STATE_BREAKOUTGAME_H
#define STATE_BREAKOUTGAME_H


#include <TextObject.h>
#include <sstream>
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <GameObjectFactory.h>
#include <CollisionManager.h>
#include <TextureManager.h>
#include <math.h>
#include <vector>
#include <istream>
#include <Application.h>
#include <FontManager.h>
#include <GameObject_Ball.h>
#include <GameObject_Block.h>
#include <GameObject_Paddle.h>
#include <StateFactory.h>
/**<
r=    2(d.n)n
r = reflection vector
d = normalised incoming vector
n = normalised of surface its reflecting off

(d.n) = is the dot product of d and n;


 */
class State_BreakOutGame : public GameState
{
public:
    State_BreakOutGame();
    virtual ~State_BreakOutGame();
    void Render();
    void Update();
    void DoPaddleHit();
    void DoWallHit();
    void DoBlockHit();
    void BallSpawnUpdate();
    bool OnEnter();
    void RenderColour();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "State_BreakOutGame";
    }
float Ballv = 0.0;
vec2f Ballv2 = vec2f(0,0);
protected:

    std::vector<GameObject*>m_gameobjects;
    //      GUI_Frame *m_Frame;
    SDLGameObject *m_BackGround;
    vec2f s = vec2f(0,0);
    vec2f s2 = vec2f(0,0);
    SDL_FRect boarder ;
    SDL_Rect boarder2 ;
    vec2f paddleRectNormal;
    bool isBallSpawn = true;
};

class State_BreakOutGameCreater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new State_BreakOutGame();
    }
};
#endif // STATE_BREAKOUTGAME_H
