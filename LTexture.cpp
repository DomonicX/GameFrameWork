#include "LTexture.h"
LTexture::LTexture() : m_texture(NULL),
    surf(NULL),
    m_pixels(NULL) {}
LTexture::~LTexture()
{
    Free();
}

void LTexture::Free()
{
    SDL_DestroyTexture(m_texture);
    if(m_pixels!=NULL)
    {
        delete m_pixels;
    }
}
bool LTexture::CreateBlankTexture(SDL_Renderer * renderer, int w,int h)
{




    m_texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, w, h);



    unsigned char* pixels;
    int pitch;


    if(!SDL_LockTexture( m_texture, NULL, (void**)&pixels, &pitch ));

// set pixels to solid white
    for(int i = 0; i < pitch * h; i++)
    {
        pixels[i] = 255;
    }





}
//
//    bool  LTexture::CreateBlankTexture(SDL_Renderer * renderer,
//                                                        Uint32 format,
//                                                        int access, int w,
//                                                        int h)
//
bool LTexture::LoadFromFile(SDL_Renderer* r,std::string path)
{
    return LoadFromFile(r, {255,0,255,0},path);
}
bool LTexture::LoadFromFileandSave(SDL_Renderer* r,SDL_Color colourKey,std::string path,std::string Savepath)
{
    SDL_Colour C = {colourKey.r,colourKey.g,colourKey.b,colourKey.a};
    m_filePath = path;
    SDL_Surface * temp = IMG_Load(path.c_str());
    SDL_SetColorKey( temp, SDL_TRUE, SDL_MapRGB( temp->format,C.r,C.g,C.b));
    IMG_SavePNG(temp,(Savepath.c_str()));
    m_texture = SDL_CreateTextureFromSurface(r,temp);

    if(m_texture==NULL)
    {
        SDL_free(temp);
        return false;
    }
    SDL_free(temp);

    QueyTexture();
    return true;

}
bool  LTexture::LoadFromFile(SDL_Renderer* r,SDL_Color colourKey,std::string path)
{
    m_filePath = path;
    SDL_Surface * temp = IMG_Load(path.c_str());
    SDL_SetColorKey( temp, SDL_TRUE, SDL_MapRGB( temp->format,colourKey.r,colourKey.g,colourKey.b));
    m_texture = SDL_CreateTextureFromSurface(r,temp);
    SDL_free(temp);

    if(m_texture==NULL)
    {
        SDL_free(temp);
        return false;
    }
    QueyTexture();
    return true;

}

bool LTexture::LoadFromRenderedText(SDL_Renderer* r,TTF_Font *f,std::string Text)
{
    if(surf!=NULL)
    {
        SDL_FreeSurface(surf);
    }
    if(m_texture!=NULL)
    {
        SDL_DestroyTexture(m_texture);
    }

    if(Text=="")
    {
        return false;
    }
    surf =  TTF_RenderText_Blended(f,Text.c_str(),SDL_Color{0,0,0,0});
    if(surf==nullptr)
    {

        return false;
    }
    m_texture = SDL_CreateTextureFromSurface(r,surf);
    if(m_texture==nullptr)
    {
        SDL_FreeSurface(surf);
        return false;
    }
    SDL_QueryTexture(m_texture,NULL,NULL,&m_width,&m_height);

//    SDL_RenderCopyEx(render,texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);

    SDL_FreeSurface(surf);
    return true;
}
bool  LTexture::LoadFromRendered(SDL_Renderer* r,int w,int  h,SDL_Colour Colour,SDL_BlendMode blendMode,Uint8 Alpha)
{
    m_aplha = Alpha;
    m_colour = Colour;
    m_width = w;
    m_height = h;
    SDL_Rect Size = {0,0,m_width,m_height};

    surf =   SDL_CreateRGBSurface(0,m_width,m_height,32,0,0,0,0);

    if(surf==NULL)
    {
        return false;
    }
    SDL_FillRect(surf,&Size, SDL_MapRGBA(surf->format,Colour.r,Colour.g,Colour.b,Colour.a));
    m_texture = SDL_CreateTextureFromSurface(r,surf);
    if(m_texture==NULL)
    {
        SDL_FreeSurface(surf);
        return false;
    }
    // m_pixels = GetPixels32();

    //  m_pitch = GetPitch32() * surf->h;

    SDL_SetTextureBlendMode(m_texture,blendMode);
    SDL_SetTextureColorMod(m_texture,m_colour.r,m_colour.g,m_colour.b);
    SDL_SetTextureAlphaMod(m_texture,m_aplha);
    SDL_FreeSurface(surf);

    return true;
}
void  LTexture::Render(SDL_Renderer* r,float x,float y, float angle,SDL_FPoint* center)
{
    SDL_FRect pos {x,y,m_width,m_height};
    SDL_RenderCopyExF(r,m_texture,NULL,&pos,angle,center,SDL_FLIP_NONE);
}

