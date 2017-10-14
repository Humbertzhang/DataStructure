#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

using namespace std;

Stack CreateStack()
{
    Stack s = new Node;
    if(s == NULL){
        cout << "Error:No enough space" << endl;
        exit(1);
    }
    s->next = NULL;
    return s;
}

int IsEmpty(Stack s)
{
    if(s->next == NULL)
        return 1;
    return 0;
}

void MakeEmpty(Stack s)
{
    if(s->next == NULL){
        cout << "Error: No such Stack" <<endl;
        exit(1);
    }
    while(s->next != NULL){
        Pop(s);
    }
}

void Push(int x, Stack s)
{
    Node * temp = new Node;
    if(temp == NULL){
        cout << "Error:No enough space" <<endl;
        exit(1);
    }
    temp->Element = x;
    temp->next = s->next;
    s->next = temp;
}

int Pop(Stack s)
{
    if(s->next == NULL){
        cout << "Error: Stack is empty" <<endl;
        exit(1);
    }
    Node * p = s->next;
    s->next = s->next->next;
    return p->Element;
}

int Top(Stack s)
{
    if(s == NULL){
        cout << "Error: No that stack" <<endl;
        exit(0);
    }
    return s->next->Element;
}
