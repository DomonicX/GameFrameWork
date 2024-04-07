#ifndef GUI_SUBMENU_H
#define GUI_SUBMENU_H


#include <GUI_Wigdet.h>
#include <Application.h>
#include <TextureManager.h>
#include <FontManager.h>
class GUI_SubMenu : public GUI_Wigdet

{
public:
    GUI_SubMenu(std::string label);
    virtual ~GUI_SubMenu();
 std::string getTitle(){return m_title;};
void init(std::string Title, ICommand *cmd,int x = 0, int y = 0, int Margin = 0);
    bool isClicked()
    {
        return m_isClicked;
    }
    bool isMouseOver();
    void Add(GUI_Wigdet* w) ;
    void  SetHitBox(SDL_FRect r)
    {
        m_hitBox = r;
    }
    void Remove(int n) ;
    GUI_Wigdet& GetChild(int ) ;
    void HandleEvent(SDL_Event &e ) ;
    void Update(float deltaTime);
    void Render();
    bool isVisable()
    {
        return m_isVisable;
    };
    void SetVisable(bool con);

     void SetTitle(std::string Title);
    int GetChildSize() {return 0;}
    std::string Type()
    {
        return "GUI_SubMenu";
    }
    void SetPosition(vec2f pos);
    int getHeight()
    {
        return m_hitBox.h;
    }
    int getWidth()
    {
        return m_hitBox.w;
    }
    vec2f Getposition()
    {
        return vec2f(m_hitBox.x,m_hitBox.y);
    }
    SDL_FRect GetHitBox()
    {
        return m_hitBox;
    }
    void SetIsAvailable(bool isAvailable);
    bool IsAvailable();
protected:

private:
    ICommand *m_cmd;
    bool m_isAvailable  =  true;
    bool m_onAction =  false;
    bool m_isMouseOver =  false;
    bool m_isClicked =  false;
    bool m_isVisable =  true;
    float m_w;
    float m_h;
    SDL_FRect m_hitBox;
    float m_x;
    float m_y;
std::string m_title;
};

class GUI_SubMenuCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_SubMenu("SUBMENU");
    }
};
#endif // GUI_SUBMENU_H
