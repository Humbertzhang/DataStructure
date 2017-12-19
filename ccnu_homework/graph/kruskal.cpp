#include <iostream>
#include "kruskal.h"

using namespace std;

struct VertexSet {
    VertexType val;
    int groupid;
};

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
void Kruskal(MGraph * g);

/****************end func***************/

int main() {
    MGraph* g = new MGraph;
    CreateGraph(g);
    Kruskal(g);
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

void Kruskal(MGraph * g)
{
    VertexSet vset[gVexnum];
    for(int i = 0; i < gVexnum; i++){
        vset[i].val = g->vexs[i];
        vset[i].groupid = i;
    }
    int k = 0;  //记边数
    while(k < gVexnum - 1){
        /*****GetMinArc*****/
        VRType minarc = 10000.0;//若结束循环后minarc 仍然为10000则证明已经查找完毕.
        int mini = -1;
        int minj = -1;
        for(int i = 0; i < gVexnum; i++){
            for(int j = 0; j < gVexnum; j++){
                if(g->arcs[i][j].adj != 0 && g->arcs[i][j].adj < minarc){
                    minarc = g->arcs[i][j].adj;
                    mini = i;
                    minj = j;
                }
            }
        }
        if(minarc == 10000.0){
            //结束循环后minarc 仍然为10000证明已经查找完毕.
            break;
        }
        /*****End GetMinArc*****/

        /*****Handle MinArc*****/
        if(vset[mini].groupid != vset[minj].groupid){
            k++; //找到的边数加一
            //使groupid一致
            int jid = vset[minj].groupid;
            int iid = vset[mini].groupid;
            for(int q = 0; q < gVexnum; q++){
                if (vset[q].groupid == jid){
                    vset[q].groupid = iid; 
                }
            }

            //输出
            cout << vset[mini].val << "------>" << minarc << "<------" << vset[minj].val << endl;
            //清空那条边
            g -> arcs[mini][minj].adj = 0;
        }else{
            g -> arcs[mini][minj].adj = 0;
        }

    }
}
