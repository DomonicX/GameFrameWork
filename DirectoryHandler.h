#ifndef DIRECTORYHANDLER_H
#define DIRECTORYHANDLER_H
#include <SDL2/SDL_filesystem.h>

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <map>
#include <vector>
#include <LFile.h>

class DirectoryHandler
{
public:
    static DirectoryHandler* Instance()
    {

        if(s_pInstance == 0)
        {

            s_pInstance = new DirectoryHandler();
        }
        return s_pInstance;
    }

    std::string GetFileBase() const
    {
        return m_AppFileBase;
    }

    void Clean()
    {
    std::cout << "Destorying DirectoryHandler\n";

    }
    void SetFileBase()
    {
    std::string str ("bin/Debug\\");
    std::string ss  = SDL_GetBasePath();
    ss.resize( ss.length()-str.length());
    m_AppFileBase = ss;

    m_AppFileAsset= m_AppFileBase + "asset\\";

    m_AppFileFont= m_AppFileBase + "font\\";

    m_AppFileImg= m_AppFileBase + "img\\";

    m_AppFileLevel= m_AppFileBase + "level\\";

    }
     void ChangeData(std::string ID,std::string NewData);
     bool Load(std::string fileName);
    bool Save(std::string fileName);
    std::map<std::string,LFile *> GetFileMap();
    bool ClearLFileMap(std::string id);

    std::string GetFileBase() {return m_AppFileBase;}
    std::string GetFileAsset() {return m_AppFileAsset ;}
    std::string GetFileImg(){return m_AppFileImg ;}
    std::string GetFileFont(){return m_AppFileFont ;}
    std::string GetFileLevel(){return m_AppFileLevel ;}




protected:
private:
    std::string m_AppFileBase;
    std::string m_AppFileAsset;
    std::string m_AppFileFont;
    std::string m_AppFileImg;
    std::string m_AppFileLevel;


    std::map<std::string,LFile*>m_FileMap;

    static DirectoryHandler * s_pInstance;
    DirectoryHandler();
    virtual ~DirectoryHandler();

};

#define  DIRECTORYHANDLER DirectoryHandler::Instance()
#endif // DIRECTORYHANDLER_H

