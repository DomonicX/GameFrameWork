#ifndef LTEXT_H
#define LTEXT_H
#include <string.h>
#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <FontManager.h>

#include <math.h>
class LText
{
public:
    LText();
    LText(std::string text) : m_text(text){}
    virtual ~LText();
    void LoadFromRenderedText(SDL_Renderer* r,int x, int y);
    bool ChangeText(std::string NewText,TTF_Font *font,SDL_Renderer* r);
    void SetTextColour(SDL_Color c){m_textColour = c;
    }

void SetTextSize( int pxSize= 16 ) {m_textSize  = pxSize ;}
   SDL_Color GetTextColour(){return m_textColour;}
    SDL_Rect GetBounds();
SDL_Rect GetTextSize(std::string FontID);
void SetWrapped(int wrappedLength);

protected:

private:
    Uint32 m_wrapLength = 0;
    bool m_isWrapped = false;
    int m_textSize = 16;
 SDL_Rect m_box = {0,0,0,0};
SDL_Color m_textColour = {0,0,0};
    std::string m_text = "_";
    SDL_Texture* m_texture = NULL;
};

#endif // LTEXT_H
