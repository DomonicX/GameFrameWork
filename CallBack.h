#ifndef CALLBACK_H
#define CALLBACK_H

#include <iostream>
#include <TextureManager.h>
#include <GameStateMachine.h>
class CallBack
{
public:
    virtual ~CallBack(){}
    virtual void call() = 0;
};

class App_CallBack : public CallBack
{
public :
   std::string m_cbstr2;
    GameStateMachine* m_gsm;
    std::string m_cbstr;

     App_CallBack(std::string str)
    {
        m_cbstr = str;
    }
    App_CallBack(GameStateMachine* _gsm,std::string str,std::string str2) : m_gsm(_gsm), m_cbstr(str),m_cbstr2(str2) {}
    ~ App_CallBack() {}

    void call()
    {
        if(m_gsm!=NULL)
        {
            std::cout << m_gsm->GetCurrentStateID()<<"\n";
        }
        if(m_cbstr=="PushState")
        {
//
//        "PushState"
            m_gsm->PushState(StateFactory::Instance()->Create(m_cbstr2));


        }
        if(m_cbstr=="test")
            std::cout << m_cbstr <<  "\n";
        if(m_cbstr=="DeleteAllTexture")
        {
            std::cout << m_cbstr <<      TextureManager::Instance()->GetSize() << "\n";
//            TextureManager::Instance()->Clean();
        }
    }
};

class StaticCallBack : public CallBack
{

public :
    StaticCallBack(void (*func)()) : m_func(func)
    {

    }  StaticCallBack(void (*func2)(int),int I) : m_func2(func2), i(I)
    {

    }  StaticCallBack(void (*func3)(char *),char* C) : m_func3(func3), s(C)
    {

    }
    virtual ~StaticCallBack(){}
    virtual void call()
    {
        if(m_func!=NULL)
            m_func();
//        if(m_func2!=NULL)
//            m_func2(i);
//        if(m_func3!=NULL)
//            m_func3(s);
    }
private :
    void (*m_func)();
    void (*m_func2)(int);
    int i;
    char* s;
    void (*m_func3)(char*);

};

#endif // CALLBACK_H
