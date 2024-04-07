#include "GameObjectFactory.h"

GameObjectFactory *GameObjectFactory::s_pInstance = 0;

bool GameObjectFactory::registerType(std::string typeID, BaseCreater* pCreator)
{
    std::map<std::string,BaseCreater*>::iterator it = m_creator.find(typeID);

    if(it!=m_creator.end())
    {

        std::cout << "type already registered \n ";
        delete pCreator;
        return false;

    }
    m_creator[typeID] = pCreator;
    return true;
}
GameObject* GameObjectFactory::Create(std::string typeID)
{
    std::map<std::string,BaseCreater*>::iterator it = this->Instance()->m_creator.find(typeID);
    if(it == m_creator.end())
    {

        std::cout << "could not find " << typeID << "\n";
        return NULL;
    }
    BaseCreater *pCreater = (*it).second;
    return pCreater->CreateGameObject();
}


void GameObjectFactory::Close()
{
    std::cout << m_creator.size() << " m_creator deleting\n ";

    while(!m_creator.empty())
    {
        auto itt = m_creator.begin();

        BaseCreater* s = itt->second;

        delete s;

        m_creator.erase(m_creator.begin());
    }
    m_creator.clear();

}
