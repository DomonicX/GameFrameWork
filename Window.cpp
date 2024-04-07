#include "Window.h"
//      ::SDL_WINDOW_FULLSCREEN,    ::SDL_WINDOW_OPENGL,
// *               ::SDL_WINDOW_HIDDEN,        ::SDL_WINDOW_BORDERLESS,
// *               ::SDL_WINDOW_RESIZABLE,     ::SDL_WINDOW_MAXIMIZED,
// *               ::SDL_WINDOW_MINIMIZED,     ::SDL_WINDOW_INPUT_GRABBED,
// *               ::SDL_WINDOW_ALLOW_HIGHDPI, ::SDL_WINDOW_VULKAN.

Window::Window(std::string Title,int x, int y, int w, int h,Uint32 flags,IWidget* widget)
    : m_title(Title)
{
m_WindowFlags = flags;
    m_resolutionScaler = 0;
    m_aspectRaito = 0;
    m_Win = nullptr;
    m_fullScreen = false;
    m_Minimize = false;
    m_KeyboardFocus = false;
    m_MouseFocus = false;
    isFullScreenAble = false;
    m_Win = SDL_CreateWindow(m_title.c_str(),x,y,w,h,m_WindowFlags);
    if(m_Win==nullptr)
    {
        std::cout << SDL_GetError() << "\n";
        SDL_ClearError();
    }
    m_windowsWidget.push_back(widget);
  //  dynamic_cast<Gui::WindowImp*>(
//        m_windowsWidget.back())->SetContext(*m_Win);
       m_windowsWidget.back()->SetFocus(true);
//    AddPopUpWindow(widget);


//        SDL_SetWindowResizable(m_Win,SDL_TRUE);

}
  int Window::GetWindowMaximumWidth(){
       int WindowMaximumWidth = 0;
    SDL_GetWindowMaximumSize(m_Win,&WindowMaximumWidth,NULL);
    return WindowMaximumWidth;
  }
  int Window::GetWindowMaximumHeight(){
       int WindowMaximumHeight = 0;
    SDL_GetWindowMaximumSize(m_Win,NULL,&WindowMaximumHeight);
    return WindowMaximumHeight;
  }

    bool Window::SetIsFullScreenAble(bool con){isFullScreenAble = con;}
SDL_Rect Window::GetWindowRect()
{
    return {0,0,GetWidth(),GetHeight()};
}
vec2f Window::GetOrigin()
{
     return vec2f( GetWidth()*0.5, GetHeight()*0.5);
}

void Window::HideWindow()
{
    SDL_HideWindow(m_Win);
}
void Window::ShowWindow()
{
    SDL_ShowWindow(m_Win);
}
bool Window::IsFullScreen()
{
    return m_fullScreen;
};
void Window::SetMinimizeWindow()
{
    SDL_MinimizeWindow(m_Win);
}
void Window::SetFullScreen(Uint32 flags)
{
    SDL_SetWindowFullscreen(m_Win,flags);
}
bool Window::RestoreWindow()
{
    SDL_RestoreWindow(m_Win);
}
Window::~Window()
{
    for(int i = 0; i < m_windowsWidget.size(); i++)
        delete m_windowsWidget[i];
    m_windowsWidget.clear();
    //dtor
    std::cout << "DESTOYING WINDOW\n";
    SDL_DestroyWindow(m_Win);
}

