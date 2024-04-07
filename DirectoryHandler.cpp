#include "DirectoryHandler.h"

DirectoryHandler *DirectoryHandler::s_pInstance = 0;

DirectoryHandler::DirectoryHandler()
{
    //ctor
}

DirectoryHandler::~DirectoryHandler()
{
    //dtor
}

bool DirectoryHandler::Load(std::string fileName)
{
    if(!m_FileMap.empty())
    {
        if(m_FileMap.find(fileName)==m_FileMap.end())
        {
    m_FileMap[fileName] = new LFile();

}else
 if(m_FileMap[fileName]->ReadTxtFile(fileName,m_AppFileBase))
{
    return true;
}
else
{
    delete m_FileMap[fileName];
    return false;

}
}
else
{
  m_FileMap[fileName] = new LFile();
  if(m_FileMap[fileName]->ReadTxtFile(fileName,m_AppFileBase))
{
    return true;
}
else
{
    delete m_FileMap[fileName];
    return false;

}

}

}
void  DirectoryHandler::ChangeData(std::string ID,std::string NewData)
{
    GetFileMap()[ID]->ChangeData(NewData);
}

bool DirectoryHandler::Save(std::string fileName)
{
//    m_FileMap[fileName] = new LFile();
    if(!m_FileMap.empty())
        if(m_FileMap.find(fileName)!=m_FileMap.end())
            m_FileMap[fileName]->OutPutTxtFile(fileName,m_AppFileBase);

    return true;

}


std::map<std::string,LFile *> DirectoryHandler::GetFileMap()
{
    return m_FileMap;
}
bool DirectoryHandler::ClearLFileMap(std::string id)
{

}