void  LTexture::Render(SDL_Renderer* r, SDL_Rect* screct,SDL_Rect* dsrect,double angle,SDL_Point* center,SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(r,m_texture,screct,dsrect,angle,center,flip);
}
int LTexture::QueyTexture()
{
    return SDL_QueryTexture(m_texture,NULL,NULL,&m_width,&m_height);
}
void LTexture::SetColorMod(Uint8 red,Uint8 Green,Uint8 Blue)
{
    SDL_SetTextureColorMod(m_texture,red,Green,Blue);
}

void LTexture::SetBlendMode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(m_texture,blending);
}

void LTexture::SetAlpha(Uint8 Alpha)
{
    m_aplha = Alpha;
    SDL_SetTextureAlphaMod(m_texture,m_aplha);
}

void  LTexture::Render(SDL_Renderer* r, SDL_Rect* screct,SDL_FRect* dsrect,double angle,SDL_FPoint* center,SDL_RendererFlip flip)
{
    SDL_RenderCopyExF(r,m_texture,screct,dsrect,angle,center,flip);

}
void LTexture::Render(SDL_Renderer* r,float x, float y, SDL_Rect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip)
{

    SDL_FRect dsrect = {x,y,m_width,m_height};
    SDL_Rect l_clip = {clip->x,clip->y,clip->w,clip->h};
    if(clip!=NULL)
    {
        dsrect.w = clip->w;
        dsrect.h = clip->h;
    }
    SDL_RenderCopyExF(r,m_texture,&l_clip,&dsrect,angle,center,flip);
}

SDL_Texture* LTexture::GetSDLTexture()
{
    return m_texture;
}
int LTexture::GetWidth()
{
    return m_width;
}

int LTexture::GetHeight()
{
    return m_height;
}

Uint8 LTexture::GetAlpha()
{
    return m_aplha;
}

SDL_Colour LTexture::GetColour()
{
    return m_colour;
}
bool LTexture::lockTexture()
{
    bool Success = true;
//    SDL_LockTexture(m_texture);
    //  SDL_GetError();
};
bool LTexture::unlockTexture()
{
    SDL_UnlockTexture(m_texture);
};
int LTexture::SDLS_getpixels(SDL_Renderer* r,Uint32* pixels, int w, int h)
{
    int res;
    int width=w;//, height=h;
    //SDL_RenderGetLogicalSize(ren,&width,&height);
    //printf("%d %d\n",width,height);
    res = SDL_RenderReadPixels(r,NULL,SDL_PIXELFORMAT_ARGB8888,pixels,width*sizeof(Uint32));
    if (res<0)
    {
        fprintf(stderr,"Erreur getpixels : %s\n",SDL_GetError());
        return -1;
    }
    return 0;
}
Uint32*  LTexture::GetPixels32()
{

    Uint32 * pixels = NULL;
    if(m_surfacePixels != NULL)
    {
        pixels = static_cast<Uint32*>(m_surfacePixels->pixels);
    }
    return pixels;
}
Uint32  LTexture::GetPitch32()
{
    Uint32 m_pitch = 0;
    if(m_surfacePixels != NULL)
    {
        m_pitch = m_surfacePixels->pitch / 4;
    }
    return m_pitch;

}
