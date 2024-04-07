#ifndef GAMEOBJECT_TILE_H
#define GAMEOBJECT_TILE_H



#include <SDLGameObject.h>
#include <Application.h>
#include <TextureManager.h>
#include <SoundManager.h>
#include <GameObjectFactory.h>
#include <GameObject_Ball.h>
class GameObject_Tile : public SDLGameObject
{

    public:
        GameObject_Tile();
        virtual ~GameObject_Tile();
    void Load(std::string FileName){};
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Update(float dt){};
    void Clean(){};
     void Collision( GameObject* g);
    void Collision();
    void HandleEvent(SDL_Event& e ){};
    std::string  GetType(std::string newType ) {return m_Type;}
    void SetType(std::string newType ) {m_Type = newType;}
    std::string     Type()
    {
        return m_Type;
    };
    std::string   Texture()
    {
        return m_textureID;
    }
    protected:

    private:
         std::string m_Type = "GameObject_Tile";
};
class GameObject_TileCreater: public BaseCreater
{
public :
    GameObject_Tile* CreateGameObject() const
    {
        return  new GameObject_Tile();
    }

};

#endif // GAMEOBJECT_TILE_H
