#ifndef GUI_MENU_H
#define GUI_MENU_H

#include <GUI_Wigdet.h>
#include <Application.h>
#include <TextureManager.h>
#include <FontManager.h>
class GUI_Menu : public GUI_Wigdet
{
public:
    GUI_Menu();
    virtual ~GUI_Menu();
    vec2f Getposition()
    {
        return vec2f(m_hitBox.x,m_hitBox.y);
    }
    bool isClicked()
    {
        return m_isClicked;
    }
    bool isMouseOver()
    {
        return false;
    }
    void Add(GUI_Wigdet* w) ;
    void Remove(int n) ;
    void  SetHitBox(SDL_FRect r)
    {
        m_hitBox = r;
    }

    int GetChildSize()
    {
        return m_Wigdets.size();
    }
    GUI_Wigdet& GetChild(int i) ;
    void HandleEvent(SDL_Event &e ) ;
    void Update(float deltaTime);
    void Render();
    SDL_FRect GetHitBox()
    {
        return m_hitBox;
    }
  bool isVisable()
    {
        return m_isVisable;
    } ;
void init(std::string Title,int x =0, int y = 0 , int Margin = 24);
     void SetTitle(std::string Title);
    void  SetVisable(bool con) {
     m_isVisable = con;}

    std::string Type()
    {
        return "GUI_Menu";
    }
    int getHeight()
    {
        return m_hitBox.h;
    }
    int getWidth()
    {
        return m_hitBox.w;
    }
    std::string getTitle(){return m_title;};
    void SetPosition(vec2f pos);
    int GetTextSize(){return m_textSize;}
protected:

private:
SDL_FRect m_subMenuHitbox;
    int m_margin ;
    int m_textSize;
std::string m_title;
    bool m_isVisable = true;
    SDL_Color backGround;
    float m_w;
    float m_h;
    std::vector<GUI_Wigdet*>m_Wigdets;
    SDL_FRect m_hitBox;
    bool m_isMouseOver = false;
    bool m_isClicked = false;
    float m_x;
    float m_y;
    ICommand *m_cmd;
};
class GUI_MenuCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_Menu();
    }
};
#endif // GUI_MENU_H
