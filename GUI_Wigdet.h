#ifndef GUI_WIGDET_H
#define GUI_WIGDET_H

#include <SDL2/SDL.h>
#include <iostream>
#include <Vector2D.h>
#include <ICommand.h>

class GUI_Wigdet
{
public:
    GUI_Wigdet();
    virtual ~GUI_Wigdet();
//  virtual bool init(std::string Title,SDL_Rect hitbox) = 0;
      virtual void HandleEvent(SDL_Event &e ) = 0;
    virtual void Update(float deltaTime)= 0;
    virtual void Render() = 0;
    virtual void Remove(int n) = 0;
    virtual void Add(GUI_Wigdet* w) = 0;
    virtual GUI_Wigdet& GetChild(int i) = 0;
    virtual int GetChildSize() = 0;




    virtual std::string Type() = 0;


      virtual   void SetVisable(bool con) = 0;
    virtual void SetTitle(std::string Title)= 0;
  virtual   void SetHitBox(SDL_FRect r)= 0;
 virtual    void SetPosition(vec2f pos)= 0;
virtual    bool isClicked()= 0;
 virtual    bool isVisable()= 0;
 virtual    bool isMouseOver()= 0;
 virtual    SDL_FRect GetHitBox()= 0;
 virtual    int getHeight()= 0;
 virtual    std::string getTitle()= 0;
 virtual    vec2f Getposition()= 0;
 virtual    int getWidth()= 0;

protected:

private:
};

#endif // GUI_WIGDET_H
