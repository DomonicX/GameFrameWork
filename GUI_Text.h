#ifndef GUI_TEXT_H
#define GUI_TEXT_H

#include <GUI_Wigdet.h>
#include <string.h>
#include <iostream>
#include <TextureManager.h>
#include <FontManager.h>
#include <Application.h>
#include <InputHandler.h>

class GUI_Text: public GUI_Wigdet
{
    public:
        GUI_Text();
        virtual ~GUI_Text();

void Init(std::string Title,int x, int y);
  void HandleEvent(SDL_Event &e ){}
    void Update(float deltaTime){}
    void Render(){}
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
    std::vector<GUI_Wigdet*>m_Buttons;
    std::string m_title;
    SDL_FRect m_hitBox;
};

class GUI_TextCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_Text();
    }
};
#endif // GUI_TEXT_H
