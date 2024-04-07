#ifndef ENEMYLAYER_H
#define ENEMYLAYER_H

#include <ILayer.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>
#include <iostream>
#include <sstream>
#include <string>

class EnemyLayer: public ILayer
{
    public:
        EnemyLayer();
        EnemyLayer(float speed);
        virtual ~EnemyLayer();
  void Update(float DeltaTime);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void HandleEvent(SDL_Event &e ) ;
    protected:

    private:
        float m_speed = 0;
};

#endif // ENEMYLAYER_H
