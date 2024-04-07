#ifndef TESTSTATE28_H
#define TESTSTATE28_H

#include <GameState.h>
#include <StateFactory.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <Animation.h>
 #include <SimplexNoise.h>
class TestState28: public GameState
{
    public:
        TestState28();
        virtual ~TestState28();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    float time  = 0;
        void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState28";
    }
    protected:

    private:
        rectangle rect;
        circle c;
        line l;
        vec2f pe,ke;
        Animation s;
    Animation Anim ;
        Animation Anim2;

        std::string a = "";
};
class TestState28Creater : public StateBaseCreater
{


public :  TestState28* CreateState() const
    {
        return new TestState28();
    }
};

#endif // TESTSTATE28_H
