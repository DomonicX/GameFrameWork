#include "TextureManager.h"
#define scaleOffSet 1
TextureManager *TextureManager::s_pInstance = 0;

bool TextureManager::Load(std::string fileName, std::string id,SDL_Renderer* p_ren)
{
    if(!m_TextureMap.empty())
    {
        if(m_TextureMap.find(id)==m_TextureMap.end())
        {
            //
            LTexture * temp = new LTexture();
            if(temp->LoadFromFile(p_ren,fileName))
            {
                m_TextureMap[id] = temp;
                return true;
            }
            else
            {

                delete temp;
            }
        }
        std::cout << "Image is already Loaded : " << fileName << "\n";
        return false;
    }

    LTexture * temp = new LTexture();
    if(temp->LoadFromFile(p_ren,fileName))
    {
        m_TextureMap[id] = temp;
        return true;
    }
    delete temp;
    return false;

}

bool TextureManager::Load(SDL_Renderer* p_ren, std::string id,std::string fileName,std::string  SaveFile,SDL_Color KeyColour)
{
    if(!m_TextureMap.empty())
    {
        if(m_TextureMap.find(id)==m_TextureMap.end())
        {
            //
            LTexture * temp = new LTexture();
            if(temp->LoadFromFileandSave(p_ren,KeyColour,fileName,SaveFile))
            {
                m_TextureMap[id] = temp;
                return true;
            }
            else
            {

                delete temp;
            }
        }
        std::cout << "Image is already Loaded : " << fileName << "\n";
        return false;
    }

    LTexture * temp = new LTexture();
    if(temp->LoadFromFileandSave(p_ren,KeyColour,fileName,SaveFile))
    {
        m_TextureMap[id] = temp;
        return true;
    }
    delete temp;
    return false;
}
bool TextureManager::Load(std::string fileName, std::string id,SDL_Color KeyColour,SDL_Renderer* p_ren)
{
    if(!m_TextureMap.empty())
    {
        if(m_TextureMap.find(id)==m_TextureMap.end())
        {
            //
            LTexture * temp = new LTexture();
            if(temp->LoadFromFile(p_ren,KeyColour,fileName))
            {
                m_TextureMap[id] = temp;
                return true;
            }
            else
            {

                delete temp;
            }
        }
        std::cout << "Image is already Loaded : " << fileName << "\n";

        return false;
    }

    LTexture * temp = new LTexture();
    if(temp->LoadFromFile(p_ren,KeyColour,fileName))
    {
        m_TextureMap[id] = temp;
        return true;
    }
    delete temp;
    return false;

}
int  TextureManager::GetAhpla(std::string id, Uint8 *alpha)
{
    return  m_TextureMap[id]->GetAlpha();
}

void TextureManager::SetAhpla(std::string id,int alpha )
{
    m_TextureMap[id]->SetAlpha(alpha);
}
void TextureManager::SetColorMod(std::string id,SDL_Color c )
{
    m_TextureMap[id]->SetColorMod(c.r,c.g,c.b);
}

void TextureManager::QueryTexture(std::string id)
{
    m_TextureMap[id]->QueyTexture();
}
void TextureManager::SetColour(char r,char g, char b, char a,SDL_Renderer*   renderer)
{
    SDL_Color C = {r,g,b,a};
    if(SDL_SetRenderDrawColor(renderer, C.r,C.g, C.b, C.a))
        std::cout << "ERROR SDL_SetRenderDrawColor"<< SDL_GetError();
}

SDL_Colour TextureManager::GetDrawColor(SDL_Renderer* ren)
{
    SDL_Color a;
    SDL_GetRenderDrawColor(ren,&a.r,&a.g,&a.b,&a.a);
    return a;
}
void TextureManager::SetColour(SDL_Color c,SDL_Renderer*   renderer)
{
    SDL_Color C = {0,0,0,0};
    C=c;
    if(SDL_SetRenderDrawColor(renderer,C.r,C.g, C.b, C.a))
        std::cout << "ERROR SDL_SetRenderDrawColor"<< SDL_GetError();

}
void TextureManager::SetColour(SDL_Renderer*   renderer,SDL_Color c)
{
    SDL_Color C = {0,0,0,0};
    C=c;
    if(SDL_SetRenderDrawColor(renderer,C.r,C.g, C.b, C.a))
        std::cout << "ERROR SDL_SetRenderDrawColor"<< SDL_GetError();

}
void TextureManager::SetBlendMode(const std::string id,SDL_BlendMode blending)
{
    std::string l_id = id;
    SDL_BlendMode l_blend =  blending;
    m_TextureMap[l_id]->SetBlendMode(l_blend);
}

SDL_Color TextureManager::GetColorMod(std::string id)
{
    std::string l_id = id;
    return m_TextureMap[l_id]->GetColorMod();

}

