#include <stdio.h>
#define MAXSIZE 5
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node * next;
} Node;
typedef (struct Node *) Linklist;     /*链表*/

void CreateListHead(Linklist * L,int n); /*头插法创建链表*/
void CreateListTail(Linklist * L,int n); /*尾插法创建链表*/
Status GetElem(Linklist L,int i,ElemType *e);
Status ListInsert(Linklist *L,int i,ElemType e);
Status ListDelete(Linklist *L,int i,ElemType e);
Status ClearList(Linklist * L);

