#ifndef TESTSTATE23_H
#define TESTSTATE23_H



#include <GameState.h>
#include <iostream>
#include <Application.h>
#include <Lmaths.h>
#include <string.h>
#include <IWidget.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ILayer.h>
struct tile
{
vec2f m_Pos;
vec2f m_Size;
SDL_Color m_colour;
bool isViable = true;
bool isSolid = false;
};


class TestState23 : public GameState
{
    public:
        TestState23();
        virtual ~TestState23();
    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
            bool isGrounded = false;
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState23";
    }
    protected:

    private:
    std::vector<SDL_Rect> buffer;

vec2f pacmanTraj ;
std::vector<SDL_Rect>m_SoildTiles;
std::vector<SDL_Rect>m_PathTiles;
        tile m_tiles[35][28];
        vec2f tiles[35][28];
Gui::Entry *TextEnty;
Gui::Entry *TextEnty2;
Gui::Entry *TextEnty3;
    Gui::Label * label;

float gametick = 0.0F;
LTexture texture;
LTexture GamePanel;
LText text;
        bool stop ,isgrabbed = false;
        vec2f o;
        vec2f Lastpos,Lastpos1;
        vec2f pos,pos1;
        vec2f force,force1;

        vec2f vel,vel1;
        vec2f acc,acc1;
        double dt;
        float speedX,speedY;
        float speedX1,speedY1;
        float mass;
        float mass1;
        SDL_Rect paddle;
GameObject *g;;
std::vector<GameObject*>m_pellets;
std::vector<GameObject*>m_ghost;
const float  grav   = 9.81;
};

class TestState23Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState23();
    }
};

#endif // TESTSTATE23_H
