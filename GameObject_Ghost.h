#ifndef GAMEOBJECT_GHOST_H
#define GAMEOBJECT_GHOST_H


#include <SDLGameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>
#include <TextureManager.h>
#include <Lmaths.h>
#include <Animation.h>

class GameObject_Ghost : public SDLGameObject
{
    public:
        GameObject_Ghost();
        virtual ~GameObject_Ghost();
    void Load(std::string FileName);
    void Collision();
    std::string Type();
    std::string Texture();
    void HandleEvent(SDL_Event& e );
    void Update(float dt);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Clean();
void SetTarget(vec2f v);
    protected:

    private:
        vec2f m_targetPos = vec2f(0,0);
};

class GameObject_GhostCreater: public BaseCreater
{
public :
    GameObject* CreateGameObject() const
    {
        return  new GameObject_Ghost();
    }
};

#endif // GAMEOBJECT_GHOST_H
