#include "Quad.h"

 Quad::Quad()
    {
        topLeft = Point(0, 0);
        botRight = Point(0, 0);
        n = NULL;
        topLeftTree = NULL;
        topRightTree = NULL;
        botLeftTree = NULL;
        botRightTree = NULL;
    }
    Quad::Quad(Point topL, Point botR)
    {
        n = NULL;
        topLeftTree = NULL;
        topRightTree = NULL;
        botLeftTree = NULL;
        botRightTree = NULL;
        topLeft = topL;
        botRight = botR;
    }
Quad::~Quad()
{
    //dtor
}
void Quad::insert(Node* node)
{
    if (node == NULL)
        return;

    // Current quad cannot contain it
    if (!inBoundary(node->pos))
        return;

    // We are at a quad of unit area
    // We cannot subdivide this quad further
    if (abs(topLeft.x - botRight.x) <= 1
        && abs(topLeft.y - botRight.y) <= 1) {
        if (n == NULL)
            n = node;
        return;
    }

    if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
            if (topLeftTree == NULL)
                topLeftTree = new Quad(
                    Point(topLeft.x, topLeft.y),
                    Point((topLeft.x + botRight.x) / 2,
                          (topLeft.y + botRight.y) / 2));
            topLeftTree->insert(node);
        }

        // Indicates botLeftTree
        else {
            if (botLeftTree == NULL)
                botLeftTree = new Quad(
                    Point(topLeft.x,
                          (topLeft.y + botRight.y) / 2),
                    Point((topLeft.x + botRight.x) / 2,
                          botRight.y));
            botLeftTree->insert(node);
        }
    }
    else {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
            if (topRightTree == NULL)
                topRightTree = new Quad(
                    Point((topLeft.x + botRight.x) / 2,
                          topLeft.y),
                    Point(botRight.x,
                          (topLeft.y + botRight.y) / 2));
            topRightTree->insert(node);
        }

        // Indicates botRightTree
        else {
            if (botRightTree == NULL)
                botRightTree = new Quad(
                    Point((topLeft.x + botRight.x) / 2,
                          (topLeft.y + botRight.y) / 2),
                    Point(botRight.x, botRight.y));
            botRightTree->insert(node);
        }
    }
}

// Find a node in a quadtree
Node* Quad::search(Point p)
{ // Current quad cannot contain it
    if (!inBoundary(p))
        return NULL;

    // We are at a quad of unit length
    // We cannot subdivide this quad further
    if (n != NULL)
        return n;

    if ((topLeft.x + botRight.x) / 2 >= p.x) {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (topLeftTree == NULL)
                return NULL;
            return topLeftTree->search(p);
        }

        // Indicates botLeftTree
        else {
            if (botLeftTree == NULL)
                return NULL;
            return botLeftTree->search(p);
        }
    }
    else {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (topRightTree == NULL)
                return NULL;
            return topRightTree->search(p);
        }

        // Indicates botRightTree
        else {
            if (botRightTree == NULL)
                return NULL;
            return botRightTree->search(p);
        }
    }
};


// Check if current quadtree contains the point
bool Quad::inBoundary(Point p)
{
    return (p.x >= topLeft.x && p.x <= botRight.x
            && p.y >= topLeft.y && p.y <= botRight.y);
}

//// Driver program
//int main()
//{
//    Quad center(Point(0, 0), Point(8, 8));
//    Node a(Point(1, 1), 1);
//    Node b(Point(2, 5), 2);
//    Node c(Point(7, 6), 3);
//    center.insert(&a);
//    center.insert(&b);
//    center.insert(&c);
//    cout << "Node a: " << center.search(Point(1, 1))->data
//         << "\n";
//    cout << "Node b: " << center.search(Point(2, 5))->data
//         << "\n";
//    cout << "Node c: " << center.search(Point(7, 6))->data
//         << "\n";
//    cout << "Non-existing node: "
//         << center.search(Point(5, 5));
//    return 0;
//}
