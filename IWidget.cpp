#include "IWidget.h"
IWidget::IWidget() {}
IWidget::~IWidget() {}

Gui::WindowImp::~WindowImp()
{
    std::cout << "DESTOYING WindowImp\n";
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
    m_children.clear();
}

void IWidget::Init(std::string Title,SDL_Rect HitBox)
{
    SetTitle(Title);
    SetHitBox(HitBox);
}


IWidget* IWidget::Find(std::string str)
{
    if(str==GetTitle())
    {
        return this;
    }
    for(int i = 0 ; i < GetChildSize(); i++)
    {
        IWidget* temp = GetChild(i).Find(str);
        if(temp)
            return temp;
    }
    return NULL;
}

void IWidget::ChangeText(SDL_Renderer* r,std::string newText, std::string FontID)
{
    text.ChangeText(newText,FontManager::Instance()->GetFont("OpenSans-Regular"),r);

    m_hitBox.w = text.GetBounds().w ;
    m_hitBox.h = text.GetBounds().h;

};
void Gui::MenuBar::SetHorizontal()
{
    std::cout << GetChildSize() <<" -Horizontal "<<  m_title <<" -Tile\n";

//    SDL_Delay(1000);
    SDL_Rect newAlign = {GetPosition().x,GetPosition().y,0,0};
    SDL_Rect a = m_menusRect;
    for (int i = 0; i < GetChildSize(); i++)
    {
        newAlign = InputHandler::Instance()->UnionRect(newAlign,GetChild(i).GetContextRect());
        GetChild(i).SetPosition(vec2f(m_menusRect.x+ GetChild(i).GetContextRect().w,m_menusRect.y));
        SDL_Rect b =    GetChild(i).GetHitBox();
        SDL_UnionRect(&a,&b,&m_menusRect);

    }
    m_isVertical  = false;
    std::cout << GetComponentRect().x << " x " << GetComponentRect().y << " y " << GetComponentRect().w << " h " << GetComponentRect().w << " w \n\n\n\n\n";

}
void Gui::MenuBar::SetVertical  ()
{


    SDL_Rect newAlign = {GetPosition().x,GetPosition().y,0,0};

    SDL_Rect a = m_menusRect;

    std::cout << GetChildSize() <<" -Vertical "<<  m_title <<" -Tile\n";
    //SDL_Delay(1000);

    for (int i = 0; i < GetChildSize()-1; i++)
    {
        newAlign = InputHandler::Instance()->UnionRect(newAlign,GetChild(i).GetContextRect());
//    Child->SetPosition(vec2f(m_menusRect.w+m_padding._X,m_menusRect.y-m_padding.H));
        GetChild(i+1).SetPosition(vec2f(m_menusRect.x+ GetChild(i).GetContextRect().h,m_menusRect.y));
        SDL_Rect b =    GetChild(i).GetHitBox();
        SDL_UnionRect(&a,&b,&m_menusRect);

    }
}
void  Gui::Label::setWrappedLength(Uint32 WrapLength)
{
    text.SetWrapped(WrapLength);
}
void Gui::WindowImp::Save(std::string FilePath)
{

    //  TextureManager::Instance()->DrawText(m_title,m_hitBox.x,m_hitBox.y,Colour_floralwhite,fontManager->GetFont("OpenSans-Regular"),r);
//   TextureManager::Instance()->DrawText("leaf",m_hitBox.x+120,m_hitBox.y,Colour_floralwhite,fontManager->GetFont("OpenSans-Regular"),r);

    std::ofstream ofs;
    ofs.open (FilePath, std::ofstream::out);

    int w,h;
//    SDL_GetWindowSize(m_window,&w,&h);

    ofs << ":   " <<    GetTitle()  << " : " <<  m_children.size()<< "\n";

    for(int i = 0; i < m_children.size(); i++)
    {
        ofs << ":       " <<  GetChild(i).GetTitle() << "\n";

        for(int u = 0;  u    < GetChild(i).GetChildSize(); u++)

        {
        ofs << ":           " << GetChild(i).GetChild(u).GetTitle() << "\n";
        }
        ofs << "\n";
    }
    ofs.close();
//    std::cout << w << "/" << h << " " << FilePath << "\n";


}
void Gui::WindowImp::Remove(int n)
{
    delete m_children[n];
    m_children.erase(m_children.begin()+n);
};
//-----------------------------------------------------HandleEvent--------------------------------------------------------------------------------------\\

