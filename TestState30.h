#ifndef TESTSTATE30_H
#define TESTSTATE30_H

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

class TestState30: public GameState
{
public:
    TestState30();
    virtual ~TestState30();

        std::string textinString;
    void Render() ;
    void Update() {}
    void Update(float dt)   ;
    bool OnEnter();
    bool onExit() ;
    void resume() ;
     LText ltext;
    vec2f Startpos;
    vec2f Velocity;
    vec2f Acceration;

    void HandleEvent(SDL_Event &e) ;
    std::string Type()
    {
        return "TestState30";
    }
    protected   :

    private :
int frameCounter = 0;
    std::vector<GameObject*>m_gameobjects;
    vec2f ballpos,ballbass,Ke,Ne = vec2f(0,0);
bool isballReleased = false;
     float ballangle = 0;
     float ballRopeLength = 0;
    vec2f pos,vel,acc;
    float minVel;
     std::string ballInfo;
  float t;
 float f;
 float gametime= 0;
    GameObject* rocket;

const float  grav   = 9.81;
};
class TestState30Creater : public StateBaseCreater
{
public :
    TestState30* CreateState() const
    {
        return new TestState30();
    }
};


#endif // TESTSTATE30_H
