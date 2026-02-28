#include <bits/stdc++.h>
using namespace std;

typedef struct Queue
{
private:
    int *queueArray;
    int size;
    int start, end;
    int currSize;

public:
    Queue(int capacity = 1000)
    {
        queueArray = new int[capacity];
        size = capacity;
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == size)
        { // queue is full - can't push
            cout << "Queue is full\n";
            return;
        }

        if (currSize == 0) // queue is empty
            start = end = 0;
        else // queue is not empty
            end = (end + 1) % size;
        queueArray[end] = x;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
        {
            // empty queue - nothing to pop
            cout << "Queue is Empty\n";
            return -1;
        }
        int el = queueArray[start];
        if (currSize == 1)
            // only 1 element
            start = end = -1;
        else
            // many elements
            start = (start + 1) % size;
        currSize -= 1;
        return el;
    }

    int top()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return queueArray[start];
    }

    bool isEmpty()
    {
        return (currSize == 0);
    }

    int findSize()
    {
        return currSize;
    }

} Queue;

int main()
{
    Queue q;

    q.push(5);
    q.push(6);
    q.push(3);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(8);
    q.push(9);
    cout << q.top() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}