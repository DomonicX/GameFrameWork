#include "State_MainMenu_Settings.h"

State_MainMenu_Settings::State_MainMenu_Settings()
{
    //ctor
}

State_MainMenu_Settings::~State_MainMenu_Settings()
{
    //dtor
}

void State_MainMenu_Settings::Update()
{

    float dt = APP->GetDeltaTime();

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        APP->GetCamera().SetVirtualPos(APP->GetCamera().GetWorldPos()+vec2f(-1,0));
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        APP->GetCamera().SetVirtualPos(APP->GetCamera().GetWorldPos()+vec2f(1,0));
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        APP->GetCamera().SetVirtualPos(APP->GetCamera().GetWorldPos()+vec2f(0,-1));
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
        APP->GetCamera().SetVirtualPos(APP->GetCamera().GetWorldPos()+vec2f(0,1));

    for(int i = 0; i < maps.size(); i++)
    {
        maps[i].x -= APP->GetCamera().GetWorldPos().x;
        maps[i].y -= APP->GetCamera().GetWorldPos().y;
    }
        std::string ssx2 = InputHandler::Instance()->GetTextDropFile();

        if ( ssx2.find("png") != std::string::npos)
        {

            for(int i = 0; i < InputHandler::Instance()->GetTextDropFile().size(); i++)
                if(ssx2[i]=='\\')
                    ssx2.erase(0,i+1);
            ssx2.resize(ssx2.size()-4);
            texturesTites.push_back(ssx2);
             std::stringstream ss;
             ss << DirectoryHandler::Instance()->GetFileImg() << ssx2 << ".png";
            if(!TextureManager::Instance()->Load(APP->GetRenderer(),
                                                  ssx2,InputHandler::Instance()->GetTextDropFile(),ss.str().c_str(),Colour_magenta))
            {
                texturesTites.pop_back();
            }
//            SDL_ShowSimpleMessageBox(0,"sds","sds",App->GetWindow()->GetWindow());
            InputHandler::Instance()->ClearDragFile();
            std::cout <<TextureManager::Instance()->getTextureMap().size() << " File size \n ";


        }

        if ( ssx2.find("jpg") != std::string::npos)
        {

            for(int i = 0; i < InputHandler::Instance()->GetTextDropFile().size(); i++)
                if(ssx2[i]=='\\')
                    ssx2.erase(0,i+1);
            ssx2.resize(ssx2.size()-4);
            texturesTites.push_back(ssx2);
             std::stringstream ss;
             ss << DirectoryHandler::Instance()->GetFileImg() << ssx2 << ".jpg";
            if(!TextureManager::Instance()->Load(APP->GetRenderer(),
                                                  ssx2,InputHandler::Instance()->GetTextDropFile(),ss.str().c_str(),Colour_magenta))
            {
                texturesTites.pop_back();
            }
//            SDL_ShowSimpleMessageBox(0,"sds","sds",App->GetWindow()->GetWindow());
            InputHandler::Instance()->ClearDragFile();
            std::cout <<TextureManager::Instance()->getTextureMap().size() << " File size \n ";


        }

          if (ssx2.find("txt") != std::string::npos)
        {

            std::cout  << "txt\n";
            InputHandler::Instance()->ClearDragFile();
        }
pos = vec2f(WindowOrigin);

    vel += acc *speed* dt*2;
    pos += vel* dt*2;

}
void State_MainMenu_Settings::Render()
{
    SDL_SetRenderDrawColor(APP->GetRenderer(),0,23,125,125);


    SDL_RenderDrawLine(APP->GetRenderer(),0,0,190,100);

    std::vector<SDL_Rect> tiles = MakeGrid(0,0,9,9,32);




    for(int i = 0; i< texturesTites.size(); i++)
    {
        std::stringstream text;
//        text << texturesTites[i]<<  " " << App->GetCamera().GetWorldScaler() << " WPos:" <<  App->GetCamera().GetWorldPos()  << " WSize:"<< App->GetCamera().GetWorldSize() << " DropFile : " << InputHandler::Instance()->GetTextDropFile();

        text << texturesTites[i]<< " DropFile : " << InputHandler::Instance()->GetTextDropFile();
        textureManager->drawText(text.str(),WindowOrigin.x,WindowOrigin.y+FontManager::Instance()->GetFontSize("OpenSans-Regular")*i,Colour_white,fontManager->GetFont("OpenSans-Regular"),APP->GetRenderer());
    }


    TextureManager::Instance()->DrawRects(APP->GetRenderer(),&maps[0],maps.size(),Colour_teal,false);

    for(int i = 0 ; i < textCheck.size(); i ++)
    {
        textCheck[i].x+=i/9;

    }
    for(int i = 0 ; i < suhTextPosGrids.size()/16; i ++)
    {

        std::stringstream text;
        if(i%2==0)
        {

            for(int j = 0 ; j < 9; j ++)
            {

                float val = 0;
                std::stringstream text;
                val= GetRandomNumber()%9;

                text << val;
                textureManager->drawText(text.str(),i*32+WindowOrigin.x-suhTextPosGrids[suhTextPosGrids.size()].w,suhTextPosGrids[i].y+j*32,Colour_white,fontManager->GetFont("OpenSans-Regular"),APP->GetRenderer());





            }
        }
    }
//    TextureManager::Instance()->DrawRects(App->GetRenderer(),&suhTextPosGrids[0],suhTextPosGrids.size(),Colour_black,false);
//    TextureManager::Instance()->DrawRects(App->GetRenderer(),&suhGrids[0],suhGrids.size(),Colour_white,false);


    cam= APP->GetCamera().GetRectF();
TextureManager::Instance()->DrawGrid(cam.x,cam.y,cam.w/256,cam.h+1/256,256,Colour_black,APP->GetRenderer());
TextureManager::Instance()->DrawGrid(cam.x,cam.y,cam.w/128,cam.h+1/128,128,Colour_black,APP->GetRenderer());
TextureManager::Instance()->DrawGrid(cam.x,cam.y,cam.w/64,cam.h+1/64,64,Colour_black,APP->GetRenderer());
TextureManager::Instance()->DrawGrid(cam.x,cam.y,cam.w/32,cam.h+1/32,32,Colour_black,APP->GetRenderer());
    std::vector<SDL_Rect> xx = MakeGrid(cam.x+counter,cam.y,cam.w/16,cam.h+1/16,16);
    TextureManager::Instance()->DrawRects(APP->GetRenderer(),&xx[0],xx.size(),Colour_black,false);
int aas = 0;
vec2f aas1 = vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y-128);
vec2f aas2  = vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y+128);
vec2f aas3  = vec2f(MOUSEPOSITION.x+128,MOUSEPOSITION.y);
vec2f aas4  = vec2f(MOUSEPOSITION.x-128,MOUSEPOSITION.y);

    for(int i = 0; i<
            xx.size(); i++)

        if(InputHandler::Instance()->MouseinRect(xx[i]) && vec2f::Dist(vec2f(MOUSEPOSITION.x,MOUSEPOSITION.y-128),vec2f(xx[i].x,xx[i].y))/16)

            TextureManager::Instance()->DrawRect(APP->GetRenderer(),xx[i],Colour_forestgreen,true);


    TextureManager::Instance()->SetColour(Colour_floralwhite,APP->GetRenderer());

    SDL_RenderDrawLine(APP->GetRenderer(),aas3.x,aas4.y,aas1.x,aas2.y);
    SDL_RenderDrawLine(APP->GetRenderer(),aas4.x,aas3.y,aas2.x,aas1.y);
    SDL_RenderDrawLine(APP->GetRenderer(),aas4.x,aas3.y,aas1.x,aas2.y);
    SDL_RenderDrawLine(APP->GetRenderer(),aas3.x,aas4.y,aas2.x,aas1.y);

    std::cout << WindowOrigin.vectorAngle(MOUSEPOSITION.x-WindowOrigin.x,MOUSEPOSITION.y-WindowOrigin.y) << "\n";



        TextureManager::Instance()->Drawcircle(APP->GetRenderer(),MOUSEPOSITION.x,MOUSEPOSITION.y,Colour_antiquewhite,128,false);
    for(int i = 0; i<
            texturesTites.size(); i++)
    {
            int cx = TextureManager::Instance()->getTextureMap()[texturesTites[i]]->GetWidth()/2;
             int cy =   TextureManager::Instance()->getTextureMap()[texturesTites[i]]->GetHeight()/2;
SDL_Point point= vecToSDL_Point(vec2f(cx,cy));
        std::string stri =  texturesTites[i];
        SDL_Rect poss = {MOUSEPOSITION.x,MOUSEPOSITION.y,TextureManager::Instance()->getTextureMap()[stri]->GetWidth(),TextureManager::Instance()->getTextureMap()[stri]->GetHeight()};
        SDL_RenderCopyEx(APP->GetRenderer(), TextureManager::Instance()->getTextureMap()[stri]->GetSDLTexture(),NULL,&poss,
                          (WindowOrigin.vectorAngle(MOUSEPOSITION.x,MOUSEPOSITION.y))*vec2f::Dist(MOUSEPOSITION,WindowOrigin)/180,&point,SDL_FLIP_NONE);
    }//angle
