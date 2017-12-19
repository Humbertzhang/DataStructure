#include <iostream>
#include <climits>
#include "haffmantree.h"

using namespace std;

//HFT为待构建的哈夫曼树， w为大小为n的数组，存放权值， n为待编码的元素的数目
void CreateHuffmanTree(HuffmanTree * HfTree, int *w, int n);
void TraverseHT(HuffmanTree HfTree, int index);
void Select(HTNode * Htree, int size, int* s1, int* s2, int flag);

int main() {
    HuffmanTree * HfTree = new HuffmanTree;
    int size = 8;
    int w[size] = {5, 29, 7, 8, 14, 23, 3, 11};
    CreateHuffmanTree(HfTree, w, size);
    TraverseHT(*HfTree, 2*size-4);
    return 0;
}
void CreateHuffmanTree(HuffmanTree * HfTree, int *w, int n)
{
    //小于1不需要编码
    if(n <= 1){
        return;
    }
    //编码n个元素需要2*n-1个节点. 最后一个节点作为哨兵节点在Select中使用
    int m = 2 * n;
    HfTree->HTree = new HTNode[m];

    HTNode* p = HfTree->HTree;
    int i = 0;
    //初始化， -1表示为空
    for(; i < n; ++i, ++p, ++w){
        *p = {*w, -1, -1, false};
    }
    for(; i < m-1; ++i, ++p){
        *p = {0, -1, -1, false};
    }
    HfTree->HTree[m-1].weight = INT32_MAX;

    for(i = n; i < 2*n-1; ++i){
        int s1 = m-1, s2 = m - 1;
        Select(HfTree->HTree, i, &s1, &s2, m-1);
        HfTree->HTree[i].lchild = s1;
        HfTree->HTree[i].rchild = s2;
        HfTree->HTree[i].weight = HfTree->HTree[s1].weight + HfTree->HTree[s2].weight;
    }
    HfTree->root = m-2;
}

void Select(HTNode * Htree, int size, int* s1, int* s2, int flag)
{
    if (size < 2)   return;

    for(int i = 0; i < size; i++){
        if(Htree[i].weight < Htree[*s1].weight && Htree[i].searched != true){
            *s2 = *s1;
            *s1 = i;
            Htree[i].searched = true;
        }
        else if(Htree[i].weight < Htree[*s2].weight && Htree[i].weight != Htree[*s1].weight && Htree[i].searched != true){
            *s2 = i;
            Htree[i].searched = true;
        }
    }

}

void TraverseHT(HuffmanTree HfTree, int index)
{
    int root = index;
    if (HfTree.HTree[root].rchild != 0 || HfTree.HTree[root].lchild != 0){
        cout << "index" << ":" << root << "=>";
        cout << "weight" << ":" << HfTree.HTree[root].weight << endl;
    }
    if(HfTree.HTree[root].rchild != 0){
        TraverseHT(HfTree, HfTree.HTree[root].rchild);
    }
    if(HfTree.HTree[root].lchild != 0){
        TraverseHT(HfTree, HfTree.HTree[root].lchild);
    }
}
