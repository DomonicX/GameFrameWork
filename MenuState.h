#ifndef MENUSTATE_H
#define MENUSTATE_H
#include <GameState.h>
#include <iostream>
#include <CallBack.h>
#include <SDL2/SDL_rect.h>
typedef enum
{
    PLAY,
    LEVEL,
    QUIT,
    SETTINGS
} MainMenuButtons;

class MenuState : public GameState
{
public:
    MenuState( std::string * FilePath,  std::string * FileMap);
    MenuState();
    virtual ~MenuState();
    void Render() ;
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();

  void HandleEvent(SDL_Event &e ){}
    std::string GetStateID()
    {
        return "MenuState";
    }
private:
    std::string * m_FilePath;
    std::string * m_FileMap;
    void DisplayButtonText();
    bool isMouseOverButtons();
    void DisplaySelectButton();
    bool CheckButtonPress();
    bool clicked();
    void MenuStateToPlayState();
    void MenuStateToSettings();
    void MenuStateToQuit();
    void MenuStateToLevel();

    SDL_Rect m_ButtonsRects[4];
    bool isInsideBox(int x, int y, int w, int h);
    SDL_Rect *m_ButtonSelection = nullptr;
    bool nn  = false;
    bool nr = false;
};

#endif // MENUSTATE_H

