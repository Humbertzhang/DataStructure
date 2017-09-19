#include <stdio.h>
#define MAXSIZE 11
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;
typedef int Status;

typedef struct 
{
    QElemType data[MAXSIZE];
    int front;      /*头指针*/
    int rear;       /*尾指针,若队尾不为空，则指向队尾元素的下一个位置*/
}SqQueue;           /*循环队列,大小为MAXSIZE-1*/

Status InitQueue(SqQueue * Q);
int QueueLength(SqQueue Q);
Status EnQueue(SqQueue * Q,QElemType e);
Status DeQueue(SqQueue * Q,QElemType * e);
Status Display(SqQueue Q);

int main()
{
    SqQueue Q;
    int i,e,length;
    InitQueue(&Q);
    for(i=0;i<8;i++){
        EnQueue(&Q,i);
    }
    Display(Q);
    DeQueue(&Q,&e);
    DeQueue(&Q,&e);
    EnQueue(&Q,23);
    EnQueue(&Q,233);
    EnQueue(&Q,666);
    EnQueue(&Q,2333);

    Display(Q);

    length =  QueueLength(Q);
    printf("Queue Length : %d\n",length);
    
    return 0;
}

Status InitQueue(SqQueue * Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue * Q,QElemType e)
{
    if((Q->rear + 1)%MAXSIZE == Q->front)   /*队列已满(其实还有一个没有占用，但视为已满)*/
        return ERROR;
    Q->data[Q->rear] = e;                   /*将e赋值给队尾*/
    Q->rear = (Q->rear + 1) % MAXSIZE;      /*Q向后移动一位，若到了最后则%MAXSIZE转到数组头部*/
    
    printf("EnQueue %d\n",e);
    return OK;
}
Status DeQueue(SqQueue * Q,QElemType * e)
{
    if(Q->front == Q->rear)                 /*队列为空*/
        return ERROR;
    *e = Q->data[Q->front];                 /*将队头赋值给e*/
    Q->front = (Q->front + 1) % MAXSIZE;

    printf("Dequeue %d\n",*e);
    return OK;
}
Status Display(SqQueue Q)
{
    int i;
    if(Q.front == Q.rear)
        return ERROR;
    printf("Display:");

    if(Q.rear < Q.front){
        for(i = Q.front;i<MAXSIZE;i++)
            printf("%d ",Q.data[i]);
        for(i = 0;i<Q.rear;i++)
            printf("%d ",Q.data[i]);
    }
    else if(Q.rear > Q.front){
        for(i=Q.front;i<Q.rear;i++)
            printf("%d ",Q.data[i]);
    }

    printf("\n");
    return OK;
}