#include "State_GameEngine_EmptyProject.h"

State_GameEngine_EmptyProject::State_GameEngine_EmptyProject()
{
    //ctor
}

State_GameEngine_EmptyProject::~State_GameEngine_EmptyProject()
{
    //dtor
}

bool State_GameEngine_EmptyProject::OnEnter()
{
    std::cout << "enter \n";

    vec2f o =  App->GetOrigin();


    GUI_Wigdet * frame = guiFactory->Create("GUI_Frame");
    GUI_Frame& l_Frame = *dynamic_cast<GUI_Frame*>(frame);

    l_Frame.init("Frame", {0,0, App->GetWindowWidth(), App->GetWindowHeight()});
//
//    GUI_Wigdet *  pannel = guiFactory->Create("GUI_Pannel");
//    GUI_Pannel& l_pannel = *dynamic_cast<GUI_Pannel*>(pannel);
//
//
//    l_pannel.Init({0,23, App->GetWindowWidth(), App->GetWindowHeight()-24},Colour_darkcyan,Colour_darkblue, 1,24,3);
//
//
//    l_Frame.Add(pannel);

//
//    GUI_Wigdet * Buttonbar = guiFactory->Create("GUI_ButtonBar");
//    //GUI_ButtonBar& l_Buttonbar = *dynamic_cast<GUI_ButtonBar*>(Buttonbar);
//
//    l_Frame.Add(Buttonbar);
//
//    l_Buttonbar.SetHitBox({0,0,o.x*2,24});
//
//
//    GUI_Wigdet *  Button= guiFactory->Create("GUI_Button");
//    GUI_Button& l_Button = *dynamic_cast<GUI_Button*>(Button);
//    l_Button.init("File",0,0);
//    l_Buttonbar.Add(Button);
//
//    GUI_Wigdet *  SubButton = guiFactory->Create("GUI_SubButton");
//    GUI_SubButton& l_SubButton = *dynamic_cast<GUI_SubButton*>(SubButton);
//    l_SubButton.init("New",new Command("File/New"),0,0);
//
//    l_SubButton.SetHitBox({l_Button.Getposition().x,24,128,24});
//    l_Button.Add(SubButton);
//    GUI_Wigdet *  SubButton2 = guiFactory->Create("GUI_SubButton");
//    GUI_SubButton& l_SubButton2 = *dynamic_cast<GUI_SubButton*>(SubButton2);
//    l_SubButton2.init("Load",new Command("File/Load"),0,0);
//    l_SubButton2.SetHitBox({l_Button.Getposition().x,24*2,128,24});
//    l_Button.Add(SubButton2);
////    l_Button.Add(guiFactory->Create("GUI_SubButton"));
////    l_Button.Add(guiFactory->Create("GUI_SubButton"));
////    l_Button.Add(guiFactory->Create("GUI_SubButton"));
//
//
//    GUI_Wigdet *  Button2= guiFactory->Create("GUI_Button");
//    GUI_Button& l_Button2 = *dynamic_cast<GUI_Button*>(Button2);
//    l_Button2.init("Edit",l_Button.GetHitBox().x+l_Button.GetHitBox().w+1,0,22);
//    l_Buttonbar.Add(Button2);
//    GUI_Wigdet *  SubButton3 = guiFactory->Create("GUI_SubButton");
//    GUI_SubButton& l_SubButton3 = *dynamic_cast<GUI_SubButton*>(SubButton3);
//
//
//    l_SubButton3.init("Undo",NULL,0,0);
//
//
//    l_SubButton3.SetHitBox({l_Button2.Getposition().x,24,128,24});
//   // l_SubButton3.SetIsAvailable(false);
//    l_Button2.Add(SubButton3);
//    GUI_Wigdet *  SubButton4 = guiFactory->Create("GUI_SubButton");
//    GUI_SubButton& l_SubButton4 = *dynamic_cast<GUI_SubButton*>(SubButton4);
//    l_SubButton4.init("Redo",NULL,0,0);
//    l_SubButton4.SetHitBox({l_Button2.Getposition().x,l_SubButton3.getHeight()+24,128,24});
//   // l_SubButton4.SetIsAvailable(false);
//    l_Button2.Add(SubButton4);
//
//
//    GUI_Wigdet *  Button3= guiFactory->Create("GUI_Button");
//    GUI_Button& l_Button3 = *dynamic_cast<GUI_Button*>(Button3);
//    l_Button3.init("View",l_Button2.GetHitBox().x+l_Button2.GetHitBox().w+1,0,20);
//    l_Buttonbar.Add(Button3);
//
//    GUI_Wigdet *  Button4= guiFactory->Create("GUI_Button");
//    GUI_Button& l_Button4 = *dynamic_cast<GUI_Button*>(Button4);
//    l_Button4.init("Settings",l_Button3.GetHitBox().x+l_Button3.GetHitBox().w+1,0,16);
//    l_Buttonbar.Add(Button4);
//

//l_Button.init("Button",new Cmd::GameStateMachine(App->GetStateMachine(),"Push_State","TestStateUnitTestPannel"),200,200);


//    dynamic_cast<GUI_Pannel*>(pannel)->Init(SDL_Rect{16*0,16*0, o.x*2, 3*16},Colour_darkgrey,Colour_blue,1,0,0);


    App->PushCommand_Wigdet(&l_Frame,"Set_Frame","Frame");

    return true;

}

//        char* g = SDL_GetBasePath(); char* gh; char* gq;  SDL_GetPrefPath(gh,gq); std::cout << "sds << " << *g  << *gh<< *gq <<"\n";
