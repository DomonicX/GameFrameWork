#ifndef LQAUDTREE_H
#define LQAUDTREE_H

#include <GameObject.h>
#include <InputHandler.h>
#include <Node.h>
#include <Vector2D.h>
#include <vector>

typedef enum {nw,ne,sw,se}  qaudTreeSubBox;
class LQaudTree
{
public:
    LQaudTree();
    LQaudTree(rectangle box)
    {
m_topLeft = box.rectTopLeft;
m_botRight =box.rectBottomRight;
    }
    virtual ~LQaudTree();
bool PointInFRect(vec2f p);
bool PointInRect(vec2f p);
void Insert(Node *n);
protected:

private:
 vec2f m_topLeft;
    vec2f m_botRight;

    // Contains details of node
    Node* m_n;

    // Children of this tree
    LQaudTree* m_topLeftTree;
    LQaudTree* m_topRightTree;
    LQaudTree* m_botLeftTree;
    LQaudTree* m_botRightTree;


};

#endif // LQAUDTREE_H
