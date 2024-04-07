#include "ILayer.h"

ILayer::ILayer()
{
    //ctor
}

ILayer::~ILayer()
{

}

     std::vector<GameObject*> ILayer::GetGameObejcts(){return m_gameObjects;}