void TextureManager::SetColourKey(const std::string id, float x,float y,SDL_Renderer *render)
{

}
std::map<std::string,LTexture *> TextureManager::getTextureMap()
{
    return m_TextureMap;
}
void TextureManager::Clean()
{
    while(!m_TextureMap.empty())
    {


        auto itt = m_TextureMap.begin();

        LTexture* s = itt->second;
        delete s;

        m_TextureMap.erase( itt);
    }
    m_TextureMap.clear();
}
void TextureManager::ClearTextureMap()
{


}
bool TextureManager::ClearFromTextureMap(std::string id)
{
    if(m_TextureMap.find(id)==m_TextureMap.end())
    {
        return false;
    }
    //SDL_DestroyTexture(m_TextureMap[id]);
    delete m_TextureMap[id];
    m_TextureMap.erase(id);
    return true;
}

void  TextureManager::DrawSqaure(SDL_Renderer *renderer,float CentreX,float CentreY,int length,SDL_Color c,bool Filled,float angle)
{
    SDL_Rect temp = SDL_Rect{CentreX-length/2.f,CentreY-length/2.f, length,length};

    SetColour(c,renderer);
    if(angle == 0 | 90 | 180 | 270)
    {

        Filled  ? SDL_RenderFillRect(renderer,&temp):
        SDL_RenderDrawRect(renderer,&temp)  ;

    }
    else
    {
// DrawTriangle
    }
}
void  TextureManager::DrawRectangle(SDL_Renderer *renderer,float CentreX,float CentreY,int Width, int Height,SDL_Color c,bool Filled,float angle)
{
    SDL_FRect temp = SDL_FRect{CentreX-Width/2.f,CentreY-Height/2.f, Width,Height};

    SetColour(c,renderer);
    if(angle == 0 | 90 | 180 | 270)
        Filled  ? SDL_RenderFillRectF(renderer,&temp):
        SDL_RenderDrawRectF(renderer,&temp)  ;

}
void TextureManager::DrawRect(SDL_Renderer *ren,vec2f r,float w,float h,SDL_Color c,bool isFilled)
{
    SDL_Color C = {0,0,0,0};
    C=c;
    SDL_FRect temp = SDL_FRect{r.x,r.y, w,h};
    SetColour(C,ren);
    isFilled  ? SDL_RenderFillRectF(ren,&temp):
    SDL_RenderDrawRectF(ren,&temp)  ;

}

void TextureManager::DrawRect(SDL_Renderer *ren,SDL_FRect r,SDL_Color c,bool isFilled)
{
    SDL_Color C = {0,0,0,0};
    C=c;
    DrawRect(ren,vec2f(r.x,r.y),r.w,r.h,C,isFilled);
}
void TextureManager::DrawRect(SDL_Renderer *ren,SDL_Rect r,SDL_Color c,bool isFilled)
{
    SDL_Color C = {0,0,0,0};
    C=c;
    DrawRect(ren,vec2f(r.x,r.y),r.w,r.h,C,isFilled);
}

void TextureManager::DrawRects(SDL_Renderer *ren,SDL_Rect *rects,int RectCount,SDL_Color c, bool isFilled)
{
    SDL_Color C = {0,0,0,0};
    C=c;

    SetColour(C,ren);
    if(!isFilled)
        SDL_RenderDrawRects(ren,&rects[0],RectCount);
    else
        SDL_RenderFillRects(ren,&rects[0],RectCount);
}

void TextureManager::DrawRects(SDL_Renderer *ren,SDL_FRect *rects,int RectCount,SDL_Color c, bool isFilled)
{
    SDL_Color C = {0,0,0,0};
    C=c;

    SetColour(C,ren);
    if(!isFilled)
        SDL_RenderDrawRectsF(ren,&rects[0],RectCount);
    else
        SDL_RenderFillRectsF(ren,&rects[0],RectCount);
}
void TextureManager::DrawVector(SDL_Renderer* render,vec2f o,vec2f v,SDL_Color c,float thickness, float rotation)
{
    SetColour(c,render);

    vec2f a =vec2f(o);
    vec2f b =vec2f(o+v);

    //DrawSqaure(render,o.x,o.y,6,Colour_black,true);
   // Drawcircle(render,b.x,b.y,c,4,true);
    SDL_RenderDrawLineF(render,a.x,a.y,b.x,b.y);

}
    void  TextureManager::DrawVector(SDL_Renderer* render,vec2f* v,int Count,SDL_Color c)
    {
    SetColour(render,c);
        SDL_FPoint p[Count];
        for(int i = 0; i < Count; i++)
        {
            p[i] = {v[i].x,v[i].y};
        }
    SDL_RenderDrawLinesF(render,&p[0],Count);
    }
