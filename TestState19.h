#ifndef TESTSTATE19_H
#define TESTSTATE19_H

#include <GameState.h>
#include <iostream>
#include <StateFactory.h>
#include <TextureManager.h>
#include <InputHandler.h>
#include <Application.h>
class TestState19 : public GameState
{
public:
    TestState19();
    virtual ~TestState19();
    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void HandleEvent(SDL_Event &e );
    std::string Type()
    {
        return "TestState19";
    }
protected:

private:


       vec2f *vs;
       vec2f m_pos,m_oldpos,m_vel,m_acc = vec2f(0,0);

};
class TestState19Creater : public StateBaseCreater
{

public :
    GameState* CreateState() const
    {
        return new TestState19();
    }
};

#endif // TESTSTATE19_H

//    m_force1 = m_mass1 * m_gravity * dt;
//    m_force2 -= m_mass2 * m_gravity * dt;
//    vel1 += acc1 *dt;
//    vel2 += acc2 *dt;
//pos1 -= vel1;
//pos1.y *= m_force1;

//    std::cout << pos1.y<< "ss\n";
//    // m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//    // m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//
//m_force -= m_mass * m_gravity * dt
//
//    m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//    m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//
//
//
//
//    m_velocity += GetAcceleration() * Speed *= Game::Instance()->GetDeltaTime();
//    m_position +=  m_velocity;
////
//if(m_position.y>=Game::Instance()->GetWindowHeight())
//{
//    m_position.y =0;

//VEL + acc + dt
//pos  += vel
//f = MA;
//
////        velocity += acceleration *= Game::Instance()->GetDeltaTime();
////        m_velocity.x = velocity*= 0.99;
////        m_position +=  m_velocity;
//    m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
////           m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
////            //    m_position.y -= m_force * Game::Instance()->GetDeltaTime();
////        } m_force -= 1;
////        m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
////        m_position.y -= m_force * Game::Instance()->GetDeltaTime();
////        velocity += acceleration *= Game::Instance()->GetDeltaTime();
//    float l_dt= Game::Instance()->GetDeltaTime();
//m_velocity  -= GetAcceleration() + l_dt*2;
//m_position  -= m_velocity;
