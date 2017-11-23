#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 100

template <class X>
class Queue
{
    X * arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue();
    X dequeue();
    void enqueue(X x);
    //X peek();
    bool isEmpty();
    bool isFull();
};

template <class X>
Queue<X>::Queue()
{
    arr = new X[SIZE];
    capacity = SIZE;
    front = 0;
    rear = -1;
    count = 0;
}

template <class X>
X Queue<X>::dequeue()
{
    if(isEmpty()){
        cout << "Queue is Empty";
        exit(1);
    }
    X ret =  arr[front];
    front = (front + 1) % capacity;
    count -= 1;
    return ret;
}

template <class X>
void Queue<X>::enqueue(X item)
{
    if (isFull()){
        cout << "Queue is Full";
        exit(1);
    }
    rear = (rear+1) % capacity;
    arr[rear] = item;
    count += 1;
}

template <class X>
bool Queue<X>::isEmpty()
{
    return(count == 0);
}

template <class X>
bool Queue<X>::isFull()
{
    return(count == capacity);
}