void  TextureManager::DrawVector(SDL_Renderer* render,vec2f v,vec2f o,vec2f s,SDL_Color c,float thickness, float rotation)
{
    vec2f aa = s;
    aa.x*=v.x;
    aa.y*=v.y;
    vec2f bb = s;
    bb.x*=o.x;
    bb.y*=o.y;
    std::cout << aa << bb << "\n";
    SDL_RenderDrawLineF(render,s.x*0.5+aa.x,s.y*0.5+aa.y,s.x*0.5+bb.x,s.y*0.5+bb.y);
}


 void TextureManager::DrawPoint(SDL_Renderer *r,SDL_Point p,SDL_Color c)
    {
    SetColour(r,c);
    SDL_RenderDrawPoint(r,p.x,p.y);

    }

 void TextureManager::DrawPoint(SDL_Renderer *r,SDL_FPoint p,SDL_Color c)
    {
    SetColour(r,c);
    SDL_RenderDrawPointF(r,p.x,p.y);

    }
void TextureManager::DrawPoint(SDL_Renderer *r,float x, float y,SDL_Color c)
{
    SetColour(r,c);
    SDL_RenderDrawPointF(r,x,y);
}
    void TextureManager::DrawPoint(SDL_Renderer *r,vec2f v,SDL_Color c)
    {

    SetColour(r,c);
    SDL_RenderDrawPointF(r,v.x,v.y);
    }
 void   TextureManager::drawSprite(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
   if(!m_TextureMap.empty())
    {
        if(m_TextureMap.find(id)==m_TextureMap.end())
        {
printf("cant find\n");
         return;

        }
         }
        SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;   // THIS WAS THE ERROR (You had destRect.x = y;)
    destRect.y = y;

    SDL_RenderCopyEx(renderer, m_TextureMap[id]->GetSDLTexture(), &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::DrawRectWithBoarder(SDL_FRect r,SDL_Color BackGround_c,SDL_Color OutLine_c,float thickness,SDL_Renderer *render)
{

    SetColour(OutLine_c,render);

    SDL_RenderDrawRectF(render,&r);
    thickness*=2;
    SDL_FRect tempRect = {r.x + thickness/2,r.y + thickness/2,r.w - thickness,r.h - thickness};
    SetColour(BackGround_c,render);
    SDL_RenderDrawRectF(render,&tempRect);
}
void  TextureManager::DrawRectWithBoarder(SDL_Rect r,SDL_Color BackGround_c,SDL_Color OutLine_c,float thickness,SDL_Renderer *render)
{
    SDL_FRect tempRect  = {r.x,r.y,r.w,r.h};
    DrawRectWithBoarder(tempRect,BackGround_c,OutLine_c,thickness,render);

}
void TextureManager::DrawTileHorizontal(SDL_Renderer * r,std::string id, int tileSize, int desSize,float x, float y,SDL_FRect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip)
{
    for(int i = 0 ; i < desSize ; i+=tileSize)
        Draw(r,id,x+i,y,clip,angle,center,flip);
}
void TextureManager::DrawTileVertical(SDL_Renderer * r,std::string id, int tileSize, int desSize,float x, float y,SDL_FRect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip)
{

    for(int i = 0 ; i < desSize ; i+=tileSize)
        Draw(r,id,x,y+i,clip,0,center,flip);
}
void TextureManager::DrawTileBox(SDL_Renderer * r,std::string id,int tileSize,SDL_Rect srcRect,SDL_Rect desRect)
{
    SDL_Rect BottomLeft,Bottom,BottomRight,Left,middle,Right,rectTopLeft,Top,TopRight;

    rectTopLeft = {srcRect.x,srcRect.y,tileSize,tileSize};
    Top = {srcRect.x+tileSize,srcRect.y,tileSize,tileSize};
    TopRight = {srcRect.x+tileSize+tileSize,srcRect.y,tileSize,tileSize};
    Left = {srcRect.x,srcRect.y+tileSize,tileSize,tileSize};
    middle = {srcRect.x+tileSize,srcRect.y+tileSize,tileSize,tileSize};
    Right = {srcRect.x+tileSize+tileSize,srcRect.y+tileSize,tileSize,tileSize};
    BottomLeft = {srcRect.x,srcRect.y+tileSize+tileSize,tileSize,tileSize};
    Bottom = {srcRect.x+tileSize,srcRect.y+tileSize+tileSize,tileSize,tileSize};
    BottomRight = {srcRect.x+tileSize+tileSize,srcRect.y+tileSize+tileSize,tileSize,tileSize};


    for(int i = tileSize ; i < desRect.h-tileSize ; i+=tileSize)
    {
        Draw(r,id,desRect.x,desRect.y+i,&Left,0,NULL,SDL_FLIP_NONE);
        Draw(r,id,desRect.x+desRect.w-tileSize,desRect.y+i,&Right,0,NULL,SDL_FLIP_NONE);
    }
    for(int i = tileSize ; i < desRect.w-tileSize ; i+=tileSize)
    {
        Draw(r,id,desRect.x+i,desRect.y,&Top,0,NULL,SDL_FLIP_NONE);
        Draw(r,id,desRect.x+i,desRect.y+desRect.h-tileSize,&Bottom,0,NULL,SDL_FLIP_NONE);
    }
    Draw(r,id,desRect.x,desRect.y,&rectTopLeft,0,NULL,SDL_FLIP_NONE);
    Draw(r,id,desRect.x+desRect.w-tileSize,desRect.y,&TopRight,0,NULL,SDL_FLIP_NONE);
    Draw(r,id,desRect.x,desRect.y+desRect.h-tileSize,&BottomLeft,0,NULL,SDL_FLIP_NONE);
    Draw(r,id,desRect.x+desRect.w-tileSize,desRect.y+desRect.h-tileSize,&BottomRight,0,NULL,SDL_FLIP_NONE);

//    SDL_RenderCopyEx(r,m_TextureMap[id]->GetSDLTexture(),&srcRect,&desRect,0,NULL,SDL_FLIP_NONE);

}
void TextureManager::DrawTileBoxAroundRect(SDL_Renderer * r,std::string id,int tileSize,SDL_Rect desRect,SDL_Rect srcRect)
{
    SDL_Rect BottomLeft,Bottom,BottomRight,Left,middle,Right,rectTopLeft,Top,TopRight;
    desRect  = {desRect.x-tileSize,desRect.y-tileSize,desRect.w+tileSize*2,desRect.h+tileSize*2};
    rectTopLeft = {srcRect.x,srcRect.y,tileSize,tileSize};
    Top = {srcRect.x+tileSize,srcRect.y,tileSize,tileSize};
    TopRight = {srcRect.x+tileSize+tileSize,srcRect.y,tileSize,tileSize};
    Left = {srcRect.x,srcRect.y+tileSize,tileSize,tileSize};
    middle = {srcRect.x+tileSize,srcRect.y+tileSize,tileSize,tileSize};
    Right = {srcRect.x+tileSize+tileSize,srcRect.y+tileSize,tileSize,tileSize};
    BottomLeft = {srcRect.x,srcRect.y+tileSize+tileSize,tileSize,tileSize};
    Bottom = {srcRect.x+tileSize,srcRect.y+tileSize+tileSize,tileSize,tileSize};
    BottomRight = {srcRect.x+tileSize+tileSize,srcRect.y+tileSize+tileSize,tileSize,tileSize};


    for(int i = tileSize ; i < desRect.h-tileSize ; i+=tileSize)
    {
        Draw(r,id,desRect.x,desRect.y+i,&Left,0,NULL,SDL_FLIP_NONE);
        Draw(r,id,desRect.x+desRect.w-tileSize,desRect.y+i,&Right,0,NULL,SDL_FLIP_NONE);
    }
    for(int i = tileSize ; i < desRect.w-tileSize ; i+=tileSize)
    {
        Draw(r,id,desRect.x+i,desRect.y,&Top,0,NULL,SDL_FLIP_NONE);
        Draw(r,id,desRect.x+i,desRect.y+desRect.h-tileSize,&Bottom,0,NULL,SDL_FLIP_NONE);
    }
    Draw(r,id,desRect.x,desRect.y,&rectTopLeft,0,NULL,SDL_FLIP_NONE);
    Draw(r,id,desRect.x+desRect.w-tileSize,desRect.y,&TopRight,0,NULL,SDL_FLIP_NONE);
    Draw(r,id,desRect.x,desRect.y+desRect.h-tileSize,&BottomLeft,0,NULL,SDL_FLIP_NONE);
    Draw(r,id,desRect.x+desRect.w-tileSize,desRect.y+desRect.h-tileSize,&BottomRight,0,NULL,SDL_FLIP_NONE);

//    SDL_RenderCopyEx(r,m_TextureMap[id]->GetSDLTexture(),&srcRect,&desRect,0,NULL,SDL_FLIP_NONE);

}
void TextureManager::SDLDraw(SDL_Renderer * renderer,std::string id, SDL_Rect * srcrect, SDL_Rect *dstrect, double angle, SDL_Point *center, SDL_RendererFlip flip)
{

    //    m_TextureMap[id]->Render(renderer,srcrect->x,srcrect->y,dstrect,angle,center,flip);
    SDL_RenderCopyEx(renderer,m_TextureMap[id]->GetSDLTexture(),srcrect,dstrect,angle,center,flip);
}

void TextureManager::SDLDraw(SDL_Renderer * renderer,std::string id, SDL_Rect*  srcrect,  SDL_FRect* dstrect,double angle, SDL_FPoint *center, SDL_RendererFlip flip)
{
//    m_TextureMap[id]->Render(renderer,srcrect->x,srcrect->y,dstrect,angle,center,flip);
    SDL_RenderCopyExF(renderer,m_TextureMap[id]->GetSDLTexture(),srcrect,dstrect,angle,center,flip);
}

void TextureManager::Drawcircle(SDL_Renderer *renderer,float centreX, float centreY,SDL_Color c, float radius,bool Filled)
{
    if(!Filled)
    {
        SetColour(c,renderer);

        const int32_t diameter = (radius * 2);

        int32_t x = (radius - 1);
        int32_t y = 0;
        int32_t tx = 1;
        int32_t ty = 1;
        int32_t error = (tx - diameter);

        while (x >= y)
        {
            //  Each of the following renders an octant of the circle
            SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
            SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
            SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
            SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
            SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
            SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
            SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
            SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

            if (error <= 0)
            {
                ++y;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --x;
                tx += 2;
                error += (tx - diameter);
            }
        }
        // Setting the color to be RED with 100% opaque (0% trasparent).
        // Drawing circle
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
        for (int w = 0; w < radius * 2; w++)
        {
            for (int h = 0; h < radius * 2; h++)
            {
                float dx = radius - w; // horizontal offset
                float dy = radius - h; // vertical offset
                if ((dx*dx + dy*dy) <= (radius * radius))
                {
                    SDL_RenderDrawPointF(renderer, centreX + dx, centreY + dy);
                }
            }
        }
    }
}

SDL_FRect TextureManager::QueryText(const std::string message,TTF_Font *font,SDL_Renderer *render)
{

    if(message=="")
    {
        return {0,0,0,0};
    }
    SDL_Surface *surf = TTF_RenderText_Blended(font,message.c_str(), {255,255,255,255});
    if(surf==nullptr)
        std::cout << "error QueryText \n";
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
    if(texture==nullptr)
        std::cout << "error QueryText \n";

    int iW,iH;
    SDL_QueryTexture(texture,NULL,NULL,&iW,&iH);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
    return {0,0,iW,iH};
    // SDL_RenderCopyEx(render,texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);

}
void TextureManager::DrawGrid(float offsetX,float offsetY,float Width,float Height,float TileSize,SDL_Color c,SDL_Renderer *render)
{
    SetColour(c,render);
    float TotalRowSize = Width*(float)TileSize;
    float TotalColumnSize = Height*(float)TileSize;



    for(int j = 0 ; j <=  TotalRowSize; j+=TileSize)
        SDL_RenderDrawLine(render,
                           j+offsetX,
                           offsetY,
                           j+offsetX,
                           TotalColumnSize+offsetY
                          );
    for(int i = 0 ;  i <= TotalColumnSize; i+= TileSize)
        SDL_RenderDrawLine(render,
                           offsetX,
                           i+offsetY,
                           TotalRowSize+offsetX,
                           i+offsetY
                          );




}
void TextureManager::DrawGridSqaured(float x, float y, float w, float h, float tileSize,SDL_Color c,SDL_Renderer *render)
{


    SetColour(c,render);
    for(int j = 0 ; j <= w; j += tileSize)
    {

        SDL_RenderDrawLineF(render,x,y+j,w,y+j);
        SDL_RenderDrawLineF(render,x+j,y,x+j,h);
    }


}
/**

y(t) = A * sin(2 * PI * f * t + shift)
where:
{\displaystyle y(t)=A\sin(2\pi ft+\varphi )=A\sin(\omega t+\varphi )}
A = the amplitude, the peak deviation of the function from zero.
f = the ordinary frequency, the number of oscillations (cycles)
t = time
shift = phase shift

y[t] = AMPLITUDE * sin (2 * M_PI * 0.15 * t + 0) + ZERO_OFFSET;
                                   ^^^ f = 15 cycles / NUM_POINTS = 0.15 Hz
*/
void TextureManager::DrawSineWave(vec2f position,int wavelength,float amplitude,float frequency,float  time,float  shift,SDL_Renderer *render)
{

    int framecounter = 0;
    for(int i = 0 ; i < wavelength; i+=1)
    {
        float rads = 2.0*M_PI/180;

        float inc = amplitude*std::sin(i*rads*frequency*time+(shift*0.17));

        DrawPoint(render,position.x+i,position.y+inc);
    }
}

void TextureManager::DrawLine(SDL_Renderer* render,float x1,float y1, float x2,float y2,SDL_Color c)
{
    SetColour(c,render);
    SDL_RenderDrawLineF(render,x1,y1,x2,y2);

}

void TextureManager::DrawLine(SDL_Renderer* render,line l,SDL_Color c)
{

    SetColour(c,render);
    SDL_RenderDrawLineF(render,l.Min.x,l.Min.y,l.Max.x,l.Max.y);

}
//SDL_Colour RenColour = GetDrawColor(render);
////RenColour.r = 255%(125-RenColour.r);
////RenColour.g = 255%(125-RenColour.g);
////RenColour.b = 255%(125-RenColour.b);
//vec2f l_Step = vec2f::Lerp(l.Min,l.Max,0.5);
//DrawVector(render,l.Min,l_Step,RenColour);
//DrawVector(render,l.Min+l_Step,l.Max,c);
//
//
//        SDL_Rect rr = {0,0,MOUSEPOSITION.x,MOUSEPOSITION.y};
//        TextureManager::Instance()->DrawRect(APP->GetRenderer(),rr, Colour_gold,false);
//        TextureManager::Instance()->SetColour(Colour_black,APP->GetRenderer());
//        float spacing = 9;
//        for(int i = 0 ; i < rr.w ; i+=spacing)
//        {
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x+i,rr.y);
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x+i+1,rr.y);
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x+i,rr.y+rr.h-1);
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x+i+1,rr.y+rr.h-1);
//        }
//
//        for(int i = 0 ; i < rr.h ; i+=spacing)
//        {
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x,rr.y+i);
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x,rr.y+i+1);
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x+rr.w-1,rr.y+i);
//            TextureManager::Instance()->DrawPoint(APP->GetRenderer(),rr.x+rr.w-1,rr.y+i+1);
//        }
//        SDL_GetRenderDrawColor()
//        SDL_Color dd = SDL_GetRenderDrawColor()
//                       SetColour(c,render);
//        SDL_RenderDrawLineF(render,l.Min.x,l.Min.y,l.Max.x,l.Max.y);
//        SDL_RenderDrawLineF(render,l.Min.x,l.Min.y,l.Max.x,l.Max.y);