void Window::Render(SDL_Renderer *r)
{
    for(int i = 0; i < m_windowsWidget.size(); i++)
        m_windowsWidget[i]->Render(r);

}
void Window::IsResizable(bool Resizeable)
{
    m_bReSizeable = Resizeable;
    SDL_SetWindowResizable(m_Win, (SDL_bool)m_bReSizeable);
}
void  Window::HandleEvent(SDL_Event& e)
{

    for(int i = 0; i < m_windowsWidget.size(); i++)
        m_windowsWidget[i]->HandleEvent(e);

    if(e.type == SDL_WINDOWEVENT)
    {
        std::cout << (Uint8)e.type << "SDL_WINDOWEVENT\n\n";

        if(isFullScreenAble)   if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
            {
                m_fullScreen = true;
                SDL_SetWindowFullscreen(m_Win,true);
            }
    }//    case SDL_WINDOWEVENT_MINIMIZED  :  /**< Window has been minimized */

        //dynamic_cast<Gui::WindowImp*>(m_widget)->isMinimized(true);
  if(e.type == SDL_WINDOWEVENT_MINIMIZED)
    {
        m_Minimize = true;

    }
     if(e.type == SDL_WINDOWEVENT_RESTORED)
    {
        m_Minimize = false;

    }
    bool updateCaption = false;



    if(isFullScreenAble)
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
        {
            if(m_fullScreen)
            {
                m_fullScreen = false;
                SDL_SetWindowFullscreen(m_Win,false);
            }
            else
            {
                SDL_SetWindowFullscreen(m_Win,true);
                m_Minimize = false;
                m_fullScreen = true;
            }
        }

//    switch(e.window.event)
//    {
//    case SDL_WINDOWEVENT_NONE : /**< Never used */
//        break;
//    case SDL_WINDOWEVENT_SHOWN : /**< Window has been shown */
//        break;
//    case SDL_WINDOWEVENT_HIDDEN :    /**< Window has been hidden */
//        break;
//    case SDL_WINDOWEVENT_EXPOSED :   /**< Window has been exposed and should beredrawn */
//
//        break;
//    case SDL_WINDOWEVENT_MOVED :     /**< Window has been moved to data1, data2*/
//        break;
//    case SDL_WINDOWEVENT_RESIZED :/**< Window has been resized to data1xdata2 */
//
//        break;
//    case SDL_WINDOWEVENT_SIZE_CHANGED :   /**< The window size has changed, either asa result of an API call or through thesystem or user changing the window size. */
//        break;

//    case SDL_WINDOWEVENT_MAXIMIZED :  /**< Window has been maximized */
//        m_Minimize = false;
//        break;
//    case SDL_WINDOWEVENT_RESTORED :   /**< Window has been restored to normal sizeand position */
//        //  dynamic_cast<Gui::WindowImp*>(m_widget)->isMinimized(false);
//        m_Minimize =false;
//        break;
////    case SDL_WINDOWEVENT_ENTER :   /**< Window has gained mouse focus */
////
////    m_MouseFocus = true;
////        if(m_widget!=NULL)
////        dynamic_cast<Gui::WindowImp*>(m_widget)->isKeyboardFocus(m_MouseFocus);
////        break;
////    case SDL_WINDOWEVENT_LEAVE : /**< Window has gained keyboard focus */
////
////    m_MouseFocus = false;
////        if(m_widget!=NULL)
////        dynamic_cast<Gui::WindowImp*>(m_widget)->isKeyboardFocus(m_MouseFocus);
////        break;
////    case SDL_WINDOWEVENT_FOCUS_GAINED :  /**< Window has gained keyboard focus */
////
////        m_KeyboardFocus = true;
////        if(m_widget!=NULL)
////        dynamic_cast<Gui::WindowImp*>(m_widget)->isKeyboardFocus(m_KeyboardFocus);
////        break;
////    case SDL_WINDOWEVENT_FOCUS_LOST : /**< Window has lost keyboard focus */
////
////        m_KeyboardFocus = false;
////        if(m_widget!=NULL)
////        dynamic_cast<Gui::WindowImp*>(m_widget)->isKeyboardFocus(m_KeyboardFocus);
////        break;
//    case SDL_WINDOWEVENT_CLOSE :  /**< The window manager requests that the window be closed */
//        break;
//    case SDL_WINDOWEVENT_TAKE_FOCUS: /**< Window is being offered a focus (should SetWindowInputFocus() on itself or a subwindow, or ignore) */
//        break;
//    case SDL_WINDOWEVENT_HIT_TEST: /**< Window had a hit test that wasn't SDL_HITTEST_NORMAL. */
//
//        break;
//
//    }



}

void Window::RescaleWindow(float s)
{

    SDL_SetWindowSize(m_Win,GetWidth()*s,GetHeight()*s);
}
void Window::ResizeWindow(int w,int h)
{
    SDL_SetWindowSize(m_Win,w,h);
}
void Window::SetPosition(int x, int y)
{
    SDL_SetWindowPosition(m_Win,x,y);
}


