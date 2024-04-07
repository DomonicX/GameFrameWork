#ifndef TESTSTATE36_H
#define TESTSTATE36_H


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


class TestState36: public GameState
{
public:
    TestState36();
    virtual ~TestState36();
    void Render(SDL_Renderer* r);
    void Render() {};
    void Update() {};
    void Update(float dt);
    bool OnEnter();
    bool onExit();
    void resume();
    Animation ani;
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState36";
    }
    std::vector<vec2f>p;
    std::vector<vec2f>m_circle;
    bool num[120][67];
    SDL_Point *m_po;
    int m_maxWidth = 0;
    int m_maxHeight = 0;
  float  k = 0.25;
  float  x = 100;
  float  f =0;
  GameObject* obj = NULL;
  GameObject* objplayer = NULL;
private:
    std::vector<ILayer*>m_layers;
    std::vector<GameObject*>m_gameObects;
    std::vector<GameObject*>m_collisons;

    int dir = 0;
    vec2f pos,vel,acc = vec2f(0,0);
    vec2f LmouseClick,RmouseClick = vec2f(0,0);
       std::vector<ParticleEmitter*> m_e;
       std::vector<ParticleEmitter*> m_2e;
       ParticleSystem psys ;
  std::vector<vec2f>rand_pos;
  std::vector<vec2f>trace_pos;
  std::vector<SDL_Point>rand_pon;
  SDL_Rect camB ;
};


class TestState36Creater : public StateBaseCreater
{
public :
    TestState36* CreateState() const
    {
        return new TestState36();
    }
};

#endif // TESTSTATE36_H


