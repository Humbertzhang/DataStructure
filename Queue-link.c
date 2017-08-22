#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
    QueuePtr front,rear;
}LinkQueue;

void InitQueue(LinkQueue * Q);
Status EnQueue(LinkQueue * Q,QElemType e);
Status DeQueue(LinkQueue * Q,QElemType * e);

int main()
{
    LinkQueue Q;
    int e=2333;
    InitQueue(&Q);
    EnQueue(&Q,1);
    DeQueue(&Q,&e);
    printf("Dequeued: %d\n",e);

    return 0;
}

void InitQueue(LinkQueue * Q)
{
    QueuePtr Head = (QueuePtr)malloc(sizeof(QNode));
    Head -> next = NULL;
    Q->front = Head;
    Q->rear = Head;
}

Status EnQueue(LinkQueue * Q , QElemType e)
{
    QueuePtr  s = (QueuePtr)malloc(sizeof(QNode));
    if(!s){
        exit(1);
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    printf("EnQueued: %d\n",e);
    return OK;
}

Status DeQueue(LinkQueue * Q,QElemType * e)
{
    QueuePtr p;
    if(Q->front == Q->rear )           /*无节点*/
        return ERROR;
    
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;

    if(Q->rear == p)              /*仅存在一个节点时，队头为队尾*/
        Q->rear = Q->front;
    free(p);
    return OK;
}