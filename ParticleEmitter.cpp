#include "ParticleEmitter.h"
ParticleEmitter::ParticleEmitter(vec2f pos, vec2f vel,vec2f acc,vec2f endPoint, float  Size, SDL_Color c,  float alpha,float shape,float lifetime, float drag, float VarSpeed,float fuzziDegree,float emission ) :
    m_pos(pos),
    m_vel(vel),
    m_acc(acc),
    m_endPoint(endPoint),
    m_Size(Size),
    m_c(c),
    m_alpha(alpha),
    m_shape(shape),
    m_lifetime(lifetime),
    m_AliveCounter(lifetime),
    m_drag(drag),
    m_VarSpeed(VarSpeed)
    , m_spawnPos(pos)
    , m_spawnvel(vel)
    ,m_fuzziDegree(fuzziDegree)
    ,m_emission(emission)
{
// vec2f::Lerp(vec2f(),WindowOrigin*2,640)

};
ParticleEmitter::ParticleEmitter()
{
    //ctor
}

ParticleEmitter::~ParticleEmitter()
{
////    std::cout  << "~ParticleSystem\n";

    for(int i = 0; i < m_Particles.size(); i++)
    {
////    std::cout << "called " << i << "  " << &m_Particles[i]<< "\n";
        m_Particles.erase(m_Particles.begin()+i);

//        delete m_Particles[i];
    }
    m_Particles.clear();
}


void ParticleEmitter::Update(float dt)
{

    if(!m_Particles.empty())
    {
        if(!dead)
        {

            for(int i = 0 ; i < m_Particles.size(); i++)
            {
                m_Particles[i].Update(dt);

            }
        }
    }

    //       ee.m_acc = MOUSEPOSITION-ee.m_pos;
//        ee.m_acc.Normalise();
//        ee.m_acc *= 16;
//if(m_vel.x <= 0.9 && m_vel.x >= -0.9)
//{
////m_vel = m_spawnvel;
//}else
//{
////    m_vel *= m_drag;
//        m_vel += m_acc *(float) dt;
//
//        // m_vel.Truncate(16);
//
//        m_pos +=m_vel *(float) dt;
//        m_AliveCounter -=  1 * dt;
//        m_alphaCounter -= m_alpha * dt;
//
//        if(m_alphaCounter <= 0)
//        {
//
//    m_alphaCounter = m_alpha;
////       dead = true;
//        }
//            if(m_AliveCounter <= 0)
//            {
//
//            m_AliveCounter = m_lifetime;
//  m_vel = m_spawnvel;
//           m_pos = m_spawnPos;
//
//
//            }
//
//    }
}
void   ParticleEmitter::render(SDL_Renderer* r, std::string textureID,vec2f Offset, float Alpha,SDL_Color modColour)
{

    if(!dead)
    {
        for(int i = 0 ; i < m_Particles.size(); i++)
        {
            m_Particles[i].Render(r,textureID,Offset.x,Offset.y);

        }
    TextureManager::Instance()->DrawLine(r,line({m_pos,m_endPoint}),Colour_bisque);
    vec2f aa = vec2f::GetMidPoint(m_pos,m_endPoint);
    vec2f aa2 = aa.GetRotation(90);

vec2f ww = vec2f(m_endPoint-m_pos);
    TextureManager::Instance()->DrawVector(r,Offset+m_pos,Offset+ww,Colour_darkblue);
    TextureManager::Instance()->DrawVector(r,Offset+m_pos,Offset+vec2f(m_endPoint-m_pos).GetRotation(m_fuzziDegree),Colour_darkblue);
    TextureManager::Instance()->DrawVector(r,Offset+m_pos,Offset+vec2f(m_endPoint-m_pos).GetRotation(-m_fuzziDegree),Colour_darkblue);
    TextureManager::Instance()->Drawcircle(r,Offset.x+m_pos.x+Offset.x,m_pos.y+Offset.y,Colour_red,16,false);

//    TextureManager::Instance()->DrawVector(r,m_pos,vec2f(-std::cos(ww.y),std::sin(ww.x))*16,Colour_darkblue);
//    TextureManager::Instance()->DrawVector(r,m_pos,vec2f(-std::cos(ww.y),-std::sin(ww.x))*16,Colour_darkblue);
//        TextureManager::Instance()->SetColorMod(textureID,m_c);
//        TextureManager::Instance()->SetAhpla(textureID,m_alpha);
//
//        SDL_FRect desrect = {m_pos.x,m_pos.y,m_Size,m_Size};
//        desrect.x += Offset.x;
//        desrect.y += Offset.y;
//        if(m_Size<16)
//            m_Size = 16;
//        SDL_Rect srcrect = {0,0,m_Size,m_Size};
//        TextureManager::Instance()->SDLDraw(r,   textureID,
//                                            &srcrect,
//                                            &desrect,
//                                            0,
//                                            NULL,
//                                            SDL_FLIP_NONE);

    }


}
