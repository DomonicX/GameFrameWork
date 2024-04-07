#ifndef TILEMAPMANAGERWIDGET_H
#define TILEMAPMANAGERWIDGET_H

#include <IWidget.h>
#include <Application.h>
using namespace Gui;
class TileMapManagerWidget : public IWidget
{
    public:
        TileMapManagerWidget();
        virtual ~TileMapManagerWidget();


     void Load(std::string FileLocation);
     void HandleEvent(SDL_Event &e);
     void  Update(float DeltaTime) ;
     void Render(SDL_Renderer *r) ;
     void Remove(int n);
     void  Add(IWidget* Child) ;
  std::string Type();
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

    protected:

    private:
    std::vector<IWidget*>m_children;
        LText m_titleText;
        std::vector<std::string>m_textures;
        Label m_Label; // title of widget
        DropDownList m_DropDownList; // search
        Panel *m_Panel; //Containter
        Vscrollbar m_Vscrollbar; // vscrollbar if contents is to big
        Hscrollbar m_Hscrollbar ; // hscrollbar if contents is to big
};

#endif // TILEMAPMANAGERWIDGET_H
