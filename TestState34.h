#ifndef TESTSTATE34_H
#define TESTSTATE34_H

#include <GameState.h>
#include <StateFactory.h>
#include <Application.h>
#include <InputHandler.h>
#include <Lmaths.h>
#include <TextureManager.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>
#include <Lmaths.h>
#include <Quad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ParticleEmitter.h>



class TestState34 : public GameState
{

public:
    bool isdown = false;

    vec2f m_pos = vec2f();
    vec2f m_vel = vec2f();
    vec2f m_acc = vec2f();
    float x  = 0;
    TestState34();
    virtual ~TestState34();
    void Render();
    void Update() {};
    void Update(float dt);
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState34";
    }
    std::vector<ParticleEmitter*> m_e;
//LQaudTree qt;
protected:

private:
    int framecount = 0;
    std::vector<SDL_Rect> t1;
    std::vector<SDL_Rect> t2;
    std::vector<SDL_Rect> t3;
    std::string sstring;
    std::vector<SDL_Rect>mrects;
};
class TestState34Creater : public StateBaseCreater
{
public :
    TestState34* CreateState() const
    {
        return new TestState34();
    }
};

#endif // TESTSTATE34_H
