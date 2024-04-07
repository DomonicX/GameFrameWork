#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H


#include <GUI_Wigdet.h>
class GUI_Window : public GUI_Wigdet
{
public:
    GUI_Window();
     ~GUI_Window();

     void Add(GUI_Wigdet* w){}

     void Remove(int n){}

     void GUI_Wigdet& GetChild(int ){}
    void  HandleEvent(SDL_Event &e ){}
    void Update(){}
    virtual void Render(){}
protected:

private:
};

#endif // GUI_WINDOW_H

