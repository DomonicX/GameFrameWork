#ifndef GAMEOBJECT_PACMAN_H
#define GAMEOBJECT_PACMAN_H

#include <SDLGameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>
#include <TextureManager.h>
#include <Lmaths.h>
#define Pac_Man_Tile_Row 28
#define Pac_Man_Tile_col 32
#define Pac_Man_Tile_area 868
#include <Animation.h>


namespace PacMan
{

typedef enum
{
    MOVING_LEFT,
    MOVING_RIGHT,
    MOVING_UP,
    MOVING_DOWN,
} Animation;

//ctor

typedef enum
{
    IDLE,
    SUPER_PACMAN,
    SPAWNING,
    DYING,
    DEAD,
    MOVING,
    EATING_GHOST,
    EATING_CHERRY,
    EATING_PALLET,
    EATING_SUPERPALLET
} OBJECT;


typedef enum {LEFT,RIGHT,UP,DOWN} Moving;
}


class GameObject_PacMan :public SDLGameObject
{
public:
    GameObject_PacMan();
    virtual ~GameObject_PacMan();
    void Load(std::string FileName);
    void Collision();
    void Collision( GameObject* g) {
GameObject::GetPosition() =m_lastPos;

m_collision = true;
m_velocity = vec2f(0,0);
 m_acceleration = vec2f(0,0);
SetStoreMove(false);
};
bool Gamemap[32][28];
vec2f GameCoord[32][28];
void AssignWall(bool gm[32][28])
{
    for(int i = 0; i < 32; i++)
    for(int j = 0; j < 28; j++)
    {
        GameCoord[i][j] = vec2f(j*8,i*8);
Gamemap[i][j] = gm[i][j];
    }
}
    std::string Type()
    {
        return "GameObject_PacMan";
    }
    std::string Texture();
    void HandleEvent(SDL_Event& e );
    void Update(float dt);
    void SetStoreMove(bool con)
    {
        m_setStoreMove = con;
    }
    bool IsStoreMove()
    {
        return m_setStoreMove;
    }
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Clean();
    void  updateAnimation();
    vec2f getDirVec()
    {
        return ((m_velocity.GetNormalise())*m_mass);
    }
    void setUpSenser(vec2f s)
    {
        m_UpSenser = s;
    }
    void setLeftSenser(vec2f s)
    {
        m_LeftSenser =s;
    }
    void  setRightSenser(vec2f s)
    {
        m_RightSenser = s;
    }
    void    setDownSenser(vec2f s)
    {
        m_DownSenser  = s;
    }
    std::string GetDir();
    std::string GetVaildDir()
    {
//        switch(m_DirFlag)
//    {

//        case 0 :
//        return "U";
//        break;case 1 :
//        return "left";
//        break;case 2 :
//        return "right";
//        break;case 3 :
//        return "left";
//        break;
//        default :
//
//    };
        return " ";
    }
    void SetDir(int dir)
    {
        m_DirFlag = dir;
    }
    void Move_Up();
    void Move_Left();
    void Move_Right();
    void Move_Down();

    vec2f GetDirSenser();
protected:

private:
    bool m_setStoreMove = false;
    Animation*  m_CurrentAnmation = NULL;
    Animation m_Pacman_animation_MovingRight;
    Animation m_Pacman_animation_MovingLeft;
    Animation m_Pacman_animation_MovingUp;
    Animation m_Pacman_animation_MovingDown;
    bool m_collision = false;
    int m_DirFlag = -1;
    int m_stateFlag = 0;
    SDL_Rect m_dsr;
    vec2f m_UpSenser,m_LeftSenser,m_DownSenser,m_RightSenser = vec2f (0,0);
};
class GameObject_PacManCreater: public BaseCreater
{
public :
    GameObject* CreateGameObject() const
    {
        return  new GameObject_PacMan();
    }
};


#endif // GAMEOBJECT_PACMAN_H
/**<
    void Update(){};
    void Load(std::string FileName){};
    void Update(){};
    void Render(){};
    void Clean(){};
    void Collision(){};
 bool isVisable(){}
    std::string Type()
    {
        return "";
    }
    std::string Texture(){};
    void HandleEvent(SDL_Event& e ){}; */
