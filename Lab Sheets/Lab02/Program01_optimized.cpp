#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution
{
private:
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    // function to print the linked list
    void print(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome(ListNode *head)
    {
        // edge case - linked list is empty or just single element
        if (head == NULL || head->next == NULL)
            return true;

        // check if a ll is palindrome or not
        // find the middle
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now the middle is in slow pointer
        // now we reverse the second half of the ll
        // slow->next is the head of the second half of the ll
        ListNode *newHead = reverseLinkedList(slow->next);

        // Now, we compare the two halves using two pointer approach
        ListNode *first = head;
        ListNode *second = newHead;

        while (second != NULL)
        {
            if (first->val != second->val)
            {
                reverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
};

int main()
{
    // your code goes here
    // palindrome check
    // let's make a ll
    // 1 5 2 5 1
    ListNode *head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(1);

    Solution solution;
    solution.print(head);
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