#include "IPathFinder.h"

IPathFinder::IPathFinder()
{
    //ctor
}

IPathFinder::~IPathFinder()
{
    //dtor
}
void IPathFinder::DisplayPath(SDL_Renderer &Rend ,int TileSize)
{
    for(int i; i<PathNode.size(); i++)
    {
        PathNode[i]->Display(Rend,TileSize);
    }
}



 void IPathFinder::addGrid(Node gridNode[],int Rows){PathNode.push_back(gridNode);}



/*
IPathFinder::IPathFinder(const IPathFinder& other)
{
    //copy ctor
}

IPathFinder& IPathFinder::operator=(const IPathFinder& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
*/
//Grid.push_back(gridNode);
//Grid.push_back(*gridNode);




