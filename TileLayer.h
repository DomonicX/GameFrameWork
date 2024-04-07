#ifndef TILELAYER_H
#define TILELAYER_H

#include <ILayer.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>

class TileLayer : public ILayer
{
public:
    TileLayer();
    virtual ~TileLayer();
    void Update(float DeltaTime);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void HandleEvent(SDL_Event &e );
protected:

private:
};

#endif // TILELAYER_H
