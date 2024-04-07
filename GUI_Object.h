#ifndef GUI_OBJECT_H
#define GUI_OBJECT_H

#include <SDL2/SDL.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>

#include <TextureManager.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>
class GUI_Object : public GameObject
{
public:
    GUI_Object();
    virtual ~GUI_Object();
    void Load(std::string FileName) {}
    void Render();
    void Update();
    void Clean();
    void SetSize(SDL_FRect Rect );
    void Collision();
    std::string Texture();
    std::string Type();
    int getHeight();
    int getWidth();
     void SetTitle(std::string Title){m_title = Title;}
    bool isFoucs()
    {
        return m_foucs;
    }
    std::string getTitle(){return m_Title;};

    void setFoucs()
    {
        m_foucs = true;
    }
    void setNOFoucs()
    {
        m_foucs = false;
    }

    virtual void HandleEvent(SDL_Event& e ) {}
    void  changePos(SDL_FRect r)
    {
        m_desRect = r;
    }
protected:
std::string m_title;
    bool m_bisHighLit;
    bool m_foucs;
    std::string m_textureID;
    std::string m_filename;
    int m_height;
    int m_width;
    SDL_FRect m_srcRect;
    SDL_FRect m_desRect;
    std::string m_Title;

private:
    void DrawCentre();
    void  DrawSides();
    void DrawLeftAndRightSide();
    void DrawCorner();
};

class  GUIObjectCreater : public BaseCreater
{
public :
    GameObject* CreateGameObject() const
    {
        return  new GUI_Object();
    }
};
#endif // GUI_OBJECT_H
