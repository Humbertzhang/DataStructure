#ifndef _GRAPH2_H
#define _GRAPH2_H
const int MAX_VERTEX_NUM = 20;
typedef char VertexType;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
} ArcNode;

typedef struct VNode {
    VertexType  data;
    ArcNode*    firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

/*种类为无向图*/
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
#endif
