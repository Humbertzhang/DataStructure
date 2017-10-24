#include <iostream>
#include <cstdlib>
#include <cmalloc>
#include "stack.h"

using namespace std;

Stack CreateStack()
{
    s = new Stack;
    s->top = -1;
    s->size = 5;
    if(s == NULL){
        cout << "Create Fail" <<endl;
        exit(0);
    }
    return s;
}

int IsEmpty(Stack * s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

void MakeEmpty(Stack * s)
{
    s->top = -1;
}

void Push(int x, Stack *s)
{
    if(s->top == s->size-1){
        Resize(s, s->size);
    }
    s->ele[top++] = x;
}

int Pop(Stack *s)
{
    if(s->top != -1)
        return s->ele[top--];
    else{
        cout << "Stack is empty" <<endl;
        exit(0);
    }
}

int Top(Stack S)
{
    if(S!= NULL)
        return s->ele[top];
    else{
        cout << "Stack is not exits" <<endl
        exit(0);
    }
}

void Resize(Stack * s, oldsize)
{
    int temp[s->size];
    memcpy(temp, s->ele,sizeof(int) * oldsize);
    s->size = oldsize*2;
    s->ele = new int[s->size];
    memcpy(s->size, temp, sizeof(int) * oldsize);
}
