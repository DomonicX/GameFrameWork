#ifndef TESTSTATE18_H
#define TESTSTATE18_H

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
#include <StateFactory.h>

/**<
r=    2(d.n)n
r = reflection vector
d = normalised incoming vector
n = normalised of surface its reflecting off

(d.n) = is the dot product of d and n;


 */
class TestState18CallBack : public CallBack{
public :
    TestState18CallBack(){};
    ~TestState18CallBack(){};
   void call();

};


class TestState18 : public GameState
{
public:
    TestState18();
    virtual   ~TestState18();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState18";
    }
protected:

private:

    SDL_Rect box;
    vec2f boxCentre;
    vec2f spawnPos = vec2f(0,0);
    vec2f mouse = vec2f(0,0);
    vec2f r,d,n;

};
class TestState18Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState18();
    }
};

#endif // TESTSTATE18_H
