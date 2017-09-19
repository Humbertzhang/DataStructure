#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char ElemType;

struct TreeNode;
typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElemType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElemType X,SearchTree T);
SearchTree Delete(ElemType X,SearchTree T);
void Retrieve(Position P); //检索

struct TreeNode
{
    ElemType Element;
    SearchTree Left;
    SearchTree Right;
};

int main()
{
    SearchTree  T = NULL;
    //SearchTree T = malloc(sizeof(struct TreeNode));
    Position temp;
    T = Insert('H',T);
    T = Insert('U',T);
    T = Insert('M',T);
    T = Insert('B',T);
    T = Insert('E',T);
    T = Insert('R',T);
    T = Insert('T',T);
    Retrieve(T);
    printf("\n");
    temp = FindMin(T);
    printf("Min:%c\n",temp->Element);
    FindMax(T);
    temp = FindMax(T);
    printf("Max:%c\n",temp->Element);
    T = Delete('U',T);
    Retrieve(T);
    MakeEmpty(T);
    //Retrieve(T);
    return 0;
}

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElemType X, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(X < T->Element)
        return Find(X,T->Left);
    else if(X > T->Element)
        return Find(X,T->Right);
    else
        return T;
}
Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(T->Left != NULL){
        return FindMin(T->Left);
    }
    else
        return T;
}

Position FindMax(SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(T->Right != NULL)
        return FindMax(T->Right);
    else
        return T;
}
SearchTree Insert(ElemType X,SearchTree T)
{
    if(T == NULL) //TREE is empty.
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            exit(1);
        else{
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert(X,T->Left);
    else
        T->Right = Insert(X,T->Right);

    return T;
}
SearchTree Delete(ElemType X,SearchTree T)
{
    struct TreeNode * temp;
    if(T == NULL)
        exit(1);
    else if( X < T->Element)
        T->Left = Delete(X,T->Left);
    else if(X>T->Element)
        T->Right = Delete(X,T->Right);

    else if(T->Left  && T->Right ){
        temp = FindMin(T->Right);
        T->Element = temp->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    /*巧妙的处理1个或0个子节点的情况*/
    else{
        temp = T;
        if(T->Left == NULL)
            T = T -> Right;
        else if(T->Right == NULL)
            T = T -> Left;
        free(temp);
    }
    return  T;
}
void Retrieve(Position P)
{
    if(P == NULL)
        return;
    printf("%c ",P->Element);
    Retrieve(P->Left);
    Retrieve(P->Right);
}