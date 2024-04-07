#ifndef CAMERA_H
#define CAMERA_H

#include <Vector2D.h>
#include <SDL2/SDL.h>
#include <iostream>
class Camera
{
public:
    Camera() {};
    Camera(vec2f Pos,vec2f Size, float Scale):
        m_pos(Pos),m_WorldPos(vec2f(0,0)),
        m_Size(Size),m_WorldSize(vec2f(0,0)),
        m_scale(Scale),m_WorldScaler(Scale) {}
    virtual ~Camera() {};
    void Move(vec2f pos) ;
    vec2f GetPos() const
    {
        return m_pos;
    }
    vec2f GetSize() const
    {
        return m_Size;
    }
    vec2f GetCentre()
    {
        return vec2f(m_pos+m_Size/(float)2);
    }

    void SetCentre(vec2f Centre);
    void SetPos(vec2f Pos);
    void SetSize(vec2f Size);
    void SetScaler(float scale);

    vec2f GetVirtualCentre() ;
    void SetVirtualPos(vec2f Pos);
    void SetVirtualSize(vec2f Size);
    void SetVirtualScaler(float scale);

    float GetScaler() const
    {
        return m_scale;
    }
    SDL_Rect GetRect() const
    {
        return {m_pos.x,m_pos.y,m_Size.x,m_Size.y};
    }
    SDL_FRect GetRectF() const
    {
        return {m_pos.x,m_pos.y,m_Size.x,m_Size.y};
    }

    SDL_Rect GetWorldRect() const
    {
        return {m_WorldPos.x,m_WorldPos.y,m_WorldSize.x,m_WorldSize.y};
    }
    SDL_FRect GetWorldRectF() const
    {
        return {m_WorldPos.x,m_WorldPos.y,m_WorldSize.x,m_WorldSize.y};
    }

    rectangle GetRectangle() const
    {
        return {m_pos,m_Size};
    }
    rectangle GetWorldRectangle() const
    {
        return {m_WorldPos,m_WorldSize};
    }

    float GetWorldScaler() const
    {
        return m_WorldScaler;
    }
vec2f GetWorldPos() const
{
    return m_WorldPos;
}
vec2f GetWorldCentre()
{
    return (m_WorldPos+m_WorldSize/2);
}
vec2f GetWorldSize() const
{
    return m_WorldSize;
}
    vec2f m_WorldPos, m_WorldSize,m_pos,m_Size = vec2f(0,0);
    float m_scale,m_WorldScaler = 1;
    SDL_Rect temp;
     friend std::ostream& operator<< ( std::ostream& os, const Camera& c )
    {

        //std::fixed(os);
//  os   <<std::setprecision(0) <<" [" << c.x << "][" << c.y << "] " ;
        os   <<"[" << c.GetRect().x << "][" << c.GetRect().y <<
         "][" << c.GetRect().w << "][" << c.GetRect().h << "]  " << c.GetScaler();

        os   <<"\n[" << c.GetWorldRectF().x << "][" << c.GetWorldRectF().y <<
         "][" << c.GetWorldRectF().w << "][" << c.GetWorldRectF().h << "]  " << c.GetWorldScaler();
        return os;
    }
protected:



private:
};

#endif // CAMERA_H
