#ifndef GAMEOBJECTPARSER_H
#define GAMEOBJECTPARSER_H

#include <Vector2D.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>
class GameObjectParser
{
public:
    GameObjectParser();
    virtual ~GameObjectParser();

protected:

private:
};

class PaserGameObject
{
public :
    PaserGameObject(vec2f pos,
                    vec2f vel,
                    vec2f acc,
                    vec2f force,
                    vec2f lastPos,
                    float mass,
                    float grav,
                    bool isDead,
                    bool IgnoreCamera,
                    int height,
                    int width,
                    float speed)
        : m_position(pos),
          m_velocity(vel),
          m_lastPos(lastPos),
          m_acceleration(acc),
          m_force(force),
          m_mass(mass),
          m_gravity(grav),
          m_isDead(isDead),
          m_isIgnoreCamera(IgnoreCamera),
          m_height(height),
          m_width(width),
          m_speed(speed)
    {

        std::cout << "createdGameObject  Paser\n";
    }
    virtual void ToString()
    {


        std::cout <<"m_position "<<  m_position.x<< "\n";
        std::cout <<"m_velocity"<<  m_velocity.x<< "\n";
        std::cout <<"m_acceleration"<< m_acceleration.x<< "\n";
        std::cout <<"m_force " << m_force.x<< "\n";
        std::cout <<"m_lastPos"<< m_lastPos.x<< "\n";
        std::cout <<"m_mass "<< m_mass<< "\n";
        std::cout <<"m_gravity " << m_gravity<< "\n";
        std::cout <<"m_isDead  " << m_isDead<< "\n";
        std::cout <<"m_isIgnoreCamera "<< m_isIgnoreCamera<< "\n";
        std::cout <<"m_height  " << m_height<< "\n";
        std::cout <<"m_width " << m_width<< "\n";
        std::cout <<"m_speed  " << m_speed<< "\n\n\n\n";
    }
    ~PaserGameObject()
    {
        std::cout <<" deleting GameObjectPaser\n";
    }
    vec2f m_position;
    vec2f m_velocity;
    vec2f m_acceleration;
    vec2f m_force;
    vec2f m_lastPos;
    float m_mass;
    float m_gravity;
    bool m_isDead;
    bool m_isIgnoreCamera;
    int m_height;
    int m_width;
    float m_speed;
};

class PaserSDLGameObject
{
public :
    PaserSDLGameObject(SDL_Rect srcRect,
                       bool AnimationSprite,
                       bool isbFilled,
                       int isStaticSprite,
                       int currentFrame,
                       int  numFrame,
                       int frameRate,
                       std::string textureID,
                       std::string Type,
                       std::string filename)
        :
          m_srcRect( srcRect),
          m_isAnimationSprite(AnimationSprite),
          m_isbFilled(isbFilled),
          m_isStaticSprite(isStaticSprite),
          m_currentFrame(currentFrame),
          m_numFrame(numFrame),
          m_frameRate(frameRate),
          m_textureID(textureID),
          m_Type (Type),
          m_filename(filename)
    {

        std::cout <<"created SDLPaser\n";


    };

    void ToString()
    {
        std::cout <<"m_srcRect" << m_srcRect.x << "\n";
        std::cout <<"m_isAnimationSprite" << m_isAnimationSprite << "\n";
        std::cout <<"m_isbFilled" <<  m_isbFilled << "\n";
        std::cout << "m_isStaticSprite" << m_isStaticSprite << "\n";
        std::cout <<" m_currentFrame" << m_currentFrame << "\n";
        std::cout << "m_numFrame" << m_numFrame << "\n";
        std::cout <<"  m_frameRate"<< m_frameRate << "\n";
        std::cout <<"m_textureID" << m_textureID << "\n";
        std::cout <<" m_Type" << m_Type<< "\n";
        std::cout <<"m_filename" <<    m_filename << "\n\n\n";

    }


    ~PaserSDLGameObject()
    {
        std::cout <<" deleting SDLPaser\n";
    };




    bool m_isAnimationSprite;
    bool m_isbFilled;
    bool m_isStaticSprite;
    int m_currentFrame;
    int m_frameRate;
    int  m_numFrame;
    SDL_Rect m_srcRect;
    std::string m_textureID;
    std::string m_Type;
    std::string m_filename;
};



#endif // GAMEOBJECTPARSER_H
