#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *start;
    Node *end;
    int size;
} Queue;

// functions to create Node and Queue
Node *createNode(char x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 0;
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

// queue operations
void push(Queue *queue, char x)
{

    Node *temp = createNode(x);

    // if q is empty
    if (queue->start == NULL)
    {
        queue->start = queue->end = temp;
    }
    else
    {
        queue->end->next = temp;
        queue->end = temp;
    }
    queue->size++;
}

int pop(Queue *queue)
{
    if (queue->start == NULL)
    {
        printf("Queue is empty, nothing to pop\n");
        return -1;
    }

    int el = queue->start->data;
    Node *temp = queue->start;
    queue->start = queue->start->next;
    free(temp);
    queue->size--;

    if (queue->start == NULL)
    {
        // queue got empty
        queue->end = NULL;
    }
    return el;
}

int front(Queue *queue)
{
    if (queue->start == NULL)
    { // ALTERNATE CONDITION IS queue->end == NULL
        // queue is Empty
        printf("Queue is Empty, Nothing to peek\n");
        return -1;
    }
    return queue->start->data;
}

bool isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

int currSize(Queue *queue)
{
    return queue->size;
}

void firstNonRepeatingCharacter(char *s)
{
    int freqArr[26] = {0};
    Queue *q = createQueue();

    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        // traverse the string s
        freqArr[s[i] - 'a']++; // update the frequency

        if (freqArr[s[i] - 'a'] == 1)
            push(q, s[i]);

        while (!isEmpty(q) && freqArr[front(q) - 'a'] != 1)
        {
            pop(q);
        }

        if (isEmpty(q))
            printf("-1 ");
        else
            printf("%c ", front(q));
    }
}

int main()
{

    char string[1000];
    scanf("%s", string);

    firstNonRepeatingCharacter(string);

    return 0;
}