#include "MarioEditorLayer.h"

MarioEditorLayer::MarioEditorLayer()
{
    //ctor
    int w,h;
    TextureManager::Instance()->QueryTexture("MarioTileSet",w,h);

    Widget_Box_Selection = GameObjectFactory::Instance()->Create("GUI_RECT");
    Widget_Box_Selection->Load("asset/GUI_/GUI_RECT.txt");

    dynamic_cast<GUI_Object*>(Widget_Box_Selection)->SetSize({0,272,912,480});
    dynamic_cast<GUI_Object*>(Widget_Box_Selection)->changePos({0,272,912,480});

    m_Widget_ScrollBar = GameObjectFactory::Instance()->Create("GUI_ScrollBar");
    m_Widget_ScrollBar->Load("GUI_ScrollBar");



//    dynamic_cast<GUI_ScrollBar*>(m_Widget_ScrollBar)->SetSize3072);
    SDL_Rect r = {0,224,256,16};
    dynamic_cast<GUI_ScrollBar*>(m_Widget_ScrollBar)->init(r,3072);



}

MarioEditorLayer::~MarioEditorLayer()
{
    //dtor
}

void MarioEditorLayer::Render()
{

Application::Instance()->GetCamera()->Setpos(dynamic_cast<GUI_ScrollBar*>(m_Widget_ScrollBar)->GetCurrentBarPos()*3328,0);

//    int w,h;
//    TextureManager::Instance()->QueryTexture("MarioTileSet",w,h);
//    std::stringstream s;
//    s << "w/h: " <<  dynamic_cast<GUI_ScrollBar*>(m_Widget_ScrollBar)->GetCurrentBarPos()  << "/  "   << Game::Instance()->GetCamera()->getpos().x;
//    TextureManager::Instance()->DrawText(s.str(),0,0,FontManager::Instance()->GetFont("OpenSans-Bold"),Game::Instance()->GetRenderer());


    TextureManager::Instance()->SetColour(255,255,255,0,Application::Instance()->GetRenderer());

    SDL_Rect cam = Application::Instance()->GetCamera()->GetSDLRect();
    m_Widget_ScrollBar->Render();
    Widget_Box_Selection->Render();
TextureManager::Instance()->Draw("MarioTileSet",200,356,256,128,Application::Instance()->GetRenderer(),SDL_FLIP_NONE);
//TextureManager::Instance()->Draw("Level_1-1",-Game::Instance()->GetCamera()->getpos().x,0,3328,224,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);

    TextureManager::Instance()->DrawRect(cam,Application::Instance()->GetRenderer());




}
void MarioEditorLayer::Update(Level* pLevel)
{

}
void  MarioEditorLayer::Update(GameState* pLevel)
{

    m_Widget_ScrollBar->Update();
}

void  MarioEditorLayer::HandleEvent(SDL_Event &e )
{

    m_Widget_ScrollBar->HandleEvent(e);
}
