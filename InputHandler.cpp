#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;



bool InputHandler::MousePointInRect(SDL_Point p,SDL_Rect r)
{

    return SDL_PointInRect(&p,&r);
}

bool InputHandler::HasIntersection(SDL_Rect r2,SDL_Rect r1)
{
    if(SDL_HasIntersection(&r2,&r1))
    {
        return true;
    }
    return false;
}

SDL_FRect  InputHandler::HasPointinRects(float x,float y,SDL_FRect *r, int Size)
{
    for(int i = 0 ; i < Size; i++)
    {
        SDL_FPoint fpoint =  SDL_FPoint{x,y};
        if(SDL_PointInFRect(&fpoint,&r[i]))
            return r[i];
    }
    return SDL_FRect({0,0,0,0});
}
SDL_Rect  InputHandler::HasPointinRects(float x,float y,SDL_Rect *r, int Size)
{
    for(int i = 0 ; i < Size; i++)
    {
        SDL_Point point =  SDL_Point{x,y};
        if(SDL_PointInRect(&point,&r[i]))
            return r[i];
    }
    return SDL_Rect({0,0,0,0});
}

bool InputHandler::HasIntersection(SDL_FRect r2,SDL_FRect r1)
{
    if(SDL_HasIntersectionF(&r2,&r1))
    {
        return true;
    }
    return false;
}

bool  InputHandler::MousePointInRect(SDL_FPoint p,SDL_FRect r)
{
    SDL_Point pp = {p.x,p.y};
    SDL_Rect rr = {r.x,r.y,r.w,r.h};

    return MousePointInRect(pp,rr);
}

bool InputHandler::GetWindowEvent(SDL_WindowEventID event)
{


    if(event==m_WindowStates)
    {
        m_WindowStates = SDL_WINDOWEVENT_NONE;
        return true;
    }
    else return false;
}

void InputHandler::OnWindowEvent(SDL_Event &event)
{
    switch(event.window.event)
    {
    case SDL_WINDOWEVENT_NONE : /**< Never used */
        std::cout <<"SDL_WINDOWEVENT_NONE \n";
        break;
    case SDL_WINDOWEVENT_SHOWN : /**< Window has been shown */
        std::cout <<"SDL_WINDOWEVENT_SHOWN \n";
        break;
    case SDL_WINDOWEVENT_HIDDEN :    /**< Window has been hidden */
        std::cout <<"SDL_WINDOWEVENT_HIDDEN \n";
        break;
    case SDL_WINDOWEVENT_EXPOSED :   /**< Window has been exposed and should beredrawn */
        std::cout <<"SDL_WINDOWEVENT_EXPOSED \n";
        break;
    case SDL_WINDOWEVENT_MOVED :     /**< Window has been moved to data1, data2*/
        std::cout <<"SDL_WINDOWEVENT_MOVED \n";
        break;
    case SDL_WINDOWEVENT_RESIZED :/**< Window has been resized to data1xdata2 */
        std::cout <<"SDL_WINDOWEVENT_RESIZED \n";
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED :   /**< The window size has changed, either asa result of an API call or through thesystem or user changing the window size. */
        std::cout <<"SDL_WINDOWEVENT_SIZE_CHANGED \n";
        break;
    case SDL_WINDOWEVENT_MINIMIZED  :  /**< Window has been minimized */
        std::cout <<"SDL_WINDOWEVENT_MINIMIZED \n";
        break;
    case SDL_WINDOWEVENT_MAXIMIZED :  /**< Window has been maximized */
        std::cout <<"SDL_WINDOWEVENT_MAXIMIZED \n";
        break;
    case SDL_WINDOWEVENT_RESTORED :   /**< Window has been restored to normal sizeand position */
        std::cout <<"SDL_WINDOWEVENT_RESTORED \n";
        break;
    case SDL_WINDOWEVENT_ENTER :   /**< Window has gained mouse focus */
        std::cout <<"SDL_WINDOWEVENT_ENTER \n";
        break;
    //m_MouseFocus = true;
    case SDL_WINDOWEVENT_LEAVE :          /**< Window has gained keyboard focus */
        std::cout <<"SDL_WINDOWEVENT_LEAVE \n";
        break;
    //  m_MouseFocus = false;
    case SDL_WINDOWEVENT_FOCUS_GAINED :  /**< Window has gained keyboard focus */
        std::cout <<"SDL_WINDOWEVENT_FOCUS_GAINED \n";
        break;
    //m_KeyboardFocus = true;
    case SDL_WINDOWEVENT_FOCUS_LOST : /**< Window has lost keyboard focus */
        std::cout <<"SDL_WINDOWEVENT_FOCUS_LOST \n";
        break;
    //m_KeyboardFocus = false;
    case SDL_WINDOWEVENT_CLOSE :  /**< The window manager requests that the window be closed */
        std::cout <<"SDL_WINDOWEVENT_CLOSE \n";
        break;
    case SDL_WINDOWEVENT_TAKE_FOCUS: /**< Window is being offered a focus (should SetWindowInputFocus() on itself or a subwindow, or ignore) */
        std::cout <<"SDL_WINDOWEVENT_TAKE_FOCUS \n";
        break;
    case SDL_WINDOWEVENT_HIT_TEST: /**< Window had a hit test that wasn't SDL_HITTEST_NORMAL. */
        std::cout <<"SDL_WINDOWEVENT_HIT_TEST \n";
        break;
    }
//std::cout << (char*)event.window.event << "\n";
    m_WindowStates = (Uint8)event.window.type;
}

