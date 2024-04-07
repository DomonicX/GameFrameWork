#include "LTimer.h"

LTimer::LTimer()
{
    Uint32 m_PausedTicks = 0;
    Uint32 m_startTicks= 0;
    bool m_paused = false;
    bool m_started= false;
    //ctor
}

LTimer::~LTimer()
{
    //dtor
}

void LTimer::Start()
{
    m_paused = false;
    m_started = true;
    m_startTicks = SDL_GetTicks();
    m_PausedTicks = 0;
}
void LTimer::Stop ()
{
    m_paused = false;
    m_started = false;
    m_startTicks = 0;
    m_PausedTicks = 0;
}
void LTimer::Pause()
{
    if(!isPaused() && isStarted())
    {
        m_paused = true;
        m_PausedTicks = SDL_GetTicks() - m_startTicks;
        m_startTicks = 0;
    }
}
void  LTimer::UnPause()
{
    if(isPaused() && isStarted())
    {
        m_paused = false;
        m_PausedTicks = SDL_GetTicks() - m_PausedTicks;
        m_PausedTicks = 0;

    }
}
Uint32 LTimer::GetTicks()
{
    Uint32 time = 0;
    if(m_started)
    {
        if(m_paused)
        {
            return m_PausedTicks;
        }
        else
        {
            time = SDL_GetTicks();
            - m_startTicks;
        }
    }
    return time;
}

bool LTimer::isStarted()
{
    return m_started;
}
bool LTimer::isPaused()
{
    return m_paused && m_started;
}
