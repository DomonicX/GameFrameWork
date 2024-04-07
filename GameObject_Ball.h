#ifndef GAMEOBJECT_BALL_H
#define GAMEOBJECT_BALL_H


#include <SDLGameObject.h>
#include <Application.h>
#include <TextureManager.h>
#include <SoundManager.h>
#include <GameObjectFactory.h>
class GameObject_Ball  : public SDLGameObject
{
public:
    GameObject_Ball();
    virtual ~GameObject_Ball();
    void Load(std::string FileName);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Update(float dt);
    void Clean() ;
    void Collision(GameObject* g);
    void Collision();
    void HandleEvent(SDL_Event& e );
    void FlipXspeed();
    void FlipYspeed();

    bool isVisable(){return m_isVisable;}
    int GetWallHitCounter();
    std::string     Type()
    {
        return "BreakOut_Ball";
    };
    std::string   Texture()
    {
        return m_textureID;
    };

    bool m_clicked_D = false;
    bool m_clicked_A = false;

//        return "BreakOut_Ball";
//    }
private: bool m_isVisable;
    SDL_Rect m_boarder;
    int speedX,speedY = 0;
    int wallHitCounter =0;
};
class GameObject_BallCreater: public BaseCreater
{
public :
    SDLGameObject* CreateGameObject() const
    {
        return  new GameObject_Ball();
    }
};

#endif // GAMEOBJECT_BALL_H
//
//class foo()
//{
//
//};
