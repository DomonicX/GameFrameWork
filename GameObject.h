#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <Vector2D.h>
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>
#include <SDL2/SDL.h>

typedef struct Transform
{
  vec2f position;
  vec2f rotation;
  vec2f scale;
};

class GameObject
{
public:

    virtual void Load(std::string FileName) = 0;
    virtual void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY) = 0;
    virtual void Update(float dt) = 0;

    virtual void Clean() =0;
    virtual void Collision() = 0;
    virtual void Collision( GameObject* g){};
    virtual std::string Type() = 0;
    virtual std::string Texture() = 0;
    virtual void HandleEvent(SDL_Event& e ) =0;
    int getHeight() const
    {
        return m_orientation.scale.y;
    }
    int getWidth() const
    {
        return m_orientation.scale.x;
    }
    vec2f& GetPosition()
    {
        return m_orientation.position;
    }
    void SetWidth(int w)
    {

        m_orientation.scale.x = w;
    }
    void SetHeight(int h)
    {
        m_orientation.scale.y = h;
    }
    bool Dead()
    {
        return m_isDead;
    }
    void SetDead(bool isDead)
    {
        m_isDead = isDead;
    }
    virtual  ~GameObject()
    {
    }
    GameObject()
    {

    }
protected:
Transform m_orientation;

    vec2f m_position= vec2f(0,0);
    bool m_isDead = false;
    int m_height = 0;
    int m_width = 0;
private:

};







#endif // GAMEOBJECT_H



//  bool m_bDying;
//        m_bDying(false)

//    void SetDying()
//    {
//        m_bDying = true;
//    }
//   bool Dying()
//    {
//        return m_bDying;
//    }

// bool m_bUpdating;

// m_bUpdating(false),
// int m_height;
////    int m_width;
//    int r,g,b,a;
//    double m_angle;
//    char m_alpha = 0;
//    std::string m_textureID;
//    std::string m_filename;


//      std::string& GettextureID()
//    {
//        return m_textureID;
//    }
//    std::string getFilePath()
//    {
//        return m_filename;
//    }

//        m_velocity(0,0),
//        m_acceleration(0,0),
// m_height(0),
//   m_width(0),
//        m_angle(0),
//        m_alpha(255),
//        r(0),g(0),b(0)
//    void setUpdating(bool updating)
//    {
//        m_bUpdating = updating;
//    }  bool updating()
//    {
//        return m_bUpdating;
//    }
//    void scroll(float scrollSpeed)
//    {
//        if(Type()!= "player")
//        {
//            m_position.x-=scrollSpeed;
//
//        }
//    }

//    int GetLastFrame()
//    {
//        return m_lastFrame;
//    }
//    int GetStartFrame()
//    {
//        return m_startFrame;
//    }

//    } int GetCurrentFrame()
//    {
//        return m_currentFrame;
//    }
//    virtual char Type()
//    {
//        return '_';
//    }
//    int GetCurrentRow()
//    {
//        return m_currentRow;
//    }
//        m_currentRow(0),
//        m_currentFrame(0),

//    int  m_Level;
//    int  m_cost;
//    int  m_dmg;
//    int  m_Range;

//    int m_numFrame;
//
//    int m_frameRate;
//    int m_currentRow;
//    int m_currentFrame;
//    int m_startFrame;
//    int m_lastFrame;
