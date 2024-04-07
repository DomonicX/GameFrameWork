#ifndef GAMEOBJECTTREE_H
#define GAMEOBJECTTREE_H

#include <SDLGameObject.h>
#include <Application.h>
#include <TextureManager.h>
#include <SoundManager.h>
#include <GameObjectFactory.h>
#include <ParticleSystem.h>
#include <ParticleEmitter.h>
class GameObjectTree  : public SDLGameObject
{
    public:
        GameObjectTree();
        virtual ~GameObjectTree();
    void Load(std::string FileName);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Update(float dt);
    void Clean() ;
    void Collision();
    bool m_startShaking = false;
    int  m_ShakingTimer;
    void SetplayerTarget(GameObject *player){m_playerTarget = player;}
    GameObject *m_playerTarget = NULL;
    void HandleEvent(SDL_Event& e );
      std::string     Type()
    {
        return "GameObjectTree";
    };
    std::string   Texture()
    {
        return m_textureID;
    }
void setTreeHeight(int treeheight);
    protected:

    private:
ParticleSystem m_LeavesFallingSystem;
ParticleEmitter m_LeaveFallingEmitter;
    int m_treeHeight = 0;
};

class GameObject_TreeCreater: public BaseCreater
{
public :
    SDLGameObject* CreateGameObject() const
    {
        return  new GameObjectTree();
    }
};

#endif // GAMEOBJECTTREE_H
