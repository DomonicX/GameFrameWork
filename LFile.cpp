#include "LFile.h"

LFile::LFile()
{
    //ctor
}

LFile::~LFile()
{
    //dtor
}

void  LFile::ChangeData(std::string NewData)
{
    m_FileData.str("");
    m_FileData.clear();
    m_FileData << NewData;
}
bool LFile::ReadTxtFile(std::string FileName,std::string BasePath)
{
    std::cout << "FileName <"<< FileName<< "> : good\n";
    std::cout << "BasePath <"<< BasePath<< "> : good\n";
    m_FileName  = FileName;
    std::ifstream ifs;
    std::string ss = std::string{BasePath+FileName};
    ifs.open(ss, std::ifstream::in);
 if(ifs.bad())
 {
     return false;
 }
    if(ifs.good())
        std::cout << "ifstream loaded "<< FileName<< " : good\n";
    if(ifs.fail())
    {
        return false;
        std::cout << "fail\n";

    }

    if(ifs.bad())
    {
        return false;
        std::cout << "bad\n";
    }
    while(!ifs.eof())
    {
        std::string l_readString;
        l_readString = ifs.get();

    if(ifs.eof())
{
    break;
}
        m_FileData << l_readString;

    }
//    if(m_FileData.str()!="")
      //  m_FileData.str().pop_back();
//std::cout << m_FileData.str() << " : " << m_FileName << "\n";
    ifs.close();
    return true;
}

bool LFile::OutPutTxtFile(std::string FileName,std::string BasePath)
{
    std::ofstream ofs;

    ofs.open(BasePath+FileName,std::ofstream::out);

    ofs << m_FileData.str().c_str();

    ofs.close();
}

