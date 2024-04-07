#ifndef GUI_LISTBOX_H
#define GUI_LISTBOX_H

#include <GUI_Wigdet.h>
#include <string.h>
#include <iostream>
#include <TextureManager.h>
#include <FontManager.h>
#include <Application.h>
#include <InputHandler.h>
class GUI_ListBox : public GUI_Wigdet
{
public:
    GUI_ListBox();
    virtual ~GUI_ListBox();
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

    GUI_Wigdet& GetChild(int i);
    SDL_FRect GetHitBox();
    int GetChildSize();
    int getHeight();
    std::string getTitle();
    vec2f Getposition();
    int getWidth();
protected:

private:
};


class GUI_ListBoxCreater : public GUIBaseCreater
{
public :
    GUI_Wigdet* CreateGUIObject() const
    {
        return  new GUI_ListBox();
    }
};

#endif // GUI_LISTBOX_H
