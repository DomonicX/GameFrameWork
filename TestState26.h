#ifndef TESTSTATE26_H
#define TESTSTATE26_H


#include <GameState.h>
#include <Application.h>
#include <StateFactory.h>
class TestState26: public GameState
{
public:
        TestState26();
        virtual ~TestState26();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState26";
    }
protected:

private:
    bool isOver = false;
SDL_FRect n;

    bool is_A_ButtonDown = false;
    long int FrameCounter = 0;
std::string sssss ;
};


class TestState26Creater : public StateBaseCreater
{

public :  TestState26* CreateState() const
    {
        return new TestState26();
    }
};

#endif // TESTSTATE26_H
