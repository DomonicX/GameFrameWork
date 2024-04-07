#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
//#include "GL/glew.h"
//#include <GL/glu.h>
//#include <GL/glext.h>
//#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>


#include <cstdio>
#include <limits>
#include <cstdint>
#include <cinttypes>
#include <GameStateMachine.h>
#include <time.h>
#include <Window.h>
#include <Camera.h>
#include <vector>
#include <list>
#include <iostream>
#include <string.h>
#include <stack>
#include <Logger.h>

#include <IWidget.h>
#define Colour_MarioBackGround_ {147, 187, 236}
#include <Render.h>
#include <Vector2D.h>
#include <State_BlankScreen.h>
#include <TestState.h>
#include <LTimer.h>


typedef enum
{
_NA_,
_DEBUG_,
_GAME_,
_RESTART_,
_TERMINATE_,

} GAME_ENGINE_FLAG;

class Application
{
private:
//IWidget * m_widget = NULL;



    static Application * s_pInstance;
    int userType;

    Window *m_window = nullptr;
    GameStateMachine *m_pGameStateMachine;
    Camera m_camera;
    LTimer m_Timer;

std::stringstream logg;
    bool m_bRunning= false;
    double m_frameDelay = 0.0;
    double m_frameStart =0;
    int m_frameRate = 0;
    double m_deltaTime = 0;



    Application();
    ~Application();
public:
    static Application* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new Application();
        }
        return s_pInstance;

    }
SDL_DisplayMode m_DisplayMode ;
  SDL_RendererInfo m_Renderer_info;

ShowSimpleMessageBox(Uint32 flags = SDL_MESSAGEBOX_ERROR, const char *title = "Error", const char *message = "ERROR : CreateWindow", SDL_Window *window = NULL);
std::stringstream m_AppInfoStr;
    SDL_Renderer*  m_ren = NULL;
    int GetGameTime();
    double GetDeltaTime();
//    void SetWidgetWindow(IWidget* winImp);
    Window* GetWindow();
    Camera& GetCamera();
    GameStateMachine*   GetStateMachine() ;
    SDL_Renderer* GetRenderer() const ;
     std::string GetEngineflag();
GAME_ENGINE_FLAG m_AppEditorFlag = GAME_ENGINE_FLAG::_NA_;
    //  Logger GetLogger();
    bool Init(const char *Title= "GameEngine", int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED, int w = 640,int h = 480 ,Uint32 flags = SDL_WINDOW_HIDDEN,std::string State = "TestState", IWidget* widget = NULL);
vec2f GetMousePosition() const ;
    void Draw();
    int x = 0;
     int y = 0;
    void Update();
    void HandleEvent( );
    void Clean();
    void quit(void);
    void Restart(void);
    bool running();
  const int GetFps();
  float GetAspectRatio()const ;
  double m_aspectRatio = 0.0f;
  float m_scale= 0.0f;
void PushEvent(int code, void* data1, void* data2);

    // GUI_Wigdet * GetWigdet();

protected:
// acc += jerk * time /only need if acc isnt constant
// speed += acc * time /the current velocity given acceaction
// pos += speed * time /the position given vel
//
//1 .  a = a;
// 2. v = at+v0
// 3. s = .5at^2 + v0*t + s0

};
/**<
    if(e.button.type == SDL_MOUSEBUTTONDOWN && e.button.state == SDL_PRESSED)
    {
                std::cout << "SDL_PRESSED\n";

    }
    if(e.button.type == SDL_MOUSEBUTTONUP && e.button.state == SDL_RELEASED)
    {
        std::cout << "SDL_RELEASED\n";
    } */
 static Uint32 callbackj( Uint32 interval, void* param )
 {

//Application::Instance()->Draw();
    //APP->GetWindow()->SetMinimizeWindow();
    //Print callback message
//SDL_TimerID timerID = SDL_AddTimer(1000/(float)60, callbackj,  (char*)" a"  );
  //  std::cout << SDL_GetTicks() << "\n";
    printf( "Callback called back with message: %s\n  %i \n", reinterpret_cast<char*>(param));

                std::cout << "\n"<<SDL_GetTicks()<< "\n";

    return 0;
}

/**<

bool running = true;
while (running) {

	Uint64 start = SDL_GetPerformanceCounter();

	// Do event loop

	// Do physics loop

	// Do rendering loop

	Uint64 end = SDL_GetPerformanceCounter();

	float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

	// Cap to 60 FPS
	SDL_Delay(floor(16.666f - elapsedMS));

}


*/


#define  APP Application::Instance()
#define  WindowWidth APP->GetWindow()->GetWidth()
#define  CAMRECT APP->GetCamera().GetRect()
#define  CAMCENTRE APP->GetCamera().GetCentre()
#define  CAMSCALER APP->GetCamera().GetScaler()
#define  WindowHeight APP->GetWindow()->GetHeight()
#define  WindowOrigin  APP->GetWindow()->GetOrigin()
#define  WindowRect  APP->GetWindow()->GetWindowRect()
#define MOUSEPOSITION APP->GetMousePosition()

#endif // APPLICATION_H

//
//
//class SoundManager
//{
//public:
//
////    std::map<std::string, *>m_TextureMap;
////};
