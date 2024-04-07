#include "State_BlankScreen.h"

State_BlankScreen::State_BlankScreen()
{
    //ctor
}

State_BlankScreen::~State_BlankScreen()
{
    //dtor
}

void State_BlankScreen::Render()
{
};
void State_BlankScreen::Update()
{
};
bool State_BlankScreen::OnEnter()
{

    TextureManager::Instance()->Load("Img/GUI_TileSheet.png","GUI_TileSheet",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Shapes.png","Shapes",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Tile_Floor_Wood.png","Tile_Floor_Wood",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/BackGround_256.png","BackGround_256",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/BackGround3.png","BackGround3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/1.png","Tile_wood",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/2.png","Tile_wood_Mask",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/3.png","Tile_wood_Mask2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/4.png","Tile_wood_Mask3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/circle2.png","circle2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur.png","blur",Colour_black,APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur2.png","blur2",Colour_black,APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur3.png","blur3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/background.png","background",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/background2.png","background2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/background1.png","background1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/background4.png","background4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/level1_BackGround.png","level1_BackGround",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur4.png","blur4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blur5.png","blur5",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/spriteSheet01.png","Sheet01",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/bush.png","bush",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree.png","tree",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree1.png","tree1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree2.png","tree2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tree3.png","tree3",Colour_white,APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Rock.png","Rock",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/char.png","char",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/char2.png","char2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/char3.png","char3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/cannon.png","cannon",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/backgroundS.png","backgroundS",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/rocks.png","rocks",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/walking1.png","walking1",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/compass.png","compass",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/par_effect.png","par_effect",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/TS.png","TS",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/TS_ALPHA.png","TS_ALPHA",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/32x32.png","32x32",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blank.png","blank",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blank2.png","blank2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/blank3.png","blank3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/platformTile.png","platformTile",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/platformTile2.png","platformTile2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/platformTile3.png","platformTile3",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/platformTile4.png","platformTile4",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/platformTile5.png","platformTile5",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/lights.png","lights",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Error.png","Error",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tile.png","tile",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Spikes.png","Spikes",APP->GetRenderer());

    TextureManager::Instance()->Load("Img/chair.png","chair",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/table.png","table",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Bubble.png","Bubble",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/Heart.png","Heart",APP->GetRenderer());
//TextureManager::Instance()->Load("Img/idea.png","idea",APP->GetRenderer());

    TextureManager::Instance()->Load("Img/bubblemaker.png","bubblemaker",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/ball.png","ball",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/boxPlayer.png","boxPlayer",APP->GetRenderer());
    return true;

};

bool State_BlankScreen::onExit() {};
void State_BlankScreen::resume() {};
void State_BlankScreen::HandleEvent(SDL_Event &e ) {};
/**<




if(m_msg=="GUIButton")
             _guif::Instance()->registerType(m_msg,new GUI_MenuCreater());
    if(m_msg=="GUIFrame")
            _guif::Instance()->registerType(m_msg,new GUI_FrameCreater());
    if(m_msg=="GUIMenu")
            _guif::Instance()->registerType(m_msg,new GUI_MenuCreater());
    if(m_msg=="GUIPannel")
            _guif::Instance()->registerType(m_msg,new GUI_PannelCreater());
    if(m_msg=="GUILabel")
            _guif::Instance()->registerType(m_msg,new GUI_LabelCreater());




    GameObjectFactory::Instance()->registerType("TextObject",new TextObjectCreater());
    m_Text = GameObjectFactory::Instance()->Create("TextObject");


    m_Text->GetPosition() = vec2f(0,64);



    TempstrStream << "logger :: " << Application::Instance()->GetLogger().getLogs()[0];
    dynamic_cast<TextObject*>(m_Text)->AddSentence(TempstrStream.str());



    App->GetLogger().log("sdddddd ");

    App->GetLogger().ToString();







    frame->Add(new GUI_Pannel("Pannel_2", {o.x, 0, o.x, o.y}));
    frame->Add(new GUI_Pannel("Pannel_3", {o.x, o.y, o.x, o.y}));
    frame->Add(new GUI_Pannel("Pannel_4", {0, o.y, o.x, o.y}));
 */
