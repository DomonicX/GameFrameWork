#include "TestState30.h"

TestState30::TestState30()
{
    //ctor
}

TestState30::~TestState30()
{
    //dtor
}


void TestState30::Render()
{

    /**<
    //    float sclae = WindowOrigin.Length()*2;
    //
    //    vec2f aa = vec2f(WindowOrigin+-MOUSEPOSITION);
    //    vec2f aa = vec2f(WindowOrigin+-MOUSEPOSITION);
    //    aa.Rotate(0);
    //    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,aa,Colour_green);
    //    for(int i = 0; i < 180 ; i++)
    //    {
    //        aa.Rotate(M_PI/(float)180);
    //        TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,aa,Colour_green);
    //    }
        vec2f sPos = vec2f(WindowOrigin.x,0);
        vec2f bpos = MOUSEPOSITION;
        std::cout << 90-vec2f::vectorAngle(bpos,sPos) << "\n";
        vec2f n = sPos - bpos;
        n-=bpos;
        n.Rotate(-(M_PI/2));
        TextureManager::Instance()->Drawcircle(APP->GetRenderer(),bpos.x,bpos.y,Colour_blue,16,true);

        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ballbass,ballpos,Colour_yellow);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ballpos,ballbass+-Ke,Colour_red);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ballbass,ballbass+-Ne,Colour_red);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ballpos,ballpos+-Ne,Colour_red);
        ballInfo = ballangle;

    //
        vec2f sss = ballbass-ballpos;
    //sss.y += 16;
    //sss.Rotate(M_PI/8);
    //ballpos.Rotate(M_PI/8);
        TextureManager::Instance()->DrawVector(APP->GetRenderer(),ballbass,sss,Colour_yellow);
        TextureManager::Instance()->DrawRect(APP->GetRenderer(),SDL_Rect({WindowOrigin.x-8,0,16,2}),Colour_aqua,true);
        TextureManager::Instance()->Drawcircle(APP->GetRenderer(),ballpos.x,ballpos.y,Colour_blue,16,false);

        vec2f screenoffSet =  Application::Instance()->GetCamera().screenOffSet();
    // TextureManager::Instance()->DrawRect(APP->GetRenderer(),Application::Instance()->GetCamera().GetWorldPos(),Application::Instance()->GetCamera().GetWorldSize().x,Application::Instance()->GetCamera().GetWorldSize().y,Colour_gainsboro,false);
        TextureManager::Instance()->DrawRect(APP->GetRenderer(),Application::Instance()->GetCamera().GetPos(),Application::Instance()->GetCamera().GetSize().x,Application::Instance()->GetCamera().GetSize().y,Colour_antiquewhite,false);
    //    rocket->Render(APP->GetRenderer(),screenoffSet.x,screenoffSet.y);
    //    Application::Instance()->GetCamera().GetVirtualCentre()
        {

            std::stringstream aaa;
            aaa << "t = " << t << "";
            aaa << "f = " << f << "";
            aaa << " " << ballbass << "";
            aaa << " " << sss << "";
            aaa << " " << gametime << "";
            aaa << " " << screenoffSet << "";
            aaa << " " << Application::Instance()->GetCamera().GetPos() << "";
            aaa << " " << Application::Instance()->GetCamera().GetWorldPos() << "";
            aaa << " " << rocket->GetPosition() << "";
            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),aaa.str(),0,WindowOrigin.y);

        }
        for(int i = 0; i < 30; i++)
        {
            if(         InputHandler::Instance()->HasPointinRect(SDL_FPoint({m_gameobjects[i]->GetPosition().x-screenoffSet.x,m_gameobjects[i]->GetPosition().y-screenoffSet.y}),
                        Application::Instance()->GetCamera().GetRectF()))

                m_gameobjects[i]->Render(APP->GetRenderer(),screenoffSet.x,screenoffSet.y);

        }


        vec2f world,mouse, screen, camera,toWorld,toscreen, apple,apple2;

        apple = vec2f(150,0);
        world = vec2f(-MOUSEPOSITION.x,0);
        camera = vec2f(0,0);

        mouse = MOUSEPOSITION;

        sss += MOUSEPOSITION;
        TextureManager::Instance()->DrawLine(APP->GetRenderer(),sss.x-Application::Instance()->GetCamera().GetPos().x,sss.y-Application::Instance()->GetCamera().GetPos().y,sss.x,sss.y,Colour_aqua);

        TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin+-mouse,Colour_blanchedalmond);
     apple += ToWorld(world,camera);
         {
            std::stringstream aaa;
            aaa << "World " << apple << "";
            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),aaa.str(),apple.x,apple.y,Colour_white,Align_Center);
        }
         apple -= ToScreen(world,camera);
         {
            std::stringstream aaa;
            aaa << "Screen " << apple << "";
            TextureManager::Instance()->DrawText(APP->GetRenderer(),FontManager::Instance()->GetFont("OpenSans-Regular"),aaa.str(),apple.x,apple.y,Colour_white,Align_Center);
        }





        TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),vec2f(16,16)+MOUSEPOSITION,vec2f(0,32)+MOUSEPOSITION,vec2f(32,32)+MOUSEPOSITION,Colour_blue);
    //    TextureManager::Instance()->DrawTriangle(APP->GetRenderer(),vec2f(0,0),vec2f(MOUSEPOSITION),vec2f(WindowOrigin.x*2,0),Colour_blue);

    {

        TTF_Font* font = TTF_OpenFont("Fonts/Consolas-Font/CONSOLA.TTF", 16);
//SDL_Rect rcGround = {0, 0, 800, 600};
//            TTF_Font* font = TTF_OpenFont("Fonts/OpenSans/OpenSans-Regular.TTF", 3);
        SDL_Surface* textSurface = nullptr;
        SDL_Point textSize = { 0, 0 };
        TTF_SizeText(font, "example text to test that it drops to a new line.", &textSize.x, &textSize.y);
        textSurface = TTF_RenderText_Solid_Wrapped(font, "example text to test that it drops to a new line.", {255, 255, 255, 255},WindowOrigin.x);

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(APP->GetRenderer(), textSurface);

        SDL_FreeSurface(textSurface);

        TextureManager::Instance()->DrawText(APP->GetRenderer(),font,"example",MOUSEPOSITION.x,MOUSEPOSITION.y);

        TTF_CloseFont(font);


        textSize.x = textSurface->w;
        textSize.y = textSurface->h;
//    		TTF_SizeText(font, "Hello\nHello", &textSize.x, &textSize.y);
//	textSize.y*=2;
//std::cout << textSize.y << "\n";

        SDL_FRect textRect = { 0, 0, float(textSize.x), float(textSize.y) };
        SDL_Rect extRect = { 0, 0, textSize.x, textSize.y};


        SDL_RenderCopyF(APP->GetRenderer(), textTexture, NULL, &textRect);

        SDL_DestroyTexture(textTexture);

    }
    {

        TTF_Font* font = TTF_OpenFont("Fonts/Consolas-Font/CONSOLA.TTF", 16);
//SDL_Rect rcGround = {0, 0, 800, 600};
//            TTF_Font* font = TTF_OpenFont("Fonts/OpenSans/OpenSans-Regular.TTF", 3);
        SDL_Surface* textSurface = nullptr;
        SDL_Point textSize = { 0, 0 };
        TTF_SizeText(font, "example text to test that it drops to a new line.", &textSize.x, &textSize.y);
        textSurface = TTF_RenderText_Solid_Wrapped(font, "example text to test that it drops to a new line test that it drops to a new line.", {255, 255, 0, 255},WindowOrigin.x*2);

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(APP->GetRenderer(), textSurface);

        SDL_FreeSurface(textSurface);

        TextureManager::Instance()->DrawText(APP->GetRenderer(),font,"example",MOUSEPOSITION.x,MOUSEPOSITION.y);

        TTF_CloseFont(font);


        textSize.x = textSurface->w;
        textSize.y = textSurface->h;
//    		TTF_SizeText(font, "Hello\nHello", &textSize.x, &textSize.y);
//	textSize.y*=2;
//std::cout << textSize.y << "\n";

        SDL_FRect textRect = { 0, 200, float(textSize.x), float(textSize.y) };
        SDL_Rect extRect = { 0, 0, textSize.x, textSize.y};


        SDL_RenderCopyF(APP->GetRenderer(), textTexture, NULL, &textRect);

        SDL_DestroyTexture(textTexture);

    }
    {

        TTF_Font* font = TTF_OpenFont("Fonts/Consolas-Font/CONSOLAB.TTF", 18);
//SDL_Rect rcGround = {0, 0, 800, 600};
//            TTF_Font* font = TTF_OpenFont("Fonts/OpenSans/OpenSans-Regular.TTF", 3);
        SDL_Surface* textSurface = nullptr;
        SDL_Point textSize = { 0, 0 };
        TTF_SizeText(font, "example text to test that it drops to a new line.", &textSize.x, &textSize.y);
        textSurface = TTF_RenderText_Solid_Wrapped(font, "example text to test that it drops to a new line.", {255, 255, 125, 255},WindowOrigin.x*1.5);

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(APP->GetRenderer(), textSurface);

        SDL_FreeSurface(textSurface);

        TextureManager::Instance()->DrawText(APP->GetRenderer(),font,"example",MOUSEPOSITION.x,MOUSEPOSITION.y,Colour_cadetblue,Align_Center);

        TTF_CloseFont(font);

        textSize.x = textSurface->w;
        textSize.y = textSurface->h;
//    		TTF_SizeText(font, "Hello\nHello", &textSize.x, &textSize.y);
//	textSize.y*=2;
//std::cout << textSize.y << "\n";

        SDL_FRect textRect = { 0, 300, float(textSize.x), float(textSize.y) };
        SDL_Rect extRect = { 0, 0, textSize.x, textSize.y};


        SDL_RenderCopyF(APP->GetRenderer(), textTexture, NULL, &textRect);

        SDL_DestroyTexture(textTexture);

    }


    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),WindowOrigin.x,WindowOrigin.y,Colour_crimson,64,false);
    TextureManager::Instance()->Drawcircle(APP->GetRenderer(),pos.x,pos.y,Colour_crimson,8,true);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),WindowOrigin,WindowOrigin-pos,Colour_green);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,pos.GetOrtho(),Colour_green);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),pos,pos-vel,Colour_green);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0,0),vec2f(0,0)-pos,Colour_blue);
    TextureManager::Instance()->DrawVector(APP->GetRenderer(),vec2f(0,0),vec2f(0,0)-WindowOrigin,Colour_yellow);

//		TextureManager::Instance()->Draw
//		TextureManager::Instance()->Draw

    TextureManager::Instance()->SetBlendMode("dotAphla1",SDL_BlendMode::SDL_BLENDMODE_ADD);
    SDL_FRect pipeDesRect {0,0,   64,64};

//    SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["Pipe"]->GetSDLTexture(),NULL,&pipeDesRect);
    SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["dotAphla1"]->GetSDLTexture(),NULL,&pipeDesRect);

    TextureManager::Instance()->SetBlendMode("dotAphla1",SDL_BlendMode::SDL_BLENDMODE_BLEND);

 */
//frameCounter += (90/APP->GetFps());

//        TextureManager::Instance()->DrawRect(APP->GetRenderer(),SDL_Rect({MOUSEPOSITION.x,MOUSEPOSITION.y,25,55}),Colour_white,true);


SDL_Colour ss = SDL_Colour{255,255,255};
       TextureManager::Instance()->SetColorMod("d",ss);     SDL_FRect bk {0,0,   490,351};
 SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["d"]->GetSDLTexture(),NULL,&bk);

