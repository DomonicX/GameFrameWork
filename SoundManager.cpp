#include "SoundManager.h"

SoundManager *SoundManager::s_pInstance = 0;


void SoundManager::Close()
{
    std::cout << m_MusicMap.size() <<"  deleting m_MusicMap \n ";

    while(!m_MusicMap.empty())
    {
        auto itt = m_MusicMap.begin();
        Mix_FreeMusic(itt->second);
        m_MusicMap.erase( itt);

    }
    m_MusicMap.clear();


    Mix_CloseAudio();

}
bool SoundManager::Init(int flags)
{
    Mix_Init(flags);
    Mix_Linked_Version();

    if(Mix_QuerySpec(&frequency, &format,&channels))
    {

        printf("Mix_QuerySpec: %s\n", Mix_GetError());
        return true;
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
    {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(2);
        return true;
    };
    return false;
}
SoundManager::~SoundManager()
{

}

bool SoundManager::Load(std::string fileName, std::string id)
{

    if(! m_MusicMap.empty())
    {
        if( m_MusicMap.find(id)== m_MusicMap.end())
        {
            m_MusicMap[id] = Mix_LoadMUS(fileName.c_str());
            if(  m_MusicMap[id]==nullptr)
            {
                std::cout << " SoundManager :: loadSound Error \n";
                return false;
            }

        }
        else
        {
            std::cout << " SoundManager :: loadSound Error \n";
            return false;
        }

    }
    else    m_MusicMap[id] =Mix_LoadMUS(fileName.c_str());
    if(  m_MusicMap[id]==nullptr)
    {
        std::cout << " SoundManager :: loadSound Error \n";
        return false;
    }
    else  return true;





    Mix_Music *music = Mix_LoadMUS(fileName.c_str());
    m_MusicMap[id] = music;



    //  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(p_ren,pTempSurFace);
    //  SDL_free(pTempSurFace);

    return true;
}
void SoundManager::PauseMusic()
{
    Mix_PauseMusic();
    Mix_Paused(channels);
}
std::map<std::string,Mix_Music*> SoundManager::GetMusicMap()
{
    return m_MusicMap;
}
void SoundManager::ResumeMusic()
{
    Mix_ResumeMusic();
}
void SoundManager::SetPlay(std::string FileName,int loop)
{
    //  Mix_PlayChannelTimed(channels,m_MusicMap[FileName],loop,0);
    Mix_PlayMusic(m_MusicMap[FileName],loop);
};
void SoundManager::SetStop()
{
    Mix_HaltMusic();
};
void SoundManager::SetVolume(int volumeLevel)
{
    Mix_VolumeMusic(volumeLevel);
};
