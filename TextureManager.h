#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <math.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <istream>
#include <ostream>
#include <Vector2D.h>
#include <LTexture.h>

#define Colour_GUIForeGround                      {125,146,158}
#define Colour_GUIBackGround                      {211,203,190}
#define Colour_GUIBackGroundHighLighted           {255,235,182}
#define Colour_aliceblue             {240,248,255}
#define Colour_antiquewhite          {250,235,215}
#define Colour_aqua                  {0,255,255}
#define Colour_aquamarine            {127,255,212}
#define Colour_azure                 {240,255,255}
#define Colour_beige                 {245,245,220}
#define Colour_bisque                {255,228,196}
#define Colour_black                 {0,0,0}
#define Colour_blanchedalmond        {255,235,205}
#define Colour_blue                  {0,0,255}
#define Colour_blueviolet            {138,43,226}
#define Colour_brown                 {165,42,42}
#define Colour_burlywood             {222,184,135}
#define Colour_cadetblue             {95,158,160}
#define Colour_chartreuse            {127,255,0}
#define Colour_chocolate             {210,105,30}
#define Colour_coral                 {255,127,80}
#define Colour_cornflowerblue        {100,149,237}
#define Colour_cornsilk              {255,248,220}
#define Colour_crimson            	 {220,20,60}
#define Colour_cyan                  {0,255,255}
#define Colour_darkblue              {0,0,139}
#define Colour_darkcyan              {0,139,139}
#define Colour_darkgoldenrod         {184,134,11}
#define Colour_darkgray              {169,169,169}
#define Colour_darkgrey              {169,169,169}
#define Colour_darkkhaki             {189,183,107}
#define Colour_darkmagenta           {139,0,139}
#define Colour_darkolivegreen        {85,107,47}
#define Colour_darkorange            {255,140,0}
#define Colour_darkorchid            {153,50,204}
#define Colour_darkred           	 {139,0,0}
#define Colour_darksalmon            {233,150,122}
#define Colour_darkseagreen          {143,188,143}
#define Colour_darkslateblue         {72,61,139}
#define Colour_darkslategray         {47,79,79}
#define Colour_darkturquoise         {0,206,209}
#define Colour_darkviolet            {148,0,211}
#define Colour_deeppink              {255,20,147}
#define Colour_deepskyblue           {0,191,255}
#define Colour_dimgray      	     {105,105,105}
#define Colour_dodgerblue            {30,144,255}
#define Colour_firebrick             {178,34,34}
#define Colour_floralwhite           {255,250,240}
#define Colour_forestgreen           {34,139,34}
#define Colour_fuchsia               {255,0,255}
#define Colour_gainsboro             {220,220,220}
#define Colour_ghostwhite            {248,248,255}
#define Colour_gold                  {255,215,0}
#define Colour_goldenrod             {218,165,32}
#define Colour_green                 {0,255,0}
#define Colour_darkgreen                {0,128,0}
#define Colour_greenyellow           {173,255,47}
#define Colour_grey                  {128,128,128}
#define Colour_honeydew              {240,255,240}
#define Colour_hotpink       	     {255,105,180}
#define Colour_indianred             {205,92,92}
#define Colour_indigo                {75,0,130}
#define Colour_ivory                 {255,255,240}
#define Colour_khaki                 {240,230,140}
#define Colour_lavender              {230,230,250}
#define Colour_lavenderblush         {255,240,245}
#define Colour_lawngreen             {124,252,0}
#define Colour_lemonchiffon          {255,250,205}
#define Colour_lightblue             {173,216,230}
#define Colour_lightcoral            {240,128,128}
#define Colour_lightcyan             {224,255,255}
#define Colour_lightgoldenrodyellow  {250,250,210}
#define Colour_lightgray             {211,211,211}
#define Colour_lightgreen            {144,238,144}
#define Colour_lightpink             {255,182,193}
#define Colour_lightsalmon           {255,160,122}
#define Colour_lightseagreen         {32,178,170}
#define Colour_lightskyblue          {135,206,250}
#define Colour_lightslategray        {119,136,153}
#define Colour_lightsteelblue        {176,196,222}
#define Colour_lightyellow           {255,255,224}
#define Colour_lime                  {0,255,0}
#define Colour_limegreen             {50,205,50}
#define Colour_linen                 {250,240,230}
#define Colour_magenta               {255,0,255}
#define Colour_maroon                {128,0,0}
#define Colour_mediumaquamarine      {102,205,170}
#define Colour_mediumblue            {0,0,205}
#define Colour_mediumorchid          {186,85,211}
#define Colour_mediumpurple          {147,112,219}
#define Colour_mediumseagreen        {60,179,113}
#define Colour_mediumslateblue       {123,104,238}
#define Colour_mediumspringgreen     {0,250,154}
#define Colour_mediumturquoise       {72,209,204}
#define Colour_mediumvioletred       {199,21,133}
#define Colour_midnightblue          {25,25,112}
#define Colour_mintcream             {245,255,250}
#define Colour_mistyrose             {255,228,225}
#define Colour_moccasin              {255,228,181}
#define Colour_navajowhite           {255,222,173}
#define Colour_navy                  {0,0,128}
#define Colour_oldlace               {253,245,230}
#define Colour_olive                 {128,128,0}
#define Colour_olivedrab             {107,142,35}
#define Colour_orange                {255,165,0}
#define Colour_orangered             {255,69,0}
#define Colour_orchid                {218,112,214}
#define Colour_palegoldenrod         {238,232,170}
#define Colour_palegreen             {152,251,152}
#define Colour_paleturquoise         {175,238,238}
#define Colour_palevioletred         {219,112,147}
#define Colour_papayawhip            {255,239,213}
#define Colour_peachpuff             {255,218,185}
#define Colour_peru                  {205,133,63}
#define Colour_pink                  {255,192,203}
#define Colour_plum                  {221,160,221}
#define Colour_powderblue            {176,224,230}
#define Colour_purple                {128,0,128}
#define Colour_red                   {255,0,0}
#define Colour_rosybrown             {188,143,143}
#define Colour_royalblue             {65,105,225}
#define Colour_saddlebrown           {139,69,19}
#define Colour_salmon                {250,128,114}
#define Colour_sandybrown            {244,164,96}
#define Colour_seagreen              {46,139,87}
#define Colour_seashell              {255,245,238}
#define Colour_sienna                {160,82,45}
#define Colour_silver                {192,192,192}
#define Colour_skyblue               {135,206,235}
#define Colour_slateblue             {106,90,205}
#define Colour_slategray             {112,128,144}
#define Colour_snow                  {255,250,250}
#define Colour_springgreen           {0,255,127}
#define Colour_steelblue             {70,130,180}
#define Colour_tan                   {210,180,140}
#define Colour_teal                  {0,128,128}
#define Colour_thistle               {216,191,216}
#define Colour_tomato                {255,99,71}
#define Colour_turquoise             {64,224,208}
#define Colour_violet                {238,130,238}
#define Colour_verydarkgray              {18,18,18}
#define Colour_veryLightgray              {237,237,237}

