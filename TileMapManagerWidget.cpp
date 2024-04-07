#include "TileMapManagerWidget.h"

TileMapManagerWidget::TileMapManagerWidget()
{
    //    m_Label.Init("DirectoryManager\n");//   printf(m_Label.GetTitle().c_str());

    //ctor
}

TileMapManagerWidget::~TileMapManagerWidget()
{
    //dtor
}
void TileMapManagerWidget::Load(std::string FileLocation)
{
//    m_Panel = new Panel();
//    m_Panel->Init("TileMapPanel",GetHitBox());
//
    m_Panel = new Panel();
    m_Panel->Init("TileMapPanel",GetHitBox());

Add(    m_Panel);
//Add(    WIDGETFACTORY->Create("Panel","TileMapManager",GetHitBox()));

    printf(FileLocation.c_str());
    printf("\n");
    {

        std::map<std::string,int>  configInfo;
        std::cout << "_____________Config_____________________\n\n";
        std::string m_fileconfig = "asset/Config.txt";
        int i = 0;
        std::ifstream ifs;
        ifs.open (FileLocation, std::ifstream::in);
        if(ifs.good())
            std::cout << "ifstream loaded "<< m_fileconfig<< ": good\n";
        if(ifs.fail())
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"FILE NOT FOUND");

            return ;
        }
        if(ifs.bad())
            std::cout << "bad\n";
        while(!ifs.eof())
        {
            std::string l_readString;
            int l_readInt;
            ifs >> l_readString;
            ifs >> l_readInt;

            configInfo[l_readString] = l_readInt;

            std::cout <<  l_readString<< " / ";
            std::cout << l_readInt<< " \n";
            i++;
        }


    }



    m_titleText.SetTextColour(Colour_black);
}
std::string TileMapManagerWidget::Type()
{
    return "TileMapManager";
}

