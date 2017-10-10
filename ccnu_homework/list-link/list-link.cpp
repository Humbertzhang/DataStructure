//
// Created by humbert on 17-10-8.
//

#include <iostream>
#include <cstdlib>

#include "list-link.h"

using namespace std;

void ErrorMessage(char *s)
{
    cout << s <<endl;
    exit(0);
}

int ListLength(LinkList L)
{
    int count = 0;
    while(L->next != NULL){
        L = L -> next;
        count += 1;
    }
    return count;
}

LNode * LocateNode(LinkList L, ElemType e)
{
    while(L != NULL){
        if(L->data == e){
            return L;
        }
        L = L->next;
    }
    return NULL;
}

//将s插入到P之前
void ListInsert(LinkList * L, LNode *p, LNode *s){
    if(p == *L){
        s->next = (*L)->next;
        (*L)->next = s;
        //s->next = p;
        //*L = s;
    }
    else{
        LinkList temp = *L;

        while(temp -> next != p)
            temp = temp->next;

        temp -> next = s;
        s -> next = p;
    }
}
void ListDelete(LinkList * L, LNode *p, ElemType *e){ //删除p, 并将值赋值到e
    if(p == (*L)->next){
        *e = (*L)->next->data;
        (*L)->next = (*L)->next->next;
    }
    else{
        LinkList dummy = (*L);

        while(dummy -> next != p){
            dummy = dummy -> next;
        }
        *e = dummy->next->data;
        dummy -> next = dummy -> next -> next;
    }
}

void InvertLinkedList(LinkList * L)
{
    LinkList p = *L;
    *L = new LNode;
    p = p->next;//去除第一个节点,它为空.
    while(p!=NULL){
        LNode *n = new LNode;
        n->data = p->data;
        if((*L) -> next == NULL)
            (*L)->next = n;
        else{
            n->next = (*L)->next;
            (*L) -> next = n;
        }
        p = p->next;
    }
}

void ListTravers(LinkList L)
{
    int flag = 0;
    while(L != NULL){
        if(flag == 1) {
            cout << L->data << " ";
            L = L->next;
        }
        if(flag == 0) {
            flag = 1;
            L = L->next;
        }
    }
    cout << endl;
}
