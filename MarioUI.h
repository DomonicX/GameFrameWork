#ifndef MARIOUI_H
#define MARIOUI_H


#include <string.h>
#include <SDLGameObject.h>
class MarioUI : public SDLGameObject
{
public:
    MarioUI();
    virtual ~MarioUI();
   void Load(char* filename) { m_UItype = filename; SDLGameObject::Load("asset/Mario/MarioBlock.txt"); }
      void Update() {}
    void Clean() {}
    void Collision() {}
    std::string Type()
    {
        return m_UItype;
    }
    std::string Texture()
    {
        return "MarioTileSet";
    }
protected:

private:
    std::string m_UItype;
};

class MarioUIObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioUI();
    }
};


#endif // MARIOUI_H