#define Colour_wheat                 {245,222,179}
#define Colour_white                 {255,255,255}
#define Colour_whitesmoke            {245,245,245}
#define Colour_yellow                {255,255,0}
#define Colour_yellowgreen           {154,205,50}
#define Colour_MarioBackGround_      {147, 187, 236}
#include <vector>

typedef enum
{
    Line_NORMAL,
    Line_DOT,
    Line_SPECIAL
} LineStyle;
typedef enum
{
    Align_Left,
    Align_Center,
    Align_Right
} Text_Align;

class TextureManager
{
public:
    static TextureManager* Instance()
    {
        if(s_pInstance==NULL) s_pInstance = new TextureManager();
        return s_pInstance;
    }
 void   drawSprite(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip);

    void Draw(SDL_Renderer* r,std::string id,SDL_Rect screct,SDL_FRect dsrect,double angle = 0.0,SDL_FPoint *center = NULL,SDL_RendererFlip flip = SDL_FLIP_NONE);
    void Draw(SDL_Renderer * r,std::string id,float x = 0,float y = 0,SDL_Rect* clip = NULL,double angle = 0.0,SDL_FPoint* center = NULL,SDL_RendererFlip flip = SDL_FLIP_NONE);
    void Draw(SDL_Renderer * r,std::string id,float x = 0,float y = 0,SDL_FRect* clip = NULL,double angle = 0.0,SDL_FPoint* center = NULL,SDL_RendererFlip flip = SDL_FLIP_NONE);

