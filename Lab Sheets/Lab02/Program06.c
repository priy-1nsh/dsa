#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

// increasing subsequence from first element
Node *increasingSubsequence(Node *head)
{

    // edge case - single element or empty list
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next->data <= temp->data)
        {
            // delete the temp->data
            Node *delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        }
        temp = temp->next;
    }
    return head;
}

int main()
{

    int n;
    scanf("%d", &n);

    // empty list can't be rotated
    if (n == 0)
    {
        printf("Empty list");
        return 0;
    }

    int x;
    scanf("%d", &x);

    Node *head = createNode(x);
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        temp->next = createNode(x);
        temp = temp->next;
    }

    print(head);

    Node *newHead = increasingSubsequence(head);

    print(newHead);

    return 0;
}