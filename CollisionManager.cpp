#include "CollisionManager.h"
CollisionManager  *CollisionManager::s_pInstance = 0;


CollisionManager::~CollisionManager()
{


    m_Object.clear();
}
void CollisionManager::Add(GameObject* o )
{
//    bool isAlreadyAdded = false;
//    if(m_Object.empty())
//    {
//
//        m_Object.push_back(o);
//
//    }
//    else
//    {
//
//        for(int i = 0 ; i < (int)m_Object.size(); i++)
//            if(m_Object[i]->GetPosition() == o->GetPosition())
//            {
//                isAlreadyAdded = true;
//
//            }
//
//        if(!isAlreadyAdded)
//        {
//
//
//        }
//
//    }
  m_Object.push_back(o);
}
bool CollisionManager::Check(GameObject* o)
{
   if(o==NULL)
    return false;
    vec2f aa = Application::Instance()->GetCamera().GetWorldPos();
    bool b = false;
    SDL_FRect o_rect = { o->GetPosition().x+aa.x,o->GetPosition().y+aa.y,o->getWidth(),o->getHeight()};
    for(int i = 0 ; i < m_Object.size(); i ++)
    {
   if(m_Object[i]==NULL)
     continue;
        if(m_Object[i]==o)
            continue;

        SDL_FRect objectRect = { m_Object[i]->GetPosition().x+aa.x,m_Object[i]->GetPosition().y+aa.y,m_Object[i]->getWidth(),m_Object[i]->getHeight()};
   if(!m_Object[i]->Dead() && !o->Dead())
        if(SDL_HasIntersectionF(&o_rect,&objectRect))
        {
//            std::cout << i << "  " << m_Object[i]->GetPosition() << "\n";
            b = true;
     //   m_Object[i]->Collision(o);
        }
    }
    return b;
}
bool CollisionManager::Checker(GameObject* o)
{

   if(o==NULL)
    return false;
    vec2f aa = Application::Instance()->GetCamera().GetWorldPos();
    bool b = false;
    SDL_FRect o_rect = { o->GetPosition().x+aa.x,o->GetPosition().y+aa.y,o->getWidth(),o->getHeight()};
    for(int i = 0 ; i < m_Object.size(); i ++)
    {
        if(m_Object[i]==o)
            continue;
        SDL_FRect objectRect = { m_Object[i]->GetPosition().x+aa.x,m_Object[i]->GetPosition().y+aa.y,m_Object[i]->getWidth(),m_Object[i]->getHeight()};
        if(!m_Object[i]->Dead() && !o->Dead())
            if(SDL_HasIntersectionF(&o_rect,&objectRect))
                b = true;

    }
    return b;
}
std::vector<GameObject*>  CollisionManager::check(GameObject* o)
{
   if(o==NULL)
    return std::vector<GameObject*>(NULL);
//    std::cout << o->Type() << "  " << o->GetPosition() << "\n";
    std::vector<GameObject*> temp;
    vec2f aa = Application::Instance()->GetCamera().GetWorldPos();
    bool b = false;
    SDL_FRect o_rect = { o->GetPosition().x+aa.x,o->GetPosition().y+aa.y,o->getWidth(),o->getHeight()};
    for(int i = 0 ; i < m_Object.size(); i ++)
    {

        if(m_Object[i]==o)
            continue;

        SDL_FRect objectRect = { m_Object[i]->GetPosition().x+aa.x,m_Object[i]->GetPosition().y+aa.y,m_Object[i]->getWidth(),m_Object[i]->getHeight()};
    if(!m_Object[i]->Dead() && !o->Dead())
        if(SDL_HasIntersectionF(&o_rect,&objectRect))
        {
          temp.push_back( m_Object[i]);
//            std::cout << m_Object[i]->Type() << "  " << m_Object[i]->GetPosition() << "\n";
      //   m_Object[i]->Collision();
        }
    }
    return temp;
}

std::vector<GameObject*>  CollisionManager::check(vec2f p)
{
    return std::vector<GameObject*>(NULL);
//    std::cout << o->Type() << "  " << o->GetPosition() << "\n";
    std::vector<GameObject*> temp;
    vec2f aa = Application::Instance()->GetCamera().GetWorldPos();
    bool b = false;
   SDL_FPoint o = {p.x+aa.x,p.y+aa.y};

    for(int i = 0 ; i < m_Object.size(); i ++)
    {
        SDL_FRect objectRect = { m_Object[i]->GetPosition().x+aa.x,m_Object[i]->GetPosition().y+aa.y,m_Object[i]->getWidth(),m_Object[i]->getHeight()};
    if(!m_Object[i]->Dead())
        if(SDL_PointInFRect(&o,&objectRect))
        {
          temp.push_back( m_Object[i]);
//            std::cout << m_Object[i]->Type() << "  " << m_Object[i]->GetPosition() << "\n";
      //   m_Object[i]->Collision();
        }
    }
    return temp;
}
std::vector<GameObject*> CollisionManager::FindResult()
{
    std::vector<GameObject*> temp;
    vec2f aa = Application::Instance()->GetCamera().GetWorldPos();
    bool b = false;
    for(int i = 0 ; i < m_Object.size(); i ++)
    {
        SDL_FRect objI = { m_Object[i]->GetPosition().x+aa.x,m_Object[i]->GetPosition().y+aa.y,m_Object[i]->getWidth(),m_Object[i]->getHeight()};

        for(int j = i ; j < m_Object.size(); j ++)
        {
            if(m_Object[j]==m_Object[i])
                continue;
            SDL_FRect objJ = { m_Object[j]->GetPosition().x+aa.x,m_Object[j]->GetPosition().y+aa.y,m_Object[j]->getWidth(),m_Object[j]->getHeight()};
    if(!m_Object[i]->Dead() && !m_Object[j]->Dead())
            if(SDL_HasIntersectionF(&objJ,&objI))
            {
                temp.push_back( m_Object[i]);
//             m_Object[i]->Collision( m_Object[j]);
//            std::cout << m_Object[i]->Type() << "  " << m_Object[i]->GetPosition() << "\n";
//         m_Object[i]->Collision();
    //     m_Object[j]->Collision();
            }
        }
    }
    return temp;
};
