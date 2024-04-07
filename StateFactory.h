#ifndef STATEFACTORY_H
#define STATEFACTORY_H



#include <map>
#include <iostream>
#include <iterator>
#include <string.h>
#include <GameState.h>

class StateBaseCreater
{
public :
    virtual GameState* CreateState() const = 0;
    virtual ~StateBaseCreater() {}
};



class StateFactory
{
public:
    static StateFactory* Instance()
    {

        if(s_pInstance==NULL) s_pInstance = new StateFactory();
        return s_pInstance;
    }
    int GetSize()
    {
        return m_creator.size();
    }
    bool registerType(std::string typeID, StateBaseCreater* pCreator);
    GameState* Create(std::string typeID);
    void Close();
protected:


private:
    StateFactory() {}
    virtual ~StateFactory() {}
    std::map<std::string,StateBaseCreater*>m_creator;
    static StateFactory* s_pInstance;
protected:

private:
};

#define  stateFactory StateFactory::Instance()


#endif // STATEFACTORY_H
