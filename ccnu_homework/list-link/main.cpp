#include <iostream>
#include <cstdlib>

#include "list-link.h"

using namespace std;

int main()
{
    LinkList L = new LNode;
    LinkList ptr = L;
    int i = 0, num;
    cout << "How many node would u want to add:";
    cin >> num;

    while(i < num){
        ElemType temp = 0;
        cout << "Input data:";
        cin >> temp;
        LNode * t = new LNode;
        t->data = temp;
        t->next = NULL;
        ptr -> next = t;
        ptr = ptr -> next;
        i += 1;
    }
    ptr = NULL;

    LNode *a = new LNode;
    a->data = 100;
    a->next = NULL;
    ListInsert(&L, L, a);
    LNode *loc = LocateNode(L, a->data);

    cout << "data:" << loc->data << endl;
    cout << "Length:";
    cout << ListLength(L) <<endl;
    int e = 0;
    ListDelete(&L, a, &e);
    cout << e << " deleted." << endl;
    ListTravers(L);
    InvertLinkedList(&L);
    ListTravers(L);

    return 0;
}
