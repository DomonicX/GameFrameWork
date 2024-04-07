#include "WidgetFactory.h"

WidgetFactory *WidgetFactory::s_pInstance = 0;
//last thing i did
IWidget*  WidgetFactory::Create(std::string Create, std::string Title,SDL_Rect r)
{
    if(Create=="WindowImp")
    {
        WindowImp * w = new WindowImp();
        w->Init("WindowImp",r);
        return w;
    }
    else if(Create=="MenuBar")
    {
        MenuBar * w = new MenuBar();
        w->Init(Title,r);
        return   w;
    }
    else if(Create=="SubMenu")
    {
        SubMenu * w = new SubMenu();
        w->Init(Title,r);
        w->SetVisable(false);
        return   w;
    }
    else if(Create=="Frame")
    {
       Frame * w = new Frame();
        w->Init(Title,r);

        return   w;
    }

    else if(Create=="GroupBox")
    {  GroupBox * w = new GroupBox();
        w->Init(Title,r);

          return   w;
    }

    else if(Create=="DropDownList")
     {
         DropDownList * w = new DropDownList();
        w->Init(Title,r);
     //   w->Load(FilePath);
          return    w;
     }
    else if(Create=="RatioButton")
{       RatioButton * w = new RatioButton();
        w->Init(Title,r);
          return  w;
}
    else if(Create=="TabList")
    {
        TabList * w = new TabList();

        w->Init(Title,r);
          return  w;

    }
    else if(Create=="ToggleButton")
      {
          ToggleButton * w = new ToggleButton();
        w->Init(Title,r);
          return  w;
      }
    else if(Create=="Label")
       {
                Label * w = new Label();
        w->Init(Title,r);
          return  w;
       }
    else if(Create=="progressbar")
       {
                progressbar * w = new progressbar();
        w->Init(Title,r);

          return w;
       }
    else if(Create=="Entry")
     {
           Entry * w = new Entry();
        w->Init(Title,r);
        return  w;
     }
    else if(Create=="Vscrollbar")
      {
              Vscrollbar * w = new Vscrollbar();
        w->Init(Title,r);

          return w;
      }
    else if(Create=="textbox")
      {
              textbox * w = new textbox();
        w->Init(Title,r);

          return w;
      }
    else if(Create=="Hscrollbar")
      {
              Hscrollbar * w = new Hscrollbar();
        w->Init(Title,r);          return w;
      }
    else if(Create=="TextEdit")
      {
              Gui::TextEdit * w = new Gui::TextEdit();
        w->Init(Title,r);

          return w;
      }
    else if(Create=="Panel")
       {
               Panel * w = new Panel();
       w->Init(Title,r);
          return w;
       }
    else if(Create=="Menu")
     {
             Menu * w = new Menu();
 w->Init(Title,r);
w->SetPadding(r.x,r.y,r.w,r.h);

          return w;
     }
    else if(Create=="Button")
    {
           Button * w = new Button();
      w->Init(Title,r);
          return w;
    }
    else if(Create=="Tab")
{
       Tab * w = new Tab();
   w->Init(Title,r);
          return w;
}
    else
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"WidgetCreation ","Could not find widget Name in WidgetFactory",NULL);
        std::cout << "ERROR\n";
        return NULL;
    }

}
