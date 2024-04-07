#include "MarioBlock.h"

MarioBlock::MarioBlock()
{
    m_position = vec2f(0,0);
    //ctor
    m_bDead = false;
}

MarioBlock::~MarioBlock()
{
    //dtor
} void MarioBlock::Load(char* filename)
{
//    m_blocktype = filename;
//    std::string m_filename = filename;
//    std::ifstream ifs;
//    ifs.open (m_filename, std::ifstream::in);
//
//    ifs >> m_textureID;
//    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
//    ifs >> m_bisFilled;
//    ifs.close();

//    = filename;
    m_width = 16;
    m_height = 16;
    m_Type = filename;
    std::string filenameStr  = filename;

        m_desRect = {0,0,16,16};

    if(filenameStr=="QuestionMarkBlock")
    {
        m_blocktype = "QuestionMarkBlock";
        m_BlockState = QuestionMarkBlock;
        m_srcRect = {0,3*16,16,16};
        m_isAnimationSprite = true;
        m_isStaticSprite  = false;
        Ilde.AddSrect( 16, 3*16,16, 16 );
        Ilde.AddSrect( 32, 3*16,16, 16 );
        Ilde.AddSrect( 48, 3*16,16,16 );
    //    Ilde.AddSrect( 64, 3*16,16,16 );
        Ilde.maxFrame = 3;
        Ilde.frameRate = 150;
        Ilde.currentFrame = 0;
    }
    else if(filenameStr=="BrickGround")
    {
        m_blocktype = "BrickGround";
        m_BlockState = BrickGround;
        m_srcRect = {0,112,16,16};

        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="SqaureBrick")
    {
        m_blocktype = "SqaureBrick";
        m_BlockState = SqaureBrick;
        m_srcRect = {16*5,3*16,16,16};

        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Brick2")
    {
        m_blocktype = "Brick2";
        m_BlockState = Brick2;
        m_srcRect = {32,80,16,16};

        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Brick")
    {
        m_blocktype = "Brick";
        m_BlockState = Brick;
        m_srcRect = {16,80,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
//    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
//                     );

    } else if(filenameStr=="PipeL")
    {
        m_blocktype = "PipeL";
        m_BlockState = PipeL;
        m_srcRect ={96,32,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
//    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
//                     );

    }else if(filenameStr=="PipeBL")
    {
        m_blocktype = "PipeBL";
        m_BlockState = PipeBL;
        m_srcRect ={96,48,16,16};
        m_desRect = {m_position.x,m_position.y,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
//    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
//                     );

    }else if(filenameStr=="PipeR")
    {
        m_blocktype = "PipeR";
        m_BlockState = PipeR;
        m_srcRect ={112,32,16,16};
        m_desRect = {m_position.x,m_position.y,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
//    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
//                     );

    }else if(filenameStr=="PipeBR")
    {
        m_blocktype = "PipeBR";
        m_BlockState = PipeBR;
        m_srcRect ={112,48,16,16};
        m_desRect = {m_position.x,m_position.y,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
//    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
//                     );

    }
}

void MarioBlock::Draw()
{
    float x =App->GetCamera()->getpos().x;
    float y =App->GetCamera()->getpos().y;
if(!isIgnoreCamera())
{
    x = App->GetCamera()->getpos().x;
     y = App->GetCamera()->getpos().y;
}
else { x = 0; y = 0;}
    if(!Dead())
    {

        if(m_isStaticSprite)
        {
            m_desRect.x = m_position.x - x;
            m_desRect.y = m_position.y - y;
            TextureManager::Instance()->SDLDraw( App->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,SDL_FLIP_NONE);

        }
        if(m_isAnimationSprite)
        {
            m_desRect.x = m_position.x - x;
            m_desRect.y = m_position.y - y;
            TextureManager::Instance()->SDLDraw( App->GetRenderer(),Texture(), &Ilde.Srect[Ilde.currentFrame],&m_desRect,0,0,SDL_FLIP_NONE);

        }
    }
}


void MarioBlock::Update()
{

    if(m_isAnimationSprite)
    {
        m_currentFrame = ( ((SDL_GetTicks()/Ilde.frameRate)%Ilde.maxFrame));
        Ilde.currentFrame = m_currentFrame;
    }
    m_desRect = {m_position.x,m_position.y,m_width,m_height};

}
void MarioBlock::Bump()
{
    m_position.y-=8;
    std::cout << "bump\n";
}
