#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    bool isPalindrome(Node *head)
    {
        // create an empty stack
        stack<int> st;

        Node *temp = head;

        // fill the stack with the elements of the ll
        while (temp != nullptr)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        // compare with the given ll
        temp = head;
        while (temp != NULL)
        {
            if (temp->data != st.top())
                return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};

// function to print the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // your code goes here
    // palindrome check
    // let's make a ll
    // 1 5 2 5 1
    Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    print(head);

    Solution solution;
    bool isPalindrome = solution.isPalindrome(head);

    if (isPalindrome)
    {
        cout << "Is a Palindrome";
    }
    else
    {
        cout << "Isn't a Palindrome";
    }

    return 0;
}
