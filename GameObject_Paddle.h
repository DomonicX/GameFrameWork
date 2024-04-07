#ifndef GAMEOBJECT_PADDLE_H
#define GAMEOBJECT_PADDLE_H



#include <SDLGameObject.h>
#include <GameObjectFactory.h>
#include <Application.h>
#include <TextureManager.h>
class GameObject_Paddle :public SDLGameObject
{
public:
    GameObject_Paddle();
    virtual ~GameObject_Paddle();
    void Load(std::string FileName) {}
    void Update(float dt);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void Clean() ;
    void Collision();
    std::string Type();
    bool isVisable(){return m_isVisable;}
    std::string Texture();
    void HandleEvent(SDL_Event& e );
protected:

private:
    bool m_isVisable;
    vec2f  Mouse;
    bool m_collisionFlag = false;
};
class CreateGameObject_Paddle : public BaseCreater
{
public :


    SDLGameObject* CreateGameObject() const
    {
        return  new GameObject_Paddle();
    }



};
#endif // GAMEOBJECT_PADDLE_H
