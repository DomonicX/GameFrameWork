#ifndef MARIOMAINMENUSTATE_H
#define MARIOMAINMENUSTATE_H


#include <GameState.h>

#include <Vector2D.h>
#include <MarioLevelState.h>
#include <Application.h>
#include <TextureManager.h>
#include <FontManager.h>
class MarioMainMenuState :  public GameState
{
    public:
        MarioMainMenuState();
        virtual ~MarioMainMenuState();
 void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
  void HandleEvent(SDL_Event &e );
    std::string GetStateID()
    {
        return "MarioMainMenuState";
    }
    protected:

    private:
         int Val = 0;
};

#endif // MARIOMAINMENUSTATE_H
