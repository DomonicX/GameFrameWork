#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <IWidget.h>
#include <string.h>
using namespace Gui;
class WidgetFactory
{
public:
    IWidget* Create(std::string Create, std::string Title  = "NA" ,SDL_Rect r = SDL_Rect({0,0,0,0}));


    static WidgetFactory* Instance()
    {
        if(s_pInstance==NULL)
            s_pInstance = new WidgetFactory();
        return s_pInstance;
    }
private:
    WidgetFactory(){}
    virtual ~WidgetFactory(){}
    static WidgetFactory* s_pInstance;
};
#define  WIDGETFACTORY WidgetFactory::Instance()

#endif // WIDGETFACTORY_H
