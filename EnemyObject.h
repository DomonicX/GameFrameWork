#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#include <SDL2/SDL.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <Game.h>
#include <Vector2D.h>
#include <TextureManager.h>

#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>



class EnemyObject: public GameObject
{
public:
   bool m_hit;


bool OnHitEvent(){return m_hit;};
     std::string Texture();
     EnemyObject();
     ~EnemyObject();
    void Load(char* filename);
    void Render();
    void Update();
    void Clean() {}
    void Collision();
    std::string m_textureID;
    std::string m_filename;
    std::string Type()
    {
        return  "Enemy";
    }    int getHeight()
    {
        return m_height;
    }
    int getWidth()
    {
        return m_width;
    }  vec2f& GetAcceleration()
    {
        return m_acceleration;
    }
    vec2f& GetVelocity()
    {
        return m_velocity;
    }
    void HandleEvent(SDL_Event& e ){}
    int m_height;
    int m_width;
    void SetTarget(std::vector<vec2f*> pathPos);
    void UpdatePath(std::vector<vec2f*> pathPos);
bool IsAtEnd();
          void  SetLife(int life);
    // m_pathPos = &pathPos ; m_target = Target;
protected:
private:
float m_numOfBars;
    SDL_Rect m_srcRect;
    SDL_Rect m_desRect;
    int m_currentPath;
    int m_life;
 bool m_bisAtEnd;
    int m_numFrame;
int m_MaxLife;

    int m_frameRate;
    int m_currentRow;
    int m_currentFrame;
    int m_startFrame;
    int m_lastFrame;
    int r,g,b,a;
    double m_angle;
    vec2f m_velocity;
    vec2f m_acceleration;
    char m_alpha = 0;
   // std::vector<vec2f*> m_pathPos;

};

class  EnemyObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new EnemyObject();
    }
};


#endif // ENEMYOBJECT_H

