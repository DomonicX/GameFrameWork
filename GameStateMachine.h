#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H
#include <vector>
#include <GameState.h>

#include <string.h>
#include <StateFactory.h>
#include <Particle.h>
class GameStateMachine
{
public:
    GameStateMachine()
    {
        //std::cout << "creating GameStateMachine\n";
    };
    virtual  ~GameStateMachine() {};
    void Update();
    void Update(float dt);
    void Render(SDL_Renderer *r);
    void PushState(GameState *pState);
    void ChangeState(GameState* pState);
    void PopState();
    void Clean();
    void HandleEvent(SDL_Event &e );
    std::string GetCurrentStateID()
    {

        return m_gameStates.back()->Type();
    }
    std::vector<GameState*> getStack()
    {
        return m_gameStates;
    }

protected:



private:

    std::vector<GameState*>m_gameStates;
};

#endif // GAMESTATEMACHINE_H
