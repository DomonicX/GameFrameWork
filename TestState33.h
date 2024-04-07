#ifndef TESTSTATE33_H
#define TESTSTATE33_H

#include <GameState.h>
#include <StateFactory.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>
#include <Lmaths.h>
class TestState33 : public GameState
{
    public:
        TestState33();
        virtual ~TestState33();
   void Render();
    void Update(){};
    void Update(float dt);
    bool OnEnter();
    bool onExit();
    void resume();
  vec2f m_pos = vec2f(0,0);
    vec2f m_vel = vec2f(0,0);
    vec2f m_acc = vec2f(0,0);
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState33";
    }
    protected:

    private:

        std::vector<GameObject*>m_gameObects;

};
class TestState33Creater : public StateBaseCreater
{
public :
    TestState33* CreateState() const
    {
        return new TestState33();
    }
};

#endif // TESTSTATE33_H
