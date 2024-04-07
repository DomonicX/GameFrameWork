#include "MarioMainMenuState.h"

MarioMainMenuState::MarioMainMenuState()
{
    //ctor
}

MarioMainMenuState::~MarioMainMenuState()
{
    //dtor
}

void MarioMainMenuState::Render()
{
    SDL_Rect l_desrect = {0,0,256,224};
    TextureManager::Instance()->SDLDraw(Application::Instance()->GetRenderer(),"marioMainMenu",&l_desrect,&l_desrect,0,0,SDL_FLIP_NONE);
    TextureManager::Instance()->SetColour(0,0,0,255,Application::Instance()->GetRenderer());

    SDL_Rect r =  TextureManager::Instance()->QueryText("1 PLAYER GAME",FontManager::Instance()->GetFont("OpenSans-Regular"),Application::Instance()->GetRenderer());
    vec2f pl1 = vec2f(Application::Instance()->GetWindowWidth()/2 - r.w/2,Application::Instance()->GetWindowHeight()/2- r.h/2);
    vec2f pl2 = pl1;
    pl2.y+=64;


//    TextureManager::Instance()->DrawText(sss,0,48,FontManager::Instance()->GetFont("OpenSans-Semibold"),Game::Instance()->GetRenderer());
    if(Val%2==0)
    {
        TextureManager::Instance()->DrawRect(pl1.x-64-r.w/4,pl1.y,64,64,Application::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("1 PLAYER GAME",pl1.x,pl1.y,FontManager::Instance()->GetFont("OpenSans-Semibold"),Application::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("2 PLAYER GAME",pl2.x,pl2.y,FontManager::Instance()->GetFont("OpenSans-Regular"),Application::Instance()->GetRenderer());

    }
    else
    {
        TextureManager::Instance()->DrawRect(pl2.x-64-r.w/4,pl2.y,64,64,Application::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("1 PLAYER GAME",pl1.x,pl1.y,FontManager::Instance()->GetFont("OpenSans-Regular"),Application::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("2 PLAYER GAME",pl2.x,pl2.y,FontManager::Instance()->GetFont("OpenSans-Semibold"),Application::Instance()->GetRenderer());


    }



}
void MarioMainMenuState::Update()
{

}
bool MarioMainMenuState::OnEnter() {

    SoundManager::Instance()->SetPlay("smb_main_theme",-1);
   // SoundManager::Instance()->PauseMusic();
   // SoundManager::Instance()->ResumeMusic();
return true;
}
bool MarioMainMenuState::onExit() {}
void MarioMainMenuState::resume() {}
void MarioMainMenuState::HandleEvent(SDL_Event &e )
{
    if(   e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_DOWN)
    {
        Val-=1;
    }
    if(   e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_UP)
    {
        Val+=1;
    }


    if(   e.type == SDL_KEYUP && e.key.keysym.scancode==SDL_SCANCODE_RETURN)
    {

       Application::Instance()->ChangeGameState(new MarioLevelState ());

    }
}

//  Game::Instance()->ChangeGameState(new MarioLevelState ());

   //Game::Instance()->ChangeGameState(new MarioLevelState ());

//    SDL_Surface* s = SDL_CreateRGBSurfaceWithFormat(0,Game::Instance()->GetWindowWidth(),
//                     Game::Instance()->GetWindowHeight(),
//                     32, SDL_PIXELFORMAT_RGBA32);
//    SDL_PixelFormat* ss = s->format;
//    Uint32 sss = SDL_MapRGB(ss,255,0,255);
//
//    void* m_pixels;
//    int m_pitch;
//  SDL_Surface* x = SDL_ConvertSurfaceFormat(s,SDL_GetWindowPixelFormat(Game::Instance()->GetWindow()->GetWindow()),0);
//    SDL_Texture *t = SDL_CreateTexture(Game::Instance()->GetRenderer(),ss->format,SDL_TEXTUREACCESS_STREAMING,
//                                     x->w,
//                                       x->h);
//
//    SDL_LockTexture(t,NULL,&m_pixels,&m_pitch);
//    memcpy(m_pixels , x->pixels , x->pitch* x->h);
//    SDL_SetTextureColorMod(t,255,255,255);
//    SDL_UnlockTexture(t);
//    SDL_RenderCopy(Game::Instance()->GetRenderer(),t,NULL,NULL);
//

    // TextureManager::Instance()->SetColour((Uint8)sss,(Uint8)sss,(Uint8)sss,(Uint8)sss,Game::Instance()->GetRenderer());



// TextureManager::Instance()->DrawText("OpenSans-Bold",0,0,FontManager::Instance()->GetFont("OpenSans-Bold/12"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-Light"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-BoldItalic"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-ExtraBold"),Game::Instance()->GetRenderer());
//         TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-LightItalic"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-Semibold"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-SemiboldItalic"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-ExtraBoldItalic"),Game::Instance()->GetRenderer());
//        TextureManager::Instance()->DrawText("OpenSans",0,0,FontManager::Instance()->GetFont("OpenSans-Italic"),Game::Instance()->GetRenderer());