bool InputHandler::CheckInput(SDL_Scancode key, SDL_Event event)
{
    if (event.key.keysym.scancode == key)
        return true;
    else
        return false;
}
void InputHandler::pushEvent(Sint32 code,std::string data1,std::string data2)
{

            std::cout << "InputHandler::pushEvent\n";

    SDL_Event UserEvent;
    UserEvent.type =  SDL_USEREVENT;
    UserEvent.user.code = code;
    UserEvent.user.data1  = new std::string(data1);
    UserEvent.user.data2 = new std::string(data2);
    SDL_PushEvent(&UserEvent);
}
void InputHandler::HandleEvent(SDL_Event &event)
{
    SDL_GetMouseState(&x,&y);
//   m_keyState = SDL_GetKeyboardState(NULL);
    switch(event.type)
    {
    case SDL_TEXTINPUT :
        if(isTextInputActive())
        {
            std::cout << "isTextInputActive case\n";
            inputText += event.text.text; /*//Add new text onto the end of our textstrcat(text, event.text.text);//  std::cout <<event.text.text <<"\n";           */
        }
        break;
    case SDL_TEXTEDITING :
        if(isTextInputActive())
            std::cout << "TextEditting case\n";        /*//Update the composition text.//Update the cursor position.//Update the selection length (if any).composition = event.edit.text;cursor = event.edit.start;selection_len = event.edit.length;*/
        break;

    case SDL_MOUSEMOTION :
        OnMouseMove(event);
        m_mousePosition.x = event.motion.x;
        m_mousePosition.y = event.motion.y;
        break;


    case SDL_MOUSEBUTTONDOWN :
        OnMouseButtonDown(event);
        m_mousePosition.x = event.motion.x;
        m_mousePosition.y = event.motion.y;
        break;


    case SDL_MOUSEBUTTONUP :
        m_mousePosition.x = event.motion.x;
        m_mousePosition.y = event.motion.y;
        OnMouseButtonUp(event);
        break;


    case SDL_KEYDOWN :
        std::cout << "Key " << (char)event.key.keysym.sym << " "<<
                  ((event.key.state == SDL_PRESSED) ? "pressed" : "released") << "\n";
        OnKeyDown();

        if(m_isTyping)
        {
            //   inputText += event.text.text;
            if(event.type==SDL_KEYDOWN&&event.key.keysym.scancode==SDL_SCANCODE_BACKSPACE)
            {
                if(inputText != "")
                    inputText.pop_back();
            }
        }

        break;
    case SDL_KEYUP:
        std::cout << "Key " << (char)event.key.keysym.sym << " "<<
                  ((event.key.state == SDL_PRESSED) ? "pressed" : "released") << "\n";

        OnKeyUp();
        break;

    case SDL_JOYAXISMOTION :
        OnJoyStickAxisMove( event);
        break;
    case SDL_JOYBUTTONUP :
        OnJoyStickButtonUp( event);
        break;
    case SDL_JOYBUTTONDOWN :
        OnJoyStickButtonDown( event);
        break;
    case SDL_DROPFILE :

        char * file;
        file = event.drop.file;
        std::cout << file << "\n";
        inputDropText = file;
        m_isDropFile = true;
        SDL_free(file);
        break;
    }
}
bool InputHandler::IsDropFile()
{
    return m_isDropFile;
}
std::string InputHandler::GetTextDropFile()
{
    if(IsDropFile())return inputDropText;
    else return "";
}