void TileMapManagerWidget::HandleEvent(SDL_Event &e)
{
    if(MouseOver(GetHitBox()) && !InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        std::string ssx2 = InputHandler::Instance()->GetTextDropFile();

        if ( ssx2.find("png") != std::string::npos)
        {

            for(int i = 0; i < InputHandler::Instance()->GetTextDropFile().size(); i++)
                if(ssx2[i]=='\\')
                    ssx2.erase(0,i+1);
            ssx2.resize(ssx2.size()-4);
      Label *tempLabel = new Label();
      tempLabel->Init(ssx2);
      tempLabel->SetTextColour(Colour_black);
    tempLabel->ChangeText(APP->GetRenderer(),ssx2);
    tempLabel->SetPosition(vec2f(GetHitBox().x+16,16+GetHitBox().y+(22*m_textures.size())));
            m_Panel->Add(tempLabel);

            m_textures.push_back(ssx2);
            std::stringstream ss;
            ss << DirectoryHandler::Instance()->GetFileImg() << ssx2 << ".png";
            if(!TextureManager::Instance()->Load(APP->GetRenderer(),
                                                 ssx2,InputHandler::Instance()->GetTextDropFile(),ss.str().c_str(),Colour_magenta))
            {
                 m_Panel->Remove(m_Panel->GetChildSize()-1);
                m_textures.pop_back();
            }
//            SDL_ShowSimpleMessageBox(0,"sds","sds",App->GetWindow()->GetWindow());

        //    std::cout <<TextureManager::Instance()->getTextureMap().size() << " File size \n ";

  InputHandler::Instance()->ClearDragFile();

        }

        if ( ssx2.find("jpg") != std::string::npos)
        {

            for(int i = 0; i < InputHandler::Instance()->GetTextDropFile().size(); i++)
                if(ssx2[i]=='\\')
                    ssx2.erase(0,i+1);
            ssx2.resize(ssx2.size()-4);
            m_textures.push_back(ssx2);
            std::stringstream ss;
            ss <<  DirectoryHandler::Instance()->GetFileImg() << ssx2 << ".jpg";
            if(!TextureManager::Instance()->Load(APP->GetRenderer(),
                                                 ssx2,InputHandler::Instance()->GetTextDropFile(),ss.str().c_str(),Colour_magenta))
            {
                 m_Panel->Remove(m_Panel->GetChildSize()-1);
                m_textures.pop_back();
            }
//            SDL_ShowSimpleMessageBox(0,"sds","sds",App->GetWindow()->GetWindow());

        //    std::cout <<TextureManager::Instance()->getTextureMap().size() << " File size \n ";
//
  InputHandler::Instance()->ClearDragFile();

        }

    }
m_Panel->HandleEvent(e);
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->HandleEvent(e);

}
void TileMapManagerWidget::Update(float DeltaTime) {
m_Panel->Update(DeltaTime);
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Update(DeltaTime);

}
void TileMapManagerWidget::Render(SDL_Renderer *r)
{
   // std::cout << GetPosition();

// TextureManager::Instance()->DrawRect(APP->GetRenderer(),APP->GetCamera().GetRect(),Colour_white,true);
    vec2f textpos = GetPosition();

    // TextureManager::Instance()->DrawRect(APP->GetRenderer(),GetHitBox(),Colour_lightgray,false);

    for(int i = 0 ; i <    m_textures.size() ; i ++)
    {

//
// if(i%2==0)   TextureManager::Instance()->DrawRect(App->GetRenderer(),  vec2f(GetHitBox().x+16,m_titleText.GetBounds().h+textpos.y+i*16),m_titleText.GetBounds().w,m_titleText.GetBounds().h,Colour_lightgray,true);

//
//        SDL_Point point= vecToSDL_Point(vec2f( TextureManager::Instance()->getTextureMap()[m_textures[i]]->GetWidth()/2,TextureManager::Instance()->getTextureMap()[m_textures[i]]->GetHeight()/2));
//        std::string stri =  m_textures[i];
//        SDL_Rect poss = {GetHitBox().x,m_titleText.GetBounds().h+GetHitBox().y+i*14,TextureManager::Instance()->getTextureMap()[stri]->GetWidth(),TextureManager::Instance()->getTextureMap()[stri]->GetHeight()};
//     SDL_RenderCopyEx(App->GetRenderer(), TextureManager::Instance()->getTextureMap()[stri]->GetSDLTexture(),NULL,&poss,//angle0,&point,SDL_FLIP_NONE);
//
//        TextureManager::Instance()->DrawText( m_textures[i],
//                                              GetHitBox().x+16,m_titleText.GetBounds().h+GetHitBox().y+i*16,
//                                              Colour_black,
//                                              fontManager->GetFont("OpenSans-Regular12"),
//                                              App->GetRenderer());
//
//
        SDL_Rect srsc = {GetContextCentre().x+m_titleText.GetBounds().w,m_titleText.GetBounds().h+GetHitBox().y+i*14,18,23};
        SDL_Rect src = {48,160,18,23};
//

        SDL_RenderCopy(r,textureManager->getTextureMap()["GUI_TileSheet"]->GetSDLTexture(),& src,&srsc);

         srsc = {GetContextCentre().x+m_titleText.GetBounds().w+23,m_titleText.GetBounds().h+GetHitBox().y+i*14,18,23};
         src = {66,160,18,23};
//

        SDL_RenderCopy(r,textureManager->getTextureMap()["GUI_TileSheet"]->GetSDLTexture(),& src,&srsc);
    }
    if(!m_children.empty())
        for(int i = 0; i< m_children.size(); i++)
            m_children[i]->Render(r);

             TextureManager::Instance()->drawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),"TileMap",GetHitBox().x+GetHitBox().w/2,GetHitBox().y+4,Colour_black,Align_Center);

m_Panel->Render(r);

}

void TileMapManagerWidget::Remove(int n)
{
    for(int i = 0 ; i < m_children.size(); i++)
    {
        delete m_children[i];
        m_children.erase(m_children.begin() + i);
    }
}
void  TileMapManagerWidget::Add(IWidget* Child)
{
    m_children.push_back(Child);
}
