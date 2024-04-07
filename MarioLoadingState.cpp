#include "MarioLoadingState.h"

MarioLoadingState::MarioLoadingState()
{
    //ctor
}

MarioLoadingState::~MarioLoadingState()
{
    //dtor
}

void MarioLoadingState::Render()
{
    TextureManager::Instance()->DrawText("MarioLoadingState ",0,0,FontManager::Instance()->GetFont("OpenSans-Bold"),Application::Instance()->GetRenderer());

}
void MarioLoadingState::Update()
{
    Application::Instance()->ChangeGameState(new MarioMainMenuState ());
}
bool MarioLoadingState::OnEnter()
{
    TextureManager::Instance()->Load("Img/Mario/MarioPlayer.PNG","MarioPlayer",SDL_Color({147,187,236}),Application::Instance()->GetRenderer());
    TextureManager::Instance()->Load("Img/stickman/smallstickmanWalking.PNG","smallstickmanWalking",SDL_Color({255,255,255}),Application::Instance()->GetRenderer());
    TextureManager::Instance()->Load("Img/Mario/MarioTileSet.PNG","MarioTileSet",SDL_Color({27,89,153}),Application::Instance()->GetRenderer());

    SoundManager::Instance()->Load("MP3/smb_powerup.WAV","smb_powerup");
    SoundManager::Instance()->Load("MP3/smb_1-up.WAV","smb_1-up");
    SoundManager::Instance()->Load("MP3/smb_bowserfalls.WAV","smb_bowserfalls");
    SoundManager::Instance()->Load("MP3/smb_bowserfire.WAV","smb_bowserfire");
    SoundManager::Instance()->Load("MP3/smb_breakblock.WAV","smb_breakblock");
    SoundManager::Instance()->Load("MP3/smb_bump.WAV","smb_bump");
    SoundManager::Instance()->Load("MP3/smb_coin.WAV","smb_coin");
    SoundManager::Instance()->Load("MP3/smb_fireball.WAV","smb_fireball");
    SoundManager::Instance()->Load("MP3/smb_fireworks.WAV","smb_fireworks");
    SoundManager::Instance()->Load("MP3/smb_flagpole.WAV","smb_flagpole");
    SoundManager::Instance()->Load("MP3/smb_gameover.WAV","smb_gameover");
    SoundManager::Instance()->Load("MP3/smb_jump-small.WAV","smb_jump-small");
    SoundManager::Instance()->Load("MP3/smb_jump-super.WAV","smb_jump-super");
    SoundManager::Instance()->Load("MP3/smb_kick.WAV","smb_kick");
    SoundManager::Instance()->Load("MP3/smb_mariodie.WAV","smb_mariodie");
    SoundManager::Instance()->Load("MP3/smb_pause.WAV","smb_pause");
    SoundManager::Instance()->Load("MP3/smb_pipe.WAV","smb_pipe");
    SoundManager::Instance()->Load("MP3/smb_powerup_appears.WAV","smb_powerup_appears");
    SoundManager::Instance()->Load("MP3/smb_stage_clear.WAV","smb_stage_clear");
    SoundManager::Instance()->Load("MP3/smb_stomp.WAV","smb_stomp");
    SoundManager::Instance()->Load("MP3/smb_vine.WAV","smb_vine");
    SoundManager::Instance()->Load("MP3/smb_warning.WAV","smb_warning");
    SoundManager::Instance()->Load("MP3/smb_world_clear.WAV","smb_world_clear");
    SoundManager::Instance()->Load("MP3/smb_main_theme.WAV","smb_main_theme");

    GameObjectFactory::Instance()->registerType("MarioBlock",new MarioBlockObjectCreater());
    GameObjectFactory::Instance()->registerType("MarioUI",new MarioUIObjectCreater());
    GameObjectFactory::Instance()->registerType("MarioItem",new MarioItemObjectCreater());
    GameObjectFactory::Instance()->registerType("MarioEnemy",new MarioEnemyObjectCreater());
    GameObjectFactory::Instance()->registerType("MarioPlayer",new MarioPlayerObjectCreater());
    GameObjectFactory::Instance()->registerType("MarioBackGround",new MarioBackGroundObjectCreater());

        if(Application::Instance()->Is_Debug())
            SDL_RenderSetScale(Application::Instance()->GetRenderer(),1,1);

        if(Application::Instance()->Is_GAME())
            SDL_RenderSetScale(Application::Instance()->GetRenderer(),4,4);

    return true;
};

bool MarioLoadingState::onExit() {}
void MarioLoadingState::resume() {}
void MarioLoadingState::HandleEvent(SDL_Event &e ) {}