void Window::HasWINDOWEVENT_LEAVE()
{
    m_MouseFocus = false;
}
void Window::HasWINDOWEVENT_ENTER()
{
    m_MouseFocus = true;
}
void Window::update(float deltaTime)
{
    for(int i = 0; i < m_windowsWidget.size(); i++)
        m_windowsWidget[i]->Update(deltaTime);
}
SDL_Window *Window::GetWindow()
{
    return m_Win;
}
IWidget *Window::GetWidget()
{
    return m_windowsWidget.back();
}
std::string Window::GetTitle()
{
    return m_title;
}
bool Window::FreePopUpWindow()
{
    bool con = true;
    if(m_windowsWidget.size()>1)
    {
        delete m_windowsWidget.back();
        m_windowsWidget.pop_back();
    }
    return con;
}
int Window::GetWidth()
{
    int windowWidth;
    SDL_GetWindowSize(m_Win,&windowWidth,NULL);

    return windowWidth;
}
int Window::GetHeight()
{
    int windowHeight;
    SDL_GetWindowSize(m_Win,NULL,&windowHeight);

    return windowHeight;
}
bool Window::IsMinimize()
{
    return m_Minimize;
}
bool Window::IsMouseFocus()
{
    if(!m_windowsWidget.empty())
        return dynamic_cast<Gui::WindowImp*>( m_windowsWidget.back())->HasMouseFocus();
}
bool Window::IsKeyboardFocus()
{
    if(!m_windowsWidget.empty())
        return dynamic_cast<Gui::WindowImp*>( m_windowsWidget.back())->HasKeyboardFocus();
}
float Window::getAspectRaito()
{
    return GetWidth()/(float)GetHeight();
}

bool  Window::IsFocus()
{
    if(IsKeyboardFocus() && IsMouseFocus())
        return true;
    else
        return false;
}
void Window::AddPopUpWindow(IWidget * w)
{
    if(!m_windowsWidget.empty())
        m_windowsWidget.back()->SetFocus(false);

    m_windowsWidget.push_back(w);
//    dynamic_cast<Gui::WindowImp*>(w)->SetContext(*m_Win);
        m_windowsWidget.back()->SetFocus(true);

//void Window::clearWidgets()
//{
////    delete m_widget; doesnt work
////    m_widget = NULL;
//}


}
void Window::closePopUp()
{
    if(m_windowsWidget.size()>1)
    {

       delete m_windowsWidget.back();
       m_windowsWidget.pop_back();

        m_windowsWidget.back()->SetFocus(true);
    }
}

void Window::SetWindowTitle(std::string title)
{
    m_title = title;
    SDL_SetWindowTitle(m_Win,m_title.c_str());
}




