#ifndef GUI_MENUBAR_H
#define GUI_MENUBAR_H


#include <GUI_Wigdet.h>
#include <string.h>
#include <iostream>
#include <TextureManager.h>
#include <FontManager.h>
#include <Application.h>
#include <InputHandler.h>
class GUI_MenuBar: public GUI_Wigdet
{
public:
    GUI_MenuBar();
    virtual ~GUI_MenuBar();

    void HandleEvent(SDL_Event &e );
    void Update(float deltaTime);
    void Render();
    void Remove(int n);
    void Add(GUI_Wigdet* w);
    void SetVisable(bool con);
    void SetTitle(std::string Title);
    void SetHitBox(SDL_FRect r);
    void SetPosition(vec2f pos);
    bool isClicked();
    bool isVisable();
    bool isMouseOver();
    std::string Type();
    int getHeight();
    std::string getTitle();
    vec2f Getposition();
    int getWidth();
    GUI_Wigdet& GetChild(int i);
    SDL_FRect GetHitBox();
    int GetChildSize();

protected:

private:
    bool m_isMouseOver,m_isVisable,m_isClicked;
    std::vector<GUI_Wigdet*>m_menus;
    std::string m_title;
    SDL_FRect m_hitBox;
};

class GUI_MenuBarCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_MenuBar();
    }
};
#endif // GUI_MENUBAR_H
/**<
    void GUI_MenuBar::Remove(int n){delete m_menus[n];}
    void GUI_MenuBar::Add(GUI_Wigdet* w){m_menus.push_back(w);}
    void GUI_MenuBar::SetVisable(bool con){m_isVisable = con;}
    void GUI_MenuBar::SetTitle(std::string Title){ m_title = Title;}
    void GUI_MenuBar::SetHitBox(SDL_FRect r){m_hitBox = r;}
    void GUI_MenuBar::SetPosition(vec2f pos){m_hitBox.x = pos.x; m_hitBox.y = pos.y;}
    bool GUI_MenuBar::isClicked(){return m_isClicked;}
    bool GUI_MenuBar::isVisable(){return m_isVisable;}
    bool GUI_MenuBar::isMouseOver(){return m_isMouseOver;}
    std::string GUI_MenuBar::Type(){return "GUI_MenuBar";}
    GUI_Wigdet& GUI_MenuBar::GetChild(int i){return *m_menus[i];}
    SDL_FRect GUI_MenuBar::GetHitBox(){return m_hitBox;}
    int GUI_MenuBar::GetChildSize(){return m_menus.size();}
    int GUI_MenuBar::getHeight(){return m_hitBox.h;}
    std::string GUI_MenuBar::getTitle(){return m_title;}
    vec2f GUI_MenuBar::Getposition(){return vec2f(m_hitBox.x,m_hitBox.y);}
    int GUI_MenuBar::getWidth(){return m_hitBox.w;}
 */
