#ifndef GUI_FRAME_H
#define GUI_FRAME_H

#include <GUI_Wigdet.h>
#include <string.h>
#include <iostream>
#include <vector>
//#include <TextureManager.h>
//#include <windows.h>
#include <Application.h>

// Button = File
//  sub     = New
//  sub     = Open
//  Sub     = Save
//  Sub     = SaveAs



class GUI_Frame : public GUI_Wigdet
{
public:
    GUI_Frame();
    ~GUI_Frame();
    GUI_Wigdet* Find(std::string str);
    void Add(GUI_Wigdet* w);
    void SetLayOut(std::string Flag);
    void init(std::string Title, SDL_FRect HitBox);
    int GetChildSize();
    bool isClicked();
    void  SetHitBox(SDL_FRect r);
    bool isVisable();
    void SetPosition(vec2f pos);
    SDL_FRect GetHitBox();

    vec2f Getposition();
    SDL_FRect GetFrameRect();

    std::string Type();
    int getHeight();
    int getWidth();
    bool isMouseOver();
    void Remove(int n);
    GUI_Wigdet& GetChild(int  i);
    void HandleEvent(SDL_Event &e );
    void Update(float deltaTime);
    void Render();
    void  SetVisable(bool con);
    std::string getTitle()
    {
        return m_title;
    };

    void SetTitle(std::string Title)
    {
        m_title = Title;
    }


protected:

private:
    bool m_clicked = false;
    bool isMouseHover = false;
    bool m_isVisable = true;
    float m_padding ;
    int m_boarder;
    float m_margin;
    std::vector<GUI_Wigdet*>m_Wigdets;
    std::string m_title;
    SDL_FRect m_hitBox;
};

class GUI_FrameCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_Frame();
    }
};

#endif // GUI_FRAME_H
