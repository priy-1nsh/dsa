#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definition of linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *reverseLinkedList(Node *head)
{
    // reversing the linked list
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// function to check isPalindrome
bool isPalindrome(Node *head)
{
    // first handle edge case - linked list empty or singleton
    if (head == NULL || head->next == NULL)
        return true; // trivially a palindrome

    // half the linked list into two halves - by fidng the middle of the ll - tortoise-hare algorthm
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL || fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Now, reverse the second half
    Node *newHead = reverseLinkedList(slow->next);

    // compare the two halves
    Node *first = head;
    Node *second = newHead;

    while (second != NULL)
    {
        if (first->data != second->data)
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

int main()
{

    int n;
    scanf("%d", &n);

    if (n == 0 || n = 1)
    {
        printf("Palindrome");
        return 0;
    }

    int x;
    // create head node
    scanf("%d", &x);

    Node *head = createNode(x);
    Node *temp = head;

    // since there is no new keyword in C, we use the function createNode for creating nodes
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        temp->next = createNode(x);
        temp = temp->next;
    }

    if (isPalindrome(head))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}