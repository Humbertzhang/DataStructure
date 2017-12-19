#ifndef HAFFMANTREE_HAFFMANTREE_H
#define HAFFMANTREE_HAFFMANTREE_H

typedef struct {
    int weight;
    // 指示该节点的左孩子，右孩子在数组的下标
    int lchild, rchild;
    bool searched;
} HTNode;

typedef struct {
    HTNode* HTree;
    int root;
} HuffmanTree;

#endif //HAFFMANTREE_HAFFMANTREE_H
