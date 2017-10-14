#ifndef _Stack_h

//栈的链表实现

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack s);
Stack CreateStack();
void MakeEmpty(Stack s);
void Push(int x, Stack s);
int Pop(Stack s);
int Top(Stack S);

#endif
struct Node
{
    int Element;
    PtrToNode next;
};
