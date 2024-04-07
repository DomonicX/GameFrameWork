#ifndef LTIMER_H
#define LTIMER_H

#include <SDL2/SDL.h>
class LTimer
{
    public:
        LTimer();
        virtual ~LTimer();
void Start();
void Stop ();
void Pause();
void  UnPause();
Uint32 GetTicks();

bool isStarted();
bool isPaused();

    protected:

    private:


Uint32 m_PausedTicks;
Uint32 m_startTicks;
bool m_paused;
bool m_started;
};

#endif // LTIMER_H
/**<
const Uint32 timeout =SDL_GetTicks() + 100;
  if (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {

 }
 */
