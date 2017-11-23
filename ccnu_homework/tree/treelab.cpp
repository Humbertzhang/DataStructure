#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

typedef char ElementType;

typedef struct BiTNode {
    ElementType data;
    struct BiTNode * lchild, *rchild;
} BiTNode, *BiTree;

void BuildTree(BiTree & T);
void InOrderTraversal(BiTree T);
void LayerTraversal(BiTree T, Queue<BiTNode *> * q);

int main()
{
    BiTree T;
    BuildTree(T);
    cout << "中序遍历:";
    InOrderTraversal(T);
    cout << endl;
    cout << "按层遍历:";
    
    Queue<BiTNode *> q;
    LayerTraversal(T, &q);
    cout << endl;
}

void BuildTree(BiTree &T)
{
   cout << "Input A char:";
   char ch;
   cin >> ch;
   if(ch == '#'){
        T == NULL;
   }else{
        T = new BiTNode;
        T -> data = ch;
        BuildTree(T->lchild);
        BuildTree(T->rchild);
   }
}

void InOrderTraversal(BiTree T)
{
    if(T == NULL){
        return;
    }
    InOrderTraversal(T->lchild);
    cout << T->data << " ";
    InOrderTraversal(T->rchild);
}

void LayerTraversal(BiTree T, Queue<BiTNode *> * q)
{
    if(T == NULL){
        return;
    }else{
        q->enqueue(T);
    }

    while(!q->isEmpty()){
        BiTNode * cur = q->dequeue();
        cout << cur -> data << " ";
        if(cur -> lchild != NULL)
            q->enqueue(cur -> lchild);
        if(cur -> rchild != NULL)
            q->enqueue(cur -> rchild);
    }
}
