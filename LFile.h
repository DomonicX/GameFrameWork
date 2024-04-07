#ifndef LFILE_H
#define LFILE_H


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
class LFile
{
    public:
        LFile();
        virtual ~LFile();

bool ReadTxtFile(std::string FileName,std::string BasePath);
bool OutPutTxtFile(std::string FileName,std::string BasePath);
void ChangeData(std::string NewData);
std::string  GetFileData() const {return m_FileData.str();}
std::string  GetFileName() const {return m_FileName;}

    protected:

    private:
        std::stringstream m_FileData;
        std::string m_FileName;
};
#endif // LFILE_H

/**<
    LFile b;
    b.ReadTxtFile("222.txt",DirectoryHandler::Instance()->GetFileBase());
    b.ChangeData("sds");
    std::cout << b.GetFileData() << "\n";
    b.OutPutTxtFile("222.txt",DirectoryHandler::Instance()->GetFileBase());

     */