void Gui::Label::HandleEvent(SDL_Event &e)
{

    if(INPUTHANDLER->MousePointInRect(SDL_Point{e.motion.x,e.motion.y},m_hitBox))
        m_isMouseHover = true;
    else
        m_isMouseHover = false;
    if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
        m_isMouseClicked = true;
    if(e.button.type==SDL_MOUSEBUTTONUP|| !m_isMouseHover)
        m_isMouseClicked = false;

    m_isMouseHover = MouseOver(m_hitBox);



}
void Gui::Button::HandleEvent(SDL_Event &e)
{

    m_isMouseHover = MouseOver(GetContextRect());

    if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
        m_isMouseClicked = true;
    if(e.button.type==SDL_MOUSEBUTTONUP|| !m_isMouseHover)
        m_isMouseClicked = false;


}
void Gui::GroupBox::HandleEvent(SDL_Event &e) {};
void Gui::WindowImp::HandleEvent(SDL_Event &e)
{
//    switch(e.window.event)
//    {
//    case SDL_WINDOWEVENT_NONE :   /**< Window has gained mouse focus */
//        // std::cout <<"Window NONE \n";
//        break;
//    case SDL_WINDOWEVENT_ENTER :   /**< Window has gained mouse focus */
//        std::cout <<"Window has gained mouse focus \n";
//        m_isMouseFocus = true;
//        break;
//    case SDL_WINDOWEVENT_LEAVE : /**< Window has gained keyboard focus */
//        std::cout <<"Window has gained keyboard focus \n";
//
//        m_isMouseFocus = false;
//        break;
//    case SDL_WINDOWEVENT_FOCUS_GAINED :  /**< Window has gained keyboard focus */
//        std::cout <<"Window has gained keyboard focus\n";
//
//        m_isKeyboardFocus = true;
//        break;
//    case SDL_WINDOWEVENT_FOCUS_LOST : /**< Window has lost keyboard focus */
//        std::cout <<"Window has lost keyboard focus\n";
//        m_isKeyboardFocus = false;
//        break;
//    case SDL_WINDOWEVENT_MINIMIZED:
//        std::cout <<"Window has minimized\n";
//        m_isMinimized = true;
//        break;
//    case SDL_WINDOWEVENT_RESTORED:
//        std::cout <<"Window has Restored\n";
//        m_isMinimized = false;
//        break;
//    case SDL_WINDOWEVENT_MOVED:
//        std::cout <<"Window has Moved\n";
//
//        break;
//
//
//    };

    if(m_isVisable  && m_isFocus)
    {
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);


    }
};
void Gui::MenuBar::HandleEvent(SDL_Event &e)
{

    if(m_isVisable)
    {
//    if(inputHandler->MousePointInRect(SDL_Point{e.motion.x,e.motion.y},m_hitBox))
//        m_isMouseHover = true;
//    else
//        m_isMouseHover = false;
//    if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
//        m_isMouseClicked = true;
//    if(e.button.type==SDL_MOUSEBUTTONUP|| !m_isMouseHover)
//        m_isMouseClicked = false;
//
//    m_isMouseHover = MouseOver(m_hitBox);

        for(int i = 0; i< m_children.size(); i++)
        {
            m_children[i]->HandleEvent(e);

        }

    }



}
void Gui::Menu::HandleEvent(SDL_Event &e)
{
    if(m_isVisable)
    {

        m_isMouseHover = MouseOver(GetContextRect());

        if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
            m_isMouseClicked = true;
        if(e.button.type==SDL_MOUSEBUTTONUP|| !m_isMouseHover)
            m_isMouseClicked = false;


        for(int i = 0;  i < m_children.size(); i++)

        {
            if(MouseOver(GetContextRect()))
                m_isMouseHover = true;
            m_children[i]->HandleEvent(e);
        }

//
//    if(e.type == SDL_USEREVENT && IsMouseHover() )
//    {
//        if(e.user.code == InputHandler::Instance()->GetEventCode("GuiUser"))
//        {
//
//            if(m_callback!=NULL)
//                m_callback->call();
//            std::cout << InputHandler::Instance()->GetEventCode("GuiUser") <<  "eventCode \n";
//
//            std::cout << (std::string*)(e.user.data1) << "\n";
//            std::cout << (std::string*)(e.user.data2) << "\n";
//            delete e.user.data1;
//            delete  e.user.data2;
//            m_isMouseClicked = false;
//        }
//    }



    }
}
void Gui::SubMenu::HandleEvent(SDL_Event &e)
{


    if(m_isVisable)
    {

//    if(IsMousePressed())
//     {
//          m_isVisable = false;
//           m_isFocus = false;
//     }


        if(INPUTHANDLER->MousePointInRect(SDL_Point{e.motion.x,e.motion.y},m_hitBox))
            m_isMouseHover = true;
        else
            m_isMouseHover = false;

        if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
            m_isMouseClicked = true;
        if(e.button.type==SDL_MOUSEBUTTONUP && !m_isMouseHover)
        {
            m_isVisable = false;
            m_isFocus = false;
        }
//    if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
//        m_isMouseClicked = true;
//    if(e.button.type==SDL_MOUSEBUTTONUP|| !m_isMouseHover)
//        m_isMouseClicked = false;

    }
}
void Gui::Frame::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
}
void Gui::Panel::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i < m_children.size(); i++)
            if(isVisable())
                m_children[i]->HandleEvent(e);



}
void Gui::ToggleButton::HandleEvent(SDL_Event &e) {}
void Gui::DropDownList::HandleEvent(SDL_Event &e) {}
void Gui::Hscrollbar::HandleEvent(SDL_Event &e)
{

//bool m_isMouseOverThumb = false;
//bool m_isMousePressedThumb = false;
//bool m_isThumbUpdate = false;

    if(e.button.type==SDL_MOUSEBUTTONDOWN)
        m_isMouseClicked = true;
    if(e.button.type==SDL_MOUSEBUTTONUP)
        m_isMouseClicked = false;

    m_isMouseHover = MouseOver(m_hitBox);

    (m_isMouseHover)? m_isMouseOverThumb = true : m_isMouseOverThumb = false;


    if(m_isMousePressedThumb && m_isMouseClicked)

        m_isMousePressedThumb = false;


    if(m_isMouseClicked && MouseOver(m_ThumbRect))

        if(!m_isMousePressedThumb) m_isMousePressedThumb = true;
        else
            m_isMousePressedThumb = false;

    if(m_isMousePressedThumb)
    {
        m_ThumbPos.x = e.motion.x-m_ThumbRect.w/2;
        m_scrollX=  m_ThumbPos.x;
    }

}
void Gui::Vscrollbar::HandleEvent(SDL_Event &e)
{

//
//    if(INPUTHANDLER->MousePointInRect(SDL_Point{e.motion.x,e.motion.y},m_hitBox))
//        m_isMouseHover = true;
//    else
//        m_isMouseHover = false;
    m_isMouseHover = MouseOver(m_hitBox);
}
void Gui::textbox::HandleEvent(SDL_Event &e)
{

    m_isMouseHover = MouseOver(m_hitBox);

}
void Gui::progressbar::HandleEvent(SDL_Event &e) {}
void Gui::RatioButton::HandleEvent(SDL_Event &e) {}
void Gui::TextEdit::HandleEvent(SDL_Event &e) {}
void Gui::TabList::HandleEvent(SDL_Event &e)
{

    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
}
void Gui::Tab::HandleEvent(SDL_Event &e)
{

    if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
        m_isMouseClicked = true;
    if( e.button.type==SDL_MOUSEBUTTONUP || !m_isMouseHover)
        m_isMouseClicked = false;


    m_isMouseHover = MouseOver(m_hitBox);
}
void Gui::Entry::HandleEvent(SDL_Event &e)
{

    if(INPUTHANDLER->MousePointInRect(SDL_Point{e.motion.x,e.motion.y},m_hitBox))
        m_isMouseHover = true;
    else
        m_isMouseHover = false;
    if(e.button.type==SDL_MOUSEBUTTONDOWN && m_isMouseHover)
        m_isMouseClicked = true;
    if(e.button.type==SDL_MOUSEBUTTONDOWN && !m_isMouseHover)
        m_isMouseClicked = false;

}
//-----------------------------------------------------UPDATE--------------------------------------------------------------------------------------------
void Gui::WindowImp::Update(float DeltaTime)
{
    if(m_isVisable && m_isFocus)
    {
        if(!m_children.empty())
            for(int i = 0; i< m_children.size(); i++)
                m_children[i]->Update(DeltaTime);

    }
}
void Gui::MenuBar::Update(float DeltaTime)
{

    if(m_isVisable)
    {
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);

    }
};
void Gui::Menu::Update(float DeltaTime)
{


    if(m_isVisable)
    {
        for(int i = 0; i< m_children.size(); i++)
        {
            m_children[i]->Update(DeltaTime);

        }
        if(isVisable())
        {
            if(m_isMouseClicked)
            {
                InputHandler::Instance()->pushEvent(0,GetTitle()," Menu was Pressed");


            }
            if(IsMousePressed())
                if(m_callback!=NULL)
                {
                    m_callback->call();
                }

        }

    }

};
void Gui::SubMenu::Update(float DeltaTime)
{


    if(isVisable())
    {
        if(m_isMouseClicked)
        {
            InputHandler::Instance()->pushEvent(0,GetTitle()," SubMenu was Pressed");


        }
        if(IsMousePressed())
            if(m_callback!=NULL)
            {
                m_callback->call();
            }

    }
}

