#ifndef GUI_SCROLLBAR_H
#define GUI_SCROLLBAR_H

#include <FontManager.h>
#include <Application.h>
#include <InputHandler.h>

#include <TextureManager.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>
#include <GUI_Wigdet.h>
class GUI_ScrollBar : public GUI_Wigdet
{
public:


    GUI_ScrollBar();
    virtual ~GUI_ScrollBar();


     void Remove(int n) {}
     void Add(GUI_Wigdet* w){}
     void SetVisable(bool con){}
     void SetHitBox(SDL_FRect r){}
     void SetPosition(vec2f pos){}
     bool isClicked(){}
     bool isVisable(){}
     bool isMouseOver(){}

     void SetTitle(std::string Title){m_title = Title;}
    void HandleEvent(SDL_Event& e );
    void Clean();
    void Collision();
    std::string Texture();
    std::string Type();
    int getHeight();
    int getWidth();
    void SetSize(SDL_FRect Rect,int pageSize );
     GUI_Wigdet& GetChild(int i){}
     SDL_FRect GetHitBox(){}
     int GetChildSize(){}
     vec2f Getposition(){}
    void Load(char* filename);
    void Render();
    void Update(float deltaTime);
    void init(SDL_Rect Rect,int  pageMaxW )
    {

        m_width = Rect.w;
        m_height = Rect.h;
        m_pos= vec2f(Rect.x,Rect.y);

        m_pageMaxWidth = pageMaxW;
        m_pageMinWidth = Rect.w;
        pageInc = (float)m_pageMaxWidth/(float)m_pageMinWidth;

        m_barWidth =  m_width/(float)pageInc;

        l_desRect =  {(int)m_pos.x,(int)m_pos.y,m_width,m_height};
        l_currentBar =  {(int)m_pos.x,(int)m_pos.y,(int)m_barWidth,16};


    }
 std::string getTitle(){return m_title;};



    float GetCurrentBarPos()
    {
        return m_process;
    };

protected:

protected:

private:
    float m_process = 0;

std::string m_title;
    vec2f m_pos ;
    int m_pageMaxWidth = 3072;
    int m_pageMinWidth = 256;
    float pageInc = 12;
    float m_barWidth = 21.3333;
    float currentBarPoisiton = 213.333;
    bool m_bIsScrolling = false;
    SDL_FRect l_desRect ;
    SDL_FRect l_currentBar;
    int m_width,m_height;
};
class  GUI_ScrollBarCreater : public GUIBaseCreater
{
    GUI_Wigdet* CreateGUIObject() const
    {
        return new GUI_ScrollBar();
    }
};
#endif // GUI_SCROLLBAR_H