void TextureManager::DrawLineDotted(SDL_Renderer* render,line l,SDL_Color c)
{
//    SDL_RenderDrawLineF(render,l.Min.x,l.Min.y,l.Max.x,l.Max.y);
    SetColour(c,render);
    SDL_RenderDrawLineF(render,l.Min.x,l.Min.y,l.Max.x,l.Max.y);
    SDL_Rect rr = {l.Min.x,l.Min.y,l.Max.x-l.Min.x+1,l.Max.y-l.Min.y+1};
    DrawRect(render,rr, {255,255,255});

//
//    float dis = vec2f::Dist(l.Min,l.Max);
//    float step = dis*0.1;
//    SetColour({255,0,255},render);
//    for(int i = 0 ; i < dis/step ; i+=1)
//    {
//        vec2f g = ( l.Max - l.Min );
//        g.Normalise();
//        g *= step*i;
//        g+= l.Min+i*step;
//        DrawLine(render,line{(l.Min,g)},Colour_coral);
//        DrawPoint(render,l.Min+vec2f(g));
//        DrawPoint(render,l.Min+vec2f(i+1,0));
//        DrawPoint(render,l.Min+vec2f(0,i));
//        DrawPoint(render,l.Min+vec2f(0,i+1));
//        DrawPoint(render,l.Min+vec2f(0,i+1+1));

//    }
//SDL_Colour RenColour = GetDrawColor(render);
////RenColour.r = 255%(125-RenColour.r);
////RenColour.g = 255%(125-RenColour.g);
////RenColour.b = 255%(125-RenColour.b);
//    float spacing = 9;
//vec2f l_Step = vec2f::Lerp(l.Min,l.Max,0.25);
//DrawVector(render,l.Min,l_Step,RenColour);
//DrawVector(render,l.Min+l_Step,l.Max,c);
}