void Gui::Frame::Update(float DeltaTime)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
}
void Gui::Panel::Update(float DeltaTime)
{
    for(int i = 0; i < m_children.size(); i++)
        if(isVisable())
            m_children[i]->Update(DeltaTime);
}
void Gui::Button::Update(float DeltaTime)
{
    if(isVisable())
    {
        if(m_isMouseClicked)
        {
            //InputHandler::Instance()->pushEvent(0,GetTitle()," SubMenu was Pressed");


        }
        if(IsMousePressed())
            if(m_callback!=NULL)
            {
                m_callback->call();

            }

    }

//    bool b_buttonDelay  = false;
//    float m_buttonPressDelay = 1;
//    float m_buttonDelayInc = 0.0;
//    m_buttonPressDelay = 1;)
//
//    if(b_buttonDelay)
//    {
//        m_buttonDelayInc += DeltaTime;
//        if(m_buttonDelayInc>=m_buttonPressDelay)
//        {
//            m_buttonDelayInc = 0.0;
//            b_buttonDelay = false;
//        }
//    }

}
void Gui::GroupBox::Update(float DeltaTime) {};
void Gui::Label::Update(float DeltaTime) {};
void Gui::DropDownList::Update(float DeltaTime) {}
void Gui::ToggleButton::Update(float DeltaTime) {}
void Gui::Vscrollbar::Update(float DeltaTime)
{

}
void Gui::Hscrollbar::Update(float DeltaTime)
{

// m_scrollX += DeltaTime;
// m_ThumbStep = (float)m_hitBox.w*m_scrollX*2;
//m_ThumbPos = vec2f(m_ThumbStep+m_scrollX,0);
//m_ThumbRect = {m_ThumbPos.x,m_ThumbPos.y,16,16};
    m_ThumbStep = m_hitBox.h;
    // m_ContextArea =  GetIntersectRect(GetHitBox(),SDL_Rect{(6,0,16,32)}).w;

    // m_ThumbPos.x+=m_ThumbStep;
    if(m_ThumbPos.x<=GetHitBox().x)
    {
        m_ThumbPos.x = GetHitBox().x;
    }
    if(m_scrollX>GetHitBox().w-m_ThumbRect.w-8)
    {
        m_scrollX = GetHitBox().w-m_ThumbRect.w-8;
        m_ThumbPos = vec2f(m_scrollX,GetPosition().y);
    }
    m_ThumbRect = {m_ThumbPos.x,m_ThumbPos.y,m_ThumbStep,16};

}
void Gui::textbox::Update(float DeltaTime) {}
void Gui::progressbar::Update(float DeltaTime) {}
void Gui::RatioButton::Update(float DeltaTime) {}
void Gui::TextEdit::Update(float DeltaTime) {}
void Gui::TabList::Update(float DeltaTime)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)


            m_children[i]->Update(DeltaTime);




}
void Gui::Entry::Update(float DeltaTime)
{
//    if(!m_isTyping)
//        if(m_isMouseClicked && m_isMouseHover)
//        {
//            m_isFocus = true;
//
//            InputHandler::Instance()->StartTextInput();
//            m_isTyping = true ;
//        }
//    if(m_isFocus)
//    {
//        if(INPUTHANDLER->isTextInputActive())
//            m_TextString = InputHandler::Instance()->GetTextInput();
//    }
//    if(!m_isMouseClicked && m_isMouseHover)
//    {
//        m_isMouseClicked = false;
//        m_isFocus = false;
//        m_isTyping = false;
//        InputHandler::Instance()->StopTextInput();
//        m_isTyping=false;
//    }

}
void Gui::Tab::Update(float DeltaTime)
{
        if(m_isMouseClicked)
        {
            InputHandler::Instance()->pushEvent(0,m_title," was Pressed");

}

}
//-----------------------------------------------------RENDER------------------------------------------------------------------------------------------
void Gui::WindowImp::Render(SDL_Renderer *r)
{


    if(!m_isMinimized && m_isVisable)
    {
    //    TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_GUIBackGround,false);

        for(int i = 0; i < m_children.size(); i++)
            m_children[i]->Render(r);

    }
}
void Gui::MenuBar::Render(SDL_Renderer *r)
{
    // TextureManager::Instance()->DrawRect(m_hitBox,Colour_lightgray,r);
    if(isVisable())
    {
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_GUIBackGround,true);
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);
    }
};
void Gui::Menu::Render(SDL_Renderer *r)
{

    if(isVisable())
    {
        // TextureManager::Instance()->DrawRect(r,vec2f(GetHitBox().x,GetHitBox().y),GetHitBox().w,GetHitBox().h,Colour_white,true);
////   TextureManager::Instance()->DrawRectWithBoarder(GetHitBox(),Colour_bisque,Colour_red,1,r);
        if(m_isMouseHover)
        {
//   TextureManager::Instance()->DrawRectWithBoarder(GetHitBox(),Colour_lightblue,Colour_darkblue,1,r);
            TextureManager::Instance()->DrawRect(r,vec2f(GetHitBox().x,GetHitBox().y),GetHitBox().w,GetHitBox().h,Colour_lightblue,true);
            TextureManager::Instance()->DrawRect(r,vec2f(GetHitBox().x,GetHitBox().y),GetHitBox().w,GetHitBox().h,Colour_darkblue,false);
////
        }

        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);
        ChangeText(r,m_title);
        text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);


    }
}
void Gui::SubMenu::Render(SDL_Renderer *r)
{
    if(isVisable())
    {
        if(m_isMouseHover &&!m_isMouseClicked)
        {
            TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_darkgreen,true);
            text.SetTextColour(Colour_blue);
        }
        if(!m_isMouseHover &&!m_isMouseClicked)
        {
            TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_darkred,true);
            text.SetTextColour(Colour_white);
        }
        if(m_isMouseHover &&m_isMouseClicked)
        {
            TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_red,true);
            text.SetTextColour(Colour_green);
        }
        if(!m_isMouseHover &&m_isMouseClicked)
        {
            TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_lightgreen,true);
            text.SetTextColour(Colour_red);
        }
        ChangeText(r,m_title);
        text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);
    }

};
void Gui::Panel::Render(SDL_Renderer *r)
{
    if(m_isVisable)
    {
        SDL_Rect   src = {0,0,48,48};
        if(InputHandler::Instance()->MouseinRect(GetHitBox()))
              src = {0,48,48,48};
if(m_isFilled)
        TextureManager::Instance()->DrawRect(r,GetHitBox(),Colour_GUIBackGround,true);

        TextureManager::Instance()->DrawTileBox(r,"GUI_TileSheet",16,src,GetHitBox());

        for(int i = 0; i < m_children.size(); i++)
        {

            m_children[i]->Render(r);
        }


    }
}
void Gui::Frame::Render(SDL_Renderer *r)
{

    if(m_isVisable)
    {
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_GUIBackGround,true);

        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);




    }
}
void Gui::Button::Render(SDL_Renderer *r)
{
    if(isVisable())
    {
//        SDL_Rect TextRect = fontManager->QueryText(GetTitle(),"OpenSans-Regular");
//m_hitBox.w = TextRect.w;
//m_hitBox.h = TextRect.h;



        ChangeText(r,m_title);
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_GUIForeGround,true);

//        TextureManager::Instance()->DrawRectFilled(m_hitBox,Colour_GUIForeGround,r);
//SDL_Rect l_button_Idie_= {96,160,191,175}

        SDL_Rect l_button_Idie_= {96,160,16,16};
        SDL_Rect l_buttonLastAction = {112,160,16,16};
        SDL_Rect l_buttonISAction = {128,160,16,16};
        SDL_Rect l_buttonToggled_On = {144,160,16,16};
//        TextureManager::Instance()->Draw(r,"GUI_TileSheet",l_button_Idie_,  {MOUSEPOSITION.x,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//        TextureManager::Instance()->Draw(r,"GUI_TileSheet",l_buttonLastAction,  {MOUSEPOSITION.x+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//        TextureManager::Instance()->Draw(r,"GUI_TileSheet",l_buttonISAction,  {MOUSEPOSITION.x+16+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//        TextureManager::Instance()->Draw(r,"GUI_TileSheet",l_buttonToggled_On,  {MOUSEPOSITION.x+16+16+16,MOUSEPOSITION.y,16,16},0,NULL,SDL_FLIP_NONE);
//SDL_Rect l_buttonToggled_On = {96,160,16,16}
        SDL_Rect l_sRect = {144,0,32,32};
        text.SetTextColour(Colour_black);
        if(IsMouseHover())
        {
            text.SetTextColour(Colour_red);
        }
        if(IsFocus())
        {
            text.SetTextColour(Colour_white);
//
        }
        if(IsMousePressed())
        {
        }
        if(b_buttonDelay)
        {

            text.SetTextColour(Colour_pink);

        }
        TextureManager::Instance()->DrawTileBoxAroundRect(r,"GUI_TileSheet",(float)32/3,m_hitBox,l_sRect);
        text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);
