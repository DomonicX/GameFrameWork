#include "FileMenuManager.h"

FileMenuManager::FileMenuManager()
{
    //ctor
}

FileMenuManager::~FileMenuManager()
{
    //dtor
}
void FileMenuManager::Load(std::string FileLocation)
{

    int MenubarSize = FontManager::Instance()->GetFontSize("OpenSans-Regular");
    SDL_Rect Rect_MenuBar = {0,0,GetHitBox().w, MenubarSize};

    Add(WIDGETFACTORY->Create("MenuBar","FileMenuBar",Rect_MenuBar));

    Find("FileMenuBar")->Add(WIDGETFACTORY->Create("Menu","File", {0,0,0,0}));
    Find("FileMenuBar")->Add(WIDGETFACTORY->Create("Menu","Edit", {0,0,0,0}));
    Find("FileMenuBar")->Add(WIDGETFACTORY->Create("Menu","View", {0,0,0,0}));
    Find("FileMenuBar")->Add(WIDGETFACTORY->Create("Menu","Search", {0,0,0,0}));

    Find("File")->Add(WIDGETFACTORY->Create("SubMenu","Open", {0,4,0,2}));
    Find("File")->Add(WIDGETFACTORY->Create("SubMenu","New", {0,64,0,2}));
    Find("File")->Add(WIDGETFACTORY->Create("SubMenu","Save...As", {0,4,0,2}));
    Find("File")->Add(WIDGETFACTORY->Create("SubMenu","Save", {0,4,0,4}));
    Find("File")->Add(WIDGETFACTORY->Create("SubMenu","Quit", {0,4,0,4}));

    Find("New")->SetPosition(vec2f(Find("File")->GetHitBox().x + Find("File")->GetHitBox().w/2,Find("File")->GetHitBox().y + Find("File")->GetHitBox().h ));
    Find("Open")->SetPosition(vec2f(Find("File")->GetHitBox().x + Find("File")->GetHitBox().w/2,Find("File")->GetHitBox().y + Find("File")->GetHitBox().h+24 ));
    Find("Save")->SetPosition(vec2f(Find("File")->GetHitBox().x + Find("File")->GetHitBox().w/2,Find("File")->GetHitBox().y + Find("File")->GetHitBox().h+72 ));
    Find("Save...As")->SetPosition(vec2f(Find("File")->GetHitBox().x + Find("File")->GetHitBox().w/2,Find("File")->GetHitBox().y + Find("File")->GetHitBox().h+48 ));
    Find("Quit")->SetPosition(vec2f(Find("File")->GetHitBox().x + Find("File")->GetHitBox().w/2,Find("File")->GetHitBox().y + Find("File")->GetHitBox().h+64 ));
//Open
// Find("File")->SetTextSize(12);
// Find("Edit")->SetTextSize(12);
// Find("View")->SetTextSize(12);
// Find("Search")->SetTextSize(12);
// Find("Open")->SetTextSize();
    {
        auto s = Find("Edit");
        if(s!=NULL)
            dynamic_cast<Gui::Menu*>(s)->OnAction(new FileMenuCallBack("Edit"));

    }
    {
        auto s = Find("File");
        if(s!=NULL)
            dynamic_cast<Gui::Menu*>(s)->OnAction(new FileMenuCallBack("File"));

    }
    {
        auto s = Find("New");
        if(s!=NULL)
            dynamic_cast<Gui::SubMenu*>(s)->OnAction(new FileMenuCallBack("New"));

    }
    {
        auto s = Find("Quit");
        if(s!=NULL)
            dynamic_cast<Gui::SubMenu*>(s)->OnAction(new FileMenuCallBack("Quit"));

    }

//    dynamic_cast<Gui::MenuBar*>(m_MenuBarFile)->SetVertical();
    //dynamic_cast<Gui::MenuBar*>(m_MenuBar)->SetHorizontal();

//
//auto s = m_MenuBar->Find("View");
//if(s!=NULL)
//s->SetVisable(false);

//


};
void FileMenuManager::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
};
void  FileMenuManager::Update(float DeltaTime)
{

    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
};
void FileMenuManager::Render(SDL_Renderer *r)
{

//TextureManager::Instance()->DrawRect(APP->GetRenderer(),APP->GetCamera().GetRect(),Colour_GUIBackGround,true);

    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);
    TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("CONSOLAB"),Type(),GetHitBox().x+GetHitBox().w/2,GetHitBox().y+2,Colour_black,Align_Center,14);
// TextureManager::Instance()->DrawLine(r,GetHitBox().x,GetHitBox().y,GetHitBox().w,GetHitBox().h,Colour_red);

};
void FileMenuManager::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
void  FileMenuManager::Add(IWidget* Child)
{
    m_children.push_back(Child);
}

/**< Panel m_Panel;
m_Panel.Init("TileMapPanel",GetHitBox());
m_Panel.HandleEvent(e);
    m_Panel.Update(DeltaTime);
m_Panel.Render(r); */
