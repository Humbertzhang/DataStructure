#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{
    TElemType data;                     /*节点数据*/
    struct BiTNode * lchild, *rchild;   /*左右*/
}BiTNode,*BiTree;

/*前序遍历*/
void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    printf("%c ",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

/*中序遍历:直到一个子树没有左子树开始*/
void InOrderTraverse(BiTree T)
{
    if ( T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ",T->data);
    InOrderTraverse(T->rchild);
}
/*后序遍历*/
void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}
void CreateBiTree(BiTree * T)
{
    TElemType ch;
    scanf("%c",&ch);
    if(ch == '#'){
        *T = NULL;
        return;
    }
    else{
        *T = (BiTree) malloc (sizeof(BiTNode));
        
        if(!*T)
            exit(1);
        
        (*T) -> data = ch; /*生成根节点*/
        printf("test\n");
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int main()
{
    BiTree T;
    CreateBiTree(&T);
}