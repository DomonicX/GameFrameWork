#ifndef ANIMATION_H
#define ANIMATION_H
#include <string.h>
#include <iostream>
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <Vector2D.h>

/**<
                    (vec2f Size,int TileSize,float FrameRate, int Style)
    ani = Animation(vec2f(256,16),16,16/(float)60,ANIMATION_HORIZONTAL);
    ______________

    ani.Update(dt);
    ______________
    SDL_Rect SpriteRect =  ani.GetCurrentTile();
    TextureManager::Instance()->Draw(APP->GetRenderer(),"GUI_TileSheet",SpriteRect, {MOUSEPOSITION.x+16+16+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);

 */

enum
{
    ANIMATION_NONE,
    ANIMATION_HORIZONTAL,
    ANIMATION_VERTICAL,
    ANIMATION_BOX
}
typedef AnimationSpriteLayout;

class Animation
{
public:
    Animation();
    ~Animation();
    Uint32 currentFrame = 0;
    std::vector<SDL_Rect>Srect;
    void AddSrect(int x,int y,int h, int w);
    Uint32 maxFrame =0;
    void UpdateAnimation();
    Uint32 frameRate = 0;
    Uint32 oldTime = 0;

    SDL_Rect GetCurrentTile()
    {
        SDL_Rect f = {FramePos.x,FramePos.y,m_tileSize,m_tileSize};
        return f;
    }

    Animation(vec2f Size,int TileSize,float FrameRate, int Style) : m_size(Size), m_tileSize(TileSize),m_FrameRate(FrameRate),m_SpriteLayout(Style)

    {
        m_MaxTileW = m_size.x/m_tileSize;
        m_MaxTileH = m_size.y/m_tileSize;
     //   std::cout << "m_tileSize " << m_tileSize   << " m_MaxTileW " <<  m_MaxTileW << " m_MaxTileH " << m_MaxTileH << "\n";
        FramePos = vec2f(0,0);
        switch(m_SpriteLayout)
        {
        case ANIMATION_NONE:
            break;
        case ANIMATION_HORIZONTAL:
            break;
        case ANIMATION_VERTICAL:
            break;
        case ANIMATION_BOX:
            break;

        }
    }
    void Update(float dt)
    {
        m_dt+=dt;
        if(m_dt>=m_FrameRate)
        {
            m_dt = 0;
            FramePos.x+=m_tileSize;
            if(FramePos.x/m_tileSize>=m_MaxTileW)
                FramePos.x = 0;
        }
    }
    vec2f m_size;

    vec2f FramePos;
    float m_dt;
    float m_MaxTileW = 0;
    float m_MaxTileH = 0;
    SDL_FRect m_clip;
    int m_tileSize = 0;
    float m_FrameRate = 0;
    int m_SpriteLayout = ANIMATION_NONE;
protected:

private:
};

#endif // ANIMATION_H