// Application::Instance()->GetCamera().SetPos()
SDL_FRect background {0,0,   300,300};
SDL_FRect blur {MOUSEPOSITION.x,MOUSEPOSITION.y,   64,64};


SDL_FRect a ={ MOUSEPOSITION.x, MOUSEPOSITION.y,  240,246};
SDL_FRect b ={ MOUSEPOSITION.x, MOUSEPOSITION.y,   74,64};
SDL_FRect c ={ 0,0, 490,351};
SDL_FRect a2 ={ MOUSEPOSITION.x, MOUSEPOSITION.y,  490,351};
SDL_FRect b1 ={ MOUSEPOSITION.x, MOUSEPOSITION.y,   490,351};
SDL_Rect c2 ={0,0,240,246};
//    TextureManager::Instance()->SetBlendMode("c",SDL_BlendMode::SDL_BLENDMODE_ADD);
//       TextureManager::Instance()->SetColorMod("c",Colour_green);
//       TextureManager::Instance()->SetColorMod("da",Colour_green);
LTexture LightRect = LTexture();
LightRect.LoadFromRendered(APP->GetRenderer(),25,55,Colour_white,SDL_BLENDMODE_BLEND,125);
//LightRect.SetAlpha(125);
LightRect.Render(APP->GetRenderer(),MOUSEPOSITION.x,MOUSEPOSITION.y,0,NULL);


    TextureManager::Instance()->SetBlendMode("b",SDL_BlendMode::SDL_BLENDMODE_ADD);
    TextureManager::Instance()->SetBlendMode("c",SDL_BlendMode::SDL_BLENDMODE_MOD);
    TextureManager::Instance()->SetBlendMode("a",SDL_BlendMode::SDL_BLENDMODE_MUL);