bool InputHandler::ClearDragFile()
{
    inputDropText = "";
    m_isDropFile = false;
}

void InputHandler::ShowMouse(bool con)
{
    SDL_ShowCursor(con);
}

void InputHandler::StartTextInput()
{
    if(!isTextInputActive())
    {
        m_isTyping = true;
        std::cout <<"SDL_StartTextInput  " <<"\n";
        SDL_StartTextInput();
    }

}
void InputHandler::StopTextInput()
{

    if(isTextInputActive())
    {

        m_isTyping = false;
        inputText = "";
        std::cout <<"SDL_StopTextInput  " <<"\n";
        SDL_StopTextInput();
    }
}
bool InputHandler::isTextInputActive()
{
    return m_isTyping;
}

bool  InputHandler::JoyStickInitialised()const
{
    return m_bJoyStickInitialised;
}
std::string InputHandler::GetTextInput()
{
    return Instance()->inputText;
}


vec2f InputHandler::GetMousePosition() const
{

    return vec2f(x,y);
}

void InputHandler::OnKeyUp()
{
    m_keyState = SDL_GetKeyboardState(NULL);
}
void InputHandler::OnKeyDown()
{
    m_keyState = SDL_GetKeyboardState(0);
}


bool InputHandler::MouseinRect(SDL_FRect r)
{
    SDL_FPoint m = {m_mousePosition.x,m_mousePosition.y};
    return MousePointInRect(m,r);
}
bool InputHandler::MouseinRect(SDL_Rect r)
{
    SDL_Point m = {m_mousePosition.x,m_mousePosition.y};
    return MousePointInRect(m,r);
}
void InputHandler::OnMouseMove(SDL_Event &event)
{
    m_mousePosition.x = event.motion.x;
    m_mousePosition.y = event.motion.y;
}
bool InputHandler::GetMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}
void InputHandler::OnMouseButtonUp(SDL_Event &event)
{
    switch(event.button.button)
    {
    case SDL_BUTTON_LEFT:
        m_mouseButtonStates[LEFT] = false;
        break;
    case SDL_BUTTON_MIDDLE :
        m_mouseButtonStates[MIDDLE] = false;
        break;
    case SDL_BUTTON_RIGHT:
        m_mouseButtonStates[RIGHT] = false;
        break;
    }
}
void InputHandler::OnMouseButtonDown(SDL_Event &event)
{
    switch(event.button.button)
    {
    case SDL_BUTTON_LEFT:
        m_mouseButtonStates[LEFT] = true;
        break;
    case SDL_BUTTON_MIDDLE :
        m_mouseButtonStates[MIDDLE] = true;
        break;
    case SDL_BUTTON_RIGHT:
        m_mouseButtonStates[RIGHT] = true;
        break;
    }
}
bool InputHandler::isKeyDown(SDL_Scancode  key) const
{
    if(m_keyState != 0)
    {
        if(m_keyState[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
void InputHandler::OnJoyStickButtonUp(SDL_Event &event) {}
void InputHandler::OnJoyStickButtonDown(SDL_Event &event) {}
void InputHandler::OnJoyStickAxisMove(SDL_Event &event) {}

bool InputHandler::HasPointinRect(float x,float y,SDL_FRect r)
{
    SDL_FPoint np = SDL_FPoint{x,y};
    return SDL_PointInFRect(&np,&r);
}

bool InputHandler::HasPointinRect( vec2f p,rectangle box)
{

    SDL_FRect frect = SDL_FRect{box.rectTopLeft.x,
                                box.rectTopLeft.y,
                                box.rectBottomRight.x,
                                box.rectBottomRight.x};
    SDL_FPoint fpoint =  SDL_FPoint{p.x,p.y};
    return SDL_PointInFRect(&fpoint,&frect);
}
bool InputHandler::HasPointinRect(SDL_FPoint p,SDL_FRect r)
{
    return SDL_PointInFRect(&p,&r);
}
bool InputHandler::HasPointinRect(vec2f p,SDL_FRect r)
{
    SDL_FPoint np = SDL_FPoint{p.x,p.y};
    return SDL_PointInFRect(&np,&r);
}

bool InputHandler::HasPointinRect(int x,int y,SDL_Rect r)
{
    SDL_Point np = SDL_Point{x,y};
    return SDL_PointInRect(&np,&r);
}
bool InputHandler::HasPointinRect(SDL_Point p,SDL_Rect r)
{
    return SDL_PointInRect(&p,&r);
}
bool InputHandler::HasPointinRect(vec2f p,SDL_Rect r)
{
    SDL_Point np = SDL_Point{p.x,p.y};
    return SDL_PointInRect(&np,&r);
}

bool InputHandler::HasLineinRect(vec2f tail,vec2f head,SDL_Rect r)
{
    SDL_FRect fr = {r.x,r.y,r.w,r.h};
    float X1,Y1,X2,Y2;
    X1 = tail.x;
    Y1 = tail.y;
    X2 = head.x;
    Y2 = head.y;
    return SDL_IntersectFRectAndLine(&fr,&X1,&Y1,&X2,&Y2);

}
SDL_Rect InputHandler::UnionRect(SDL_Rect a,SDL_Rect b)
{

    SDL_Rect result;

    SDL_UnionRect(&a,&b,&result);
    //std::cout << result.x << "x" << result.y << "y" <<result.w<< "w" <<result.h << "h\n" ;
    return result;
}


SDL_FRect InputHandler::UnionRectF(SDL_FRect a,SDL_FRect b)
{

    SDL_FRect result;

    SDL_UnionFRect(&a,&b,&result);
    return result;
    //  std::cout << result.x << "x" << result.y << "y" <<result.w<< "w" <<result.h << "h\n" ;

}


SDL_Rect   InputHandler::UnionRects(SDL_Rect *rects,int RectCount)
{
    SDL_Rect  *t = &rects[0];
    int counter = 0;
    SDL_Rect  temp  = *t;

    while(counter<5)
    {
        temp = UnionRect(*t,temp);
//        std::cout << t->x << " " << t->y << " " << t->w << " " << t->h << " \n";
//std::cout << &t->x << " " << &t->y << " " << &t->w << " " << &t->h << " \n";
        t++;
        counter++;
    }
    return temp;

}


SDL_FRect   InputHandler::UnionRects(SDL_FRect *rects,int RectCount)
{
    SDL_FRect  *t = &rects[0];
    int counter = 0;
    SDL_FRect  temp  = *t;

    while(counter<5)
    {
        temp = UnionRectF(*t,temp);
//        std::cout << t->x << " " << t->y << " " << t->w << " " << t->h << " \n";
//std::cout << &t->x << " " << &t->y << " " << &t->w << " " << &t->h << " \n";
        t++;
        counter++;
    }
    return temp;

}

SDL_FRect InputHandler::EnclosePoints(SDL_FPoint * point,int Count,SDL_FRect clip)
{
    SDL_FRect result;

    SDL_EncloseFPoints(point,Count,&clip,&result);


    return result;
}

SDL_Rect InputHandler::EnclosePoints(SDL_Point * point,int Count,SDL_Rect clip)
{
    SDL_Rect result;

    SDL_EnclosePoints(point,Count,&clip,&result);


    return result;
}
//   case SDL_WINDOWEVENT :
//OnWindowEvent(event);
//       break;
//
//        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_1)
//        {
//            std::cout << m_pGameStateMachine->GetCurrentStateID()<< "\n";
//            inputText = "";
//            SDL_StartTextInput();
//        }

//        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_2)
//        {
//            //   isRenderText = true;
//            isTyping = false;
//            SDL_StopTextInput();
//        }
//        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_3)
//        {
//            isTextSemibold = true;
//        }
//        if(e.type==SDL_KEYDOWN&&e.key.keysym.scancode==SDL_SCANCODE_4)
//        {
//            isTextSemibold = false;
//        }
//        if(e.type==)
//        {
//            inputText += e.text.text;
//
//
//        }
//        if(e.type==)
//        {
//            std::cout <<"SDL_TEXTEDITING  " <<"\n";
//            SDL_Rect a = {0,0,1000,1000};
//            SDL_SetTextInputRect(&a);
//            composition = e.edit.text;
//            m_cursor = e.edit.start;
//            m_selection_length = e.edit.length;
//
//        }c
