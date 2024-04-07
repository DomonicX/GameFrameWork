
#ifndef IWIDGET_H
#define IWIDGET_H


#include <Vector2D.h>
#include <Lmaths.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


#include <LText.h>
#include <LTexture.h>

#include <TextureManager.h>
#include <InputHandler.h>
#include <FontManager.h>
#include <DirectoryHandler.h>

#include <CallBack.h>


////
//SDL_MESSAGEBOX_COLOR_BACKGROUND,
//    SDL_MESSAGEBOX_COLOR_TEXT,
//    SDL_MESSAGEBOX_COLOR_BUTTON_BORDER,
//    SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND,
//    SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED,
//    SDL_MESSAGEBOX_COLOR_MAXtypedef enum

typedef enum
{
    //Pressed,
    //Released,
    //Toogle,
    //Ratio
} ButtonPolicy;
typedef struct
{
    int _X;
    int _Y;
    int _W;
    int _H;
} Padding;

typedef enum
{
    GUI_TEXT_Left,
    GUI_TEXT_Center,
    GUI_TEXT_Right
} GUI_TEXT_Align;


typedef enum
{
    NOFILLED,
    FILLED,
    DOTDOTTED,
    SPECIAL
} boarderStyle;


typedef struct
{
    SDL_Color BackGround = Colour_chocolate;
    SDL_Color Boarder= Colour_indianred;
    SDL_Color isFocus = Colour_honeydew;
    SDL_Color isMouseOver = Colour_yellow;
    SDL_Color isSelected = Colour_wheat;
    SDL_Color Text = Colour_navajowhite;
} WidgetColourData;
typedef struct
{
    int m_thickness;
    int Style;
} boarderVisual;

class IWidget
{
public:
//    IWidget(IWidget* parent = nullptr);
    IWidget();

    virtual ~IWidget();
    virtual void Init(std::string Title = {""},SDL_Rect HitBox = {0,0,0,0});

    virtual IWidget* Find(std::string str);

    virtual std::string  Type()
    {
        return "IWidget";
    }
    bool MouseOver(SDL_Rect r)
    {
        return InputHandler::Instance()->MouseinRect(r);
    }
    virtual void Load(std::string FileLocation)
    {
        std::cout << "Loading FileLocation at " << FileLocation << ".txt\n";
        m_title = FileLocation;
    }
    virtual void HandleEvent(SDL_Event &e) {}
    virtual void Update(float DeltaTime) {}
    virtual void Render(SDL_Renderer *r) {}
    virtual void Remove(int n) {};
    virtual void Add(IWidget* Child) {}

virtual void ChangeText(SDL_Renderer* r,std::string newText, std::string FontID = "OpenSans-Regular");
    void SetTextColour(SDL_Color c)
    {
        text.SetTextColour(c);
    };
   void SetTextSize( int pxSize)
{text.SetTextSize(pxSize);};
    void Pressed()
    {
        m_isMouseClicked = true;
    }
    void Released()
    {
        m_isMouseClicked = false;
    }

    virtual IWidget&  GetChild(int i)
    {
        return *this;
    }
    virtual int  GetChildSize()
    {
        return 0;
    };
    std::string  GetTitle()
    {
        return m_title;
    }

    SDL_Rect  GetHitBox()
    {
        return {m_hitBox.x-m_padding._X,m_hitBox.y-m_padding._Y,m_hitBox.w+m_padding._W*2,m_hitBox.h+m_padding._H*2};
    }
    vec2f GetHitBoxCentre()
    {
        return {((float)m_hitBox.x+m_hitBox.w/2),((float)m_hitBox.y+m_hitBox.h/2)};
    }
    SDL_Rect GetContextRect()
    {
        return

        {
            m_hitBox.x-m_padding._X,
            m_hitBox.y-m_padding._Y,
            m_hitBox.w+m_padding._W*2,
            m_hitBox.h+m_padding._H*2
        };
    }
    SDL_Rect GetComponentRect()
    {
        if(GetChildSize()==0)
        {
            return SDL_Rect({0,0,0,0});
        }
        SDL_Rect c ={0,0,0,0};
        for(int i = 0; i < GetChildSize()-1; i++)
        {

            SDL_Rect b = GetChild(i).GetHitBox();
            SDL_Rect a = GetChild(i+1).GetHitBox();
            SDL_UnionRect(&a,&b,&c);

        }
        return c;
    }
    Padding GetPadding(){return m_padding;}
    vec2f GetContextCentre()
    {
        return {((float)GetContextRect().x+GetContextRect().w/2),((float)GetContextRect().y+GetContextRect().h/2)};
    }
    boarderVisual  Getboarder()
    {
        return m_boarder;
    }
    vec2f   GetPosition()
    {
        return vec2f(m_hitBox.x,m_hitBox.y);
    }
    vec2f   GetSize()
    {
        return vec2f(GetHitBox().y,GetHitBox().y);
    }
    bool  isVisable()
    {
        return m_isVisable;
    }
    bool IsMousePressed()
    {
        return m_isMouseClicked;
    }
    bool IsMouseReleased()
    {
        return m_isMouseReleased;
    }
    bool IsMouseHover()
    {
        return m_isMouseHover;
    }
    bool IsFocus()
    {
        return m_isFocus;
    }
    void  SetTitle( std::string Title)
    {
        m_title = Title;
    }
    void  SetVisable( bool con)
    {
        m_isVisable = con;
    }
    void  SetHitBox(SDL_Rect Rect)
    {
        m_hitBox = Rect;
    }
    void  SetFilled(bool isFilled)
    {  m_isFilled = isFilled;

    }
    void  SetPosition(vec2f Pos)
    {
        m_hitBox.x = Pos.x;
        m_hitBox.y = Pos.y;
    }
    void  SetSize(vec2f Size)
    {
        m_hitBox.h = Size.x;
        m_hitBox.w = Size.y;
    }
    void  SetFocus(bool con)
    {
        m_isFocus = con;
    }
    void  SetColour(WidgetColourData cd)
    {
        m_colourdata = cd;
    }
    void SetPadding(int x = 0, int y= 0, int w=0, int h = 0)
    {

        m_padding._X = x;
        m_padding._Y = y;
        m_padding._H = h;
        m_padding._W = w;
    }

