#include "OutputLogWidget.h"

OutputLogWidget::OutputLogWidget()
{
    //ctor
}

OutputLogWidget::~OutputLogWidget()
{
    //dtor
}

void OutputLogWidget::Load(std::string FileLocation)
{

        Gui::Panel* m_Panel = new Panel();
    m_Panel->Init("OutputLogPanel",GetHitBox());
    Add(m_Panel);
//    m_Panel.Init("OutputLogPanel",GetHitBox());
};
void OutputLogWidget::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
};
void  OutputLogWidget::Update(float DeltaTime)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
};
void OutputLogWidget::Render(SDL_Renderer *r)
{

    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);


    TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),Type(),GetHitBox().x+GetHitBox().w/2,GetHitBox().y+4,Colour_black,Align_Center);

};
void OutputLogWidget::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
