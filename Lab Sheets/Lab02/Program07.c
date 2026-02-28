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

Node *moveXToEnd(Node *head, int x)
{
    Node *xHead = NULL;
    Node *xTail = NULL;
    Node *nonXHead = NULL;
    Node *nonXTail = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        // detach this node
        curr->next = NULL;

        if (curr->data == x)
        {
            // add x to the x list
            if (xHead == NULL)
            {
                // empty xList
                xHead = xTail = curr;
            }
            else
            {
                xTail->next = curr;
                xTail = curr;
            }
        }
        else
        {
            // add x to the nonXList
            if (nonXHead == NULL)
            {
                // empty nonXList
                nonXHead = nonXTail = curr;
            }
            else
            {
                nonXTail->next = curr;
                nonXTail = curr;
            }
        }
        curr = nextNode;
    }

    // check if the nonXList is empty
    if (nonXHead == NULL)
        return xHead;

    nonXTail->next = xHead;

    return nonXHead;
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

    Node *newHead = moveXToEnd(head, k);

    print(newHead);

    return 0;
}