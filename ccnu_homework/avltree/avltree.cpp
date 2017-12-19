//
// Created by humbert on 17-12-3.
//
#include <iostream>
#include <cstdio>
#include "avltree.h"

using namespace std;

Node * CreateNode(Type key, Node * left, Node * right)
{
    Node * p = new Node;

    p -> val = key;
    p -> height = 0;
    p -> left = left;
    p -> right = right;

    return p;
}

int GetHeight(AVLTree t)
{
    if(t == NULL){
        return 0;
    }
    return t->height;
}

/*查找树中有无该key*/
Node * SearchNode(AVLTree tree, Type key)
{
    if(tree == NULL || tree->val == key){
        return tree;
    }
    if(key < tree -> val){
        return SearchNode(tree -> left, key);
    }else{
        return SearchNode(tree -> right, key);
    }
}

void preorder_traversal(AVLTree t)
{
    if(t != NULL){
        cout << t->val << " ";
        preorder_traversal(t->left);
        preorder_traversal(t->right);
    }
}

Node * llRotation(AVLTree k2)
{
    AVLTree k1;
    /*返回值根节点为原树的左节点*/
    k1 = k2 -> left;
    /*原树的新左节点为原左节点的右节点*/
    k2 -> left = k1 -> right;
    /*返回值（即原左节点的右节点）的新右节点改为原来的根节点k2*/
    k1->right = k2;

    k2 -> height = max(GetHeight(k2->left), GetHeight(k2->right)) + 1;
    k1 -> height = max(GetHeight(k1->left), GetHeight(k1->right)) + 1;

    return k1;
}

Node *  rrRotation(AVLTree k1)
{
    AVLTree k2;

    k2 = k1 -> right;
    k1 -> right = k2 -> left;
    k2 -> left = k1;

    k1 -> height = max(GetHeight(k1->left), GetHeight(k1->right)) + 1;
    k2 -> height = max(GetHeight(k2->left), GetHeight(k2->right)) +1;

    return k2;
}
Node *  lrRotation(AVLTree k3)
{
    k3 -> left = rrRotation(k3->left);
    return llRotation(k3);
}

Node *  rlRotation(AVLTree k4)
{
    k4 -> right = llRotation(k4 -> right);
    return rrRotation(k4);
}

Node *  InsertNode(AVLTree tree, Type val)
{
    if(tree == NULL) {
        /*原来为NULL则创建一棵AVL树*/
        tree = CreateNode(val, NULL, NULL);
        return tree;
    } else if(val < tree -> val) {
        /*应插入至左子树*/
        tree -> left = InsertNode(tree->left, val);
        /*判断树是否失衡, 失衡则旋转*/
        if(GetHeight(tree->left) - GetHeight(tree->right) >= 2) {
            /*根据数值可以判断出是以何种情况插入至左子树的，即可判断该怎么旋转*/
            if(val < tree->left->val) {
                tree = llRotation(tree);
            }else{
                tree = lrRotation(tree);
            }
        }
    } else if(val > tree->val) {
        /*应插入到右子树*/
        tree -> right = InsertNode(tree->right, val);
        if(GetHeight(tree->right) - GetHeight(tree->left) >= 2) {
            if(val > tree->right->val) {
                tree = rrRotation(tree);
            }else{
                tree = rlRotation(tree);
            }
        }
    } else {
        printf("Duplicated element is not legal");
    }
    tree -> height = max(GetHeight(tree->left), GetHeight(tree->right)) + 1;
    return tree;
}
