#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue Implementation
typedef struct Node
{
    int tickets;
    int index;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *start; // front
    Node *end;   // back
    int size;
} Queue;

// createNode
Node *createNode(int index, int tickets)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->index = index;
    newNode->tickets = tickets;
    return newNode;
}

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->end = NULL;
    q->start = NULL;
    q->size = 0;
    return q;
}

// Queue Operations
bool isEmpty(Queue *q)
{
    return (q->size == 0);
}

void push(Queue *q, int index, int tickets)
{
    Node *temp = createNode(index, tickets);

    if (q->size == 0)
    {
        // q is empty
        q->start = q->end = temp;
    }
    else
    {
        // q is not empty
        q->end->next = temp;
        q->end = temp;
    }
    q->size++;
}

Node *pop(Queue *q)
{
    // edge case - if q is empty
    if (isEmpty(q))
    {
        printf("Q is Empty\n");
        return NULL;
    }

    Node *temp = q->start;
    // if q has one element only
    if (q->size == 1)
    {
        q->start = q->end = NULL;
    }
    else
    {
        q->start = q->start->next;
    }
    q->size--;
    return temp;
}

Node *front(Queue *q)
{
    if (isEmpty(q))
    {
        return NULL;
    }
    return q->start;
}

// calculateTime
int calculateTime(int *tickets, int n, int k)
{
    // push all the elements into the q
    Queue *q = createQueue();
    for (int i = 0; i < n; i++)
    {
        push(q, i, tickets[i]);
    }

    int time = 0;

    while (!isEmpty(q))
    {
        Node *temp = front(q);
        pop(q);

        temp->tickets--;
        time++;

        if (temp->index == k && temp->tickets == 0)
            break;

        if (temp->tickets > 0)
        {
            push(q, temp->index, temp->tickets);
        }
    }
    return time;
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);

    int *tickets = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tickets[i]);
    }

    int result = calculateTime(tickets, n, k);

    printf("%d\n", result);

    free(tickets);

    return 0;
}