#ifndef MARIOITEM_H
#define MARIOITEM_H

#include <string.h>
#include <SDLGameObject.h>

typedef enum
{
    RedMushroom,
    GreenMushroom,
    Coin,
    StarPower,
    FireFlower
}   MarioItemType;

class MarioItem : public SDLGameObject
{
public:
    MarioItem();
    virtual ~MarioItem();

    void Load(char* filename);
     void Update();
    void Clean();
    void Collision();
    void HandleEvent(SDL_Event& e ){}
    std::string Texture()
    {
        return "MarioTileSet";
    }
    void isOnGround()
    {
        m_bisGrounded= true;
    }

void Draw();
protected:

private:
     bool m_bisGrounded = false;
    std::string m_Itemtype;
};


class  MarioItemObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioItem();
    }
};






#endif // MARIOITEM_H
