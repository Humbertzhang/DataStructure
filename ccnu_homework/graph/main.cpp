#include <iostream>
#include "main.h"

using namespace std;

/*Global Input Data*/
const int gVexnum = 9;
const int gArcnum = 15;
typedef struct Lines{
    VertexType start;
    VertexType end;
    VRType val;
}Lines;
VertexType inputV[gVexnum] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
Lines inputL[gArcnum] = {{'A', 'I', 18.2}, {'A', 'H', 12.1}, {'A', 'B', 32.8},
                {'A', 'C', 44.6}, {'B', 'C', 5.9}, {'C', 'D', 21.3},
                {'C', 'E', 41.1}, {'C', 'G', 56.4}, {'D', 'E', 67.3},
                {'D', 'F', 98.7}, {'E', 'G', 10.5}, {'E', 'F', 85.6},
                {'G', 'H', 52.5}, {'H', 'I', 8.7}, {'F', 'I', 79.2}};

/*End Global input data*/

/****************func area***************/
void CreateGraph(MGraph * g);
void DFSTraverse(MGraph g);
void DFS(MGraph g, int v);

/****************end func***************/

bool visited[gVexnum];

int main() {
    MGraph* g = new MGraph;
    CreateGraph(g);
    DFSTraverse(*g);
    return 0;
}

void CreateGraph(MGraph * g)
{
    g -> vexnum = gVexnum;
    g -> arcnum = gArcnum;
    for(int i = 0; i < g->vexnum; i++){
        g->vexs[i] = inputV[i];
    }
    for(int j = 0; j < g->arcnum; j++){
        int vtail = inputL[j].start;
        int vhead = inputL[j].end;
        VRType weight = inputL[j].val;
        g->arcs[vtail - 'A'][vhead - 'A'].adj = weight;
        g->arcs[vhead - 'A'][vtail - 'A'].adj = weight;
    }
}

void DFSTraverse(MGraph g)
{
    for(int i = 0; i < gVexnum; i++){
        if(!visited[i]){
            DFS(g, i);
        }
    }
}

void DFS(MGraph g, int v)
{
    visited[v] = true;
    cout << g.vexs[v] << " ";
    VertexType p = g.vexs[v];
    for(int k = 0; k < gVexnum; k++){
        if(g.arcs[v][k].adj!= 0 && visited[k] == false){
            DFS(g, k);
        }
    }
}
