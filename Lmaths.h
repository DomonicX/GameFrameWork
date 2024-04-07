#ifndef LMATHS_H
#define LMATHS_H

#include <SDL2/SDL.h>
#include <Vector2D.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <random>


#define INFINITY 9999
#define maxX 5

struct PathNode
{
    float F = 0;
    float G = 0;
    float H = 0;
    vec2f pos;
    PathNode * parentNode= NULL;
};

typedef  enum
{
    NW, N, NE,
    W, M, E,
    SW, S, SE,
}  cardinal_Directions;


static int GetRandomNumber()
{
    return rand();
}

static SDL_FRect alignToTilePosition(float x, float y,int TileSize)
{
    return  {(x-(x+0%TileSize)),(y-(y+0%TileSize)),TileSize,TileSize};
}

static SDL_Rect alignToTilePosition(int x,int y,int TileSize)
{
    return  {(x-(x%TileSize)),(y-(y%TileSize)),TileSize,TileSize};
}
static SDL_FPoint vecToSDL_FPoint(vec2f p)
{
    return SDL_FPoint({p.x,p.y});
}

static SDL_Point vecToSDL_Point(vec2f p)
{
    return SDL_Point({(int)p.x,(int)p.y});
}


static vec2f vecToPoint(SDL_Point p)
{
    return vec2f(p.x,p.y);
}

static vec2f vecToPoint(SDL_FPoint p)
{
    return vec2f(p.x,p.y);
}
static vec2f alignToVec2Position(vec2f v,int TileSize)
{
    return  vec2f(v.x-(int)v.x%TileSize,v.y-(int)v.y%TileSize);
}

static std::vector<SDL_Rect> MakeGrid(int x = 0, int y = 0, int rows = 0,int columns = 0,int TileSize = 0)
{
    std::vector<SDL_Rect> r;
//    int TotalRowSize = rows*TileSize;
//    int TotalColumnSize = columns*TileSize;

    for(int i = 0 ; i < columns; i++)
        for(int j = 0 ; j < rows; j++)
        {
            r.push_back({j*TileSize+x,i*TileSize+y,TileSize,TileSize});
        }
    return r;
}

static SDL_FPoint GetRectCentre(rectangle rectangle)
{
    return SDL_FPoint({rectangle.rectTopLeft.x + rectangle.rectBottomRight.x/2,
                       rectangle.rectTopLeft.y+
                       rectangle.rectBottomRight.y/2});
}

static SDL_Rect RectangleToSDLRect(rectangle rectangle)
{
    return SDL_Rect({(int)rectangle.rectTopLeft.x,
                     (int)rectangle.rectTopLeft.y,
                     (int)rectangle.rectBottomRight.x,
                     (int)rectangle.rectBottomRight.y});
}

static vec2f GetSDLRectCenter(SDL_Rect rect)
{
    return vec2f(std::floor(rect.x+rect.w/2),std::floor(rect.y+rect.h/2));
}
static vec2f GetSDLRectFCenter(SDL_FRect rect)
{
    return vec2f(rect.x+rect.w/(float)2,rect.y+rect.h/(float)2);
}
static SDL_Rect GetIntersectRect(SDL_Rect r1, SDL_Rect r2)
{
    SDL_Rect result;
    SDL_IntersectRect(&r1,&r2,&result);
    return result;

}
static SDL_FRect GetIntersectRect(SDL_FRect r1, SDL_FRect r2)
{
    SDL_FRect result;
    SDL_IntersectFRect(&r1,&r2,&result);
    return result;

}
static bool GetIntersectRectF(SDL_FRect r1, SDL_FRect r2)
{

    return SDL_HasIntersectionF(&r1,&r2);

}
static bool GetPointInRectF(SDL_FPoint r1, SDL_FRect r2)
{

    return SDL_PointInFRect(&r1,&r2);

}


static float Getphi(float a,float b)
{
    return  (a + std::sqrt(5))/(float)b;
}


//
//static vec2f CircularMotion(float angle,float orbit_speed,float radius ,float delta_time, vec2f center)
//{
//vec2f p;
//angle += orbit_speed * delta_time;
//p.x = center.x + radius * std::cos(angle);
//p.y = center.y + radius * std::sin(angle);
//return p;
//}

static float GetSimpleHarmonicMotion(float amplitude,float framecount,float period)
{
    return  amplitude *(float) std::sin((framecount/(float)period)*(float)M_PI2);
}

