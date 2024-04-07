#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <vector>
#include <SDL2/SDL.h>
#include <GameObject.h>
#include <iostream>
#include <Application.h>
#include <SDLGameObject.h>
class CollisionManager
{
public:
    static CollisionManager* Instance()
    {

        if(s_pInstance == NULL)
        {
            s_pInstance = new CollisionManager();
            return s_pInstance;
        }
        return s_pInstance;
    }




 std::vector< std::vector<GameObject*>> m_Mat;
void Add(std::vector<GameObject*> m) { m_Mat.push_back(m);}
std::vector<GameObject*>& GetCollisionLayer(int i)   { return m_Mat[i];}
GameObject& GetCollision(int CollisionLayer ,int Index ) { return *m_Mat[CollisionLayer][Index];}

    bool Remove(GameObject * g)
    {

    for( GameObject* i : m_Object)


            if(g==i)
                m_Object.pop_back();



    }
    void Add(vec2f& pos)
    {
        //    m_vecs.push_back*m_vecs);
    }
    int GetSize()
    {
        return (int)m_Object.size();
    }
    virtual ~CollisionManager();
//    void add(SDLGameObjec
    int GetObjectSize()
    {

        return m_Object.size();
    }
    void Clear()
    {
        m_Object.clear();
    };
    void Add(GameObject* o);

    void AddCollision(GameObject* o)
    {
        m_CollidingObjects.push_back(o);
    }
    std::vector<GameObject*> FindResult();
    bool Check(GameObject* o);
    bool Checker(GameObject* o);

    std::vector<GameObject*> check(GameObject* o);
    std::vector<GameObject*> check(vec2f p);
    void AddGrid(vec2f grid)
    {
        m_grid.push_back(grid);
    };
    void AddRect(SDL_Rect Rect)
    {
        m_Rects.push_back(Rect);
    };
    std::vector<vec2f> getGrid()
    {
        return m_grid;
    };
    std::vector<SDL_Rect> getRects()
    {
        return m_Rects;
    };

    std::vector<SDL_Rect>m_Rects;
protected:

private:
    CollisionManager()
    {
    }


    std::vector<vec2f>m_lines;
    std::vector<vec2f>m_grid;
//std::vector<vec2f&>m_vecs;

    std::vector<GameObject*>m_Object;
    std::vector<GameObject*>m_CollidingObjects;

    static CollisionManager* s_pInstance;

};

#define  collisionManager CollisionManager::Instance()
#endif // COLLISIONMANAGER_H
