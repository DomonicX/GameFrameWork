#include "EnemyLayer.h"

EnemyLayer::EnemyLayer()
{
//    for(int i = 0; i< 120; i++)
//    {
//
//        for(int j = 0; j< 67 ; j++)
//        {
//            m_gameObjects.push_back(gameobjectFactory->Create("GameObjectProxy"));
//            m_gameObjects.back()->Load("GameObjectProxy.txt");
//            m_gameObjects.back()->GetPosition().x = i*16;
//            m_gameObjects.back()->GetPosition().y = j*16;
//        }
//    }
//for(int i = 0; i< 40; i++)
//    {
//
//        for(int j = 0; j< 67 ; j++)
//        {
//            int a = GetRandomNumber() %640;
//
//            int b = GetRandomNumber()%360;
//
//            m_gameObjects.push_back(gameobjectFactory->Create("GameObjectProxy"));
//            m_gameObjects.back()->Load("GameObjectProxy.txt");
//            m_gameObjects.back()->GetPosition().x = 0;
//            m_gameObjects.back()->GetPosition().y = 360/2;
//        }
//    }
}
EnemyLayer::EnemyLayer(float speed ) : m_speed(speed)
{
}

EnemyLayer::~EnemyLayer()
{
    //dtor
}  void EnemyLayer::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
    {
        m_gameObjects[i]->Render(Ren,OffsetX*m_speed,OffsetY*m_speed);
//TextureManager::Instance()->DrawRect(Ren,SDL_FRect({ m_gameObjects[i]->GetPosition().x+OffsetX*m_speed,m_gameObjects[i]->GetPosition().y+OffsetY*m_speed,16,16}),SDL_Color({255*(float)m_speed,255*m_speed,255*m_speed}),true);
    }

//   TextureManager::Instance()->drawSprite("box",delta,0,16,16,r,SDL_FLIP_NONE);
//   TextureManager::Instance()->DrawRect(r,SDL_Rect{0,0,48,48},Colour_black,true);
//    TextureManager::Instance()->DrawTileBox(r,"box",16,SDL_Rect{0,0,16,16},SDL_Rect{0,0,48,48});
//        TextureManager::Instance()->DrawGrid(0,0,120,67.5,16,Colour_green,r);
};
void  EnemyLayer::HandleEvent(SDL_Event &e )
{
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
    {
        m_gameObjects[i]->HandleEvent(e);

    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {

        if(m_gameObjects.empty())
        {

        }
        else
        {
            std::stringstream aa ;
        aa.clear();
            for(int i = 0 ; i < m_gameObjects.size(); i++)
            {
                std::cout << m_gameObjects[i]->GetPosition().x << " " << m_gameObjects[i]->GetPosition().y << " "<< m_gameObjects[i]->Type() <<"\n";
                aa << m_gameObjects[i]->GetPosition().x << " " << m_gameObjects[i]->GetPosition().y << " "<< m_gameObjects[i]->Type() <<"\n";
            }
            DirectoryHandler::Instance()->Load("tt.txt");
            LFile & s = *DirectoryHandler::Instance()->GetFileMap()["tt.txt"];
            DirectoryHandler::Instance()->ChangeData("tt.txt",aa.str().c_str());
            DirectoryHandler::Instance()->Save("tt.txt");

        }

    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LCTRL))
    {
        for(int i = 0 ; i < (int)m_gameObjects.size(); i++)
        {
            delete m_gameObjects[i];
            m_gameObjects.erase(m_gameObjects.begin() + i);
        }
        m_gameObjects.clear();
        DirectoryHandler::Instance()->Load("tt.txt");
        LFile & sa = *DirectoryHandler::Instance()->GetFileMap()["tt.txt"];
        std::istringstream  aaa(sa.GetFileData()) ;

            int x = 0;
            int y = 0;
            std::string type;

        while(!aaa.eof())
        {

            aaa >> x;
            aaa >> y;
            getline(aaa,type);
//       std::getline(aaa,type);

//std::cout <<"\n"<< x << "  " << y << " " << type <<"\n ";
if(aaa.eof())
{
    break;
}
            std::cout <<"\n"<< x << "  " << y << " " << type <<"\n ";
            m_gameObjects.push_back(GameObjectFactory::Instance()->Create("GameObjectProxy"));

            m_gameObjects.back()->Load("GameObjectProxy.txt");
            m_gameObjects.back()->GetPosition().x = x;
            m_gameObjects.back()->GetPosition().y = y;

        }
    }
}
void EnemyLayer::Update(float DeltaTime)
{ std::cout <<CollisionManager::Instance()->GetObjectSize() << " GetObjectSize \n";

    for(int i = 0 ; i < m_gameObjects.size(); i++ )
    if(m_gameObjects[i]->Dead())
    {

      if(CollisionManager::Instance()->Remove(m_gameObjects[i]))
      {
          std::cout << m_gameObjects[i] << "\n";
      }
        // delete m_gameObjects[i];
        m_gameObjects.erase(m_gameObjects.begin()+i);
    }
    for(int i = 0 ; i < m_gameObjects.size(); i++ )
    {  std::cout << m_gameObjects[i] << "\n";

//        if(m_gameObjects[i]->GetPosition().x+m_gameObjects[i]->getWidth() < 0)
//        {
//            m_gameObjects[i]->GetPosition().x = 640+m_gameObjects[i]->getWidth();
//            m_gameObjects[i]->SetDead(false);
//        }
//        if(m_gameObjects[i]->GetPosition().Dist(MOUSEPOSITION) <= 64)
//        {
//            m_gameObjects[i]->SetDead(true);
//        }

        m_gameObjects[i]->Update(DeltaTime);
    }
}