static vec2f ToWorld(vec2f world,vec2f camera)
{
    return world+camera ;
}
static vec2f ToScreen(vec2f world,vec2f camera)
{
    //screen position = world  - camera position.
    return  world-camera;
}

static vec2f GetSDLFRectCenter(SDL_FRect rect)
{
    return vec2f(std::floor(rect.x+rect.w/2),std::floor(rect.y+rect.h/2));
}
static SDL_FPoint GetRectHitPoint(int pIndex,SDL_FRect Rect)
{
    SDL_FRect rect = Rect;

    switch(pIndex)
    {
    case (0):
        return SDL_FPoint({rect.x,rect.y});
        break;
    case (1):
        return SDL_FPoint({rect.x+rect.w/(float)2, rect.y});
        break;
    case (2):
        return SDL_FPoint({rect.x+rect.w, rect.y});
        break;
    case (3):
        return SDL_FPoint({rect.x,rect.y+rect.h/(float)2});
        break;
    case (4):
        return SDL_FPoint({rect.x+rect.w/(float)2,rect.y+rect.h/(float)2});
        break;
    case (5):
        return SDL_FPoint({rect.x+rect.w,rect.y+rect.h/(float)2});
        break;
    case (6):
        return SDL_FPoint({rect.x,rect.y+rect.h});
        break;
    case (7):
        return SDL_FPoint({rect.x+rect.w/(float)2,rect.y+rect.h});
        break;
    case (8):
        return SDL_FPoint({rect.x+rect.w,rect.y+rect.h});
        break;
    default :
        return SDL_FPoint({-1,-1});
        break;
    }

};

static std::vector<SDL_Point> GetSineWave(vec2f position,int wavelength,float amplitude,float frequency,float  time,float  shift)
{
    std::vector<SDL_Point> temp;

    int framecounter = 0;
    for(int i = 0 ; i < wavelength; i+=1)
    {
        float rads = 2.0*M_PI/180;

        float inc = amplitude*std::sin(i*rads*frequency*time+(shift*0.17));
        temp.push_back(SDL_Point{(int)position.x+i,(int)position.y+inc});
    }
    return temp;
}
//Algorithm : Dijkstra’s Shortest Path C++
//
//1.     Initialize the distance from the source node S to all other nodes as infinite (999999999999) and to itself as 0.
//2.    Insert the pair of < distance , node > for source i.e < 0, S > in a priority-based SET [C++]
//       where the priority of the elements in the set is based on the length of the distance.
//3.    While the SET is not empty do
//4.       pair_at_top = SET . top( );
//         Remove the element from the top of the SET.
//         current_source_node = pair_at_top . second.
//5.       For every adjacent_node to current_source_node do
//6.            If ( distance [ adjacent_node ] > length_of_path_to_adjacent_node_from_current_source + distance [ current_source_node ] ) then
//7.                 distance [ adjacent_node ] = length_of_path_to_adjacent_node_from_current_source + distance [ current_source_node ]
//8.                 Update the SET with the new pair < distance [ adjacent_node ], adjacent_node >

