#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H




#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <map>
#include <math.h>
#include <iostream>
#include <string.h>
//  SoundManager::Instance()->SetPlay("pacman_beginning");
class SoundManager
{
public:

    static SoundManager* Instance()
    {
        if(s_pInstance == NULL)
        {
            s_pInstance = new SoundManager();

            return s_pInstance;
        }
        return s_pInstance;
    }
    bool Init(int flags);
    void ResumeMusic();
    void PauseMusic();
    void SetPlay(std::string FileName,int loop =0);
    void SetStop();
    void SetVolume(int volumeLevel);
    std::map<std::string,Mix_Music*> GetMusicMap();
    bool Load(std::string fileName, std::string id);
    void Close();
    int GetSize()
    {
        return m_MusicMap.size();
    }
protected:

private:

    std::map<std::string,Mix_Music*>m_MusicMap;
    SoundManager()
    {


    }

    ~SoundManager();
    static SoundManager* s_pInstance;
    int frequency;
    Uint16 format;
    int channels;
};

#define  soundManager SoundManager::Instance()
#endif // SOUNDMANAGER_H

