#include "Camera.h"
void Camera::Move(vec2f pos)
{
    m_WorldPos += pos;

    if(m_WorldPos.x < m_pos.x ||  m_WorldPos.x > m_WorldSize.x- m_Size.x )
    {
        m_WorldPos.x -= pos.x;
    }
    if(m_WorldPos.y < m_pos.y || m_WorldPos.y  > m_WorldSize.y- m_Size.y)
    {
      m_WorldPos.y -= pos.y;
    }

}
void Camera::SetPos(vec2f Pos)
{
    m_pos = Pos;
}
void Camera::SetCentre(vec2f Centre)
{
    m_pos = Centre-m_Size/2;
}
void Camera::SetSize(vec2f Size)
{
    m_Size = Size;
}
void Camera::SetScaler(float scale)
{
    m_scale = scale;
}
    vec2f  Camera::GetVirtualCentre()  {return vec2f(m_WorldPos+m_WorldSize/2);}
void   Camera::SetVirtualPos(vec2f Pos){m_WorldPos = Pos;}
    void   Camera::SetVirtualSize(vec2f Size){m_WorldSize = Size;}
    void   Camera::SetVirtualScaler(float scale){ m_WorldScaler = scale;}
