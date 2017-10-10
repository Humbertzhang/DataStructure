#ifndef _LIST_LINK_H
#define _LIST_LINK_H

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}*LinkList;

void ErrorMessage(char *s);
int ListLength(LinkList L);
LNode * LocateNode(LinkList L, ElemType e);
void ListInsert(LinkList * L, LNode *p, LNode *s); //将s插入到P之前
void ListDelete(LinkList * L, LNode *p, ElemType *e); //删除p, 并将值赋值到e
void InvertLinkedList(LinkList * L);
void ListTravers(LinkList L);

#endif