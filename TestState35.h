#ifndef TESTSTATE35_H
#define TESTSTATE35_H


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
class TestState35: public GameState

{
    public:
        TestState35();
        virtual ~TestState35();

    bool isdown = false;

    float x  = 0;
    void Render();
    void Update() {};
    void Update(float dt);
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState35";
    }
    protected:
SDL_Rect m;
std::vector<vec2f>m_points;
    private:
        bool m_d =false;
        bool m_ud =false;
};

class TestState35Creater : public StateBaseCreater
{
public :
    TestState35* CreateState() const
    {
        return new TestState35();
    }
};
#endif // TESTSTATE35_H