static void dijkstra(int G[maxX][maxX],int n,int startnode)
{
    int cost[maxX][maxX],distance[maxX],pred[maxX];
    int visited[maxX],count,mindistance,nextnode,i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0; i<n; i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        for(i=0; i<n; i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    for(i=0; i<n; i++)
        if(i!=startnode)
        {
            std::cout<<"\nDistance of node"<<i<<"="<<distance[i];
            std::cout<<"\nPath="<<i;
            j=i;
            do
            {
                j=pred[j];
                std::cout<<"<-"<<j;
            }
            while(j!=startnode);
        }
}  /*

    function dijkstra(G, S)
        for each vertex V in G
            dist[V] <- infinite
            prev[V] <- NULL
            If V != S, add V to Priority Queue Q
        dist[S] <- 0

        while Q IS NOT EMPTY
            U <- Extract MIN from Q
            for each unvisited neighbour V of U
                temperoryDist <- dist[U] + edgeWeight(U, V)
                if temperoryDist < dist[V]
                    dist[V] <- temperoryDist
                    prev[V] <- U
        return dist[], prev[]
*/

static std::vector<vec2f> Findpath(vec2f* G,int Gsize,vec2f StartNode,vec2f S,int Row,int TileSize)
{
    int* prev[Gsize];
    int* dist[Gsize];
    std::vector<vec2f>Q;
    for(int V = 0; V < Gsize; V++)
    {
        *dist[V] = INT_MAX;
        prev[V] = NULL;
        if(S!=G[V])
            Q.push_back(G[V]);

    }
    dist[StartNode.GetArrayIndex(Row,TileSize)] = 0;
    while(!Q.empty())
    {

        vec2f smallest = Q[0];
        int smallestindex = 0;
        for(int V = 0 ; V < Q.size(); V++)
        {
            if(smallest.Length() >= Q[V].Length())
            {

                smallest = Q[V];
                smallestindex = V;
            }
        }

        auto u = smallest;

        Q.erase(Q.begin()+smallestindex);

        vec2f M = u;



        {

            int temperoryDist = 0;
            int g = M.GetArrayIndex(Row,TileSize);
            temperoryDist = g;
            + vec2f::Dist(M,u);
            if(temperoryDist < *dist[g])
            {
                *dist[g] = temperoryDist;
                *prev[g] = M.GetArrayIndex(Row,TileSize);
            }

        }
        vec2f N = vec2f(u.x,u.y-TileSize);
        {

            int temperoryDist = 0;
            int g = N.GetArrayIndex(Row,TileSize);
            temperoryDist = g;
            + vec2f::Dist(N,S);
            if(temperoryDist < *dist[g])
            {
                *dist[g] = temperoryDist;
                *prev[g] = N.GetArrayIndex(Row,TileSize);
            }

        }
        vec2f E = vec2f(u.x+TileSize,u.y);

        {

            int temperoryDist = 0;
            int g = E.GetArrayIndex(Row,TileSize);
            temperoryDist = g;
            + vec2f::Dist(E,S);
            if(temperoryDist < *dist[g])
            {
                *dist[g] = temperoryDist;
                *prev[g] = E.GetArrayIndex(Row,TileSize);
            }

        }
        vec2f s = vec2f(u.x,u.y+TileSize);

        {

            int temperoryDist = 0;
            int g = s.GetArrayIndex(Row,TileSize);
            temperoryDist = g;
            + vec2f::Dist(u,S);
            if(temperoryDist < *dist[g])
            {
                *dist[g] = temperoryDist;
                *prev[g] = s.GetArrayIndex(Row,TileSize);
            }

        }
        vec2f W = vec2f(u.x-TileSize,u.y);

        {

            int temperoryDist = 0;
            int g = W.GetArrayIndex(Row,TileSize);
            temperoryDist = g;
            + vec2f::Dist(W,S);
            if(temperoryDist < *dist[g])
            {
                *dist[g] = temperoryDist;
                *prev[g] = W.GetArrayIndex(Row,TileSize);
            }

        }
    }
    size_t size1 = sizeof(dist) / sizeof(dist[0]);

    for(int i = 0 ; i <size1; i++)
    {

    }
    return Q;
}

static std::vector<vec2f> FindPath2(  vec2f Target, vec2f Start, int TileSize)
{
    std::vector<vec2f> path;
    double smallestF = INT_MAX;
    vec2f c = Target-Start;
    std::cout << c <<"\n";
    if(c.Length()/TileSize>0)
    {

        for(int i = 0; i < (c.Length()/TileSize); i++)
        {

            path.push_back(    c.GetNormalise() * (TileSize*i));
        }
    }
//path.push_back(Start);
//path.push_back(Target);

    return path;
}




auto ForwardToTestFunc = []<typename ...T>(T&& ...args)
{
    return TestFunc(std::forward<T>(args)...); // we have all the types!
};



static std::vector<SDL_FPoint> FindPath3(  vec2f Target, vec2f Start, int TileSize)
{
    std::vector<SDL_FPoint> path;
    for(int i = 0; i < ( vec2f::Dist(Start,Target)/(int)TileSize); i++)
        path.push_back({vec2f(vec2f(Target-Start).GetNormalise() *(float) (TileSize*(float)i)).x+Start.x,
                        vec2f(vec2f(Target-Start).GetNormalise() *(float) (TileSize*(float)i)).y+Start.y});
    return path;
}

//
//auto lam = [](vec2f x)
//{
//    return x;
//};
//const auto foo = [](auto x)
//{
//    std::cout << x << '\n';
//};
//
//
//
//




//} vec2f(Target-Start).Length())
//  {x
//      x/(float)TileSize;
//   for(int i = 0; i <= x ; i++
//
//  auto lam = [](float x){
//    for(int i = 0; i <= ( vec2f( Target-Start).Length()/(float)TileSize); i++)
//    return x * 1.1; };
//
//}
//

static std::vector<vec2f> FindPath( vec2f* tiles,int Count, vec2f Target, vec2f Start, int TileSize)
{
    double smallestF = INT_MAX;
    vec2f* Tiles = &tiles[0];
//   std::vector<vec2f> closedSet;
    std::vector<vec2f> openSet;
    std::vector<vec2f> openSetF;

    std::vector<bool> closedSet;

    std::vector<vec2f> PathNode;




    float h = 0;
    float f = INT_MAX;
    float g = 0;

    vec2f s =Start;
    vec2f* currentPos =&s;
    vec2f e = Target;
    for(int i = 0; i < Count; i++)
        if(Tiles[i]!=s)
        {
            closedSet[i] = false;
//    openSet.push_back(tiles[i]);
//    openSet.back() = vec2f(INT_MAX,INT_MAX);
        }
    if(e==s)
    {
        return PathNode;
    }
//
    openSet.push_back(*currentPos);

//    while(!openSet.empty())
//    {
//
//        double smallestF = FLT_MAX;
//        for( int i = 0; i<openList.size(); ++i)
//        {
//            if(openSetF[i]->F < smallestF)
//            {
//                smallestF = openSetF[i]->F;
//                smallestFindexer = smallestF;
//                curNode = openList[i];
//            }
//        }
//
//    vec2f N,E,S,W;

// what i want /
// pacman
// cornering
// pathfinding
//
//        float GridIndexX = currentPos.x;
//        float GridIndexY = currentPos.y;
//
//        vec2f M  = vec2f(GridIndexX,GridIndexY);
//
//        TileSize
//        N = vec2f(m.x,          m.y-TileSize);
//        E = vec2f(m.x+TileSize, m.y);
//        S = vec2f(m.x,          m.y+TileSize);
//        W = vec2f(m.x-TileSize, m.y);
//
//        vec2f M  = vec2f(GridIndexX,GridIndexY);
////
////        /1.4142135623730950488016887242097
////
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
//                if(openSetF[N.GetArrayIndex(ROWS)].F == FLT_MAX
//                        || openSetF[N.GetArrayIndex(ROWS)].F > F)
//                {
//                    gridNode[N.GetArrayIndex(ROWS)].G = G;
//                    gridNode[N.GetArrayIndex(ROWS)].H = H;
//                    openSetF[N.GetArrayIndex(ROWS)].F = F;
//                    gridNode[N.GetArrayIndex(ROWS)].parentNode = curNode;
//
//                    std::cout << "\n" << std::endl;
//                    Node *Nnode = new Node(N,*curNode,G,H,F);
//                    openList.push_back(std::move(Nnode));
//                    Nnode = NULL;
//                }
//            }
//        }
//
////currentPos->x
//
//
//    }
//
//    }
//
}
//
//
//
//    PathNode.clear();
//    std::vector<vec2f*>openList;
//    bool closedList[COLS][ROWS],foundDest;
//    float F,G,H;
//    vec2f startVec,targetVec,  *currentPos = nullptr;
//
//    foundDest = false;
//    currentPos = &startVec;
//
//
//    start->ChangeType(CELL_STATE::START);
//    target->ChangeType(CELL_STATE::END);
//    startVec  = vec2f( start->pos.x,start->pos.y );
//    targetVec  = vec2f( target->pos.x,target->pos.y );
//
//    for(int i = 0; i<COLS; ++i)
//        for(int j = 0; j<ROWS; ++j)
//            closedList[i][j] = false;
//
//    openList.push_back(std::move(currentPos));
//    while(!openList.empty())
//    {
//        openList.pop_back();
//
//    }
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
//        /1.4142135623730950488016887242097
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
//
//
//
//
//
//
//
//
//
//
//}
/**<

void PathFinderAstar::FindPath( std::vector<Node*> Path,Node *start, Node* target,int ROWS,int COLS,int TileSize)

{

    //vec2f *currentPos;

    PathNode.clear();
    std::vector<vec2f*>openList;
    bool closedList[COLS][ROWS],foundDest;
    float F,G,H;
    vec2f startVec,targetVec,  *currentPos = nullptr;

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
static std::vector<SDL_Rect> MakeGrid(int rows,int columns,int TileSize)
{
    std::vector<SDL_Rect> r;
    int TotalRowSize = rows*TileSize;
    int TotalColumnSize = columns*TileSize;

    for(int i = 0 ; i < rows; i++)
        for(int j = 0 ; j < columns; j++)
        {
            r.push_back({j*TileSize,i*TileSize,TileSize,TileSize});
        }
    return r;
}
 */

class Lmaths
{
public:
    Lmaths();
    virtual ~Lmaths();

protected:

private:
};

#endif // LMATHS_H