    void SDLDraw(SDL_Renderer * renderer,std::string id, SDL_Rect * srcrect, SDL_Rect *dstrect, double angle, SDL_Point *center, SDL_RendererFlip flip);
    void SDLDraw(SDL_Renderer * renderer,std::string id, SDL_Rect * srcrect, SDL_FRect *dstrect, double angle, SDL_FPoint *center, SDL_RendererFlip flip);

    void DrawPoint(SDL_Renderer *r,float x, float y,SDL_Color c = Colour_magenta);
    void DrawPoint(SDL_Renderer *r,SDL_Point,SDL_Color c = Colour_magenta);
    void DrawPoint(SDL_Renderer *r,SDL_FPoint,SDL_Color c = Colour_magenta);
    void DrawPoint(SDL_Renderer *r,vec2f v,SDL_Color c = Colour_magenta);

    void DrawVector(SDL_Renderer* render,vec2f o,vec2f v,SDL_Color c = SDL_Color{0,0,0,0}, float thickness = 1, float rotation = 0.0);
    void DrawVector(SDL_Renderer* render,vec2f v,vec2f o,vec2f s,SDL_Color c = SDL_Color{0,0,0,0}, float thickness = 1, float rotation = 0.0);
    void DrawVector(SDL_Renderer* render,vec2f* v,int Count,SDL_Color c = Colour_aliceblue);

    void DrawTriangle(SDL_Renderer* render,vec2f v1,vec2f v2,vec2f v3,SDL_Color c);

    void DrawRect(SDL_Renderer *ren,vec2f r,float w,float h,SDL_Color c = {255,255,255},bool isFilled = false);
    void DrawRect(SDL_Renderer *ren,SDL_FRect r,SDL_Color c = {255,255,255},bool isFilled = false);
    void DrawRect(SDL_Renderer *ren,SDL_Rect r,SDL_Color c = {255,255,255},bool isFilled = false);

    void DrawRects(SDL_Renderer *ren,SDL_Rect *rects,int RectCount,SDL_Color c = {0,0,0,0}, bool isFilled = false);
    void DrawRects(SDL_Renderer *ren,SDL_FRect *rects,int RectCount,SDL_Color c = {0,0,0,0}, bool isFilled = false);

    void DrawRectangle(SDL_Renderer *renderer,float CentreX,float CentreY,int Width, int Height,SDL_Color c = Colour_green,bool Filled = false,float angle = 0);

    void Drawcircle(SDL_Renderer *renderer,float centreX, float centreY,SDL_Color c,float radius,bool Filled = false);

    void DrawGridSqaured(float x, float y, float w, float h, float tileSize,SDL_Color c,SDL_Renderer *render);

    void DrawSineWave(vec2f position,int wavelength,float amplitude,float frequency,float  time,float  shift,SDL_Renderer *render);

    void DrawGrid(float offsetX,float offsetY,float Width,float Height,float TileSize,SDL_Color c,SDL_Renderer *render);


    void DrawSqaure(SDL_Renderer *renderer,float CentreX,float CentreY,int length,SDL_Color c = Colour_green,bool Filled = false,float angle = 0);


    SDL_Colour GetDrawColor(SDL_Renderer* ren);

    void DrawLine(SDL_Renderer* render,float x1,float y1, float x2,float y2,SDL_Color c);
    void DrawLine(SDL_Renderer* render,line l,SDL_Color c);
    void DrawLineDotted(SDL_Renderer* render,line l,SDL_Color c);

    void DrawRectWithBoarder(SDL_FRect r,SDL_Color BackGround_c,SDL_Color OutLine_c,float thickness,SDL_Renderer *render);
    void DrawRectWithBoarder(SDL_Rect r,SDL_Color BackGround_c,SDL_Color OutLine_c,float thickness,SDL_Renderer *render);

    void DrawTileHorizontal(SDL_Renderer * r,std::string id, int tileSize, int desSize,float x, float y,SDL_FRect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip);
    void DrawTileVertical(SDL_Renderer * r,std::string id, int tileSize, int desSize,float x, float y,SDL_FRect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip);
    void DrawTileBox(SDL_Renderer * r,std::string id,int tileSize,SDL_Rect srcRect,SDL_Rect desRect);
    void DrawTileBoxAroundRect(SDL_Renderer * r,std::string id,int tileSize,SDL_Rect desRect,SDL_Rect srcRect);

    void drawText(const std::string message, float x,float y,SDL_Color Textcolour,TTF_Font *font,SDL_Renderer *render);
    void drawText(SDL_Renderer *render,TTF_Font *font,const std::string message, float x,float y,SDL_Color Textcolour= Colour_darkviolet,int textalign = Text_Align::Align_Left,int pxSize = 12);


