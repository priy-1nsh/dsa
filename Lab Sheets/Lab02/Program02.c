#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node *segregateEvenAndOdd(Node *head)
{
    Node *temp = head;
    Node *evenHead = createNode(0);
    Node *oddHead = createNode(0);

    Node *even = evenHead;
    Node *odd = oddHead;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            even->next = temp;
            even = even->next;
        }
        else if (temp->data % 2 == 1)
        {
            odd->next = temp;
            odd = odd->next;
        }

        temp = temp->next;
    }

    odd->next = NULL;

    even->next = oddHead->next;

    return evenHead->next;
}

int main()
{

    int n;
    scanf("%d", &n);

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

    // Now, we will separate the odd and even numbers
    // Importat - here, the even head and the odd head i made don't store any values of the origial list but their first next contains the first even and odd numbers of the original list,
    Node *resultHead = segregateEvenAndOdd(head);

    print(resultHead);

    return 0;
}