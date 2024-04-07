#ifndef TESTSTATE37_H
#define TESTSTATE37_H


#include <GameState.h>
#include <StateFactory.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <Application.h>
#include <Animation.h>
#include <EnemyLayer.h>
#include <ILayer.h>
#include <TileLayer.h>
#include <ParticleEmitter.h>
#include <Particle.h>
#include <ParticleSystem.h>
#include <Quad.h>

#define Pac_Man_Tile_Row 29
#define Pac_Man_Tile_col 30
#define Pac_Man_Cells 868
class TestState37 : public GameState
{
public:
    TestState37();
    virtual ~TestState37();
    void Render(SDL_Renderer* r);
    void Render() {};
    void Update() {};
    void Update(float dt);
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );

    std::string Type()
    {
        return "TestState37";
    }
    bool m_rightdown= false;
    bool m_Leftdown= false;
    bool m_Downdown = false;
    vec2f m_pos;
    vec2f m_vel;
    vec2f m_oldpos,m_oldpos2;
    vec2f m_acc;
    float m_mass = 10;
    vec2f m_pos2 = vec2f();
    vec2f m_vel2;
    vec2f m_acc2;
    bool isinBound(int i)
    {
        if( i>29 && i<841-29) return true;
        else return false;
    }

    void StoreKey(int dir)
    {
        dirflag = dir;
    }

    int dirflag = 0;
    bool checkIfOffPath(vec2f v);
    void addTOOBJECT(std::string type,std::string Texture,int w, int h,int x = 0, int y = 0,float degree = 0);
    float m_mass2 = 10;
    std::vector<SDL_Rect> tempRect;
    bool Gamemap[32][28];
    int GameGrid[30][29];
    float dtt = 0;
    GameObject* objplayer = NULL;
private:
    std::vector<GameObject*>m_gameObects;
    GameObject* m_player;
    std::vector<vec2f>m_v2;
    std::vector<SDL_Rect>m_Path;
    std::vector<SDL_Point>m_Path1;
    std::vector<Node>m_node;
    std::vector<GameObject*>obj;
    std::vector<GameObject*>OBJECT;
    std::vector<GameObject*>obj2;
    SDL_FPoint  playerBot;
    GameObject* m_pacman;
//    TextureManager::Instance()->Load("Img/BackGround_256.png","BackGround_256",APP->GetRenderer());
//int numberOfParticle;
//float m_emitterRaito;
//vec2f m_pos;
//vec2f m_vel;
//vec2f m_acc;
//vec2f m_lifeVar;
//vec2f m_

    LTimer timer;
    ParticleSystem m_ParticleSystem;
    ParticleEmitter m_ParticleEmitter;

    Animation  ani ;

};


class TestState37Creater : public StateBaseCreater
{
public :
    TestState37* CreateState() const
    {
        return new TestState37();
    }
};
#endif // TESTSTATE37_H

