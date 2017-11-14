#ifndef _STACK_
#define _STACK_

typedef int ElemType;
typedef ElemType Elemtype;
struct Node {
    ElemType val;
    Node *next;
    Node() : next(0) {};
    Node(ElemType value) : val(value), next(0) {};
};

typedef struct Node  Stack;

int InitStack(Stack * s);
int DestoryStack(Stack * s);
int ClearStack(Stack * s);
int StackEmpty(Stack s);
int StackLength(Stack s);
ElemType GetTop(Stack s);
int Push(Stack * s, Elemtype e);
ElemType Pop(Stack * s);
void StackTraverse(Stack s);

#endif
