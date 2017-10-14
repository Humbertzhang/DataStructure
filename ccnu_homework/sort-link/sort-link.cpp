#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL){}
};

void InitList(ListNode * head){
    ListNode * ptr = head;
    int n;
    cout << "Input the number of numbers:";
    cin >> n;

    for(int i=0; i < n; i++){
        cout << "Input the value:";
        int temp;
        cin >> temp;
        ListNode *node = new ListNode(temp);
        
        if(i == 0){
            ptr = node;
        }
        else{
            ptr->next = node;
            ptr = ptr->next;
        }
    }
    
    for(int j = 0; j < n ; j++){
        cout << head->val <<endl;
        head = head->next;
    }
}

int main()
{
    ListNode * head;
    InitList(head);
    return 0;
}
