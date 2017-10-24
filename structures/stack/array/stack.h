#ifndef _Stack_h
//栈数组实现

struct Stack;
Stack CreateStack();
int IsEmpty(Stack *s);
void MakeEmpty(Stack *s);
void Push(int x, Stack *s);
int Pop(Stack s);
int Top(Stack s);
void Resize(Stack * s, int oldsize);

#endif

struct Stack{
    int ele[5];
    int top;
    int size;
};
