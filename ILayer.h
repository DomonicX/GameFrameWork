#ifndef ILAYER_H
#define ILAYER_H

#include <SDL2/SDL.h>
#include <vector>
#include <GameObject.h>
class ILayer
{
public:
    ILayer();
    virtual ~ILayer();
    virtual void Update(float DeltaTime)= 0;
    virtual void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY) = 0;
    virtual void HandleEvent(SDL_Event &e )= 0;
     std::vector<GameObject*> GetGameObejcts();
    void Add(GameObject * obj)
    {
        m_gameObjects.push_back(obj);
    }
    std::vector<GameObject*> m_gameObjects;
protected:

private:
};


#endif // ILAYER_H
//
//
//
//#ifndef LAYERWIGDETSTATEPANNEL_H
//#define LAYERWIGDETSTATEPANNEL_H
//
//#include <vector>
//#include <GUI_Wigdet.h>
//
//class LayerWigdetStatePannel: public LayerWigdet
//
//{
//public:
//    LayerWigdetStatePannel();
//    virtual ~LayerWigdetStatePannel();
//    virtual void Render() {}
//    virtual void Update() {}
//    virtual void HandleEvent() {}
//protected:
//
//private:
//};
//
//
//#endif // LAYERWIGDETSTATEPANNEL_H
