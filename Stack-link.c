#include <stdio.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct StackNode{
    SElemType data;
    struct StackNode * next;
}StackNode, * LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;

void Init(LinkStack *S);
Status ClearStack(LinkStack * S);
int StackLength(LinkStack S);
int Gettop(LinkStack S);
Status Display(LinkStack S);
Status Push(LinkStack * S,SElemType e);
Status Pop(LinkStack * S,SElemType *e);
Status EmptyStack(LinkStack S);
Status DestoryStack(LinkStack * S);

int main()
{
    LinkStack S;
    int e;

    Init(&S);
    Push(&S,1);
    Push(&S,10);
    Push(&S,12);
    StackLength(S);
    Display(S);
    Pop(&S,&e);
    Gettop(S);
    ClearStack(&S);
    Display(S);
    Push(&S,9);
    Push(&S,99);
    Display(S);
    DestoryStack(&S);
    Display(S);  
    return 0;
}

void Init(LinkStack * S)
{
    S->top = NULL;
    S->count = 0;
}

Status Display(LinkStack S)
{
    if(S.top == NULL)
        return ERROR;

    printf("Display:");
    while(S.top != NULL){
        printf(" %d ",S.top->data);
        S.top = S.top->next;
    }
    printf("\n");
    return OK;
}

Status EmptyStack(LinkStack S)
{
    if (&S == NULL)
        return ERROR;

    if (&S.count == 0)
        return TRUE;
    
    else
        return FALSE;
    
}

Status Push(LinkStack * S,SElemType e)
{
    if (S == NULL)
        return ERROR;

    LinkStackPtr s = (LinkStackPtr) malloc (sizeof(StackNode));   /* s 为新的栈顶元素　*/
    s->data = e;
    s->next = S->top;   /*原栈顶元素作为s元素的下一个*/
    S->top = s;         /*栈S的栈顶元素改为s*/
    S->count ++;
    printf("Pushed %d\n",e);
    return OK;
}
Status Pop(LinkStack * S,SElemType *e)
{
    if (S == NULL)
        return ERROR;
    LinkStackPtr p;
    if(EmptyStack(*S))
        return ERROR;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count -= 1;
    printf("Poped %d\n",*e);
    return OK;
}

Status ClearStack(LinkStack * S)
{
    if (S == NULL)
        return ERROR;

    LinkStackPtr temp;
    while(S->count != 0){
        temp = S->top;
        S->top = S->top->next;
        free(temp);
        S->count -= 1;
    }
    printf("Stack cleared\n");
}

int Gettop(LinkStack S)
{
    if (&S == NULL)
        return ERROR;
    
    int ret;
    if(S.count == 0)
        return ERROR;
    ret = S.top->data;
    printf("The top element is %d\n",ret);
    
    return ret;
}

int StackLength(LinkStack S)
{
    if (&S == NULL)
        return ERROR;
    printf("The Length of Stack is : %d\n",S.count);
    return S.count;
}

Status DestoryStack(LinkStack * S)
{
    LinkStackPtr temp;
    
    if (S == NULL)
        return ERROR;
    
    while(S->top != NULL){
        temp = S->top;
        S->top = S->top->next;
        free(temp);
    }
    S == NULL;
    printf("Stack Destoried\n");
    return OK;
}