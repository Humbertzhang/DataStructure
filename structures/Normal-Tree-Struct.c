#include <stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int TElemType;
typedef int Status;


/*树的父结点表示法*/
typedef struct PTNode
{
    TElemType data;         /*节点数据*/
    int parent;             /*父结点位置*/
}PTNode;
typedef struct
{
    PTNode nodes[MAXSIZE];
    int r;                  /*根位置*/
    int n;                  /*节点个数*/
}PTree;


/*树的子节点表示法*/
/*一颗数由节点CTBox组成，而每个CTBox中又保存有其子节点的头指针(CTNode的next)*/
typedef struct CTNode
{
    int child;              /*标识在同一父结点下的子节点中的索引值*/
    struct CTNode *next;    /*指向树中的节点*/
}ChildPtr;

typedef struct              /*保存该节点的data以及CTNode的指针*/
{
    TElemType data;
    ChildPtr firstchild;
}CTBox;

typedef struct              /*树*/
{
    CTBox nodes[MAXSIZE];   /*节点的数组*/  
    int r;                  /*根位置*/
    int n;                  /*节点数*/
}

/*孩子兄弟表示法*/
typedef struct CSNode
{
    TElemType data;
    struct CSNode * firstchild; /*第一个字节点*/
    struct CSNode * rightsib;   /*右边的兄弟节点*/
}CSNode,*CSTree;
