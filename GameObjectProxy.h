#ifndef GAMEOBJECTPROXY_H
#define GAMEOBJECTPROXY_H

#include <GameObject.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <Application.h>
class GameObjectProxy :  public GameObject

{
public:
    GameObjectProxy();
    virtual ~GameObjectProxy();

    void Load(std::string FileName) {}
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY) ;
    void Update(float dt) {}

    void Clean() {}
    void Collision() ;
    std::string Type()
    {
        return "GameObjectProxy";
    }
    std::string Texture()
    {
        return "Error";
    }
    void HandleEvent(SDL_Event& e ) {}

protected:

private:
};

class GameObjectProxyCreater : public BaseCreater
{
public:
    GameObject* CreateGameObject() const
    {
        return  new GameObjectProxy();
    }
};
#endif // GAMEOBJECTPROXY_H
