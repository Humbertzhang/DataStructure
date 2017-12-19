#include <iostream>
#include "avltree.h"

using namespace std;

int main() {
    Node * root = CreateNode(-1, NULL, NULL);
    int n;
    cout << "How many nodes do you want to add:";
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cout << "Input data:";
        cin >> temp;
        if(i == 0){
            root -> val = temp;
        }else{
            root = InsertNode(root, temp);
        }
    }
    preorder_traversal(root);
    return 0;
}