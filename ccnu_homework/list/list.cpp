#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAXSIZE 10
#define INCREMENTSIZE 10
#define OK 1
#define ERROR -1

typedef int ElemType;

typedef struct {
    ElemType *elem;
    //ElemType * elem;
    int length;
    int listsize;
    int incrementsize;
}Sqlist;

void ErrorMessage(char * s);
void InitList(Sqlist * L);
void Union(Sqlist * La, Sqlist * Lb);
int DestroyList(Sqlist * L);
int ClearList(Sqlist * L);
int ListEmpty(Sqlist L);
int ListLength(Sqlist L);
int GetElem(Sqlist L, int i, int * elem);
int LocateElem(Sqlist L, ElemType e);
int PriorElem(Sqlist L, int curr_elem, int * pre_elem);
int NextElem(Sqlist L, int curr_elem, int * next_elem);
int ListInsert(Sqlist * L, int i, int elem);
int ListDelete(Sqlist * L, int i, int * elem);
int ListTraverse(Sqlist L);

int main()
{
    Sqlist L;
    InitList(&L);
    
    if(ListEmpty(L))
        cout << "List is empty" <<endl;

    ListInsert(&L,0,1);
    ListInsert(&L,0,2);
    ListInsert(&L,0,3);
    ListTraverse(L);
    
    if(ListEmpty(L))
        cout << "List is empty" <<endl;

    
    printf("List Length: %d\n", ListLength(L));
    
    int e, location;
    GetElem(L, 2, &e);
    printf("The element at 2 is:%d\n", e);
    
    location = LocateElem(L, e);
    printf("The location of %d is %d\n", e, location);
    
    int e2,e3;
    PriorElem(L, e, &e2);
    printf("The Previous of %d is %d\n", e, e2);

    NextElem(L, e2, &e3);
    printf("The next of %d is %d\n",e2, e3);
    
    ListDelete(&L, 0, &e);
    printf("Deleted %d\n",e);
    ListTraverse(L);

    cout << "Start Union" <<endl;
    Sqlist Lb;
    InitList(&Lb);
    ListInsert(&Lb,0,4);
    ListInsert(&Lb,0,5);
    ListInsert(&Lb,0,1);
    Union(&L, &Lb);
    cout << "After Union:" <<endl;;
    ListTraverse(L);

    printf("Clear\n");
    ClearList(&L);
    cout << "destory" <<endl;
    DestroyList(&L);

    
}

void ErrorMessage(char * s)
{
    cout << s << endl;
    exit(1);
}

void InitList(Sqlist * L)
{
    L->elem = new ElemType[MAXSIZE+INCREMENTSIZE];
    L->length = 0;
    L->listsize = MAXSIZE;
    L->incrementsize = INCREMENTSIZE;
}

int DestroyList(Sqlist * L)
{
    delete [] L->elem;
    L->listsize = 0;
    L->length = 0;
    return OK;
}

int ClearList(Sqlist * L)
{
    for (int i=0; i < L->length;i++){
        L->elem[i] = 0;
    }
    L->listsize = 0;
    L->length = 0;
    L->incrementsize = 0;
    return OK;
}

int ListEmpty(Sqlist L)
{
    if(L.length == 0)
        return 1;
    else
        return 0;
}

int ListLength(Sqlist L)
{
    return L.length;
}

int GetElem(Sqlist L, int i, int * elem)
{
    if(i > L.length)
        return ERROR;

    *elem = L.elem[i];
    return OK;
}

int LocateElem(Sqlist L, ElemType e)
{
    for(int i = 0; i < L.length ; i++)
        if (L.elem[i] == e)
            return i;
    
    return 0;
}

int PriorElem(Sqlist L, int curr_elem, int * pre_elem)
{
    int curr_index = LocateElem(L, curr_elem);
    if(curr_elem == ERROR || curr_elem == 0){
        ErrorMessage("Do not have PriorElement.\n");
    }
    *pre_elem = L.elem[curr_index-1];
    return OK;
}

int NextElem(Sqlist L, int curr_elem, int * next_elem)
{
    int curr_index = LocateElem(L, curr_elem);
    if (curr_index == ERROR || curr_index == L.length-1){
        ErrorMessage("Do not have NextElement.\n");
    }
    
    *next_elem = L.elem[curr_index + 1];
    return OK;
}

int ListInsert(Sqlist * L, int i, int elem)
{
    if(L->length == MAXSIZE){
        ErrorMessage("No Enough Space!\n");
    }

    for(int j = L->listsize; j >= i; j--)
        L->elem[j+1] = L->elem[j];
    
    L->elem[i] = elem;
    L->length += 1;
    return OK;
}

int ListDelete(Sqlist * L, int i, int * elem)
{
    if(i>L->length-1){
        ErrorMessage("Do not have that Element.\n");
    }

    *elem = L->elem[i];

    for(int j = i; j<L->length; j++)
        L->elem[j] = elem[j+1];
    L->elem[L->length-1] = 0;
    L->length -= 1;
    
    return OK;
}

int ListTraverse(Sqlist L)
{
    for(int i=0; i < L.length; i++)
        printf("[%d]:%d\n",i,L.elem[i]);
    return OK;
}

void Union(Sqlist * La, Sqlist * Lb)
{
    int La_len = ListLength(*La);
    while(!ListEmpty(*Lb)){
        int e = 0;
        ListDelete(Lb, 0, &e);
        if(!LocateElem(*La, e)){
            ListInsert(La, ++La_len, e);
        }
    }
    DestroyList(Lb);
}
