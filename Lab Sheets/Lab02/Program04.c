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

void sumAndSkip(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {

        int sum = temp->data + temp->next->data;
        Node *sumNode = createNode(sum);

        sumNode->next = temp->next->next;
        temp->next->next = sumNode;
        temp = sumNode->next;
    }

    if (temp != NULL && temp->next == NULL)
    {
        Node *dupNode = createNode(temp->data);
        dupNode->next = NULL;
        temp->next = dupNode;
    }
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

    sumAndSkip(head);

    print(head);

    return 0;
}