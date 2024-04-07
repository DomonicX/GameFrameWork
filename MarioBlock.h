#ifndef MARIOBLOCK_H
#define MARIOBLOCK_H
#include <string.h>
#include <SDLGameObject.h>
#include <iostream>
#include <TextureManager.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>
#include <Animation.h>
#include <SoundManager.h>
typedef enum
{
    QuestionMarkBlock,
    BrickGround,
    Brick2,Brick,
    PipeL,PipeR,
    PipeBL,PipeBR,
    SqaureBrick
} MarioBlockType;

class MarioBlock : public SDLGameObject
{
public:
    MarioBlock();
    virtual ~MarioBlock();
    void Load(char* filename);
    void Update();
    void Clean() {}
    void Bump();
    void Collision()
    {
        if(m_blocktype=="QuestionMarkBlock")
        {

            SoundManager::Instance()->SetPlay("smb_bump");
            m_srcRect = { 69, 63,16,16 };
            m_isStaticSprite  =true;
            m_isAnimationSprite = false;
        }
        if(m_blocktype!="QuestionMarkBlock")
        {
            SoundManager::Instance()->SetPlay("smb_breakblock");
            this->m_bDead = true;
            m_isStaticSprite  =false;
            m_isAnimationSprite = false;
        }
        //
    }

    std::string Type(){return m_blocktype;}
    void Draw();
    std::string Texture()
    {
        return "MarioTileSet";
    }
    void HandleEvent(SDL_Event& e ) {}
    SDL_Rect GetSDLRect()
    {
        return {m_position.x,m_position.x,m_width,m_height};
    }

protected:

private:
    Animation Ilde;
    int m_BlockState;
    std::string m_blocktype;
};

class  MarioBlockObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioBlock();
    }
};
#endif // MARIOBLOCK_H
