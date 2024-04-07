#include "PathFinderAstar.h"

PathFinderAstar::PathFinderAstar()
{
    //ctor
}

PathFinderAstar::~PathFinderAstar()
{
    //dtor
}


void PathFinderAstar::FindPath( std::vector<Node*> Path,Node *start, Node* target,int ROWS,int COLS,int TileSize)

{
    PathNode.clear();
    std::vector<vec2f*>openList;
    bool closedList[COLS][ROWS],foundDest;
    float F,G,H;
    vec2f startVec,targetVec,  *currentPos = nullptr;

    //vec2f *currentPos;
    foundDest = false;
    currentPos = &startVec;


    start->ChangeType(CELL_STATE::START);
    target->ChangeType(CELL_STATE::END);
    startVec  = vec2f( start->pos.x,start->pos.y );
    targetVec  = vec2f( target->pos.x,target->pos.y );

    for(int i = 0; i<COLS; ++i)
        for(int j = 0; j<ROWS; ++j)
            closedList[i][j] = false;

    openList.push_back(std::move(currentPos));
    while(!openList.empty())
    {
        openList.pop_back();

    }

//    Path[1]->ChangeType(Node::OPEN);
//Path[2]->ChangeType(Node::OPEN);
//Path[3]->ChangeType(Node::OPEN);



}

//
//    std::cout <<TileSize<< " TileSize \n ";
//    std::cout <<COLS<< " COLS \n ";
//    std::cout <<ROWS<< " ROWS \n ";
//    std::cout  << "start "<< start->pos.x << " :   " << start->pos.y << " y\n ";
//    std::cout  << "target "<< target->pos.x << " :   " << target->pos.y << " y\n ";
//    std::cout  << "target " << Path.size() << "\n";
//

//Path[Path.size()/2]->ChangeType(Node::START);

//curNode->F = 0;
// curNode->G = 0;
// curNode->H = 0;
// curNode->parentNode = NULL;



//   delete openList.back();
//
//return ((double)sqrt ((row-dest.first)*(row-dest.first)
//                   + (col-dest.second)*(col-dest.second)));
//
//


