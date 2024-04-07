#include "TestState.h"

TestState::TestState()
{


}
TestState::~TestState()
{
    //dtor
}
void TestState::Render()
{
}

void TestState::Update()
{

}

bool TestState::OnEnter()
{

    return true;
}
bool TestState::onExit()
{
    std::cout<< "Exiting : "<< Type() << " \n";
}
void TestState::resume()
{
    std::cout<< "Resuming : "<< Type() << " \n";
}

void TestState::HandleEvent(SDL_Event &e ) {}
