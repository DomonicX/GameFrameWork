#include "TextObject.h"

TextObject::TextObject()
{
    //ctor


//m_message =  "this is a multiline\n message for you\n";


    //std::cout << m_message << "\n";
}

void TextObject::Init()
{
//    m_message = "Sdsd";
//    m_font = TTF_OpenFont("OpenSans-Bold.TTF",12);
//    m_surf = TTF_RenderUTF8_Solid(m_font,m_message, {255,255,255,255});
//    // m_texture = SDL_CreateTextureFromSurface(,m_surf);
//    GetWidth() = 0;
}
TextObject::~TextObject()
{
    //dtor
//
}

void TextObject::Update(float dt)
{
//    if(hasTextChanged)
//    {
//    }
}
void TextObject::Render(SDL_Renderer *Ren,float OffsetX,float OffsetY)
{
    for(int i = 0 ; i < m_sentences.size(); i++)
    {

//        TextureManager::Instance()->DrawText(m_sentences[i],
//                                             GetPosition().x,GetPosition().y+i*fontManager->GetFontSize("OpenSans-Regular"),
//                                             Colour_white,
//                                             fontManager->GetFont("OpenSans-Regular"),
//                                             App->GetRenderer());
//  TextureManager::Instance()->DrawText(GetPosition.x,GetPosition.y,m_texture,m_font,App->GetRenderer());



    }
}
void TextObject::Clean()
{
    if(!m_sentences.empty())

        m_sentences.clear();
}

void TextObject::Collision() {}
std::string TextObject::Type()
{
    return "TextObject";
}
std::string TextObject::Texture() {};
void TextObject::HandleEvent(SDL_Event& e ) {}

void TextObject::AddSentence(std::string sen)
{
    m_sentences.push_back(sen);


} void TextObject::SetTextWidth(int width)
    {
        //  m_width = width;
    }
    void TextObject::SetfontName(std::string Font)
    {
        m_fontName = Font;
        m_FontHeightSpacing = FontManager::Instance()->GetFontSize(Font);
    } void TextObject::SetColour(char r,char g,char b,char a)
    {
        textColour = {(Uint8)r,(Uint8)g,(Uint8)b,(Uint8)a};
    }
