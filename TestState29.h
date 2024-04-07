#ifndef TESTSTATE29_H
#define TESTSTATE29_H

#include <GameState.h>
#include <StateFactory.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <Animation.h>
#include <LTimer.h>
class TestState29: public GameState
{
public:
    TestState29();
    virtual ~TestState29();

    void Render() ;
    void Update()   ;
    bool OnEnter();
    bool onExit() ;
    void resume() ;

    void HandleEvent(SDL_Event &e) ;
    std::string Type()
    {
        return "TestState29";
    }
protected:
private  :
    vec2f acc;
    vec2f vel;
    vec2f friction;
    vec2f oldpos;
    vec2f pos;

    int counter = 0;
    float dt = 0;
    float fen = 0;
    int time = 0;
    LTimer s ;
};
class TestState29Creater : public StateBaseCreater
{


public :
    TestState29* CreateState() const
    {
        return new TestState29();
    }
};

#endif // TESTSTATE29_H
