#include "FontManager.h"



FontManager  *FontManager::s_pInstance = 0;

TTF_Font* FontManager::GetFont(std::string FontType)
{
    return m_fonts[FontType];
}
void FontManager::Close()
{

    std::cout << m_fonts.size() << "  deleting font\n ";
    while(!m_fonts.empty())
    {


        auto itt = m_fonts.begin();
        TTF_CloseFont(itt->second);

        m_fonts.erase( m_fonts.begin()   );
    }
    m_fonts.clear();
}
int FontManager::GetFontSize(std::string name)
{
    return TTF_FontHeight(m_fonts[name]);
}
bool FontManager::LoadFont(std::string FilePath,std::string name)
{

    if(!m_fonts.empty())
    {
        if(m_fonts.find(name)==m_fonts.end())
        {
            m_fonts[name] = TTF_OpenFont(FilePath.c_str(),14);
            if( m_fonts[name]==nullptr)
            {
                std::cout << " FontManager :: loadFont Error1 \n";
                return false;
            }

        }
        else
        {
            std::cout << " FontManager :: loadFont Error2 \n";
            return false;
        }

    }
    else   m_fonts[name] = TTF_OpenFont(FilePath.c_str(),14);

    {
        if( m_fonts[name]==nullptr)
        {
            std::cout << " FontManager :: loadFont Error3 \n";
            return false;
        }
        else  return true;
    }
    return false;
}
 SDL_Rect FontManager::QueryText(std::string message,std::string FontType){

       if(message=="")
    {
        return {0,0,0,GetFontSize(FontType)};
    }
    int w;
    int h;
 TTF_SizeText(Instance()->m_fonts[FontType],message.c_str(),&w,&h);
    return {0,0,w,h};

    }
void FontManager::SetSize(std::string FontType,int PtSize)
    {

    TTF_SetFontSize(Instance()->GetFont(FontType),PtSize);

    }
