#include <bits/stdc++.h>
using namespace std;

// Implement stack using LL

// Node definition
typedef struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        this->data = x;
    }

} Node;

// Stack
typedef struct Stack
{
private:
    int size;
    Node *top;

public:
    Stack()
    {
        size = 0;
        top = NULL;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    int pop()
    {
        // edge case
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        Node *temp = top;
        int el = temp->data;
        top = top->next;
        delete (temp);
        return el;
    }
    int peek()
    {
        // egde case
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }
    int currSize()
    {
        return size;
    }
} Stack;

int main()
{
    Stack st; // constructor called automatically - no need of new() keyword
              // as it returns the pointer which we don't want
    st.push(8);
    st.push(9);
    st.push(5);
    st.pop();
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    cout << st.currSize() << endl;
    cout << st.currSize() << endl;
    return 0;
}