 protected:
    LText text;
    bool m_isMouseHover = false;
    bool m_isMouseClicked = false;
    bool m_isMouseReleased = false;
    bool m_isFocus = false;
    bool m_isVisable = true;
    bool m_isFilled = false;
    WidgetColourData m_colourdata ;
    boarderVisual m_boarder;
    std::string m_title;
    SDL_Rect m_hitBox;
    Padding m_padding;

private:
};


namespace Gui
{
//composites


class WindowImp : public IWidget
{
public :
    WindowImp() {}

    ~WindowImp();
//    void SetContext(SDL_Window &w)
//    {
//        m_window = &w;
//    }
//SDL_Window& GetWindow()
//{
//    return *m_window;
//}

    void HandleEvent(SDL_Event &e) ;
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
    std::string Type(){return "WindowImp";}
    void Remove(int n);
    void Add(IWidget* Child)
    {
        std::cout <<"\n" << GetTitle() << " adding : ";
        std::cout << Child->GetTitle() << " :" <<  Child->Type() <<  " ";
        std::cout << Child->GetPosition()<<" ";
        std::cout << Child->GetSize()<<"\n";
        m_children.push_back(Child);
    };
//    void AddMenuBar(MenuBar* mb);
    IWidget& GetChild(int i)
    {
        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"errorrr GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    }
    int GetChildSize()
    {
        return m_children.size();
    };

    void Save(std::string FilePath);
    bool HasMouseFocus()
    {
        return m_isMouseFocus;
    }
    bool HasKeyboardFocus()
    {
        return m_isKeyboardFocus;
    }
    void isMouseFocus(bool con)
    {
        m_isMouseFocus = con;
    }
    void isKeyboardFocus(bool con)
    {
        m_isKeyboardFocus = con;
    }
    void isMinimized(bool con)
    {
        m_isKeyboardFocus = con;
    }
private :
    std::vector<IWidget*>m_children;
    //SDL_Window  *m_window;
//    MenuBar *m_menubar;

    bool m_isMouseFocus,m_isKeyboardFocus,m_isMinimized= false;

};
class MenuBar : public IWidget
{
public :
    std::string Type()
    {
        return "MenuBar";
    }
    MenuBar() {}
    ~MenuBar()
    {
        for(int i = 0 ; i < m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }
    void SetHorizontal();
    void SetVertical  ();

    void HandleEvent(SDL_Event &e) ;
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r);
    void Remove(int n) {};
    void Add(IWidget* Child)
    {

    if(m_isVertical)
        {

           Child->SetPosition(vec2f(GetComponentRect().x,GetComponentRect().h+GetComponentRect().y));
        }else
        {
            if(GetChildSize()!=0)
            {
      //  Child->SetPosition(vec2f(GetChild(GetChildSize()-1).GetHitBox().w,GetChild(GetChildSize()-1).GetHitBox().h));
        Child->SetPosition(vec2f(
                         Child->GetPadding()._X    +GetChild(GetChildSize()-1).GetContextRect().w+GetChild(GetChildSize()-1).GetContextRect().x,
                                 GetChild(GetChildSize()-1).GetContextRect().y
                                 ));
        std::cout << GetComponentRect().x << " x " << GetComponentRect().y << " y " << GetComponentRect().w << " h " << GetComponentRect().w << " w \n\n\n\n\n";
            }
    }
        m_children.push_back(Child);

    };
    IWidget& GetChild(int i)
    {
        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"MenuBar GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };
    int GetChildSize()
    {
        return m_children.size();
    };
private :
     bool m_isVertical  = false;
    SDL_Rect m_menusRect = {0,0,0,0};
    std::vector<IWidget*>m_children;
};
class Menu : public IWidget
{
public :
    Menu() {}
    ~Menu()
    {
        for(int i = 0 ; i < m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
        if(m_callback!=NULL) delete m_callback;
    }

    std::string Type()
    {
        return "Menu";
    }
    void Init(std::string Title,SDL_Rect HitBox = {0,0,0,0})
    {
        SDL_Rect TextRect = fontManager->QueryText(Title,"OpenSans-Regular");
        m_hitBox = {HitBox.x,HitBox.y, TextRect.w,TextRect.h};
        SetTitle(Title);
        SetHitBox(m_hitBox);
    }


    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
    void Remove(int n) {};
    void Add(IWidget* Child)
    {
        m_children.push_back(Child);


    };

     IWidget& GetChild(int i)
    {
        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"Menu GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };
    int GetChildSize()
    {
        return m_children.size();
    };

    void OnAction(CallBack * cb)
    {
        if(cb==NULL)
        {
            m_callback = NULL;
            return ;
        }
        if(m_callback!=NULL)
        {
            delete m_callback;
        }
        m_callback = cb;
    }
private :
    CallBack* m_callback = NULL;
    std::vector<IWidget*>m_children;

};
class Frame : public IWidget
{
public :
    Frame() {}
    ~Frame()
    {
        for(int i = 0 ; i < m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }



    void HandleEvent(SDL_Event &e) ;
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
    std::string Type()
    {
        return "Frame";
    }
    void Remove(int n)
    {
        delete m_children[n];
        m_children.erase(m_children.begin()+n);
    };
    void Add(IWidget* Child)
    {
        std::cout <<"\n" << GetTitle() << " adding : ";
        std::cout << Child->GetTitle() << " :" <<  Child->Type() <<  " ";
        std::cout << Child->GetPosition()<<" ";
        std::cout << Child->GetSize()<<"\n";
        m_children.push_back(Child);



    };
    IWidget& GetChild(int i)
    {
        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"Frame GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };

    int GetChildSize()
    {
        return m_children.size();
    };

    int GetHeader()
    {
        return m_Header;
    }
private :
    std::vector<IWidget*>m_children;
    int m_Header = 0;

};
class Panel : public IWidget
{
public :

    Panel() {}
    ~Panel()
    {
        for(int i = 0 ; i < (int)m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }
    std::string Type()
    {
        return "Panel";
    }



    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r) ;
    void Remove(int n)
    {
        delete m_children[n];
        m_children.erase(m_children.begin()+n);
    };
    void Add(IWidget* Child)
    {
        m_children.push_back(Child);
    };

    IWidget& GetChild(int i)
    {

        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"Panel GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };
    int GetChildSize()
    {
        return m_children.size();
    };

private :
    SDL_Rect m_ChildhitBox;
    std::vector<IWidget*>m_children;

};
class GroupBox : public IWidget
{
public :

    std::string Type()
    {
        return "GroupBox";
    }
    GroupBox() {}
    ~GroupBox()
    {
        for(int i = 0 ; i < m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }


    void HandleEvent(SDL_Event &e) ;
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
    void Remove(int n) {};
    void Add(IWidget* Child)
    {
        std::cout <<"\n" << GetTitle() << " adding : ";
        std::cout << Child->GetTitle() << " :" <<  Child->Type() <<  " ";
        std::cout << Child->GetPosition()<<" ";
        std::cout << Child->GetSize()<<"\n";
        m_children.push_back(Child);
    };
    IWidget& GetChild(int i)
    {
        if(i <= m_children.size()-1)
            return *m_children[i];
        std::cout <<"GroupBox GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };
    int GetChildSize()
    {
        return ((int)m_children.size());
    }
//    void Init(std::string Title,std::string Type,SDL_Rect HitBox) {};
private :
    std::vector<IWidget*>m_children;
};
class DropDownList : public IWidget
{
public :
    std::string Type()
    {
        return "DropDownList";
    }
    DropDownList() {}
    ~DropDownList()
    {
        for(int i = 0 ; i < (int)m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }
    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
    void Remove(int n) {};
    void Add(IWidget* Child)
    {
        std::cout <<"\n" << GetTitle() << " adding : ";
        std::cout << Child->GetTitle() << " :" <<  Child->Type() <<  " ";
        std::cout << Child->GetPosition()<<" ";
        std::cout << Child->GetSize()<<"\n";
        m_children.push_back(Child);
    };
    IWidget& GetChild(int i)
    {
        if(i <(int)m_children.size())
            return *m_children[i];
        std::cout <<"errorrr GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };
    int GetChildSize()
    {
        return m_children.size();
    };
//    void Init(std::string Title,SDL_Rect HitBox) {};
private :
    std::vector<IWidget*>m_children;
};
class RatioButton : public IWidget
{
public :
    std::string Type()
    {
        return "RatioButton";
    }
    RatioButton() {}
    ~RatioButton()
    {
        for(int i = 0 ; i <(int)m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }
    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
    void Remove(int n) {};
    void Add(IWidget* Child)
    {
        std::cout <<"\n" << GetTitle() << " adding : ";
        std::cout << Child->GetTitle() << " :" <<  Child->Type() <<  " ";
        std::cout << Child->GetPosition()<<" ";
        std::cout << Child->GetSize()<<"\n";
        m_children.push_back(Child);
    };
    IWidget& GetChild(int i) {};
    int GetChildSize()
    {
        return m_children.size();
    };
//    void Init(std::string Title,SDL_Rect HitBox) {};
private :
    std::vector<IWidget*>m_children;
};
class TabList : public IWidget
{
public :
    TabList() {}
    ~TabList()
    {
        for(int i = 0 ; i < m_children.size(); i++)
        {
            delete m_children[i];
            m_children.erase(m_children.begin() + i);
        }
        m_children.clear();
    }

    std::string Type()
    {
        return "TabList";
    }

    Init(std::string title,SDL_Rect r,Padding padding = Padding({0,0,0,0}))
    {
        m_padding = padding;
        IWidget::Init(title,r);

    };

    void setFoucsTab(std::string str);


    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r) ;
    void Remove(int n)
    {
        delete m_children[n];
        m_children.erase(m_children.begin()+n);
    };
    void Add(IWidget* Child)
    {
        m_children.push_back(Child);

    };

    IWidget& GetChild(int i)
    {

        if(i <= m_children.size()-1)
            return *m_children[i];
        std::cout <<"TabList GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };
    int GetChildSize()
    {
        return m_children.size();
    };
private :
    Padding m_padding;
    SDL_Rect m_ChildhitBox;
    std::vector<IWidget*>m_children;
};

//Leafs


class Button : public IWidget
{
public :
    Button() {}


    ~Button()
    {
        if(m_callback!=NULL) delete m_callback;
    }
    void Init(std::string Title,SDL_Rect HitBox)
    {
        SDL_Rect TextRect = fontManager->QueryText(Title,"OpenSans-Regular");


        m_hitBox = {HitBox.x,HitBox.y, TextRect.w,TextRect.h};
        SetTitle(Title);
        SetHitBox(m_hitBox);
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    std::string Type()
    {
        return "Button";
    }
    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
    void OnAction(CallBack * cb)
    {
        if(cb==NULL)
        {
            m_callback = NULL;
            return ;
        }
        if(m_callback!=NULL)
        {
            delete m_callback;
        }
        m_callback = cb;
    }
private :

    bool b_buttonDelay  = false;
    float m_buttonPressDelay = 0.25;
    float m_buttonDelayInc = 0.0;
    CallBack* m_callback = NULL;
};
class ToggleButton : public IWidget
{
public :
    ToggleButton() {}
    ~ToggleButton() {}
    std::string Type()
    {
        return "ToggleButton";
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    void HandleEvent(SDL_Event &e) ;
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
private :

};
class Label : public IWidget
{

public :
    Label() {}
    ~Label() {}

IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}


  std::string Type()
    {
        return "Label";
    }
    void Update(float DeltaTime);
    void HandleEvent(SDL_Event &e);
    void Render(SDL_Renderer *r);
    void setWrappedLength(Uint32 WrapLength);

private :

bool b_mHasTextChanged = false;
bool b_mHasTextColourChanged = false;
};
class progressbar : public IWidget
{
public :
    progressbar() {}
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    ~progressbar() {}
    std::string Type()
    {
        return "progressbar";
    }
    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
private :

};
class Entry : public IWidget
{
public :
    Entry() {}
    ~Entry()
      {
        if(m_callback!=NULL) delete m_callback;
    }
    std::string Type()
    {
        return "Entry";
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
    void OnAction(CallBack * cb)
    {
        if(cb==NULL)
        {
            m_callback = NULL;
            return ;
        }
        if(m_callback!=NULL)
        {
            delete m_callback;
        }
        m_callback = cb;
    }
private :

    bool b_buttonDelay  = false;
    float m_buttonPressDelay = 0.25;
    float m_buttonDelayInc = 0.0;
    CallBack* m_callback = NULL;
};
class Vscrollbar : public IWidget
{
public :
    Vscrollbar() {}
    ~Vscrollbar() {}
    std::string Type()
    {
        return "Vscrollbar";
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}


     void Init(std::string Title,SDL_Rect HitBox)
    {

m_hitBox = HitBox;
        SetTitle(Title);
        }
    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
private :

    bool Hscrollbar = false;
};
class textbox : public IWidget
{
public :
    textbox() {}
    ~textbox() {}
    std::string Type()
    {
        return "textbox";
    }
      void Init(std::string Title,SDL_Rect HitBox)
    {


        m_hitBox = HitBox;
        SetTitle(Title);
        SetHitBox(m_hitBox);
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}


  void HandleEvent(SDL_Event &e) ;
    void Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
private :


    std::vector<LText*> m_texts;
};
class Hscrollbar : public IWidget
{
public :
    Hscrollbar() {}
    ~Hscrollbar() {}
    std::string Type()
    {
        return "Hscrollbar";
    }
        void Init(std::string Title,SDL_Rect HitBox)
    {
m_hitBox = HitBox;
SetTitle(Title);

 m_ThumbStep = (float)HitBox.w;
 m_scrollX = 0;
// ContextArea = GetHitBox().w - m_scrollX;
m_ThumbPos = vec2f(m_hitBox.x+m_scrollX+m_ThumbStep/4,m_hitBox.y+m_hitBox.h-16);
m_ThumbRect = {m_ThumbPos.x,m_ThumbPos.y,m_ThumbStep,16};


    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    SDL_Rect  GetHitBox()
    {
        return {m_hitBox.x,m_hitBox.y,m_hitBox.w,m_hitBox.h};
    }
//    void SetConText(SDL_Rect ClipRect,SDL_Rect ViewRect) { m_cont Lmaths::GetInterSectRect(ClipRect,ViewRect) }
    void SetConTextSize(float ConText) { m_ContextArea = ConText; };
    float m_ContextArea  = 0;
    float GetScrolledValue(){return m_ContextArea;}
    float GetScrollWidth(){return m_scrollX;}
    void SetScrollWidth(float scrollX){  m_scrollX = scrollX;}
void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
private :
float m_scrollX = 0;

vec2f m_ThumbPos = vec2f(0,0);
float thumbSize = 0.0;
SDL_Rect m_ThumbRect = {0,0,0,0};
float m_ThumbStep = 0.f;
bool m_isMouseOverThumb = false;
bool m_isMousePressedThumb = false;
bool m_isThumbUpdate = false;


};
class TextEdit : public IWidget
{
public :
    std::string Type()
    {
        return "TextEditBox";
    }
    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
    TextEdit() {}
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    ~TextEdit() {}
private :

};
class Tab : public IWidget
{
public :
    Tab() {}
    ~Tab() {}
    std::string Type()
    {
        return "Tab";
    }
    void Init(std::string Title,SDL_Rect HitBox = {0,0,0,0})
    {
        SDL_Rect TextRect = fontManager->QueryText(Title,"OpenSans-Regular");
        m_hitBox = {HitBox.x,HitBox.y, TextRect.w,TextRect.h};
        SetTitle(Title);
        SetHitBox(m_hitBox);
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);

private :


};
class SubMenu : public IWidget
{
public :
    SubMenu() {}
    ~SubMenu() {}
    std::string Type()
    {
        return "SubMenu";
    }
    void Init(std::string Title,SDL_Rect HitBox = {0,0,0,0})
    {
        SDL_Rect TextRect = fontManager->QueryText(Title,"OpenSans-Regular");
        m_hitBox = {HitBox.x,HitBox.y, TextRect.w,TextRect.h};
        SetTitle(Title);
        SetHitBox(m_hitBox);
    }
IWidget* Find(std::string str){if(m_title == str) return this; else NULL;}

    void HandleEvent(SDL_Event &e);
    void Update(float DeltaTime);
    void Render(SDL_Renderer *r);
    void OnAction(CallBack * cb)
    {
        if(cb==NULL)
        {
            m_callback = NULL;
            return ;
        }
        if(m_callback!=NULL)
        {
            delete m_callback;
        }
        m_callback = cb;
    }
private :
    CallBack* m_callback = NULL;


};

}



/**<


typedef enum
{
    ALWAYS,
    AS_NEEDED,
    NEVER
} ScrollBarPolicy;

typedef enum
{
    Pressed,
    Released,
    Toogle,
    Ratio
} ButtonPolicy;

typedef enum
{
    CheckBox,
    PushButton,
    RadioButton,
    ToolButton
} ButtonType;
typedef enum
{

    Unchecked,          //The item is unchecked.
    PartiallyChecked,   //The item is partially checked. Items in hierarchical models may be partially checked if some, but not all, of their children are checked.
    Checked         	// The item is checked.
} CheckState;


typedef enum
{
    NoTextInteraction = 0, //No interaction with the text is possible.
    TextSelectableByMouse =0x100, //Text can be selected with the mouse and copied to the clipboard using a context menu or standard keyboard shortcuts.
    TextSelectableByKeyboard = 0x150, //	Text can be selected with the cursor keys on the keyboard. A text cursor is shown.
    LinksAccessibleByMouse = 0x200, //Links can be highlighted and activated with the mouse.
    LinksAccessibleByKeyboard = 0x300,// Links can be focused using tab and activated with enter.
    TextEditable = 0x400, //	The text is fully editable.
    TextEditorInteraction = 0x600, //TextSelectableByMouse | TextSelectableByKeyboard | TextEditable	The default
    TextBrowserInteraction = 0x650  //TextSelectableByMouse | LinksAccessibleByMouse | LinksAccessibleByKeyboard	The default for QTextBrowser.
} TextEditingPolicy;


QWidget *parent = nullptr
class IButton
{
public :
    IButton() {}

    //Slots
    void	animateClick() {}
    void	click() {}
    void	setChecked(bool) {}
    void	setIconSize(const QSize &size) {}
    void	toggle() {}
//Signals
    void	clicked(bool checked = false) {}
    void	pressed() {}
    void	released() {}
    void	toggled(bool checked) {}

    virtual void	checkStateSet() {}
    virtual bool	hitButton(const QPoint &pos) const
    virtual void	nextCheckState() {}
    // Reimplemented Protected Functions
    virtual void	changeEvent(QEvent *e) override= 0;
    virtual bool	event(QEvent *e) override= 0;
    virtual void	focusInEvent(QFocusEvent *e) override= 0;
    virtual void	focusOutEvent(QFocusEvent *e) override= 0;
    virtual void	keyPressEvent(QKeyEvent *e) override= 0;
    virtual void	keyReleaseEvent(QKeyEvent *e) override= 0;
    virtual void	mouseMoveEvent(QMouseEvent *e) override= 0;
    virtual void	mousePressEvent(QMouseEvent *e) override= 0;
    virtual void	mouseReleaseEvent(QMouseEvent *e) override= 0;
    virtual void	paintEvent(QPaintEvent *e) override = 0;
    virtual void	timerEvent(QTimerEvent *e) override= 0;


};
 */
/** \brief

Qt::IgnoreAspectRatio	0	The size is scaled freely. The aspect ratio is not preserved.
Qt::KeepAspectRatio	1	The size is scaled to a rectangle as large as possible inside a given rectangle, preserving the aspect ratio.
Qt::KeepAspectRatioByExpanding	2	The size is scaled to a rectangle as small as possible outside a given rectangle, preserving the aspect ratio.


QAbstractButton,
QAbstractSlider,
QAbstractSpinBox,
QCalendarWidget,
QComboBox,
QDesignerActionEditorInterface,
QDesignerFormWindowInterface,
QDesignerObjectInspectorInterface,
QDesignerPropertyEditorInterface,
QDesignerWidgetBoxInterface,
QDialog,
QDialogButtonBox,
QDockWidget,
QFocusFrame,
QFrame,
QGroupBox,
QKeySequenceEdit,
QLineEdit,
QMainWindow,
QMdiSubWindow
QMenu,
QMenuBar,
QProgressBar,
QQuickWidget,
QRubberBand,
QSizeGrip,
QSplashScreen,
QSplitterHandle,
QStatusBar,
QSvgWidget,
QTabBar,
QTabWidget,
QToolBar,
QStyleOption::SO_Button	2	QStyleOptionButton
QStyleOption::SO_ComboBox	0xf0004	QStyleOptionComboBox
QStyleOption::SO_Complex	0xf0000	QStyleOptionComplex
QStyleOption::SO_Default	0	QStyleOption
QStyleOption::SO_DockWidget	9	QStyleOptionDockWidget
QStyleOption::SO_FocusRect	1	QStyleOptionFocusRect
QStyleOption::SO_Frame	5	QStyleOptionFrame
QStyleOption::SO_GraphicsItem	15	QStyleOptionGraphicsItem
QStyleOption::SO_GroupBox	0xf0006	QStyleOptionGroupBox
QStyleOption::SO_Header	8	QStyleOptionHeader
QStyleOption::SO_MenuItem	4	QStyleOptionMenuItem
QStyleOption::SO_ProgressBar	6	QStyleOptionProgressBar
QStyleOption::SO_RubberBand	13	QStyleOptionRubberBand
QStyleOption::SO_SizeGrip	0xf0007	QStyleOptionSizeGrip
QStyleOption::SO_Slider	0xf0001	QStyleOptionSlider
QStyleOption::SO_SpinBox	0xf0002	QStyleOptionSpinBox
QStyleOption::SO_Tab	3	QStyleOptionTab
QStyleOption::SO_TabBarBase	12	QStyleOptionTabBarBase
QStyleOption::SO_TabWidgetFrame	11	QStyleOptionTabWidgetFrame
QStyleOption::SO_TitleBar	0xf0005	QStyleOptionTitleBar
QStyleOption::SO_ToolBar	14	QStyleOptionToolBar
QStyleOption::SO_ToolBox	7	QStyleOptionToolBox
QStyleOption::SO_ToolButton	0xf0003	QStyleOptionToolButton
QStyleOption::SO_ViewItem	10	QStyleOptionViewItem (used in Interviews)
*/


/** \brief
 Left 0	Align left. side
 Center 2 Align center. spreads equally left and right.
 Right 1 Align right side
 */

/** \brief
 ScrollBarAsNeeded
 shows a scroll bar when the content is too large to fit and not otherwise. This is the default.
 ScrollBarAlwaysOff
 never shows a scroll bar.
  ScrollBarAlwaysOn
  always shows a scroll bar. This property is ignored on systems with transient scroll bars

  ALWAYS
Indicates that a scroll bar should always be shown.
AS_NEEDED
Indicates that a scroll bar should be shown when required.
NEVER
Indicates that a scroll bar should never be shown.
 */

/** \brief
Qt::NoTextInteraction	0
Qt::TextSelectableByMouse	1
Qt::TextSelectableByKeyboard	2
Qt::LinksAccessibleByMouse	4
Qt::LinksAccessibleByKeyboard	8
Qt::TextEditable	16
Qt::TextEditorInteraction	TextSelectableByMouse | TextSelectableByKeyboard | TextEditable	The default for a text editor.
Qt::TextBrowserInteraction	TextSelectableByMouse | LinksAccessibleByMouse | LinksAccessibleByKeyboard	The default for QTextBrowser.
 */


/**<

 Qt::UI_AnimateMenu	1	Show animated menus.
Qt::UI_FadeMenu	2	Show faded menus.
Qt::UI_AnimateCombo	3	Show animated comboboxes.
Qt::UI_AnimateTooltip	4	Show tooltip animations.
Qt::UI_FadeTooltip	5	Show tooltip fading effects.
Qt::UI_AnimateToolBox	6	Reserved

  Class              QAbstractButton
Inherits:
                QWidget
Inherited By:
                QCheckBox, QPushButton, QRadioButton, and QToolButton
Properties
autoExclusive : bool
autoRepeat : bool
autoRepeatDelay : int
autoRepeatInterval : int
checkable : bool
checked : bool
down : bool
icon : QIcon
iconSize : QSize
shortcut : QKeySequence
text : QString

Public Functions

QAbstractButton(QWidget *parent = nullptr)
virtual	~QAbstractButton()
bool	autoExclusive() const
bool	autoRepeat() const
int	autoRepeatDelay() const
int	autoRepeatInterval() const
QButtonGroup *	group() const
QIcon	icon() const
QSize	iconSize() const
bool	isCheckable() const
bool	isChecked() const
bool	isDown() const
void	setAutoExclusive(bool)
void	setAutoRepeat(bool)
void	setAutoRepeatDelay(int)
void	setAutoRepeatInterval(int)
void	setCheckable(bool)
void	setDown(bool)
void	setIcon(const QIcon &icon)
void	setShortcut(const QKeySequence &key)
void	setText(const QString &text)
QKeySequence	shortcut() const
QString	text() const
Public Slots
void	animateClick()
void	click()
void	setChecked(bool)
void	setIconSize(const QSize &size)
void	toggle()
Signals
void	clicked(bool checked = false)
void	pressed()
void	released()
void	toggled(bool checked)
Protected Functions
virtual void	checkStateSet()
virtual bool	hitButton(const QPoint &pos) const
virtual void	nextCheckState()
Reimplemented Protected Functions
virtual void	changeEvent(QEvent *e) override
virtual bool	event(QEvent *e) override
virtual void	focusInEvent(QFocusEvent *e) override
virtual void	focusOutEvent(QFocusEvent *e) override
virtual void	keyPressEvent(QKeyEvent *e) override
virtual void	keyReleaseEvent(QKeyEvent *e) override
virtual void	mouseMoveEvent(QMouseEvent *e) override
virtual void	mousePressEvent(QMouseEvent *e) override
virtual void	mouseReleaseEvent(QMouseEvent *e) override
virtual void	paintEvent(QPaintEvent *e) override = 0
virtual void	timerEvent(QTimerEvent *e) override

QCheckBox Class

Inherits:	QAbstractButton

Properties
tristate : bool
Public Functions
QCheckBox(const QString &text, QWidget *parent = nullptr)
QCheckBox(QWidget *parent = nullptr)
virtual	~QCheckBox()
Qt::CheckState	checkState() const
bool	isTristate() const
void	setCheckState(Qt::CheckState state)
void	setTristate(bool y = true)
Reimplemented Public Functions
virtual QSize	minimumSizeHint() const override
virtual QSize	sizeHint() const override
Signals
void	stateChanged(int state)
Protected Functions
virtual void	initStyleOption(QStyleOptionButton *option) const
Reimplemented Protected Functions
virtual void	checkStateSet() override
virtual bool	event(QEvent *e) override
virtual bool	hitButton(const QPoint &pos) const override
virtual void	mouseMoveEvent(QMouseEvent *e) override
virtual void	nextCheckState() override
virtual void	paintEvent(QPaintEvent *) override
Detailed Description

 Class QPushButton
Inherits:	QAbstractButton
Inherited By:
            QCommandLinkButton
Properties
autoDefault : bool
default : bool
flat : bool
Public Functions
QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)
QPushButton(const QString &text, QWidget *parent = nullptr)
QPushButton(QWidget *parent = nullptr)
virtual	~QPushButton()
bool	autoDefault() const
bool	isDefault() const
bool	isFlat() const
QMenu *	menu() const
void	setAutoDefault(bool)
void	setDefault(bool)
void	setFlat(bool)
void	setMenu(QMenu *menu)
Reimplemented Public Functions
virtual QSize	minimumSizeHint() const override
virtual QSize	sizeHint() const override
Public Slots
void	showMenu()
Protected Functions
virtual void	initStyleOption(QStyleOptionButton *option) const
Reimplemented Protected Functions
virtual bool	event(QEvent *e) override
virtual void	focusInEvent(QFocusEvent *e) override
virtual void	focusOutEvent(QFocusEvent *e) override
virtual bool	hitButton(const QPoint &pos) const override
virtual void	keyPressEvent(QKeyEvent *e) override
virtual void	mouseMoveEvent(QMouseEvent *e) override
virtual void	paintEvent(QPaintEvent *) override

 Class QRadioButton
Header:	#include <QRadioButton>
CMake:	find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(mytarget PRIVATE Qt6::Widgets)
qmake:	QT += widgets
Inherits:	QAbstractButton
List of all members, including inherited members
Public Functions
QRadioButton(const QString &text, QWidget *parent = nullptr)
QRadioButton(QWidget *parent = nullptr)
virtual	~QRadioButton()
Reimplemented Public Functions
virtual QSize	minimumSizeHint() const override
virtual QSize	sizeHint() const override
Protected Functions
virtual void	initStyleOption(QStyleOptionButton *option) const
Reimplemented Protected Functions
virtual bool	event(QEvent *e) override
virtual bool	hitButton(const QPoint &pos) const override
virtual void	mouseMoveEvent(QMouseEvent *e) override
virtual void	paintEvent(QPaintEvent *) override


QRadioButton *button = new QRadioButton("Search from the &cursor", this);


*/



#endif // IWIDGET_H

/** \brief

Context	Functions and Properties

Window functions

	show(), hide(), raise(), lower(), close().
Top-level windows

	windowModified, windowTitle, windowIcon, isActiveWindow, activateWindow(), minimized, showMinimized(), maximized, showMaximized(), fullScreen, showFullScreen(), showNormal().
Window contents

	update(), repaint(), scroll().
Geometry

pos, x(), y(), rect, size, width(), height(), move(), resize(), sizePolicy, sizeHint(), minimumSizeHint(), updateGeometry(), layout(), frameGeometry, geometry, childrenRect, childrenRegion, adjustSize(), mapFromGlobal(), mapToGlobal(), mapFromParent(), mapToParent(), maximumSize, minimumSize, sizeIncrement, baseSize, setFixedSize()
Mode

visible, isVisibleTo(), enabled, isEnabledTo(), modal, isWindow(), mouseTracking, updatesEnabled, visibleRegion().
Look and feel

style(), setStyle(), styleSheet, cursor, font, palette, backgroundRole(), setBackgroundRole(), fontInfo(), fontMetrics().
Keyboard focus functions

	focus, focusPolicy, setFocus(), clearFocus(), setTabOrder(), setFocusProxy(), focusNextChild(), focusPreviousChild().
Mouse and keyboard grabbing
	grabMouse(), releaseMouse(), grabKeyboard(), releaseKeyboard(), mouseGrabber(), keyboardGrabber().
Event handlers
	event(), mousePressEvent(), mouseReleaseEvent(), mouseDoubleClickEvent(), mouseMoveEvent(), keyPressEvent(), keyReleaseEvent(), focusInEvent(), focusOutEvent(), wheelEvent(), enterEvent(), leaveEvent(), paintEvent(), moveEvent(), resizeEvent(), closeEvent(), dragEnterEvent(), dragMoveEvent(), dragLeaveEvent(), dropEvent(), childEvent(), showEvent(), hideEvent(), customEvent(). changeEvent(),
System functions
	parentWidget(), window(), setParent(), winId(), find(), metric().
Context menu
	contextMenuPolicy, contextMenuEvent(), customContextMenuRequested(), actions()
Interactive help
	setToolTip(), setWhatsThis()
 */
