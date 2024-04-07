#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <sstream>
#include <string.h>

//
#include <IWidget.h>
class Window
{
public:
    Window(std::string Title,int x, int y, int w, int h,Uint32 flags,IWidget* widget  = NULL);
    virtual ~Window();
    // bool init(const char* title,int xpos,int ypos,int w,int h,float RefreshRate = 0,float resScaler= 0,bool fullscreen= 0,int Tile= 0,int column= 0,int row);
    bool FreePopUpWindow();


  int GetWindowMaximumWidth();
 int  GetWindowMaximumHeight();

   IWidget *GetWidget();
    SDL_Window *GetWindow();
  void AddPopUpWindow(IWidget * w);
  void closePopUp();
//    void  clearWidget(){};
    std::string GetTitle();
    void SetWindowTitle(std::string title);
    void SetColour(char r,char g, char b, char a);
    void SetPosition(int x, int y);
    void SetFrameStart();

    bool IsMinimize();
    bool IsMouseFocus();
    bool IsKeyboardFocus();
    void IsResizable(bool Resizeable);
    bool IsFocus();
    SDL_Colour m_oldColour;
    SDL_Color GetColour();

    float getAspectRaito();
    int GetWidth();
    int GetHeight();

    int getColumn();
    int getRow();

SDL_Rect GetDisplayBounds(){
    SDL_Rect rect; SDL_GetDisplayBounds(0,&rect); return rect;

    }
    bool SetIsFullScreenAble(bool con);
    void HandleEvent(SDL_Event& e);
    void ClearDisplay();
    void ResizeWindow(int w,int h);
    void RescaleWindow(float  s);
    void Render(SDL_Renderer *r);
    void HasWINDOWEVENT_LEAVE();
    void HasWINDOWEVENT_ENTER();

    void update(float deltaTime);
void HideWindow();
    void ShowWindow();
    bool IsFullScreen(); void SetMinimizeWindow();
    void SetFullScreen(Uint32 flags);
    bool RestoreWindow();


SDL_Rect GetWindowRect();
  vec2f GetOrigin();
// *  \sa SDL_GetNumDisplayModes()
// *  \sa SDL_GetDisplayMode()
// *  \sa SDL_GetDesktopDisplayMode()
// *  \sa SDL_GetCurrentDisplayMode()
// *  \sa SDL_GetClosestDisplayMode()
// *  \sa SDL_SetWindowDisplayMode()
// *  \sa SDL_GetWindowDisplayMode()

//   void CreateWindowFrom(const void *data);
//   void DestroyWindow();
//   void GetWindowData(SDL_Window * window,const char *name);
//   void GetWindowFlags(SDL_Window * window);
//   void GetWindowGrab(SDL_Window * window);
//   void GetWindowPosition(SDL_Window * window,int *x, int *y);
//   void GetWindowSize(SDL_Window * window, int *w,int *h);
//   void GetWindowTitle(SDL_Window * window);
//   void HideWindow(SDL_Window * window);
//   void MaximizeWindow(SDL_Window * window);
//   void MinimizeWindow(SDL_Window * window);
//   void RaiseWindow(SDL_Window * window);
//   void RestoreWindow(SDL_Window * window);
//   void SetWindowData(SDL_Window * window,const char *name);
//   void SetWindowFullscreen(SDL_Window * window,Uint32 flags);
//   void SetWindowGrab(SDL_Window * window,SDL_bool grabbed);
//   void SetWindowIcon(SDL_Window * window,SDL_Surface * icon);
//   void SetWindowPosition(SDL_Window * window,int x, int y);
//   void SetWindowSize(SDL_Window * window, int w, int h);
//   void SetWindowBordered(SDL_Window * window,SDL_bool bordered);
//   void SetWindowResizable(SDL_Window * window,SDL_bool resizable);
//   void SetWindowTitle(SDL_Window * window,const char *title);
//   void ShowWindow(SDL_Window * window);


//   void Cmd_CreateWindow(const char *title,int x, int y, int w,int h, Uint32 flags);
//   void Cmd_CreateWindowFrom(const void *data);
//   void Cmd_DestroyWindow();
//   void Cmd_GetWindowData(SDL_Window * window,const char *name);
//   void Cmd_GetWindowFlags(SDL_Window * window);
//   void Cmd_GetWindowGrab(SDL_Window * window);
//   void Cmd_GetWindowPosition(SDL_Window * window,int *x, int *y);
//   void Cmd_GetWindowSize(SDL_Window * window, int *w,int *h);
//   void Cmd_Cmd_GetWindowTitle(SDL_Window * window);
//   void Cmd_Cmd_HideWindow(SDL_Window * window);
//   void Cmd_Cmd_MaximizeWindow(SDL_Window * window);
//   void Cmd_MinimizeWindow(SDL_Window * window);
//   void Cmd_RaiseWindow(SDL_Window * window);
//   void Cmd_RestoreWindow(SDL_Window * window);
//   void Cmd_SetWindowData(SDL_Window * window,const char *name);
//   void Cmd_SetWindowFullscreen(SDL_Window * window,Uint32 flags);
//   void Cmd_SetWindowGrab(SDL_Window * window,SDL_bool grabbed);
//   void Cmd_SetWindowIcon(SDL_Window * window,SDL_Surface * icon);
//   void Cmd_SetWindowPosition(SDL_Window * window,int x, int y);
//   void Cmd_SetWindowSize(SDL_Window * window, int w, int h);
//   void Cmd_SetWindowBordered(SDL_Window * window,SDL_bool bordered);
//   void Cmd_SetWindowResizable(SDL_Window * window,SDL_bool resizable);
//   void Cmd_SetWindowTitle(SDL_Window * window,const char *title);
//   void Cmd_ShowWindow(SDL_Window * window);

protected:

private:
    Uint32 m_WindowFlags = 0;
   std::vector<IWidget*>m_windowsWidget;

    bool isFullScreenAble = false;
    int m_maxHieght = 0;
    int m_maxWidth = 0;
    float m_aspectRaito = 0.0f;
    float m_resolutionScaler = 0.0f;
    std::string m_title;
    SDL_Window *m_Win = NULL;
    bool m_bReSizeable = false;
    bool m_fullScreen = false;
    bool m_Minimize = false;
    bool m_MouseFocus = true;
    bool m_KeyboardFocus = true;
};

#endif // WINDOW_H


//#define WINDOW_SCALE 1
//#define WINDOW_HEIGHT  720
//#define WINDOW_WIDTH 1280

//bool SDL_CreateWindow(std::string Title,vec2f position,vec2f ,Uint32 flags)
//              int Title,
//              vec2fMaxYpos;;
//              float RefreshRate;,
//              float resScaler;,
//              bool fullscreen;,
//              int Tile;,
//              int column;,
//              int rowk;);



