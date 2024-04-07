#ifndef GAMEOBJECT_PACMANWALL_H
#define GAMEOBJECT_PACMANWALL_H

#include <SDLGameObject.h>
#include <Application.h>
#include <TextureManager.h>
#include <SoundManager.h>
#include <GameObjectFactory.h>
#include <GameObject_Tile.h>

class GameObject_PacmanWall: public SDLGameObject
{
public:
    GameObject_PacmanWall();
    virtual ~GameObject_PacmanWall();

    void Load(std::string FileName);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Update(float dt) ;
    void Clean() ;
    void Collision( GameObject* g) ;
    void Collision();
    void HandleEvent(SDL_Event& e ) ;
    std::string  GetType(std::string newType )
    {
        return m_Type;
    }
    void SetType(std::string newType )
    {
        m_Type = newType;
    }
    std::string     Type()
    {
        return m_Type;
    };
    std::string   Texture()
    {
        return m_textureID;
    }
    void SetNeighbour(bool con, int index)
    {
        m_bNeighbour[index] = con;
    }
protected:

private:
    std::string m_Type = "GameObject_PacmanWall";
    bool m_bNeighbour[9];
};
class GameObject_PacmanWallCreater: public BaseCreater
{
public :
    GameObject_PacmanWall* CreateGameObject() const
    {
        return  new GameObject_PacmanWall();
    }

};

#endif // GAMEOBJECT_PACMANWALL_H