    void drawTestTexture(SDL_Renderer *render, std::string id);
void DrawTextWrapped(SDL_Renderer *render,TTF_Font *font,const std::string message,vec2f Pos = vec2f(0,0),float wrapLength = 0,SDL_Color Textcolour = Colour_white, Text_Align align = Align_Left,float angle = 0,SDL_FPoint center = {0,0},SDL_RendererFlip Flip = SDL_FLIP_NONE);
void DrawTextWrappedShaded(SDL_Renderer *render,TTF_Font *font,const std::string message,vec2f Pos = vec2f(0,0),Uint32 wrapLength = 640,SDL_Color Textcolour = Colour_white,SDL_Color BackGroundColour= Colour_black, Text_Align align = Align_Left,float angle = 0,SDL_FPoint center = {0,0},SDL_RendererFlip Flip = SDL_FLIP_NONE);

    SDL_FRect QueryText(const std::string message,TTF_Font *font,SDL_Renderer *render);

    void QueryTexture(std::string id);
    void SetColour(SDL_Renderer*   renderer,SDL_Color c = Colour_magenta);
    void SetColourKey(const std::string id, float x,float y,SDL_Renderer *render);
    void SetAhpla(std::string id,int alpha );
    void SetColorMod(std::string id,SDL_Color c );
    SDL_Color GetColorMod(std::string id);
    void SetColour(char r,char g, char b, char a,SDL_Renderer*   renderer);
    void SetColour(SDL_Color c,SDL_Renderer*   renderer);

    void  SetBlendMode(const std::string id,SDL_BlendMode blending);
    int GetSize()
    {
        return (int)m_TextureMap.size();
    }

    bool Load(std::string fileName, std::string id,SDL_Renderer* p_ren);
    bool Load(std::string fileName, std::string id,SDL_Color KeyColour,SDL_Renderer* p_ren);

    bool Load(SDL_Renderer* p_ren, std::string id,std::string fileName,std::string  SaveFile,SDL_Color KeyColour);

    std::map<std::string,LTexture *> getTextureMap();
    void ClearTextureMap();
    bool ClearFromTextureMap(std::string id);
    int GetAhpla(std::string id, Uint8 *alpha);
    void Clean();

private:
    TextureManager()
    {
    }
    ~TextureManager() {}
    static TextureManager* s_pInstance;

    std::map<std::string,LTexture *>m_TextureMap;
};

#define  textureManager TextureManager::Instance()
#endif // TEXTUREMANAGER_H

// void DrawArrow(Arrow arrow,SDL_Renderer*   renderer);
//  void DrawVector(vec2f v1,float Scalar,SDL_Renderer*   renderer);
//
//
//     void DrawRectsFilled(SDL_Renderer *ren,SDL_Rect *rects,int RectCount,SDL_Color c);
//
////
//    void DrawText(int val, float x,float y,TTF_Font *font,SDL_Renderer *render);
//    void DrawText(float val, float x,float y,TTF_Font *font,SDL_Renderer *render);
//    void DrawText(const std::string message, float x,float y,float FontSize,SDL_Renderer *render);
//    void DrawText(const std::string message, float x,float y,TTF_Font *font,SDL_Renderer *render);
//    void DrawText(const std::string message, vec2f pos,TTF_Font *font,SDL_Renderer *render);
//



//void TextureManager::LoadRegisterType(std::string fileName,SDL_Renderer* p_ren)
//{
//}
//    void LoadRegisterType(std::string fileName, SDL_Renderer* p_ren);

//    void DrawTarget2(std::string id, int cropX,int cropY,int x, int y,int width, int height, SDL_Renderer*p_ren,double angle, SDL_RendererFlip flip);
//
//    void DrawTarget(std::string id, int cropX,int cropY,int x, int y,int width, int height, SDL_Renderer*p_ren, SDL_RendererFlip flip);

//    void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* p_ren,double angle,int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
//    void DrawTile(std::string id, int margin,int spacing,int x, int y,int width, int height,int currentRow, int currentFrame, SDL_Renderer*p_ren);

//delete &m_TextureMap;
//    ClearTextureMap();
// bool LoadColour(std::string fileName, char r, char, char b, char a);
// std::map<std::string,SDL_Color *> getcolour();
