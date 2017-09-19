#include <stdio.h>
#define MAXSIZE 5
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType data[MAXSIZE];     /*数组来储存元素*/
    int length;                 /*当前长度*/
}SqList;

Status InitList(SqList * L);
void DesplayList(SqList L);
Status GetElem(SqList L, int i, ElemType * e);
Status ListInsert(SqList * L, int i, ElemType e);
Status ListDelete(SqList * L,int i,ElemType *e);

int main()
{
    SqList L;
    int ele;

    L.length = 0;
    
    
    if((InitList(&L)) == ERROR)
        return 1;

    DesplayList(L);
    
    GetElem(L,3,&ele);
    printf("Element at 3 position is %d\n",ele);
    ele = 2333;
    ListInsert(&L,3,ele);
    DesplayList(L);
    ListDelete(&L,3,&ele);
    DesplayList(L);
    return 0;
}

Status InitList(SqList * L)
{
    int i;

    printf("Length of List:");
    scanf("%d",&(L->length));
    if(L->length > MAXSIZE){
        printf("More than MAXSIZE.\n");
        return ERROR;
    }
    for(i=0;i<L->length;i++){
        scanf("%d",&L->data[i]);
    }
    return OK;
}

void DesplayList(SqList L)
{
    int i;
    printf("Display List: ");
    for(i = 0;i<L.length;i++){
        if(i != L.length -1)
            printf("%d ",L.data[i]);
        else
            printf("%d\n",L.data[i]);
    }

}

Status GetElem(SqList L, int i, ElemType * e)    /*Get element in i position*/
{                                               /*e was used to store the element*/  
    if(L.length == 0 || i < 1 || i>L.length)    /* Thorw eror */
        return ERROR;
    
    *e = L.data[i-1];
    return OK;
}

Status ListInsert(SqList * L, int i, ElemType e)
{
    /* i = L.length + 1,则为表尾. i <= L.length 则为在表中　*/
    int k;
    
    if (i<1 || L->length == MAXSIZE || i>L->length + 1)  /* i小于１，Ｌ已满，或i的位置大于了L长度+1,则抛出异常　*/
        return ERROR;

    if(i <= L->length)
        for(k = L->length - 1;k>=i-1;k--)
            L->data[k+1] = L->data[k];               /* 依次往后移动一个　*/

    printf("Insert | %d | to | %d | position.\n",e,i);
    L->data[i-1] = e;
    L->length+=1;
    return OK;
}


Status ListDelete(SqList * L,int i,ElemType *e)   /* e was used to return the delete num */
{
    int k;
    if(i<1 || i > L->length || L->length == 0)
        return ERROR;
    
    *e = L->data[i-1];
    if( i < L->length ){                        /*不是最后一个被删除*/
        for( k = i ;k<L->length;k++){
            L->data[k-1] = L->data[k];
        }
    }

    L->length --;
    printf("Delete | %d | in | %d | index\n",*e,i);
    return OK;
}
