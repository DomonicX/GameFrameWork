#ifndef GUIFACTORY_H
#define GUIFACTORY_H


#include <map>
#include <iostream>
#include <iterator>
#include <string.h>
#include <GUI_Wigdet.h>
class GUIBaseCreater;
class GUIFactory
{
public:
    static GUIFactory* Instance()
    {
        if(s_pInstance==NULL) s_pInstance = new GUIFactory();
        return s_pInstance;
    }
    bool registerType(std::string typeID, GUIBaseCreater* pCreator);
    GUI_Wigdet* Create(std::string typeID);
    void Close();
    int GetSize()
    {
        return (int)m_creator.size();
    }
protected:


private:
    GUIFactory() {}
    virtual ~GUIFactory() {}
    std::map<std::string,GUIBaseCreater*>m_creator;
    static GUIFactory* s_pInstance;
protected:

private:
};

class GUIBaseCreater
{
public :
    virtual GUI_Wigdet* CreateGUIObject() const = 0;
    virtual ~GUIBaseCreater()
    {

    }
};

#define  guiFactory GUIFactory::Instance()
#endif // GUIFACTORY_H
