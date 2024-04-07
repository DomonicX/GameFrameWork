#ifndef TESTSTATE31_H
#define TESTSTATE31_H


#include <GameState.h>
#include <StateFactory.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <Animation.h>
#include <LTimer.h>
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>

class TestState31 : public  GameState
{
    public:
        TestState31();
        virtual ~TestState31();

    void Render() ;
    void Update() {}
    void Update(float dt)   ;
    bool OnEnter();
    bool onExit() ;
    void resume() ;

        std::vector<GameObject*>m_gameObects;
Animation Anim2;
Animation Anim3;bool m_clicked = false;
Animation Anim;
float m_scrollingspeed = 1;
int m_scrollingBoarderOffset = 0;
    void HandleEvent(SDL_Event &e) ;
    std::string Type()
    {
        return "TestState31";
    }
    protected:

    private:
        std::vector<GameObject*>m_gameobjects;
};

class TestState31Creater : public StateBaseCreater
{
public :
    TestState31* CreateState() const
    {
        return new TestState31();
    }
};
#endif // TESTSTATE31_H
