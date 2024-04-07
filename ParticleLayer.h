#ifndef PARTICLELAYER_H
#define PARTICLELAYER_H


#include <ILayer.h>
#include <Application.h>
#include <InputHandler.h>
#include <TextureManager.h>

class ParticleLayer : public ILayer
{
    public:
        ParticleLayer();
        virtual ~ParticleLayer();

    void Update(float DeltaTime);
    void Render(SDL_Renderer *Ren,float OffsetX,float OffsetY);
    void HandleEvent(SDL_Event &e );
    protected:

    private:
};

#endif // PARTICLELAYER_H
