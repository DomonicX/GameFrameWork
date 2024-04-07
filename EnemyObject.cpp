#include "EnemyObject.h"
#include <CollisionManager.h>
EnemyObject::EnemyObject()
{
    m_bisAtEnd =false;
    m_bDead = false;
    vec2f m_tempos= vec2f(0,0);
    vec2f m_tempos2 = vec2f(0,0);
    m_width =  m_width;
    m_height = m_height;
    m_currentFrame = 0;
    m_frameRate  = 100;
    m_numFrame = 8;
    m_acceleration = vec2f(-0.001,0.1);
    m_position = vec2f(0,0);
//    m_target = vec2f(0,0);
m_hit = false;
    m_life = 100;
    m_speed = 2;
    m_currentPath = 1;
    m_angle= 0;
    m_MaxLife = m_life;
    m_life = 50;
}

EnemyObject::~EnemyObject()
{
    //  std::cout << "deleting Enemy\n";
    //dtor
}

void EnemyObject::Load(char* filename)
{



    m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);
    ifs >>  m_textureID;
    ifs >> m_width;
    ifs >> m_height;
    ifs >> r >> g >> b >> a;
    ifs >> m_srcRect.x >> m_srcRect.y >> m_srcRect.w >> m_srcRect.h;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_speed ;
    ifs >> m_life ;
    ifs.close();
    m_speed = 2;

    m_numOfBars = m_life/(m_MaxLife*0.1);
}

void EnemyObject::Collision()
{
    if(!m_life)
        m_bDead = true;
     m_hit = true;


}
void EnemyObject::Update()
{
SDL_Rect hpbar;
hpbar.x = m_position.x-12;
hpbar.y = m_position.y-24;
hpbar.w = 10;
hpbar.h = 10;
//std::cout << "nd "<< (int)m_numOfBars<< "\n";
}

void EnemyObject::Render()
{

// TextureManager::Instance()->SetColour(0,255,0,0,Game::Instance()->GetRenderer());
//
//        for(int i = 0 ; i < m_numOfBars ; i++)
//        {
//
//            TextureManager::Instance()->DrawRectFilled((m_position.x-12 ),m_position.y-24,10,4,Game::Instance()->GetRenderer());
//
//        }
    if(!Dead())
    {
        if(m_life<=m_MaxLife*0.6)
        {
            TextureManager::Instance()->SetColour(255,242,0,255,Game::Instance()->GetRenderer());
            if(m_life<=m_MaxLife*0.3)

                TextureManager::Instance()->SetColour(255,0,0,255,Game::Instance()->GetRenderer());


        }
        else
            TextureManager::Instance()->SetColour(0,255,0,0,Game::Instance()->GetRenderer());

        TextureManager::Instance()->DrawRectFilled(m_position.x-12,m_position.y-24,m_life/10,3,Game::Instance()->GetRenderer());

        TextureManager::Instance()->SetColour(r,g,b,a,Game::Instance()->GetRenderer());
if(OnHitEvent())
    {   TextureManager::Instance()->SetColour(r-60,g-60,b-60,a,Game::Instance()->GetRenderer());

m_hit = false; }
        TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());

    }


}
     std::string EnemyObject::Texture(){return m_textureID;}
void EnemyObject::UpdatePath(std::vector<vec2f*> pathPos)
{
    if(m_currentPath==pathPos.size()-1)
    {
        m_bisAtEnd = true;
        m_position = *pathPos[1];
        m_currentPath = 1;
    }
    else m_bisAtEnd = false;
    if(m_currentPath+1<pathPos.size())
    {
        if(m_position.Dist( *pathPos[m_currentPath+1])>1)
        {
            vec2f m_posS  = m_position;
            vec2f m_pos = m_posS-*pathPos[m_currentPath+1];
            m_position -=m_pos.Normalise() *m_speed;
        }
        else
        {
            m_currentPath++;
        }

    }

}


bool EnemyObject::IsAtEnd()
{


    if(m_bisAtEnd)
    {
        return true;
    }
    else return m_bisAtEnd;
}
void EnemyObject::SetLife(int life)
{
    m_life -= life;
    if(!m_life) m_life = 0;
}
void EnemyObject::SetTarget(std::vector<vec2f*> pathPos)
{
}


//     m_pathPos = pathPos;
//
//    if(m_currentPath==m_pathPos.size()-1)
//    {
//        m_position = *m_pathPos[1];
//
//        m_currentPath = 1;
//
//    }
//    if(m_currentPath+1<m_pathPos.size())
//    {
//        if(m_position.Dist( *m_pathPos[m_currentPath+1])>1)
//        {
//            vec2f m_posS  = m_position;
//            vec2f m_pos = m_posS-*m_pathPos[m_currentPath+1];
//            m_position -=m_pos.Normalise() *m_speed;
//        }
//        else
//        {
//            m_currentPath++;
//        }
//
//    }

//   if(m_bcollision)
//    {

//   }
//    if(m_currentPath)
//    m_bDead = false;
//if(m_currentRow==m_pathPos.size()-1)
//        m_bDead = true;



// CollisionManager::Instance()->add(this);
// m_bcollision = true;
// std::cout << "Collision\n";
//m_bcollision = false;

//m_position-= vec2f(0,48);
//  TextureManager::Instance()->SetColour(0,0,0,a,Game::Instance()->GetRenderer());

//TextureManager::Instance()->DrawTarget2(m_textureID,m_currentFrame,0,m_position.x-12,m_position.y-12,m_width,m_height,Game::Instance()->GetRenderer(),m_angle,SDL_FLIP_NONE);

//        m_angle +=2;
//        m_tempos = m_position;
//    m_tempos=  m_position;
//    m_tempos2 =  *m_pathPos[m_currentPath+1];

//render comment
// TextureManager::Instance()->DrawTarget(m_textureID,m_currentFrame,0,m_position.x-12,m_position.y-12,m_width,m_height,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);
//  TextureManager::Instance()->DrawFrame(m_textureID,0,0,24,24,0,0,Game::Instance()->GetRenderer(),0,0,SDL_FLIP_NONE);
// TextureManager::Instance()->Draw(m_textureID,0,0,24,24,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);

//logic comment
//  m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame));
//  std::cout << Game::Instance()->GetDeltaTime() << "sssss\n";
//m_velocity = m_acceleration += SDL_GetTicks()/1000;
//  m_position+=m_velocity;
//    if(m_position.y>400)
//    {
////
//        m_position.y = 0;
//        m_position.x = Game::Instance()->getRandomNumber()%550;
//
//    }

//        m_tempos = m_position;
//    m_tempos=  m_position;
//    m_tempos.Normalise();
//    m_tempos2 =  *m_pathPos[m_currentPath+1];
//    m_tempos2.Normalise();
//
//    vec2f m_Nd = m_tempos-m_tempos2;
//    std::cout << "nd "<< m_Nd.Length()<< "\n";
//
//     m_angle+=  m_Nd.Length();
