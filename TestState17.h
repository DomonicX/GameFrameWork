#ifndef TESTSTATE17_H
#define TESTSTATE17_H




#include <TextObject.h>
#include <sstream>
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <math.h>
#include <vector>
#include <istream>
#include <Application.h>
#include <ParticleSystem.h>
#include <FontManager.h>
#include <StateFactory.h>

typedef struct
{
SDL_Color c;
} Recttile;

class TestState17: public GameState
{
    public:
        TestState17();
        virtual ~TestState17();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    int framec = 0;

    bool isPointBeingRender(int x, int y)
    {
        if(x >= 0 && y >= 0 )
        if(x <640 && y <360 )
        return isRenderAble[y][x];
        else return false;
    }
////    void CreateFrame();
////    void CreatePannels();
////    void CreateCamera();


    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState17";
    }
    protected:

    private:

SDL_Point rects[360][640];
bool isRenderAble[360][640];
    std::vector<SDL_Rect> GridLinesRect;
    std::vector<SDL_Rect> TileEdge;
    std::vector<SDL_Rect> blocks;
SDL_Rect box;
bool isBlack, isWhite = false;
        ParticleSystem* p;
        std::vector<SDL_Rect> r;
        int index,ccount = 0;
        vec2f m_pos,m_vel,m_acc,m_oldpos,m_spawn,m_force,m_fricton = vec2f(0,0);
        float m_mass, m_speedY,m_speedX;
        bool m_spawnBlocks = false;
        vec2f Yaxis,Xaxis,v,dn,sn,ref = vec2f(0,0);

};
class TestState17Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState17();
    }
};

#endif // TESTSTATE17_H