//
//    void Window::CreateWindowFrom(const void *data)
//    void Window::DestroyWindow()
//    void Window::GetWindowData(SDL_Window * window,const char *name)
//    void Window::GetWindowFlags(SDL_Window * window)
//    void Window::GetWindowGrab(SDL_Window * window)
//    void Window::GetWindowPosition(SDL_Window * window,int *x, int *y)
//    void Window::GetWindowSize(SDL_Window * window, int *w,int *h)
//    void Window::GetWindowTitle(SDL_Window * window)
//    void Window::HideWindow(SDL_Window * window)
//    void Window::MaximizeWindow(SDL_Window * window)
//    void Window::MinimizeWindow(SDL_Window * window)
//    void Window::RaiseWindow(SDL_Window * window)
//    void Window::RestoreWindow(SDL_Window * window)
//    void Window::SetWindowData(SDL_Window * window,const char *name)
//    void Window::SetWindowFullscreen(SDL_Window * window,Uint32 flags)
//    void Window::SetWindowGrab(SDL_Window * window,SDL_bool grabbed)
//    void Window::SetWindowIcon(SDL_Window * window,SDL_Surface * icon)
//    void Window::SetWindowPosition(SDL_Window * window,int x, int y)
//    void Window::SetWindowSize(SDL_Window *window, int w, int h)
//    void Window::SetWindowBordered(SDL_Window *window,SDL_bool bordered)
//    void Window::SetWindowResizable(SDL_Window *window,SDL_bool resizable)
//    void Window::SetWindowTitle(SDL_Window *window,const char *title)
//    void Window::ShowWindow(SDL_Window *window)
//
//
//
//        SDL_CreateWindowFrom(const void *data);
//        SDL_DestroyWindow();
//        SDL_GetWindowData(SDL_Window * window,const char *name);
//        SDL_GetWindowFlags(SDL_Window * window);
//        SDL_GetWindowGrab(SDL_Window * window);
//        SDL_GetWindowPosition(SDL_Window * window,int *x, int *y);
//        SDL_GetWindowSize(SDL_Window * window, int *w,int *h);
//        SDL_GetWindowTitle(SDL_Window * window);
//        SDL_HideWindow(SDL_Window * window);
//        SDL_MaximizeWindow(SDL_Window * window);
//        SDL_MinimizeWindow(SDL_Window * window);
//        SDL_RaiseWindow  (SDL_Window * window);
//        SDL_RestoreWindow(SDL_Window * window);
//        SDL_GetWindowData(SDL_Window * window,const char *name);
//        SDL_SetWindowFullscreen(SDL_Window * window,Uint32 flags);
//        SDL_SetWindowGrab(SDL_Window * window,SDL_bool grabbed);
//        SDL_SetWindowIcon(SDL_Window * window,SDL_Surface * icon);
//        SDL_SetWindowPosition(SDL_Window * window,int x, int y);
//        SDL_SetWindowSize(SDL_Window * window, int w, int h);
//        SDL_SetWindowBordered(SDL_Window * window,SDL_bool bordered);
//        SDL_SetWindowResizable(SDL_Window * window,SDL_bool resizable);
//        SDL_SetWindowTitle(SDL_Window * window,const char *title);
//        SDL_ShowWindow(SDL_Window * window);
/*

//    case SDL_WINDOWEVENT_LEAVE:
//        std::cout << "sdl_windowevent_leave\n";
//            MouseFocus = false;
//        break;
//    case SDL_WINDOWEVENT_ENTER:
//        std::cout << "SDL_WINDOWEVENT_ENTER\n";
//           MouseFocus = true;
//        break;
//
//    case SDL_WINDOWEVENT_EXPOSED:
//
//        std::cout << "SDL_WINDOWEVENT_EXPOSED\n";
//         SDL_RenderPresent(&_grender);
//        break;


        //case SDL_WINDOWEVENT_SIZE_CHANGED :
            std::cout << "SDL_WINDOWEVENT_SIZE_CHANGED\n";
            width = e.window.data1;
            height = e.window.data2;
            std::cout << "SDL_WINDOWEVENT_SIZE_CHANGED\n " << height;;
            break;


           break;
     //   case SDL_WINDOWEVENT_FOCUS_GAINED:
            std::cout << "SDL_WINDOWEVENT_FOCUS_GAINED\n";
            KeyboardFocus = true;

            updateCaption = true;
            break;
            break;

      //  case SDL_WINDOWEVENT_FOCUS_LOST:
            std::cout << "SDL_WINDOWEVENT_FOCUS_LOST\n";
            KeyboardFocus = false;

            updateCaption = true;
            break;
       // case SDL_WINDOWEVENT_MAXIMIZED:
            std::cout << "SDL_WINDOWEVENT_MAXIMIZED\n";

            Minimize = false;
            break;
       // case SDL_WINDOWEVENT_MINIMIZED:
            std::cout << "SDL_WINDOWEVENT_MINIMIZED\n";
            Minimize = true;
            break;
        //case SDL_WINDOWEVENT_RESTORED:
            std::cout << "SDL_WINDOWEVENT_RESTORED\n";
            Minimize = false;
            break;
  //

           // Mouse left window
            case SDL_WINDOWEVENT_LEAVE:
            mMouseFocus = false;
            updateCaption = true;
            break;

         //   Window has keyboard focus
            case SDL_WINDOWEVENT_FOCUS_GAINED:
            mKeyboardFocus = true;
            updateCaption = true;
            break;

          //  Window lost keyboard focus
            case SDL_WINDOWEVENT_FOCUS_LOST:
            mKeyboardFocus = false;
            updateCaption = true;
            break;

 */
