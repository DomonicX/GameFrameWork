#ifndef OUTPUTLOGWIDGET_H
#define OUTPUTLOGWIDGET_H


#include <IWidget.h>
#include <Application.h>
using namespace Gui;
class OutputLogWidget : public IWidget
{
public:
    OutputLogWidget();

void Init(std::string Title,SDL_Rect HitBox)
{

    SetTitle(Title);
    SetHitBox(HitBox);
}
    virtual ~OutputLogWidget();
    void Load(std::string FileLocation);
    void HandleEvent(SDL_Event &e);
    void  Update(float DeltaTime) ;
    void Render(SDL_Renderer *r);
    void Remove(int n);
void Add(IWidget* Child)
{
    m_children.push_back(Child);
}
    std::string Type()
    {
        return "OutputLogWidget";
    }
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
};

#endif // OUTPUTLOGWIDGET_H
