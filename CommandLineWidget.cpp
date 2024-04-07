#include "CommandLineWidget.h"

CommandLineWidget::CommandLineWidget()
{
    //ctor
}

CommandLineWidget::~CommandLineWidget()
{
    //dtor
}
void CommandLineWidget::Load(std::string FileLocation)
{
//    Panel *m_Panel = new Panel();
//    m_Panel->Init("CommandLinePanel",GetHitBox());
//
//    m_MenuBar->SetPadding(0,0,0,0);
//Add(    m_Panel);
//Add(    WIDGETFACTORY->Create("Panel","DirectoryManagerPanel",GetHitBox()));
//    m_Panel.Init("OutputLogPanel",GetHitBox());
};
void CommandLineWidget::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
};
void  CommandLineWidget::Update(float DeltaTime)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
};
void CommandLineWidget::Render(SDL_Renderer *r)
{

    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);

            TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),Type(),GetHitBox().x+GetHitBox().w/2,GetHitBox().y+4,Colour_black,Align_Center);

};
void CommandLineWidget::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
void  CommandLineWidget::Add(IWidget* Child)
{
    m_children.push_back(Child);
}

