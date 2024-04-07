#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H

#include <SDL2/SDL.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>

#include <TextureManager.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>


class TextObject :public GameObject
{
public:
    TextObject();
    virtual ~TextObject();
    void Load(std::string FileName) {}; //m_Data = ObjectData;
    void Update(float dt) ;
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)  ;
    void Clean();
    bool hasTextChanged = false;
    void Collision() ;

    void AddSentence(std::string sen) ;
    void SetTextWidth(int width);
    void SetfontName(std::string Font); void SetColour(char r,char g,char b,char a);
    std::string Type();
    std::string Texture();
    void HandleEvent(SDL_Event& e );
    std::string m_textureID;
    std::string m_filename;
protected:
private:
    int m_MaxWidth;
    void Init();
    int m_MaxHeight;
    int m_FontHeightSpacing;
    SDL_Rect m_size;
    std::string m_fontName;
    std::vector <std::string> m_sentences;
    SDL_Color textColour = {0,0,0,0};


};

class  TextObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new TextObject();
    }
};
#endif // TEXTOBJECT_H
//
//    TTF_Font *font = TTF_OpenFont("OpenSans-Bold.TTF",12);
//    if(font==nullptr)
//    {
//        std::cout << " 1 erroxxxxr \n";
//    }
//    SDL_Surface *surf = TTF_RenderUTF8_Solid(font,"hello nigga", {255,255,255,255});
//    if(surf==nullptr)
//    {
//        TTF_CloseFont(font);
//        std::cout << " 2 errdddor \n";
//    }
//    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(),surf);
//    if(texture==nullptr)
//    {
//        std::cout << " 3 errddddor \n";
//    }
//
