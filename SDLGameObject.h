#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <SDL2/SDL_image.h>
#include <GameObject.h>
#include <InputHandler.h>
#include <TextureManager.h>


class SDLGameObject : public GameObject
{
protected:
    bool m_isVisable = false;
    bool m_isIgnoreCamera = false;
    bool m_isAnimated= false;
    bool m_isbFilled= false;
    bool m_isStaticSprite = false;

    float m_lifeTime = 255;

    float m_speed = 0.0f;
    float m_velocityMax = 0;
    float m_mass = 0.0f;
    float m_gravity = 0.0f;
    float m_angle = 0.0;

    int m_currentFrame = 0;
    int m_frameRate = 0;
    int  m_numFrame = 0;

    Transform& GetTransform(){return m_orientation;}
    SDL_FPoint m_centerOfMass = {0,0};
    SDL_RendererFlip  m_flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
    SDL_Rect m_srcRect = {0,0,0,0};
    SDL_FRect m_desRect = (SDL_FRect){0,0,0,0};
    SDL_Color m_colour;


    vec2f m_velocity= vec2f(0,0);
    vec2f m_acceleration= vec2f(0,0);
    vec2f m_force= vec2f(0,0);
    vec2f m_lastPos= vec2f(0,0);
    vec2f m_grsavity ;

    std::string m_textureID = " " ;
    std::string m_filename;

public:
    SDLGameObject();
    void updatePositionWithMouse();
    virtual ~SDLGameObject() {};
    virtual void Load(std::string FileName);
    virtual void Update();
    virtual void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    virtual void Clean() ;
    virtual void Collision() ;
     bool m_collision = false;

     bool isVisable() { return !m_isDead;}
    virtual std::string Type();
    virtual std::string Texture();
    virtual void HandleEvent(SDL_Event& e );
    void SetIgnoreCamera(bool isIgnoreCamera)      {m_isIgnoreCamera = isIgnoreCamera;}
    SDL_Rect GetSDLRect()                            {return {GetPosition().x,GetPosition().y,getWidth(),getHeight()};}
     SDL_FRect GetSDLRectF()                         {return {GetPosition().x,GetPosition().y,getWidth(),getHeight()};}
     SDL_Rect GetsrcRect()                          {return m_srcRect;}
   vec2f GetCentre()                            {return vec2f(GetPosition().x+getWidth()/2,GetPosition().y+getHeight()/2);}
    vec2f& GetVelocity()                             {return m_velocity;}
    vec2f& GetAcceleration()                         {return m_acceleration;}
    vec2f& GetlastPosition()                         {return m_lastPos;}
    vec2f& GetForce()                                {return m_force;}
    float& GetMass()                                 {return m_mass;}
    float& GetGravity()                              {return m_gravity;}
    float& GetSpeed()                                {return m_speed;}
    float& GetAngle()                                {return m_angle;}
    float& GetMaxVelocity()                          {return m_velocityMax;}
    float& GetLifeTime()                             {return m_lifeTime;}
    SDL_FPoint& GetCenterOfMass()                             {return m_centerOfMass;}

bool isIgnoreCamera()                            {return m_isIgnoreCamera; }
    std::string toString()                           {std::stringstream a ; a << "Pos " << GetPosition() << "Vel" << GetVelocity() << "Acc" << GetAcceleration() << "\n"; return a.str();}
    SDL_Color& GetColour()                           {return m_colour;}

   bool m_bCollision = false;
    void setTexture(std::string tex)  {m_textureID = tex;}
    void SetsrcRect(SDL_Rect src)  {m_srcRect= src;}
    void SetCenter(vec2f CenterPos) {m_position = CenterPos-vec2f(getWidth(),getHeight())/(float)2; }

//private:{10,10,100,100},false,false,10,10,10,90,"MarioPayer"," jjj"," dd")


};

//class  SDLGameObjectCreater : public BaseCreater
//{
//public :
// GameObject* CreateGameObject() const
//    {
//        return  new SDLGameObject() ;
//    }
//
//};


#endif // SDLGAMEOBJECT_H
