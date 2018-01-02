/*1,根据前缀表达式构建一颗树 如 ABD##EG##H##C#F##
 *2,检查它是否平衡
 */
#include <iostream>

using namespace std;

typedef char TElemType;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode * lchild, *rchild;
}BiTNode, *BiTree;

//构建二叉树
void BuildTree(BiTree &T);

//先序遍历树
void TraTree(BiTree T);

//检查深度，配合MAXDEPTH 与 MINDEPTH来记录最大与最小深度
void CheckDepth(BiTree T, int depth);

//判断是否平衡
void CheckBalance();

//用于检验二叉树是否平衡的全局变量
int MINDEEP;
int MAXDEEP;

// ABD##EG##H##C#F##

int main()
{
    BiTree t;
    cout << "输入字符串:" <<endl;
    BuildTree(t);
    TraTree(t);
    int depth = 1;
    MAXDEEP = -1;
    MINDEEP = 65535;
    CheckDepth(t, depth);
    cout << "Mindepth:" << MINDEEP << endl;
    cout << "Maxdepth:" << MAXDEEP << endl;
    CheckBalance();
    return 0;
}

void TraTree(BiTree T)
{
    if(T){
        cout << T->data << " "<<endl;
    }
    if(T->lchild){
        TraTree(T->lchild);
    }
    if(T->rchild){
        TraTree(T->rchild);
    }
}

void BuildTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch == '#') {
        T == NULL;
    }else{
        T = new BiTNode;
        T->data = ch;
        BuildTree(T->lchild);
        BuildTree(T->rchild);
    }
}

void CheckDepth(BiTree T, int depth)
{
     if(T->lchild){
         CheckDepth(T->lchild, depth+1);
     }
     if(T->rchild){
        CheckDepth(T->rchild, depth+1);
     }
     if(T->rchild == NULL && T->rchild == NULL){
        if(depth > MAXDEEP){
            MAXDEEP = depth;
        }
        if(depth < MINDEEP){
            MINDEEP = depth;
        }
     }
}

void CheckBalance()
{
    if(MAXDEEP-MINDEEP <= 1){
        cout << "平衡" <<endl;
    }else{
        cout << "不平衡" <<endl;
    }
}
