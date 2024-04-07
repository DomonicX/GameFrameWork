#include "LText.h"

LText::LText()
{
}
LText::~LText()
{
    //dtor
    if(m_texture!=NULL)
        SDL_DestroyTexture(m_texture);
}

void LText::LoadFromRenderedText(SDL_Renderer* r,int x, int y)
{
    SDL_SetTextureColorMod(m_texture,m_textColour.r,m_textColour.g,m_textColour.b);
    if(m_text=="")
        return ;
    SDL_Rect m_desbox = {x,y,m_box.w,m_box.h};
    SDL_RenderCopyEx(r,m_texture,NULL,&m_desbox,0,NULL,SDL_FLIP_NONE);
    SDL_SetTextureColorMod(m_texture,255,255,255);

}

void  LText::SetWrapped(int wrappedLength)
{
    m_wrapLength = wrappedLength;
    if(wrappedLength==0)
   m_isWrapped = false;
    else  m_isWrapped = true;

}
bool LText::ChangeText(std::string NewText,TTF_Font *font,SDL_Renderer* r)
{
//TTF_SetFontStyle(font,TTF_STYLE_UNDERLINE);
    if(NewText=="")
    {
        return false;
    }
    if(NewText!=m_text)
    {
        m_text = NewText;

        if(m_texture!=nullptr)
        {
            SDL_DestroyTexture(m_texture);

        }
    TTF_SetFontSize(font,m_textSize);

        SDL_Surface *  surf;
        if(m_isWrapped)
            surf =  TTF_RenderText_Blended_Wrapped(font,NewText.c_str(), {255,255,255},m_wrapLength);
        else
            surf =  TTF_RenderText_Blended(font,NewText.c_str(), {255,255,255});
        if(surf==nullptr)
            return false;

        m_texture= SDL_CreateTextureFromSurface(r,surf);
        if(m_texture==nullptr)
        {
            SDL_FreeSurface(surf);
            return  false;

        }
//        SDL_FPoint textSize = {0,0};
// TTF_SizeText(font,m_text.c_str(),&textSize.x,&textSize.y); // this returns fucked up h for wrapped maybe call other one
        m_box = {0,0,surf->w,surf->h};
        SDL_FreeSurface(surf);
        return true;


    }




    return false;

}
SDL_Rect LText::GetBounds()
{
    return m_box;
}


SDL_Rect  LText::GetTextSize(std::string FontID)
{
    return FontManager::Instance()->QueryText(m_text,FontID);
}

/**<  m_isWrapped = true;

    if(wrappedLength==m_wrapLength)
       m_isWrapped = false;
    if(wrappedLength>=0)
      {m_isWrapped = false;
    m_wrapLength = wrappedLength;
      }

}
bool LText::ChangeText(std::string NewText,TTF_Font *font,SDL_Renderer* r)
{
//TTF_SetFontStyle(font,TTF_STYLE_UNDERLINE);
    if(NewText=="")
    {
        return false;
    }
    if(NewText!=m_text || !m_isWrapped)
//
//return;
//
//
//      m_texture = SDL_CreateTextureFromSurface(r,s);
//        if(Text==m_text)
//        {
//        SDL_RenderCopy(r,m_texture,&Screct,&desRect);
//            return;
//        }else
//        if(m_texture!=NULL)
//        {
//            SDL_DestroyTexture(m_texture);
//            m_text = "";
//        }
//
//        m_text = Text;
//
//      s = TTF_RenderText_Blended(f,m_text.c_str(),SDL_Color{0,0,0,0});
//      m_texture = SDL_CreateTextureFromSurface(r,s);
//
//
//
    int iW,iH = 0;
    if(Text=="")
    {
        return;
    }
      if(Text!=m_text)
   {
       m_text = Text;
    SDL_DestroyTexture(m_texture);
 SDL_Surface *surf =  TTF_RenderText_Blended(f,Text.c_str(),SDL_Color{255,255,255,255});
   m_texture= SDL_CreateTextureFromSurface(r,surf);
    if(m_texture==nullptr)

        std::cout << " 3 error \n";

    SDL_QueryTexture(m_texture,NULL,NULL,&iW,&iH);
    SDL_Rect ss = {x,y,iW,iH};

    SDL_RenderCopyEx(r,m_texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);

    SDL_FreeSurface(surf);
        return;

}
        SDL_QueryTexture(m_texture,NULL,NULL,&iW,&iH);
SDL_Rect ss = {x,y,iW,iH};
    SDL_RenderCopyEx(r,m_texture,NULL,&ss,0,NULL,SDL_FLIP_NONE); */
