#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *back;
    int size;
} Queue;

Node *createNode(char x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->size = 0;
    q->front = NULL;
    q->back = NULL;
    return q;
}

// Queue Implementation
void push(Queue *q, char x)
{
    Node *temp = createNode(x);

    if (q->size == 0)
    {
        // 0 elements
        q->front = q->back = temp;
    }

    q->back->next = temp;
    q->back = temp;
    q->size++;
}

char pop(Queue *q)
{
    if (q->size == 0)
        return -1;

    Node *temp = q->front;
    char el = temp->data;

    if (q->size == 1)
    {
        q->front = q->back = NULL;
    }
    else
    {
        q->front = q->front->next;
    }

    q->size--;

    free(temp);
    return el;
}

int front(Queue *q)
{
    if (q->size == 0)
    {
        return -1;
    }

    return q->front->data;
}

bool isEmpty(Queue *q)
{
    return (q->size == 0);
}

int currSize(Queue *q)
{
    return q->size;
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