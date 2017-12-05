/*图的临接表储存表示与深度优先遍历*/
#include "main2.h"
#include <iostream>

using namespace std;

int LocateVex(ALGraph G, VertexType v);
void CreateUDG(ALGraph * G);
void DFSTraverse(ALGraph G);
void DFS(ALGraph G, int v);

/*构造图的数据*/
const int gVexnum = 9;
const int gArcnum = 15;
typedef struct Lines{
    VertexType start;
    VertexType end;
}Lines;
VertexType inputV[gVexnum] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
Lines inputL[gArcnum] = {{'A', 'I'}, {'A', 'H'}, {'A', 'B'},
                         {'A', 'C'}, {'B', 'C'}, {'C', 'D'},
                         {'C', 'E'}, {'C', 'G'}, {'D', 'E'},
                         {'D', 'F'}, {'E', 'G'}, {'E', 'F'},
                         {'G', 'H'}, {'H', 'I'}, {'F', 'I'}};
/*End*/

/*visited数组*/
bool visited[gVexnum] = {0};

int main()
{
    ALGraph * G = new ALGraph;
    CreateUDG(G);
    DFSTraverse(*G);
    cout << endl;
    return 0;
}

int LocateVex(ALGraph G, VertexType v)
{
    for(int i = 0; i < gVexnum; i++){
        if(G.vertices[i].data == v){
            return i;
        }
    }
    return -1;
}
/*使用全局变量构造图*/
void CreateUDG(ALGraph * G)
{
    for(int i = 0; i < gVexnum; i++){
        G->vertices[i].data = inputV[i];
        G->vertices[i].firstarc = NULL;
    }
    for(int j = 0; j < G->arcnum; j++){
        int start  = LocateVex(*G, inputL[j].start);
        int end = LocateVex(*G, inputL[j].end);
        
        ArcNode * pi = new ArcNode;
        pi -> adjvex = end;
        pi -> nextarc = G->vertices[start].firstarc;
        G->vertices[start].firstarc = pi;

        ArcNode * pj = new ArcNode;
        pj -> adjvex = start;
        pj -> nextarc = G->vertices[end].firstarc;
        G->vertices[end].firstarc = pj;
    }
}
void DFSTraverse(ALGraph G)
{
    for(int v = 0; v < gVexnum; v++){
        if(!visited[v]){
            DFS(G, v);
        }
    }
}
void DFS(ALGraph G, int v)
{
    visited[v] = true;
    cout << G.vertices[v].data <<  " ";
    for(ArcNode* p = G.vertices[v].firstarc; p; p = p->nextarc) {
       int w = p->adjvex;
       if(!visited[w]){
           DFS(G, w);
       }
    }
}