//  TextureManager::Instance()->DrawRect(m_hitBox,Colour_red,r);



    }
}
void Gui::TabList::Render(SDL_Renderer *r)
{

    if(m_isVisable)
    {
        SDL_FRect l_sRect = {120,0,8,24};
        TextureManager::Instance()->DrawTileHorizontal(r,"GUI_TileSheet",8,m_hitBox.w,GetHitBox().x,GetHitBox().y,&l_sRect,0,NULL,SDL_FLIP_NONE);
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);
    }
}
void Gui::Label::Render(SDL_Renderer *r)
{
    //  ChangeText(m_title,r);
    if(isVisable())
    {
        if(IsMouseHover())
            TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_white,true);
        else
            TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_black,true);
//TextureManager::Instance()->DrawRectWithBoarder(SDL_Rect({m_hitBox.x,m_hitBox.y,text.GetBounds().w+text.GetBounds().h,text.GetBounds().h}),Colour_honeydew,Colour_rosybrown,2,r);
//  TextureManager::Instance()->DrawRectWithBoarder(SDL_Rect({m_hitBox.x,m_hitBox.y,text.GetBounds().w+text.GetBounds().h,text.GetBounds().h}),Colour_lightgreen,Colour_black,2,r);

        text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);

    }
}
void Gui::GroupBox::Render(SDL_Renderer *r) {}
void Gui::Tab::Render(SDL_Renderer *r)
{

    if(isVisable())
    {

        SDL_Rect ContextRect= GetContextRect();
        SDL_FRect   dsrcf ;
        SDL_Rect leftRect, RightRect ;
//TextureManager::Instance()->DrawTileHorizontal(r,"GUI_TileSheet",16,text.GetBounds().w,m_hitBox.x,m_hitBox.y,&dsrcf,0,NULL,SDL_FLIP_NONE);
        if(IsMouseHover() && !IsFocus())
        {
            text.SetTextColour(Colour_red);
            dsrcf =      {104,24,8,24};
            RightRect = {   112,24,8,24};
            leftRect = {96,24,8,24};
//
        }
        else if(IsFocus())
        {
            text.SetTextColour(Colour_white);
            dsrcf =      {104,0,8,24};
            RightRect = {112,0,8,24};
            leftRect = {96,0,8,24};
//
        }
        else if(IsMousePressed())
        {
            text.SetTextColour(Colour_white);
            dsrcf =      {104,0,8,24};
            RightRect = {  112,0,8,24};
            leftRect = {96,0,8,24};
//
        }
        else
        {
            text.SetTextColour(Colour_black);

            dsrcf =     {104,24,8,24};
            RightRect =   {112,24,8,24};
            leftRect = {96,24,8,24};
//
        }
//    TextureManager::Instance()->DrawRect(r,ContextRect,Colour_blue,false);
        TextureManager::Instance()->DrawTileHorizontal(r,"GUI_TileSheet",8,m_hitBox.w,GetHitBox().x,GetHitBox().y,&dsrcf,0,NULL,SDL_FLIP_NONE);
        TextureManager::Instance()->Draw(r,"GUI_TileSheet",RightRect, {text.GetBounds().w+GetHitBox().x,GetHitBox().y,8,24});
        TextureManager::Instance()->Draw(r,"GUI_TileSheet",leftRect, {GetHitBox().x-8,GetHitBox().y,8,24});

        ChangeText(r,m_title);
        text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);

    }
}
void Gui::ToggleButton::Render(SDL_Renderer *r) {}
void Gui::DropDownList::Render(SDL_Renderer *r) {}
void Gui::Hscrollbar::Render(SDL_Renderer *r)
{
    if(isVisable())
    {
//        TextureManager::Instance()->DrawRectWithBoarder(GetHitBox(),Colour_lightblue,Colour_navy,1,r);
//        TextureManager::Instance()->DrawRect(r,m_ThumbPos,16,16,Colour_verydarkgray,true);

//        if(IsMouseHover())
//            TextureManager::Instance()->DrawRect(r,m_ThumbPos,16,16,Colour_saddlebrown,true);
//        if(m_isMouseOverThumb)
//            TextureManager::Instance()->DrawRect(r,m_ThumbPos,16,16,Colour_wheat,true);
//        if( m_isMousePressedThumb)
//            TextureManager::Instance()->DrawRect(r,m_ThumbPos,16,16,Colour_azure,true);


        SDL_FRect    dsrcf2 =    {64,224,16,16};
//------------------------------------Track
        TextureManager::Instance()->Draw(r,"GUI_TileSheet", {64-16,224,16,16}, {GetHitBox().x,GetHitBox().y,16,16});
        TextureManager::Instance()->Draw(r,"GUI_TileSheet", {64+16,224,16,16}, {GetHitBox().x+GetHitBox().w-m_ThumbRect.w,GetHitBox().y,16,16});
        TextureManager::Instance()->DrawTileHorizontal(r,"GUI_TileSheet",16,m_hitBox.w-m_ThumbRect.w*2,GetHitBox().x+16,GetHitBox().y,&dsrcf2,0,NULL,SDL_FLIP_NONE);


//-----------------------------------ThumbSlider
        //
        TextureManager::Instance()->Draw(r,"GUI_TileSheet", {48+16+16,208,16,16},  {m_ThumbPos.x+32,m_ThumbPos.y,16,16},0,NULL,SDL_FLIP_NONE);
        // TextureManager::Instance()->Draw(r,"GUI_TileSheet", {48+16,208,16,16},  {m_ThumbPos.x,m_ThumbPos.y,16,16},0,NULL,SDL_FLIP_NONE);
        TextureManager::Instance()->Draw(r,"GUI_TileSheet", {48+16,208,16,16},  {m_ThumbPos.x+16,m_ThumbPos.y,16,16},0,NULL,SDL_FLIP_NONE);
        TextureManager::Instance()->Draw(r,"GUI_TileSheet", {48,208,16,16}, {m_ThumbPos.x,m_ThumbPos.y,16,16});

        TextureManager::Instance()->DrawRect(r,SDL_Rect({m_ThumbPos.x,m_ThumbPos.y,48,16}),Colour_purple,false);

    }
}
void Gui::progressbar::Render(SDL_Renderer *r) {}
void Gui::textbox::Render(SDL_Renderer *r) {}
void Gui::Vscrollbar::Render(SDL_Renderer *r)
{
    if(isVisable())
    {
        if(IsMouseHover())
        {
            TextureManager::Instance()->DrawRectWithBoarder(GetHitBox(),Colour_lightblue,Colour_navy,1,r);
            TextureManager::Instance()->DrawRect(r,GetPosition(),16,16,Colour_green,true);
        }
        else
        {
            TextureManager::Instance()->DrawRectWithBoarder(GetHitBox(),Colour_lightblue,Colour_yellowgreen,1,r);
            TextureManager::Instance()->DrawRect(r,GetPosition(),16,16,Colour_beige,true);
        }
    }
}
void Gui::RatioButton::Render(SDL_Renderer *r) {}
void Gui::Entry::Render(SDL_Renderer *r)
{
//    SDL_Rect temprect = m_hitBox;
//    temprect.w = text.GetBounds().w;
//    temprect.h = text.GetBounds().h;
//
    if(m_isMouseHover &&!m_isMouseClicked)
    {
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_darkgreen,true);
    }
    if(!m_isMouseHover &&!m_isMouseClicked)
    {
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_darkred,true);
    }
    if(m_isMouseHover &&m_isMouseClicked)
    {
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_red,true);
    }
    if(!m_isMouseHover &&m_isMouseClicked)
    {
        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_lightgreen,true);
    }