//    TextureManager::Instance()->SetBlendMode("da",SDL_BlendMode::SDL_BLENDMODE_MUL);
 SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["b"]->GetSDLTexture(),NULL,&b1);
 SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["c"]->GetSDLTexture(),NULL,&b1);
 SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["a"]->GetSDLTexture(),NULL,&a2);



    TextureManager::Instance()->SetBlendMode("b",SDL_BlendMode::SDL_BLENDMODE_ADD);
    TextureManager::Instance()->SetBlendMode("c",SDL_BlendMode::SDL_BLENDMODE_MOD);
    TextureManager::Instance()->SetBlendMode("a",SDL_BlendMode::SDL_BLENDMODE_MUL);

// SDL_RenderCopyF(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["da"]->GetSDLTexture(),NULL,&c);
//
//        SDL_FRect    dsrcf2 =    {0,0,64,64};
//        TextureManager::Instance()->SetAhpla("tile",35);
//for(int i = 0; i < WindowOrigin.y*2 ; i+=64)
//TextureManager::Instance()->DrawTileHorizontal(APP->GetRenderer(),"tile",64,WindowOrigin.x*2,0,i,&dsrcf2,0,NULL,SDL_FLIP_NONE);
TextureManager::Instance()->DrawRect(Application::Instance()->GetRenderer(),SDL_FRect({WindowOrigin.x/4,WindowOrigin.y/4,WindowOrigin.x/2,WindowOrigin.y/2}),Colour_chocolate,true);
// SDL_SetRenderTarget(APP->GetRenderer(),  TextureManager::Instance()->getTextureMap()["c"]->GetSDLTexture());
// SDL_SetRenderTarget(APP->GetRenderer(),NULL);
        TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
                                                    fontManager->GetFont("OpenSans-Regular24"),
                                                    "example text to test that it drops to a new line.",
                                                    MOUSEPOSITION,
                                                    300,
                                                    Colour_white,Align_Left,
                                                    frameCounter,
                                                    SDL_FPoint({150,32}),
                                                    SDL_FLIP_NONE);



