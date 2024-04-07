#ifndef TESTSTATE25_H
#define TESTSTATE25_H

#include <GameState.h>
#include <StateFactory.h>
#include <Vector2D.h>
#include <Application.h>
#include <LTimer.h>
#define Pac_Man_Tile_Row 28
#define Pac_Man_Tile_col 32


typedef enum {_Soild = 1,
              _Empty,
              _Ghost,
              _Food,
              _Cherry
} TileTypes;
class TestState25: public GameState
{
public:
    TestState25();
    virtual ~TestState25();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();

    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState25";
    }
protected:


private:
    vec2f m_tiles[Pac_Man_Tile_col][Pac_Man_Tile_Row];
    std::vector<vec2f>m_pathTiles;
    TileTypes m_tilesType[Pac_Man_Tile_col][Pac_Man_Tile_Row];


    LText m_text;
    LTimer timer;
    std::vector<GameObject*>m_gameobjects;

    GameObject *gb;
    int conter = 0;
    int conter1 = 0;
    vec2f path = vec2f(0,0);
    vec2f ta = vec2f(0,0);
    vec2f ta1  = vec2f(0,0);
    std::vector<SDL_Point> points;
    bool isSpaceDown = false;
    vec2f oldpos,pos,acc,vel,force = vec2f(0,0);
    std::string drop;
    float gravity,mass,speed = 0.0f;
    double dt = 0.0f;
};


class TestState25Creater : public StateBaseCreater
{

public :
    TestState25* CreateState() const
    {
        return new TestState25();
    }
};

#endif // TESTSTATE25_H
