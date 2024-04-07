#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL2/SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>
class LTexture
{
public:
    LTexture();
    virtual ~LTexture();

    bool CreateBlankTexture(SDL_Renderer * renderer, int w,int h);
    bool LoadFromFile(SDL_Renderer* r,std::string path);
    bool LoadFromFile(SDL_Renderer* r,SDL_Color colourKey,std::string path);
    bool LoadFromFileandSave(SDL_Renderer* r,SDL_Color colourKey,std::string path,std::string Savepath);
    bool LoadFromRenderedText(SDL_Renderer* r,TTF_Font *f,std::string Text);
    bool LoadFromRendered(SDL_Renderer* r,int w = 0,int  h = 0,SDL_Colour Colour = {255,255,255},SDL_BlendMode blendMode = SDL_BLENDMODE_BLEND,Uint8 Alpha = 255);
    int QueyTexture();
    void Render(SDL_Renderer* r,float x, float y, SDL_Rect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip);
    void Render(SDL_Renderer* r,float x = 0,float y = 0, float angle = 0,SDL_FPoint* center = NULL);
    void Render(SDL_Renderer* r, SDL_Rect* screct = NULL,SDL_Rect* dsrect = NULL,double angle = 0,SDL_Point* center = NULL,SDL_RendererFlip flip = SDL_FLIP_NONE);
    void Render(SDL_Renderer* r, SDL_Rect* screct,SDL_FRect* dsrect,double angle,SDL_FPoint* center,SDL_RendererFlip flip);


    void Free();

    void SetColorMod(Uint8 red,Uint8 Green,Uint8 Blue);
    void SetBlendMode(SDL_BlendMode blending);
    void SetAlpha(Uint8 Alpha);

SDL_Color GetColorMod(){
SDL_GetTextureColorMod(m_texture,&m_colour.r,&m_colour.b,&m_colour.g);
return m_colour;}
int SDLS_getpixels(SDL_Renderer* r,Uint32* pixels, int w, int h);
    SDL_Colour GetColour();
    SDL_Texture* GetSDLTexture();

    Uint8 GetAlpha();
    int GetWidth();
    int GetHeight();
SDL_Surface *m_surfacePixels ;
Uint32*  GetPixels32();
Uint32  GetPitch32();
    //pixel manipulatiors
    bool lockTexture();
    bool unlockTexture();

protected:

private:

//the actual hardware Texture
    SDL_Texture* m_texture = NULL;
    SDL_Surface *surf= NULL;
    void *m_pixels= NULL;
    int m_pitch;


    SDL_Colour m_colour;
    Uint8 m_aplha;
    std::string m_filePath;
    int m_width;
    int m_height;

    //Text Data
    int iW,iH;

};

#endif // LTEXTURE_H