void TextureManager::Draw(SDL_Renderer* r,std::string id,SDL_Rect screct,SDL_FRect dsrect,double angle,SDL_FPoint *center,SDL_RendererFlip flip)
{
    m_TextureMap[id]->Render(r,&screct,&dsrect,angle,center,flip);
}

void TextureManager::Draw(SDL_Renderer * r,std::string id,float x,float y,SDL_Rect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip)
{


    m_TextureMap[id]->Render(r,x,y,clip,angle,center,flip);
}
void TextureManager::Draw(SDL_Renderer * r,std::string id,float x,float y,SDL_FRect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip)
{
    SDL_Rect temp = {clip->x,clip->y,clip->w,clip->h};
    m_TextureMap[id]->Render(r,x,y,&temp,angle,center,flip);
}

//void TextureManager::DrawText(int val, float x,float y,TTF_Font *font,SDL_Renderer *render)
//{
//    std::stringstream s ;
//    s << val;
//    DrawText(s.str(),x,y,font,render);
//
//}
//void TextureManager::DrawText(float val, float x,float y,TTF_Font *font,SDL_Renderer *render)
//{
//    std::stringstream s ;
//    s << val;
//    DrawText(s.str(),x,y,font,render);
//
//}
void TextureManager::drawText(const std::string message, float x,float y,SDL_Color Textcolour,TTF_Font *font,SDL_Renderer *render)
{
    SDL_Color FGC  = {0,0,0,0};
    FGC = Textcolour;
    if(message.empty())
    {
        std::cout << "  \n";
        return;
    }
    int iW,iH;

    if(font==NULL)
    {
        std::cout << TTF_GetError();
        std::cout << " 3 error \n";
        return ;
    }

    SDL_Surface *surf =  TTF_RenderUTF8_Blended(font,message.c_str(),FGC);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
    if(texture==nullptr)
    {
        std::cout << SDL_GetError();
        std::cout << " 3 error \n";
        return ;
    }
    SDL_QueryTexture(texture,NULL,NULL,&iW,&iH);
    SDL_Rect ss = {x,y,iW,iH};

//    SDL_SetTextureColorMod(texture,colour.r,colour.g,colour.b);
    SDL_RenderCopyEx(render,texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);

    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
}
void  TextureManager::drawText(SDL_Renderer *render,TTF_Font *font, std::string message, float x,float y,SDL_Color Textcolour,int textalign,int pxSize)
{
    SDL_Color FGC  = {0,0,0,0};
    FGC = Textcolour;
    SDL_Surface *surf = NULL;
    SDL_Texture *texture = NULL;
    if(message.empty())
    {
        std::cout << " 3 error \n";
        return;
    }
    int iW =0;
    int iH = 0;
    SDL_Rect ss = {0,0,0,0};
    if(font==NULL)
    {
        std::cout << TTF_GetError();
        std::cout << " 3 error \n";
        return ;
    }
    TTF_SetFontSize(font,pxSize);
    surf =  TTF_RenderText_Blended(font,message.c_str(),FGC);
    if(surf==nullptr)
    {
        std::cout << SDL_GetError();
        std::cout << " surf error \n";
        return ;
    }
    texture = SDL_CreateTextureFromSurface(render,surf);
    if(texture==nullptr)
    {
        std::cout << SDL_GetError();
        std::cout << " texture error \n";
        return ;
    }
    if(SDL_QueryTexture(texture,NULL,NULL,&iW,&iH))
    {
        std::cout << SDL_GetError();
        std::cout << " QueryTexture error \n";
        return ;
    }
    if(textalign==Text_Align::Align_Left)
        ss = {x,y,iW,iH};
    if(textalign==Text_Align::Align_Center)
        ss = {x-iW/2,y,iW,iH};
    if(textalign==Text_Align::Align_Right)
        ss = {x-iW,y,iW,iH};

//    SDL_SetTextureColorMod(texture,colour.r,colour.g,colour.b);
    SDL_RenderCopyEx(render,texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);

    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
}
/**<         TextureManager::Instance()->DrawTextWrapped(APP->GetRenderer(),
                                                    fontManager->GetFont("OpenSans-Regular24"),
                                                    "example text to test that it drops to a new line.",
                                                    MOUSEPOSITION,
                                                    300,
                                                    Colour_white,Align_Left,
                                                    frameCounter,
                                                    SDL_FPoint({150,32}),
                                                    SDL_FLIP_NONE); */