void PathFinderAstar::UpDate()
{
    switch (currentState)
    {
    case NO_ACTION:
        break;
    case UPDATING:
        break;

    }
}
//}
//
//
//
//        double smallestF = FLT_MAX;
//        for( int i = 0; i<openList.size(); ++i)
//        {
//            if(openList[i]->F < smallestF)
//            {
//                smallestF = openList[i]->F;
//                smallestFindexer = smallestF;
//                curNode = openList[i];
//            }
//        }
//        float GridIndexX = curNode->pos.x;
//        float GridIndexY = curNode->pos.y;
//
//
//
//        vec2f M  = vec2f(GridIndexX,GridIndexY);
//
//        ///1.4142135623730950488016887242097
//
//        vec2f    N  = vec2f(  GridIndexX,GridIndexY- TileSize);
//        if(target->pos == N && foundDest == false)
//        {
//            std::cout << " north GOAL FOUND" << std::endl;
//            foundDest = true;
//            gridNode[N.GetArrayIndex(ROWS)].parentNode = curNode;
//        }
//        else if(N.x >= 0 && N.x < (ROWS)*TileSize
//                && N.y >= 0 && N.y < (COLS)*TileSize)
//        {
//            if(gridNode[N.GetArrayIndex(ROWS)].currentState==Node::SOLID |
//                    gridNode[N.GetArrayIndex(ROWS)].currentState==Node::CLOSED|
//                    gridNode[N.GetArrayIndex(ROWS)].currentState==Node::START)
//            {}
//            else
//            {
//                G = 10 + curNode->G;
//                H =  target->pos.Dist(N)  ;
//                F = abs(G + H);
//                if(gridNode[N.GetArrayIndex(ROWS)].F == FLT_MAX
//                        || gridNode[N.GetArrayIndex(ROWS)].F > F)
//                {
//                    gridNode[N.GetArrayIndex(ROWS)].G = G;
//                    gridNode[N.GetArrayIndex(ROWS)].H = H;
//                    gridNode[N.GetArrayIndex(ROWS)].F = F;
//                    gridNode[N.GetArrayIndex(ROWS)].parentNode = curNode;
//
//                    std::cout << "N H cost /"<< (int)gridNode[N.GetArrayIndex(ROWS)].H << std::endl;
//                    std::cout << "N G cost /"<< (int)gridNode[N.GetArrayIndex(ROWS)].G << std::endl;
//                    std::cout << "N F cost /"<< (int)gridNode[N.GetArrayIndex(ROWS)].F << std::endl;
//                    std::cout << "\n" << std::endl;
//                    Node *Nnode = new Node(N,*curNode,G,H,F);
//                    openList.push_back(std::move(Nnode));
//                    Nnode = NULL;
//                }
//            }
//        }
//
////-------------------------------------------------------------------------------------------------
//
//        vec2f    W  = vec2f(GridIndexX - TileSize,GridIndexY);
//        if(target->pos == W && foundDest == false )
//        {
//            std::cout << "West GOAL FOUND" << std::endl;
//
//            foundDest = true;
////                return  &gridNode[W.GetArrayIndex(node_ROWS)];
//            gridNode[W.GetArrayIndex(ROWS)].parentNode = curNode;
//
//        }
//        else
//
////1.4142135623730950488016887242097
//            if(W.x >= 0 && W.x < (ROWS)*TileSize
//                    && W.y >= 0 && W.y < (COLS)*TileSize)
//            {
//                if(gridNode[W.GetArrayIndex(ROWS)].currentState == Node::SOLID |
//                        gridNode[W.GetArrayIndex(ROWS)].currentState == Node::CLOSED|
//                        gridNode[W.GetArrayIndex(ROWS)].currentState==Node::START)
//                {}
//                else
//                {
//                    G = 10 + curNode->G;
//                    H =  target->pos.Dist(W)  ;
//                    F = abs(G + H);
//                    //F = G + H;
//
//                    if(gridNode[W.GetArrayIndex(ROWS)].F == FLT_MAX
//                            || gridNode[W.GetArrayIndex(ROWS)].F > F)
//                    {
//                        gridNode[W.GetArrayIndex(ROWS)].G = G;
//                        gridNode[W.GetArrayIndex(ROWS)].H = H;
//                        gridNode[W.GetArrayIndex(ROWS)].F = F;
//                        gridNode[W.GetArrayIndex(ROWS)].parentNode = curNode;
//                        std::cout << "W H cost /"<< (int)gridNode[W.GetArrayIndex(ROWS)].H << std::endl;
//                        std::cout << "W G cost /"<< (int)gridNode[W.GetArrayIndex(ROWS)].G << std::endl;
//                        std::cout << "W F cost /"<< (int)gridNode[W.GetArrayIndex(ROWS)].F << std::endl;
//                        std::cout << "\n" << std::endl;
//                        Node *Wnode = new Node(W,*curNode,G,H,F);
//                        openList.push_back(std::move(Wnode));
//                        Wnode = NULL;
//                    }
//                }
//
//            }
//
//
////-------------------------------------------------------------------------------------------------
//
//        vec2f    E  = vec2f(GridIndexX + TileSize,GridIndexY);
//
//
//        if(target->pos == E && foundDest == false)
//        {
//            std::cout << "East GOAL FOUND" << std::endl;
//
//            foundDest = true;
////        return  &gridNode[E.GetArrayIndex(node_ROWS)];
//            gridNode[E.GetArrayIndex(ROWS)].parentNode = curNode;
//
//        }
//        else if(E.x >= 0 && E.x < (ROWS)*TileSize
//                && E.y >= 0 && E.y < (COLS)*TileSize)
//        {
//
//            if(gridNode[E.GetArrayIndex(ROWS)].currentState == Node::SOLID |
//                    gridNode[E.GetArrayIndex(ROWS)].currentState == Node::CLOSED|
//                    gridNode[E.GetArrayIndex(ROWS)].currentState==Node::START)
//            {}
//            else
//            {
//                G = 10 + curNode->G;
//                H =  target->pos.Dist(E)  ;
//                F = abs(G + H);
//                //F = G + H;
//
//                if(gridNode[E.GetArrayIndex(ROWS)].F == FLT_MAX
//                        | gridNode[E.GetArrayIndex(ROWS)].F > F)
//                {
//                    gridNode[E.GetArrayIndex(ROWS)].G = G;
//                    gridNode[E.GetArrayIndex(ROWS)].H = H;
//                    gridNode[E.GetArrayIndex(ROWS)].F = F;
//                    gridNode[E.GetArrayIndex(ROWS)].parentNode = curNode;
//                    std::cout << "E H cost /"<< (int)gridNode[E.GetArrayIndex(ROWS)].H << std::endl;
//                    std::cout << "E G cost /"<< (int)gridNode[E.GetArrayIndex(ROWS)].G << std::endl;
//                    std::cout << "E F cost /"<< (int)gridNode[E.GetArrayIndex(ROWS)].F << std::endl;
//                    std::cout << "\n" << std::endl;
//                    Node *Enode = new Node(E,*curNode,G,H,F);
//                    openList.push_back(std::move(Enode));
//                    Enode = NULL;
//
//                }
//            }
//
//        }
//
//
////-------------------------------------------------------------------------------------------------
//
//
//        vec2f    S  = vec2f(GridIndexX,GridIndexY + TileSize );
//
//        if(target->pos == S && foundDest == false)
//        {
//            std::cout << "south GOAL FOUND" << std::endl;
//            foundDest = true;
////        return  &gridNode[S.GetArrayIndex(node_ROWS)];
//            gridNode[S.GetArrayIndex(ROWS)].parentNode = curNode;
//
//        }
//        else if(S.x >= 0 && S.x < (ROWS)*TileSize
//                && S.y >= 0 && S.y <(COLS)*TileSize)
//        {
//            if(gridNode[S.GetArrayIndex(ROWS)].currentState == Node::SOLID |
//                    gridNode[S.GetArrayIndex(ROWS)].currentState == Node::CLOSED|
//                    gridNode[S.GetArrayIndex(ROWS)].currentState==Node::START)
//            {}
//            else
//            {
//
//                G = 10 + curNode->G;
//                H = target->pos.Dist(S)  ;
//                F = abs(G + H);
//                //F = G + H;
//
//                if(gridNode[S.GetArrayIndex(ROWS)].F == FLT_MAX
//                        | gridNode[S.GetArrayIndex(ROWS)].F > F)
//                {
//                    gridNode[S.GetArrayIndex(ROWS)].G = G;
//                    gridNode[S.GetArrayIndex(ROWS)].H = H;
//                    gridNode[S.GetArrayIndex(ROWS)].F = F;
//                    gridNode[S.GetArrayIndex(ROWS)].parentNode = curNode;
//                    std::cout << "S H cost /"<< (int)gridNode[S.GetArrayIndex(ROWS)].H << std::endl;
//                    std::cout << "S G cost /"<< (int)gridNode[S.GetArrayIndex(ROWS)].G << std::endl;
//                    std::cout << "S F cost /"<< (int)gridNode[S.GetArrayIndex(ROWS)].F << std::endl;
//                    std::cout << "\n" << std::endl;
//                    Node *Snode = new Node(S,*curNode,G,H,F);
//                    openList.push_back(std::move(Snode));
//                    Snode = NULL;
//
//                }
//            }
//
//        }
//
//
//
//        if(isDiagonal)
//        {
//            if(gridNode[N.GetArrayIndex(ROWS)].currentState==Node::SOLID &&
//                    gridNode[W.GetArrayIndex(ROWS)].currentState==Node::SOLID && !isCrossCorner)
//            {}
//            else
//            {
//                vec2f    NW = vec2f(  GridIndexX  - TileSize,  GridIndexY- TileSize);
//                if(target->pos == NW && foundDest == false)
//                {
//                    std::cout << " north-west GOAL FOUND" << std::endl;
//                    foundDest = true;
//                    gridNode[NW.GetArrayIndex(ROWS)].parentNode = curNode;
//                }
//                else if(NW.x >= 0 && NW.x < (ROWS)*TileSize
//                        && NW.y >= 0 && NW.y < (COLS)*TileSize)
//                {
//                    if(gridNode[NW.GetArrayIndex(ROWS)].currentState==Node::SOLID |
//                            gridNode[NW.GetArrayIndex(ROWS)].currentState==Node::CLOSED|
//                            gridNode[NW.GetArrayIndex(ROWS)].currentState==Node::START)
//                    {}
//                    else
//                    {
//                        G = 14+ curNode->G;
//                        H =  target->pos.Dist(NW)  ;
//                        F = abs(G + H);
//                        if(gridNode[NW.GetArrayIndex(ROWS)].F == FLT_MAX
//                                || gridNode[NW.GetArrayIndex(ROWS)].F > F)
//                        {
//                            gridNode[NW.GetArrayIndex(ROWS)].G = G;
//                            gridNode[NW.GetArrayIndex(ROWS)].H = H;
//                            gridNode[NW.GetArrayIndex(ROWS)].F = F;
//                            gridNode[NW.GetArrayIndex(ROWS)].parentNode = curNode;
//
//                            std::cout << "NW H cost /"<< (int)gridNode[NW.GetArrayIndex(ROWS)].H << std::endl;
//                            std::cout << "NW G cost /"<< (int)gridNode[NW.GetArrayIndex(ROWS)].G << std::endl;
//                            std::cout << "NW F cost /"<< (int)gridNode[NW.GetArrayIndex(ROWS)].F << std::endl;
//
//                            Node *NWnode = new Node(NW,*curNode,G,H,F);
//                            openList.push_back(std::move(NWnode));
//                            NWnode = NULL;
//                        }
//                    }
//                }
//            }
////-------------------------------------------------------------------------------------------------
////-------------------------------------------------------------------------------------------------
//
//
//            if(gridNode[N.GetArrayIndex(ROWS)].currentState==Node::SOLID &&
//                    gridNode[E.GetArrayIndex(ROWS)].currentState==Node::SOLID && !isCrossCorner)
//            {}
//            else
//            {
//                vec2f    NE = vec2f(  GridIndexX + TileSize,  GridIndexY - TileSize);
//
//                if(target->pos == NE && foundDest == false)
//                {
//                    std::cout << " north-east GOAL FOUND" << std::endl;
//                    foundDest = true;
//                    gridNode[NE.GetArrayIndex(ROWS)].parentNode = curNode;
//                }
//                else if(NE.x >= 0 && NE.x < (ROWS)*TileSize
//                        && NE.y >= 0 && NE.y < (COLS)*TileSize)
//                {
//                    if(gridNode[NE.GetArrayIndex(ROWS)].currentState==Node::SOLID |
//                            gridNode[NE.GetArrayIndex(ROWS)].currentState==Node::CLOSED|
//                            gridNode[NE.GetArrayIndex(ROWS)].currentState==Node::START)
//                    {}
//                    else
//                    {
//                        G = 14+ curNode->G;
//                        H =  target->pos.Dist(NE)  ;
//                        F = abs(G + H);
//                        if(gridNode[NE.GetArrayIndex(ROWS)].F == FLT_MAX
//                                || gridNode[NE.GetArrayIndex(ROWS)].F > F)
//                        {
//                            gridNode[NE.GetArrayIndex(ROWS)].G = G;
//                            gridNode[NE.GetArrayIndex(ROWS)].H = H;
//                            gridNode[NE.GetArrayIndex(ROWS)].F = F;
//                            gridNode[NE.GetArrayIndex(ROWS)].parentNode = curNode;
//
//                            std::cout << "NE H cost /"<< (int)gridNode[NE.GetArrayIndex(ROWS)].H << std::endl;
//                            std::cout << "NE G cost /"<< (int)gridNode[NE.GetArrayIndex(ROWS)].G << std::endl;
//                            std::cout << "NE F cost /"<< (int)gridNode[NE.GetArrayIndex(ROWS)].F << std::endl;
//                            Node *NEnode = new Node(NE,*curNode,G,H,F);
//                            openList.push_back(std::move(NEnode));
//                            NEnode = NULL;
//                        }
//                    }
//                }
//            }
////-------------------------------------------------------------------------------------------------
//
//
////-------------------------------------------------------------------------------------------------
//
//            if(gridNode[W.GetArrayIndex(ROWS)].currentState==Node::SOLID &&
//                    gridNode[S.GetArrayIndex(ROWS)].currentState==Node::SOLID && !isCrossCorner)
//            {}
//            else
//            {
//                vec2f    SW = vec2f(GridIndexX - TileSize,GridIndexY + TileSize);
//
//                if(target->pos == SW && foundDest == false)
//                {
//                    std::cout << " SOUTH-west GOAL FOUND" << std::endl;
//                    foundDest = true;
//                    gridNode[SW.GetArrayIndex(ROWS)].parentNode = curNode;
//                }
//                else if(SW.x >= 0 && SW.x < (ROWS)*TileSize
//                        && SW.y >= 0 && SW.y < (COLS)*TileSize)
//                {
//                    if(gridNode[SW.GetArrayIndex(ROWS)].currentState==Node::SOLID |
//                            gridNode[SW.GetArrayIndex(ROWS)].currentState==Node::CLOSED|
//                            gridNode[SW.GetArrayIndex(ROWS)].currentState==Node::START)
//                    {}
//                    else
//                    {
//                        G = 14+ curNode->G;
//                        H =  target->pos.Dist(SW)  ;
//                        F = abs(G + H);
//                        if(gridNode[SW.GetArrayIndex(ROWS)].F == FLT_MAX
//                                || gridNode[SW.GetArrayIndex(ROWS)].F > F)
//                        {
//                            gridNode[SW.GetArrayIndex(ROWS)].G = G;
//                            gridNode[SW.GetArrayIndex(ROWS)].H = H;
//                            gridNode[SW.GetArrayIndex(ROWS)].F = F;
//                            gridNode[SW.GetArrayIndex(ROWS)].parentNode = curNode;
//
//                            std::cout << "SW H cost /"<< (int)gridNode[SW.GetArrayIndex(ROWS)].H << std::endl;
//                            std::cout << "SW G cost /"<< (int)gridNode[SW.GetArrayIndex(ROWS)].G << std::endl;
//                            std::cout << "SW F cost /"<< (int)gridNode[SW.GetArrayIndex(ROWS)].F << std::endl;
//
//                            Node *SWnode = new Node(SW,*curNode,G,H,F);
//                            openList.push_back(std::move(SWnode));
//                            SWnode = NULL;
//                        }
//                    }
//                }
//            }
////-------------------------------------------------------------------------------------------------
////-------------------------------------------------------------------------------------------------
//
//
//
//            if(gridNode[S.GetArrayIndex(ROWS)].currentState==Node::SOLID &&
//                    gridNode[E.GetArrayIndex(ROWS)].currentState==Node::SOLID && !isCrossCorner)
//            {}
//            else
//
//            {
//                vec2f    SE = vec2f(GridIndexX + TileSize,GridIndexY + TileSize);
//
//                if(target->pos == SE && foundDest == false)
//                {
//                    std::cout << " south-east GOAL FOUND" << std::endl;
//                    foundDest = true;
//                    gridNode[SE.GetArrayIndex(ROWS)].parentNode = curNode;
//                }
//                else if(SE.x >= 0 && SE.x < (ROWS)*TileSize
//                        && SE.y >= 0 && SE.y < (COLS)*TileSize)
//                {
//                    if(gridNode[SE.GetArrayIndex(ROWS)].currentState==Node::SOLID |
//                            gridNode[SE.GetArrayIndex(ROWS)].currentState==Node::CLOSED|
//                            gridNode[SE.GetArrayIndex(ROWS)].currentState==Node::START)
//                    {}
//                    else
//                    {
//                        G = 14+ curNode->G;
//                        H =  target->pos.Dist(SE)  ;
//                        F = abs(G + H);
//                        if(gridNode[SE.GetArrayIndex(ROWS)].F == FLT_MAX
//                                || gridNode[SE.GetArrayIndex(ROWS)].F > F)
//                        {
//                            gridNode[SE.GetArrayIndex(ROWS)].G = FLT_MAX;
//                            gridNode[SE.GetArrayIndex(ROWS)].H = FLT_MAX;
//                            gridNode[SE.GetArrayIndex(ROWS)].F = FLT_MAX;
//                            gridNode[SE.GetArrayIndex(ROWS)].parentNode = curNode;
//
//                            std::cout << "SE H cost /"<< (int)gridNode[SE.GetArrayIndex(ROWS)].H << std::endl;
//                            std::cout << "SE G cost /"<< (int)gridNode[SE.GetArrayIndex(ROWS)].G << std::endl;
//                            std::cout << "SE F cost /"<< (int)gridNode[SE.GetArrayIndex(ROWS)].F << std::endl;
//
//                            Node *SEnode = new Node(SE,*curNode,G,H,F);
//                            openList.push_back(std::move(SEnode));
//                            SEnode = NULL;
//                        }
//                    }
//                }
//            }
//        }
////-------------------------------------------------------------------------------------------------
//
//        curNode->ChangeType(Node::CLOSED);
//
//        for(int v = 0; v<openList.size(); ++v)
//        {
//            if(openList[v]->currentState==Node::CLOSED)
//            {
//
//                openList.erase(openList.begin() + v) ;
//            }
//        }
//        if(foundDest==true)
//        {
//            std::cout << "openlist number "<< openList.size()<< std::endl;
//            for(int i = 0; i<COLS*ROWS; ++i)
//            {
//                if(gridNode[i].currentState==Node::CLOSED ||  gridNode[i].currentState==Node::OPEN)
//                {
//                    std::cout << "found a closed or open grid node must fix " << std::endl;
//                }
//            }
//            Node *tempPathNode = NULL;
//            tempPathNode = &gridNode[target->pos.GetArrayIndex(ROWS)];
//            while(tempPathNode->parentNode!=NULL)
//            {
//                std::cout << "WHile PAth node check"<< std::endl;
////Node *tempNode = new Node(tempNode);
//                //tempPathNode->ChangeType(Node::PATH);
//                tempPathNode = tempPathNode->parentNode;
//                PathNode.push_back(tempPathNode);
//            }
//            std::reverse(PathNode.begin(),PathNode.end());
////PathNode[1]->ChangeType(Node::PATH);
//            PathNode.push_back(target);
//            for(int i = 0; i<COLS*ROWS; ++i)
//            {
//                if(gridNode[i].currentState!=Node::SOLID)
//                {
//
//                    gridNode[i].ChangeType(Node::EMPTY);
//                    gridNode[i].F = FLT_MAX;
//                    gridNode[i].G = FLT_MAX;
//                    gridNode[i].H = FLT_MAX;
//                    gridNode[i].parentNode = NULL;
//                }
//            }
//
//            for(int i = 0; i<COLS*ROWS; ++i)
//            {
//
//                if(gridNode[i].currentState==Node::EMPTY && gridNode->F!=FLT_MAX)
//                {
//
//                }
//
//            }
//            break;
//        }
//    }
//}
