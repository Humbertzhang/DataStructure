#include "stack.h"
#include <iostream>

using namespace std;

struct Queue {
    Stack enstack;
    Stack qustack;
};

void InitQueue(Queue * q) {
    InitStack(&q->enstack);
    InitStack(&q->qustack);
}

void Enqueue(Queue * q, char e) {
    Push(&q->enstack, e);
}

char Dequeue(Queue * q) {
    if (StackEmpty(q->qustack)) {
        while(!StackEmpty(q->enstack)){
            char c = Pop(&q->enstack);
            Push(&q->qustack, c);
        }
        return Pop(&q->qustack);
    }else {
        return  Pop(&q->qustack);
    }
}

int ain()
{
    Queue q;
    InitQueue(&q);
    Enqueue(&q, 'a');
    Enqueue(&q, 'b');
    Enqueue(&q, 'c');
    cout << "Dequeue:" << Dequeue(&q) <<endl;
    cout << "Dequeue:" << Dequeue(&q) <<endl;
    cout << "Dequeue:" << Dequeue(&q) <<endl;
    return 0;
}