//    TextureManager::Instance()->DrawVector(APP->GetRenderer(),MOUSEPOSITION,WindowOrigin,WindowOrigin.vectorAngle(MOUSEPOSITION.x-WindowOrigin.x,MOUSEPOSITION.y-WindowOrigin.y));

}

bool State_MainMenu_Settings::OnEnter()
{


    SDL_FRect rectf = APP->GetCamera().GetRectF();
    speed = (1);
    acc = vec2f(0,0);

    //acc.Normalise();


    maps = MakeGrid(0,rectf.h+rectf.y,9,1,32);



    //std::cout << speed << "s[eed\n";

}
bool State_MainMenu_Settings::onExit() {}
void State_MainMenu_Settings::resume() {}
void State_MainMenu_Settings::HandleEvent(SDL_Event &e )
{
//   if(Application::Instance()->GetWindow()->GetWidget()->Find("Hello")->IsMousePressed())
//    {
//std::cout << "tab is pressed " << "\n";
//
//    };

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
//    Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->SetVisable(false);
//    Application::Instance()->GetWindow()->GetWidget()->Find("Panel2")->SetVisable(false);

    }
    if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {

//    Application::Instance()->GetWindow()->GetWidget()->Find("tab")->SetVisable(true);
//    Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->SetVisable(true);
//    Application::Instance()->GetWindow()->GetWidget()->Find("Panel2")->SetVisable(true);
    }
}
/**<
//
    SDL_RenderDrawLine(App->GetRenderer(),WindowOrigin.x,WindowOrigin.y,MousePosition.x,MousePosition.y);
    TextureManager::Instance()->SetColour(Colour_yellow,App->GetRenderer());

 TextureManagerPannel = new Gui::Panel();
    TextureManagerPannel->Init("Panel1",{0,32,200,200});
//    Application::Instance()->GetWindow()->GetWidget()->Find("Frame")->Add(TextureManagerPannel);
TextureManagerPannel->SetVisable(false);
 TextureManagerPannel = new Gui::Panel();
    TextureManagerPannel->Init("Panel2",{200,64,200,200});
//    Application::Instance()->GetWindow()->GetWidget()->Find("Frame")->Add(TextureManagerPannel);
tablist = new Gui::TabList();
tab = new Gui::Tab();
tab2= new Gui::Tab();
tablist->Init("tablist2",{0,0,0,0},{0,0,0,0});
tab->Init("tab");
tab->SetPadding(16,4,16,0);
tab2->Init("tab2");
tab2->SetPadding(16,4,16,0);

InputHandler::Instance()->StartTextInput();

//tablist->Add(tab2);
//TextureManagerPannel->Add(tablist);

//Gui::Button *Button2 = new Gui::Button();
////    Button2->Init("PushPopStateCheck",Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->GetContextRect());
//   Button2->OnAction(NULL);
//

    //Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->Add(Button2);




//    Application::Instance()->GetWindow()->GetWidget()->Find("Panel2")->SetPosition(WindowOrigin);

//    Application::Instance()->StartTextEditingActive();
//        SDL_Rect screensize =SDL_Rect({0,32,480,270});
//    SDL_RenderSetLogicalSize(Application::Instance()->GetRenderer(),480,270);
//    SDL_RenderSetViewport(Application::Instance()->GetRenderer(),&screensize );
////    SDL_RenderSetIntegerScale(Application::Instance()->GetRenderer(),SDL_TRUE);
//    SDL_RenderSetScale(Application::Instance()->GetRenderer(),1,1);
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);

#include "State_MainMenu_Settings.h"

State_MainMenu_Settings::State_MainMenu_Settings()
{
    //ctor
}

State_MainMenu_Settings::~State_MainMenu_Settings()
{
    //dtor
}

void State_MainMenu_Settings::Update()
{
//
////std::cout << " rect \n"  <<
////    Application::Instance()->GetWindow()->GetWidget()->Find("Frame")->GetComponentRect().h;
//  //  Application::Instance()->GetWindow()->GetWidget()->Find("tab")->SetPosition(vec2f(MousePosition.x,MousePosition.y));
////LeftUp,RightDown,MiddleDown,LeftDown,RightDown,MiddleDown
//
//    float dt = App->GetDeltaTime();
//
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
//        App->GetCamera().SetVirtualPos(App->GetCamera().GetWorldPos()+vec2f(-1,0));
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
//        App->GetCamera().SetVirtualPos(App->GetCamera().GetWorldPos()+vec2f(1,0));
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
//        App->GetCamera().SetVirtualPos(App->GetCamera().GetWorldPos()+vec2f(0,-1));
//    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
//        App->GetCamera().SetVirtualPos(App->GetCamera().GetWorldPos()+vec2f(0,1));
//
//    for(int i = 0; i < maps.size(); i++)
//    {
//        maps[i].x -= App->GetCamera().GetWorldPos().x;
//        maps[i].y -= App->GetCamera().GetWorldPos().y;
//    }
//    if(InputHandler::Instance()->IsDropFile())
//    {
//
//        std::string ssx2 = InputHandler::Instance()->GetTextDropFile();
//
//        if ( ssx2.find("png") != std::string::npos)
//        {
//
//            for(int i = 0; i < InputHandler::Instance()->GetTextDropFile().size(); i++)
//                if(ssx2[i]=='\\')
//                    ssx2.erase(0,i+1);
//            ssx2.resize(ssx2.size()-4);
//            texturesTites.push_back(ssx2);
//          if(!TextureManager::Instance()->Load(InputHandler::Instance()->GetTextDropFile(),ssx2,App->GetRenderer()))
//          {
//              texturesTites.pop_back();
//          }
//
//          SDL_ShowSimpleMessageBox(0,"sds","sds",App->GetWindow()->GetWindow());
//                      InputHandler::Instance()->ClearDragFile();
//            std::cout <<TextureManager::Instance()->getTextureMap().size() << " File size \n ";
//
//
//        }
//
//        if (ssx2.find("txt") != std::string::npos)
//        {
//
//            std::cout  << "txt\n";
//            InputHandler::Instance()->ClearDragFile();
//        }
////
////
//
//    }
////std::cout << (double)App->GetDeltaTime() << "\n";
////
//
//// acc1 = vec2f(pos-pos1);
//    vel += acc *speed* dt*2;
////    vel.Limit(10);
//    pos += vel* dt*2;
////
//
////            std::cout << " acc " << acc << " vel " << vel << " pos " << pos << " \n";
//
//// pos1 += vel1 += acc1 * dt;

}
void State_MainMenu_Settings::Render()
{

////   if(Application::Instance()->GetWindow()->GetWidget()->Find("tab")->isVisable()){
////    if(InputHandler::Instance()->isTextInputActive())
////    {
////
////tab->ChangeText(InputHandler::Instance()->GetTextInput(),App->GetRenderer());
////    }
////TextureManagerPannel2->Add(NULL);
////TextureManagerPannel->Add(NULL);
//    SDL_SetRenderDrawColor(App->GetRenderer(),0,23,125,125);
//
//
//    SDL_RenderDrawLine(App->GetRenderer(),0,0,190,100);
//    //  textureManager->DrawVector(App->GetRenderer(),WindowOrigin,MousePosition);
//
////        if(vec2f::Dot(pos1.GetNormalise(),pos1.GetNormalise()))
//
//
//    std::vector<SDL_Rect> tiles = MakeGrid(0,0,9,9,32);
//
//
//
//
//    TextureManager::Instance()->DrawRects(App->GetRenderer(),&tiles[0],tiles.size(),Colour_white,false);
//
//    // TextureManager::Instance()->DrawRect(App->GetRenderer(),MousePosition,32,32,Colour_chartreuse);
//
//    for(int i = 0 ; i < tiles.size(); i++)
//        textureManager->DrawVector(App->GetRenderer(),vec2f(tiles[i].x+16,tiles[i].y+16),vec2f(tiles[i].x,tiles[i].y));
//
//    SDL_Rect  rect = {0,0,480,302};
//    SDL_FRect rectf = App->GetCamera().GetRectF();
//    TextureManager::Instance()->Draw(App->GetRenderer(),"CameraViewPort",rect,rectf,0,NULL,SDL_FLIP_NONE);
//    //   TextureManager::Instance()->DrawGrid(16,32+16,28,16,16,Colour_pink,App->GetRenderer());
//    TextureManager::Instance()->DrawGrid(0,32,15,9,32,Colour_darkkhaki,App->GetRenderer());
////    textureManager->DrawVector(App->GetRenderer(),WindowOrigin,alignToVec2Position(MousePosition,16));
//    // textureManager->DrawVector(App->GetRenderer(),WindowOrigin,MousePosition);
//
//
//    Rectangle rectangle = {WindowOrigin,MousePosition};
//    textureManager->DrawVector(App->GetRenderer(),rectangle.rectTopLeft,rectangle.rectBottomRight);
//
//
//    textureManager->Drawcircle(App->GetRenderer(),pos.x+App->GetCamera().GetWorldPos().x,pos.y+App->GetCamera().GetWorldPos().y,Colour_red,16,true);
//    textureManager->Drawcircle(App->GetRenderer(),pos1.x+App->GetCamera().GetWorldPos().x,pos1.y+App->GetCamera().GetWorldPos().y,Colour_aliceblue,16,true);
//    {
//
//        std::stringstream text;
////if(Application::Instance()->isTextEditingActive())
////  text << InputHandler::Instance()->GetTextInput();
//
//        text << "Scale:" << App->GetCamera().GetScaler() << " Pos:" <<  App->GetCamera().GetPos()  << " Size:"<< App->GetCamera().GetSize() << " DropFile : " << InputHandler::Instance()->GetTextDropFile();
//        textureManager->DrawText(text.str(),0,0,Colour_white,fontManager->GetFont("OpenSans-Regular"),App->GetRenderer());
//
//    }
//                for(int i = 0; i< texturesTites.size(); i++)
//                        {
//        std::stringstream text;
//        text << texturesTites[i]<<  " " ;// << App->GetCamera().GetWorldScaler() << " WPos:" <<  App->GetCamera().GetWorldPos()  << " WSize:"<< App->GetCamera().GetWorldSize() << " DropFile : " << InputHandler::Instance()->GetTextDropFile();
//      SDL_Rect tt = FontManager::Instance()->QueryText(texturesTites[i],"OpenSans-Regular");
//SDL_Rect aa = {0,rectf.h+rectf.y+i*tt.h,tt.w,tt.h};
//  textureManager->DrawText(text.str(),aa.x,aa.y,Colour_white,fontManager->GetFont("OpenSans-Regular"),App->GetRenderer());
//  SDL_Rect uRect = InputHandler::Instance()->UnionRect(tt,FontManager::Instance()->QueryText(texturesTites[i],"OpenSans-Regular"));
//  //  std::cout << "uRect" << uRect.x << "x" << uRect.y << "y" <<uRect.w<< "w" <<uRect.h << "h\n" ;
//
//    TextureManager::Instance()->DrawRect(App->GetRenderer(),vec2f(uRect.x,uRect.y),uRect.w,uRect.h);
//        }
//
//SDL_Rect xxx = Application::Instance()->GetWindow()->GetWidget()->Find("Frame")->GetComponentRect();
//   // TextureManager::Instance()->DrawRect(App->GetRenderer(),vec2f(xxx.x,xxx.y),xxx.w,xxx.h,Colour_GUIForeGround,true);
//
//   TextureManager::Instance()->DrawRects(App->GetRenderer(),&maps[0],maps.size(),Colour_teal,false);
////    SDL_RenderFillRects(App->GetRenderer(),&maps[0],maps.size());
//
//
//TextureManagerPannel->SetPosition(MousePosition);
//
//    for(int i = 0 ; i < textCheck.size(); i ++)
//    {
//        textCheck[i].x+=i/9;
//
//    }
//    for(int i = 0 ; i < suhTextPosGrids.size()/16; i ++)
//    {
//
//        std::stringstream text;
//        if(i%2==0)
//        {
//
//            for(int j = 0 ; j < 9; j ++)
//            {
//
//                float val = 0;
//                std::stringstream text;
//                val= Application::Instance()->GetRandomNumber()%9;
//
//                text << val;
//                textureManager->DrawText(text.str(),suhTextPosGrids[i].x,suhTextPosGrids[i].y+(j*32),Colour_white,fontManager->GetFont("OpenSans-Regular"),App->GetRenderer());
//
//
//
//
//
//            }
//        }
//    }
//    TextureManager::Instance()->DrawRects(App->GetRenderer(),&suhTextPosGrids[0],suhTextPosGrids.size(),Colour_black,false);
//    TextureManager::Instance()->DrawRects(App->GetRenderer(),&suhGrids[0],suhGrids.size(),Colour_white,false);
//
//                for(int i = 0; i<
//                        texturesTites.size(); i++)
//                        {
//
//   std::string stri =  texturesTites[i];
//        SDL_Rect poss = {MousePosition.x,MousePosition.y,TextureManager::Instance()->getTextureMap()[stri]->GetWidth(),TextureManager::Instance()->getTextureMap()[stri]->GetHeight()};
//        SDL_RenderCopy(App->GetRenderer(), TextureManager::Instance()->getTextureMap()[stri]->GetSDLTexture(),NULL,&poss);
//    }
//
////    TextureManager::Instance()->DrawGrid(0,32,9*2,9*2,16,Colour_black,App->GetRenderer());
////    TextureManager::Instance()->DrawGrid(0,32,9,9,32,Colour_white,App->GetRenderer());
//
//
//  TextureManager::Instance()->DrawRect(App->GetRenderer(),WindowOrigin,128,64);
//
//    float inc = 0.0f;
//  for(int i = 0; i < 128; i++)
//  {
//inc += std::sin(i)*4;
//                   SDL_RenderDrawPoint(App->GetRenderer(),WindowOrigin.x+inc,WindowOrigin.y+32);
//  }
//
////    TextureManager::Instance()->DrawRect(App->GetRenderer(),
////    Application::Instance()->GetWindow()->GetWidget()->Find("tab")->GetContextRect(),Colour_antiquewhite,true);

}

bool State_MainMenu_Settings::OnEnter()
{

// TextureManagerPannel = new Gui::Panel();
//    TextureManagerPannel->Init("Panel1",{0,32,200,200});
//    Application::Instance()->GetWindow()->GetWidget()->Find("Frame")->Add(TextureManagerPannel);
//
// TextureManagerPannel = new Gui::Panel();
//    TextureManagerPannel->Init("Panel2",{200,64,200,200});
//    Application::Instance()->GetWindow()->GetWidget()->Find("Frame")->Add(TextureManagerPannel);
//tab = new Gui::Tab();
//tablist = new Gui::TabList();
//
//    SDL_Rect Camrect = App->GetCamera().GetRect();
////tablist->Init("tablist",{Camrect.x,Camrect.y-26 ,200,32});
//                            SDL_Rect ect =  Application::Instance()->GetWindow()->GetWidget()->Find("Panel")->GetHitBox();
//
//tablist->Init("tablist2",{ect.x+16,ect.y-26,200,32});
//tab->Init("tab");
//tab->SetPosition(tablist->GetPosition());
//tab->SetPadding(16,4,16,0);
//  dynamic_cast<Gui::Tab*>(tab)->ChangeText("Hello",App->GetRenderer());
//tab2= new Gui::Tab();
//tab2->Init("tab2");
//tablist->Add(tab);
//
//tab2->SetPosition(vec2f(tab->GetHitBox().x+tab->GetContextRect().w,tab->GetHitBox().y));
//tab2->SetPadding(16,4,0,0);
//  dynamic_cast<Gui::Tab*>(tab2)->ChangeText("World",App->GetRenderer());
//  // dynamic_cast<Gui::Tab*>(tab)->SetTextColour(Colour_white);
////   dynamic_cast<Gui::TabList*>(tablist)->ChangeText("Log & others",App->GetRenderer());
////   dynamic_cast<Gui::TabList*>(tablist)->SetTextColour(Colour_white);
//
////   dynamic_cast<Gui::Panel*>(TextureManagerPannel)->SetTextColour(Colour_white);
////   dynam//   dynamic_cast<Gui::Panel*>(TextureManagerPannel)->SetTextColour(Colour_green);
////   dynamic_cast<Gui::Panel*>(TextureManagerPannel)->ChangeText("Panel1",App->GetRenderer());
////dynamic_cast<Gui::Panel*>(TextureManagerPannel)->ChangeText("Log & others",App->GetRenderer());
//InputHandler::Instance()->StartTextInput();
//
//tablist->Add(tab2);
//TextureManagerPannel->Add(tablist);
//
//Gui::Button *Button2 = new Gui::Button();
//    Button2->Init("PushPopStateCheck",Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->GetContextRect());
//   Button2->OnAction(NULL);
//
//
//    //Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->Add(Button2);
//
//
//
//
////    Application::Instance()->GetWindow()->GetWidget()->Find("Panel2")->SetPosition(WindowOrigin);
//
////    Application::Instance()->StartTextEditingActive();
////        SDL_Rect screensize =SDL_Rect({0,32,480,270});
////    SDL_RenderSetLogicalSize(Application::Instance()->GetRenderer(),480,270);
////    SDL_RenderSetViewport(Application::Instance()->GetRenderer(),&screensize );
//////    SDL_RenderSetIntegerScale(Application::Instance()->GetRenderer(),SDL_TRUE);
////    SDL_RenderSetScale(Application::Instance()->GetRenderer(),1,1);
////    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
//
//    SDL_Rect  rect = {0,0,480,302};
//
//    SDL_FRect rectf = App->GetCamera().GetRectF();
//
//    SDL_Rect Vrectf = App->GetCamera().GetWorldRect();
//    pos1 = vec2f(Vrectf.x,Vrectf.y+rectf.y);
//    pos = pos1 + vec2f(0,rect.h*0.25);
//    speed = (1920/WindowWidth)/3;
//    acc = vec2f(pos1-pos);
//
//    acc.Normalise();
//
//
//    maps = MakeGrid(0,rectf.h+rectf.y,9,1,32);
//
//
//
//    //std::cout << speed << "s[eed\n";
//
//
//



}
bool State_MainMenu_Settings::onExit() {}
void State_MainMenu_Settings::resume() {}
void State_MainMenu_Settings::HandleEvent(SDL_Event &e )
{


//
//
//   if(Application::Instance()->GetWindow()->GetWidget()->Find("tab")->IsMousePressed())
//    {
//std::cout << "tab is pressed " << "\n";
//
//    };
//
//if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
//{
////    Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->SetVisable(false);
////    Application::Instance()->GetWindow()->GetWidget()->Find("Panel2")->SetVisable(false);
//
//}
//if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
//{
//
////    Application::Instance()->GetWindow()->GetWidget()->Find("tab")->SetVisable(true);
////    Application::Instance()->GetWindow()->GetWidget()->Find("Panel1")->SetVisable(true);
////    Application::Instance()->GetWindow()->GetWidget()->Find("Panel2")->SetVisable(true);
//}
//
//
//


}

 */
