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

Node *pairWiseSwap(Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
        return head;

    // now, swap nodes
    // make two pointers prev and temp
    Node *prev = head;
    Node *curr = head->next;

    // update the head
    head = curr;

    while (true)
    {
        Node *next = curr->next;
        curr->next = prev;

        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }

        prev->next = next->next;

        // move the pointers
        prev = next;
        curr = prev->next;
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

    Node *resultHead = pairWiseSwap(head);

    print(resultHead);

    return 0;
}