void  TextureManager::DrawTextWrappedShaded(SDL_Renderer *render,TTF_Font *font,const std::string message, vec2f Pos,Uint32 wrapLength,SDL_Color Textcolour,SDL_Color BackGroundColour, Text_Align align,float Angle,SDL_FPoint Center,SDL_RendererFlip Flip)
{
    SDL_Color BGC = {0,0,0,0};
    SDL_Color FGC  = {0,0,0,0};
    SDL_FRect textRect = {0,0,0,0};
    BGC = BackGroundColour;
    FGC = Textcolour;
    SDL_Surface* textSurface = nullptr;
    SDL_Texture* textTexture = nullptr;
    {

        if(message.empty())
        {
            std::cout << " message error \n";
            return;
        }
        if(font==NULL)
        {
            std::cout << TTF_GetError();
            std::cout << " font error \n";
            return ;
        }
        textSurface = TTF_RenderText_Shaded_Wrapped(font,message.c_str(),FGC,BGC,wrapLength);

        if(textSurface==nullptr)
        {
            std::cout << " textSurface error \n";
            return ;
        }

        textTexture = SDL_CreateTextureFromSurface(render, textSurface);

        if(textTexture==nullptr)
        {
            SDL_FreeSurface(textSurface);
            std::cout << SDL_GetError();
            std::cout << " textTexture error \n";
            return ;
        }

//    		TTF_SizeText(font, "Hello\nHello", &textSize.x, &textSize.y);
//	textSize.y*=2;
//std::cout << textSize.y << "\n";
        if(align==Text_Align::Align_Left)
            textRect = { Pos.x, Pos.y, textSurface->w, textSurface->h};
        if(align==Text_Align::Align_Center)
            textRect = { Pos.x-textSurface->w/2, Pos.y, textSurface->w, textSurface->h};
        if(align==Text_Align::Align_Right)
            textRect = { Pos.x-textSurface->w, Pos.y, textSurface->w, textSurface->h};

        SDL_RenderCopyExF(render, textTexture, NULL,&textRect,Angle,&Center,Flip);

        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);



    }


}
void TextureManager::DrawTextWrapped(SDL_Renderer *render,TTF_Font *font,const std::string message, vec2f Pos,float wrapLength,SDL_Color Textcolour, Text_Align align,float Angle,SDL_FPoint Center,SDL_RendererFlip Flip)
{

    SDL_Color FGC  = {0,0,0,0};
    FGC = Textcolour;
    {

        if(message.empty())
        {
            std::cout << " message error \n";
            return;
        }
        if(font==NULL)
        {
            std::cout << TTF_GetError();
            std::cout << " font error \n";
            return ;
        }
        SDL_Surface* textSurface;
        textSurface = TTF_RenderText_Blended_Wrapped(font,message.c_str(),FGC,wrapLength);

        if(textSurface==nullptr)
        {
            std::cout << SDL_GetError();
            std::cout << " textSurface error \n";
            return ;
        }

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(render, textSurface);
        SDL_FreeSurface(textSurface);

        if(textTexture==nullptr)
        {
            std::cout << SDL_GetError();
            std::cout << " textTexture error \n";
            return ;
        }


//    		TTF_SizeText(font, "Hello\nHello", &textSize.x, &textSize.y);
//	textSize.y*=2;
//std::cout << textSize.y << "\n";
        SDL_FRect textRect = {0,0,0,0};
        if(align==Text_Align::Align_Left)
            textRect = { Pos.x, Pos.y, textSurface->w, textSurface->h};
        if(align==Text_Align::Align_Center)
            textRect = { Pos.x-textSurface->w/2, Pos.y, textSurface->w, textSurface->h};
        if(align==Text_Align::Align_Right)
            textRect = { Pos.x-textSurface->w, Pos.y, textSurface->w, textSurface->h};


        SDL_RenderCopyExF(render, textTexture, NULL,&textRect,Angle,&Center,Flip);

        SDL_DestroyTexture(textTexture);

    }

}

