#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#if SCREEN_WIDTH  == 800
#define SCREEN_HEIGHT 600

#endif // SCREEN_WIDTH



#ifndef IPATHFINDER_H
#define IPATHFINDER_H
#include <Node.h>
#include <algorithm>
#define SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <Node.h>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <float.h>
#include <Vector2D.h>
#include <math.h>
typedef enum {NW,N,NE,
              W,M,E,
              SW,S,SE
             } DIRECTION;
enum state
{
    NO_ACTION,
    UPDATING
};


class IPathFinder
{
public:
    IPathFinder();

    virtual ~IPathFinder();


    IPathFinder(const IPathFinder& other);
    IPathFinder& operator=(const IPathFinder& other);

    void addGrid(Node gridNode[],int Rows);

    virtual void FindPath( std::vector<Node*> Path,Node *start, Node *target,int ROWS,int COLS,int TileSize)= 0;
    virtual void UpDate() = 0;

    void DisplayPath(SDL_Renderer &Rend,int TileSize);
    bool IsDisplay;
    bool isDiagonal;
    bool isCrossCorner;
    int currentPathIndex = 0;

    std::vector<Node*>PathNode;
    std::vector<Node*>& GetPath()
    {
        return PathNode;
    }
    int GetPathIndex()
    {
        return currentPathIndex;
    }
    Node& FindClosestPathNode()
    {
        return *PathNode[currentPathIndex];   //made need to make it bool with path.size to see if place 1 or make it do a test
    }

protected:

    Node *currentGrid;
    state currentState = NO_ACTION;
private:
};

#endif // IPATHFINDER_H












