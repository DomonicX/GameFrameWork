#ifndef PATHFINDERASTAR_H
#define PATHFINDERASTAR_H
#include <IPathFinder.h>

class PathFinderAstar : public IPathFinder
{
public:
    PathFinderAstar();
    virtual ~PathFinderAstar();

    void FindPath( std::vector<Node*> Path,Node *start, Node *target,int ROWS,int COLS,int TileSize) ;
    void UpDate();


protected:

private:
};

#endif // PATHFINDERASTAR_H

