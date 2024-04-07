#ifndef TESTSTATE_H
#define TESTSTATE_H

#include <GameState.h>
#include <iostream>
#include <StateFactory.h>
class TestState : public GameState
{
public:
    TestState();
    virtual   ~TestState();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState";
    }
protected:

private:
};

class TestStateCreater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState();
    }
};

#endif // TESTSTATE_H
