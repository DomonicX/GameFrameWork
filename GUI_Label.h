#ifndef GUI_LABEL_H
#define GUI_LABEL_H
#include <TextObject.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <GUI_Wigdet.h>
#include <GUIFactory.h>
#include <Application.h>
#include <SDL2/SDL_ttf.h>

class GUI_Label : public GUI_Wigdet
{
public: std::string getTitle(){return m_title;};

    GUI_Label(std::string Title);
    ~GUI_Label();
    void Init(std::string Title,int x, int y);
    void Add(GUI_Wigdet* w) {}
    void Remove(int n) {}
    GUI_Wigdet& GetChild(int i ) {}
    void HandleEvent(SDL_Event &e );
    void Update(float deltaTime) {}
    bool isVisable();
    void  SetVisable(bool con);
    void Render();
    std::string Type();void SetPosition(vec2f pos);
        int getHeight();
    int getWidth();
    bool isClicked();
    vec2f Getposition();
    bool isMouseOver();
    void  SetHitBox(SDL_FRect r);
    SDL_FRect GetHitBox();
     void SetTitle(std::string Title);
    int GetChildSize() {}

protected:

private:
    int m_margin = 0;
std::string m_title;
    bool m_isVisable = true;
    SDL_FRect m_hitBox;

};



class GUI_LabelCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_Label("Gui_Label");
    }
};



//        int iW,iH;
//    SDL_Surface *surf =  TTF_RenderText_Blended(font,message.c_str(), C);
//    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
//    if(texture==nullptr)
//    {
//        std::cout << " 3 error \n";
//    }
//    SDL_QueryTexture(texture,NULL,NULL,&iW,&iH);
//    SDL_Rect ss = {x,y,iW,iH};
//    SDL_RenderCopyEx(render,texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);
//
//    SDL_FreeSurface(surf);
//    SDL_DestroyTexture(texture);


#endif // GUI_LABEL_H
