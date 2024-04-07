#ifndef QUAD_H
#define QUAD_H
#include <cmath>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};

// The objects that we want stored in the quadtree
struct Node {
    Point pos;
    int data;
    Node(Point _pos, int _data)
    {
        pos = _pos;
        data = _data;
    }
    Node() { data = 0; }
};
class Quad
{
    public:
        Quad();
        Quad(Point topL, Point botR);
        virtual ~Quad();

    void insert(Node*);
    Node* search(Point);
    bool inBoundary(Point);
    protected:

    private:
        // Hold details of the boundary of this node
    Point topLeft;
    Point botRight;

    // Contains details of node
    Node* n;

    // Children of this tree
    Quad* topLeftTree = NULL;
    Quad* topRightTree= NULL;
    Quad* botLeftTree= NULL;
    Quad* botRightTree= NULL;


};

#endif // QUAD_H
