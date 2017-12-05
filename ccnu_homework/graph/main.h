#ifndef _MAINH_
#define _MAINH_

//const int MAX = INT32_MAX;
const int MAX_VERTEX_NUM = 20;

//typedef enum {DG, DN, AG, AN} GraphKind;    //有向图， 有向网， 无向图， 无向网
typedef double VRType;
typedef char VertexType;

typedef struct ArcCell{
    VRType adj;      //权值
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

//无向图
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM];    //描述顶点信息的数组
    AdjMatrix arcs;     //临接矩阵
    int vexnum, arcnum; //顶点有多少， 弧有多少。
    //GraphKind kind;     //类型
}MGraph;

#endif