void TextureManager::drawTestTexture(SDL_Renderer *render, std::string id)
{
    SDL_Rect screct = {0,0,m_TextureMap[id]->GetWidth(),m_TextureMap[id]->GetHeight()};
    SDL_RenderCopy(render,m_TextureMap[id]->GetSDLTexture(),NULL,&screct);
}


void TextureManager::DrawTriangle(SDL_Renderer* render,vec2f v1,vec2f v2,vec2f v3,SDL_Color c)
{

    SDL_Vertex vertex_1 = {{v1.x,v1.y}, {255,0,0,255}, {1, 1}};
    SDL_Vertex vertex_2 = {{v2.x,v2.y}, {0,255,0,0}, {1, 1}};
    SDL_Vertex vertex_3 = {{v3.x,v3.y}, {0,0,255,0}, {1, 1}};
// Put them into array
    SDL_Vertex vertices[] =
    {
        vertex_1,
        vertex_2,
        vertex_3
    };
    SDL_RenderGeometry(render, NULL, vertices,3, NULL, 0);

// Set renderer color

//SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

// Render red triangle


}



//void TextureManager::DrawText(const std::string message,float x,float y,TTF_Font *font,SDL_Renderer *render)
//{
//
//    DrawText(message,x,y, {255,255,255,255},font,render);
//
//
//}
//void TextureManager::DrawText(const std::string message, vec2f pos,TTF_Font *font,SDL_Renderer *render)
//{
//
//    DrawText(message,pos.x,pos.y, {255,255,255,255},font,render);
//}



//  float inc = amplitude*std::sin(i*rads*frequency*time+shift);

//      f,x+vt)+
//y(t) = A * sin(2 * PI * f * t + shift)
//A = the amplitude, the peak deviation of the function from zero.
//f = the ordinary frequency, the number of oscillations (cycles)
//t = time
//shift = phase shift
//  rads = 2.0*M_PI*i/100;
//
// for(int i = 0 ; i < camsize.x; i+=1)
//    {
//        float inc = 10*std::sin(i*2.0*M_PI*0.5/180+framecounter);
//
//        TextureManager::Instance()->DrawPoint(campos.x+i,camsize.y+campos.y+inc,App->GetRenderer());
//    }
