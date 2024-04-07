#ifndef GAMEOBJECT_PLAYER_H
#define GAMEOBJECT_PLAYER_H


#include <SDLGameObject.h>
#include <Application.h>
#include <TextureManager.h>
#include <SoundManager.h>
#include <GameObjectFactory.h>

namespace PLAYER
{

typedef enum
{
    MOVING_NA,
    MOVING_LEFT,
    MOVING_RIGHT,
    MOVING_UP,
    MOVING_DOWN,
} Move;

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

class GameObject_Player : public SDLGameObject
{
public:
    GameObject_Player();
    virtual ~GameObject_Player();
    void Load(std::string FileName);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Update(float dt);
    void Clean();
    void OnGround(){isOnGround = true; Jump = false;m_force = vec2f(0,0);
        m_velocity.y = 0;
        m_acceleration.y = 0;}
    void Collision();
    void Collision( GameObject* g);
    void HandleEvent(SDL_Event& e );
    std::string     Type()
    {
        return "GameObject_Player";
    };
    std::string   Texture()
    {
        return m_textureID;
    }
    std::string GetDir();
    std::string GetState();
    void isGround(){
        isOnGround = true;
        Jump = false;
         m_force = vec2f(0,0);
    m_velocity.y = 0;
    m_acceleration.y = 0;
    }
protected:

private:
    float m_Friction;
    bool m_key_Up= false;
    bool m_key_left= false;
    bool m_key_right= false;
    bool m_key_down = false;
    bool buttonDown = false;
    bool buttonUpDown = false;
    bool buttonUpDown2 = false;
    float buttonTimer = 0.0;
    bool Jump = true;
    bool canJump() {return (isOnGround && !Jump);}
    bool isOnGround = false;
    int m_DirFlag =PLAYER::Move::MOVING_RIGHT;
    int m_StateFlag =PLAYER::OBJECT::IDLE;
    SDL_Point l_dX2;
};

class GameObject_PlayerCreater: public BaseCreater
{
public :
    SDLGameObject* CreateGameObject() const
    {
        return  new GameObject_Player();
    }
};

#endif // GAMEOBJECT_PLAYER_H

