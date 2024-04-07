#include "ObjectInspectorWidget.h"

ObjectInspectorWidget::ObjectInspectorWidget()
{
    //ctor
}

ObjectInspectorWidget::~ObjectInspectorWidget()
{
    //dtor
}

void ObjectInspectorWidget::Load(std::string FileLocation)
{

Add(WidgetFactory::Create("Panel","GameManagerPanel",GetHitBox()));

};
void ObjectInspectorWidget::HandleEvent(SDL_Event &e)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
};
void  ObjectInspectorWidget::Update(float DeltaTime)
{
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
};
void ObjectInspectorWidget::Render(SDL_Renderer *r)
{
// TextureManager::Instance()->DrawRect(APP->GetRenderer(),APP->GetCamera().GetRect(),Colour_white,true);
    TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),Type(),GetHitBox().x+GetHitBox().w/2,GetHitBox().y+4,Colour_black,Align_Center);

 //TextureManager::Instance()->DrawLine(r,GetHitBox().x,GetHitBox().y,GetHitBox().w+GetHitBox().x,GetHitBox().h+GetHitBox().y,Colour_black);
 //TextureManager::Instance()->DrawLine(r,GetHitBox().x+GetHitBox().w,GetHitBox().y,GetHitBox().x,GetHitBox().h+GetHitBox().y,Colour_black);

  if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);


};

void ObjectInspectorWidget::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
void  ObjectInspectorWidget::Add(IWidget* Child)
{
    m_children.push_back(Child);
}
