#include "StateFactory.h"


StateFactory *StateFactory::s_pInstance = 0;

bool StateFactory::registerType(std::string typeID, StateBaseCreater* pCreator)
{
    m_creator[typeID] = pCreator ;
}

GameState* StateFactory::Create(std::string typeID)
{
    return m_creator[typeID]->CreateState();
}

void StateFactory::Close()

{

    std::cout << m_creator.size() << " deleting StateFactorycreator \n ";
    while(!m_creator.empty())
    {


        auto itt = m_creator.begin();

        StateBaseCreater* s = itt->second;
        delete s;

        m_creator.erase( itt);
    }
    m_creator.clear();
}
