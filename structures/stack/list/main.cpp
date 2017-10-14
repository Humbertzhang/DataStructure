#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s = CreateStack();
    if(IsEmpty(s)){
        cout << "Stack is empty" <<endl;
    }
    Push(1, s);
    Push(2, s);
    Push(3, s);
    Push(4, s);
    Push(5, s);
    int tem = Top(s);
    cout << "Top:" << tem <<endl;
    tem = Pop(s); 
    cout << "Pop:" << tem <<endl;
    tem = Pop(s); 
    cout << "Pop:" << tem <<endl;
    
    if(IsEmpty(s)){
        cout << "Stack is empty" <<endl;
    }
    cout << "Make Stack Empty" << endl;

    MakeEmpty(s);
}
