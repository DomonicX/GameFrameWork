#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
//   SDL_RENDERER_SOFTWARE = 0x00000001,         /**< The renderer is a software fallback */
//    SDL_RENDERER_ACCELERATED = 0x00000002,      /**< The renderer uses hardwareacceleration */
//    SDL_RENDERER_PRESENTVSYNC = 0x00000004,     /**< Present is synchronized with the refresh rate */
//    SDL_RENDERER_TARGETTEXTURE = 0x00000008     /**< The renderer supports
//          SDL_RendererFlags                                           rendering to texture */

class Render
{
public:
    Render(SDL_Window * window,int index, Uint32 flags);
    virtual ~Render();
    void ClearDisplay()
    {
        SDL_RenderClear(m_ren);
    }
//    void SetRenderScale(){SDL_RenderSetScale}
//    void SetRenderLogicalSize(){SDL_RenderSetLogicalSize}
//    void SetRenderViewport(){SDL_RenderSetViewport}
//SDL_RenderSetIntegerScale()


    void RenderPresent()
    {
        SDL_RenderPresent(m_ren);
    }

    SDL_Renderer& GetRender()
    {
        return *m_ren;
    }
    bool isRenderTargetSupported(){
 return    SDL_RenderTargetSupported(m_ren);}
protected:

private:
    void Close();
    SDL_Renderer *m_ren;
};

#endif // RENDER_H
