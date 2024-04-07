#include "TestState35.h"

TestState35::TestState35()
{
    //ctor
}

TestState35::~TestState35()
{
    //dtor
}

void TestState35::Render()
{
    LTexture l = LTexture();
    l.LoadFromRendered(APP->GetRenderer(),640,360,Colour_black,SDL_BLENDMODE_BLEND,128);
    SDL_Point ss = SDL_Point({0,0});
    l.Render(APP->GetRenderer(),0,0,0,&ss);

    TextureManager::Instance()->DrawRect(APP->GetRenderer(),m,Colour_darkseagreen,true);
    if(m_points.size()>=2)
        for(int i = 0 ; i < m_points.size()-1; i++)
        {
            TextureManager::Instance()->DrawLine(APP->GetRenderer(),m_points[i].x,m_points[i].y,m_points[i+1].x,m_points[i+1].y,Colour_darkseagreen);
            TextureManager::Instance()->DrawRect(APP->GetRenderer(),m_points[i],m_points[i+1].x-m_points[i].x,200,Colour_blueviolet,true);

vec2f nf = vec2f::GetMidPoint(vec2f(m_points[i].x,m_points[i].y),vec2f(m_points[i+1].x,m_points[i+1].y));

            TextureManager::Instance()->DrawVector(APP->GetRenderer(),nf,nf.GetRotation(90),Colour_darkseagreen);
        }
         TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x,WindowOrigin.y,Colour_red,16,true);
          TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,vec2f(16,16),Colour_darkseagreen);

};
void TestState35::Update(float dt)
{
//    m = {MOUSEPOSITION.x,MOUSEPOSITION.y,16,16};
    m = alignToTilePosition((int)MOUSEPOSITION.x,(int)MOUSEPOSITION.y,16);


    for(int i = 0 ; i < m_points.size(); i++)
    {

    }
}

bool TestState35::OnEnter()
{

    std::ifstream ifs;
    ifs.open ("tt.txt", std::ifstream::in);
    while(!ifs.eof())
    {

        float x,y = 0;
        ifs >> x;
        ifs >> y;
        vec2f a = vec2f(x,y);
        m_points.push_back(a);

    }        m_points.pop_back();

    ifs.close();

    return true;

};
bool TestState35::onExit() {};
void TestState35::resume() {};
void TestState35::HandleEvent(SDL_Event &e )
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_F2))

        Application::Instance()->GetStateMachine()->PopState();
//            Application::Instance()->GetStateMachine()->ChangeState(stateFactory->Create("TestState34"));

    if(!m_d)
        if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))

        {
            m_d = true;
            m_points.push_back(
                vec2f(
                    alignToVec2Position(MOUSEPOSITION,16)));


        }
    if(!InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        std::stringstream aa ;

        for(int i = 0 ; i < m_points.size(); i++)
        {
            aa << m_points[i].x << " " << m_points[i].y << "\n";
        }
        m_d = false;
        DirectoryHandler::Instance()->Load("tt.txt");
        LFile & s = *DirectoryHandler::Instance()->GetFileMap()["tt.txt"];
        DirectoryHandler::Instance()->ChangeData("tt.txt",aa.str().c_str());
        DirectoryHandler::Instance()->Save("tt.txt");
    }

    if(!m_ud)
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_1))
        {
            m_points.pop_back();
            m_ud = true;
        }
    if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_1))
        m_ud = false;

}
