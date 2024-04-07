#ifndef MARIOENEMY_H
#define MARIOENEMY_H


#include <string.h>
#include <SDLGameObject.h>
class IMarioEnemyState;
typedef enum
{
    GREENTURTLE,REDTURTLE,BLUETURTLE,
    GOOMBA,BLUEGOOMBA,GREYGOOMBA,
    MANEATINGPLANT,GREYMANEATINGPLANT,
    HAMMERTHROWTURTLE,GREYHAMMERTHROWTURTLE,
    BROWSER
}   MarioEnemyType;

class MarioEnemy : public SDLGameObject
{
public:
    MarioEnemy();
    virtual ~MarioEnemy();
    void Load(char* filename) ;
    void Update();
    void Render();
    void Clean() {}
    void Collision() {}
    int getWidth();
    std::string Type();
    int getHeight();
    void Turn();
    bool iSFacingRight();

    void SetEnemyState(std::string  enemyType);
    IMarioEnemyState* GetState()
    {
        if(m_state!=NULL) return m_state;
    }
    void isOnGround()
    {
        m_bisGrounded= true;
    }

    std::string Texture();
    void HandleEvent(SDL_Event& e ) {}
protected:

private:
    bool b_mFacingRight = true;
    bool m_bisGrounded;
    int m_EmenyState;
    std::string m_Enemytype;
    IMarioEnemyState* m_state;
};

class MarioEnemyObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioEnemy();
    }
};

class IMarioEnemyState
{
public:
    IMarioEnemyState();
    ~IMarioEnemyState();

    virtual std::string getState() = 0;
    virtual int GetHeight()=0;
    virtual int GetWidth()=0;
    virtual  std::string Texture() =0;
};

class GreenTurtle : public IMarioEnemyState
{
public:
    GreenTurtle();
    ~GreenTurtle();
    std::string getState()
    {
        return "GreenTurtle";
    }
    int GetHeight()
    {
        return 32;
    }
    int GetWidth()
    {
        return 16;
    }  std::string Texture()
    {
        return "GreenTurtle";
    }
};

class BlueTurtle : public IMarioEnemyState
{
public:
    BlueTurtle();
    ~BlueTurtle();
    std::string getState()
    {
        return "BlueTurtle";
    }
    int GetHeight()
    {
        return 32;
    }  int GetWidth()
    {
        return 16;
    } std::string Texture()
    {
        return "BlueTurtle";
    }
};

class RedTurtle   : public IMarioEnemyState
{
public:
    RedTurtle();
    ~RedTurtle();
    std::string getState()
    {
        return "RedTurtle";
    } int GetHeight()
    {
        return 32;
    }
    int GetWidth()
    {
        return 16;
    }
    std::string Texture()
    {
        return "RedTurtle";
    }
};
class Goomba      : public IMarioEnemyState
{
public:
    Goomba();
    ~Goomba();
    std::string getState()
    {
        return "Goomba";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 16;
    } std::string Texture()
    {
        return "Goomba";
    }
};
class BlueGoomba  : public IMarioEnemyState
{
public:
    BlueGoomba();
    ~BlueGoomba();
    std::string getState()
    {
        return "BlueGoomba";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 16;
    } std::string Texture()
    {
        return "BlueGoomba";
    }
};
class GreyGoomba  : public IMarioEnemyState
{
public:
    GreyGoomba();
    ~GreyGoomba();
    std::string getState()
    {
        return "GreyGoomba";
    }
    int GetHeight()
    {
        return 16;
    } int GetWidth()
    {
        return 16;
    }  std::string Texture()
    {
        return "GreyGoomba";
    }
};
class ManEatingPlant : public IMarioEnemyState
{
public:
    ManEatingPlant();
    ~ManEatingPlant();
    std::string getState()
    {
        return "ManEatingPlant";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 32;
    } std::string Texture()
    {
        return "ManEatingPlant";
    }
};
class GreyManEatingPlant : public IMarioEnemyState
{
public:
    GreyManEatingPlant();
    ~GreyManEatingPlant();
    std::string getState()
    {
        return "GreyManEatingPlant";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 32;
    } std::string Texture()
    {
        return "GreyManEatingPlant";
    }
};
class HammerThrowTurtle : public IMarioEnemyState
{
public:

//     //   m_EmenyState = HAMMERTHROWTURTLE;
//      SDL_Rect  m_srcRect = {0,0,16,32};
//       SDL_Rect m_desRect = {32,0,16,32};
//        bool m_isStaticSprite = true;
//       bool m_isAnimationSprite = false;
//    m_Type = "HammerThrowTurtle";
//
//        m_EmenyState = HAMMERTHROWTURTLE;
//      SDL_Rect  m_srcRect = {0,0,16,32};
//       SDL_Rect m_desRect = {32,0,16,32};
//        bool m_isStaticSprite = true;
//       bool m_isAnimationSprite = false;
    HammerThrowTurtle();
    ~HammerThrowTurtle();
    std::string getState()
    {
        return "HammerThrowTurtle";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 32;
    } std::string Texture()
    {
        return "HammerThrowTurtle";
    }

////   m_Type = "HammerThrowTurtle";
//
//        m_EmenyState = HAMMERTHROWTURTLE;
//      SDL_Rect  m_srcRect = {0,0,16,32};
//       SDL_Rect m_desRect = {32,0,16,32};
//        bool m_isStaticSprite = true;
//       bool m_isAnimationSprite = false;
};
class GreyHammerThrowTurtle : public IMarioEnemyState
{
public:
    GreyHammerThrowTurtle();
    ~GreyHammerThrowTurtle();
    std::string getState()
    {
        return "GreyHammerThrowTurtle";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 32;
    } std::string Texture()
    {
        return "GreyHammerThrowTurtle";
    }
};
class Browser : public IMarioEnemyState
{
public:
    Browser();
    ~Browser();
    std::string getState()
    {
        return "Browser";
    } int GetWidth()
    {
        return 16;
    }
    int GetHeight()
    {
        return 32;
    } std::string Texture()
    {
        return "Browser";
    }
};

#endif // MARIOENEMY_H
