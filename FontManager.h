#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <map>
#include <string.h>
#include <iostream>
class FontManager
{
public:
    static FontManager* Instance()
    {
        if(s_pInstance == NULL)
        {
            s_pInstance = new FontManager();
            return s_pInstance;
        }
        return s_pInstance;
    } void SetSize(std::string FontType,int PtSize);
    SDL_Rect QueryText(std::string message,std::string FontType);
    bool LoadFont(std::string FilePath,std::string name);
    TTF_Font* GetFont(std::string name = " ");
    int GetFontSize(std::string name);
    void Close();
    int GetSize()
    {
        return  m_fonts.size();
    }
protected:

private:

    FontManager() {}
    ~FontManager() {}
    std::map<std::string, TTF_Font *>m_fonts;
    static FontManager* s_pInstance;
};
#define fontManager FontManager::Instance()

#endif // FONTMANAGER_H
