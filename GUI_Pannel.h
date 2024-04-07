#ifndef GUI_PANNEL_H
#define GUI_PANNEL_H


#include <GUI_Label.h>
#include <GUI_Wigdet.h>
#include <string.h>
#include <iostream>
#include <TextureManager.h>
#include <FontManager.h>
#include <Application.h>
#include <InputHandler.h>

//
//
//enum {OTHER_TYPE, WINDOW_TYPE, RENDERER_TYPE, TEXTURE_TYPE, SURFACE_TYPE,
//      FONT_TYPE, STRING_TYPE, ARRAY_TYPE
//     } typedef  ;
//
//
//
//
//#define Gui::Icon icon
//
//
//typedef enum {Na, PANNEL_HEADER, PANNEL_GAMESTATE} PANNEL_TYPE;

class GUI_Pannel : public GUI_Wigdet
{
public:
    GUI_Pannel();
    virtual ~GUI_Pannel();
    void HandleEvent(SDL_Event &e ) ;
    void Init(SDL_FRect Box);

    void Update(float deltaTime);
    void Render() ;
    void Remove(int n) ;
    void Add(GUI_Wigdet* w) ;

    void SetVisable(bool con) ;
    void SetTitle(std::string Title) ;
    void SetHitBox(SDL_FRect r) ;
    void SetPosition(vec2f pos) ;
    bool isClicked() ;
    bool isVisable() ;
    bool isMouseOver() ;
    std::string Type() ;

    GUI_Wigdet& GetChild(int i) ;
    SDL_FRect GetHitBox();
    int GetChildSize() ;
    int getHeight() ;
    std::string getTitle() ;
    vec2f Getposition() ;
    int getWidth() ;

protected:

private:
    vec2f m_pos;
    std::string m_title;
    SDL_FRect m_hitBox;
    int Margin;
    int spacing;
    SDL_Color HitBoxArea;
    SDL_Color hitBoxOutLine;
    int HitBoxOutLineThickness;
    bool m_isclicked = false;
    bool isMouseHover = false;
    bool m_isVisable = true;

    std::vector<GUI_Wigdet*>m_Wigdets;
};

class GUI_PannelCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_Pannel();
    }
};
#endif // GUI_PANNEL_H
