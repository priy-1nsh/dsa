#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// function to rotate the linked list by one place to the right
Node *rotateListByOne(Node *head)
{

    // edge case - if the ll is empty or only has one element
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *tail = temp->next;
    temp->next = NULL;
    tail->next = head;

    return tail;
}

Node *rotateListByK(Node *head, int n, int k)
{
    // handle edge case
    if (head == NULL || head->next == NULL)
        return head;

    k = k % n;
    for (int i = 0; i < k; i++)
    {
        head = rotateListByOne(head);
    }
    return head;
}

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

    int k;
    scanf("%d", &k);

    print(head);

    Node *newHead = rotateListByK(head, n, k);

    print(newHead);

    return 0;
}