SDL_FRect aa = { MOUSEPOSITION.x,0,ltext.GetBounds().w,ltext.GetBounds().h};
ltext.SetTextColour(Colour_white);
              ltext.ChangeText(textinString,fontManager->GetFont("OpenSans-Regular"),APP->GetRenderer());
    ltext.LoadFromRenderedText(APP->GetRenderer(),aa.x,aa.y);
//    if(MOUSEPOSITION.x+ltext.GetBounds().w >= WindowOrigin.x*2)
//    ltext.LoadFromRenderedText(APP->GetRenderer(),WindowOrigin.x*2-ltext.GetBounds().w,0);else


TextureManager::Instance()->DrawRect(APP->GetRenderer(),alignToTilePosition(MOUSEPOSITION.x,MOUSEPOSITION.y,16),Colour_black,true);

    TextureManager::Instance()->SetBlendMode("circle_alpha",SDL_BlendMode::SDL_BLENDMODE_ADD);
textureManager->drawTestTexture(APP->GetRenderer(),"circle_alpha");
    TextureManager::Instance()->SetBlendMode("circle_alpha",SDL_BlendMode::SDL_BLENDMODE_BLEND);
}
void TestState30::Update(float dt)
{
    acc = pos-WindowOrigin;
    acc.Ortho();
    acc.Normalise();
    pos += vel += acc * dt;
    minVel = 64;

//    vec2f::Clamp(WindowOrigin.Length()-64,WindowOrigin.Length()-64,pos);

    for(int i = 0; i <30; i++)
    {
        m_gameobjects[i]->Update(dt);
    }
    rocket->Update(dt);
//    std::cout << dt <<" \n";
    gametime += dt;
    if(gametime>=t)
        gametime = 0;

};
bool TestState30::OnEnter()
{
//    Application::Instance()->GetWindow()->SetFullScreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
       ltext.SetTextColour(Colour_beige);
      ltext.SetWrapped(94);
    pos = vec2f(WindowOrigin.x-(64*std::sin(45)),WindowOrigin.y-(64*std::cos(45)));
//   pos = vec2f(0,0);
    TextureManager::Instance()->Load("Img/blur.png","blur",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/background.png","background",APP->GetRenderer());

    TextureManager::Instance()->Load("Img/Pipe.png","Pipe",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/PipeAlpha.png","PipeAlpha",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/dotAphla1.png","dotAphla1",APP->GetRenderer());

    TextureManager::Instance()->Load("Img/a.png","a",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/b.png","b",APP->GetRenderer());
//    TextureManager::Instance()->Load("Img/d.png","d",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/d2.png","d",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/da.png","da",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/tile.png","tile",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/da2.png","da2",APP->GetRenderer());
    TextureManager::Instance()->Load("Img/c.png","c",APP->GetRenderer());
 TextureManager::Instance()->Load("Img/f.png","f",APP->GetRenderer());
 TextureManager::Instance()->Load("Img/circle_alpha.png","circle_alpha",APP->GetRenderer());

    rocket = GameObjectFactory::Instance()->Create("GameOBject_RocketShip");
    rocket->GetPosition().x = 32;
    rocket->GetPosition().y = 32;

//InputHandler::Instance()->StartTextInput();

    for(int i = 0; i < 30; i++)
    {
        m_gameobjects.push_back(GameObjectFactory::Instance()->Create("GameOBject_RocketShip"));
        m_gameobjects[i]->GetPosition().x= 32*i;
        m_gameobjects[i]->GetPosition().y= 32;
        dynamic_cast<SDLGameObject*>(m_gameobjects[i])->GetColour().r =  125-i*4;
        dynamic_cast<SDLGameObject*>(m_gameobjects[i])->GetColour().g =  255-i*4;
        dynamic_cast<SDLGameObject*>(m_gameobjects[i])->GetColour().b =  0+i*4;

    }
//    m_gameobjects[0]->GetPosition().y= 64;
//    m_gameobjects[m_gameobjects.size()-1]->GetPosition().y= 64;
//dynamic_cast<SDLGameObject*>(m_gameobjects[0])->GetColour().r =  0;
//dynamic_cast<SDLGameObject*>(m_gameobjects[m_gameobjects.size()-1])->GetColour().r =  255;


InputHandler::Instance()->ShowMouse(false);

    ballbass = vec2f(WindowOrigin.x,0); //ball_bass
    Ke = vec2f(0,0); // ke-enegry
    Ne = vec2f(0,0); // n-enegry
    isballReleased = false; // isballreleased
    ballangle = M_PI/4; // angle
    ballRopeLength = WindowOrigin.y;  //meters
    ballInfo;
    ballpos = ballbass; //ball_pos
    ballpos.y+=ballRopeLength;
    Ne = ballbass + vec2f(0,ballpos.y);

    t = 2*M_PI*std::sqrt((2/(float)9.807));
    f = 1/t;


};
bool TestState30::onExit() {};
void TestState30::resume() {};

void TestState30::HandleEvent(SDL_Event &e)
{

        if(e.type==SDL_USEREVENT)
        if(e.user.code==3)
            std::cout << "KeyBoardPressed 3\n";
        if(e.type==SDL_USEREVENT)
        if(e.user.code==4)
            std::cout << "KeyBoardPressed 4\n";

  textinString =    InputHandler::Instance()->GetTextInput();
    if(isballReleased==false);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        isballReleased = true;

    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_3))
    {
        InputHandler::Instance()->pushEvent(3,"KeyBoardPressed","3");

        }    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_4))
    {
        InputHandler::Instance()->pushEvent(4,"KeyBoardPressed","4");

        }
};
