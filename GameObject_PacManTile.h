#ifndef GAMEOBJECT_PACMANTILE_H
#define GAMEOBJECT_PACMANTILE_H

#include <SDLGameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>
#include <TextureManager.h>
#include <Lmaths.h>
#define Pac_Man_Tile_Row 28
#define Pac_Man_Tile_col 31
#define Pac_Man_Tile_area 868
#include <Animation.h>

class GameObject_PacManTile :public SDLGameObject
{

public:
    GameObject_PacManTile();
    virtual ~GameObject_PacManTile();
    std::string Type()
    {
        return m_type;
    }
    std::string Texture() {return "PacManTileSet";}

    void Load(std::string FileName);
    void Update(float dt);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Clean();
    void Collision();
    void HandleEvent(SDL_Event& e );
    SDL_Color m_colour = Colour_white;
    std::string m_type = "GameObject_PacManTile";
protected:

private:
};
class GameObject_PacManTileCreater: public BaseCreater
{
public :
    GameObject* CreateGameObject() const
    {
        return  new GameObject_PacManTile();
    }
};

#endif // GAMEOBJECT_PACMANTILE_H
