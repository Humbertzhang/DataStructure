#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    InitStack(&S);
    int T = 16;
    int n = 6;
    int w[n] = {2,5,8,3,4,6};
    int k = 0;

    do {
        while(T > 0 && k < n) {
            if(T - w[k] >= 0) {
                Push(&S, k);
                T -= w[k];
            }
            k++;
        }
        if(T==0)
            StackTraverse(S);
        cout << "K:" << k <<endl;
        k = Pop(&S);
        T += w[k];
        k++;
    }while(!StackEmpty(S) || k < n);
}
