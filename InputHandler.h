#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <vector>
#include <SDL2/SDL.h>
#include <Vector2D.h>
#include <iostream>
#include <map>
#include <sstream>

enum mouse_Buttons
{
    LEFT = 1,
    MIDDLE = 2,
    RIGHT = 3
};
class InputHandler
{
public:

    static InputHandler* Instance()
    {

        if(s_pInstance == 0)
        {

            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
//    bool IntersectFRect(SDL_FRect r1,SDL_FRect r2,SDL_FRect result){SDL_IntersectRect(&r1,&r2,&result)}
    void InitialiseJoyStick();
    bool JoyStickInitialised()const;
    void Reset();
    void HandleEvent(SDL_Event &event);
    void Clean() {};
    bool MousePointInRect(SDL_FPoint p,SDL_FRect r);
    bool MousePointInRect(SDL_Point p,SDL_Rect r);
    bool MouseinRect(SDL_FRect r);
    bool MouseinRect(SDL_Rect r);

    SDL_FRect HasPointinRects(float x,float y,SDL_FRect *r, int Size);
    SDL_Rect HasPointinRects(float x,float y,SDL_Rect *r, int Size);

    bool HasPointinRect(float x,float y,SDL_FRect r);
    bool HasPointinRect(SDL_FPoint p,SDL_FRect r);
    bool HasPointinRect(vec2f p,rectangle box);
    bool HasPointinRect(vec2f p,SDL_FRect r);

    bool HasPointinRect(int x,int y,SDL_Rect r);
    bool HasPointinRect(SDL_Point p,SDL_Rect r);
    bool HasPointinRect(vec2f p,SDL_Rect r);

    bool HasIntersection(SDL_FRect r2,SDL_FRect r1);
    bool HasIntersection(SDL_Rect r2,SDL_Rect r1);

    bool HasLineinRect(vec2f tail,vec2f head,SDL_Rect r);

    SDL_Rect  UnionRect(SDL_Rect a,SDL_Rect b);

    SDL_Rect  UnionRects(SDL_Rect *rects,int RectCount);
    SDL_FRect  UnionRects(SDL_FRect *rects,int RectCount);

    SDL_FRect UnionRectF(SDL_FRect a,SDL_FRect b);

    SDL_FRect EnclosePoints(SDL_FPoint * point,int Count,SDL_FRect clip);
    SDL_Rect EnclosePoints(SDL_Point * point,int Count,SDL_Rect clip);
    bool GetButtonState(int joy, int buttonNumber) const;
    bool GetMouseButtonState(int buttonNumber);
    vec2f GetMousePosition() const;
    bool isKeyDown(SDL_Scancode  key) const;
    void ShowMouse(bool con);
    int m_WindowStates;
    bool GetWindowEvent(SDL_WindowEventID event);
    std::string GetTextInput();
    bool isTextInputActive();
    void StartTextInput();
    void StopTextInput();
    char Key_StopText()
    {
        return SDL_SCANCODE_X;
    }

    int GetSize()
    {
        return (int)m_buttonStates.size();
    }
    bool CheckInput(SDL_Scancode key, SDL_Event event);
//    bool SetAppState()
//    {
//        sdl_userEventSTATE = SDL_RegisterEvents(1);
//        if (sdl_userEventSTATE == ((uint32_t) -1))
//        {
//            SDL_LogMessage(SDL_LOG_CATEGORY_ERROR,SDL_LogPriority::SDL_LOG_PRIORITY_CRITICAL,"Error.. userType EVENT register Fail\n");
//            return false;
//        }
//        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LogPriority::SDL_LOG_PRIORITY_INFO,"sdl_userEventSTATE\n");
//        std::cout << sdl_userEventSTATE << "\n";
//        return true;
//    };
    void pushEvent(Sint32 code,std::string data1,std::string data2);


    void registerNewEventcode(std::string eventName)
    {
        iUserEvents[eventName] = userEvents++;
    }
    Uint32 GetEventCode(std::string eventName)
    {
        return iUserEvents[eventName];
    }
    int userEvents = 0;
    std::string GetTextDropFile();

    bool ClearDragFile();
    std::string Get_OS()
    {
        return SDL_GetPlatform();
    }
protected:

private:

    std::string m_OS;
    std::string Data1;
    std::string  Data2;
    bool IsDropFile();
    Uint32 sdl_userEventSTATE = 0;
   int x =0;int  y=0;

    std::map<std::string,Uint32>iUserEvents;

    InputHandler() : m_keyState(new Uint8(0)), m_bJoyStickInitialised(false), m_mousePosition(vec2f(-1,-1))
    {
        for(int i = 0; i < 3; i++)
        {
            m_mouseButtonStates.push_back(false);
        }
        m_WindowStates = 0;
        inputText = "";
        m_isTyping = false;

//    if(Instance()->isTextInputActive())
        //       Instance()->StopTextInput();
    }

    ~InputHandler()
    {
        //dtor
    }

    char *text = NULL;
    char *composition= NULL;
    Sint32 cursor = 0;
    Sint32 selection_len = 0;


    std::string inputText;
    std::string  inputDropText;
    std::stringstream inputSteam;

    bool m_isTyping = false;
    bool m_isDropFile = false;
    void OnKeyUp();
    void OnKeyDown();
    void OnMouseMove(SDL_Event &event);
    void OnMouseButtonDown(SDL_Event &event);
    void OnMouseButtonUp(SDL_Event &event);

    void OnJoyStickButtonUp(SDL_Event &event);
    void OnJoyStickButtonDown(SDL_Event &event);
    void OnJoyStickAxisMove(SDL_Event &event);
    const Uint8 *m_keyState;

    std::vector<std::pair<vec2f*,vec2f*>>m_joyStickValues;
    std::vector<SDL_Joystick*>m_joystick;
    std::vector<bool> m_mouseButtonStates;

    std::vector<std::vector<bool>> m_buttonStates;
    bool m_bJoyStickInitialised;
    static const int m_joystickDeadZone = 10000;
    vec2f m_mousePosition = vec2f();
    bool m_MouseFocus = true;
    bool m_KeyboardFocus = true;
    void OnWindowEvent(SDL_Event &event);
    static InputHandler* s_pInstance;
    bool isReleased =  false;
    bool isPressed = false;

};
#define INPUTHANDLER InputHandler::Instance()
#endif // INPUTHANDLER_H
