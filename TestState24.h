#ifndef TESTSTATE24_H
#define TESTSTATE24_H



#include <GameState.h>
#include <iostream>
#include <StateFactory.h>
#include <Vector2D.h>
#include <Application.h>
#include <TextureManager.h>
#include <InputHandler.h>
#include <CallBack.h>
class testCallBack : public CallBack{
public :
    testCallBack();
    ~testCallBack();
   void call();
};

class TestState24 : public GameState
{
    public:
        TestState24();
        virtual ~TestState24();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    GameObject* rocket;
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState24";
    }
//    Node grid[10][10];
const float  grav   = 9.80665;
    protected:

    private:
bool m_left = false;
bool m_right = false;
bool m_middle = false;
std::vector<SDL_Rect> rects;
std::vector<bool> isRenderAble;

vec2f m_orgin[2] = {vec2f(0,1),vec2f(1,0)};

};

class TestState24Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState24();
    }
};
#endif // TESTSTATE24_H
