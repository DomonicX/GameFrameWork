#ifndef TESTSTATE32_H
#define TESTSTATE32_H

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

class TestState32 : public GameState
{
    public:
        TestState32();
        virtual ~TestState32();
    void Render() ;
    void Update() {}
    void Update(float dt)   ;
    bool OnEnter();
    bool onExit() ;
    void resume() ;
    void HandleEvent(SDL_Event &e) ;
    std::string Type()
    {
        return "TestState32";
    }
    float  _angleVelocity, _angleAccel, _angle , _length, _dt = 0;
 vec2f m_pos , m_vel ,k,m_rest, m_acc = vec2f();
  float m_width = 64;
  float m_height = 64;
float inc =0.0f;
    vec2f m_levelSize = vec2f(1920,1080);
    float m_scrollSpeed = 0.0f;
    vec2f m_player = vec2f();
    vec2f m_displacement  = vec2f();
float counter = 0.0;
float f,t,l,g,m,a = 0;
        vec2f m_scrollSpeedvel = vec2f (0,0);
    vec2f m_scrollSpeedacc = vec2f (0,0);
protected:

    private:
 std::vector<SDL_Rect> TR;
 std::vector<SDL_Rect> lR;
 std::vector<std::vector<SDL_Rect>> lR2;

};
class TestState32Creater : public StateBaseCreater
{
public :
    TestState32* CreateState() const
    {
        return new TestState32();
    }
};
#endif // TESTSTATE32_H