//
////  if(m_isFocus)
////  {
////
////  TextureManager::Instance()->DrawRectWithBoarder(m_hitBox,Colour_brown,Colour_black,2,r);
////
//// }
//
//    //TextureManager::Instance()->DrawText(m_title,m_hitBox.x-FontManager::Instance()->QueryText(m_title,"OpenSans-Regular").w*1.5,m_hitBox.y,Colour_black,fontManager->GetFont("Sans"),r);
////    ChangeText(m_TextString,r);
//    text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);



}
void Gui::TextEdit::Render(SDL_Renderer *r) {};
void  Gui::TabList::setFoucsTab(std::string str)
{
    for(int i = 0 ; i < GetChildSize(); i++)
        m_children[i]->SetFocus(false);
    if(Find(str)!=NULL)
    {
        Find(str)->SetFocus(true);
        Find(str)->SetVisable(true);
    }
}
//    if(!IsFocus())
//    {
//        TextureManager::Instance()->DrawRect(r,GetPosition(),GetHitBox().w,GetHitBox().h,Colour_black,false);
//        ChangeText(m_title,r);
//        text.LoadFromRenderedText(r,m_hitBox.x,m_hitBox.y);
//        }
//old buttonCode
/**<

{
    if(m_isVisable)
    {


        if(!m_isMouseHover && !m_isMouseClicked)
        {



            if(m_boarder.m_thickness!=0)
                if(m_boarder.Style==boarderStyle::NOFILLED)
                {
                    TextureManager::Instance()->DrawRect(m_hitBox,m_colourdata.Boarder,m_boarder.m_thickness,r);
                }
                else if(m_boarder.Style==boarderStyle::FILLED)
                    TextureManager::Instance()->DrawRectFilled(m_hitBox,m_colourdata.Boarder,r);


    SDL_FRect l_dRect = {144,0,64,32};
    SDL_Rect l_sRect = {m_hitBox.x,m_hitBox.y,64,32};

     TextureManager::Instance()->SDLDraw(r,"GUI_TileSheet",&l_sRect,&l_dRect,0,NULL,SDL_FLIP_NONE);


            SDL_FRect l_TextBackGround = TextureManager::Instance()->QueryText(m_title,FontManager::Instance()->GetFont("Sans"),r);
//std::cout << l_TextBackGround.w << " " << l_TextBackGround.h << "\n";

            l_TextBackGround.x+=m_hitBox.x+m_hitBox.w/2-l_TextBackGround.w/2;
            l_TextBackGround.y+=m_hitBox.y+m_hitBox.h/2-l_TextBackGround.h/2;

            //TextureManager::Instance()->DrawText(m_title,l_TextBackGround.x,l_TextBackGround.y,Colour_white,fontManager->GetFont("Sans"),r);

            ChangeText(m_title,r);
            text.LoadFromRenderedText(r,l_TextBackGround.x,l_TextBackGround.y);

//    TextureManager::Instance()->SDLDraw(r,"GUI_TileSheet",&l_sRect,&l_dRect,0,NULL,SDL_FLIP_NONE);
        }
        if(m_isMouseHover)
        {


            if(m_boarder.m_thickness!=0)
                if(m_boarder.Style==boarderStyle::NOFILLED)
                {
                    TextureManager::Instance()->DrawRect(m_hitBox,m_colourdata.Boarder,m_boarder.m_thickness,r);
                }
                else if(m_boarder.Style==boarderStyle::FILLED)
                    TextureManager::Instance()->DrawRectFilled(m_hitBox,m_colourdata.Boarder,r);


            SDL_FRect l_TextBackGround = TextureManager::Instance()->QueryText(m_title,FontManager::Instance()->GetFont("Sans"),r);
//std::cout << l_TextBackGround.w << " " << l_TextBackGround.h << "\n";

            l_TextBackGround.x+=m_hitBox.x+m_hitBox.w/2-l_TextBackGround.w/2;
            l_TextBackGround.y+=m_hitBox.y+m_hitBox.h/2-l_TextBackGround.h/2;

            text.LoadFromRenderedText(r,l_TextBackGround.x,l_TextBackGround.y);
// TextureManager::Instance()->DrawText(m_title,l_TextBackGround.x,l_TextBackGround.y,Colour_white,fontManager->GetFont("Sans"),r);

        }
        if(m_isMouseClicked)
        {


            //    TextureManager::Instance()->DrawRectWithBoarder(m_hitBox,Colour_forestgreen,Colour_red,16,r);
            SDL_FRect l_TextBackGround = TextureManager::Instance()->QueryText(m_title,FontManager::Instance()->GetFont("Sans"),r);
//std::cout << l_TextBackGround.w << " " << l_TextBackGround.h << "\n";

            l_TextBackGround.x+=m_hitBox.x+m_hitBox.w/2-l_TextBackGround.w/2;
            l_TextBackGround.y+=m_hitBox.y+m_hitBox.h/2-l_TextBackGround.h/2;

            //TextureManager::Instance()->DrawText(m_title,l_TextBackGround.x,l_TextBackGround.y,Colour_white,fontManager->GetFont("Sans"),r);


            if(m_boarder.m_thickness!=0)
                if(m_boarder.Style==boarderStyle::NOFILLED)
                {
                    TextureManager::Instance()->DrawRect(m_hitBox,m_colourdata.Boarder,m_boarder.m_thickness,r);
                }
                else if(m_boarder.Style==boarderStyle::FILLED)
                    TextureManager::Instance()->DrawRectFilled(m_hitBox,m_colourdata.Boarder,r);

            text.LoadFromRenderedText(r,l_TextBackGround.x,l_TextBackGround.y);
            m_isMouseClicked = false;
        }

    }
}
 */
