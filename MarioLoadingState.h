#ifndef MARIOLOADINGSTATE_H
#define MARIOLOADINGSTATE_H

#include <GameState.h>
#include <MarioMainMenuState.h>
#include <Application.h>
#include <TextureManager.h>
#include <FontManager.h>
#include <MarioBlock.h>
#include <MarioEnemy.h>
#include <MarioPlayer.h>
#include <MarioUI.h>
#include <MarioItem.h>
#include <MarioBackGround.h>
class MarioLoadingState : public GameState
{
    public:
        MarioLoadingState();
        virtual ~MarioLoadingState();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
  void HandleEvent(SDL_Event &e );
    std::string GetStateID()
    {
        return "MarioLoadingState";
    }
    protected:

    private:
};

#endif // MARIOLOADINGSTATE_H
