#ifndef MARIOBACKGROUND_H
#define MARIOBACKGROUND_H



#include <string.h>
#include <SDLGameObject.h>


typedef enum
{
    CLOUD,BUSH,HILL
} MarioBackGroundType;

class MarioBackGround: public SDLGameObject
{
    public:
        MarioBackGround();
        virtual ~MarioBackGround();

   void Load(char* filename) ;
     void Render();
     void Update();
     void Clean() {}
     void Collision() {}

      void HandleEvent(SDL_Event& e ){}
    std::string Type()
    {
        return m_Type;
    }
    std::string Texture()
    {
        return "MarioTileSet";
    }
protected:

private:
    int m_BackGroundType;
};

class MarioBackGroundObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioBackGround();
    }
};
#endif // MARIOBACKGROUND_H
