#ifndef GAMEOBJECT_ROCKETSHIP_H
#define GAMEOBJECT_ROCKETSHIP_H


#include <SDLGameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>
#include <TextureManager.h>
#include <Lmaths.h>
#include <Animation.h>

class GameOBject_RocketShip : public SDLGameObject
{
    public:
        GameOBject_RocketShip();
        virtual ~GameOBject_RocketShip();

    void Load(std::string FileName);
    void Collision();
    std::string Type(){return "GameOBject_RocketShip";}
    std::string Texture(){return "ball";}
    void HandleEvent(SDL_Event& e );
    void Update(float dt);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Clean();
    protected:

    private:

};
class GameOBject_RocketShipCreater: public BaseCreater
{
public :
    GameObject* CreateGameObject() const
    {
        return  new GameOBject_RocketShip();
    }
};

#endif // GAMEOBJECT_ROCKETSHIP_H
