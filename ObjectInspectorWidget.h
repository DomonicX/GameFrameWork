#ifndef OBJECTINSPECTORWIDGET_H
#define OBJECTINSPECTORWIDGET_H

#include <IWidget.h>
#include <Application.h>
using namespace Gui;


class ObjectInspectorWidget: public IWidget
{
    public:
        ObjectInspectorWidget();
        virtual ~ObjectInspectorWidget();
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

  std::string Type(){return "ObjectInspectorWidget";};
    protected:

    private:
    std::vector<IWidget*>m_children;
};

#endif // OBJECTINSPECTORWIDGET_H
