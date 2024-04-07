#ifndef FILEMENUMANAGER_H
#define FILEMENUMANAGER_H

#include <IWidget.h>
#include <Application.h>
class FileMenuCallBack: public CallBack
{
public:
    FileMenuCallBack(std::string menuTitle) : m_menutile(menuTitle) {};
    ~FileMenuCallBack() {}
    void call()
    {
        if(m_menutile=="File")
        {

            std::cout << m_menutile << " - Menu callback\n";
            Application::Instance()->GetWindow()->GetWidget()->Find("New")->SetVisable(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("Open")->SetVisable(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("Save")->SetVisable(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("Save...As")->SetVisable(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("New")->SetFocus(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("Open")->SetFocus(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("Save")->SetFocus(true);
            Application::Instance()->GetWindow()->GetWidget()->Find("Save...As")->SetFocus(true);
//        SDL_Rect m_viewport =  APP->GetCamera().GetRect();
//        SDL_RenderIsClipEnabled(APP->GetRenderer());
//        SDL_RenderSetIntegerScale(APP->GetRenderer(),SDL_TRUE);
//        SDL_RenderSetLogicalSize(APP->GetRenderer(),m_viewport.w,m_viewport.h);
//
//        SDL_RenderSetClipRect(APP->GetRenderer(),&m_viewport);
////
//
//        float scales = m_viewport.w /(float) m_viewport.h;
//        SDL_RenderSetScale(APP->GetRenderer(),scales,scales);
//        APP->GetCamera().SetScaler(3);
//        APP->GetCamera().SetPos(vec2f(0,0));
//        Application::Instance()->GetWindow()->GetWidget()->SetVisable(false);
//
//        APP->GetCamera().SetSize(vec2f(1920,1080));
        }
        if(m_menutile=="Quit")
        {
           Application::Instance()->quit();
        }
        if(m_menutile=="Close")
        {
            std::cout << m_menutile << " - Menu callback\n";
//       Application::Instance()->Instance()->GetWindow()->closePopUp();
       Application::Instance()->Instance()->GetWindow()->FreePopUpWindow();

        }
        if(m_menutile=="Edit")
        {
            std::cout << m_menutile << " - Menu callback\n";

        }
        if(m_menutile=="New")
        {
            WindowImp *WindowImpt = new WindowImp();
            Frame* framet = new Frame();
            Panel* Panelt = new Panel();
            Menu *Close  = new Menu();


            WindowImpt->Init("Window1",WindowRect);
            framet->Init("frame1",{WindowRect.w/3,WindowRect.h/3,256*2,256});
            Panelt->Init("Panel1", {WindowRect.w/3,WindowRect.h/3,256*2,256});
            Close->Init("Close", {WindowRect.w/2,WindowRect.h/2,200,200});
            //  Close->OnAction( new StaticCallBack(foo));
            Close->SetPadding(16,0,16,0);
 Close->OnAction(new FileMenuCallBack("Close"));
//
//            Application::Instance()->GetWindow()->GetWidget()->Find("New")->SetVisable(false);
//            Application::Instance()->GetWindow()->GetWidget()->Find("Open")->SetVisable(false);
//            Application::Instance()->GetWindow()->GetWidget()->Find("Save")->SetVisable(false);
//            Application::Instance()->GetWindow()->GetWidget()->Find("New")->SetFocus(false);
//            Application::Instance()->GetWindow()->GetWidget()->Find("Open")->SetFocus(false);
//            Application::Instance()->GetWindow()->GetWidget()->Find("Save")->SetFocus(false);
//    Application::Instance()->Instance()->GetWindow()->GetWidget()->Find("File")->Remove(2);
//    Application::Instance()->Instance()->GetWindow()->GetWidget()->Find("File")->Remove(1);
//    Application::Instance()->Instance()->GetWindow()->GetWidget()->Find("File")->Remove(0);
            Application::Instance()->GetWindow()->AddPopUpWindow(WindowImpt);
            WindowImpt->Add(framet);
            framet->Add(Panelt);
            Panelt->Add(Close);



        }
    }
private:
    std::string m_menutile;
};




using namespace Gui;

class FileMenuManager: public IWidget
{
public:

    FileMenuManager();
    virtual ~FileMenuManager();
    void Load(std::string FileLocation);
    void HandleEvent(SDL_Event &e);
    void  Update(float DeltaTime) ;
    void Render(SDL_Renderer *r) ;
    void Remove(int n);
    void  Add(IWidget* Child);

    IWidget& GetChild(int i)
    {
        if(i < m_children.size())
            return *m_children[i];
        std::cout <<"errorrr GUI_OUTBOUND GET CHILD \n";
        return *m_children[m_children.size()-1];
    };

    int GetChildSize()
    {
        return m_children.size();
    };

    std::string Type()
    {
        return "FileMenuManager";
    }

protected:

private:
    std::vector<IWidget*>m_children;

};

#endif // FILEMENUMANAGER_H
/**<


    */
