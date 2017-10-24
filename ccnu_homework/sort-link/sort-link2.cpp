#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL){}
};


ListNode * InitList(ListNode * head);
/*排序链表*/
ListNode * sortList(ListNode *head);
ListNode * split(ListNode *head, int n);


ListNode * merge(ListNode *l1, ListNode *l2, ListNode * cur, ListNode *last_tail);


int main()
{
    ListNode * head;
    head = InitList(head);

    head = sortList(head);
    while(head != NULL){
        cout << head->val <<endl;
        head = head->next;
    }
    return 0;
}


ListNode * sortList(ListNode *head)
{
    if(!head || !(head->next)) return head;

    //获得链表长度
    ListNode * cur = head;
    int length = 0;
    while(cur){
        length += 1;
        cur = cur->next;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode * left, *right, *tail;

    for(int step = 1; step < length; step*=2){
        cur = dummy.next;
        tail = &dummy;
        while(cur) {
            left = cur;
            right = split(left, step);
            if(right == left || right == NULL)
                break;
            cur = split(right, step);
            tail = merge(left, right, cur, tail);
        }
    }
    return dummy.next;
}

ListNode * split(ListNode *head, int n)
{
    int cnt = 0;
    ListNode * ptr = head;
    while(cnt < n){
        if(ptr != NULL){
            ptr = ptr->next;
            cnt += 1;
        }else{
            break;
        }
    }
    if(cnt == n || ptr == NULL)
        return ptr;
    else
        return head;
}


ListNode * merge(ListNode *l1, ListNode *l2, ListNode * cur, ListNode *last_tail)
{
    if(l2 == NULL){
        last_tail->next = l1;
        return NULL;
    }
    ListNode * end1 = l2;
    ListNode * end2 = cur;

    //合并两个有序序列
    while(l1 != end1 || l2 != end2){
        if(l1 == NULL || l2 == NULL || l2 == end2 || l1 == end1)
            break;

        if(l1->val >= l2->val){
            last_tail -> next = l2;
            last_tail = last_tail -> next;
            l2 = l2->next;
        }
        else if(l2->val > l1->val){
            last_tail -> next = l1;
            last_tail = last_tail -> next;
            l1 = l1->next;
        }
    }

    if(l1 != end1){
        while(l1 != end1) {
            last_tail->next = l1;
            last_tail = last_tail->next;
            l1 = l1->next;
            if(l1 == end1){
                last_tail -> next = cur;
            }
        }
    }else if(l2 != end2){
        while(l2 != end2) {
            last_tail->next = l2;
            last_tail = last_tail->next;
            l2 = l2 -> next;
            if(l2 == end2){
                last_tail -> next = cur;
            }
        }
    }

    //找到这次tail并返回
    return last_tail;
}

ListNode * InitList(ListNode * head){
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
            head = ptr;
        }
        else{
            ptr->next = node;
            ptr = ptr->next;
        }
    }
    return head;
}

