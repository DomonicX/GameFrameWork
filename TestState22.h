#ifndef TESTSTATE22_H
#define TESTSTATE22_H


#include <GameState.h>
#include <iostream>
#include <StateFactory.h>
#include <Vector2D.h>
#include <Application.h>
#include <TextureManager.h>
#include <InputHandler.h>
struct level {rectangle _Rect;} ;
class TestState22: public GameState
{
    public:
        TestState22();
        virtual ~TestState22();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    vec2f sv,ev = vec2f(0,0);
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState22";
    }
    protected:

    private:
        vec2f m_oldpos,m_position,m_velocity, m_acceleration = vec2f(0,0);
        vec2f m_centreBallPos;
float  m_mass2 = 64;
float  m_mass1 = 16;
LText text;
float onesecond = 0.0;
float mouseRighDownTimer = 0;
    Gui::Label * label;
};
class TestState22Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState22();
    }
};

#endif // TESTSTATE22_H

