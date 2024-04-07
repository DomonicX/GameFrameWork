#ifndef DIRECTORYMANAGERWIDGET_H
#define DIRECTORYMANAGERWIDGET_H


#include <IWidget.h>
#include <Application.h>
using namespace Gui;
class DirectoryManagerWidget : public IWidget
{
    public:
        DirectoryManagerWidget();
        virtual ~DirectoryManagerWidget();

     void Load(std::string FileLocation);
     void HandleEvent(SDL_Event &e);
     void  Update(float DeltaTime) ;
     void Render(SDL_Renderer *r) ;
     void Remove(int n);
     void  Add(IWidget* Child) ;
 IWidget& GetChild(int i)
    {
        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"errorrr GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };

    int GetChildSize()
    {
        return m_children.size();
    };

  std::string Type() { return "DirectoryManager";}

    private:
    std::vector<IWidget*>m_children;
        Label m_Label; // title of widget
        DropDownList m_DropDownList; // search
        Vscrollbar m_Vscrollbar; // vscrollbar if contents is to big
        Hscrollbar m_Hscrollbar ; // hscrollbar if contents is to big
};

#endif // DIRECTORYMANAGERWIDGET_H
