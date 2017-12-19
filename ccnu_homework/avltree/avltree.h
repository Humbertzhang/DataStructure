//
// Created by humbert on 17-12-3.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

#define max(a,b) ((a) > (b) ? (a) : (b))

typedef int Type;
typedef struct AVLTreeNode {
    Type val;
    int height;
    struct AVLTreeNode * left;
    struct AVLTreeNode * right;
}Node, * AVLTree;

Node * CreateNode(Type key, Node * left, Node * right);
int GetHeight(AVLTree t);
Node * SearchNode(AVLTree tree, Type key);

void preorder_traversal(AVLTree t);

/*以下操作的返回值为操作完成后的根节点*/
Node * llRotation(AVLTree t);
Node * rrRotation(AVLTree t);
Node * lrRotation(AVLTree t);
Node * rlRotation(AVLTree t);
Node * InsertNode(AVLTree tree, Type val);
//Node * DeleteNode(AVLTree tree, Type val);

#endif //AVLTREE_AVLTREE_H
