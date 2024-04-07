#ifndef TESTSTATE20_H
#define TESTSTATE20_H


#include <GameState.h>
#include <iostream>
#include <Application.h>
#include <Lmaths.h>
#include <string.h>

class TestState20 : public GameState
{
    public:
        TestState20();
        virtual ~TestState20();
    void Render();
    void Update();
     bool OnEnter();
    bool onExit(){}
    void resume(){}
    void HandleEvent(SDL_Event &e );
  float mouseWheelX,mouseWheelY;
    std::string Type()
    {
        return "TestState20";
    }

    protected:

    private:

LText ltext;
LTexture ltexture;
};
class TestState20Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState20();
    }
};


#endif // TESTSTATE20_H
