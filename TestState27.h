#ifndef TESTSTATE27_H
#define TESTSTATE27_H


#include <GameState.h>
#include <Application.h>
#include <StateFactory.h>
#include <WidgetFactory.h>


class TestState27: public GameState
{
public:
    TestState27();
    virtual ~TestState27();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState27";
    }
protected:

private:
    vec2f a,b = vec2f();
    Gui::Button *Button1;
    GameObject * m_ball = NULL;
};

class TestState27Creater : public StateBaseCreater
{

public :  TestState27* CreateState() const
    {
        return new TestState27();
    }
};
#endif // TESTSTATE27_H
