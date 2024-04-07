#ifndef TESTSTATE21_H
#define TESTSTATE21_H

#include <GameState.h>
#include <iostream>
#include <StateFactory.h>
#include <TextureManager.h>
#include <Application.h>
#include <Animation.h>
#include <vector>
#include <string.h>
class TestState21 : public GameState
{
    public:
        TestState21();
        virtual ~TestState21();


    void Render();
    void Update();
    bool OnEnter();

    bool onExit();
    void resume();
    Animation   Ani;
    void HandleEvent(SDL_Event &e );
float dt = 0.0;
        vec2f b= vec2f(0,100);





        std::vector<std::string>strList;
        std::vector<LText>lTextList;
    std::string Type()
    {
        return "TestState21";
    }
    protected:

    private:
     LText ltext;
};

class TestState21Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState21();
    }
};

#endif // TESTSTATE21_H
