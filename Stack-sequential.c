#include <stdio.h>
#define MAXSIZE 5
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct {
    SElemType data[MAXSIZE];
    int top;                    /*栈顶指针*/
}SqStack;

void Init(SqStack * S);
Status Push(SqStack * S,SElemType e);
Status Pop(SqStack * S,SElemType * e);
void Display(SqStack S);
Status ClearStack(SqStack * S);
void StackEmpty(SqStack S);
Status Gettop(SqStack S,SElemType * e);
void StackLength(SqStack S);

int main()
{
    SqStack S;
    int e1=0,e2=0;
    
    Init(&S);

    if((Push(&S,1)) == ERROR )
        return 1;
    if((Push(&S,2))== ERROR)
        return 1;
    if((Push(&S,2333))== ERROR)
        return 1;
    
    StackEmpty(S);
    Gettop(S,&e2);
    Display(S);
    
    if((Pop(&S,&e2)) == ERROR)
        return 1;
    StackLength(S);
    Display(S);
    ClearStack(&S);
    StackEmpty(S);
    Display(S);

    return 0;
}

void Init(SqStack * S)
{
    S->top = -1;
}


Status Push(SqStack * S, SElemType e)
{
    if(S->top == MAXSIZE -1)
        return ERROR;
    S->top += 1;
    S->data[S->top] = e;
    printf("Pushed %d\n",e);
    return OK;
}

Status Pop(SqStack * S,SElemType * e)
{
    if(S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    printf("Poped %d\n",*e);
    return OK;
}

void Display(SqStack S)
{
    int i;
    printf("Display:");
    for(i=S.top;i>-1;i--)
        printf(" %d ",S.data[i]);
    printf("\n");
}

Status ClearStack(SqStack * S)
{
    while(1){
        if((S->top) == -1)
            break;
        S->top -= 1;
    }
    printf("Stack Cleared\n");
}

void StackEmpty(SqStack S)
{
    if(S.top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}
Status Gettop(SqStack S, SElemType * e)
{
    if(S.top == -1)
        return ERROR;
    *e = S.data[S.top];
    printf("The top element is : %d\n",*e);
    return OK;
}

void StackLength(SqStack S)
{
    printf("Stack Length is : %d\n", (S.top+1) );
}