#include "stack.h"
#include <iostream>
using namespace std;

int InitStack(Stack * s)
{
    s = new Node();
}

int DestoryStack(Stack * s)
{
    Node * temp;
    while(s->next != NULL){
        temp = s->next;
        s->next = s->next->next;
        delete temp;
    }
    delete s;
}

int ClearStack(Stack * s)
{
    Node * temp;
    while(s->next != NULL){
        temp = s->next;
        s->next = s->next->next;
        delete temp;
    }
}

int StackEmpty(Stack s)
{
    return (s.next == NULL);
}

int StackLength(Stack s)
{
    int cnt = 0;
    while(s.next != NULL){
        s.next = s.next->next;
        cnt += 1;
    }
    return cnt;
}

ElemType GetTop(Stack s)
{
    return s.next->val;
}

int Push(Stack * s, Elemtype e)
{
    Node * t = new Node(e);
    t->next = s->next;
    s->next = t;
}
ElemType Pop(Stack * s)
{
    if(s->next != NULL){
        Node * t = s->next;
        s->next = t->next;
        int v = t->val;
        delete t;
        return v;
    }else{
        cout << "Stack POP Fail" <<endl;
    }
}

void StackTraverse(Stack s)
{
    cout << "List Traverse:" <<endl;
    while(s.next != NULL){
        cout << s.next->val <<endl;
        s.next = s.next->next;
    }
}
