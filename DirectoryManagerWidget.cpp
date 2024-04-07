#include "DirectoryManagerWidget.h"

DirectoryManagerWidget::DirectoryManagerWidget()
{
//    m_Label.Init("DirectoryManager\n");
    //ctor
}

DirectoryManagerWidget::~DirectoryManagerWidget()
{
    //dtor
}

void DirectoryManagerWidget::Load(std::string FileLocation)
{
//    Panel* m_Panel = new Panel();
//    m_Panel->Init("DirectoryManagerPannel",GetHitBox());
//    Add(m_Panel);
//
Add(    WIDGETFACTORY->Create("Panel","DirectoryManagerPanel",GetHitBox()));
//    printf(FileLocation.c_str());
//    printf("\n");
//
//    {
//
//        std::map<std::string,int>  configInfo;
//        std::cout << "_____________Config_____________________\n\n";
//        std::string m_fileconfig = "asset/Config.txt";
//        int i = 0;
//        std::ifstream ifs;
//        ifs.open (FileLocation, std::ifstream::in);
//        if(ifs.good())
//            std::cout << "ifstream loaded "<< m_fileconfig<< ": good\n";
//        if(ifs.fail())
//        {
//            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"FILE NOT FOUND");
//
//            return ;
//        }
//        if(ifs.bad())
//            std::cout << "bad\n";
//        while(!ifs.eof())
//        {
//            std::string l_readString;
//            int l_readInt;
//            ifs >> l_readString;
//            ifs >> l_readInt;
//
//            configInfo[l_readString] = l_readInt;
//
//            std::cout <<  l_readString<< " / ";
//            std::cout << l_readInt<< " \n";
//            i++;
//        }
//
//
//    }
//



}


void DirectoryManagerWidget::HandleEvent(SDL_Event &e)

{
    if(MouseOver(GetHitBox()) && !InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {

            std::string ssx2 = InputHandler::Instance()->GetTextDropFile();

   if (ssx2.find("txt") != std::string::npos)
        {
            std::cout  <<ssx2;
            InputHandler::Instance()->ClearDragFile();
        }

    }

    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);
}
   void DirectoryManagerWidget::Update(float DeltaTime) {

 if(!m_children.empty())
for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);
    }
void DirectoryManagerWidget::Render(SDL_Renderer *r)
{
// TextureManager::Instance()->DrawRect(APP->GetRenderer(),APP->GetCamera().GetRect(),Colour_white,true);
    //   printf(m_Label.GetTitle().c_str());
    TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),Type(),GetHitBoxCentre().x,GetHitBox().y+4,Colour_black,Align_Center);

 //TextureManager::Instance()->DrawLine(r,GetHitBox().x,GetHitBox().y,GetHitBox().w+GetHitBox().x,GetHitBox().h+GetHitBox().y,Colour_black);
// TextureManager::Instance()->DrawLine(r,GetHitBox().x+GetHitBox().w,GetHitBox().y,GetHitBox().x,GetHitBox().h+GetHitBox().y,Colour_black);
 if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);

//     LText m_titleText;
//    m_titleText.SetTextColour(Colour_black);
//    m_titleText.ChangeText(Type(),fontManager->GetFont("OpenSans-Regular12"),APP->GetRenderer());
//    m_titleText.LoadFromRenderedText(r,GetContextCentre().x/2,GetHitBox().y);


}

void DirectoryManagerWidget::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
void  DirectoryManagerWidget::Add(IWidget* Child)
{
    m_children.push_back(Child);
}
