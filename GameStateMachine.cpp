#include "GameStateMachine.h"

void GameStateMachine::Clean()
{
    while(!m_gameStates.empty())
    {
        PopState();
    }
    m_gameStates.clear();
}
void GameStateMachine::Update()
{

    if(!m_gameStates.empty() )
    {
        m_gameStates.back()->Update();
    }
}

void GameStateMachine::Update(float dt)
{
    {

        if(!m_gameStates.empty() )
        {
            m_gameStates.back()->Update(dt);
        }
    }
}

void GameStateMachine::Render(SDL_Renderer *r)
{
    if(!m_gameStates.empty())
    {
        for(int i = 0; i <  (int)m_gameStates.size() ; i++ )
        {

            m_gameStates[i]->Render();
            m_gameStates[i]->Render(r);

        }

    }
}
void GameStateMachine::PushState(GameState *pstate)
{
    if(!m_gameStates.empty())
        if(m_gameStates.back()->Type()==pstate->Type())
            return;
    m_gameStates.push_back(pstate);
    m_gameStates.back()->OnEnter();
}

void GameStateMachine::PopState()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->onExit();
        //delete m_gameStates.back() ;
        delete m_gameStates[m_gameStates.size()-1];
        m_gameStates.pop_back();
    }
    //std::cout << "cant take last state of stack";
    // m_gameStates.back()->resume();
}
void GameStateMachine::ChangeState(GameState *pstate)
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->Type() == pstate->Type())
        {
            return ;
        }
        m_gameStates.back()->onExit();
        //delete m_gameStates.back() ;

        m_gameStates.pop_back();
    }
    PushState(pstate);
}



void GameStateMachine::HandleEvent(SDL_Event &e )
{
    if(!m_gameStates.empty() )
    {
        m_gameStates.back()->HandleEvent(e);
    }
}
