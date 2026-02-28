#include <bits/stdc++.h>
using namespace std;

class ArrayStack
{
private:
    int *stackArray;
    int capacity;
    int topIndex;

public:
    ArrayStack(int capacity = 1000) // declare size here in case we call constructor
                                    // without any parameter
    {
        this->capacity = capacity;
        topIndex = -1;
        stackArray = new int[capacity];
    }

    ~ArrayStack()
    {
        delete[] stackArray;
    }

    void push(int x)
    {
        if (topIndex >= this->capacity - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        stackArray[++topIndex] = x;
    }

    int pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty, nothing to pop" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }

    bool isEmpty()
    {
        return (topIndex == -1);
        // if yes, then stack is empty
    }

    int size()
    {
        return topIndex + 1;
    }
};

int main()
{
    ArrayStack stack;

    stack.push(7);
    stack.push(8);
    stack.push(5);

    cout << stack.top() << endl;

    cout << stack.pop() << endl;

    cout << stack.top();

    return 0;
}