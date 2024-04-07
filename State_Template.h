#ifndef STATE_TEMPLATE_H
#define STATE_TEMPLATE_H

#include <GameState.h>
#include <StateFactory.h>
class State_Template: public GameState
{
public:
    State_Template();
    virtual ~State_Template();

    void Render(){}
    void Update(){}
    bool OnEnter(){}
    bool onExit(){}
    void resume(){}
        void HandleEvent(SDL_Event &e ){}
    std::string Type()
    {
        return "State_Template";
    }
protected:

private:
};


class State_TemplateCreater : public StateBaseCreater
{

public :  State_Template* CreateState() const
    {
        return new State_Template();
    }
};
#endif // STATE_TEMPLATE_H
