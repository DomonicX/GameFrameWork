#ifndef GAMEMANAGERWIDGET_H
#define GAMEMANAGERWIDGET_H

#include <stdlib.h>

#include <IWidget.h>
#include <Application.h>
#include <ILayer.h>
#include <GameObject.h>
#include <WidgetFactory.h>
#include <ParticleSystem.h>
using namespace Gui;
class GameManagerWidget : public IWidget
{
    public:
        GameManagerWidget();
        virtual ~GameManagerWidget();

     void Load(std::string FileLocation);
     void HandleEvent(SDL_Event &e);
     void  Update(float DeltaTime) ;
     void Render(SDL_Renderer *r) ;
     void Remove(int n);
     void  Add(IWidget* Child) ;
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

  std::string Type(){return "GameManager";};

    protected:

    private:

        LText m_titleText;
        std::vector<std::string>m_textures;
        float deltaTime;
        float GameTime;
        int fps;
        ParticleSystem* p;


        std::string currentStateID;
        std::string Config;

    std::vector<IWidget*>m_children;

        std::vector<ILayer*>m_layers;
        std::vector<GameObject*>m_gameObects;
        vec2f SceneView,CameraView,WorldView,PixelView;
//        GameEngine_SceneView_Pannel
};

#endif // GAMEMANAGERWIDGET_H
